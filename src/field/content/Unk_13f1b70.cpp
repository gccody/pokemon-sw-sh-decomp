// Scope: common
// Script commands (Unk_13f1360.h): the names, flags and requests of the objects
// 0x71013f6c00 finds, and the rotation of the ones of type 0x71013f6d80.
#include <arm_neon.h>

#include <types.h>

#include "field/content/Unk_13f1360.h"
#include "gflib3/Unk_239a418.h"
#include "unsorted/Unk_d0c0.h"

// 0x7100d7b040: what is kept under the id (a reference).
Unk_239a418_Ref<Unk_239a418> Unk_d7b040(const s64& id);
// 0x7100d9cd00
Unk_239a418_Ref<Unk_239a418> Unk_d9cd00();

// 0x71013f6d80
const Unk_239a418_Type* Unk_13f6d80();

// 0x7100d25bd0: the player's object (src/field/content/Unk_e36370.cpp finds it
// the same way).
Unk_13f1360_Object* Unk_d25bd0();

// 0x7100990590: the angle of a direction, in radians.
f32 Unk_990590(f32 x, f32 z);

// What 0x7100d20d30 asks of an object: where to go, facing which way.
struct Unk_d20d30_Request {
    float32x4_t field_0;  // the position
    f32 field_10;         // the angle
    f32 field_14;
    u8 field_18;
    u8 field_19;
    u8 field_1a;
    f32 field_1c;
    Unk_5cfaf0_Name field_20;
};
PKMN_OFFSET_ASSERT(Unk_d20d30_Request, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_d20d30_Request, field_1c, 0x1c);
PKMN_OFFSET_ASSERT(Unk_d20d30_Request, field_20, 0x20);
PKMN_SIZE_ASSERT(Unk_d20d30_Request, 0x40);

// 0x7100d20d30: sends the object with the id the request.
void Unk_d20d30(const s64& id, const Unk_d20d30_Request& request);

// The objects of type 0x71013f6d80.
class Unk_13f6d80_Object : public Unk_13f1360_Object {
public:
    static const Unk_239a418_Type* Unk_GetType() { return Unk_13f6d80(); }

    // 0x7100d05a80 (in radians)
    float32x4_t Unk_d05a80();
};

// The first object of type 0x71013f6d80 with the id that isn't gone.
static Unk_13f6d80_Object* FindRotating(s64 id) {
    for (auto& object : Unk_27d6158->field_b0) {
        Unk_13f6d80_Object* found = object->Unk_Cast<Unk_13f6d80_Object>();
        if (found != nullptr && found->field_1a0 == id && !object->vf17())
            return found;
    }
    return nullptr;
}

// 0x71013f1b70
s64 Unk_13f1b70_call(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    s64 id = args->field_8;
    s32 index = args->field_10;
    Unk_13f6c00_Object* object = Unk_13f1360_FindObject(id);
    if (object == nullptr)
        return 0;
    Unk_239a418_Ref<Unk_13f6c00_Object> ref(object);
    object->Unk_d01730(index);
    return 1;
}

// 0x71013f1c00
s64 Unk_13f1c00_call(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    s64 id = args->field_8;
    Unk_d7b040(id);
    Unk_66efd0_update(self, 0xc);
    return 1;
}

// 0x71013f1c60
s64 Unk_13f1c60_call(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    s64 id = args->field_8;
    Unk_13f6c00_Object* object = Unk_13f1360_FindObject(id);
    if (object == nullptr)
        return 0;
    Unk_239a418_Ref<Unk_13f6c00_Object> ref(object);
    return object->Unk_d00b50();
}

// 0x71013f1ce0
s64 Unk_13f1ce0_call(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    s64 id = args->field_8;
    s64 value = args->field_10;
    Unk_13f6c00_Object* object = Unk_13f1360_FindObject(id);
    if (object == nullptr)
        return 0;
    Unk_239a418_Ref<Unk_13f6c00_Object> ref(object);
    object->Unk_d01760(value != 0);
    return 1;
}

// 0x71013f1d70
s64 Unk_13f1d70_call(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    s64 id = args->field_8;
    Unk_13f6c00_Object* object = Unk_13f1360_FindObject(id);
    if (object == nullptr)
        return 0;
    Unk_239a418_Ref<Unk_13f6c00_Object> ref(object);
    object->Unk_d01870();
    return 1;
}

// 0x71013f1df0
s64 Unk_13f1df0_call(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    s64 id = args->field_8;
    Unk_13f6c00_Object* object = Unk_13f1360_FindObject(id);
    if (object == nullptr)
        return 0;
    Unk_239a418_Ref<Unk_13f6c00_Object> ref(object);
    object->Unk_d018e0();
    return 1;
}

// 0x71013f1e70
s64 Unk_13f1e70_call(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    s64 id = args->field_8;
    Unk_13f6c00_Object* object = Unk_13f1360_FindObject(id);
    if (object == nullptr)
        return 0;
    Unk_239a418_Ref<Unk_13f6c00_Object> ref(object);
    return object->Unk_d01950();
}

// 0x71013f1ef0
s64 Unk_13f1ef0_call(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    s64 id = args->field_8;
    Unk_13f6c00_Object* object = Unk_13f1360_FindObject(id);
    if (object == nullptr)
        return 0;
    Unk_239a418_Ref<Unk_13f6c00_Object> ref(object);
    object->Unk_d01970();
    return 1;
}

// 0x71013f1f70
s64 Unk_13f1f70_call(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    s64 id = args->field_8;
    Unk_13f6c00_Object* object = Unk_13f1360_FindObject(id);
    if (object == nullptr)
        return 0;
    Unk_239a418_Ref<Unk_13f6c00_Object> ref(object);
    object->Unk_d019c0();
    return 1;
}

// NON_MATCHING: the first Newton step's fmul has its operands the other way round
// (as in HaxeVector2::Normalize), and the name's stores pair differently (the
// original reuses x8 for the hash and the string).
// 0x71013f1ff0
s64 Unk_13f1ff0_call(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    s64 id = args->field_8;
    s32 time = args->field_10;
    Unk_13f6c00_Object* object = Unk_13f1360_FindObject(id);
    if (object == nullptr)
        return 0;
    Unk_239a418_Ref<Unk_13f6c00_Object> ref(object);
    Unk_13f1360_Object* player = Unk_d25bd0();
    float32x4_t dir = vsubq_f32(player->field_b0, object->field_b0);

    float32x4_t sq = vmulq_f32(dir, dir);
    float32x2_t sum = vadd_f32(vget_high_f32(sq), vget_low_f32(sq));
    sum = vpadd_f32(sum, sum);
    float32x4_t lengthSq = vcombine_f32(sum, sum);
    float32x4_t rsqrt = vrsqrteq_f32(lengthSq);
    for (int i = 0; i < 2; i++)
        rsqrt = vmulq_f32(rsqrt, vrsqrtsq_f32(rsqrt, vmulq_f32(rsqrt, lengthSq)));
    uint32x4_t nonzero = vmvnq_u32(vceqq_f32(lengthSq, vdupq_n_f32(0.0f)));
    dir = vreinterpretq_f32_u32(vandq_u32(vreinterpretq_u32_f32(vmulq_f32(dir, rsqrt)), nonzero));

    float32x4_t offset = {0.65f, 0.0f, 0.0f, 0.0f};
    float32x4_t target =
        vaddq_f32(object->field_b0, vaddq_f32(vmulq_f32(dir, vdupq_n_f32(76.0f)), offset));
    f32 angle = Unk_990590(-vgetq_lane_f32(dir, 0), -vgetq_lane_f32(dir, 2));
    Unk_d20d30_Request request = {
        target, angle, 10.0f, 0, 1, 0, static_cast<f32>(time), Unk_5cfaf0_Name(""),
    };
    s64 playerId = player->field_1a0;
    Unk_d20d30(playerId, request);
    return 1;
}

// 0x71013f2190
s64 Unk_13f2190_call(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    Unk_d9cd00();
    Unk_66efd0_update(self, 0xc);
    return 1;
}

// 0x71013f21e0
s64 Unk_13f21e0_call(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    Unk_13f6d80_Object* object = FindRotating(args->field_8);
    if (object == nullptr)
        return 0;
    Unk_239a418_Ref<Unk_13f6d80_Object> ref(object);
    return vgetq_lane_f32(object->Unk_d05a80(), 0);
}

// 0x71013f22c0
s64 Unk_13f22c0_call(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    Unk_13f6d80_Object* object = FindRotating(args->field_8);
    if (object == nullptr)
        return 0;
    Unk_239a418_Ref<Unk_13f6d80_Object> ref(object);
    return vgetq_lane_f32(object->Unk_d05a80(), 1);
}
