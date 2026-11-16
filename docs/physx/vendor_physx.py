"""Vendor the PhysX 3.4 TUs that are in the binary (the first step of
lib/physx, see docs/compiler.md, PhysX: Reproducing lib/physx).

    python docs/physx/vendor_physx.py <v3.4.2 tree> <HEAD tree> <NX headers> <stage dir> <out dir>

Run it from the repository root. The TU list, include-path order and defines
come from v3.4.2's linux64 makefiles (the revision the binary was built from).
File contents come from HEAD (BSD-3). Only headers that the TUs actually read
are copied (clang -M). Foundation's Unix TUs are left out: the binary has the
Switch ones. <NX headers> holds the stand-in headers at their in-tree paths
(lib/physx's are the current ones). It writes <out dir>/physx (for lib/physx),
<out dir>/libcxx (for include/libcxx) and <out dir>/physx_build.json (TUs,
include directories, defines). The Switch TUs and lib/physx's README and
LICENSE aren't generated: they're maintained in lib/physx.
"""
import json
import os
import re
import shutil
import subprocess
import sys
from pathlib import Path

V342, HEAD, SHIM, STAGE, OUT = (Path(a).resolve() for a in sys.argv[1:6])
REPO = Path.cwd()
LIBS = ("PxFoundation PxTask PhysXCommon PhysX SimulationController LowLevel LowLevelAABB "
        "LowLevelDynamics LowLevelCloth LowLevelParticles SceneQuery PhysXExtensions").split()
MK = Path("PhysX_3.4/Source/compiler/linux64")
SKIP = re.compile(r"/(gpu|windows|linux|sse2|avx|PhysXGpu)/|PhysXIndicator|PxGpu|NpPhysicsGpu")
UNIX_TU = re.compile(r"PxShared/src/foundation/src/unix/")
CLANG = REPO / "toolchain/clang-6.0.1/bin" / ("clang++.exe" if os.name == "nt" else "clang++")
LIBCXX = (REPO / "toolchain/candidates/src/libcxx-7.0.1/include").resolve()
MUSL = (REPO / "include/libc").resolve()
DEST = OUT / "physx"
DEST_CXX = OUT / "libcxx"


def rel(p: Path, root: Path) -> str:
    return p.resolve().relative_to(root).as_posix()


srcs, incs, defs = [], [], []
for lib in LIBS:
    text = (V342 / MK / f"Makefile.{lib}.mk").read_text()
    for kind, v in re.findall(rf"^{lib}_(release_hpaths|release_defines|cppfiles)\s*\+=\s*(\S+)", text, re.M):
        p = Path(os.path.normpath(V342 / MK / v))
        if kind == "release_hpaths" and p.exists():
            r = rel(p, V342)
            if r not in incs:
                incs.append(r)
        elif kind == "cppfiles" and p.exists() and not SKIP.search(v):
            r = rel(p, V342)
            if not UNIX_TU.match(r):
                srcs.append(r)
        elif kind == "release_defines" and not re.search(r"EXPORTS|_DLL|PVD|NDEBUG|STATIC_LIB", v):
            defs.append(v)
# the sweep put these two first (physx_args.py), after the shim directory
incs = ["PxShared/src/foundation/include/unix", "PxShared/src/task/include"] + \
       [i for i in incs if i not in ("PxShared/src/foundation/include/unix", "PxShared/src/task/include")]
missing = [s for s in srcs if not (HEAD / s).exists()]
print(f"{len(srcs)} TUs ({len(missing)} missing at HEAD: {missing}), {len(incs)} include dirs, defines {sorted(set(defs))}")

# Stage: the HEAD tree plus the NX stand-in headers at their in-tree places.
if STAGE.exists():
    shutil.rmtree(STAGE)
shutil.copytree(HEAD, STAGE)
for f in SHIM.rglob("*"):
    if f.is_file():
        t = STAGE / f.relative_to(SHIM)
        t.parent.mkdir(parents=True, exist_ok=True)
        shutil.copy2(f, t)

flags = ["--target=aarch64-none-elf", "-mcpu=cortex-a57+fp+simd+crypto+crc", "-D__ELF__", "-nostdinc++",
         "-std=gnu++14", "-fno-rtti", "-fexceptions", "-D__NX__", "-DNDEBUG", "-DPX_PHYSX_STATIC_LIB",
         "-DPX_FOUNDATION_DLL=0", "-DPX_SUPPORT_PVD=0", "-D_LIBCPP_HAS_MUSL_LIBC",
         "-D_LIBCPP_HAS_THREAD_API_PTHREAD", *[f"-D{d}" for d in sorted(set(defs))]]
flags += [a for i in incs for a in ("-I", str(STAGE / i))]
flags += ["-isystem", str(LIBCXX), "-isystem", str(MUSL)]

deps: set[Path] = set()
bad = []
for s in srcs:
    r = subprocess.run([str(CLANG), *flags, "-M", str(STAGE / s)], capture_output=True, text=True)
    if r.returncode:
        bad.append((s, r.stderr[:400]))
        continue
    body = r.stdout.replace("\\\n", " ")
    for tok in re.split(r"(?<!\\) ", body.split(":", 1)[1] if ": " in body else body):
        tok = tok.strip().replace("\\ ", " ")
        if tok:
            deps.add(Path(tok).resolve())
for s, e in bad:
    print("FAILED", s, e)
if bad:
    raise SystemExit(1)

for d in (DEST, DEST_CXX):
    if d.exists():
        shutil.rmtree(d)
n_px = n_cxx = 0
other = set()
for d in sorted(deps):
    try:
        r = rel(d, STAGE)
        t = DEST / r
        n_px += 1
    except ValueError:
        try:
            r = rel(d, LIBCXX)
            t = DEST_CXX / r
            n_cxx += 1
        except ValueError:
            if not str(d).startswith(str(MUSL)):
                other.add(d)
            continue
    t.parent.mkdir(parents=True, exist_ok=True)
    shutil.copy2(d, t)
print(f"copied {n_px} PhysX files (TUs + headers), {n_cxx} libc++ headers; outside: {sorted(other)[:10]}")
used_incs = [i for i in incs if (DEST / i).is_dir()]
(OUT / "physx_build.json").write_text(json.dumps(
    {"srcs": srcs, "incs": incs, "used_incs": used_incs, "defs": sorted(set(defs))}, indent=1))
print("unused include dirs:", [i for i in incs if i not in used_incs])
