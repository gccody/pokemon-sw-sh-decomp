#pragma once

// Game-version selection. The whole tree is compiled twice (see CMakePresets.json):
//   build/sword   -DPKMN_VERSION=PKMN_VERSION_SWORD
//   build/shield  -DPKMN_VERSION=PKMN_VERSION_SHIELD
// and every function is checked against BOTH original executables.
//
// Rules (enforced by tools/check.py):
//   * Scope `common` / `common-data` functions must compile identically for both
//     games, so they should not need any of the macros below.
//   * Scope `diverged` functions use PKMN_SW_SH / PKMN_IS_SWORD where the games differ.
//   * Scope `sword` / `shield` functions are wrapped in `#if PKMN_IS_SWORD` etc.

#define PKMN_VERSION_SWORD 1
#define PKMN_VERSION_SHIELD 2

#ifndef PKMN_VERSION
#error "PKMN_VERSION is not defined - build through CMake (cmake --preset sword|shield)"
#endif

#define PKMN_IS_SWORD (PKMN_VERSION == PKMN_VERSION_SWORD)
#define PKMN_IS_SHIELD (PKMN_VERSION == PKMN_VERSION_SHIELD)

// Pick a per-game value: PKMN_SW_SH(sword_value, shield_value)
#if PKMN_IS_SWORD
#define PKMN_SW_SH(sword, shield) sword
#else
#define PKMN_SW_SH(sword, shield) shield
#endif

namespace pkmn {

// In-game version IDs (stored in save data / Pokemon "origin game").
enum class GameVersion : int {
    Sword = 44,
    Shield = 45,
};

constexpr GameVersion kThisGame = PKMN_SW_SH(GameVersion::Sword, GameVersion::Shield);

}  // namespace pkmn
