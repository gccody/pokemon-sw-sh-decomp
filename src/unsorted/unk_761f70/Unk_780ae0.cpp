// Scope: common
// The move data reader (an Unk_23a7b38 on holders of loaded FlatBuffers data,
// src/unsorted/unk_761f70/Unk_7814e0.h): making and destroying the one at
// 0x710277a178, and the accessors that point it at a move and read one of its
// fields. Placeholder names: rename once the classes are known.
#include <memory>

#include "unsorted/Unk_23f4660.h"
#include "unsorted/Unk_2771620.h"
#include "unsorted/unk_761f70/Unk_7814e0.h"

// Loads the holders and lets them go (src/unsorted/unk_761f70/Unk_7814e0.cpp).
void Unk_7814e0(void* heap);
void Unk_781640();

// Reads a field of the selected data by `kind` (0x7100782360, not decompiled).
bool Unk_782360(const Unk_23a7b38* self, u32 kind);

// The reader.
extern std::unique_ptr<Unk_23a7b38, Unk_23f4660_Deleter> Unk_277a178
    __attribute__((visibility("hidden")));

// 0x7100780ae0
// NON_MATCHING: the original passes the allocator to the constructor (x1). It
// matches once Unk_23a7b38's constructor takes it (0x71007816b0,
// _ZN11Unk_23a7b38C2EP21Unk_239a418_Allocator) and this passes it on:
// Unk_2771620_MakeUnique<Unk_23a7b38>(heap, heap).
void Unk_780ae0(Unk_239a418_Allocator* heap) {
    Unk_7814e0(heap);
    Unk_277a178 = Unk_2771620_MakeUnique<Unk_23a7b38>(heap);
}

// 0x7100780bd0
void Unk_780bd0() {
    Unk_277a178.reset();
    Unk_781640();
}

// 0x7100780c30
// NON_MATCHING: matches, but functions.csv names it _Z10Unk_780c30m: the move
// is a u32 (mov w1, w0). Rename it _Z10Unk_780c30j.
bool Unk_780c30(u32 move) {
    Unk_277a178->Unk_7816f0(move);
    return Unk_277a178->Unk_781700();
}

// 0x7100780c60
bool Unk_780c60(u32 move, u32 kind) {
    Unk_277a178->Unk_7816f0(move);
    return Unk_782360(Unk_277a178.get(), kind);
}

// 0x7100780ca0
// NON_MATCHING: matches once functions.csv names it _Z10Unk_780ca0jh (the
// count of PP ups is a u8: and w9, w1, #0xff) and Unk_23a7b38::Unk_7819a0
// returns a u32 (src/unsorted/unk_761f70/Unk_7814e0.h; it still matches so).
u8 Unk_780ca0(u32 move, u8 ups) {
    if (ups > 3)
        ups = 3;
    Unk_277a178->Unk_7816f0(move);
    u8 pp = Unk_277a178->Unk_7819a0();
    return pp + pp * static_cast<u8>(ups * 20) / 100;
}

// 0x7100780d10
// NON_MATCHING: matches once Unk_23a7b38::Unk_781880 returns a u32 (it still
// matches so): the original calls it and doesn't tail call it.
u8 Unk_780d10(u32 move) {
    Unk_277a178->Unk_7816f0(move);
    return Unk_277a178->Unk_781880();
}

// 0x7100780d40
u8 Unk_780d40(u32 move) {
    Unk_277a178->Unk_7816f0(move);
    return Unk_277a178->Unk_781760();
}

// 0x7100780d70
u8 Unk_780d70(u32 move) {
    Unk_277a178->Unk_7816f0(move);
    return Unk_277a178->Unk_781820();
}

// 0x7100780da0
u8 Unk_780da0(u32 move) {
    Unk_277a178->Unk_7816f0(move);
    return Unk_277a178->Unk_7817c0();
}

// 0x7100780dd0
s32 Unk_780dd0(u32 move) {
    Unk_277a178->Unk_7816f0(move);
    return Unk_277a178->Unk_781a00();
}

// 0x7100780e00
// NON_MATCHING: matches once Unk_23a7b38::Unk_7818e0 returns a u32: the
// original calls it and doesn't tail call it. (Unk_7818e0 doesn't match yet
// with a u32 return written as it is.)
u8 Unk_780e00(u32 move) {
    Unk_277a178->Unk_7816f0(move);
    return Unk_277a178->Unk_7818e0();
}

// 0x7100780e30
bool Unk_780e30(u32 move) {
    Unk_277a178->Unk_7816f0(move);
    return Unk_277a178->Unk_781940();
}

// 0x7100780e60
u8 Unk_780e60(u32 move) {
    Unk_277a178->Unk_7816f0(move);
    return Unk_277a178->Unk_781ac0();
}

// 0x7100780e90
u8 Unk_780e90(u32 move) {
    Unk_277a178->Unk_7816f0(move);
    return Unk_277a178->Unk_781b20();
}

// 0x7100780ec0
// NON_MATCHING: matches once Unk_23a7b38::Unk_781880 returns a u32 (it still
// matches so): the original compares all of w0 with 0.
bool Unk_780ec0(u32 move) {
    Unk_277a178->Unk_7816f0(move);
    return Unk_277a178->Unk_781880() != 0;
}

// 0x7100780f00
// NON_MATCHING: matches once Unk_23a7b38::Unk_781a60 returns a u32 (it still
// matches so): the original calls it and doesn't tail call it.
u8 Unk_780f00(u32 move) {
    Unk_277a178->Unk_7816f0(move);
    return Unk_277a178->Unk_781a60();
}
