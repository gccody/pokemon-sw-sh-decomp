#pragma once
// The base classes of the sound engine's nodes, each with three vtables (at 0,
// 0x18 and 0x30):
//   Unk_2381d78 (74, 17 and 3 slots; constructor 0x710037e080, destructor
//                0x710037e0e0), 0xb8 bytes
//   Unk_237f858 (76 slots: the children), 0xc8 bytes, inline
//   Unk_237c170 (83 slots; constructor 0x7100309750, destructor 0x71003097b0),
//                0xe8 bytes
// The bases of Unk_2381d78 aren't reconstructed: Unk_NodeA, Unk_NodeB and
// Unk_NodeC only give the vtables their shape, and a slot gets its signature
// when a class here overrides it. Placeholder names.
#include <types.h>
#include "containers.h"

#define UNK_VF10(p)                                                                              \
    virtual void vf##p##0();                                                                     \
    virtual void vf##p##1();                                                                     \
    virtual void vf##p##2();                                                                     \
    virtual void vf##p##3();                                                                     \
    virtual void vf##p##4();                                                                     \
    virtual void vf##p##5();                                                                     \
    virtual void vf##p##6();                                                                     \
    virtual void vf##p##7();                                                                     \
    virtual void vf##p##8();                                                                     \
    virtual void vf##p##9();

// The argument of slot 19.
struct Unk_NodeArg19 {
    u32 field_0;
    void* field_8;
    u32 field_10;
    u8 _14[0xc];
    bool field_20;
    bool field_21;
    bool field_22;
    bool field_23;
    u8 _24[0xc];
    void* field_30;
    union {
        u32 field_38;
        f32 field_38_f;
    };
    u8 field_3c_0 : 1;
    u8 field_3c_1 : 1;
};
PKMN_OFFSET_ASSERT(Unk_NodeArg19, field_38, 0x38);

// The argument of slot 23.
struct Unk_NodeArg23 {
    u32 field_0;
    u8 _4[0x34];
    bool field_38;
};
PKMN_OFFSET_ASSERT(Unk_NodeArg23, field_38, 0x38);

// The argument of slot 71.
struct Unk_NodeArg71_18 {
    u32 field_0;
    u32 field_4;
};
struct Unk_NodeArg71 {
    u8 _0[0x10];
    void* field_10;
    Unk_NodeArg71_18* field_18;
    u8 field_20[0x168];
    u8 field_188_0 : 2;
    u8 field_188_2 : 1;
};
PKMN_OFFSET_ASSERT(Unk_NodeArg71, field_18, 0x18);

struct Unk_310160_T;
class Unk_2381d78;

// What slot 15 fills in for every node below one.
struct Unk_NodeEntry15 {
    u32 field_0;  // the node's ID
    u32 field_4;  // its parent's
    u32 field_8;  // its depth
};

struct Unk_NodeA {
    virtual ~Unk_NodeA() {}
    virtual void vf2();  // adds a reference
    virtual void vf3();  // releases one
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7(Unk_2381d78* parent);
    virtual void vf8();
    virtual void vf9();
    virtual u32 vf10(Unk_2381d78* child);
    virtual u32 vf11(u32 id);
    virtual void vf12(Unk_NodeA* child);
    virtual void vf13(u32 id);
    virtual void vf14();
    virtual void vf15(u32* max, Unk_NodeEntry15* entries, u32* count, u32 depth);
    virtual void vf16(void* a1, void* a2, void* a3, bool a4, void* a5, u32 a6, u32 a7);
    virtual u32 vf17();  // the kind of node
    virtual void vf18();
    virtual void vf19(Unk_NodeArg19* a1);
    virtual void vf20(Unk_NodeArg19* a1);
    virtual void vf21();
    virtual void vf22(void* a1, void* a2, u32 a3);
    virtual void vf23(Unk_NodeArg23* a1);
    virtual void vf24();
    virtual void vf25(void* a1, bool a2, f32 a3);
    virtual void vf26(void* a1, void* a2, f32 a3, bool a4);
    virtual void vf27(u32 a1, void* a2, void* a3, f32 a4);
    virtual void vf28();
    virtual void vf29();
    virtual void vf30(void* a1, void* a2, void* a3);
    virtual void vf31(u32 a1, u32 a2, void* a3, void* a4);
    virtual void vf32();
    virtual void vf33();
    virtual void vf34(u32 a1);
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual u32 vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48(bool a1);
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53(u32 a1, u8 a2);
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual void vf59();
    virtual void vf60();
    virtual bool vf61(u32 a1);
    virtual bool vf62(u32 a1);
    virtual void vf63();
    virtual void vf64();
    virtual void vf65();
    virtual void vf66();
    virtual void vf67();
    virtual void vf68();
    virtual void vf69();
    virtual void vf70();
    virtual u32 vf71(Unk_NodeArg71* a1);
    virtual void vf72();
    virtual void vf73(u32 a1);

    void* field_8;  // next in the index's hash chain
    u32 field_10;  // ID
    u32 field_14;  // reference count
};

// What a node's field_28 points at: an object with a second base at 0x20.
struct Unk_NodeB_28_0 {
    u8 _0[0x20];
};
struct Unk_NodeB_28_20 {
    u64 field_0;
};
struct Unk_NodeB_28 : Unk_NodeB_28_0, Unk_NodeB_28_20 {};

// The base at 0x18: its members are named for the vtable at 0x18 (b_vf<slot>)
// and for their places in the node.
struct Unk_NodeB {
    virtual ~Unk_NodeB() {}
    virtual void b_vf2();
    virtual void b_vf3();
    virtual void b_vf4();
    virtual void b_vf5();
    virtual void b_vf6();
    virtual Unk_NodeB_28_20* b_vf7() { return field_28; }  // 0x710034c1f0
    virtual void b_vf8();
    virtual void b_vf9();
    virtual void b_vf10();
    virtual void b_vf11();
    virtual void b_vf12();
    virtual void b_vf13();
    virtual void b_vf14();
    virtual void b_vf15();
    virtual void b_vf16();

    u64 field_20;
    Unk_NodeB_28* field_28;
};

// The base at 0x30.
struct Unk_NodeC {
    virtual void c_vf0();
    virtual void c_vf1();
    virtual void c_vf2();
};

// A node's children, sorted by ID.
struct Unk_NodeChildren {
    Unk_NodeA** field_0;
    u32 field_8;
    u32 field_c;

    void Term() {
        if (field_0 != nullptr) {
            field_8 = 0;
            Unk_3047c0(Unk_237e820, field_0);
            field_0 = nullptr;
            field_c = 0;
        }
    }

    Unk_NodeA** Exists(u32 key) const {
        s32 top = 0;
        s32 bottom = field_8 - 1;
        while (top <= bottom) {
            s32 mid = top + (bottom - top) / 2;
            Unk_NodeA** p = field_0 + mid;
            if (key < (*p)->field_10)
                bottom = mid - 1;
            else if (key > (*p)->field_10)
                top = mid + 1;
            else
                return p;
        }
        return nullptr;
    }
};

// 0xe8 bytes.
void Unk_37e0e0(void* self);
void Unk_3820f0(void* self);

struct Unk_2381d78_70 {
    u8 _0[0x90];
    s16 field_90;
    u8 _92[2];
    s16 field_94;
};

// 0xb8 bytes.
class Unk_2381d78 : public Unk_NodeA, public Unk_NodeB, public Unk_NodeC {
public:
    explicit Unk_2381d78(u32 id);  // 0x710037e080
    // The destructor is 0x710037e0e0. The classes here call it by the name
    // earlier code gave it (Unk_37e0e0, see ~Unk_237f858), so that the row
    // keeps that name.
    ~Unk_2381d78() override {}

    // What a creator does with the new node: one flag says whether it is of
    // kind 0 or 10, and the node goes into the index (0x71003820f0).
    void Register() {
        u32 kind = vf17();
        field_9c_17 = kind == 0 || kind == 10;
        Unk_3820f0(this);
    }

    u8 _38[0x38];
    Unk_2381d78_70* field_70;
    Unk_2381d78* field_78;  // parent
    void* field_80;
    u8 _88[0x10];
    u32 field_98_0 : 1;
    u32 field_98_1 : 11;
    u32 field_98_12 : 5;
    u32 field_98_17 : 4;
    u32 field_98_21 : 1;
    u32 field_98_22 : 1;
    u32 field_98_23 : 1;
    u32 field_98_24 : 1;
    u32 field_98_25 : 1;
    u32 field_98_26 : 4;
    u32 field_98_30 : 1;
    u32 field_98_31 : 1;
    u32 : 0;
    u32 field_9c_0 : 17;
    u32 field_9c_17 : 1;
    u32 field_9c_18 : 14;
    u64 field_a0;
    u64 field_a8;
    u8 field_b0_0 : 3;
    u8 field_b0_3 : 3;
    u8 field_b0_6 : 2;
    u8 : 0;
    u8 field_b1_0 : 4;
    u8 field_b1_4 : 3;
    u8 field_b1_7 : 1;
};
PKMN_SIZE_ASSERT(Unk_2381d78, 0xb8);
PKMN_OFFSET_ASSERT(Unk_2381d78, field_78, 0x78);

// 0xc8 bytes: a node with children.
class Unk_237f858 : public Unk_2381d78 {
public:
    explicit Unk_237f858(u32 id) : Unk_2381d78(id) {
        field_b8.field_0 = nullptr;
        field_b8.field_8 = 0;
        field_b8.field_c = 0;
    }

    ~Unk_237f858() override {
        field_b8.Term();
        Unk_37e0e0(this);
    }

    virtual u16 vf74();
    virtual u32 vf75(Unk_2381d78* child);

    Unk_NodeChildren field_b8;
};
PKMN_SIZE_ASSERT(Unk_237f858, 0xc8);
PKMN_OFFSET_ASSERT(Unk_237f858, field_b8, 0xb8);

// 0xe8 bytes.
class Unk_237c170 : public Unk_237f858 {
public:
    explicit Unk_237c170(u32 id);  // 0x7100309750
    ~Unk_237c170() override;  // 0x71003097b0

    virtual Unk_310160_T* vf76(void* a1, void* a2, void* a3, bool a4);
    virtual void vf77();
    virtual void vf78();
    virtual void vf79();
    virtual void vf80();
    virtual void vf81();
    virtual void vf82();

    u64 field_c8;
    u64 field_d0;
    u32 field_d8;
    u8 field_dc_0 : 4;
    void* field_e0;
};
PKMN_SIZE_ASSERT(Unk_237c170, 0xe8);

// What slot 76 creates: the base of the classes 0x7100310160 and 0x710031c020 construct.
struct Unk_310160_T {
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

    u8 _8[0x40];
    u32 field_48;  // reference count
};
PKMN_OFFSET_ASSERT(Unk_310160_T, field_48, 0x48);

struct Unk_309110_Arg {
    u32 field_0;
    u32 field_4;
    u32 field_8;
};

struct Unk_309380;
void Unk_308aa0(void* self);
void Unk_309380_call(Unk_309380* self);
u32 Unk_30ae10(Unk_310160_T* self);
void Unk_309110(Unk_310160_T* self, Unk_309110_Arg* arg);
void Unk_30a6e0(void* self);
void Unk_30a0c0(Unk_237c170* self, Unk_NodeArg19* a1);
void Unk_30a210(Unk_237c170* self, Unk_NodeArg19* a1);
void Unk_306630(u64 inst, Unk_237c170* owner, void* a2, u32 a3, u32 value, bool a5);
void Unk_3067b0(u64 inst, Unk_237c170* owner, void* a2, u32 a3, f32 value, bool a5);
extern u64 Unk_24bb988;
