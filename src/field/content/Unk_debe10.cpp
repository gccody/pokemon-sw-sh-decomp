// Scope: common
// HaxeSymbolPokemonObject's collision, reaction and area getters: the names it keeps
// itself, the rest read from the Pokemon it wraps.
#include <arm_neon.h>

#include <types.h>

#include "field/content/HaxeSymbolPokemonObject.h"
#include "field/content/HaxeVector3.h"
#include "field/content/Unk_debce0_Owner.h"

namespace field {
namespace content {

static const Unk_debce0_Owner* Owner(const HaxeSymbolPokemonObject* object) {
    return static_cast<const Unk_debce0_Owner*>(object->field_0);
}

// 0x7100debe10
float HaxeSymbolPokemonObject::GetTouchCollision() const {
    return Owner(this)->field_994;
}

// 0x7100debe20
float HaxeSymbolPokemonObject::GetEncountCollision() const {
    return Owner(this)->field_998;
}

// 0x7100debe30
float HaxeSymbolPokemonObject::GetReactionParam0() const {
    return Owner(this)->field_99c;
}

// 0x7100debe40
float HaxeSymbolPokemonObject::GetReactionParam1() const {
    return Owner(this)->field_9a0;
}

// 0x7100debe50
float HaxeSymbolPokemonObject::GetReactionParam2() const {
    return Owner(this)->field_9a4;
}

// 0x7100debe60
float HaxeSymbolPokemonObject::GetReactionParam3() const {
    return Owner(this)->field_9a8;
}

// 0x7100debe70
float HaxeSymbolPokemonObject::GetReactionTime() const {
    return Owner(this)->field_9ac;
}

// 0x7100debe80
const char* HaxeSymbolPokemonObject::GetSpecialLeave() const {
    return field_8a;
}

// 0x7100debe90
const char* HaxeSymbolPokemonObject::GetMoveType() const {
    return field_cb;
}

// 0x7100debea0
float HaxeSymbolPokemonObject::GetWatchOutBicycleDistance() const {
    return Owner(this)->field_a30;
}

// 0x7100debeb0
float HaxeSymbolPokemonObject::GetWatchOutBicycleRadius() const {
    return Owner(this)->field_a34;
}

// NON_MATCHING: the code is identical, but the original calls 0x7100ded9e0 (the
// HaxeVector3 constructor) under its leaf placeholder name Unk_ded9e0_set.
// 0x7100debec0
HaxeVector3 HaxeSymbolPokemonObject::GetEventCollisionDefaultOffset() const {
    float32x4_t offset = Owner(this)->field_a40;
    return HaxeVector3(vgetq_lane_f32(offset, 0), vgetq_lane_f32(offset, 1),
                       vgetq_lane_f32(offset, 2));
}

// NON_MATCHING: the code is identical, but the original calls 0x7100ded9e0 (the
// HaxeVector3 constructor) under its leaf placeholder name Unk_ded9e0_set.
// 0x7100debf00
HaxeVector3 HaxeSymbolPokemonObject::GetTouchCollisionDefaultOffset() const {
    float32x4_t offset = Owner(this)->field_a50;
    return HaxeVector3(vgetq_lane_f32(offset, 0), vgetq_lane_f32(offset, 1),
                       vgetq_lane_f32(offset, 2));
}

// 0x7100debf40
bool HaxeSymbolPokemonObject::IsGimmickSymbolPokemon() const {
    return Owner(this)->Unk_d0b900();
}

// 0x7100debf50
bool HaxeSymbolPokemonObject::IsContainsCreateArea(HaxeVector3 pos) const {
    return Unk_c8dd50(Owner(this)->field_a70, float32x4_t{pos.X, pos.Y, pos.Z, 0.0f}, 0, 0.0f);
}

// 0x7100debfc0
bool HaxeSymbolPokemonObject::IsContainsVanishArea(HaxeVector3 pos) const {
    return Unk_c8dd50(Owner(this)->field_a70, float32x4_t{pos.X, pos.Y, pos.Z, 0.0f}, 1, 0.0f);
}

}  // namespace content
}  // namespace field
