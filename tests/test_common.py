from __future__ import annotations

from common import BASE, ROOT, Function, read_functions_csv, write_functions_csv


def test_functions_csv_round_trips_byte_for_byte(tmp_path):
    """Every tool rewrites functions.csv via write_functions_csv; it must not churn the file."""
    src = ROOT / "data" / "functions.csv"
    out = tmp_path / "functions.csv"
    write_functions_csv(out, read_functions_csv(src))
    assert out.read_bytes() == src.read_bytes()


def test_addresses_are_stored_relative_to_base(functions_csv):
    path = functions_csv("0x00000071007c2d80,8,0x00000071007c2db0,8,common,O,_ZN4pkmn10GetVersionEv")
    (fn,) = read_functions_csv(path)
    assert fn.sword == 0x7C2D80
    assert fn.shield == 0x7C2DB0
    assert fn.sword_str == "0x00000071007c2d80"
    assert fn.addr("shield") + BASE == 0x71007C2DB0


def test_display_name_falls_back_to_address():
    sw = Function(sword=0x1234, shield=0x1238, sword_size=4, shield_size=4, scope="common")
    sh_only = Function(sword=None, shield=0x40, sword_size=None, shield_size=4, scope="shield")
    assert sw.display_name == "FUN_7100001234"
    assert sh_only.display_name == "FUN_sh_7100000040"
    assert not sh_only.in_version("sword")
    sw.name = "_Z3foov"
    assert sw.display_name == "_Z3foov"


def test_key_is_stable_across_names():
    a = Function(sword=0x10, shield=0x20, sword_size=4, shield_size=4, scope="common")
    b = Function(sword=0x10, shield=0x20, sword_size=4, shield_size=4, scope="common", name="_Z1av")
    assert a.key == b.key == "sw:10"
