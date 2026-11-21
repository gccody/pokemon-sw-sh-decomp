#pragma once
// The base class of the sound engine's nodes (vtables at 0x710237c170): three
// vtables of 83, 17 and 3 slots, at 0, 0x18 and 0x30. Its own bases aren't
// reconstructed: Unk_NodeA, Unk_NodeB and Unk_NodeC only give the vtables their
// shape, and a slot gets its signature when a class here overrides it.
// Placeholder names.
#include <types.h>

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
    u8 _14[0x24];
    union {
        u32 field_38;
        f32 field_38_f;
    };
    u8 field_3c_0 : 1;
    u8 field_3c_1 : 1;
};
PKMN_OFFSET_ASSERT(Unk_NodeArg19, field_38, 0x38);

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
class Unk_237c170;

struct Unk_NodeA {
    virtual ~Unk_NodeA();
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
    virtual u32 vf17();  // the kind of node
    virtual void vf18();
    virtual void vf19(Unk_NodeArg19* a1);
    virtual void vf20(Unk_NodeArg19* a1);
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    UNK_VF10(3)
    UNK_VF10(4)
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
    UNK_VF10(6)
    virtual void vf70();
    virtual u32 vf71(Unk_NodeArg71* a1);
    virtual void vf72();
    virtual void vf73();
    virtual u16 vf74();
    virtual u32 vf75(Unk_237c170* child);
    virtual Unk_310160_T* vf76(void* a1, void* a2, void* a3, bool a4);
    virtual void vf77();
    virtual void vf78();
    virtual void vf79();
    virtual void vf80();
    virtual void vf81();
    virtual void vf82();

    void* field_8;  // next in the index's hash chain
    u32 field_10;  // ID
    u32 field_14;  // reference count
};

// The base at 0x18: its members are named for the vtable at 0x18 (b_vf<slot>)
// and for their places in the node.
struct Unk_NodeB {
    virtual ~Unk_NodeB();
    virtual void b_vf2();
    virtual void b_vf3();
    virtual void b_vf4();
    virtual void b_vf5();
    virtual void b_vf6();
    virtual void b_vf7();
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
    u64 field_28;
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
class Unk_237c170 : public Unk_NodeA, public Unk_NodeB, public Unk_NodeC {
public:
    explicit Unk_237c170(u32 id);  // 0x7100309750
    ~Unk_237c170() override;  // 0x71003097b0

    // What a creator does with the new node: one flag says whether it is of
    // kind 0 or 10, and the node goes into the index (0x71003820f0).
    void Register();

    u8 _38[0x40];
    Unk_237c170* field_78;  // parent
    u8 _80[0x1c];
    u32 field_9c_0 : 17;
    u32 field_9c_17 : 1;
    u32 field_9c_18 : 14;
    u8 _a0[0x18];
    Unk_NodeChildren field_b8;
    u64 field_c8;
    u64 field_d0;
    u32 field_d8;
    u8 field_dc_0 : 4;
    void* field_e0;
};
PKMN_SIZE_ASSERT(Unk_237c170, 0xe8);
PKMN_OFFSET_ASSERT(Unk_237c170, field_78, 0x78);
PKMN_OFFSET_ASSERT(Unk_237c170, field_b8, 0xb8);
void Unk_3820f0(void* self);

inline void Unk_237c170::Register() {
    u32 kind = vf17();
    field_9c_17 = kind == 0 || kind == 10;
    Unk_3820f0(this);
}

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
