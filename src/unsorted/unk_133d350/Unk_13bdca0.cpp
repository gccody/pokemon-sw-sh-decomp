// Scope: common
// Script commands (Unk_13bd600.h): the position and rotation of field objects,
// by their ids, in degrees for the script.
#include <arm_neon.h>

#include <types.h>

#include <nn/util.h>

#include "field/content/Unk_13f1360.h"
#include "unsorted/unk_133d350/Unk_13bd600.h"

static constexpr f32 kPi = 3.1415927f;

// 0x7100d1fe70: the position of the object with the id.
const Unk_13bd600_Vector& Unk_d1fe70(const s64& id);
// 0x7100d20070: the rotation (a quaternion) of the object with the id.
const Unk_13bd600_Vector& Unk_d20070(const s64& id);
bool Unk_d1f280(const s64& id, const float32x4_t& position, bool arg3, bool arg4);
bool Unk_d1f640(const s64& id, f32 angle, bool arg3);
bool Unk_d1f910(const s64& id, const s64& target, bool arg3);
bool Unk_d1fb70(const s64& id, f32 arg2, f32 arg3, bool arg4);
bool Unk_d1fd00(const s64& id, const float32x4_t& rotation, bool arg3);
f32 Unk_d1fb50(const Unk_13bd600_Vector& from, const Unk_13bd600_Vector& to);
f32 Unk_d28e50(const s64& id, const s64& target);
f32 Unk_962230(f32 x, f32 z);
float32x4_t Unk_972c70(f32 x, f32 y, f32 z);
float32x4_t Unk_9733f0(const Unk_13bd600_Vector& rotation);

// The global next to the manager (Unk_27d6158).
class Unk_27d6160_Type {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual bool vf8();
};

extern Unk_27d6160_Type* Unk_27d6160;

// The field objects, with the flags 0x71013bdca0 looks at.
class Unk_13bdca0_Object : public Unk_13f1360_Object {
public:
    u8 _1a8[0x378 - 0x1a8];
    u32 field_378;
};
static_assert(__builtin_offsetof(Unk_13bdca0_Object, field_378) == 0x378, "field_378");

// The types (0x71027efd90, 0x71027efd80) the types of the objects below are
// on, as in src/unsorted/types/Unk_cf2500.cpp. Unk_23dcdd0's getter
// (src/unsorted/Unk_23dcdd0.h) is called out of line (0x71013a6920).
class Unk_23dcdd0 {
public:
    static const Unk_239a418_Type* Unk_GetType();
};

struct Unk_23dd820 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23dcdd0::Unk_GetType());
        return &type;
    }
};

struct Unk_23e4758 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23dd820::Unk_GetType());
        return &type;
    }
};

// Field objects of two kinds (as src/unsorted/types/Unk_d4fd40.cpp and
// Unk_d16230.cpp name them).
// The first's type getter is out of line (0x71013ca860).
class Unk_23ea898 : public Unk_13f1360_Object {
public:
    static const Unk_239a418_Type* Unk_GetType();
};

class Unk_23e8958 : public Unk_13f1360_Object {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23e4758::Unk_GetType());
        return &type;
    }
};

// What the two kinds are checked with (src/unsorted/leaf/Unk_d4fb90.cpp and
// Unk_d17bc0.cpp): whether a name's hash is set.
struct Unk_d4fbc0;
struct Unk_d17bc0;
bool Unk_d4fbc0_check(const Unk_d4fbc0* self);
bool Unk_d17bc0_check(const Unk_d17bc0* self);

// 0x71013bdca0
s64 Unk_13bdca0_call(Unk_13bd600_Script* self, const Unk_13bd600_Arg* args) {
    s64 first = args[1].i;
    s64 second = args[2].i;
    Unk_13f1360_Manager* manager = Unk_27d6158;
    if (first != 0) {
        for (auto& object : manager->field_b0) {
            if ((static_cast<Unk_13bdca0_Object*>(object)->field_378 & 0x1000) == 0 ||
                object->vf17())
                continue;
            Unk_23ea898* found = object->Unk_Cast<Unk_23ea898>();
            if (found != nullptr && Unk_d4fbc0_check(reinterpret_cast<const Unk_d4fbc0*>(found)))
                found->vf16();
        }
    }
    if (second != 0) {
        for (auto& object : manager->field_b0) {
            if ((static_cast<Unk_13bdca0_Object*>(object)->field_378 & 0x8) == 0 || object->vf17())
                continue;
            Unk_23e8958* found = object->Unk_Cast<Unk_23e8958>();
            if (found != nullptr && Unk_d17bc0_check(reinterpret_cast<const Unk_d17bc0*>(found)))
                found->vf16();
        }
    }
    return 1;
}

// 0x71013bdec0
s64 Unk_13bdec0_call(Unk_13bd600_Script* self, const Unk_13bd600_Arg* args) {
    return Unk_27d6160->vf8();
}

// 0x71013bdef0
s64 Unk_13bdef0_call(Unk_13bd600_Script* self, const Unk_13bd600_Arg* args) {
    s64 id = args[1].i;
    f32 x = args[2].f;
    f32 z = args[3].f;
    bool arg4 = args[4].i != 0;
    bool arg5 = args[5].i != 0;
    const Unk_13bd600_Vector& current = Unk_d1fe70(id);
    float32x4_t position = {x, vgetq_lane_f32(current.v, 1), z, 0.0f};
    return Unk_d1f280(id, position, arg4, arg5);
}

// 0x71013bdf80
s64 Unk_13bdf80_call(Unk_13bd600_Script* self, const Unk_13bd600_Arg* args) {
    s64 id = args[1].i;
    f32 x = args[2].f;
    f32 z = args[3].f;
    f32 angle = static_cast<f32>(args[4].f) * kPi / 180.0f;
    bool arg5 = args[5].i != 0;
    bool arg6 = args[6].i != 0;
    const Unk_13bd600_Vector& current = Unk_d1fe70(id);
    float32x4_t position = {x, vgetq_lane_f32(current.v, 1), z, 0.0f};
    bool moved = Unk_d1f280(id, position, arg5, arg6);
    bool turned = Unk_d1f640(id, angle, arg6);
    return moved & turned;
}

// 0x71013be050
s64 Unk_13be050_call(Unk_13bd600_Script* self, const Unk_13bd600_Arg* args) {
    s64 id = args[1].i;
    f32 x = args[2].f;
    f32 y = args[3].f;
    f32 z = args[4].f;
    bool arg5 = args[5].i != 0;
    bool arg6 = args[6].i != 0;
    float32x4_t position = {x, y, z, 0.0f};
    return Unk_d1f280(id, position, arg5, arg6);
}

// 0x71013be0c0
s64 Unk_13be0c0_call(Unk_13bd600_Script* self, const Unk_13bd600_Arg* args) {
    s64 id = args[1].i;
    f32 angle = static_cast<f32>(args[2].f) * kPi / 180.0f;
    return Unk_d1f640(id, angle, args[3].i != 0);
}

// 0x71013be120
s64 Unk_13be120_call(Unk_13bd600_Script* self, const Unk_13bd600_Arg* args) {
    s64 id = args[1].i;
    s64 target = args[2].i;
    return Unk_d1f910(id, target, args[3].i != 0);
}

// 0x71013be170
s64 Unk_13be170_call(Unk_13bd600_Script* self, const Unk_13bd600_Arg* args) {
    s64 id = args[1].i;
    return Unk_d1fb70(id, args[2].f, args[3].f, args[4].i != 0);
}

// 0x71013be1c0
s64 Unk_13be1c0_call(Unk_13bd600_Script* self, const Unk_13bd600_Arg* args) {
    s64 id = args[1].i;
    f32 x = static_cast<f32>(args[2].f) * kPi / 180.0f;
    f32 y = static_cast<f32>(args[3].f) * kPi / 180.0f;
    f32 z = static_cast<f32>(args[4].f) * kPi / 180.0f;
    bool arg5 = args[5].i != 0;
    float32x4_t rotation = Unk_972c70(y, x, z);
    return Unk_d1fd00(id, rotation, arg5);
}

// 0x71013be250
s64 Unk_13be250_call(Unk_13bd600_Script* self, const Unk_13bd600_Arg* args) {
    s64 id = args[1].i;
    return Unk_13bd600_ToArg(vgetq_lane_f32(Unk_d1fe70(id).v, 0));
}

// 0x71013be290
s64 Unk_13be290_call(Unk_13bd600_Script* self, const Unk_13bd600_Arg* args) {
    s64 id = args[1].i;
    return Unk_13bd600_ToArg(vgetq_lane_f32(Unk_d1fe70(id).v, 1));
}

// 0x71013be2d0
s64 Unk_13be2d0_call(Unk_13bd600_Script* self, const Unk_13bd600_Arg* args) {
    s64 id = args[1].i;
    return Unk_13bd600_ToArg(vgetq_lane_f32(Unk_d1fe70(id).v, 2));
}

// 0x71013be310: the object's yaw, in [0, 360].
s64 Unk_13be310_call(Unk_13bd600_Script* self, const Unk_13bd600_Arg* args) {
    s64 id = args[1].i;
    Unk_13bd600_Vector rotation = Unk_d20070(id);
    float32x4_t euler = Unk_9733f0(rotation);
    f32 angle = vgetq_lane_f32(euler, 1) * 180.0f / kPi;
    while (angle < 0.0f)
        angle += 360.0f;
    while (angle > 360.0f)
        angle -= 360.0f;
    return Unk_13bd600_ToArg(angle);
}

// 0x71013be3b0
s64 Unk_13be3b0_call(Unk_13bd600_Script* self, const Unk_13bd600_Arg* args) {
    s64 id = args[1].i;
    s64 target = args[2].i;
    f32 angle = Unk_d28e50(id, target);
    return Unk_13bd600_ToArg(angle *
                             (nn::util::detail::FloatDegree180 / nn::util::detail::FloatPi));
}

// 0x71013be410
s64 Unk_13be410_call(Unk_13bd600_Script* self, const Unk_13bd600_Arg* args) {
    s64 id = args[1].i;
    s64 target = args[2].i;
    Unk_13bd600_Vector from = Unk_d1fe70(id);
    Unk_13bd600_Vector to = Unk_d1fe70(target);
    f32 angle = Unk_d1fb50(from, to);
    return Unk_13bd600_ToArg(angle * 180.0f / kPi);
}

// 0x71013be490
s64 Unk_13be490_call(Unk_13bd600_Script* self, const Unk_13bd600_Arg* args) {
    f32 x = args[1].f;
    f32 z = args[2].f;
    s64 id = args[3].i;
    float32x4_t position = Unk_d1fe70(id).v;
    return Unk_13bd600_ToArg(
        Unk_962230(vgetq_lane_f32(position, 0) - x, vgetq_lane_f32(position, 2) - z));
}
