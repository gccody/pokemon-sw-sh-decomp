#pragma once
// An item of the owner 0x7102383cc0 with a second base at 0x58 (the class of
// 0x71003e1d40). Written from the executable. Placeholder names.
#include "Unk_2383cc0.h"

// A node, as far as it is asked here: the one above it is at 0x78.
struct Unk_3e22b0_Node {
    u8 _0[0x78];
    Unk_3e22b0_Node* field_78;
};

// What it plays: told when it is replaced.
struct Unk_3e23a0_Object {
    virtual void vf0(u32 arg1);
};

// Pointers into what it plays: 0x40 bytes.
struct Unk_3e2ee0_T {
    u8 _0[8];
    u8* field_8;  // the start of it
    u8 _10[0x18];
    u8* field_28;
    u8* field_30;
    u8* field_38;
};
void Unk_3e2ee0(Unk_3e2ee0_T* self, u8* start);

// What its second base is called with.
struct Unk_3e2390_Second {
    virtual void vf0(u32 arg1);
};

struct Unk_3e2390_T {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12(u64 arg1);

    Unk_3e2390_T* field_8;  // next
    u8 _10[0x48];
    Unk_3e2390_Second field_58;
    u8 _60[0x58];
    Unk_2383cc0* field_b8;  // the owner
    Unk_3e22b0_Node* field_c0;  // its node
    void* field_c8;
    u8 _d0[8];
    Unk_3e23a0_Object* field_d8;  // what it plays
    u8* field_e0;
    u32 field_e8;
    Unk_3e2ee0_T field_f0;
    u8 _130[0x4c];
    u8 field_17c_0 : 1;
};
PKMN_OFFSET_ASSERT(Unk_3e2390_T, field_58, 0x58);
PKMN_OFFSET_ASSERT(Unk_3e2390_T, field_b8, 0xb8);
PKMN_OFFSET_ASSERT(Unk_3e2390_T, field_d8, 0xd8);

template <>
struct Unk_ListNext<Unk_3e2390_T> {
    static Unk_3e2390_T*& Get(Unk_3e2390_T* item) { return item->field_8; }
};

bool Unk_3e2390(Unk_3e2390_T* self, void* arg1);
bool Unk_3e23a0(Unk_3e2390_T* self, void* arg1);
