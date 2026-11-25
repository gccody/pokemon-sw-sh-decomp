// Scope: common
// Free functions that point the static reader of Unk_277a1a0's holders
// (Unk_23a7b38, src/unsorted/unk_761f70/Unk_7814e0.h) at holder `index` and
// read one of its fields, and the TU's static initialiser, which sets up the
// reader's owning pointer.
#include "unsorted/unk_761f70/Unk_7814e0.h"

// An owning pointer to the reader with the allocator that made it: its
// destructor (0x7100780a80, src/unsorted/leaf/Unk_76d9a0.cpp) destroys the
// object and hands it back to the allocator with its size and alignment.
struct Unk_277a178_Owner {
    Unk_23a7b38* field_0;
    void* field_8;
    u64 field_10;
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_277a178_Owner, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_277a178_Owner, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_277a178_Owner, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_277a178_Owner, field_18, 0x18);

// A static of the TU, set up by its static initialiser (0x71007812d0).
extern Unk_277a178_Owner Unk_277a178 __attribute__((visibility("hidden")));

// Three fields packed into 16 bits (0x7100780fe0).
struct Unk_780fe0_Packed {
    u16 field_0 : 4;
    u16 field_4 : 6;
    u16 field_a : 6;
};
static_assert(sizeof(Unk_780fe0_Packed) == 2, "Unk_780fe0_Packed");

// 0x7100780f30
// NON_MATCHING: block order. Above 0xf0 the original tests 0x102 first and
// falls through to 0xf1's return; this tests 0xf1 first (the same with the
// cases in any order, or as an if chain).
u32 Unk_780f30(s32 id) {
    switch (id) {
        case 0xf1:
            return 1;
        case 0xf0:
            return 2;
        case 0x102:
            return 3;
        case 0xc9:
            return 4;
        default:
            return 0;
    }
}

// 0x7100780f80
u16 Unk_780f80(u32 index) {
    Unk_277a178.field_0->Unk_7816f0(index);
    return Unk_277a178.field_0->Unk_781b80();
}

// 0x7100780fb0
u8 Unk_780fb0(u32 index) {
    Unk_277a178.field_0->Unk_7816f0(index);
    return Unk_277a178.field_0->Unk_781be0();
}

// 0x7100780fe0
// NON_MATCHING: Unk_7814e0.h gives Unk_781c40 a u8 return, so this masks it
// (tst #0xff) before the test and keeps the pieces in other registers; the
// original tests all 32 bits (cbz w0): its callee returns a 32-bit type.
Unk_780fe0_Packed Unk_780fe0(u32 index) {
    Unk_277a178.field_0->Unk_7816f0(index);
    Unk_780fe0_Packed packed = {};
    u8 first = Unk_277a178.field_0->Unk_781c40();
    packed.field_0 = first;
    if (first != 0) {
        packed.field_4 = Unk_277a178.field_0->Unk_781d00();
        packed.field_a = Unk_277a178.field_0->Unk_781ca0();
    }
    return packed;
}

// 0x7100781040
// NON_MATCHING: tst w0, #0xff where the original has cmp w0, #0: Unk_781dc0
// returns u8 in Unk_7814e0.h, a 32-bit type in the original.
s32 Unk_781040(u32 index) {
    Unk_277a178.field_0->Unk_7816f0(index);
    s32 count = 0;
    for (u8 kind = 0; kind < 3; ++kind) {
        if (Unk_277a178.field_0->Unk_781dc0(kind) != 0)
            ++count;
    }
    return count;
}

// 0x71007810b0
// NON_MATCHING: Unk_781dc0's u8 return (Unk_7814e0.h) is masked before the
// test, which also moves the blocks around; the original tests 32 bits
// (cbz w0), so its callee returns a 32-bit type.
u8 Unk_7810b0(u32 index, u32 kind, u32* out) {
    if (kind > 2)
        return 0;
    Unk_277a178.field_0->Unk_7816f0(index);
    u8 result = Unk_277a178.field_0->Unk_781dc0(kind);
    if (result != 0)
        *out = Unk_277a178.field_0->Unk_781ee0(kind);
    return result;
}

// 0x7100781130
u8 Unk_781130(u32 index, u32 kind) {
    if (kind > 2)
        return 0;
    Unk_277a178.field_0->Unk_7816f0(index);
    return Unk_277a178.field_0->Unk_782000(kind);
}

// 0x7100781180
s32 Unk_781180(u32 index) {
    Unk_277a178.field_0->Unk_7816f0(index);
    return Unk_277a178.field_0->Unk_782180();
}

// 0x71007811b0
s32 Unk_7811b0(u32 index) {
    Unk_277a178.field_0->Unk_7816f0(index);
    return Unk_277a178.field_0->Unk_782240();
}

// 0x7100781210
u16 Unk_781210(u32 index) {
    Unk_277a178.field_0->Unk_7816f0(index);
    return Unk_277a178.field_0->Unk_781d60();
}

// 0x7100781240
u8 Unk_781240(u32 index) {
    Unk_277a178.field_0->Unk_7816f0(index);
    return Unk_277a178.field_0->Unk_7821e0();
}

// 0x7100781270
u8 Unk_781270(u32 index) {
    Unk_277a178.field_0->Unk_7816f0(index);
    return Unk_277a178.field_0->Unk_7822a0();
}

// 0x71007812a0
// NON_MATCHING: the original calls Unk_782120 with bl and returns its result
// unchanged: a truncation from a wider return type (as in Unk_781240), which
// stops the tail call. Unk_7814e0.h gives Unk_782120 a u8 return, so u8 here
// would tail-call it; bool tests it instead.
u8 Unk_7812a0(u32 index) {
    Unk_277a178.field_0->Unk_7816f0(index);
    return Unk_277a178.field_0->Unk_782120();
}

struct Unk_780a80;
void Unk_780a80_call(Unk_780a80* self) __attribute__((visibility("hidden")));
extern "C" int __cxa_atexit(void (*function)(void*), void* object, void* dso);
extern "C" void* __dso_handle __attribute__((visibility("hidden")));

// 0x71007812d0
void Unk_7812d0_init() {
    Unk_277a178.field_10 = 0;
    Unk_277a178.field_18 = 0;
    Unk_277a178.field_0 = nullptr;
    Unk_277a178.field_8 = nullptr;
    __cxa_atexit(reinterpret_cast<void (*)(void*)>(Unk_780a80_call), &Unk_277a178.field_0,
                 &__dso_handle);
}
