// Scope: common, except the constructor and vf7: diverged (the game's version
// ID, through pkmn::kThisGame).
// The constructor, destructors and virtual functions of Unk_2432540, and the
// accessors of its string. The destructor is its key function: its vtables and
// thunks are emitted here.
#include "unsorted/Unk_136af10.h"

#include <cstring>

#include <pkmn/version.h>

// The owner of the block stores (src/unsorted/Unk_1298270.h).
struct Unk_24ba4e0_Type;
extern Unk_24ba4e0_Type* Unk_24ba4e0;

// 0x710137e480: one of its two stores.
Unk_13471e0_Store* Unk_137e480(Unk_24ba4e0_Type* self, const int& which);

// The block's key in the store.
extern const u32 Unk_1f340a4;

// 0x71007c2280
u8 Unk_7c2280();

// 0x710067c120, 0x710067be60 and 0x710067bde0 (src/unsorted/leaf/Unk_67bdb0.cpp):
// copy a string of u16 units.
u32 Unk_67c120(u64, u64, u16);
u32 Unk_67be60_call(Unk_67be60* self, u64 value);
u32 Unk_67bde0_call(Unk_67bde0* self, u64 value, u16 size);

// A xoroshiro128+ generator.
class Unk_136af10_Random {
public:
    u64 Unk_Next() {
        u64 s0 = field_0;
        u64 s1 = field_8;
        u64 result = s0 + s1;
        s1 ^= s0;
        field_0 = ((s0 << 24) | (s0 >> 40)) ^ s1 ^ (s1 << 16);
        field_8 = (s1 << 37) | (s1 >> 27);
        return result;
    }

    // A number below `max`: the low bits of draws, until one is below it.
    u32 Unk_Below(u32 max) {
        u32 mask = ~0u >> __builtin_clz(max - 1);
        u32 value;
        do {
            value = Unk_Next() & mask;
        } while (value >= max);
        return value;
    }

    u64 field_0;
    u64 field_8;
};

// The global that holds the generator (as in src/unsorted/Unk_ccac00.cpp).
struct Unk_24ba5a8_Type {
    u8 _0[0x98];
    Unk_136af10_Random* field_98;
};
PKMN_OFFSET_ASSERT(Unk_24ba5a8_Type, field_98, 0x98);

extern Unk_24ba5a8_Type* Unk_24ba5a8;

static void Unk_Reset(Unk_136b2b0_T& block) {
    std::memset(&block, 0, sizeof(block));
    block.field_a4 = static_cast<u8>(pkmn::kThisGame);
    block.field_a7 = Unk_7c2280();
    block.field_a5 = 1;
    block.field_cc = Unk_24ba5a8->field_98->Unk_Below(56);
    std::memset(block.field_b0, 0, sizeof(block.field_b0));
    block.field_0.Unk_b70d80();
    block.field_d0 = 0;
    block.field_d4 = 0;
    block.field_d6 = 0;
    block.field_90 = 0;
    block.field_98 = 0;
}

static void Unk_Write(Unk_2432540* self) {
    Unk_24ba4e0_Type* owner = Unk_24ba4e0;
    int which = 0;
    Unk_13471e0_Store* store = Unk_137e480(owner, which);
    Unk_136b2b0_T* data = &self->field_60;
    u64 size = sizeof(self->field_60);
    store->Unk_13456e0(Unk_1f340a4, data, size);
}

// 0x710136af10
Unk_2432540::Unk_2432540() {
    Unk_Reset(field_60);
}

// 0x710136afe0, 0x710136b0d0 (D0), thunks 0x710136b030/0x710136b120 (+0x48)
// and 0x710136b080/0x710136b170 (+0x50)
Unk_2432540::~Unk_2432540() {}

// 0x710136b1c0
void Unk_2432540::vf7() {
    Unk_Reset(field_60);
    Unk_Write(this);
}

// 0x710136b3f0
// NON_MATCHING: the original tests the result's flag as a byte (tst #0xff),
// as if Unk_1346860_Result::field_0 were a u8, not the header's bool.
void Unk_2432540::vf8() {
    Unk_24ba4e0_Type* owner = Unk_24ba4e0;
    int which = 0;
    Unk_13471e0_Store* store = Unk_137e480(owner, which);
    Unk_136b2b0_T* data = &field_60;
    u64 size = sizeof(field_60);
    if (!store->Unk_1346030(Unk_1f340a4, data, size).field_0 && store->field_58 != nullptr)
        store->field_58->vf10(&Unk_1f340a4);
}

// 0x710136b480
void Unk_2432540::vf9() {
    Unk_Write(this);
}

// 0x710136b4f0
void Unk_2432540::Unk_136b4f0(const Unk_2432540& other) {
    field_60 = other.field_60;
}

// 0x710136b500
u32 Unk_2432540::Unk_136b500(Unk_67bde0* source) {
    return Unk_67bde0_call(source, reinterpret_cast<u64>(field_60.field_b0), 13);
}

// 0x710136b520
u32 Unk_2432540::Unk_136b520(Unk_67be60* target) {
    return Unk_67be60_call(target, reinterpret_cast<u64>(field_60.field_b0));
}

// 0x710136b530
u32 Unk_2432540::Unk_136b530(u16* name) {
    return Unk_67c120(reinterpret_cast<u64>(name), reinterpret_cast<u64>(field_60.field_b0), 13);
}
