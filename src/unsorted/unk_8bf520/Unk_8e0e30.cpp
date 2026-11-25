// Scope: common
// More readers of the first block of data the object with vtable
// 0x71023bc560 holds (Unk_8e0670.h): its two tables of nine values, its
// words and their bits, and its list. Its type getter's thunks (0x71008e1600
// for +0x48, 0x71008e1610 for +0x50) aren't written: they're emitted with
// its vtable, where its destructor (0x71008dfe20) is. Placeholder names:
// rename once the classes are known.
#include <types.h>

#include "unsorted/unk_8bf520/Unk_8e0670.h"

bool Unk_8ddcc0(u32 index, u8 arg);

// 0x71008e0e30
u16 Unk_8e0e30(Unk_8e0670_Owner* self, u8 index) {
    if (index > 8)
        return 0;
    Unk_8e0670_Block1* block = self->field_180;
    if (block->field_2352 == 1)
        return 0;
    return block->field_219c[index];
}

// 0x71008e0e70
u8 Unk_8e0e70(Unk_8e0670_Owner* self, u8 index) {
    if (index > 8)
        return 0;
    Unk_8e0670_Block1* block = self->field_180;
    if (block->field_2352 == 1)
        return 0;
    return block->field_21ae[index];
}

// 0x71008e0eb0
u16 Unk_8e0eb0(Unk_8e0670_Owner* self, u8 index) {
    if (index > 8)
        return 0;
    Unk_8e0670_Block1* block = self->field_180;
    if (block->field_2352 == 0)
        return 0;
    return block->field_219c[index];
}

// 0x71008e0ef0
u8 Unk_8e0ef0(Unk_8e0670_Owner* self, u8 index) {
    if (index > 8)
        return 0;
    Unk_8e0670_Block1* block = self->field_180;
    if (block->field_2352 == 0)
        return 0;
    return block->field_21ae[index];
}

// 0x71008e0f30
bool Unk_8e0f30(Unk_8e0670_Owner* self, u16 index, u32 bit) {
    return (self->field_180->field_60[index] & (1 << bit)) != 0;
}

// 0x71008e0f50
bool Unk_8e0f50(Unk_8e0670_Owner* self, u16 id, u8 form) {
    if (id == 0)
        return false;
    for (const Unk_8e0670_Entry& entry : self->field_180->field_1060) {
        if (entry.field_0 == id && entry.field_2 == form)
            return true;
    }
    return false;
}

// 0x71008e13e0
bool Unk_8e13e0(Unk_8e0670_Owner* self, s32 index) {
    Unk_8e0670_Block1* block = self->field_180;
    if (block == nullptr)
        return false;
    return (block->field_2337[index / 8] & (1 << (index & 7))) != 0;
}

// 0x71008e1490
bool Unk_8e1490(Unk_8e0670_Owner* self) {
    if (self->field_180 == nullptr)
        return true;
    for (u32 i = 0; i < 0x37b; i++) {
        if (Unk_8ddcc0(i, 0) && self->field_180->field_60[i] == 0)
            return true;
    }
    return false;
}
