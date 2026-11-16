"""Symbol naming convention shared by check.py, funcs.py, lint.py and
compiler_sweep.py.

Names in data/functions.csv and data/data_symbols.csv are the symbol names the
compiler emits, so check.py can match compiled functions to rows by name.

Global symbols are recorded as-is: `luaL_error`, `_ZN4pkmn10GetVersionEv`.

Local symbols (STB_LOCAL: C `static` functions and data, C++ internal-linkage
and anonymous-namespace symbols) are file-qualified, because different
translation units can each have their own `getfield`. The qualified name is
`<symbol>@<stem>`, where `<stem>` is the file name of the translation unit
(the .c/.cpp that was compiled) without its extension:

    getfield@lauxlib     static int getfield(...) in lib/lua/lauxlib.c
    getfield@loslib      static int getfield(...) in lib/lua/loslib.c

Every local symbol is qualified, whether or not its name collides today, so
adding a file never renames existing rows. A static function emitted from a
header belongs to the TU that includes it. Moving a file to another directory
keeps its names; renaming the file renames its local symbols.
"""
from __future__ import annotations

import re
from pathlib import PurePath

LOCAL_SEP = "@"

# A C identifier or an Itanium-mangled C++ name (also identifier characters).
_SYMBOL = re.compile(r"[A-Za-z_][A-Za-z0-9_.$]*")
_STEM = re.compile(r"[A-Za-z0-9_+-][A-Za-z0-9_.+-]*")


def file_stem(source: str | PurePath) -> str:
    """Stem used to qualify the local symbols of a translation unit."""
    return PurePath(str(source).replace("\\", "/")).stem


def qualify(symbol: str, source: str | PurePath | None, local: bool) -> str:
    """CSV name of `symbol` defined in translation unit `source`."""
    if not local or source is None:
        return symbol
    return f"{symbol}{LOCAL_SEP}{file_stem(source)}"


def split(name: str) -> tuple[str, str | None]:
    """`getfield@lauxlib` -> ("getfield", "lauxlib"); global names -> (name, None)."""
    sym, sep, stem = name.partition(LOCAL_SEP)
    return (sym, stem) if sep else (name, None)


def is_valid_name(name: str) -> bool:
    """A symbol name, optionally file-qualified (see the module docstring)."""
    sym, stem = split(name)
    if not _SYMBOL.fullmatch(sym):
        return False
    return stem is None or bool(_STEM.fullmatch(stem))
