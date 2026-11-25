// Scope: common
// HaxeSymbolPokemonObject's motion, rotation and collision functions: they pass the
// script's calls on to the Pokemon it wraps and to its motion component.
#include <arm_neon.h>

#include <types.h>

#include <nn/util.h>

#include "field/content/HaxeSymbolPokemonObject.h"
#include "field/content/HaxeVector3.h"
#include "field/content/Unk_decfa0_Owner.h"

// The Pokemon's functions these call, by the placeholder types their names were given
// with (src/unsorted/leaf/Unk_d0a100.cpp).
struct Unk_d0a100;
struct Unk_d0a110;
struct Unk_d0b220;
struct Unk_d0b570;
f32 Unk_d0a100_getField4dc(const Unk_d0a100* self);
f32 Unk_d0a110_getField514(const Unk_d0a110* self);
void Unk_d0b220_call(Unk_d0b220* self, f32 radius);
bool Unk_d0b570_call(const Unk_d0b570* self, void* value, void* arg2, u32 arg3);

namespace field {
namespace content {

static Unk_decfa0_Owner* Owner(const HaxeSymbolPokemonObject* object) {
    return static_cast<Unk_decfa0_Owner*>(object->field_0);
}

// 0x7100decfa0
bool HaxeSymbolPokemonObject::IsMotionEnd() const {
    return Owner(this)->Unk_GetComponent<Unk_23e7a38>()->Unk_d0d4b0();
}

// 0x7100ded070
float HaxeSymbolPokemonObject::GetRotationToTarget(HaxeVector3 target) const {
    Unk_23e7a38* motion = Owner(this)->Unk_GetComponent<Unk_23e7a38>();
    float32x4_t rot = motion->Unk_d0d500(float32x4_t{target.X, target.Y, target.Z, 0.0f});
    float scale = nn::util::detail::FloatDegree180 / nn::util::detail::FloatPi;
    return scale * vgetq_lane_f32(rot, 1);
}

// NON_MATCHING: the original calls 0x7100ded9e0 (the HaxeVector3 constructor)
// under its leaf placeholder name Unk_ded9e0_set.
// 0x7100ded1a0
HaxeVector3 HaxeSymbolPokemonObject::GetRotationToTargetXY(HaxeVector3 target) const {
    Unk_23e7a38* motion = Owner(this)->Unk_GetComponent<Unk_23e7a38>();
    float32x4_t rot = motion->Unk_d0d500(float32x4_t{target.X, target.Y, target.Z, 0.0f});
    float scale = nn::util::detail::FloatDegree180 / nn::util::detail::FloatPi;
    return HaxeVector3(scale * vgetq_lane_f32(rot, 0), scale * vgetq_lane_f32(rot, 1), 0.0f);
}

// 0x7100ded460
void HaxeSymbolPokemonObject::SetCollisionOffset(HaxeVector3 offset) {
    float32x4_t offset4 = {offset.X, offset.Y, offset.Z, 0.0f};
    Owner(this)->Unk_d0b1f0(offset4);
}

// NON_MATCHING: the original calls 0x7100ded9e0 (the HaxeVector3 constructor)
// under its leaf placeholder name Unk_ded9e0_set.
// 0x7100ded4a0
HaxeVector3 HaxeSymbolPokemonObject::GetCollisionOffset() const {
    float32x4_t offset = Owner(this)->Unk_d0b200();
    return HaxeVector3(vgetq_lane_f32(offset, 0), vgetq_lane_f32(offset, 1),
                       vgetq_lane_f32(offset, 2));
}

// 0x7100ded4e0
void HaxeSymbolPokemonObject::SetEventCollisionOffset(HaxeVector3 offset) {
    float32x4_t offset4 = {offset.X, offset.Y, offset.Z, 0.0f};
    Owner(this)->Unk_d0acd0(offset4);
}

// NON_MATCHING: the original calls 0x7100ded9e0 (the HaxeVector3 constructor)
// under its leaf placeholder name Unk_ded9e0_set.
// 0x7100ded520
HaxeVector3 HaxeSymbolPokemonObject::GetEventCollisionOffset() const {
    float32x4_t offset = Owner(this)->Unk_d0b210();
    return HaxeVector3(vgetq_lane_f32(offset, 0), vgetq_lane_f32(offset, 1),
                       vgetq_lane_f32(offset, 2));
}

// 0x7100ded560
void HaxeSymbolPokemonObject::SetCollisionR(float radius) {
    Unk_d0b220_call(static_cast<Unk_d0b220*>(field_0), radius);
}

// 0x7100ded570
float HaxeSymbolPokemonObject::GetCollisionR() const {
    return Unk_d0a100_getField4dc(static_cast<const Unk_d0a100*>(field_0));
}

// 0x7100ded580
void HaxeSymbolPokemonObject::SetEventCollisionR(float radius) {
    Owner(this)->Unk_d0b230(radius);
}

// 0x7100ded590
float HaxeSymbolPokemonObject::GetEventCollisionR() const {
    return Unk_d0a110_getField514(static_cast<const Unk_d0a110*>(field_0));
}

// 0x7100ded5a0
bool HaxeSymbolPokemonObject::IsWallHit() const {
    return Owner(this)->Unk_d0a900();
}

// NON_MATCHING: the original calls 0x7100ded9e0 (the HaxeVector3 constructor)
// under its leaf placeholder name Unk_ded9e0_set.
// 0x7100ded5b0
HaxeVector3 HaxeSymbolPokemonObject::RaycastWallNormal(HaxeVector3 from, HaxeVector3 to) const {
    float32x4_t from4 = vcombine_f32(float32x2_t{from.X, from.Y}, float32x2_t{from.Z, 0.0f});
    float32x4_t to4 = vcombine_f32(float32x2_t{to.X, to.Y}, float32x2_t{to.Z, 0.0f});
    float32x4_t normal = Owner(this)->Unk_d0b580(from4, to4);
    return HaxeVector3(vgetq_lane_f32(normal, 0), vgetq_lane_f32(normal, 1),
                       vgetq_lane_f32(normal, 2));
}

// 0x7100ded620
bool HaxeSymbolPokemonObject::RaycastObject(HaxeVector3 from,
                                            HaxeVector3 to,
                                            unsigned int mask) const {
    u32 flags = 0;
    if (mask & 1)
        flags |= 2;
    if (mask & 2)
        flags |= 0x100;
    if (flags == 0)
        return false;
    float32x4_t from4 = vcombine_f32(float32x2_t{from.X, from.Y}, float32x2_t{from.Z, 0.0f});
    float32x4_t to4 = vcombine_f32(float32x2_t{to.X, to.Y}, float32x2_t{to.Z, 0.0f});
    return Unk_d0b570_call(static_cast<const Unk_d0b570*>(field_0), &from4, &to4, flags);
}

// 0x7100ded690
void HaxeSymbolPokemonObject::SetEnableGroundRaycast(bool enable) {
    Owner(this)->Unk_SetEnableGroundRaycast(enable);
}

}  // namespace content
}  // namespace field
