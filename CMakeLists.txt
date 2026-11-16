cmake_minimum_required(VERSION 3.20)

# One source tree, built once per game. Select the game with PKMN_GAME
# (presets: `cmake --preset sword` / `cmake --preset shield`).
set(PKMN_GAME "sword" CACHE STRING "Game version to build: sword or shield")
set_property(CACHE PKMN_GAME PROPERTY STRINGS sword shield)

if(NOT CMAKE_TOOLCHAIN_FILE)
  set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/cmake/toolchain-nx64.cmake")
endif()

project(pkmn_swsh LANGUAGES C CXX)

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

# Every .cpp/.c under src/ and lib/ is compiled for both games. Version-specific
# code uses PKMN_SW_SH(...) / PKMN_IS_SWORD from include/pkmn/version.h.
file(GLOB_RECURSE PKMN_SOURCES CONFIGURE_DEPENDS
  "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c"
  "${CMAKE_CURRENT_SOURCE_DIR}/lib/*.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/lib/*.c")

add_library(pkmn OBJECT ${PKMN_SOURCES})
target_include_directories(pkmn PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/include"
  "${CMAKE_CURRENT_SOURCE_DIR}/src"
  "${CMAKE_CURRENT_SOURCE_DIR}/lib")
# Nintendo's libc is musl-based: musl 1.1.24 headers stand in for it (<stdio.h> ...).
target_include_directories(pkmn SYSTEM PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include/libc")
target_compile_definitions(pkmn PRIVATE PKMN_VERSION=${_ver})
target_compile_options(pkmn PRIVATE -Wall -Wno-unused-private-field)

# --- Per-library settings ----------------------------------------------------
# The global flags above and in cmake/toolchain-nx64.cmake are the default for
# every TU. A library that was built differently gets an entry here, and only
# here, backed by a section of docs/compiler.md. cmake/LibrarySettings.cmake
# documents the mechanism and its limits.
include(cmake/LibrarySettings.cmake)

# Lua 5.3.4, built as C by Game Freak with the global flags (it is the corpus
# that identified them: 490 functions byte for byte). Of the Lua versions, 5.3.4
# with LUA_COMPAT_5_2 and LUA_USE_POSIX defined scores best.
pkmn_library_settings(lib/lua
  EVIDENCE "docs/compiler.md, section Method (Lua version and defines)"
  DEFINES LUA_COMPAT_5_2 LUA_USE_POSIX)

# PhysX 3.4, built by NVIDIA: full C++ exceptions (its FDEs have personality
# and LSDA), strict aliasing, gnu++14 (gnu++11/14/17 give identical code; strict
# c++17 breaks musl's alloca), and NVIDIA's static-library defines. The other
# codegen flags are the global ones. PhysX was built with clang 6.0.1, which
# this build can't provide: once lib/physx has sources, configuring warns that
# they won't match with clang 7.0.1.
pkmn_library_settings(lib/physx
  EVIDENCE "docs/compiler.md, section PhysX"
  COMPILER_VERSION 6.0.1
  DEFINES __NX__ NDEBUG PX_PHYSX_STATIC_LIB PX_FOUNDATION_DLL=0 PX_SUPPORT_PVD=0
  OPTIONS -fexceptions -fstrict-aliasing $<$<COMPILE_LANGUAGE:CXX>:-std=gnu++14>)
