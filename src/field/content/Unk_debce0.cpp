// Scope: common
// HaxeSymbolPokemonObject's parameter getters: the script name it keeps itself, the
// rest read from the Pokemon it wraps.
#include <types.h>

#include "field/content/HaxeSymbolPokemonObject.h"
#include "field/content/Unk_debce0_Owner.h"

namespace field {
namespace content {

static const Unk_debce0_Owner* Owner(const HaxeSymbolPokemonObject* object) {
    return static_cast<const Unk_debce0_Owner*>(object->field_0);
}

// 0x7100debce0
const char* HaxeSymbolPokemonObject::GetScriptName() const {
    return field_49;
}

// 0x7100debcf0
int HaxeSymbolPokemonObject::GetReactionState() const {
    return Owner(this)->field_930;
}

// 0x7100debd00
bool HaxeSymbolPokemonObject::HasHearing() const {
    return Owner(this)->field_934 != 0;
}

// 0x7100debd20
bool HaxeSymbolPokemonObject::HasHearingWhistle() const {
    return Owner(this)->field_935 != 0;
}

// 0x7100debd40
float HaxeSymbolPokemonObject::GetTurnSpeed() const {
    return Owner(this)->field_948;
}

// 0x7100debd50
int HaxeSymbolPokemonObject::GetRandomMoveFrameMin() const {
    return static_cast<int>(Owner(this)->field_94c);
}

// 0x7100debd60
int HaxeSymbolPokemonObject::GetRandomMoveFrameMax() const {
    return static_cast<int>(Owner(this)->field_950);
}

// 0x7100debd70
int HaxeSymbolPokemonObject::GetWaitFrequency() const {
    return static_cast<int>(Owner(this)->field_954);
}

// 0x7100debd80
int HaxeSymbolPokemonObject::GetWaitFrameMin() const {
    return static_cast<int>(Owner(this)->field_958);
}

// 0x7100debd90
int HaxeSymbolPokemonObject::GetWaitFrameMax() const {
    return static_cast<int>(Owner(this)->field_95c);
}

// 0x7100debda0
int HaxeSymbolPokemonObject::GetMotion1() const {
    return Owner(this)->field_960;
}

// 0x7100debdb0
int HaxeSymbolPokemonObject::GetMotion2() const {
    return Owner(this)->field_964;
}

// 0x7100debdc0
float HaxeSymbolPokemonObject::GetWatchOutRadius() const {
    return Owner(this)->field_978;
}

// 0x7100debdd0
float HaxeSymbolPokemonObject::GetWatchOutDistance() const {
    return Owner(this)->field_97c;
}

// 0x7100debde0
float HaxeSymbolPokemonObject::GetWatchOutAngle() const {
    return Owner(this)->field_980;
}

// 0x7100debdf0
bool HaxeSymbolPokemonObject::IsWatchOutY() const {
    return Owner(this)->field_984 != 0;
}

}  // namespace content
}  // namespace field
