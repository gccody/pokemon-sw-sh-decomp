# Applies the global codegen flags (PKMN_CODEGEN_FLAGS, set in
# cmake/toolchain-nx64.cmake) to every C and C++ TU. CMakeLists.txt includes
# this right after project().
#
# The flags go into CMAKE_<LANG>_FLAGS as a normal variable, computed again on
# every configure:
#
#   CMAKE_<LANG>_FLAGS = <PKMN_CODEGEN_FLAGS> <the CMAKE_<LANG>_FLAGS cache entry>
#
# CMake reads the toolchain file on every configure and lists it as a configure
# dependency, so after an edit to the flag list the next build (`cmake --build`,
# `ninja`, tools/check.py) reconfigures by itself and recompiles every TU with
# the new flags. CMAKE_<LANG>_FLAGS_INIT, used before, only fills the cache
# entry on a build dir's first configure: a flag change needed `--fresh`.
#
# The cache entry holds only flags the user adds (-DCMAKE_C_FLAGS=..., or
# $CFLAGS / $CXXFLAGS on the first configure). They come after the codegen
# flags, so they can override one for an experiment. They are not part of the
# matching build. The command line is otherwise the same as with the _INIT
# variables: CMake puts CMAKE_<LANG>_FLAGS first in <FLAGS>, then
# CMAKE_<LANG>_FLAGS_<CONFIG>, -std, the targets' options and the per-library
# OPTIONS (cmake/LibrarySettings.cmake).
#
# tools/check.py stops if a build dir doesn't use the flags of the toolchain
# file: the list recorded below (PKMN_CODEGEN_FLAGS_CONFIGURED) must equal it,
# and every command in compile_commands.json must contain it, in order.

if(NOT DEFINED PKMN_CODEGEN_FLAGS)
  message(FATAL_ERROR "PKMN_CODEGEN_FLAGS isn't set: configure with cmake/toolchain-nx64.cmake "
    "as the toolchain file (the default; CMAKE_TOOLCHAIN_FILE is '${CMAKE_TOOLCHAIN_FILE}')")
endif()

# Build dirs configured before this file existed have the codegen flags of that
# time in the cache entries, after $CFLAGS / $CXXFLAGS. Take them out once. The
# first two flags have been the same in every revision of the list.
if(NOT PKMN_LANG_FLAGS_CACHE_IS_USER_ONLY)
  foreach(lang IN ITEMS C CXX)
    string(FIND "$CACHE{CMAKE_${lang}_FLAGS}" "-mcpu=cortex-a57+fp+simd+crypto+crc -D__ELF__" at)
    if(at GREATER -1)
      string(SUBSTRING "$CACHE{CMAKE_${lang}_FLAGS}" 0 ${at} user)
      string(STRIP "${user}" user)
      set_property(CACHE CMAKE_${lang}_FLAGS PROPERTY VALUE "${user}")
      message(STATUS "Removed the codegen flags of an older configure from the "
        "CMAKE_${lang}_FLAGS cache entry (they come from PKMN_CODEGEN_FLAGS now)")
    endif()
  endforeach()
  set(PKMN_LANG_FLAGS_CACHE_IS_USER_ONLY ON CACHE INTERNAL
    "The CMAKE_<LANG>_FLAGS cache entries hold only user flags (cmake/CodegenFlags.cmake)")
endif()

string(JOIN " " _pkmn_codegen_flags ${PKMN_CODEGEN_FLAGS})
foreach(lang IN ITEMS C CXX)
  set(CMAKE_${lang}_FLAGS "${_pkmn_codegen_flags}")
  if(NOT "$CACHE{CMAKE_${lang}_FLAGS}" STREQUAL "")
    string(APPEND CMAKE_${lang}_FLAGS " $CACHE{CMAKE_${lang}_FLAGS}")
  endif()
endforeach()
unset(_pkmn_codegen_flags)
# For tools/check.py: the list this build dir was last configured with.
set(PKMN_CODEGEN_FLAGS_CONFIGURED "${PKMN_CODEGEN_FLAGS}" CACHE INTERNAL
  "PKMN_CODEGEN_FLAGS of the last configure (cmake/CodegenFlags.cmake)")
