#pragma once
// What the battle sequence functions (Unk_a38ab0.cpp) share: reading their
// arguments from the sequence, and the objects they set. Placeholder names:
// rename once the classes are known.
#include <arm_neon.h>

#include <cstddef>
#include <utility>

#include <types.h>

#include "battle/battle_scene/Unk_23c4ef0_Owner.h"
#include "unsorted/Unk_23c4ef0.h"
#include "unsorted/Unk_d0c0.h"

// The sequence's readers (0x710140b690 ...): each copies the value at the
// sequence's cursor (+0x178) and moves it past the value if told to. Their
// names are the placeholders they were given where they were first seen.
void Unk_140b690(u64 seq, void* out, u32 advance);              // s32
void Unk_140b6b0(void* seq, void* out, u32 advance);            // u64
void Unk_140bc80(void* seq, void* out, u32 advance);            // f32
void Unk_140bca0(void* seq, void* out, u32 advance);            // a vector, three floats
void Unk_140bd40(void* seq, void* out, u32 advance);            // bool, from a word
void Unk_140bd70(u64 seq, void* out, u32 advance);              // a name (0x100 bytes)
void Unk_140bcf0(void* seq, void* out, s32 size, u32 advance);  // characters

// The sequence itself (what its functions get as their first argument).
struct Unk_23c4ef0_Sequence {
    u8 _0[0x184];
    s32 field_184;
};
PKMN_OFFSET_ASSERT(Unk_23c4ef0_Sequence, field_184, 0x184);

// Jumps (0x710140beb0).
void Unk_140beb0(void* seq, s32 arg1, u32 arg2);

// A vector from three floats, the fourth 0.
inline float32x4_t Unk_23c4ef0_MakeVec(f32 x, f32 y, f32 z) {
    float32x4_t v = vdupq_n_f32(0.0f);
    v = vsetq_lane_f32(x, v, 0);
    v = vsetq_lane_f32(y, v, 1);
    v = vsetq_lane_f32(z, v, 2);
    return v;
}

inline void Unk_23c4ef0_ReadS32(void* seq, s32* out) {
    Unk_140b690(reinterpret_cast<u64>(seq), out, 1);
}
inline void Unk_23c4ef0_ReadU64(void* seq, u64* out) {
    Unk_140b6b0(seq, out, 1);
}
inline void Unk_23c4ef0_ReadF32(void* seq, f32* out) {
    Unk_140bc80(seq, out, 1);
}
inline void Unk_23c4ef0_ReadVec(void* seq, Unk_23c4ef0_Vec* out) {
    Unk_140bca0(seq, out, 1);
}
inline void Unk_23c4ef0_ReadBool(void* seq, bool* out) {
    Unk_140bd40(seq, out, 1);
}

// What the view system holds at +0x4a8 and +0x4c8. Its setters are inline:
// the original loads the object before the value it stores.
struct Unk_23c4ef0_Light {
    void SetField_a0(f32 value) { field_a0 = value; }
    void SetField_b0(const Unk_23c4ef0_Vec& value) { field_b0 = value; }
    void SetField_c1(bool value) { field_c1 = value; }

    u8 _0[0xa0];
    f32 field_a0;
    u8 _a4[0xb0 - 0xa4];
    Unk_23c4ef0_Vec field_b0;
    u8 field_c0;
    bool field_c1;
};
PKMN_OFFSET_ASSERT(Unk_23c4ef0_Light, field_a0, 0xa0);
PKMN_OFFSET_ASSERT(Unk_23c4ef0_Light, field_b0, 0xb0);
PKMN_OFFSET_ASSERT(Unk_23c4ef0_Light, field_c1, 0xc1);

// What the view system's lists at +0x530 and +0x538 add objects to.
struct Unk_23c4ef0_List : Unk_239a418 {
    void Unk_142a660(Unk_239a418_Ref<Unk_239a418> object, u32 arg2);
};

// Objects the sequence functions add to the view system's lists, by their
// constructors' addresses (on Unk_239a418).
class Unk_993ba0 : public Unk_239a418 {
public:
    Unk_993ba0(Unk_23c4ef0_Owner* owner, u32 pos);

    u8 _60[0xb8 - 0x60];
};
static_assert(sizeof(Unk_993ba0) == 0xb8, "Unk_993ba0");

class Unk_993c90 : public Unk_239a418 {
public:
    Unk_993c90(Unk_23c4ef0_Owner* owner, u32 pos1, u32 pos2);

    u8 _60[0xb8 - 0x60];
};
static_assert(sizeof(Unk_993c90) == 0xb8, "Unk_993c90");

class Unk_994030 : public Unk_239a418 {
public:
    Unk_994030(Unk_23c4ef0_Owner* owner, u32 pos, u64 arg3);

    u8 _60[0x98 - 0x60];
};
static_assert(sizeof(Unk_994030) == 0x98, "Unk_994030");

class Unk_9941c0 : public Unk_239a418 {
public:
    Unk_9941c0(Unk_23c4ef0_Owner* owner, u32 pos);

    u8 _60[0x90 - 0x60];
};
static_assert(sizeof(Unk_9941c0) == 0x90, "Unk_9941c0");

class Unk_993d80 : public Unk_239a418 {
public:
    Unk_993d80(Unk_23c4ef0_Owner* owner, u32 pos, const Unk_23c4ef0_Info* info);

    u8 _60[0xb8 - 0x60];
};
static_assert(sizeof(Unk_993d80) == 0xb8, "Unk_993d80");

// What the view system holds at +0x5c8.
struct Unk_23c4ef0_Scene {
    void Unk_98a1c0();
    void Unk_98a1e0(u32 arg1, u32 arg2, s32 arg3);
    void Unk_98a230();
    void Unk_98a290(u8 arg1, u32 arg2, bool arg3);
    void Unk_98a8b0();
    void Unk_98aa50(u64 flags);
};

// Functions matched before their callers here, with the placeholder types
// they were matched with (src/unsorted/leaf).
struct Unk_7ee6b0;
struct Unk_8a7f60;
struct Unk_8a7f70;
struct Unk_8a9060;
struct Unk_953950;
struct Unk_953950_arg1;
struct Unk_981b60;
struct Unk_98a880;
struct Unk_98a880_arg1;
struct Unk_98aac0;
u8 Unk_7ee6b0_getField7d(const Unk_7ee6b0* self);
u64 Unk_8a9060_getField58(const Unk_8a9060* self);
void Unk_953950_set(const Unk_953950* self, const Unk_953950_arg1* value);
void Unk_981b60_set(Unk_981b60* self, bool value);
void Unk_98a880_call(const Unk_98a880* self, const Unk_98a880_arg1* value);
void Unk_98aac0_set(Unk_98aac0* self, u32 value);
void Unk_8a7f60_setField8(Unk_8a7f60* self, u32 value);
void Unk_8a7f70_setFieldc(Unk_8a7f70* self, u32 value);
void Unk_8ea3a0_call(void* self, u64 value, bool arg2, bool arg3);
void Unk_8ea3b0(u64 self, u32 arg1);

void Unk_8ea490(u64 self);

// Allocates an object of a class on Unk_239a418 from `allocator`, constructs
// it with the allocator current (the thread's allocator stack) and records
// where its memory came from (+0x8 ... +0x20), as gflib3's objects do.
template <class T, class... Args>
T* Unk_23c4ef0_New(Unk_239a418_Allocator* allocator, Args&&... args) {
    Unk_2771620_Scope scope(allocator);
    void* p = allocator->vf2(sizeof(T), alignof(T));
    if (p == nullptr)
        allocator->vf23();
    T* object = ::new (p) T(std::forward<Args>(args)...);
    object->field_8 = allocator;
    object->field_10 = reinterpret_cast<u64>(object);
    object->field_18 = sizeof(T);
    object->field_20 = alignof(T);
    return object;
}

// The command a sequence function runs: the hash its third argument points
// to is the first field.
struct Unk_23c4ef0_Cmd {
    u64 field_0;  // the hash
    s32 field_8;  // the first frame
    s32 field_c;  // the last frame
    s32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_23c4ef0_Cmd, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_23c4ef0_Cmd, field_10, 0x10);

inline const Unk_23c4ef0_Cmd* Unk_23c4ef0_GetCmd(const u64* hash) {
    return reinterpret_cast<const Unk_23c4ef0_Cmd*>(hash);
}

// How many frames the command runs.
inline s32 Unk_23c4ef0_Frames(const u64* hash) {
    const Unk_23c4ef0_Cmd* cmd = reinterpret_cast<const Unk_23c4ef0_Cmd*>(hash);
    return cmd->field_c - cmd->field_8;
}
