# One library built with its own clang (COMPILER_VERSION in a
# pkmn_library_settings() entry). Added once per such library by
# cmake/LibrarySettings.cmake, with add_subdirectory() and its own binary dir;
# don't add it by hand.
#
# A CMake build has one CMAKE_<LANG>_COMPILER, but the rule that compiles an
# object, CMAKE_<LANG>_COMPILE_OBJECT, is a variable read from the target's
# directory. In this directory it names the library's clang instead of
# <CMAKE_<LANG>_COMPILER>. Everything else in the rule (<DEFINES>, <INCLUDES>,
# <FLAGS>, the depfile flags) is the same as for `pkmn`, and so are the flags it
# expands to. compile_commands.json is written from the same rule, so it shows
# the compiler that really runs.
#
# Inputs (variables of the calling function):
#   PKMN_LIBRARY_TARGET        name of the OBJECT library to create
#   PKMN_LIBRARY_SOURCES       absolute source paths
#   PKMN_LIBRARY_<LANG>_COMPILER  absolute path of the library's clang / clang++

foreach(lang IN ITEMS C CXX)
  set(exe "${PKMN_LIBRARY_${lang}_COMPILER}")
  if(CMAKE_HOST_WIN32)
    file(TO_NATIVE_PATH "${exe}" exe)
  endif()
  if(exe MATCHES " ")
    set(exe "\"${exe}\"")
  endif()
  # CMake expands <CMAKE_<LANG>_COMPILER> to the compiler followed by these
  # (cmRulePlaceholderExpander), so the replacement carries them too: here,
  # --target=aarch64-none-elf.
  if(CMAKE_${lang}_COMPILER_ARG1)
    string(APPEND exe " ${CMAKE_${lang}_COMPILER_ARG1}")
  endif()
  if(CMAKE_${lang}_COMPILER_TARGET AND CMAKE_${lang}_COMPILE_OPTIONS_TARGET)
    string(APPEND exe " ${CMAKE_${lang}_COMPILE_OPTIONS_TARGET}${CMAKE_${lang}_COMPILER_TARGET}")
  endif()
  if(CMAKE_${lang}_COMPILER_EXTERNAL_TOOLCHAIN AND CMAKE_${lang}_COMPILE_OPTIONS_EXTERNAL_TOOLCHAIN)
    string(APPEND exe " ${CMAKE_${lang}_COMPILE_OPTIONS_EXTERNAL_TOOLCHAIN}${CMAKE_${lang}_COMPILER_EXTERNAL_TOOLCHAIN}")
  endif()
  if(CMAKE_SYSROOT_COMPILE)
    set(sysroot "${CMAKE_SYSROOT_COMPILE}")
  else()
    set(sysroot "${CMAKE_SYSROOT}")
  endif()
  if(sysroot AND CMAKE_${lang}_COMPILE_OPTIONS_SYSROOT)
    string(APPEND exe " ${CMAKE_${lang}_COMPILE_OPTIONS_SYSROOT}\"${sysroot}\"")
  endif()
  set(rule "${CMAKE_${lang}_COMPILE_OBJECT}")
  string(FIND "${rule}" "<CMAKE_${lang}_COMPILER>" at)
  if(at EQUAL -1)
    message(FATAL_ERROR "CMAKE_${lang}_COMPILE_OBJECT doesn't start with <CMAKE_${lang}_COMPILER> "
      "('${rule}'), so ${PKMN_LIBRARY_TARGET} can't use its own compiler with this CMake")
  endif()
  string(REPLACE "<CMAKE_${lang}_COMPILER>" "${exe}" CMAKE_${lang}_COMPILE_OBJECT "${rule}")
endforeach()

add_library(${PKMN_LIBRARY_TARGET} OBJECT ${PKMN_LIBRARY_SOURCES})
# The settings every TU shares (includes, PKMN_VERSION, warnings) are on
# pkmn_common, which `pkmn` links too. Language standard and the global flags
# come from the same variables as for `pkmn`.
target_link_libraries(${PKMN_LIBRARY_TARGET} PRIVATE pkmn_common)
set_target_properties(${PKMN_LIBRARY_TARGET} PROPERTIES CXX_SCAN_FOR_MODULES OFF)
