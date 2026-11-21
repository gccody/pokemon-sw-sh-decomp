#pragma once
// The class with the vtable 0x71023837d0: a node that plays one of its
// children by the value of a switch or state group (a member subscribes to
// the group). Placeholder names; the layout is what its functions use.
#include "Unk_3babc0.h"
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

    bool Has(u32 id) const {
        for (Iterator it = Begin(); it != End(); ++it) {
            if (*it == id)
                return true;
        }
        return false;
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

// A playing child that goes on when the switch changes (0x78 bytes).
struct Unk_23837d0_Cont {
    Unk_23837d0_Cont* next;
    void* field_8;
    u64 field_10;
    u32 field_18;
    u32 field_1c;
    void* field_20;  // the game object
    u8 field_28[0x44];
    u32 field_6c;
    u32 field_70;  // 1 while paused
};
PKMN_SIZE_ASSERT(Unk_23837d0_Cont, 0x78);

// A list through the items' `next`, with the number of items before it.
template <class T>
struct Unk_ListLight {
    u32 field_0;  // number of items
    T* field_8;  // first
};

// How an action fades.
struct Unk_23837d0_Transition {
    u32 field_0;  // time
    u32 field_4;  // curve
    bool field_8;

    Unk_23837d0_Transition() : field_8(false) {}
};

// What an action does to a node (0x30 bytes).
struct Unk_23837d0_Action {
    u32 field_0;  // 0 stop, 1 pause, 2 resume
    void* field_8;  // the game object, or null for all
    u32 field_10;
    Unk_23837d0_Transition field_14;
    bool field_20;
    bool field_21;
    bool field_22;
    bool field_23;
    bool field_24;
    void* field_28;

    Unk_23837d0_Action()
        : field_20(false), field_21(false), field_22(false), field_23(false), field_24(false),
          field_28(nullptr) {}
};
PKMN_SIZE_ASSERT(Unk_23837d0_Action, 0x30);

// The switch value a game object's children were last played for, and how
// many times in a row.
struct Unk_23837d0_History {
    u32 field_0;
    u32 field_4;

    void Increment(u32 value) {
        if (field_0 == value) {
            field_4++;
        } else {
            field_0 = value;
            field_4 = 1;
        }
    }
};

// A set of game objects asked by key.
struct Unk_23837d0_Filter {
    virtual bool vf0(const Unk_3babc0_Key& key);
};

// A node of the hierarchy, as far as this class calls it.
struct Unk_23837d0_Child {
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
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19(Unk_23837d0_Action* action);
    virtual void vf20();
    virtual void vf21();
    virtual void vf22(void* object, void* owner, u32 arg3);
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
};

struct Unk_23837d0 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();  // adds a reference
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
    Unk_Array<Unk_23837d0_Child*> field_b8;  // children
    u8 _c8[0x10];
    u8 field_d8[8];  // the subscriber, a base class
    u8 field_e0[8];  // a second base class: what is told that data is prepared
    u64 field_e8;
    u32 field_f0;  // how many times the data was asked to be prepared
    u32 field_f4;  // the group's type: 0 switch, 1 state
    u32 field_f8;  // the group's ID
    u32 field_fc;  // the default value
    Unk_KeyList<u32, Unk_23837d0_Nodes> field_100;  // by switch value
    Unk_KeyList<u32, Unk_23837d0_NodeParams> field_128;  // by node ID
    Unk_ListLight<Unk_23837d0_Cont> field_150;

    // A node's parameters, or the default ones.
    void GetNodeParams(u32 id, Unk_23837d0_NodeParams& params) {
        Unk_23837d0_NodeParams* item = field_128.Exists(id);
        if (item != nullptr) {
            params = *item;
        } else {
            params.field_8_3 = 0;
            params.field_8_4 = 0;
            params.field_8_0 = 0;
            params.field_0.field_0 = 0;
            params.field_0.field_4 = 0;
        }
    }

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
PKMN_OFFSET_ASSERT(Unk_23837d0, field_f0, 0xf0);
PKMN_SIZE_ASSERT(Unk_23837d0, 0x160);
