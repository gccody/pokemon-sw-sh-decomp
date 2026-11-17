#!/usr/bin/env python3
"""Protocol Buffers messages of Game Freak's code: .proto sources and protoc.

Game Freak's code links `protoc` 3.0.0 output for its own `.proto` files: each
generated `<name>.pb.cc` registers its file's serialized `FileDescriptorProto`
with `DescriptorPool::InternalAddGeneratedFile`. That descriptor spells the
`.proto` out completely, so the generated code can be matched by regenerating it:

    python tools/protos.py extract      # needs data/original: write the .proto files
    python tools/protos.py generate     # protoc 3.0.0 -> <name>.pb.cc/.pb.h next to each

`extract` finds every call of `InternalAddGeneratedFile` in Sword's `main`,
decodes the descriptor it registers, and writes `<name>.proto` into the
directory the generated code was compiled in. That directory comes from the
`__FILE__` literal of `<name>.pb.cc`, mapped through data/source_paths.csv.
Only fields this printer knows are accepted (proto3 messages, enums, oneofs,
maps, reserved ranges), anything else is an error. Each file is then checked by
compiling it with protoc and comparing the descriptor with the original.

`generate` runs protoc 3.0.0 on every committed `.proto` under src/, writing
the `.pb.cc` and `.pb.h` next to it. Those aren't committed (src/.gitignore):
protoc embeds the serialized descriptor, a copy of the game's rodata, in the
`.pb.cc`. protoc is downloaded from Google's v3.0.0 release into
toolchain/protoc-3.0.0, checked against SHA256 below. CMakeLists.txt refuses to
configure while a generated file is missing or older than its `.proto`.
"""
from __future__ import annotations

import argparse
import hashlib
import io
import platform
import re
import struct
import subprocess
import sys
import urllib.request
import zipfile
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
SRC = ROOT / "src"
PROTOC_DIR = ROOT / "toolchain" / "protoc-3.0.0"
PROTOC_URL = "https://github.com/protocolbuffers/protobuf/releases/download/v3.0.0/{asset}"
WIN32 = "7f9570e08ecc1e158114f974917463e2a11b309ac392b34aa4b12733e27fac0b"
LINUX = "56e3f685ffe3c9516c5ed1da0aefd3f41010a051e8b36f1b538ac23298fccb30"
OSX = "7ea1a482e84319bedb28d72ab3e85779b4ecff95995875fc935a26419dbdeb4b"
# (system, machine) -> release asset and its SHA-256
PROTOC_ASSETS = {
    ("Windows", "AMD64"): ("protoc-3.0.0-win32.zip", WIN32),
    ("Windows", "x86"): ("protoc-3.0.0-win32.zip", WIN32),
    ("Linux", "x86_64"): ("protoc-3.0.0-linux-x86_64.zip", LINUX),
    ("Darwin", "x86_64"): ("protoc-3.0.0-osx-x86_64.zip", OSX),
    ("Darwin", "arm64"): ("protoc-3.0.0-osx-x86_64.zip", OSX),  # runs under Rosetta
}
ADD_GENERATED_FILE = "_ZN6google8protobuf14DescriptorPool24InternalAddGeneratedFileEPKvi"

# --------------------------------------------------------------------------- decoding

# message -> field number -> (name, kind, repeated). kind: "string", "varint", or a message name.
SCHEMA = {
    "FileDescriptorProto": {
        1: ("name", "string", False), 2: ("package", "string", False), 3: ("dependency", "string", True),
        4: ("message_type", "DescriptorProto", True), 5: ("enum_type", "EnumDescriptorProto", True),
        10: ("public_dependency", "varint", True), 11: ("weak_dependency", "varint", True),
        12: ("syntax", "string", False),
    },
    "DescriptorProto": {
        1: ("name", "string", False), 2: ("field", "FieldDescriptorProto", True),
        3: ("nested_type", "DescriptorProto", True), 4: ("enum_type", "EnumDescriptorProto", True),
        7: ("options", "MessageOptions", False), 8: ("oneof_decl", "OneofDescriptorProto", True),
        9: ("reserved_range", "ReservedRange", True), 10: ("reserved_name", "string", True),
    },
    "FieldDescriptorProto": {
        1: ("name", "string", False), 3: ("number", "varint", False), 4: ("label", "varint", False),
        5: ("type", "varint", False), 6: ("type_name", "string", False),
        8: ("options", "FieldOptions", False), 9: ("oneof_index", "varint", False),
        10: ("json_name", "string", False),  # only in protoc's --descriptor_set_out
    },
    "OneofDescriptorProto": {1: ("name", "string", False)},
    "EnumDescriptorProto": {
        1: ("name", "string", False), 2: ("value", "EnumValueDescriptorProto", True),
        3: ("options", "EnumOptions", False),
    },
    "EnumValueDescriptorProto": {1: ("name", "string", False), 2: ("number", "varint", False)},
    "ReservedRange": {1: ("start", "varint", False), 2: ("end", "varint", False)},
    "MessageOptions": {7: ("map_entry", "varint", False)},
    "FieldOptions": {2: ("packed", "varint", False), 3: ("deprecated", "varint", False)},
    "EnumOptions": {2: ("allow_alias", "varint", False)},
    "FileDescriptorSet": {1: ("file", "FileDescriptorProto", True)},
}


class DescriptorError(ValueError):
    pass


def _varint(buf: bytes, i: int) -> tuple[int, int]:
    shift = value = 0
    while True:
        if i >= len(buf):
            raise DescriptorError("truncated varint")
        b = buf[i]
        i += 1
        value |= (b & 0x7F) << shift
        if not b & 0x80:
            return value, i
        shift += 7


def peek_strings(buf: bytes) -> dict[int, str]:
    """The top-level string fields of a serialized message, without its schema
    (for a FileDescriptorProto: 1 = name, 2 = package)."""
    out, i = {}, 0
    while i < len(buf):
        key, i = _varint(buf, i)
        num, wt = key >> 3, key & 7
        if wt == 0:
            _, i = _varint(buf, i)
        elif wt == 2:
            n, i = _varint(buf, i)
            if num in (1, 2):
                out[num] = buf[i:i + n].decode("utf-8")
            i += n
        elif wt in (1, 5):
            i += 8 if wt == 1 else 4
        else:
            raise DescriptorError(f"unsupported wire type {wt}")
    return out


def decode(buf: bytes, message: str = "FileDescriptorProto") -> dict:
    """A serialized `message` as a dict, by SCHEMA. Unknown fields are an error,
    so nothing the printer would drop goes unnoticed."""
    schema = SCHEMA[message]
    out: dict = {}
    i = 0
    while i < len(buf):
        key, i = _varint(buf, i)
        num, wt = key >> 3, key & 7
        if num not in schema:
            raise DescriptorError(f"{message}: unsupported field {num}")
        name, kind, repeated = schema[num]
        if wt == 0:
            if kind != "varint":
                raise DescriptorError(f"{message}.{name}: wire type 0 for {kind}")
            value, i = _varint(buf, i)
        elif wt == 2:
            n, i = _varint(buf, i)
            data, i = buf[i:i + n], i + n
            if len(data) != n:
                raise DescriptorError(f"{message}.{name}: truncated")
            if kind == "string":
                value = data.decode("utf-8")
            elif kind == "varint" and repeated:  # packed
                vals, j = [], 0
                while j < len(data):
                    v, j = _varint(data, j)
                    vals.append(v)
                out.setdefault(name, []).extend(vals)
                continue
            else:
                value = decode(data, kind)
        else:
            raise DescriptorError(f"{message}.{name}: unsupported wire type {wt}")
        if repeated:
            out.setdefault(name, []).append(value)
        elif name in out:
            raise DescriptorError(f"{message}.{name}: repeated singular field")
        else:
            out[name] = value
    return out


# --------------------------------------------------------------------------- printing

LABEL_REPEATED = 3
SCALARS = {1: "double", 2: "float", 3: "int64", 4: "uint64", 5: "int32", 6: "fixed64", 7: "fixed32",
           8: "bool", 9: "string", 12: "bytes", 13: "uint32", 15: "sfixed32", 16: "sfixed64",
           17: "sint32", 18: "sint64"}
TYPE_MESSAGE, TYPE_ENUM = 11, 14


def _type(f: dict) -> str:
    t = f.get("type")
    if t in SCALARS:
        return SCALARS[t]
    if t in (TYPE_MESSAGE, TYPE_ENUM):
        return f["type_name"]
    raise DescriptorError(f"field {f.get('name')}: unsupported type {t}")


def _bool(v: int) -> str:
    return "true" if v else "false"


def _field(f: dict, maps: dict[str, tuple[str, str]], ind: str) -> str:
    opts = [f"{k} = {_bool(v)}" for k, v in f.get("options", {}).items()]
    o = f" [{', '.join(opts)}]" if opts else ""
    if f.get("type") == TYPE_MESSAGE and f["type_name"] in maps:
        k, v = maps[f["type_name"]]
        return f"{ind}map<{k}, {v}> {f['name']} = {f['number']}{o};"
    label = f.get("label", 1)
    if label not in (1, LABEL_REPEATED):
        raise DescriptorError(f"field {f['name']}: label {label} isn't proto3")
    rep = "repeated " if label == LABEL_REPEATED else ""
    return f"{ind}{rep}{_type(f)} {f['name']} = {f['number']}{o};"


def _enum(e: dict, ind: str, out: list[str]) -> None:
    out.append(f"{ind}enum {e['name']} {{")
    for k, v in e.get("options", {}).items():
        out.append(f"{ind}  option {k} = {_bool(v)};")
    for v in e.get("value", []):
        out.append(f"{ind}  {v['name']} = {v.get('number', 0)};")
    out.append(f"{ind}}}")


def _message(m: dict, scope: str, ind: str, out: list[str]) -> None:
    full = f"{scope}.{m['name']}"
    maps = {}
    for n in m.get("nested_type", []):
        if n.get("options", {}).get("map_entry"):
            key, value = n["field"]
            maps[f"{full}.{n['name']}"] = (_type(key), _type(value))
    if m.get("options") and set(m["options"]) != {"map_entry"}:
        raise DescriptorError(f"message {m['name']}: options {m['options']}")
    out.append(f"{ind}message {m['name']} {{")
    inner = ind + "  "
    fields = m.get("field", [])
    done: set[int] = set()
    for f in fields:
        oi = f.get("oneof_index")
        if oi is None:
            out.append(_field(f, maps, inner))
            continue
        if oi in done:
            continue
        done.add(oi)
        group = [g for g in fields if g.get("oneof_index") == oi]
        at = fields.index(group[0])
        if fields[at:at + len(group)] != group:
            raise DescriptorError(f"message {m['name']}: oneof {oi}'s fields aren't contiguous")
        out.append(f"{inner}oneof {m['oneof_decl'][oi]['name']} {{")
        out += [_field(g, maps, inner + "  ") for g in group]
        out.append(f"{inner}}}")
    for n in m.get("nested_type", []):
        if not n.get("options", {}).get("map_entry"):
            _message(n, full, inner, out)
    for e in m.get("enum_type", []):
        _enum(e, inner, out)
    for r in m.get("reserved_range", []):
        last = r["end"] - 1
        out.append(f"{inner}reserved {r['start']}" + (f" to {last}" if last != r["start"] else "") + ";")
    for name in m.get("reserved_name", []):
        out.append(f'{inner}reserved "{name}";')
    out.append(f"{ind}}}")


def to_proto(fd: dict) -> str:
    """`.proto` source for a decoded proto3 FileDescriptorProto. protoc compiles it
    back to the same descriptor (`extract` checks this for every file)."""
    if fd.get("syntax") != "proto3":
        raise DescriptorError(f"{fd.get('name')}: only proto3 is supported")
    out = ['syntax = "proto3";', ""]
    if fd.get("package"):
        out += [f"package {fd['package']};", ""]
    pub, weak = set(fd.get("public_dependency", [])), set(fd.get("weak_dependency", []))
    for i, dep in enumerate(fd.get("dependency", [])):
        kind = "public " if i in pub else "weak " if i in weak else ""
        out.append(f'import {kind}"{dep}";')
    if fd.get("dependency"):
        out.append("")
    scope = f".{fd['package']}" if fd.get("package") else ""
    for m in fd.get("message_type", []):
        _message(m, scope, "", out)
        out.append("")
    for e in fd.get("enum_type", []):
        _enum(e, "", out)
        out.append("")
    return "\n".join(out).rstrip("\n") + "\n"


# --------------------------------------------------------------------------- extract

def _strip_json_names(fd: dict) -> dict:
    """protoc's --descriptor_set_out adds json_name; the C++ generator's embedded
    descriptor (FileDescriptor::CopyTo) doesn't have it."""
    def msg(m: dict) -> None:
        for f in m.get("field", []):
            f.pop("json_name", None)
        for n in m.get("nested_type", []):
            msg(n)
    for m in fd.get("message_type", []):
        msg(m)
    return fd


def registrations(img: bytes, text_end: int, target: int) -> list[tuple[int, int, int]]:
    """(call offset, descriptor offset, size) of every `bl target` whose x0 is an
    adrp/add address and w1 a mov/movk constant, set within the 12 instructions before."""
    import capstone
    md = capstone.Cs(capstone.CS_ARCH_ARM64, capstone.CS_MODE_ARM)
    out = []
    for at in range(0, text_end - 3, 4):
        w = struct.unpack_from("<I", img, at)[0]
        if (w & 0xFC000000) != 0x94000000:
            continue
        imm = w & 0x3FFFFFF
        if at + ((imm - (1 << 26) if imm & (1 << 25) else imm) << 2) != target:
            continue
        regs: dict[str, int] = {}
        start = max(0, at - 48)
        for ins in md.disasm(img[start:at], start):
            ops = ins.op_str.replace(" ", "").split(",")
            if ins.mnemonic == "adrp":
                regs[ops[0]] = int(ops[1].lstrip("#"), 16)
            elif ins.mnemonic == "add" and len(ops) == 3 and ops[0] == ops[1] in regs and ops[2].startswith("#"):
                regs[ops[0]] = regs[ops[1]] + int(ops[2].lstrip("#"), 0)
            elif ins.mnemonic in ("mov", "movz") and ops[1].startswith("#"):
                regs[ops[0].replace("x", "w")] = int(ops[1].lstrip("#"), 0)
            elif ins.mnemonic == "movk" and ops[0].replace("x", "w") in regs:
                shift = int(ops[3].split("#")[1]) if len(ops) > 3 else 0
                regs[ops[0].replace("x", "w")] |= int(ops[1].lstrip("#"), 0) << shift
        if "x0" in regs and "w1" in regs:
            out.append((at, regs["x0"], regs["w1"]))
    return out


def pb_cc_paths(img: bytes, rodata: tuple[int, int]) -> dict[str, str]:
    """`<name>.pb.cc` -> its __FILE__ literal (the original path), from rodata."""
    lo, hi = rodata
    out: dict[str, str] = {}
    for m in re.finditer(rb"[\x20-\x7e]*\.pb\.cc(?=\x00)", img[lo:hi]):
        path = m.group().decode()
        name = path.replace("\\", "/").rsplit("/", 1)[-1]
        if out.get(name, path) != path:
            raise SystemExit(f"two __FILE__ literals for {name}: {out[name]} and {path}")
        out[name] = path
    return out


def repo_dir(original: str, rules) -> Path:
    """The repository directory for an original directory, by data/source_paths.csv."""
    from source_paths import _norm, _under
    for r in sorted(rules, key=lambda r: len(r.original), reverse=True):
        rel = _under(_norm(original), _norm(r.original))
        if rel is not None:
            d = ROOT / r.root / rel
            if (d.as_posix() + "/").startswith((ROOT / r.source).as_posix()):
                return d
    raise SystemExit(f"no data/source_paths.csv row maps {original}; add one")


def cmd_extract(args) -> int:
    sys.path.insert(0, str(ROOT / "tools"))
    from common import load_module, read_functions_csv
    from source_paths import read_source_paths
    mod = load_module("sword")
    img = mod["image"]
    target = next((f.sword for f in read_functions_csv() if f.name == ADD_GENERATED_FILE), None)
    if target is None:
        raise SystemExit(f"{ADD_GENERATED_FILE} isn't named in data/functions.csv")
    files: dict[str, bytes] = {}
    for _, at, size in registrations(img, mod["text_end"], target):
        blob = img[at:at + size]
        head = peek_strings(blob)
        if head.get(2) == "google.protobuf":
            continue  # protobuf's own descriptor.proto (lib/protobuf)
        if files.get(head[1], blob) != blob:
            raise SystemExit(f"two different descriptors named {head[1]}")
        files[head[1]] = blob
    paths = pb_cc_paths(img, mod["rodata"])
    rules = read_source_paths(ROOT / "data" / "source_paths.csv")
    written = []
    for name, blob in sorted(files.items()):
        cc = name[:-len(".proto")] + ".pb.cc"
        if cc not in paths:
            raise SystemExit(f"no __FILE__ literal for {cc}")
        d = repo_dir(paths[cc].replace("\\", "/").rsplit("/", 1)[0], rules)
        d.mkdir(parents=True, exist_ok=True)
        (d / name).write_text(to_proto(decode(blob)), encoding="utf-8", newline="\n")
        written.append((d / name, blob))
    print(f"wrote {len(written)} .proto files")
    protoc = ensure_protoc()
    dirs = sorted({p.parent for p, _ in written})
    bad = 0
    for p, blob in written:
        out = ROOT / "build" / "protos" / (p.name + ".desc")
        out.parent.mkdir(parents=True, exist_ok=True)
        run_protoc(protoc, p, dirs, [f"--descriptor_set_out={out}"])
        mine = _strip_json_names(decode(out.read_bytes(), "FileDescriptorSet")["file"][0])
        if mine != decode(blob):
            print(f"{p.relative_to(ROOT)}: protoc's descriptor differs from the original")
            bad += 1
    print(f"{len(written) - bad} of {len(written)} compile back to the original descriptor")
    return 1 if bad else 0


# --------------------------------------------------------------------------- generate

def ensure_protoc() -> Path:
    exe = PROTOC_DIR / "bin" / ("protoc.exe" if platform.system() == "Windows" else "protoc")
    if exe.exists():
        return exe
    key = (platform.system(), platform.machine())
    if key not in PROTOC_ASSETS:
        raise SystemExit(f"no protoc 3.0.0 release for {key}; put one at {exe}")
    asset, sha = PROTOC_ASSETS[key]
    print(f"downloading {asset}")
    data = urllib.request.urlopen(PROTOC_URL.format(asset=asset), timeout=120).read()
    have = hashlib.sha256(data).hexdigest()
    if have != sha:
        raise SystemExit(f"{asset}: SHA-256 {have}, expected {sha}")
    with zipfile.ZipFile(io.BytesIO(data)) as z:
        for info in z.infolist():
            if info.filename.startswith("bin/") and not info.is_dir():
                exe.parent.mkdir(parents=True, exist_ok=True)
                exe.write_bytes(z.read(info))
    exe.chmod(0o755)
    return exe


def proto_files(src: Path = SRC) -> list[Path]:
    return sorted(src.rglob("*.proto"))


def outputs(proto: Path) -> tuple[Path, Path]:
    stem = proto.with_suffix("")
    return stem.with_name(stem.name + ".pb.cc"), stem.with_name(stem.name + ".pb.h")


def protoc_command(protoc: Path, proto: Path, dirs: list[Path], extra: list[str]) -> list[str]:
    """protoc on `proto` by its bare name, run in its directory, as Game Freak ran
    it (the generated code says `// source: <name>.proto` and includes
    `"<dep>.pb.h"`): that directory first on the import path, then every other
    directory with `.proto` files."""
    others = [str(d) for d in dirs if d != proto.parent]
    return [str(protoc), "--proto_path=.", *[f"--proto_path={d}" for d in others], *extra, proto.name]


def run_protoc(protoc: Path, proto: Path, dirs: list[Path], extra: list[str]) -> None:
    r = subprocess.run(protoc_command(protoc, proto, dirs, extra), cwd=proto.parent,
                       capture_output=True, text=True)
    if r.returncode:
        raise SystemExit(f"protoc failed on {proto}:\n{r.stderr}")


def cmd_generate(args) -> int:
    protos = proto_files()
    if not protos:
        print("no .proto files under src/")
        return 0
    stale = [p for p in protos if args.force or any(
        not o.exists() or o.stat().st_mtime < p.stat().st_mtime for o in outputs(p))]
    if not stale:
        print(f"{len(protos)} .proto files, generated code up to date")
        return 0
    protoc = ensure_protoc()
    dirs = sorted({p.parent for p in protos})
    for p in stale:
        run_protoc(protoc, p, dirs, ["--cpp_out=."])
    print(f"generated {len(stale)} of {len(protos)} .proto files with protoc 3.0.0")
    return 0


def main(argv: list[str] | None = None) -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    sub.add_parser("extract", help="write src/**/<name>.proto from the descriptors in main (needs data/original)")
    g = sub.add_parser("generate", help="run protoc 3.0.0 on every .proto under src/")
    g.add_argument("--force", action="store_true", help="regenerate even if up to date")
    args = ap.parse_args(argv)
    return cmd_extract(args) if args.cmd == "extract" else cmd_generate(args)


if __name__ == "__main__":
    sys.exit(main())
