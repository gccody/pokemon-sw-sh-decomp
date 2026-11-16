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
# Lua 5.3.4 (lib/lua): built as C with the configuration identified in
# docs/compiler.md. Kept to lib/lua's sources only; a later change will turn
# this into a general per-library settings mechanism.
file(GLOB PKMN_LUA_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/lib/lua/*.c")
set_source_files_properties(${PKMN_LUA_SOURCES} PROPERTIES
  COMPILE_DEFINITIONS "LUA_COMPAT_5_2;LUA_USE_POSIX")
