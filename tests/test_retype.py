"""tools/retype.py: renaming a function's parameter types and rewriting its
declarations, on tiny source trees and CSVs (no game files)."""
from __future__ import annotations

import pytest
import retype as R
from common import read_functions_csv

LEAF = """\
// Scope: common
#include <types.h>

struct Unk_7cd220 {
    u32 field_150;
};

void Unk_7f9d10(u32, u8, u32);

// 0x71007cd220
void Unk_7cd220_call(const Unk_7cd220* self, u32 value) {
    Unk_7f9d10(self->field_150, 0, value);
}
"""

HAND = """\
// Scope: common
#include <types.h>

struct Unk_7cd220;
u32 Unk_7cd220_call(const Unk_7cd220* self, u32 value);
u32 Unk_7cd220_call(const Unk_7cd220* self, u64 value);   // another overload: not ours

// 0x71008a9c50
u32 Caller(const Unk_7cd220* p, u8 index) {
    return Unk_7cd220_call(p, index);
}
"""


def test_parse_name():
    s = R.parse_name("_Z15Unk_7cd220_callPK10Unk_7cd220j")
    assert (s.prefix, s.scope, s.ident, s.params) == ("_Z15Unk_7cd220_call", [], "Unk_7cd220_call",
                                                       ["const Unk_7cd220*", "u32"])
    s = R.parse_name("_ZN11Unk_24091183vf6EP11Unk_102bf70")
    assert (s.prefix, s.scope, s.ident, s.params) == ("_ZN11Unk_24091183vf6E", ["Unk_2409118"], "vf6",
                                                       ["Unk_102bf70*"])
    s = R.parse_name("_ZNK3Foo3barEPKS_h")       # const member, its class as a substitution
    assert (s.scope, s.ident, s.params, s.codes) == (["Foo"], "bar", ["const Foo*", "u8"], "PKS_h")
    s = R.parse_name("_ZN2nn3pia11Unk_165fb30C2Ev")
    assert (s.scope, s.ident, s.xtor, s.params) == (["nn", "pia", "Unk_165fb30"], "Unk_165fb30", "C2", [])
    for bad in ("_ZN3FooplEc", "_Z3fooRK3Bar", "_ZNSt3__16vectorIiE9push_backEv", "_Z3fooN2nn3BarE", "foo",
                "_Z3foo"):
        with pytest.raises(R.RetypeError):
            R.parse_name(bad)


def test_check_rename():
    R.check_rename("_Z15Unk_7cd220_callPK10Unk_7cd220j", "_Z15Unk_7cd220_callPK10Unk_7cd220h")
    with pytest.raises(R.RetypeError, match="identity"):
        R.check_rename("_Z15Unk_7cd220_callPK10Unk_7cd220j", "_Z15Unk_7cd221_callPK10Unk_7cd220h")
    with pytest.raises(R.RetypeError, match="identity"):   # const member vs not
        R.check_rename("_ZNK3Foo3barEj", "_ZN3Foo3barEh")
    with pytest.raises(R.RetypeError, match="number"):
        R.check_rename("_Z10Unk_7cd220j", "_Z10Unk_7cd220jh")
    R.check_rename("_Z10Unk_7cd220j", "_Z10Unk_7cd220jh", force_name=True)
    with pytest.raises(R.RetypeError, match="same"):
        R.check_rename("_Z10Unk_7cd220j", "_Z10Unk_7cd220j")


def test_param_type():
    assert R.param_type("u32 value") == ("u32", " value")
    assert R.param_type(" const Unk_1* self") == ("const Unk_1*", " self")
    assert R.param_type("const Unk_1*") == ("const Unk_1*", "")
    assert R.param_type("u32 /*unused*/") == ("u32", " /*unused*/")
    assert R.param_type("unsigned int") == ("unsigned int", "")
    assert R.prototype_codes("const Unk_7cd220* self, u32 value", []) == "PK10Unk_7cd220j"
    assert R.prototype_codes("void* a, void* b", []) == "PvS_"
    assert R.prototype_codes("", []) == "v"
    assert R.prototype_codes("unsigned int x", []) is None
    assert R.rewrite_params("const Unk_7cd220* self, u32 value", ["const Unk_7cd220*", "u8"]) == \
        "const Unk_7cd220* self, u8 value"
    assert R.rewrite_params("u32, u8, u32", ["u32", "u8", "u8"]) == "u32, u8, u8"


def test_edit_generated_file():
    old, new = R.check_rename("_Z15Unk_7cd220_callPK10Unk_7cd220j", "_Z15Unk_7cd220_callPK10Unk_7cd220h")
    out, e = R.edit_text(LEAF, old, new, generated=True)
    assert "void Unk_7cd220_call(const Unk_7cd220* self, u8 value) {" in out
    assert e.rewrote == [11] and not e.other and not e.hand_definition
    # the call to another function isn't a prototype, and stays
    assert "Unk_7f9d10(self->field_150, 0, value);" in out
    old2, new2 = R.check_rename("_Z10Unk_7f9d10jhj", "_Z10Unk_7f9d10jhh")
    out2, e2 = R.edit_text(out, old2, new2, generated=True)
    assert "void Unk_7f9d10(u32, u8, u8);" in out2 and e2.rewrote == [8]
    # done already: nothing to do, and it says so
    out3, e3 = R.edit_text(out2, old2, new2, generated=True)
    assert out3 == out2 and e3.already == [8]


def test_edit_hand_written_file():
    old, new = R.check_rename("_Z15Unk_7cd220_callPK10Unk_7cd220j", "_Z15Unk_7cd220_callPK10Unk_7cd220h")
    out, e = R.edit_text(HAND, old, new, generated=False)
    assert "u32 Unk_7cd220_call(const Unk_7cd220* self, u8 value);" in out
    assert "u32 Unk_7cd220_call(const Unk_7cd220* self, u64 value);" in out   # another overload
    assert e.rewrote == [5] and e.other == [6]
    # a hand-written definition isn't rewritten: the one who wrote it changes it
    old, new = R.check_rename("_Z6CallerPK10Unk_7cd220h", "_Z6CallerPK10Unk_7cd220j")
    out, e = R.edit_text(HAND, old, new, generated=False)
    assert out == HAND and e.hand_definition == [9]
    out, e = R.edit_text(HAND, old, new, generated=True)
    assert "u32 Caller(const Unk_7cd220* p, u32 index) {" in out


def test_forward_declaration_of_a_new_struct():
    old, new = R.check_rename("_Z10Unk_7ef6a0Pv", "_Z10Unk_7ef6a0PK10Unk_7ee6b0")
    text = "#include <types.h>\n\nvoid Unk_7ef6a0(void*);\n\n// 0x71007ef600\nvoid f(void* p) {}\n"
    out, e = R.edit_text(text, old, new, generated=True)
    assert out == "#include <types.h>\n\nstruct Unk_7ee6b0;\nvoid Unk_7ef6a0(const Unk_7ee6b0*);\n\n" \
                  "// 0x71007ef600\nvoid f(void* p) {}\n"
    # declared already: no second one
    out, _ = R.edit_text("struct Unk_7ee6b0 {\n    u32 x;\n};\n" + text, old, new, generated=True)
    assert out.count("Unk_7ee6b0;") == 0 and out.count("struct Unk_7ee6b0") == 1


def test_member_prototypes():
    text = """\
struct Unk_2409118 {
    virtual u32 vf6(Unk_102bf70* p);
};
struct Other {
    virtual u32 vf6(Unk_102bf70* p);
};
// 0x7101028ec0
u32 Unk_2409118::vf6(Unk_102bf70* p) {
    return 0;
}
u32 Other::vf6(Unk_102bf70* p) {
    return 1;
}
"""
    old, new = R.check_rename("_ZN11Unk_24091183vf6EP11Unk_102bf70", "_ZN11Unk_24091183vf6EPK11Unk_102bf70")
    out, e = R.edit_text(text, old, new, generated=True)
    assert e.rewrote == [2, 8]
    assert "virtual u32 vf6(const Unk_102bf70* p);\n};\nstruct Other {\n    virtual u32 vf6(Unk_102bf70* p);" in out
    assert "u32 Other::vf6(Unk_102bf70* p) {" in out


def test_parse_check():
    log = ("OK  common      Unk_1(unsigned char)  [sword:0x7100000100, shield:0x7100000100]\n"
           "BAD common      Unk_2()  [sword:0x7100000200, shield:0x7100000210]\n"
           "      sword: differs\n\n2 matching, 1 not matching\n")
    assert R.parse_check(log) == {0x100: True, 0x200: False}
    assert R.address_comments("// 0x7100000100\nvoid f();\n  // 0x7100000200\n") == [0x100, 0x200]


def _tree(tmp_path, functions_csv, monkeypatch):
    (tmp_path / "src" / "unsorted" / "leaf").mkdir(parents=True)
    (tmp_path / "src" / "battle").mkdir(parents=True)
    leaf = tmp_path / "src" / "unsorted" / "leaf" / "Unk_7cd220.cpp"
    hand = tmp_path / "src" / "battle" / "Unk_8a9b50.cpp"
    leaf.write_text(LEAF, encoding="utf-8")
    hand.write_text(HAND, encoding="utf-8")
    csv = functions_csv("0x00000071007cd220,24,0x00000071007cd220,24,common,O,_Z15Unk_7cd220_callPK10Unk_7cd220j",
                        "0x00000071008a9c50,32,0x00000071008a9c50,32,common,M,_Z6CallerPK10Unk_7cd220h",
                        "0x00000071009a0000,8,0x00000071009a0000,8,common,U,_Z15Unk_9a0000_callv")
    monkeypatch.setattr(R, "ROOT", tmp_path)
    monkeypatch.setattr(R, "FUNCTIONS_CSV", csv)
    return leaf, hand, csv


def test_main_dry_run_and_refusals(tmp_path, functions_csv, monkeypatch, capsys):
    leaf, hand, csv = _tree(tmp_path, functions_csv, monkeypatch)
    before = csv.read_text()
    assert R.main(["0x71007cd220", "_Z15Unk_7cd220_callPK10Unk_7cd220h"]) == 0
    out = capsys.readouterr().out
    assert "+void Unk_7cd220_call(const Unk_7cd220* self, u8 value) {" in out
    assert "+u32 Unk_7cd220_call(const Unk_7cd220* self, u8 value);" in out
    assert "declares Unk_7cd220_call with other parameters" in out and "dry run" in out
    assert csv.read_text() == before and leaf.read_text() == LEAF and hand.read_text() == HAND
    # a name another row has, another function's name, an address with no function
    assert R.main(["0x71007cd220", "_Z15Unk_9a0000_callv", "--apply"]) == 2
    assert R.main(["0x71007cd220", "_Z15Unk_7cd221_callPK10Unk_7cd220h", "--apply"]) == 2
    assert R.main(["0x71007cd224", "_Z15Unk_7cd220_callPK10Unk_7cd220h", "--apply"]) == 2
    assert csv.read_text() == before


def test_main_apply_checks_what_it_touched(tmp_path, functions_csv, monkeypatch, capsys):
    leaf, hand, csv = _tree(tmp_path, functions_csv, monkeypatch)
    calls = []

    def fake_check(addrs, update=False, build=True):
        calls.append((sorted(addrs), update, build))
        return True, "", {0x7cd220: True, 0x8a9c50: True}

    monkeypatch.setattr(R, "run_check", fake_check)
    assert R.main(["0x71007cd220", "_Z15Unk_7cd220_callPK10Unk_7cd220h", "--update"]) == 0
    assert calls == [([0x7cd220, 0x8a9c50], False, True), ([0x7cd220, 0x8a9c50], True, False)]
    rows = {f.sword: f for f in read_functions_csv(csv)}
    assert rows[0x7cd220].name == "_Z15Unk_7cd220_callPK10Unk_7cd220h"
    assert "u8 value) {" in leaf.read_text() and "u8 value);" in hand.read_text()
    out = capsys.readouterr().out
    assert "0x71008a9c50 _Z6CallerPK10Unk_7cd220h: M -> OK" in out and "1 newly matching" in out


def test_main_rolls_back_a_regression(tmp_path, functions_csv, monkeypatch):
    leaf, hand, csv = _tree(tmp_path, functions_csv, monkeypatch)
    before = csv.read_text()
    monkeypatch.setattr(R, "run_check", lambda addrs, update=False, build=True: (True, "", {0x7cd220: False}))
    assert R.main(["0x71007cd220", "_Z15Unk_7cd220_callPK10Unk_7cd220h", "--apply"]) == 1
    assert csv.read_text() == before and leaf.read_text() == LEAF and hand.read_text() == HAND
    # a build that fails goes back too; --keep keeps it
    monkeypatch.setattr(R, "run_check", lambda addrs, update=False, build=True: (False, "error", {}))
    assert R.main(["0x71007cd220", "_Z15Unk_7cd220_callPK10Unk_7cd220h", "--apply"]) == 1
    assert csv.read_text() == before
    assert R.main(["0x71007cd220", "_Z15Unk_7cd220_callPK10Unk_7cd220h", "--apply", "--keep"]) == 0
    assert csv.read_text() != before


def test_main_from_file(tmp_path, functions_csv, monkeypatch, write_csv):
    leaf, hand, csv = _tree(tmp_path, functions_csv, monkeypatch)
    req = write_csv("retypes.csv", "Address,Name\n0x71007cd220,_Z15Unk_7cd220_callPK10Unk_7cd220h\n")
    assert R.main(["--from-file", str(req), "--apply", "--no-check"]) == 0
    assert "u8 value) {" in leaf.read_text()
    # again: already done
    assert R.main(["--from-file", str(req), "--apply", "--no-check"]) == 0


def test_main_hand_definitions(tmp_path, functions_csv, monkeypatch):
    """A hand-written definition stops it, unless --hand-definitions."""
    leaf, hand, csv = _tree(tmp_path, functions_csv, monkeypatch)
    monkeypatch.setattr(R, "run_check", lambda addrs, update=False, build=True: (True, "", {0x8a9c50: True}))
    assert R.main(["0x71008a9c50", "_Z6CallerPK10Unk_7cd220j", "--apply"]) == 1
    assert hand.read_text() == HAND
    assert R.main(["0x71008a9c50", "_Z6CallerPK10Unk_7cd220j", "--apply", "--hand-definitions"]) == 0
    assert "u32 Caller(const Unk_7cd220* p, u32 index) {" in hand.read_text()


def test_no_forward_declaration_of_builtins_or_old_types():
    old, new = R.check_rename("_Z10Unk_67be60P10Unk_67be60m", "_Z10Unk_67be60P10Unk_67be60PKt")
    out, e = R.edit_text("void Unk_67be60(Unk_67be60* self, u64 value);\n", old, new, generated=False)
    assert out == "void Unk_67be60(Unk_67be60* self, const u16* value);\n"
