# Per-library build settings.
#
# Every TU is built with the global codegen flags from toolchain-nx64.cmake.
# Those flags never change to make one function match. Some vendored libraries
# were built by their vendor (or by Game Freak) with a different configuration,
# and that configuration is recorded here, one entry per library directory:
#
#   pkmn_library_settings(<dir>
#     EVIDENCE <docs/compiler.md section>   # required
#     [DEFINES <name>[=<value>] ...]        # -D..., after the global defines
#     [OPTIONS <flag> ...]                  # compile flags, after the global flags
#     [INCLUDES <dir> ...]                  # -I..., searched before the shared includes
#     [SYSTEM_INCLUDES <dir> ...]           # -isystem..., searched before musl
#     [COMPILER_VERSION <version>])         # clang version that builds the library
#
# <dir> is relative to the repo root (e.g. lib/lua). The settings apply to every
# source under <dir>/, recursively, and to nothing else: lib/lua does not match
# lib/luajit/. A directory with no sources (not vendored yet, or missing) is
# fine; the entry is just reported as empty.
#
# Rules for an entry:
# - It needs evidence: a section of docs/compiler.md that shows, with sweep or
#   check.py numbers, that the library was built this way. EVIDENCE names that
#   section, and a comment above the entry says what it found.
# - Settings live only here. Don't add per-file or per-target flags elsewhere in
#   CMake, and don't change the global flags for a library.
# - OPTIONS are applied as source-file COMPILE_OPTIONS, which CMake puts after
#   CMAKE_<LANG>_FLAGS, the -std flag and the target's options. So a library
#   option wins over the global one it contradicts (-fexceptions after the
#   global -fno-exceptions, -std=gnu++14 after -std=c++17). Generator
#   expressions work, e.g. $<$<COMPILE_LANGUAGE:CXX>:-std=gnu++14>.
# - Each directory may have one entry. Nested entries (lib/foo and lib/foo/bar)
#   both apply to the inner directory, in call order; avoid them unless needed.
#   Only one of two nested entries may have a COMPILER_VERSION.
#
# INCLUDES and SYSTEM_INCLUDES
# ----------------------------
# Include directories for the library's sources only, searched before the
# shared ones (include/, src/, lib/ and the musl headers in include/libc, all
# on pkmn_common). The command line becomes
#   <INCLUDES as -I> <SYSTEM_INCLUDES as -isystem> -I include -I src -I lib -isystem include/libc
# clang searches every -I directory before every -isystem one, in command-line
# order within each kind. So INCLUDES come first of all, and SYSTEM_INCLUDES
# come after the shared -I directories but before musl. That is what libc++
# needs: its <stddef.h>, <stdlib.h>, ... wrappers must be found before musl's
# (they #include_next them), and as system headers. With libc++ as -isystem in
# OPTIONS it comes after musl, and <cstddef> fails with a max_align_t
# redefinition. INCLUDES would work (for PhysX, byte-identical objects) but
# makes libc++ a user include, so use SYSTEM_INCLUDES.
#
# Paths are relative to the repo root, like <dir>: no absolute paths, no "..",
# no generator expressions. They may point into toolchain/ (gitignored,
# downloaded) as well as into the tracked tree, and they must exist once <dir>
# has sources (an entry without sources doesn't check them). A directory may be
# a SYSTEM_INCLUDE of some entries or an INCLUDE of others, not both, and it
# can't be one of the shared directories.
#
# libc++: when PhysX sources land, its entry gets `SYSTEM_INCLUDES
# include/libcxx` with libc++ 7.0.1's include/ directory vendored there,
# unchanged, the way musl's headers are vendored in include/libc. Nothing is
# vendored until then. (The PhysX research builds use
# toolchain/candidates/src/libcxx-7.0.1/include, which works here as well.)
#
# How: the directories are the sources' INCLUDE_DIRECTORIES source property,
# which the Ninja generator emits before the target's include directories. That
# works per source, so it's the same for sources in `pkmn` and in a
# COMPILER_VERSION library's own target. A source property can't say "system",
# so SYSTEM_INCLUDES are also added to pkmn_common's
# INTERFACE_SYSTEM_INCLUDE_DIRECTORIES, which makes CMake emit those directories
# with -isystem wherever they appear. It adds no directory to any other TU's
# search path.
#
# COMPILER_VERSION
# ----------------
# The library's sources are compiled by that clang version instead of the main
# one (PKMN_CLANG_ROOT, clang 7.0.1), in the same configure and build, with the
# same global flags, includes and defines plus the entry's DEFINES, OPTIONS,
# INCLUDES and SYSTEM_INCLUDES.
# Only the compiler executable differs. If the main clang already is that
# version, the entry changes nothing.
#
# The compiler comes from, in order:
#   -DPKMN_CLANG_ROOT_<ver>=<dir>   (<ver> with underscores: PKMN_CLANG_ROOT_6_0_1)
#   $ENV{PKMN_CLANG_ROOT_<ver>}
#   <repo>/toolchain/clang-<ver>     (`python tools/get_llvm.py --compiler <ver>`)
# <dir> must contain bin/clang and bin/clang++ (.exe on Windows), and both must
# report `clang version <ver>`. Otherwise configuring fails and says how to
# install it, unless -DPKMN_ALLOW_LIBRARY_COMPILER_FALLBACK=ON: then the
# library is built with the main clang and a warning says its functions won't
# match. A directory without sources never looks for its compiler.
#
# How: the library's sources move from `pkmn` into their own OBJECT library,
# pkmn_<dir as identifier> (pkmn_lib_physx), defined in
# cmake/library-compiler/ with the binary dir build/<game>/libraries/<dir>.
# That directory's CMAKE_<LANG>_COMPILE_OBJECT rule names the library's clang,
# so the Ninja rule and compile_commands.json both show the compiler that runs,
# and tools/check.py finds the objects there like any other. The target links
# pkmn_common, which holds the settings every TU shares; give `pkmn` none of
# its own. Objects depend on the compiler executable, and configuring depends
# on it too, so replacing the compiler (or pointing the override elsewhere)
# re-checks its version and rebuilds the library.

option(PKMN_ALLOW_LIBRARY_COMPILER_FALLBACK
  "Build libraries whose COMPILER_VERSION clang is missing with the main clang (their functions won't match)"
  OFF)

set_property(GLOBAL PROPERTY PKMN_LIBRARY_SETTINGS_DIRS "")
# Targets that own sources: pkmn, plus one per COMPILER_VERSION library.
set_property(GLOBAL PROPERTY PKMN_LIBRARY_TARGETS pkmn)
# Absolute INCLUDES / SYSTEM_INCLUDES of all entries so far, to keep them apart.
set_property(GLOBAL PROPERTY PKMN_LIBRARY_INCLUDES "")
set_property(GLOBAL PROPERTY PKMN_LIBRARY_SYSTEM_INCLUDES "")

# Checks the INCLUDES or SYSTEM_INCLUDES (<kind>) paths of the entry for <dir>
# and sets <out> to their absolute paths. With <must_exist>, they must exist.
function(_pkmn_library_include_dirs dir kind must_exist out)
  set(other_kind INCLUDES)
  if(kind STREQUAL "INCLUDES")
    set(other_kind SYSTEM_INCLUDES)
  endif()
  get_property(other GLOBAL PROPERTY PKMN_LIBRARY_${other_kind})
  get_target_property(shared pkmn_common INTERFACE_INCLUDE_DIRECTORIES)
  set(result "")
  foreach(path IN LISTS ARGN)
    string(REGEX REPLACE "/+$" "" path "${path}")
    if(path STREQUAL "" OR IS_ABSOLUTE "${path}" OR path MATCHES "(^|/)\\.\\.?(/|$)|\\$<|\\\\")
      message(FATAL_ERROR "pkmn_library_settings(${dir}): ${kind} '${path}' must be a plain path "
        "relative to the repo root, with forward slashes (e.g. include/libcxx)")
    endif()
    set(abs "${PROJECT_SOURCE_DIR}/${path}")
    if(must_exist AND NOT IS_DIRECTORY "${abs}")
      message(FATAL_ERROR "pkmn_library_settings(${dir}): ${kind} ${path} is not a directory (${abs})")
    endif()
    if(abs IN_LIST shared)
      message(FATAL_ERROR "pkmn_library_settings(${dir}): ${kind} ${path} is already a shared include "
        "directory (pkmn_common)")
    endif()
    if(abs IN_LIST other)
      message(FATAL_ERROR "pkmn_library_settings(${dir}): ${path} is in the ${other_kind} of another "
        "entry; a directory is either a system include or not, for every library")
    endif()
    list(APPEND result "${abs}")
  endforeach()
  set(${out} "${result}" PARENT_SCOPE)
endfunction()

# Prints `clang version X.Y.Z` of <exe> into <out> (empty if it doesn't run).
function(_pkmn_clang_version exe out)
  execute_process(COMMAND "${exe}" --version
    OUTPUT_VARIABLE text ERROR_VARIABLE text RESULT_VARIABLE rc)
  if(rc EQUAL 0 AND text MATCHES "clang version ([0-9]+\\.[0-9]+\\.[0-9]+)")
    set(${out} "${CMAKE_MATCH_1}" PARENT_SCOPE)
  else()
    set(${out} "" PARENT_SCOPE)
  endif()
endfunction()

# Finds the clang for COMPILER_VERSION <version>. Sets <out_root> to its root,
# or to "" and <out_error> to the reason.
function(_pkmn_find_library_compiler version out_root out_error)
  string(REPLACE "." "_" id "${version}")
  set(var "PKMN_CLANG_ROOT_${id}")
  if("${${var}}" STREQUAL "")
    if(DEFINED ENV{${var}})
      set(${var} "$ENV{${var}}")
    else()
      set(${var} "${PROJECT_SOURCE_DIR}/toolchain/clang-${version}")
    endif()
  endif()
  set(${var} "${${var}}" CACHE PATH "clang ${version} for libraries with COMPILER_VERSION ${version}")
  set(root "${${var}}")

  if(CMAKE_HOST_WIN32)
    set(exe ".exe")
  endif()
  set(error "")
  foreach(name IN ITEMS clang clang++)
    set(path "${root}/bin/${name}${exe}")
    if(NOT EXISTS "${path}")
      set(error "${path} doesn't exist")
      break()
    endif()
    _pkmn_clang_version("${path}" have)
    if(NOT have VERSION_EQUAL version)
      if(have STREQUAL "")
        set(have "no clang version")
      else()
        set(have "clang ${have}")
      endif()
      set(error "${path} reports ${have}, not ${version}")
      break()
    endif()
  endforeach()

  if(error)
    set(${out_root} "" PARENT_SCOPE)
    set(${out_error} "${error} (${var}=${root})" PARENT_SCOPE)
  else()
    set(${out_root} "${root}" PARENT_SCOPE)
    set(${out_error} "" PARENT_SCOPE)
  endif()
endfunction()

# Moves <sources> out of `pkmn` into a new OBJECT library compiled by the clang
# under <root>. Sets <out_target> to its name.
function(_pkmn_add_library_compiler_target dir root sources out_target)
  string(MAKE_C_IDENTIFIER "${dir}" id)
  set(PKMN_LIBRARY_TARGET "pkmn_${id}")
  set(PKMN_LIBRARY_SOURCES ${sources})
  if(CMAKE_HOST_WIN32)
    set(exe ".exe")
  endif()
  set(PKMN_LIBRARY_C_COMPILER "${root}/bin/clang${exe}")
  set(PKMN_LIBRARY_CXX_COMPILER "${root}/bin/clang++${exe}")

  # Settings that earlier, outer entries put on these sources, in `pkmn`'s
  # directory. Source properties are per directory, so copy them over.
  set(i 0)
  foreach(src IN LISTS sources)
    foreach(prop IN ITEMS COMPILE_DEFINITIONS COMPILE_OPTIONS INCLUDE_DIRECTORIES)
      get_property(saved_${i}_${prop} SOURCE "${src}" TARGET_DIRECTORY pkmn PROPERTY ${prop})
    endforeach()
    math(EXPR i "${i} + 1")
  endforeach()

  get_target_property(pkmn_sources pkmn SOURCES)
  set(rest "")
  foreach(src IN LISTS pkmn_sources)
    get_filename_component(abs "${src}" ABSOLUTE BASE_DIR "${PROJECT_SOURCE_DIR}")
    if(NOT abs IN_LIST sources)
      list(APPEND rest "${src}")
    endif()
  endforeach()
  set_property(TARGET pkmn PROPERTY SOURCES ${rest})

  add_subdirectory("${CMAKE_CURRENT_FUNCTION_LIST_DIR}/library-compiler"
    "${PROJECT_BINARY_DIR}/libraries/${dir}")

  set(i 0)
  foreach(src IN LISTS sources)
    foreach(prop IN ITEMS COMPILE_DEFINITIONS COMPILE_OPTIONS INCLUDE_DIRECTORIES)
      if(NOT "${saved_${i}_${prop}}" STREQUAL "")
        set_property(SOURCE "${src}" TARGET_DIRECTORY ${PKMN_LIBRARY_TARGET}
          PROPERTY ${prop} "${saved_${i}_${prop}}")
      endif()
    endforeach()
    math(EXPR i "${i} + 1")
  endforeach()
  set_property(SOURCE ${sources} TARGET_DIRECTORY ${PKMN_LIBRARY_TARGET}
    APPEND PROPERTY OBJECT_DEPENDS "${PKMN_LIBRARY_C_COMPILER}" "${PKMN_LIBRARY_CXX_COMPILER}")
  set_property(DIRECTORY "${PROJECT_SOURCE_DIR}" APPEND PROPERTY CMAKE_CONFIGURE_DEPENDS
    "${PKMN_LIBRARY_C_COMPILER}" "${PKMN_LIBRARY_CXX_COMPILER}")

  set_property(GLOBAL APPEND PROPERTY PKMN_LIBRARY_TARGETS ${PKMN_LIBRARY_TARGET})
  set(${out_target} ${PKMN_LIBRARY_TARGET} PARENT_SCOPE)
endfunction()

function(pkmn_library_settings dir)
  cmake_parse_arguments(PARSE_ARGV 1 arg "" "EVIDENCE;COMPILER_VERSION"
    "DEFINES;OPTIONS;INCLUDES;SYSTEM_INCLUDES")
  if(arg_UNPARSED_ARGUMENTS)
    message(FATAL_ERROR "pkmn_library_settings(${dir}): unknown arguments: ${arg_UNPARSED_ARGUMENTS}")
  endif()
  if(NOT arg_EVIDENCE)
    message(FATAL_ERROR "pkmn_library_settings(${dir}): EVIDENCE <docs/compiler.md section> is required")
  endif()
  if(NOT TARGET pkmn OR NOT TARGET pkmn_common)
    message(FATAL_ERROR "pkmn_library_settings(${dir}): call it after add_library(pkmn ...) and pkmn_common")
  endif()
  if(arg_COMPILER_VERSION AND NOT arg_COMPILER_VERSION MATCHES "^[0-9]+\\.[0-9]+\\.[0-9]+$")
    message(FATAL_ERROR "pkmn_library_settings(${dir}): COMPILER_VERSION is a full clang version, e.g. 6.0.1")
  endif()

  string(REGEX REPLACE "/+$" "" dir "${dir}")
  if(IS_ABSOLUTE "${dir}" OR dir MATCHES "(^|/)\\.\\.?(/|$)")
    message(FATAL_ERROR "pkmn_library_settings(${dir}): give a plain path relative to the repo root")
  endif()
  get_property(seen GLOBAL PROPERTY PKMN_LIBRARY_SETTINGS_DIRS)
  if(dir IN_LIST seen)
    message(FATAL_ERROR "pkmn_library_settings(${dir}): this directory already has an entry")
  endif()
  set_property(GLOBAL APPEND PROPERTY PKMN_LIBRARY_SETTINGS_DIRS "${dir}")

  # Match on the directory prefix plus a slash, so lib/lua doesn't take lib/luajit.
  # Look in every target: an earlier entry may have moved sources out of pkmn.
  set(prefix "${PROJECT_SOURCE_DIR}/${dir}/")
  string(LENGTH "${prefix}" prefix_len)
  get_property(targets GLOBAL PROPERTY PKMN_LIBRARY_TARGETS)
  set(sources "")
  set(moved FALSE)
  foreach(target IN LISTS targets)
    get_target_property(target_sources ${target} SOURCES)
    foreach(src IN LISTS target_sources)
      get_filename_component(abs "${src}" ABSOLUTE BASE_DIR "${PROJECT_SOURCE_DIR}")
      string(SUBSTRING "${abs}" 0 ${prefix_len} head)
      if(head STREQUAL prefix)
        list(APPEND sources "${abs}")
        if(NOT target STREQUAL "pkmn")
          set(moved TRUE)
        endif()
      endif()
    endforeach()
  endforeach()
  list(LENGTH sources count)

  # Paths are checked even without sources; that they exist only with sources.
  if(count EQUAL 0)
    set(must_exist FALSE)
  else()
    set(must_exist TRUE)
  endif()
  _pkmn_library_include_dirs("${dir}" INCLUDES ${must_exist} includes ${arg_INCLUDES})
  _pkmn_library_include_dirs("${dir}" SYSTEM_INCLUDES ${must_exist} system_includes ${arg_SYSTEM_INCLUDES})
  set_property(GLOBAL APPEND PROPERTY PKMN_LIBRARY_INCLUDES ${includes})
  set_property(GLOBAL APPEND PROPERTY PKMN_LIBRARY_SYSTEM_INCLUDES ${system_includes})

  if(count EQUAL 0)
    message(STATUS "Library settings: ${dir}: no sources yet (${arg_EVIDENCE})")
    return()
  endif()

  set(compiler_note "")
  if(arg_COMPILER_VERSION)
    if(moved)
      message(FATAL_ERROR "pkmn_library_settings(${dir}): its sources already get their compiler "
        "from an outer or inner entry with COMPILER_VERSION; only one nested entry may have one")
    endif()
    if(CMAKE_CXX_COMPILER_VERSION VERSION_EQUAL arg_COMPILER_VERSION
        AND CMAKE_C_COMPILER_VERSION VERSION_EQUAL arg_COMPILER_VERSION)
      set(compiler_note ", main clang ${arg_COMPILER_VERSION}")
    else()
      _pkmn_find_library_compiler(${arg_COMPILER_VERSION} root error)
      if(root)
        _pkmn_add_library_compiler_target("${dir}" "${root}" "${sources}" target)
        set(compiler_note ", clang ${arg_COMPILER_VERSION} from ${root}")
        get_property(targets GLOBAL PROPERTY PKMN_LIBRARY_TARGETS)
      elseif(PKMN_ALLOW_LIBRARY_COMPILER_FALLBACK)
        message(WARNING
          "${dir} was built with clang ${arg_COMPILER_VERSION}, which wasn't found: ${error}. "
          "PKMN_ALLOW_LIBRARY_COMPILER_FALLBACK is ON, so its ${count} sources are compiled with "
          "the main clang ${CMAKE_CXX_COMPILER_VERSION} and most of their functions will not match.")
        set(compiler_note ", FALLBACK to main clang ${CMAKE_CXX_COMPILER_VERSION}")
      else()
        string(REPLACE "." "_" id "${arg_COMPILER_VERSION}")
        message(FATAL_ERROR
          "${dir} has ${count} sources that must be compiled with clang ${arg_COMPILER_VERSION} "
          "(${arg_EVIDENCE}), but it wasn't found: ${error}.\n"
          "Install it with `python tools/get_llvm.py --compiler ${arg_COMPILER_VERSION}` "
          "(into toolchain/clang-${arg_COMPILER_VERSION}), or point -DPKMN_CLANG_ROOT_${id}=<dir> "
          "at a clang ${arg_COMPILER_VERSION} with bin/clang and bin/clang++. To build them with the "
          "main clang anyway (they won't match), configure with -DPKMN_ALLOW_LIBRARY_COMPILER_FALLBACK=ON.")
      endif()
    endif()
  endif()

  # Source properties are per directory: set them where each target lives.
  if(arg_DEFINES)
    set_property(SOURCE ${sources} TARGET_DIRECTORY ${targets}
      APPEND PROPERTY COMPILE_DEFINITIONS ${arg_DEFINES})
  endif()
  if(arg_OPTIONS)
    set_property(SOURCE ${sources} TARGET_DIRECTORY ${targets}
      APPEND PROPERTY COMPILE_OPTIONS ${arg_OPTIONS})
  endif()
  if(includes OR system_includes)
    set_property(SOURCE ${sources} TARGET_DIRECTORY ${targets}
      APPEND PROPERTY INCLUDE_DIRECTORIES ${includes} ${system_includes})
  endif()
  if(system_includes)
    # Marks them as system directories (-isystem) for every target; it adds
    # them to no target's search path.
    set_property(TARGET pkmn_common APPEND PROPERTY INTERFACE_SYSTEM_INCLUDE_DIRECTORIES ${system_includes})
  endif()
  message(STATUS "Library settings: ${dir}: ${count} sources${compiler_note} (${arg_EVIDENCE})")
endfunction()
