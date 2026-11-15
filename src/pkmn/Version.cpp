// Scope: diverged - the one function whose only difference is the game ID.
#include <pkmn/version.h>

namespace pkmn {

// Sword 0x71007c2d80 / Shield 0x71007c2d80: `mov w0, #44` vs `mov w0, #45`.
int GetVersion() {
    return static_cast<int>(kThisGame);
}

}  // namespace pkmn
