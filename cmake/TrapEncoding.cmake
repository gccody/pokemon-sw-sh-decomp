# Gives every object the NX trap encoding. CMakeLists.txt includes this right
# after cmake/CodegenFlags.cmake, before any target is defined.
#
# Every trap in the originals is the word 0xe7ffdefe (in `main` and in the
# SDK modules Nintendo builds, both games), and none of them contains a `brk`.
# Upstream clang puts its traps (`llvm.trap`) in the same places but encodes
# them as `brk #1`. No clang option changes that, so each object is rewritten
# right after it is compiled: tools/fix_traps.py runs the compiler and then
# replaces `brk #1` in the object's code with 0xe7ffdefe, and touches nothing
# else (see its docstring). docs/compiler.md, section "Traps", has the evidence.
#
# How: the script is the C and C++ compiler launcher, so it applies to `pkmn`
# and to every COMPILER_VERSION library target alike (they are created after
# this, and the launcher variables initialize their properties). Ninja runs
#   <python> tools/fix_traps.py --run -- <compiler> <flags> -o <object> -c <source>
# as one build step, so the object is never left un-rewritten. CMake doesn't
# write the launcher into compile_commands.json, so clangd and tools/check.py
# see the plain compiler command.
#
# A launcher the user configured (-DCMAKE_CXX_COMPILER_LAUNCHER=ccache) still
# runs: it comes after `--`, so the script runs it with the compiler.
#
# The script uses only the Python standard library, so any Python 3.8+ works.
# Configure picks one with find_package(Python3); -DPython3_EXECUTABLE=<python>
# chooses it. Editing tools/fix_traps.py doesn't rebuild objects by itself:
# rebuild with `cmake --build --preset <game> --clean-first` after changing it.

find_package(Python3 3.8 REQUIRED COMPONENTS Interpreter)

set(PKMN_FIX_TRAPS "${CMAKE_CURRENT_LIST_DIR}/../tools/fix_traps.py")
get_filename_component(PKMN_FIX_TRAPS "${PKMN_FIX_TRAPS}" ABSOLUTE)
foreach(lang IN ITEMS C CXX)
  set(CMAKE_${lang}_COMPILER_LAUNCHER
    "${Python3_EXECUTABLE}" "${PKMN_FIX_TRAPS}" --run -- $CACHE{CMAKE_${lang}_COMPILER_LAUNCHER})
endforeach()
# For tools/check.py: this build dir rewrites traps.
set(PKMN_TRAP_REWRITE "${PKMN_FIX_TRAPS}" CACHE INTERNAL
  "tools/fix_traps.py runs on every object (cmake/TrapEncoding.cmake)")
