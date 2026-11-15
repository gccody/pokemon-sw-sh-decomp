# Cross toolchain for the Switch (NX64, AArch64) - object files only.
#
# The compiler is picked, in order, from:
#   -DPKMN_CLANG_ROOT=<dir>     (directory containing bin/clang++)
#   $ENV{PKMN_CLANG_ROOT}
#   <repo>/toolchain/clang      (clang 7.0.1, the matching compiler: `python tools/get_llvm.py`)
#   <repo>/toolchain/llvm-19    (fallback so the pipeline works; will NOT match non-trivial code)
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR aarch64)
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

get_filename_component(_repo "${CMAKE_CURRENT_LIST_DIR}/.." ABSOLUTE)
if(NOT PKMN_CLANG_ROOT)
  if(DEFINED ENV{PKMN_CLANG_ROOT})
    set(PKMN_CLANG_ROOT "$ENV{PKMN_CLANG_ROOT}")
  elseif(EXISTS "${_repo}/toolchain/clang/bin")
    set(PKMN_CLANG_ROOT "${_repo}/toolchain/clang")
  else()
    set(PKMN_CLANG_ROOT "${_repo}/toolchain/llvm-19")
  endif()
endif()
set(PKMN_CLANG_ROOT "${PKMN_CLANG_ROOT}" CACHE PATH "Clang used to build the decomp")

if(CMAKE_HOST_WIN32)
  set(_exe ".exe")
endif()
set(CMAKE_C_COMPILER   "${PKMN_CLANG_ROOT}/bin/clang${_exe}")
set(CMAKE_CXX_COMPILER "${PKMN_CLANG_ROOT}/bin/clang++${_exe}")
set(CMAKE_C_COMPILER_TARGET   aarch64-none-elf)
set(CMAKE_CXX_COMPILER_TARGET aarch64-none-elf)

# Codegen flags shared by every TU, identified against the original with
# tools/compiler_sweep.py (docs/compiler.md has the evidence for each one).
# The first group recreates what Nintendo's NX clang does by default but
# upstream clang for aarch64-none-elf does not.
set(PKMN_CODEGEN_FLAGS
  -mcpu=cortex-a57+fp+simd+crypto+crc   # A57 scheduling model; generic/a53 do not match
  -D__ELF__                             # NX triple is ELF (upstream none-elf leaves it undefined)
  -funwind-tables                       # every function has an FDE; CFI also pins the prologue
  -mno-implicit-float                   # memcpy/memset/store merging use GPRs, never q-regs
  -fPIC
  -fno-omit-frame-pointer
  -fno-strict-aliasing
  -ffunction-sections
  -fdata-sections
  -fno-exceptions                       # game code FDEs have no personality/LSDA
  -fno-rtti
  -fno-common
  -fno-short-enums
  -nostdinc++
  -O3
)
string(REPLACE ";" " " _flags "${PKMN_CODEGEN_FLAGS}")
set(CMAKE_C_FLAGS_INIT   "${_flags}")
set(CMAKE_CXX_FLAGS_INIT "${_flags}")
set(CMAKE_C_OUTPUT_EXTENSION   .o)
set(CMAKE_CXX_OUTPUT_EXTENSION .o)
