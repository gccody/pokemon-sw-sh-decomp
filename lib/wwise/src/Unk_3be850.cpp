// Scope: common
// What plays the sounds: the list of the playing contexts and what goes
// with it (globals at 0x71024df0a8-0x71024df130). Written from the
// executable. Placeholder names.
#include "block_pool.h"
#include "list2.h"
#include "sorted_array.h"

// A playing context, as far as these functions use it.
struct Unk_3be850_Ctx {
    virtual void vf0(u32 arg1, bool arg2);
    virtual ~Unk_3be850_Ctx();
    virtual u32 vf3();
    virtual void vf4(u32 arg1);

    u8 _8[0x158];
    struct Unk_23837d0_Child* field_160;  // its node
    u8 _168[0x28];
    Unk_3be850_Ctx* next;
    u8 _198[0xd3];
    // 40 bits of flags, not aligned.
    struct __attribute__((packed)) {
        u64 field_26b_0 : 20;
        u64 field_26b_20 : 1;
        u64 field_26b_21 : 4;
        u64 field_26b_25 : 1;
        u64 field_26b_26 : 1;
        u64 field_26b_27 : 13;
    };
    u8 _270[0x38];
    u8 field_2a8[8];
};
PKMN_OFFSET_ASSERT(Unk_3be850_Ctx, next, 0x190);
PKMN_OFFSET_ASSERT(Unk_3be850_Ctx, field_2a8, 0x2a8);

// What a node is asked to play or to count with.
struct Unk_3bee60_Params {
    f32 field_0;
    void* field_8;
    void* field_10;
    u32 field_18;
    bool field_1c;
    bool field_1d;
};

// A node of the hierarchy, as far as these functions call it.
struct Unk_3bedd0_Node {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();  // release
    virtual u32 vf4();  // what kind of node it is
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
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
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
    virtual u32 vf35(Unk_3bee60_Params* params, u32 arg2, u32 arg3);
    virtual void vf36(Unk_3bee60_Params* params);
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
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual void vf59();
    virtual void vf60();
    virtual void vf61();
    virtual void vf62();
    virtual void vf63();
    virtual void vf64();
    virtual void vf65();
    virtual void vf66();
    virtual void vf67();
    virtual void vf68();
    virtual bool vf69(void* arg1);
};

// What is to do with a context later: 0x18 bytes.
struct Unk_3be850_Item {
    Unk_3be850_Ctx* field_0;
    u32 field_8;  // what: 4 ends the context
    u32 field_c;
    f32 field_10;
};
PKMN_SIZE_ASSERT(Unk_3be850_Item, 0x18);

// What the array at 0x71024df0f8 keeps, sorted by a pointer of theirs.
struct Unk_3c0010_T {
    u8 _0[0x20];
    u64 field_20;
};
struct Unk_3c0010_Key {
    static u64& Get(Unk_3c0010_T*& item) { return item->field_20; }
};
typedef Unk_SortedKeyArrayBy<u64, Unk_3c0010_T*, Unk_3c0010_Key, Unk_KeyGreater<u64>> Unk_24df0f8_T;

struct Unk_24df108_T {
    Unk_Array<void*> field_0;
    u8 _10[0x10];
    u64 field_20;
};

extern Unk_ListPolicy<Unk_3be850_Ctx, Unk_ListCount, Unk_ListLast> Unk_24df0a8;  // the contexts
extern Unk_List2Ex<Unk_3be850_Item> Unk_24df0c0;
extern u32 Unk_24df0e8;
extern u32 Unk_24df0ec;
extern u32 Unk_24df0f0;
extern Unk_24df0f8_T Unk_24df0f8;
extern Unk_24df108_T Unk_24df108;

u32 Unk_333940();
void Unk_3339a0();
void Unk_367fe0(Unk_3be850_Ctx* ctx);

// Ends a context that is out of the list.
static inline void Unk_3be850_Destroy(Unk_3be850_Ctx* ctx) {
    Unk_367fe0(ctx);
    ctx->vf4(0);
    if (ctx != nullptr) {
        int pool = Unk_237e820;
        ctx->~Unk_3be850_Ctx();
        Unk_3047c0(pool, ctx);
    }
}

// 0x71003be850
u32 Unk_3be850() {
    Unk_24df0e8 = 0;
    Unk_24df0ec = 0;
    Unk_24df0f0 = 0;
    u32 result = Unk_24df0c0.Init(0x40);
    if (result == 1) {
        Unk_24df108.field_20 = 0;
        result = Unk_333940();
    }
    return result;
}

// 0x71003be8f0
void Unk_3be8f0() {
    Unk_3339a0();
    while (!Unk_24df0a8.IsEmpty()) {
        Unk_3be850_Ctx* ctx = Unk_24df0a8.First();
        Unk_24df0a8.RemoveFirst();
        ctx->vf0(0, true);
        Unk_3be850_Destroy(ctx);
    }
    Unk_24df0a8.RemoveAll();
    Unk_24df0c0.Term();
    Unk_24df108.field_0.Term();
    Unk_24df0f8.Term();
}

// 0x71003bea20
template void Unk_List2Ex<Unk_3be850_Item>::Term();

u32 Unk_3802b0(Unk_3bedd0_Node* node, u32* arg1);

// 0x71003bedd0
bool Unk_3bedd0(Unk_3bedd0_Node* node, void* arg1, u32* result) {
    u32 unused;
    *result = Unk_3802b0(node, &unused);
    if (*result == 3) {
        if (arg1 == nullptr || node->vf4() == 9)
            *result = 2;
        else
            *result = node->vf69(arg1) ? 2 : 1;
    }
    return *result != 1;
}

// 0x71003bee60
u32 Unk_3bee60(Unk_3bedd0_Node* node, void* arg1, u32 arg2, bool arg3, u32* state,
               Unk_3be850_Ctx* ctx, bool arg6, f32 arg7) {
    Unk_3bee60_Params params;
    params.field_18 = 1;
    params.field_1c = false;
    params.field_0 = arg7;
    params.field_1d = !ctx->field_26b_26 && arg6;
    params.field_8 = arg1;
    params.field_10 = ctx->field_2a8;
    u32 result = node->vf35(&params, 1, 0);
    if (result == 2) {
        *state = 0x20;
        return 3;
    }
    if (arg2 == 0x50 || result == 0x50) {
        ctx->field_26b_25 = 1;
        if (!arg3) {
            *state = 0x20;
            return 3;
        }
    }
    return ctx->vf3();
}

// 0x71003bef40
void Unk_3bef40(Unk_3bedd0_Node* node, Unk_3be850_Ctx* ctx, bool arg2, void* arg3) {
    if (ctx != nullptr) {
        if (!arg2)
            ctx->field_26b_20 = 1;
        ctx->vf4(1);
        int pool = Unk_237e820;
        ctx->~Unk_3be850_Ctx();
        Unk_3047c0(pool, ctx);
    } else if (arg2) {
        Unk_3bee60_Params params;
        params.field_18 = 1;
        params.field_0 = 0;
        params.field_8 = arg3;
        params.field_10 = nullptr;
        params.field_1c = false;
        params.field_1d = true;
        node->vf36(&params);
    }
}

void Unk_38d330(Unk_3be850_Ctx* ctx, u32 what, u32 arg2, f32 arg3);
bool Unk_38e160(Unk_3be850_Ctx* ctx, void* arg1);
void Unk_3c5960(void* arg0);
void Unk_3bfdd0();
bool Unk_3bfa20(f32 priority);
u32 Unk_3bfb50(f32 priority);

// How an action fades (as Unk_23837d0_Transition).
struct Unk_3bff70_Transition {
    u32 field_0;
    u32 field_4;
    bool field_8;
};
void Unk_38c050(Unk_3be850_Ctx* ctx, Unk_3bff70_Transition* transition, bool arg2);
extern void* Unk_24bbbc0;
void Unk_339930(void* self, struct Unk_23837d0_Child* node, void* object, u32 arg3);

// 0x71003bf5a0
u32 Unk_3bf5a0(f32 priority, u32* state) {
    if (Unk_3bfa20(priority)) {
        *state = 0x21;
        return Unk_3bfb50(priority);
    }
    *state = 0x22;
    return 2;
}

// 0x71003bf600
void Unk_3bf600(Unk_3be850_Ctx* ctx) {
    Unk_24df0a8.AddLast(ctx);
}

// 0x71003bfce0: something to do with a context later
// NON_MATCHING: the same instructions in another order of the blocks. The two
// inlined AddLast share their second half; the original keeps the first
// one's (the retry jumps back into it), here the retry's is kept and the
// first attempt jumps forward (4 bytes more).
void Unk_3bfce0(Unk_3be850_Ctx* ctx, u32 what, u32 arg2, f32 arg3) {
    Unk_3be850_Item* item = Unk_24df0c0.AddLast();
    if (item == nullptr) {
        Unk_3bfdd0();
        item = Unk_24df0c0.AddLast();
    }
    item->field_0 = ctx;
    item->field_8 = what;
    item->field_c = arg2;
    item->field_10 = arg3;
}

// 0x71003bfdd0: does it
void Unk_3bfdd0() {
    while (Unk_24df0c0.field_24 != 0) {
        Unk_3be850_Item& item = Unk_24df0c0.First();
        Unk_38d330(item.field_0, item.field_8, item.field_c, item.field_10);
        if (item.field_8 == 4) {
            Unk_24df0a8.Remove(item.field_0);
            Unk_3be850_Destroy(item.field_0);
        }
        Unk_24df0c0.RemoveFirst();
    }
}

// 0x71003bff70
void Unk_3bff70(void* arg0) {
    for (auto it = Unk_24df0a8.Begin(); it != Unk_24df0a8.End(); ++it) {
        Unk_3be850_Ctx* ctx = *it;
        if (Unk_38e160(ctx, arg0)) {
            Unk_3bff70_Transition transition;
            transition.field_0 = 0;
            transition.field_4 = 4;
            transition.field_8 = false;
            Unk_38c050(ctx, &transition, true);
            Unk_339930(Unk_24bbbc0, ctx->field_160, nullptr, 0);
        }
    }
    Unk_3c5960(arg0);
}

// 0x71003c0010
void Unk_3c0010(Unk_3c0010_T* self) {
    Unk_3c0010_T** item = Unk_24df0f8.AddNoSetKey(self->field_20);
    if (item != nullptr)
        *item = self;
}

// 0x71003c0050
template Unk_3c0010_T** Unk_24df0f8_T::AddNoSetKey(u64);
