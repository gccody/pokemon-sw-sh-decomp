// Scope: common
//
// Easing curves on t in [0, 1] (battle scene segment). Each curve has an "in"
// form; the "out" form mirrors it (1 - in(1 - t)) and the "in-out" form runs
// the in form on the first half and the out form on the second. The out and
// in-out forms inline the in form, so all of them are one TU.
// 0x7100985020-0x7100985a20. Placeholder names: no names in the executable.
#include <math.h>

#include "types.h"

namespace {

constexpr f32 kPi = 3.1415927f;
constexpr f32 kHalfPi = 1.5707964f;

}  // namespace

f32 Unk_985020(f32 t);
f32 Unk_985050(f32 t);
f32 Unk_985120(f32 t);
f32 Unk_985130(f32 t);
f32 Unk_985190(f32 t);
f32 Unk_9851a0(f32 t);
f32 Unk_985210(f32 t);
f32 Unk_985220(f32 t);
f32 Unk_985290(f32 t);
f32 Unk_9852b0(f32 t);
f32 Unk_985330(f32 t);
f32 Unk_985350(f32 t);
f32 Unk_985430(f32 t);
f32 Unk_985480(f32 t);
f32 Unk_985580(f32 t);
f32 Unk_9855c0(f32 t);
f32 Unk_9856b0(f32 t);
f32 Unk_985700(f32 t);
f32 Unk_985810(f32 t);

// 0x7100985020
f32 Unk_985020(f32 t) {
    return sinf((t - 1.0f) * kHalfPi) + 1.0f;
}

// 0x7100985050
f32 Unk_985050(f32 t) {
    return 1.0f - Unk_985020(1.0f - t);
}

// 0x7100985090
f32 Unk_985090(f32 t) {
    if (t < 0.5f)
        return Unk_985020(t * 2.0f) * 0.5f;
    return Unk_985050(t * 2.0f - 1.0f) * 0.5f + 0.5f;
}

// 0x7100985120
f32 Unk_985120(f32 t) {
    return t * t;
}

// 0x7100985130
f32 Unk_985130(f32 t) {
    return 1.0f - Unk_985120(1.0f - t);
}

// 0x7100985150
f32 Unk_985150(f32 t) {
    if (t < 0.5f)
        return Unk_985120(t * 2.0f) * 0.5f;
    return Unk_985130(t * 2.0f - 1.0f) * 0.5f + 0.5f;
}

// 0x7100985190
f32 Unk_985190(f32 t) {
    return t * t * t;
}

// 0x71009851a0
f32 Unk_9851a0(f32 t) {
    return 1.0f - Unk_985190(1.0f - t);
}

// 0x71009851c0
f32 Unk_9851c0(f32 t) {
    if (t < 0.5f)
        return Unk_985190(t * 2.0f) * 0.5f;
    return Unk_9851a0(t * 2.0f - 1.0f) * 0.5f + 0.5f;
}

// 0x7100985210
f32 Unk_985210(f32 t) {
    return t * t * t * t;
}

// 0x7100985220
f32 Unk_985220(f32 t) {
    return 1.0f - Unk_985210(1.0f - t);
}

// 0x7100985240
f32 Unk_985240(f32 t) {
    if (t < 0.5f)
        return Unk_985210(t * 2.0f) * 0.5f;
    return Unk_985220(t * 2.0f - 1.0f) * 0.5f + 0.5f;
}

// 0x7100985290
f32 Unk_985290(f32 t) {
    return t * t * t * t * t;
}

// 0x71009852b0
f32 Unk_9852b0(f32 t) {
    return 1.0f - Unk_985290(1.0f - t);
}

// 0x71009852d0
f32 Unk_9852d0(f32 t) {
    if (t < 0.5f)
        return Unk_985290(t * 2.0f) * 0.5f;
    return Unk_9852b0(t * 2.0f - 1.0f) * 0.5f + 0.5f;
}

// 0x7100985330
f32 Unk_985330(f32 t) {
    return t == 0.0f ? t : powf(2.0f, (t - 1.0f) * 10.0f);
}

// 0x7100985350
f32 Unk_985350(f32 t) {
    return 1.0f - Unk_985330(1.0f - t);
}

// 0x71009853a0
f32 Unk_9853a0(f32 t) {
    if (t < 0.5f)
        return Unk_985330(t * 2.0f) * 0.5f;
    return Unk_985350(t * 2.0f - 1.0f) * 0.5f + 0.5f;
}

// 0x7100985430
f32 Unk_985430(f32 t) {
    return 1.0f - sqrtf(1.0f - t * t);
}

// 0x7100985480
f32 Unk_985480(f32 t) {
    return 1.0f - Unk_985430(1.0f - t);
}

// 0x71009854d0
f32 Unk_9854d0(f32 t) {
    if (t < 0.5f)
        return Unk_985430(t * 2.0f) * 0.5f;
    return Unk_985480(t * 2.0f - 1.0f) * 0.5f + 0.5f;
}

// 0x7100985580
f32 Unk_985580(f32 t) {
    return t * t * t - t * sinf(t * kPi);
}

// 0x71009855c0
f32 Unk_9855c0(f32 t) {
    return 1.0f - Unk_985580(1.0f - t);
}

// 0x7100985610
f32 Unk_985610(f32 t) {
    if (t < 0.5f)
        return Unk_985580(t * 2.0f) * 0.5f;
    return Unk_9855c0(t * 2.0f - 1.0f) * 0.5f + 0.5f;
}

// 0x71009856b0
f32 Unk_9856b0(f32 t) {
    return sinf(13.0f * kHalfPi * t) * powf(2.0f, (t - 1.0f) * 10.0f);
}

// 0x7100985700
f32 Unk_985700(f32 t) {
    return 1.0f - Unk_9856b0(1.0f - t);
}

// 0x7100985760
f32 Unk_985760(f32 t) {
    if (t < 0.5f)
        return Unk_9856b0(t * 2.0f) * 0.5f;
    return Unk_985700(t * 2.0f - 1.0f) * 0.5f + 0.5f;
}

namespace {

// The bouncing curve the bounce "in" form mirrors.
f32 Unk_985810_Curve(f32 t) {
    if (t < 4.0f / 11.0f)
        return 121.0f * t * t / 16.0f;
    if (t < 8.0f / 11.0f)
        return 363.0f / 40.0f * t * t - 99.0f / 10.0f * t + 17.0f / 5.0f;
    if (t < 9.0f / 10.0f)
        return 4356.0f / 361.0f * t * t - 35442.0f / 1805.0f * t + 16061.0f / 1805.0f;
    return 54.0f / 5.0f * t * t - 513.0f / 25.0f * t + 268.0f / 25.0f;
}

}  // namespace

// 0x7100985810
f32 Unk_985810(f32 t) {
    return 1.0f - Unk_985810_Curve(1.0f - t);
}

// 0x7100985910
f32 Unk_985910(f32 t) {
    return 1.0f - Unk_985810(1.0f - t);
}
