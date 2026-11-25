#pragma once
// The manager Unk_27ce848 points to, and the handles that address it
// (Unk_23a8158, vtable 0x71023a8168, and Unk_23a8100, vtable 0x71023a8110,
// src/unsorted/virtual/Unk_792950.cpp). A handle is named by a string; the
// manager's lookup (Unk_791a00, on the object Unk_24ba4f0 points to) gives the
// index it is known by. Placeholder names: rename once the classes are known.
#include <nn/os.h>
#include <types.h>

#include "unsorted/Unk_d0c0.h"

// The manager: what it forwards to (+0x70) and its mutex (+0x90).
struct Unk_793990_Manager {
    u8 _0[0x70];
    void* field_70;
    u8 _78[0x18];
    nn::os::MutexType field_90;
};
PKMN_OFFSET_ASSERT(Unk_793990_Manager, field_70, 0x70);
PKMN_OFFSET_ASSERT(Unk_793990_Manager, field_90, 0x90);

// A string's characters: the static empty string's when it has none.
extern const char* const Unk_236d888;

inline const char* Unk_793990_CStr(const Unk_d0c0_String& str) {
    return str.m_ptr ? str.m_ptr->field_60 : Unk_236d888;
}

// The handle: its vtable, and its name.
class Unk_23a8158 {
public:
    virtual ~Unk_23a8158();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();

    // Whether it has a name (a string with characters).
    bool Unk_HasName() const { return field_8.m_ptr && field_8.m_ptr->field_60[0] != '\0'; }

    Unk_d0c0_String field_8;
};
static_assert(sizeof(Unk_23a8158) == 0x10, "Unk_23a8158");

extern Unk_793990_Manager* Unk_27ce848;
// What the handles are looked up in.
extern void* Unk_24ba4f0;

// The handle's index (-1: none). `add`: make one if it has none.
s64 Unk_791a00(void* registry, const void* handle, bool add);

// The manager's calls (src/unsorted/Unk_793990.cpp and before it), by the
// handle's index.
bool Unk_793640(Unk_793990_Manager* self, s64 index, const Unk_5cfaf0_Name& name);
bool Unk_7936f0(Unk_793990_Manager* self, s64 index);
bool Unk_793740(Unk_793990_Manager* self, const void* arg1, u64 arg2, u64 arg3, s64 index);
u32 Unk_7938b0(Unk_793990_Manager* self, const void* arg1, s64 index);
bool Unk_793930(Unk_793990_Manager* self, s64 index, f32 arg2);
bool Unk_793990(Unk_793990_Manager* self, const Unk_5cfaf0_Name* name, f32 decibels, s64 index);
bool Unk_793ac0(u64 manager, u64 value, u64 index);
bool Unk_793b20(u64 manager, u64 name, f32 arg2, u64 index, u32 arg3);
bool Unk_793ba0(Unk_793990_Manager* self,
                const Unk_5cfaf0_Name* name,
                const Unk_5cfaf0_Name* other,
                s64 index);
// Lets the index go.
void Unk_792300(void* registry, s64 index);
