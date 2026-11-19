#pragma once
// The event system's inside (src/battle/battle_engine/Unk_7e8a20.h is what its
// callers see): a stack of frames of variables, each variable a label and a
// value, and the list of registered handlers. Their getters and setters of
// single fields are leaf functions matched on their own
// (src/unsorted/leaf/Unk_7e89c0.cpp), each with a placeholder type of its own.
// Placeholder names: rename once the classes are known.
#include <types.h>

#include "battle/battle_engine/Unk_7e8a20.h"

// A variable (vtable 0x71023ac788).
struct Unk_7e9dc0_Var {
    void* field_0;
    u16 field_8;  // label
    u8 field_a;   // kind
    u8 _b;
    s32 field_c;   // value
    s32 field_10;  // minimum
    s32 field_14;  // maximum
    void* field_18;
};
PKMN_SIZE_ASSERT(Unk_7e9dc0_Var, 0x20);

// A frame: a variable for each label (vtable 0x71023ac768).
struct Unk_7e9d60_Frame {
    void* field_0;
    Unk_7e9dc0_Var* field_8[0x7b];
};
PKMN_SIZE_ASSERT(Unk_7e9d60_Frame, 0x3e0);

// A registered handler, in a doubly linked list.
struct Unk_7e9b00_Node {
    u8 _0[0x10];
    Unk_7e9b00_Node* field_10;
    Unk_7e9b00_Node* field_18;
    u8 _20[0x3c - 0x20];
    u32 field_3c_0 : 24;
    u32 field_3c_24 : 1;
    u32 field_3c_25 : 1;
    u32 field_3c_26 : 1;
    u32 field_3c_27 : 2;
    u32 field_3c_29 : 1;
    u32 field_3c_30 : 2;
};
PKMN_OFFSET_ASSERT(Unk_7e9b00_Node, field_18, 0x18);

// What Unk_7e99b0 copies.
struct Unk_7e99b0_Data {
    u64 field_0[8];
};
struct Unk_7e99b0_Self {
    void* field_0;
    u16 field_8;
    u8 _a[0x20 - 0xa];
    Unk_7e99b0_Data field_20;
};
PKMN_OFFSET_ASSERT(Unk_7e99b0_Self, field_20, 0x20);

struct Unk_7fe240;

// What the stacks hold: an object, and where it was allocated (gflib3).
template <class T>
struct Unk_7ea110_Entry {
    T* field_0;
    void* field_8;
    u64 field_10;
    u64 field_18;
};

// The stack of variables (vtable 0x71023ac7a8): label 1 marks where a frame
// starts, label 0 a free variable.
struct Unk_7ea110_Stack {
    void* field_0;
    Unk_7ea110_Entry<Unk_7e9dc0_Var> field_8[0x60];
    u32 field_c08;
};
PKMN_OFFSET_ASSERT(Unk_7ea110_Stack, field_c08, 0xc08);

// The stack of frames (vtable 0x71023ac7c8).
struct Unk_7ea5d0_Frames {
    void* field_0;
    Unk_7ea110_Entry<Unk_7e9d60_Frame> field_8[0x20];
    u32 field_408;
};
PKMN_OFFSET_ASSERT(Unk_7ea5d0_Frames, field_408, 0x408);

void Unk_7e9d20(Unk_7e9d60_Frame* self);

struct Unk_7e8a20 {
    u8 _0[0x8];
    const Unk_7fe240* field_8;
    u8 _10[0x30 - 0x10];
    Unk_7ea110_Stack* field_30;
    u8 _38[0x50 - 0x38];
    Unk_7ea5d0_Frames* field_50;
    u8 _58[0x70 - 0x58];
    Unk_7e9d60_Frame* field_70;
    s32 field_78;
};
PKMN_OFFSET_ASSERT(Unk_7e8a20, field_70, 0x70);

void Unk_7ea270(Unk_7ea110_Stack* self);
void Unk_7ea2f0(Unk_7ea110_Stack* self);
Unk_7e9dc0_Var* Unk_7ea3b0(Unk_7ea110_Stack* self, u16 label);
Unk_7e9d60_Frame* Unk_7ea800(Unk_7ea5d0_Frames* self);
void Unk_7ea830(Unk_7ea5d0_Frames* self);
Unk_7e9dc0_Var* Unk_7e9d60(Unk_7e9d60_Frame* self, u16 label);
void Unk_7e9d80(Unk_7e9d60_Frame* self, Unk_7e9dc0_Var* var);
void Unk_7e9f20(Unk_7e9dc0_Var* self, void* value);
void Unk_7e9ca0(Unk_7e9b00_Node* self, bool value);
void Unk_7eaee0(void* self, Unk_7e9b00_Node* node);
void Unk_7eadb0(void* self,
                u32 arg1,
                u32 arg2,
                u32 arg3,
                u32 arg4,
                u32 arg5,
                void* arg6,
                u32 arg7,
                u16 depth);

// Declared as src/unsorted/leaf/Unk_7e89c0.cpp declares them (its callers
// there match): pointers as integers.
void Unk_7ea110(u64 self);
void Unk_7ea5d0(u64 self);

// The leaf functions, with their own placeholder types.
struct Unk_7ea260;
bool Unk_7ea260_check(const Unk_7ea260* self);
struct Unk_7ea810;
void Unk_7ea810_set(Unk_7ea810* self);
struct Unk_7e9e10;
void Unk_7e9e10_setField8(Unk_7e9e10* self, u16 value);
struct Unk_7e9e20;
void Unk_7e9e20_set(Unk_7e9e20* self, u32 value);
struct Unk_7e9e30;
void Unk_7e9e30_set(Unk_7e9e30* self, u32 value);
struct Unk_7e9e50;
void Unk_7e9e50_set(Unk_7e9e50* self, u32 value);
struct Unk_7e9eb0;
void Unk_7e9eb0_set(Unk_7e9eb0* self, u32 value, u32 arg2, u32 arg3);
struct Unk_7e9ea0;
void Unk_7e9ea0_set(Unk_7e9ea0* self);
struct Unk_7e9f40;
u16 Unk_7e9f40_getField8(const Unk_7e9f40* self);
struct Unk_7eaf40;
Unk_7e9b00_Node* Unk_7eaf40_getField1588(const Unk_7eaf40* self);
const Unk_7eaf40* Unk_7fe240_getField88(const Unk_7fe240* self);
struct Unk_7e9b30;
Unk_7e9b00_Node* Unk_7e9b30_getField18(const Unk_7e9b30* self);
struct Unk_7e9ac0;
u32 Unk_7e9ac0_update(Unk_7e9ac0* self);
struct Unk_7e9ae0;
u32 Unk_7e9ae0_update(Unk_7e9ae0* self);
struct Unk_7e9a60;
u8 Unk_7e9a60_getField3b(const Unk_7e9a60* self);
struct Unk_7e9b70;
u8 Unk_7e9b70_getField30(const Unk_7e9b70* self);
struct Unk_7e9bb0;
bool Unk_7e9bb0_get(const Unk_7e9bb0* self);
struct Unk_7e9bd0;
bool Unk_7e9bd0_get(const Unk_7e9bd0* self);
