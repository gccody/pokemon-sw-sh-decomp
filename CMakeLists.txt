cmake_minimum_required(VERSION 3.20)

# One source tree, built once per game. Select the game with PKMN_GAME
# (presets: `cmake --preset sword` / `cmake --preset shield`).
set(PKMN_GAME "sword" CACHE STRING "Game version to build: sword or shield")
set_property(CACHE PKMN_GAME PROPERTY STRINGS sword shield)

if(NOT CMAKE_TOOLCHAIN_FILE)
  set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/cmake/toolchain-nx64.cmake")
endif()

project(pkmn_swsh LANGUAGES C CXX)

# The global codegen flags of the toolchain file, applied on every configure.
include(cmake/CodegenFlags.cmake)
# Traps get the NX encoding (0xe7ffdefe, not brk #1): every object is rewritten
# by tools/fix_traps.py after it is compiled.
include(cmake/TrapEncoding.cmake)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(PKMN_GAME STREQUAL "sword")
  set(_ver PKMN_VERSION_SWORD)
elseif(PKMN_GAME STREQUAL "shield")
  set(_ver PKMN_VERSION_SHIELD)
else()
  message(FATAL_ERROR "PKMN_GAME must be 'sword' or 'shield' (got '${PKMN_GAME}')")
endif()
message(STATUS "Building for Pokemon ${PKMN_GAME} with ${CMAKE_CXX_COMPILER}")

# Every .cpp/.cc/.c under src/ and lib/ is compiled for both games. Version-specific
# code uses PKMN_SW_SH(...) / PKMN_IS_SWORD from include/pkmn/version.h.
file(GLOB_RECURSE PKMN_SOURCES CONFIGURE_DEPENDS
  "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cc"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c"
  "${CMAKE_CURRENT_SOURCE_DIR}/lib/*.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/lib/*.cc"
  "${CMAKE_CURRENT_SOURCE_DIR}/lib/*.c")

# Settings every TU shares go on pkmn_common, not on pkmn: a library with its
# own COMPILER_VERSION is a separate target that links pkmn_common too.
add_library(pkmn_common INTERFACE)
target_include_directories(pkmn_common INTERFACE
  "${CMAKE_CURRENT_SOURCE_DIR}/include"
  "${CMAKE_CURRENT_SOURCE_DIR}/src"
  "${CMAKE_CURRENT_SOURCE_DIR}/lib")
# Nintendo's libc is musl-based: musl 1.1.24 headers stand in for it (<stdio.h> ...).
target_include_directories(pkmn_common SYSTEM INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include/libc")
target_compile_definitions(pkmn_common INTERFACE PKMN_VERSION=${_ver})
target_compile_options(pkmn_common INTERFACE -Wall -Wno-unused-private-field)

add_library(pkmn OBJECT ${PKMN_SOURCES})
target_link_libraries(pkmn PRIVATE pkmn_common)

# --- Per-library settings ----------------------------------------------------
# The global flags above and in cmake/toolchain-nx64.cmake are the default for
# every TU. A library that was built differently gets an entry here, and only
# here, backed by a section of docs/compiler.md. cmake/LibrarySettings.cmake
# documents the mechanism, including COMPILER_VERSION.
include(cmake/LibrarySettings.cmake)

# Lua 5.3.4, built as C by Game Freak with the global flags (it is the corpus
# that identified them: 493 functions byte for byte). Of the Lua versions, 5.3.4
# with LUA_COMPAT_5_2 and LUA_USE_POSIX defined scores best.
pkmn_library_settings(lib/lua
  EVIDENCE "docs/compiler.md, section Method (Lua version and defines)"
  DEFINES LUA_COMPAT_5_2 LUA_USE_POSIX)

# The Lua glue of field::content (symbol_encount's ai.blua) is Game Freak code
# that binds its types with sol2 v2.20.4 (lib/sol, header-only): 1,041 of its
# functions match. Its TU was built as C++14 (C++17 makes sol2 use
# std::string_view, and the binary has sol2's own basic_string_view instances)
# and with NDEBUG (sol2's asserts are compiled out). libc++ 7.0.1 supplies the
# standard headers; lib/lua is for sol2's <lua.hpp>, and _GNU_SOURCE makes musl
# declare the strtof_l/... that libc++'s <locale> uses.
pkmn_library_settings(src/field/content
  EVIDENCE "docs/compiler.md, section sol2"
  DEFINES NDEBUG _GNU_SOURCE _LIBCPP_HAS_MUSL_LIBC _LIBCPP_HAS_THREAD_API_PTHREAD
  OPTIONS $<$<COMPILE_LANGUAGE:CXX>:-std=c++14>
  INCLUDES lib/lua
  SYSTEM_INCLUDES include/libcxx)

# gflib3, Game Freak's engine library, was built against libc++ 7.0.1 like the
# rest of Game Freak's code: it calls libc++ instantiations, and its memory
# code uses std::atomic. libc++ supplies the headers; the defines make them
# build on musl, as for src/field/content. gflib3 keeps its asserts (their
# __FILE__ and __func__ strings are in main), so no NDEBUG.
pkmn_library_settings(src/gflib3
  EVIDENCE "docs/compiler.md, section gflib3"
  DEFINES _GNU_SOURCE _LIBCPP_HAS_MUSL_LIBC _LIBCPP_HAS_THREAD_API_PTHREAD
  SYSTEM_INCLUDES include/libcxx)

# The game code that isn't placed in a directory yet is built the same way: it
# includes gflib3's headers (std::atomic in its reference-counted object) and
# instantiates libc++ like the rest of Game Freak's code.
pkmn_library_settings(src/unsorted
  EVIDENCE "docs/compiler.md, section gflib3"
  DEFINES _GNU_SOURCE _LIBCPP_HAS_MUSL_LIBC _LIBCPP_HAS_THREAD_API_PTHREAD
  SYSTEM_INCLUDES include/libcxx)

# PhysX 3.4.2, built by NVIDIA: full C++ exceptions (its FDEs have personality
# and LSDA), strict aliasing, -fno-builtin (fabsf/sqrtf stay library calls),
# gnu++14 (gnu++11/14/17 give identical code; strict c++17 breaks musl's
# alloca), and NVIDIA's static-library defines. The other codegen flags,
# including -g, are the global ones. PhysX was built with clang 6.0.1 (1,224
# functions match, 509 with clang 7.0.1), so lib/physx is compiled with
# toolchain/clang-6.0.1 (`python tools/get_llvm.py --compiler 6.0.1`) or
# -DPKMN_CLANG_ROOT_6_0_1. The include directories are the release_hpaths of
# v3.4.2's linux64 makefiles of the 12 libraries in the binary, in makefile
# order (the ones no TU reads are left out), and PX_BUILD_NUMBER is
# PhysXExtensions' release define there. libc++ 7.0.1 supplies <new>.
pkmn_library_settings(lib/physx
  EVIDENCE "docs/compiler.md, section PhysX"
  COMPILER_VERSION 6.0.1
  DEFINES __NX__ NDEBUG PX_PHYSX_STATIC_LIB PX_FOUNDATION_DLL=0 PX_SUPPORT_PVD=0
    PX_BUILD_NUMBER=24171494 _LIBCPP_HAS_MUSL_LIBC _LIBCPP_HAS_THREAD_API_PTHREAD
  OPTIONS -fexceptions -fstrict-aliasing -fno-builtin $<$<COMPILE_LANGUAGE:CXX>:-std=gnu++14>
  INCLUDES
    lib/physx/PxShared/src/foundation/include/unix
    lib/physx/PxShared/include
    lib/physx/PxShared/src/foundation/include
    lib/physx/PxShared/src/fastxml/include
    lib/physx/PxShared/src/pvd/include
    lib/physx/PhysX_3.4/Include/common
    lib/physx/PhysX_3.4/Include
    lib/physx/PhysX_3.4/Source/Common/src
    lib/physx/PhysX_3.4/Include/geometry
    lib/physx/PhysX_3.4/Source/GeomUtils/headers
    lib/physx/PhysX_3.4/Source/GeomUtils/src
    lib/physx/PhysX_3.4/Source/GeomUtils/src/contact
    lib/physx/PhysX_3.4/Source/GeomUtils/src/common
    lib/physx/PhysX_3.4/Source/GeomUtils/src/convex
    lib/physx/PhysX_3.4/Source/GeomUtils/src/distance
    lib/physx/PhysX_3.4/Source/GeomUtils/src/sweep
    lib/physx/PhysX_3.4/Source/GeomUtils/src/gjk
    lib/physx/PhysX_3.4/Source/GeomUtils/src/intersection
    lib/physx/PhysX_3.4/Source/GeomUtils/src/mesh
    lib/physx/PhysX_3.4/Source/GeomUtils/src/hf
    lib/physx/PhysX_3.4/Source/GeomUtils/src/pcm
    lib/physx/PhysX_3.4/Source/GeomUtils/src/ccd
    lib/physx/PhysX_3.4/Include/GeomUtils
    lib/physx/PhysX_3.4/Include/pvd
    lib/physx/PhysX_3.4/Include/particles
    lib/physx/PhysX_3.4/Include/cloth
    lib/physx/PhysX_3.4/Source/LowLevel/API/include
    lib/physx/PhysX_3.4/Source/LowLevel/software/include
    lib/physx/PhysX_3.4/Source/LowLevel/common/include/pipeline
    lib/physx/PhysX_3.4/Source/LowLevelAABB/include
    lib/physx/PhysX_3.4/Source/LowLevelDynamics/include
    lib/physx/PhysX_3.4/Source/LowLevelDynamics/src
    lib/physx/PhysX_3.4/Source/LowLevelParticles/include
    lib/physx/PhysX_3.4/Source/PhysX/src
    lib/physx/PhysX_3.4/Source/PhysX/src/buffering
    lib/physx/PhysX_3.4/Source/PhysX/src/particles
    lib/physx/PhysX_3.4/Source/PhysX/src/cloth
    lib/physx/PhysX_3.4/Source/SimulationController/include
    lib/physx/PhysX_3.4/Source/SimulationController/src
    lib/physx/PhysX_3.4/Source/SimulationController/src/particles
    lib/physx/PhysX_3.4/Source/SceneQuery/include
    lib/physx/PhysX_3.4/Source/PhysXMetaData/core/include
    lib/physx/PhysX_3.4/Source/SimulationController/src/cloth
    lib/physx/PhysX_3.4/Source/LowLevel/common/include/utils
    lib/physx/PhysX_3.4/Source/LowLevel/common/include/collision
    lib/physx/PhysX_3.4/Source/LowLevelCloth/include
    lib/physx/PhysX_3.4/Source/LowLevel/common/include
    lib/physx/PhysX_3.4/Source/LowLevelAABB/src
    lib/physx/PhysX_3.4/Source/LowLevelCloth/src
    lib/physx/PhysX_3.4/Source/LowLevelParticles/src
    lib/physx/PhysX_3.4/Include/cooking
    lib/physx/PhysX_3.4/Include/extensions
    lib/physx/PhysX_3.4/Include/vehicle
    lib/physx/PhysX_3.4/Source/PhysXMetaData/extensions/include
    lib/physx/PhysX_3.4/Source/PhysXExtensions/src
    lib/physx/PhysX_3.4/Source/PhysXExtensions/src/serialization/Xml
    lib/physx/PhysX_3.4/Source/PhysXExtensions/src/serialization/Binary
    lib/physx/PhysX_3.4/Source/PhysXExtensions/src/serialization/File
  SYSTEM_INCLUDES include/libcxx)

# TLSF 2.0 (with mattconte/tlsf 2b73b8a's adjust_request_size), the allocator
# that Audiokinetic's Wwise memory manager links: clang 6.0.1, like PhysX, but
# with the game's aliasing and exception flags (strict aliasing loses 5 of the
# 8 swept functions; Wwise's FDEs are all zR). NDEBUG compiles tlsf_assert out.
# All 8 swept functions are byte for byte with this, and with no other clang.
pkmn_library_settings(lib/tlsf
  EVIDENCE "docs/compiler.md, section Wwise (TLSF corpus)"
  COMPILER_VERSION 6.0.1
  DEFINES NDEBUG)

# Wwise itself (proprietary): placeholders for its small functions, written by
# tools/leafgen.py (lib/wwise/README.md), with the compiler and flags the TLSF
# corpus identified for the whole Wwise block.
pkmn_library_settings(lib/wwise
  EVIDENCE "docs/compiler.md, section Wwise"
  COMPILER_VERSION 6.0.1
  DEFINES NDEBUG)

# libcurl 7.55.1, Nintendo's SDK build (NintendoSDK_libcurl-7_3_2-Release in
# the middleware block): clang 7.0.x -O3 with the game's global flags, like
# Game Freak's code (84 functions byte for byte). The defines are curl's own
# for a static library built with a curl_config.h; lib/curl/lib/curl_config.h
# is the configuration reconstructed from the binary (HTTP/HTTPS only, no IPv6,
# threaded resolver, libz). lib/curl/zlib holds zlib 1.2.11's headers, the
# SDK's zlib version: HAVE_LIBZ puts a z_stream in curl's structs.
# lib/curl/nnsocket stands in for the SDK's BSD-style socket headers, in place
# of musl's (lib/curl/README.md).
pkmn_library_settings(lib/curl
  EVIDENCE "docs/compiler.md, section Nintendo SDK middleware (libcurl 7.55.1)"
  DEFINES HAVE_CONFIG_H BUILDING_LIBCURL CURL_STATICLIB
  INCLUDES lib/curl/include lib/curl/lib lib/curl/zlib lib/curl/nnsocket)

# Protocol Buffers 3.0.0, the runtime gflnet3 vendors
# (gflnet3/external/include/google/protobuf): the game's clang 7.0.x and
# global flags, with NDEBUG (the DCHECKs are compiled out), protobuf's
# HAVE_PTHREAD (main imports pthread_mutex_*) and GOOGLE_PROTOBUF_NO_RTTI (the
# global -fno-rtti). C++11 to C++17 give the same code. libc++ 7.0.1 supplies
# the standard headers; _GNU_SOURCE makes musl declare the strtof_l/... that
# libc++'s <locale> uses.
pkmn_library_settings(lib/protobuf
  EVIDENCE "docs/compiler.md, section Protocol Buffers 3.0.0"
  DEFINES NDEBUG HAVE_PTHREAD GOOGLE_PROTOBUF_NO_RTTI _GNU_SOURCE _LIBCPP_HAS_MUSL_LIBC
    _LIBCPP_HAS_THREAD_API_PTHREAD
  INCLUDES lib/protobuf
  SYSTEM_INCLUDES include/libcxx)

# Game Freak's protobuf messages: protoc 3.0.0 output for the .proto files
# under src/ (gflnet3's and the game's), which `python tools/protos.py generate`
# writes next to each .proto. It isn't committed: each .pb.cc embeds its file's
# serialized descriptor, a copy of the game's rodata. The generated code was
# built like the runtime above (NDEBUG keeps the runtime headers' DCHECKs out),
# and protos.py adds the one virtual function Game Freak's classes have more,
# and includes the .pb.h of the files it imports by bare name, so every
# directory with .proto files is on the include path. One entry per directory.
file(GLOB_RECURSE PKMN_PROTOS CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.proto")
set_property(DIRECTORY APPEND PROPERTY CMAKE_CONFIGURE_DEPENDS tools/protos.py)
set(PKMN_PROTO_DIRS "")
set(_pkmn_protos_stale "")
foreach(_proto IN LISTS PKMN_PROTOS)
  get_filename_component(_dir "${_proto}" DIRECTORY)
  string(REGEX REPLACE "\\.proto$" "" _stem "${_proto}")
  foreach(_out IN ITEMS "${_stem}.pb.cc" "${_stem}.pb.h")
    if(NOT EXISTS "${_out}" OR "${_proto}" IS_NEWER_THAN "${_out}"
        OR "${CMAKE_CURRENT_SOURCE_DIR}/tools/protos.py" IS_NEWER_THAN "${_out}")
      list(APPEND _pkmn_protos_stale "${_out}")
    endif()
  endforeach()
  file(RELATIVE_PATH _rel "${CMAKE_CURRENT_SOURCE_DIR}" "${_dir}")
  list(APPEND PKMN_PROTO_DIRS "${_rel}")
endforeach()
if(_pkmn_protos_stale)
  list(LENGTH _pkmn_protos_stale _n)
  message(FATAL_ERROR "${_n} files generated from src/**/*.proto are missing, or older than their "
    ".proto or tools/protos.py. Run `python tools/protos.py generate` (protoc 3.0.0).")
endif()
list(REMOVE_DUPLICATES PKMN_PROTO_DIRS)
foreach(_dir IN LISTS PKMN_PROTO_DIRS)
  pkmn_library_settings(${_dir}
    EVIDENCE "docs/compiler.md, section Generated protobuf messages"
    DEFINES NDEBUG HAVE_PTHREAD GOOGLE_PROTOBUF_NO_RTTI _GNU_SOURCE _LIBCPP_HAS_MUSL_LIBC
      _LIBCPP_HAS_THREAD_API_PTHREAD
    INCLUDES lib/protobuf ${PKMN_PROTO_DIRS}
    SYSTEM_INCLUDES include/libcxx)
endforeach()

# lib/physx's files with PhysX v3.4.2's code (see the entry above) aren't in
# the repository, because that code isn't BSD-licensed. tools/get_physx.py
# generates them from NVIDIA's public repository. Stop here until they're all
# there with the SHA-256 that data/physx_v342.csv lists.
set_property(DIRECTORY APPEND PROPERTY CMAKE_CONFIGURE_DEPENDS data/physx_v342.csv)
file(STRINGS data/physx_v342.csv _pkmn_physx_v342 REGEX "^[^,]+,[0-9a-f]+$")
set(_pkmn_physx_stale 0)
foreach(_row IN LISTS _pkmn_physx_v342)
  string(REPLACE "," ";" _row "${_row}")
  list(GET _row 0 _path)
  list(GET _row 1 _hash)
  set(_have "")
  if(EXISTS "${CMAKE_SOURCE_DIR}/lib/physx/${_path}")
    file(SHA256 "${CMAKE_SOURCE_DIR}/lib/physx/${_path}" _have)
  endif()
  if(NOT _have STREQUAL _hash)
    math(EXPR _pkmn_physx_stale "${_pkmn_physx_stale} + 1")
  endif()
endforeach()
if(_pkmn_physx_stale)
  message(FATAL_ERROR "lib/physx: ${_pkmn_physx_stale} of the files with PhysX v3.4.2's code are missing "
    "or out of date. Run `python tools/get_physx.py` (see lib/physx/README.md).")
endif()
