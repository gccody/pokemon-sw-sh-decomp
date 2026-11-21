#pragma once
// The class with the vtable 0x71023837d0: a node that plays one of its
// children by the value of a switch or state group (a member subscribes to
// the group). Placeholder names; the layout is what its functions use.
#include "bank_read.h"
#include "containers.h"
#include "keylist.h"

// The nodes one switch value plays, by ID.
struct Unk_23837d0_Nodes : Unk_Array<u32> {
    Unk_23837d0_Nodes() {
        field_0 = nullptr;
        field_8 = 0;
        field_c = 0;
    }
};

// What a node does when the switch changes, 12 bytes copied as a whole.
struct Unk_23837d0_NodeParams {
    struct Times {
        u32 field_0;
        u32 field_4;
    };

    Times field_0;
    u8 field_8_0 : 3;
    u8 field_8_3 : 1;
    u8 field_8_4 : 1;
};

struct Unk_23837d0 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();  // release
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual u32 vf11(u32 id);  // add a child
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual u32 vf17();  // the node's type

    u8 _8[8];
    u32 field_10;  // ID
    u8 _14[0x88];
    u32 field_9c_0 : 29;
    u32 field_9c_29 : 1;
    u8 _a0[0x18];
    Unk_Array<u64> field_b8;  // children
    u8 _c8[0x10];
    u8 field_d8[0x1c];  // the subscriber: a base class with two vtables
    u32 field_f4;  // the group's type: 0 switch, 1 state
    u32 field_f8;  // the group's ID
    u32 field_fc;  // the default value
    Unk_KeyList<u32, Unk_23837d0_Nodes> field_100;  // by switch value
    Unk_KeyList<u32, Unk_23837d0_NodeParams> field_128;  // by node ID
    u32 field_150;
    void* field_158;

    u32 SetNodeParams(u32 id, Unk_23837d0_NodeParams params) {
        Unk_23837d0_NodeParams* item = field_128.Set(id);
        if (item == nullptr)
            return 2;
        *item = params;
        return 1;
    }
};
PKMN_OFFSET_ASSERT(Unk_23837d0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_23837d0, field_b8, 0xb8);
PKMN_OFFSET_ASSERT(Unk_23837d0, field_d8, 0xd8);
PKMN_OFFSET_ASSERT(Unk_23837d0, field_f4, 0xf4);
PKMN_OFFSET_ASSERT(Unk_23837d0, field_100, 0x100);
PKMN_OFFSET_ASSERT(Unk_23837d0, field_128, 0x128);
PKMN_OFFSET_ASSERT(Unk_23837d0, field_150, 0x150);
PKMN_OFFSET_ASSERT(Unk_23837d0, field_158, 0x158);
PKMN_SIZE_ASSERT(Unk_23837d0, 0x160);
