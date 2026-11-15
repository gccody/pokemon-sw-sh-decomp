#!/usr/bin/env python3
"""Extract the original executables from your own Sword/Shield dumps.

    python tools/setup.py                       # auto-finds assets/Pokemon */*.xci
    python tools/setup.py --sword X.xci --shield Y.xci --keys ~/.switch/prod.keys

Writes data/original/<version>/{main,main.npdm,sdk,subsdk*,rtld} (gitignored)
and verifies each `main` against tools/versions.json, so everyone decompiles
the exact same build. Reads the ExeFS straight out of the XCI - nothing large
is copied.
"""
from __future__ import annotations

import argparse
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from common import ORIGINAL, ROOT, VERSION_INFO, VERSIONS, load_module  # noqa: E402
from nx.container import default_keys_path, extract_exefs_from_xci, load_keys  # noqa: E402
from nx.nso import Nso  # noqa: E402


def find_dump(version: str) -> Path | None:
    title = VERSION_INFO[version]["title"]
    hits = sorted((ROOT / "assets").glob(f"{title}/*.xci"))
    return hits[0] if hits else None


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    for v in VERSIONS:
        ap.add_argument(f"--{v}", type=Path, help=f"path to {VERSION_INFO[v]['title']} .xci")
    ap.add_argument("--keys", type=Path, default=default_keys_path())
    ap.add_argument("--force", action="store_true", help="accept a build that doesn't match versions.json")
    args = ap.parse_args()

    if not args.keys.exists():
        print(f"error: keys file {args.keys} not found (dump prod.keys from your own console)", file=sys.stderr)
        return 1
    keys = load_keys(args.keys)

    ok = True
    for v in VERSIONS:
        dump = getattr(args, v) or find_dump(v)
        if dump is None:
            print(f"[{v}] no dump found - skipping (pass --{v} PATH)")
            continue
        print(f"[{v}] reading {dump}")
        files, nca = extract_exefs_from_xci(dump, keys)
        expected = VERSION_INFO[v]
        tid = f"{nca.title_id:016x}"
        nso = Nso(files["main"])
        build_id = nso.build_id[:0x14].hex()
        good = tid == expected["title_id"] and build_id == expected["main_build_id"] \
            and nso.text_sha256() == expected["main_text_sha256"]
        if not good:
            print(f"[{v}] WARNING: title {tid} / build id {build_id} does not match the target "
                  f"({expected['title_id']} v{expected['version']} / {expected['main_build_id']})")
            if not args.force:
                ok = False
                continue
        out = ORIGINAL / v
        out.mkdir(parents=True, exist_ok=True)
        for name, blob in files.items():
            (out / name).write_bytes(blob)
        mod = load_module(v)  # warm the cache + sanity-check
        print(f"[{v}] OK  build {build_id}  {len(mod['functions'])} functions  -> {out.relative_to(ROOT)}")
    return 0 if ok else 1


if __name__ == "__main__":
    raise SystemExit(main())
