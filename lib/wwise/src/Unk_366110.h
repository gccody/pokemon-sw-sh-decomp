#pragma once
// The objects of the list of an Unk_363570_T (Unk_366110_T, index 0x118) and
// what they know of the nodes they refer to. Placeholder names.
#include "Unk_360c20.h"

struct Unk_366110_Node;

struct Unk_366110_T;
u32 Unk_380980(Unk_366110_Node* self, Unk_366110_T* a1);
u32 Unk_3807d0(Unk_366110_Node* self, Unk_366110_T* a1);
Unk_366110_Node* Unk_3351b0(void* self, u32 id, u32 kind);

// What an Unk_366110_T keeps for a child of its owner.
struct Unk_366110_Child {
    u32 field_0;  // the ID of the child
    Unk_366110_Node* field_8;  // the child, when it has the same owner
    Unk_35f3b0_Table field_10;
    f32 field_20;  // where the table starts
    f32 field_24;  // and ends

    Unk_366110_Child() : field_0(0), field_8(nullptr), field_20(-3.4028235e38f), field_24(3.4028235e38f) {}

    inline u32 ClearChild(Unk_366110_T* self);
    inline u32 UpdateChild(Unk_366110_T* self);
    inline u32 Term(Unk_366110_T* self);
};
PKMN_SIZE_ASSERT(Unk_366110_Child, 0x28);

struct Unk_366110_T : Unk_Indexed {
    virtual void vf2();  // add a reference
    virtual void vf3();  // release

    Unk_KeyArray<u32, Unk_366110_Child> field_18;
    u64 field_28;  // the parameters it follows, a bit each
    void* field_30;  // owner
    u32 field_38;
    u32 field_3c;
};
PKMN_SIZE_ASSERT(Unk_366110_T, 0x40);

struct Unk_366110_NodeInfo {
    u8 _0[0x90];
    s16 field_90;
    s16 field_92;
    s16 field_94;
};

struct Unk_366110_Node {
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
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19(void* action);
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23(void* info);
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
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48(u32 a1);

    u8 _8[0x68];
    Unk_366110_NodeInfo* field_70;
    void* field_78;  // owner
    void* field_80;
    u8 _88[0x20];
    Unk_GrowArray<Unk_366110_T*, Unk_PoolDefault, 4>* field_a8;
};

inline u32 Unk_366110_Child::ClearChild(Unk_366110_T* self) {
    if (field_8 != nullptr) {
        u32 result = Unk_380980(field_8, self);
        field_8 = nullptr;
        return result;
    }
    return 1;
}

// 1, or 2 when the node has another owner, or what adding the object to the
// node gave.
inline u32 Unk_366110_Child::UpdateChild(Unk_366110_T* self) {
    Unk_366110_Node* node = Unk_3351b0(Unk_24bbbb8, field_0, 0);
    if (node == nullptr)
        return 1;
    u32 result = 1;
    if (self->field_30 != nullptr && node->field_78 != nullptr) {
        if (node->field_78 == self->field_30) {
            field_8 = node;
            result = Unk_3807d0(node, self);
            if (result != 1)
                field_8 = nullptr;
        } else {
            result = 2;
        }
    }
    node->vf3();
    return result;
}

inline u32 Unk_366110_Child::Term(Unk_366110_T* self) {
    u32 result = ClearChild(self);
    field_8 = nullptr;
    field_0 = 0;
    field_10.Unset();
    return result;
}

// The key of a subscription to a game parameter.
struct Unk_366f90_Key {
    u64 field_0;
    u32 field_8;
    u32 _c;
    u32 field_10;
    u32 _14;
    u8 field_18;
    u8 _19[7];
    u8 field_20;
    u8 _21[7];
    u64 field_28;

    Unk_366f90_Key()
        : field_0(0), field_8(0), field_10(0), field_18(0xff), field_20(0xff), field_28(0) {}
};
PKMN_SIZE_ASSERT(Unk_366f90_Key, 0x30);
