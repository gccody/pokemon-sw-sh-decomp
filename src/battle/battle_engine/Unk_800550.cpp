// Scope: common
// Two rows of 30 5-bit flag sets (Unk_23ac958), and a pair of 0x40-byte
// Unk_800a30s owned through an allocator with the Unk_7cac80 that picks one.
// Placeholder names: rename once the classes are known.
#include <cstring>
#include <memory>

#include "unsorted/Unk_2771620.h"
#include "unsorted/Unk_23f4660.h"

struct Unk_23ac958_Row {
    u32 field_0[30];
};
PKMN_SIZE_ASSERT(Unk_23ac958_Row, 0x78);

class Unk_23ac958 {
public:
    virtual ~Unk_23ac958();

    Unk_23ac958_Row field_8[2];
};
PKMN_OFFSET_ASSERT(Unk_23ac958, field_8, 0x8);
PKMN_SIZE_ASSERT(Unk_23ac958, 0xf8);

// 0x7100800600
void Unk_800600(Unk_23ac958* self, const Unk_23ac958* other) {
    memcpy(self->field_8, other->field_8, sizeof(self->field_8));
}

// 0x7100800610
void Unk_800610(Unk_23ac958* self) {
    self->field_8[1] = self->field_8[0];
    self->field_8[0] = Unk_23ac958_Row();
}

// 0x7100800680
bool Unk_800680(const Unk_23ac958* self, u8 index, u8 row, u8 bit) {
    bool result = false;
    if (index < 30 && row < 2 && bit < 5)
        result = (self->field_8[row].field_0[index] & (1u << bit)) != 0;
    return result;
}

// 0x71008006e0
void Unk_8006e0(void* object, u32 arg1, u32 arg2) {
    Unk_23ac958* self = static_cast<Unk_23ac958*>(object);
    u8 index = arg1;
    u8 bit = arg2;
    if (index < 30 && bit < 5)
        self->field_8[0].field_0[index] |= 1u << bit;
}

struct Unk_800a30;
void Unk_800a30_set(Unk_800a30* self, u64 value, u64 arg2);
void Unk_800ab0(Unk_800a30* self, const Unk_800a30* other);
void Unk_800b30(Unk_800a30* self, u32 value);

// Unk_800a30_set constructs one.
struct Unk_800a30 {
    Unk_800a30(u64 value, u64 arg2) { Unk_800a30_set(this, value, arg2); }

    u64 _0[8];
};
PKMN_SIZE_ASSERT(Unk_800a30, 0x40);

struct Unk_7cac80;
u8 Unk_7cac80_call(const Unk_7cac80* self, u32 value);

struct Unk_800760_Pair {
    const Unk_7cac80* field_0;
    std::unique_ptr<Unk_800a30, Unk_23f4660_Deleter> field_8[2];
};
PKMN_OFFSET_ASSERT(Unk_800760_Pair, field_8, 0x8);
PKMN_SIZE_ASSERT(Unk_800760_Pair, 0x48);

// 0x7100800760
void Unk_800760(void* object, void* allocator, u64 arg2, u64 arg3) {
    Unk_800760_Pair* self = static_cast<Unk_800760_Pair*>(object);
    Unk_239a418_Allocator* heap = static_cast<Unk_239a418_Allocator*>(allocator);
    self->field_8[0] = Unk_2771620_MakeUnique<Unk_800a30>(heap, arg2, arg3);
    self->field_8[1] = Unk_2771620_MakeUnique<Unk_800a30>(heap, arg2, arg3);
}

// 0x7100800900
void Unk_800900(Unk_800760_Pair* self, const Unk_800760_Pair* other) {
    Unk_800ab0(self->field_8[0].get(), other->field_8[0].get());
    Unk_800ab0(self->field_8[1].get(), other->field_8[1].get());
}

// 0x7100800940
void Unk_800940(Unk_800760_Pair* self, u32 value) {
    u8 index = Unk_7cac80_call(self->field_0, value);
    if (index < 2)
        Unk_800b30(self->field_8[index].get(), value);
}

// 0x7100800990
void* Unk_800990(void* object, u8 index) {
    return static_cast<Unk_800760_Pair*>(object)->field_8[index].get();
}

// 0x71008009a0
Unk_800a30* Unk_8009a0(const Unk_800760_Pair* self, u8 index) {
    return self->field_8[index].get();
}
