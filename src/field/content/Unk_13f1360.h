#pragma once
// Script commands of game/unk_133d350 (0x71013f1360-0x71013f23a4): entries of a
// command table that take the script's context and its arguments, find a field
// object by the id in their first argument and call it. Placeholder names: rename
// once the classes are known.
#include <arm_neon.h>

#include <vector>

#include <types.h>

#include "gflib3/Unk_239a418.h"

// The script's context: 0x710066efd0 sets what it waits for
// (src/unsorted/leaf/Unk_65b680.cpp).
struct Unk_66efd0;
u32 Unk_66efd0_update(Unk_66efd0* self, u32 code);

// A command's arguments, a 64-bit slot each (field_0 isn't read here).
struct Unk_13f1360_Args {
    s64 field_0;
    s64 field_8;
    s64 field_10;
    s64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_13f1360_Args, field_18, 0x18);

// A field object: the manager's list holds them.
class Unk_13f1360_Object : public Unk_239a418 {
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
    virtual bool vf17();  // gone: skipped when looking objects up

    // The object as a T, or null when it isn't one: through its +0x50 interface.
    template <class T>
    T* Unk_Cast() {
        Unk_239a498* object = this;
        const Unk_239a418_Type* type = object->vf_type();
        const Unk_239a418_Type* kind = T::Unk_GetType();
        for (; type != nullptr; type = type->field_0)
            if (type == kind)
                return static_cast<T*>(object);
        return nullptr;
    }

    u8 _60[0x1a0 - 0x60];
    s64 field_1a0;  // the id the commands look it up by
};
static_assert(__builtin_offsetof(Unk_13f1360_Object, field_1a0) == 0x1a0, "field_1a0");

struct Unk_13f1360_Manager {
    u8 _0[0xb0];
    std::vector<Unk_13f1360_Object*> field_b0;
};
static_assert(__builtin_offsetof(Unk_13f1360_Manager, field_b0) == 0xb0, "field_b0");

extern Unk_13f1360_Manager* Unk_27d6158;

// What the lookups (0x71013a67a0, 0x71013f6c00) match an object's field_1a0
// against.
struct Unk_13f1360_Find {
    const s64* id;
};
PKMN_SIZE_ASSERT(Unk_13f1360_Find, 0x8);

// An entry of the table at +0x5f0: a hash and a flag.
struct Unk_d01720_Entry {
    u64 field_0;
    u8 field_8;
};
PKMN_SIZE_ASSERT(Unk_d01720_Entry, 0x10);

// The leaf placeholders (src/unsorted/leaf/Unk_cf41f0.cpp) the object is passed
// to.
struct Unk_d00dd0;
struct Unk_d00dd0_arg1 {
    u32 field_0;
};
struct Unk_d00de0;
struct Unk_d00de0_arg1 {
    u32 field_0;
};
struct Unk_d00de0_arg2 {
    u32 field_0;
};
void Unk_d00dd0_set(Unk_d00dd0* self, const Unk_d00dd0_arg1* value);
void Unk_d00de0_set(Unk_d00de0* self, const Unk_d00de0_arg1* value, const Unk_d00de0_arg2* arg2);

// The objects 0x71013f6c00 finds: their functions are at 0x7100d00b50-0x7100d019c0.
class Unk_13f6c00_Object : public Unk_13f1360_Object {
public:
    // 0x7100d00b50
    bool Unk_d00b50();
    // 0x7100d00e00
    bool Unk_d00e00(s32 count);
    // 0x7100d011d0
    void Unk_d011d0();
    // 0x7100d01720
    Unk_d01720_Entry Unk_d01720(s32 index);
    // 0x7100d01730 (clears the entry)
    void Unk_d01730(s32 index);
    // 0x7100d01750
    u64 Unk_d01750(s32 index);
    // 0x7100d01760
    void Unk_d01760(bool value);
    // 0x7100d01870
    void Unk_d01870();
    // 0x7100d018e0
    void Unk_d018e0();
    // 0x7100d01950
    bool Unk_d01950();
    // 0x7100d01970
    void Unk_d01970();
    // 0x7100d019c0
    void Unk_d019c0();

    u8 _1a8[0x6a8 - 0x1a8];
    s32 field_6a8;  // what Unk_d00dd0_set sets
    u8 _6ac[0x6bc - 0x6ac];
    s32 field_6bc;
};
static_assert(__builtin_offsetof(Unk_13f6c00_Object, field_6a8) == 0x6a8, "field_6a8");
static_assert(__builtin_offsetof(Unk_13f6c00_Object, field_6bc) == 0x6bc, "field_6bc");

// 0x71013f6c00: the first object of the manager's that is an Unk_13f6c00_Object,
// isn't gone and has the id.
Unk_13f6c00_Object* Unk_13f6c00(Unk_13f1360_Manager* manager, const Unk_13f1360_Find& find);

// Looks an Unk_13f6c00_Object up by its id.
inline Unk_13f6c00_Object* Unk_13f1360_FindObject(const s64& id) {
    return Unk_13f6c00(Unk_27d6158, Unk_13f1360_Find{&id});
}
