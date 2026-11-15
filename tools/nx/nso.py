"""NSO0 loader: decompress segments and expose the module as a flat memory image."""
from __future__ import annotations

import hashlib
import struct
from dataclasses import dataclass

import lz4.block


@dataclass
class Segment:
    name: str
    mem_off: int
    data: bytes

    @property
    def end(self) -> int:
        return self.mem_off + len(self.data)


@dataclass
class Mod0:
    dynamic: int
    bss_start: int
    bss_end: int
    eh_frame_hdr_start: int
    eh_frame_hdr_end: int
    module_object: int


class Nso:
    def __init__(self, raw: bytes):
        if raw[:4] != b"NSO0":
            raise ValueError("not an NSO0")
        flags = struct.unpack_from("<I", raw, 0xC)[0]
        segs = []
        csizes = struct.unpack_from("<III", raw, 0x60)
        hashes = [raw[0xA0 + i * 0x20:0xC0 + i * 0x20] for i in range(3)]
        for i, name in enumerate(("text", "rodata", "data")):
            file_off, mem_off, dec_size, extra = struct.unpack_from("<IIII", raw, 0x10 + i * 0x10)
            blob = raw[file_off:file_off + csizes[i]]
            if flags & (1 << i):
                blob = lz4.block.decompress(blob, uncompressed_size=dec_size)
            if len(blob) != dec_size:
                raise ValueError(f"{name}: size mismatch")
            if flags & (1 << (i + 3)) and hashlib.sha256(blob).digest() != hashes[i]:
                raise ValueError(f"{name}: hash mismatch")
            segs.append(Segment(name, mem_off, blob))
            if name == "data":
                self.bss_size = extra
        self.text, self.rodata, self.data = segs
        self.build_id = raw[0x40:0x60]
        self.mod0 = self._parse_mod0()

    # flat image covering text..data (bss excluded)
    def image(self) -> bytes:
        img = bytearray(self.data.end)
        for s in (self.text, self.rodata, self.data):
            img[s.mem_off:s.end] = s.data
        return bytes(img)

    def _parse_mod0(self) -> Mod0:
        img = self.image()
        mod_off = struct.unpack_from("<I", img, 4)[0]
        if img[mod_off:mod_off + 4] != b"MOD0":
            raise ValueError("MOD0 header not found")
        rel = struct.unpack_from("<6i", img, mod_off + 4)
        return Mod0(*(mod_off + r for r in rel))

    def text_sha256(self) -> str:
        return hashlib.sha256(self.text.data).hexdigest()
