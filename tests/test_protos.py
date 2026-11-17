"""tools/protos.py: descriptor decoding, .proto printing, protoc commands.
Descriptors are hand-encoded protobuf wire format; no game files, no protoc."""
from __future__ import annotations

import struct
from pathlib import Path

import pytest

import protos
from source_paths import SourcePathRule


# --- protobuf wire format, by hand ---

def varint(v: int) -> bytes:
    out = bytearray()
    while True:
        b = v & 0x7F
        v >>= 7
        out.append(b | (0x80 if v else 0))
        if not v:
            return bytes(out)


def ld(num: int, data: bytes | str) -> bytes:  # length-delimited field
    data = data.encode() if isinstance(data, str) else data
    return varint(num << 3 | 2) + varint(len(data)) + data


def vi(num: int, v: int) -> bytes:  # varint field
    return varint(num << 3) + varint(v)


def field(name, number, type_, label=1, type_name=None, oneof=None, options=b""):
    b = ld(1, name) + vi(3, number) + vi(4, label) + vi(5, type_)
    if type_name:
        b += ld(6, type_name)
    if options:
        b += ld(8, options)
    if oneof is not None:
        b += vi(9, oneof)
    return b


def message(name, *parts):
    return ld(1, name) + b"".join(parts)


PING = (ld(1, "ping.proto") + ld(2, "gfl.pb")
        + ld(4, message("Ping", ld(2, field("time", 1, 4)), ld(2, field("ids", 2, 5, label=3)))))


def test_decode_reads_the_schema_fields():
    fd = protos.decode(PING + ld(12, "proto3"))
    assert fd["name"] == "ping.proto" and fd["package"] == "gfl.pb" and fd["syntax"] == "proto3"
    [m] = fd["message_type"]
    assert [(f["name"], f["number"], f["type"]) for f in m["field"]] == [("time", 1, 4), ("ids", 2, 5)]


def test_decode_rejects_fields_it_doesnt_know():
    with pytest.raises(protos.DescriptorError, match="FileDescriptorProto: unsupported field 8"):
        protos.decode(PING + ld(8, b""))  # FileOptions
    with pytest.raises(protos.DescriptorError, match="FieldDescriptorProto: unsupported field 7"):
        protos.decode(ld(4, message("M", ld(2, field("x", 1, 5) + ld(7, "3"))))) # default_value


def test_decode_reads_packed_repeated_varints():
    fd = protos.decode(ld(3, "a.proto") + ld(3, "b.proto") + ld(10, varint(0) + varint(1)) + vi(10, 1))
    assert fd["dependency"] == ["a.proto", "b.proto"] and fd["public_dependency"] == [0, 1, 1]


def test_peek_strings_needs_no_schema():
    # descriptor.proto's fields (options, default values) aren't in SCHEMA
    blob = ld(1, "google/protobuf/descriptor.proto") + ld(2, "google.protobuf") + ld(8, vi(9, 1))
    assert protos.peek_strings(blob) == {1: "google/protobuf/descriptor.proto", 2: "google.protobuf"}


def test_to_proto_prints_messages_maps_oneofs_enums():
    entry = message("ScoresEntry", ld(2, field("key", 1, 9)), ld(2, field("value", 2, 5)), ld(7, vi(7, 1)))
    holder = message(
        "Holder",
        ld(2, field("ping", 1, 11, type_name=".gfl.pb.Ping", oneof=0)),
        ld(2, field("note", 2, 9, oneof=0)),
        ld(2, field("scores", 3, 11, label=3, type_name=".gfl.pb.Holder.ScoresEntry")),
        ld(2, field("kind", 4, 14, type_name=".gfl.pb.Holder.Kind", options=vi(3, 1))),
        ld(3, entry),
        ld(4, ld(1, "Kind") + ld(2, ld(1, "NONE") + vi(2, 0)) + ld(2, ld(1, "BIG") + vi(2, 2))),
        ld(8, ld(1, "message")),
        ld(9, vi(1, 8) + vi(2, 11)),
        ld(10, "old"),
    )
    fd = protos.decode(PING + ld(3, "other.proto") + ld(4, holder) + ld(12, "proto3"))
    assert protos.to_proto(fd) == """syntax = "proto3";

package gfl.pb;

import "other.proto";

message Ping {
  uint64 time = 1;
  repeated int32 ids = 2;
}

message Holder {
  oneof message {
    .gfl.pb.Ping ping = 1;
    string note = 2;
  }
  map<string, int32> scores = 3;
  .gfl.pb.Holder.Kind kind = 4 [deprecated = true];
  enum Kind {
    NONE = 0;
    BIG = 2;
  }
  reserved 8 to 10;
  reserved "old";
}
"""


def test_to_proto_refuses_what_it_cant_print():
    with pytest.raises(protos.DescriptorError, match="only proto3"):
        protos.to_proto(protos.decode(PING))
    split = message("M", ld(2, field("a", 1, 5, oneof=0)), ld(2, field("b", 2, 5)),
                    ld(2, field("c", 3, 5, oneof=0)), ld(8, ld(1, "o")))
    with pytest.raises(protos.DescriptorError, match="aren't contiguous"):
        protos.to_proto(protos.decode(ld(4, split) + ld(12, "proto3")))


def test_strip_json_names():
    fd = {"message_type": [{"field": [{"name": "a", "json_name": "a"}],
                            "nested_type": [{"field": [{"name": "b", "json_name": "b"}]}]}]}
    assert protos._strip_json_names(fd) == {"message_type": [{"field": [{"name": "a"}],
                                                               "nested_type": [{"field": [{"name": "b"}]}]}]}


# --- locating the descriptors and their directories ---

def test_registrations_reads_x0_and_w1_before_the_call():
    adrp_x0 = 0x90000000 | (1 << 29)         # adrp x0, +0x1000 (immlo 1, immhi 0)
    add_x0 = 0x91000000 | (0x80 << 10)       # add x0, x0, #0x80
    mov_w1 = 0x52800000 | (271 << 5) | 1     # mov w1, #271
    target = 0x40
    bl = 0x94000000 | ((target - 0x0C) >> 2 & 0x3FFFFFF)
    img = struct.pack("<4I", adrp_x0, add_x0, mov_w1, bl) + bytes(0x60)
    assert protos.registrations(img, len(img), target) == [(0x0C, 0x1080, 271)]


def test_pb_cc_paths_by_file_name():
    img = b"\0junk\0C:/x/prog/a/out/data/ping.pb.cc\0C:/x/lib/b/out/data/data.pb.cc\0"
    assert protos.pb_cc_paths(img, (0, len(img))) == {
        "ping.pb.cc": "C:/x/prog/a/out/data/ping.pb.cc", "data.pb.cc": "C:/x/lib/b/out/data/data.pb.cc"}
    with pytest.raises(SystemExit, match="two __FILE__ literals for ping.pb.cc"):
        protos.pb_cc_paths(img + b"C:/y/ping.pb.cc\0", (0, len(img) + 16))


def test_repo_dir_follows_source_paths():
    rules = [SourcePathRule("src/battle/", "src/", "C:/w/program/prog/", "./"),
             SourcePathRule("src/network/", "src/", "C:/w/program/prog/", "./"),
             SourcePathRule("src/gflnet3/", "src/gflnet3/", "C:/w/program/lib/gflnet3/", "./")]
    assert protos.repo_dir("C:/w/program/prog/network/x/out/data", rules) == protos.ROOT / "src/network/x/out/data"
    assert protos.repo_dir("C:/w/program/lib/gflnet3/src/p2p/out/data", rules) == \
        protos.ROOT / "src/gflnet3/src/p2p/out/data"
    with pytest.raises(SystemExit, match="no data/source_paths.csv row maps"):
        protos.repo_dir("C:/w/program/prog/field/out/data", rules)


# --- generate ---

def test_outputs_and_proto_files(tmp_path):
    (tmp_path / "a" / "out").mkdir(parents=True)
    (tmp_path / "a" / "out" / "ping.proto").write_text("")
    (tmp_path / "b.proto").write_text("")
    assert protos.proto_files(tmp_path) == [tmp_path / "a" / "out" / "ping.proto", tmp_path / "b.proto"]
    assert protos.outputs(Path("d/sync_ping.proto")) == (Path("d/sync_ping.pb.cc"), Path("d/sync_ping.pb.h"))


def test_protoc_command_uses_the_bare_name():
    own, other = Path("/r/src/a"), Path("/r/src/b")
    cmd = protos.protoc_command(Path("/t/protoc"), own / "ping.proto", [own, other], ["--cpp_out=."])
    assert cmd == [str(Path("/t/protoc")), "--proto_path=.", f"--proto_path={other}", "--cpp_out=.", "ping.proto"]


def test_every_asset_is_pinned():
    for asset, sha in protos.PROTOC_ASSETS.values():
        assert asset.startswith("protoc-3.0.0-") and len(sha) == 64
