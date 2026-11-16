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
#     [COMPILER_VERSION <version>])         # clang version the library was built with
#
# <dir> is relative to the repo root (e.g. lib/lua). The settings apply to every
# source of the `pkmn` target under <dir>/, recursively, and to nothing else:
# lib/lua does not match lib/luajit/. A directory with no sources (not vendored
# yet, or missing) is fine; the entry is just reported as empty.
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
#
# Known limitation: the compiler itself is global. One CMake build uses one
# clang (CMAKE_<LANG>_COMPILER), so a library built with a different clang
# version (PhysX: clang 6.0.1) cannot be reproduced by flags. COMPILER_VERSION
# only records that version: if the library has sources and the configured
# compiler's version differs, configuring prints a warning that those sources
# will not match. Building such a library with its own compiler is an open
# question (a separate CMake build or ExternalProject per compiler, merged by
# check.py), not something this mechanism does.

set_property(GLOBAL PROPERTY PKMN_LIBRARY_SETTINGS_DIRS "")

function(pkmn_library_settings dir)
  cmake_parse_arguments(PARSE_ARGV 1 arg "" "EVIDENCE;COMPILER_VERSION" "DEFINES;OPTIONS")
  if(arg_UNPARSED_ARGUMENTS)
    message(FATAL_ERROR "pkmn_library_settings(${dir}): unknown arguments: ${arg_UNPARSED_ARGUMENTS}")
  endif()
  if(NOT arg_EVIDENCE)
    message(FATAL_ERROR "pkmn_library_settings(${dir}): EVIDENCE <docs/compiler.md section> is required")
  endif()
  if(NOT TARGET pkmn)
    message(FATAL_ERROR "pkmn_library_settings(${dir}): call it after add_library(pkmn ...)")
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
  set(prefix "${PROJECT_SOURCE_DIR}/${dir}/")
  string(LENGTH "${prefix}" prefix_len)
  get_target_property(all_sources pkmn SOURCES)
  set(sources "")
  foreach(src IN LISTS all_sources)
    get_filename_component(abs "${src}" ABSOLUTE BASE_DIR "${PROJECT_SOURCE_DIR}")
    string(SUBSTRING "${abs}" 0 ${prefix_len} head)
    if(head STREQUAL prefix)
      list(APPEND sources "${abs}")
    endif()
  endforeach()
  list(LENGTH sources count)

  if(count EQUAL 0)
    message(STATUS "Library settings: ${dir}: no sources yet (${arg_EVIDENCE})")
    return()
  endif()

  if(arg_DEFINES)
    set_property(SOURCE ${sources} APPEND PROPERTY COMPILE_DEFINITIONS ${arg_DEFINES})
  endif()
  if(arg_OPTIONS)
    set_property(SOURCE ${sources} APPEND PROPERTY COMPILE_OPTIONS ${arg_OPTIONS})
  endif()
  message(STATUS "Library settings: ${dir}: ${count} sources (${arg_EVIDENCE})")

  if(arg_COMPILER_VERSION)
    if(CMAKE_CXX_COMPILER_VERSION)
      set(have "${CMAKE_CXX_COMPILER_VERSION}")
    else()
      set(have "${CMAKE_C_COMPILER_VERSION}")
    endif()
    if(NOT have VERSION_EQUAL arg_COMPILER_VERSION)
      message(WARNING
        "${dir} was built with clang ${arg_COMPILER_VERSION}, but this build uses clang ${have}. "
        "Its ${count} sources compile with the library's flags, but most of their functions "
        "will not match: per-library settings can't change the compiler (${arg_EVIDENCE}).")
    endif()
  endif()
endfunction()
