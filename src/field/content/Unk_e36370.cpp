// Scope: common
// HaxeVector2's methods (fromcpp.Vector2) and HaxeFieldFunc's player getters
// (fromcpp.Field).
#include <arm_neon.h>

#include <cmath>
#include <vector>

#include <types.h>

#include <nn/util.h>

#include "field/content/HaxeFieldFunc.h"
#include "field/content/HaxeVector2.h"
#include "field/content/HaxeVector3.h"
#include "gflib3/Unk_239a418.h"

// 0x71013ed240
template <class T>
bool Unk_61a530(Unk_239a498* object);

// A field object: the manager's list holds them. Placeholder names.
class Unk_e36820_Object : public Unk_239a418 {
public:
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual bool vf17();

    // The object as a T, or null when it isn't one: through its +0x50 interface.
    template <class T>
    T* Unk_Cast() {
        Unk_239a498* object = this;
        return Unk_61a530<T>(object) ? static_cast<T*>(object) : nullptr;
    }
};

// A rotation (Unk_971950 turns it into angles in radians).
struct Unk_e36820_Rotation {
    float field_0;
    float field_4;
    float field_8;
    float field_c;
};
PKMN_SIZE_ASSERT(Unk_e36820_Rotation, 0x10);

// 0x7100971950
float32x4_t Unk_971950(const Unk_e36820_Rotation& rotation);

// The player's object (type 0x71027f0000, from HaxeFieldFunc's use).
class Unk_23ea168 : public Unk_e36820_Object {
public:
    static const Unk_239a418_Type* Unk_GetType();

    u8 _60[0xa0 - 0x60];
    Unk_e36820_Rotation field_a0;
    float32x4_t field_b0;  // the position
};
static_assert(__builtin_offsetof(Unk_23ea168, field_a0) == 0xa0, "field_a0");
static_assert(__builtin_offsetof(Unk_23ea168, field_b0) == 0xb0, "field_b0");

struct Unk_e36820_Manager {
    u8 _0[0xb0];
    std::vector<Unk_e36820_Object*> field_b0;
};
static_assert(__builtin_offsetof(Unk_e36820_Manager, field_b0) == 0xb0, "field_b0");

extern Unk_e36820_Manager* Unk_27d6158;

namespace field {
namespace content {

// 0x7100e366b0
HaxeVector2 HaxeVector2::Create(float x, float y) {
    return HaxeVector2(x, y);
}

// 0x7100e366c0
HaxeVector2 HaxeVector2::CreateAdd(HaxeVector2 a, HaxeVector2 b) {
    return HaxeVector2(a.X + b.X, a.Y + b.Y);
}

// 0x7100e366d0
HaxeVector2 HaxeVector2::CreateSub(HaxeVector2 a, HaxeVector2 b) {
    return HaxeVector2(a.X - b.X, a.Y - b.Y);
}

// 0x7100e366e0
float HaxeVector2::Dot(HaxeVector2 a, HaxeVector2 b) {
    return a.X * b.X + a.Y * b.Y;
}

// 0x7100e366f0
float HaxeVector2::Cross(HaxeVector2 a, HaxeVector2 b) {
    return a.X * b.Y - a.Y * b.X;
}

// 0x7100e36700
void HaxeVector2::Add(HaxeVector2 other) {
    X += other.X;
    Y += other.Y;
}

// 0x7100e36720
void HaxeVector2::Sub(HaxeVector2 other) {
    X -= other.X;
    Y -= other.Y;
}

// 0x7100e36740
void HaxeVector2::Mul(float scale) {
    X *= scale;
    Y *= scale;
}

// NON_MATCHING: the first Newton step's fmul has its operands the other way round
// (v1, v2 instead of v2, v1), whichever order the source writes them in.
// 0x7100e36760
void HaxeVector2::Normalize() {
    float32x4_t v = {X, Y, 0.0f, 0.0f};
    float32x4_t sq = vmulq_f32(v, v);
    float32x2_t sum = vadd_f32(vget_high_f32(sq), vget_low_f32(sq));
    sum = vpadd_f32(sum, sum);
    if (vget_lane_f32(sum, 0) != 0.0f) {
        float32x4_t lengthSq = vcombine_f32(sum, sum);
        float32x4_t rsqrt = vrsqrteq_f32(lengthSq);
        for (int i = 0; i < 2; i++)
            rsqrt = vmulq_f32(rsqrt, vrsqrtsq_f32(rsqrt, vmulq_f32(rsqrt, lengthSq)));
        uint32x4_t nonzero = vmvnq_u32(vceqq_f32(lengthSq, vdupq_n_f32(0.0f)));
        float32x4_t result =
            vreinterpretq_f32_u32(vandq_u32(vreinterpretq_u32_f32(vmulq_f32(v, rsqrt)), nonzero));
        X = vgetq_lane_f32(result, 0);
        Y = vgetq_lane_f32(result, 1);
    }
}

// 0x7100e367c0
float HaxeVector2::Length() const {
    return std::sqrt(X * X + Y * Y);
}

// 0x7100e367f0
float HaxeVector2::LengthSq() const {
    return X * X + Y * Y;
}

// 0x7100e36810
HaxeVector2 HaxeVector2::Clone() const {
    return *this;
}

// The first player object still in play.
static Unk_23ea168* FindPlayer() {
    for (auto& object : Unk_27d6158->field_b0) {
        Unk_23ea168* player = object->Unk_Cast<Unk_23ea168>();
        if (player != nullptr && !object->vf17())
            return player;
    }
    return nullptr;
}

// NON_MATCHING: the original calls 0x7100ded9e0 (the HaxeVector3 constructor)
// under its leaf placeholder name Unk_ded9e0_set.
// 0x7100e36820
HaxeVector3 HaxeFieldFunc::GetPlayerPos() {
    float32x4_t pos = FindPlayer()->field_b0;
    return HaxeVector3(vgetq_lane_f32(pos, 0), vgetq_lane_f32(pos, 1), vgetq_lane_f32(pos, 2));
}

// NON_MATCHING: the original calls 0x7100ded9e0 (the HaxeVector3 constructor)
// under its leaf placeholder name Unk_ded9e0_set, and the rotation's copy loads
// its two halves into x8/x9 the other way round.
// 0x7100e368a0
HaxeVector3 HaxeFieldFunc::GetPlayerRot() {
    Unk_e36820_Rotation rotation = FindPlayer()->field_a0;
    float32x4_t rot = Unk_971950(rotation);
    float scale = nn::util::detail::FloatDegree180 / nn::util::detail::FloatPi;
    return HaxeVector3(scale * vgetq_lane_f32(rot, 0), scale * vgetq_lane_f32(rot, 1),
                       scale * vgetq_lane_f32(rot, 2));
}

}  // namespace content
}  // namespace field
