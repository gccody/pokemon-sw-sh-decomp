// Scope: common
// Counters of the class with the vtable Unk_23ac918 (0x71023ac918), and a
// small set of up to five ids. Placeholder types: rename them once the owning
// classes are known.
#include <types.h>

#include <array>

// The data of the Unk_23ac918 class: its constructor (0x71007ff3a0) stores the
// vptr and zeroes everything after it.
struct Unk_7ff3a0 {
    u8 _0[0x8];
    std::array<u64, 2> field_8;
    std::array<std::array<u64, 5>, 2> field_18;
    std::array<std::array<u64, 2>, 2> field_68;

    u64* getField8(u8 side) { return side < 2 ? &field_8[side] : nullptr; }
    // The original compares `index` signed but indexes with it unsigned.
    u64* getField18(u8 side, u32 index) {
        if (side >= 1 || static_cast<s32>(index) >= 5)
            return nullptr;
        return &field_18[side][index];
    }
    u64* getField68(u8 side, u8 index) {
        if (side >= 1 || index >= 2)
            return nullptr;
        return &field_68[side][index];
    }
};
PKMN_OFFSET_ASSERT(Unk_7ff3a0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_7ff3a0, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_7ff3a0, field_68, 0x68);
PKMN_SIZE_ASSERT(Unk_7ff3a0, 0x88);

// The upper bound of each field_8 counter.
extern const std::array<u64, 2> Unk_7ff480_max;

// 0x71007ff410
void Unk_7ff410(Unk_7ff3a0* self, const Unk_7ff3a0* other) {
    self->field_8 = other->field_8;
    self->field_18 = other->field_18;
    self->field_68 = other->field_68;
}

// 0x71007ff460
u64 Unk_7ff460(void* self, u8 side) {
    u64* p = static_cast<Unk_7ff3a0*>(self)->getField8(side);
    return p != nullptr ? *p : 0;
}

// NON_MATCHING: the original keeps the getter's null select (csel) and branches
// on the range check; here the select is folded away.
// 0x71007ff480
void Unk_7ff480(void* self, u8 side) {
    u64* p = static_cast<Unk_7ff3a0*>(self)->getField8(side);
    if (p == nullptr)
        return;
    if (Unk_7ff480_max[side] > *p)
        ++*p;
}

// 0x71007ff4c0
u64 Unk_7ff4c0(void* self, u8 side, u32 index) {
    u64* p = static_cast<Unk_7ff3a0*>(self)->getField18(side, index);
    return p != nullptr ? *p : 0;
}

// 0x71007ff4f0
void Unk_7ff4f0(void* self, u8 side, s32 index) {
    u64* p = static_cast<Unk_7ff3a0*>(self)->getField18(side, index);
    if (p != nullptr && *p < 0xff)
        ++*p;
}

// 0x71007ff540
u64 Unk_7ff540(void* self, u8 side, u8 index) {
    u64* p = static_cast<Unk_7ff3a0*>(self)->getField68(side, index);
    return p != nullptr ? *p : 0;
}

// NON_MATCHING: the checks are scheduled differently.
// 0x71007ff570
void Unk_7ff570(void* self, u8 side, u8 index) {
    u64* p = static_cast<Unk_7ff3a0*>(self)->getField68(side, index);
    if (p != nullptr && *p < 0xff)
        ++*p;
}

// Up to five distinct ids; a free slot holds 5.
struct Unk_7ff630_Ids {
    u32 count;
    u8 ids[5];
};
PKMN_OFFSET_ASSERT(Unk_7ff630_Ids, count, 0x0);
PKMN_OFFSET_ASSERT(Unk_7ff630_Ids, ids, 0x4);
PKMN_SIZE_ASSERT(Unk_7ff630_Ids, 0xc);

// 0x71007ff630
void Unk_7ff630(Unk_7ff630_Ids* self, u8 id) {
    for (int i = 0; i < 5; ++i) {
        if (self->ids[i] == id)
            return;
        if (self->ids[i] == 5) {
            self->ids[i] = id;
            ++self->count;
            return;
        }
    }
}

bool Unk_7cce80(void* self, u8 id, u8 arg);

// NON_MATCHING: the original still tests `anyTrue && anyFalse` (an `and`) after
// the `anyTrue` branch; here that is folded to `anyFalse`.
// 0x71007ff6d0
u32 Unk_7ff6d0(const Unk_7ff630_Ids* self, void* target, u32 arg, u32 kind) {
    if (self->count == 0)
        return 4;
    bool anyTrue = false;
    bool anyFalse = false;
    for (u32 i = 0; i < self->count; ++i) {
        bool result = Unk_7cce80(target, self->ids[i], arg);
        anyFalse |= !result;
        anyTrue |= result;
    }
    if (!anyTrue)
        return 4;
    return anyTrue && anyFalse ? (kind < 2 ? 3 : 2) : 3;
}
