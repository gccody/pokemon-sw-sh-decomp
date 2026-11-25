// Scope: common
// HaxeSymbolPokemonObject's effect, sound and script-state functions, the last of the
// object's functions in its TU.
#include <types.h>

#include "field/content/HaxeSymbolPokemonObject.h"
#include "field/content/Unk_decfa0_Owner.h"
#include "unsorted/Unk_d0c0.h"

// The Pokemon's species and form getters, by the placeholder types their names were
// given with (src/unsorted/leaf/Unk_d4fb90.cpp).
struct Unk_d4fb90;
struct Unk_d4fba0;
u32 Unk_d4fb90_getField5bc(const Unk_d4fb90* self);
u16 Unk_d4fba0_getField5c0(const Unk_d4fba0* self);

// 0x71012fef00: formats the voice's name from the three numbers and plays it.
int Unk_12fef00(void* player, u32 monsNo, int formNo, int voice);

// 0x7100d281c0: starts an effect (the type, the handle of the object it follows, the
// offset from it, ..., the effect's name and the scale). Unk_d281c0_call's name leaves
// the scale out.
void Unk_d281c0_call(u32 type,
                     Unk_239a418_Ref<Unk_239a418_Handle> handle,
                     const float32x4_t* offset,
                     const void* arg3,
                     Unk_5cfaf0_Name name,
                     float scale);

extern const u8 Unk_1f07bd0[];

namespace field {
namespace content {

static Unk_decfa0_Owner* Owner(const HaxeSymbolPokemonObject* object) {
    return static_cast<Unk_decfa0_Owner*>(object->field_0);
}

// 0x7100ded6a0
bool HaxeSymbolPokemonObject::GetEnableGroundRaycast() const {
    return Owner(this)->Unk_GetEnableGroundRaycast();
}

// NON_MATCHING: the original passes the scale 1.0f in s0, which Unk_d281c0_call's
// name leaves out, and moves the handle into a second temporary for the call (the
// parameter's type isn't known).
// 0x7100ded6b0
void HaxeSymbolPokemonObject::StartBalloonEffect(int type) {
    Unk_decfa0_Owner* owner = Owner(this);
    {
        float32x4_t offset = {0.0f, 4.0f, 0.0f, 0.0f};
        Unk_d281c0_call(type, owner->vf2(), &offset, Unk_1f07bd0, Unk_5cfaf0_Name("EffOverHead01"),
                        1.0f);
    }
    owner->Unk_d0bd80(type);
}

// 0x7100ded7a0
int HaxeSymbolPokemonObject::GetBattleType() const {
    return Owner(this)->field_b1c;
}

// 0x7100ded7b0
int HaxeSymbolPokemonObject::GetPopType() const {
    return Owner(this)->field_b18;
}

// 0x7100ded7c0
void HaxeSymbolPokemonObject::StartPopEffect() {
    Owner(this)->Unk_d0b710();
}

// 0x7100ded7d0
void HaxeSymbolPokemonObject::StartEffect1() {
    Unk_decfa0_Owner* owner = Owner(this);
    u64 effect = owner->field_968;
    owner->Unk_d0b850(effect);
}

// 0x7100ded800
void HaxeSymbolPokemonObject::StartEffect2() {
    Unk_decfa0_Owner* owner = Owner(this);
    u64 effect = owner->field_970;
    owner->Unk_d0b850(effect);
}

// 0x7100ded830
void HaxeSymbolPokemonObject::PlaySe(int se) {
    Owner(this)->Unk_d0be30(se);
}

// 0x7100ded840
int HaxeSymbolPokemonObject::PlayVoice(int voice) const {
    u32 monsNo = Unk_d4fb90_getField5bc(static_cast<const Unk_d4fb90*>(field_0));
    int formNo = Unk_d4fba0_getField5c0(static_cast<const Unk_d4fba0*>(field_0));
    return Unk_12fef00(Owner(this)->field_bc0, monsNo, formNo, voice);
}

// 0x7100ded890
void HaxeSymbolPokemonObject::SetBackupScriptState(int state) {
    Owner(this)->field_b24 = state;
}

// 0x7100ded8a0
int HaxeSymbolPokemonObject::GetBackupScriptState() const {
    return Owner(this)->field_b24;
}

}  // namespace content
}  // namespace field
