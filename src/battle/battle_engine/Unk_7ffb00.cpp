// Scope: common
// A battle Pokemon's field effect state (Unk_7ee6b0_Field): its counter and
// its ten effect slots, each with a list of up to five ids. Placeholder names:
// rename once the class is known.
#include "battle/battle_engine/Unk_7ff840.h"

struct Unk_7ecc90_Con;
struct Unk_7ee6b0;

u8 Unk_7f88e0(const u64* value);
void Unk_7f8910(u64* value, u8 field);
u8 Unk_7f8960(const u64* value);
bool Unk_7cbf80(void* self, u8 arg1, u8 arg2);
Unk_7ee6b0* Unk_7ed1e0(Unk_7ecc90_Con* self, u8 pokeId);
bool Unk_7f0500(const Unk_7ee6b0* poke, u32 arg);
u8 Unk_7ee6b0_getField7d(const Unk_7ee6b0* self);

namespace {

// The original compares `slot` signed but indexes with it unsigned.
bool isInRange(u32 slot) {
    return static_cast<s32>(slot) < static_cast<s32>(Unk_7ee6b0_Field::kSlots);
}

bool isActive(const Unk_7ee6b0_Field* self, u32 slot) {
    return isInRange(slot) && self->field_180[slot] != 0;
}

bool addId(Unk_7ee6b0_Field* self, u32 slot, u8 id) {
    if (isActive(self, slot)) {
        u32 count = self->field_158[slot];
        if (count < Unk_7ee6b0_Field::kIds) {
            for (u32 i = 0; i < count; i++) {
                if (self->field_90[slot][i] == id)
                    return false;
            }
            self->field_90[slot][count] = id;
            self->field_158[slot] = count + 1;
            return true;
        }
    }
    return false;
}

u32 getTurnsGone(const Unk_7ee6b0_Field* self, u32 slot) {
    if (static_cast<s32>(slot) >= static_cast<s32>(Unk_7ee6b0_Field::kSlots))
        return 0;
    return self->field_68[slot];
}

u32 getTurnsLeft(const Unk_7ee6b0_Field* self, u32 slot) {
    if (!isInRange(slot))
        return 0;
    u32 turns = Unk_7f8960(&self->field_18[slot]);
    u32 gone = self->field_68[slot];
    if (turns != 0 && gone < turns)
        return turns - gone;
    return 0;
}

}  // namespace

// 0x71007ffb00
u32 Unk_7ffb00(const Unk_7ee6b0_Field* self) {
    u32 gone = self->field_c;
    u32 left = 0;
    if (self->field_0) {
        left = self->field_4;
        if (left != 0xff)
            left -= gone;
    }
    return left + gone;
}

// NON_MATCHING: the existing name (_Z10Unk_7ffb80v) has no parameter, but the
// function acts on the counter in x0.
// 0x71007ffb80
bool Unk_7ffb80(Unk_7ee6b0_Field* self) {
    if (!self->field_0)
        return false;
    if (self->field_4 == 0xff)
        return false;
    if (++self->field_c < self->field_4)
        return false;
    self->field_0 = false;
    self->field_10 = 0x1f;
    return true;
}

// 0x71007ffbd0
bool Unk_7ffbd0(void* object, u32 slot, void* value) {
    Unk_7ee6b0_Field* self = static_cast<Unk_7ee6b0_Field*>(object);
    const u64* packed = static_cast<const u64*>(value);
    if (self->field_180[slot] != 0)
        return false;
    self->field_180[slot] = 1;
    self->field_18[slot] = *packed;
    self->field_68[slot] = 0;
    self->field_158[slot] = 0;
    self->field_1a8[slot] = 0;
    for (u32 i = 0; i < Unk_7ee6b0_Field::kIds; i++)
        self->field_90[slot][i] = 0x1f;
    u8 id = Unk_7f88e0(packed);
    if (id != 0x1f)
        addId(self, slot, id);
    return true;
}

// 0x71007ffce0
bool Unk_7ffce0(void* object, u32 slot, u32 id) {
    return addId(static_cast<Unk_7ee6b0_Field*>(object), slot, id);
}

// 0x71007ffd80
bool Unk_7ffd80(Unk_7ee6b0_Field* self, u32 slot) {
    if (!isActive(self, slot))
        return false;
    Unk_7ee6b0_Field_clearSlot(self, slot);
    return true;
}

// 0x71007ffe20
bool Unk_7ffe20(const Unk_7ee6b0_Field* self, u32 effect) {
    return isActive(self, effect);
}

// 0x71007ffe50
bool Unk_7ffe50(void* object, u32 slot, u32 id) {
    Unk_7ee6b0_Field* self = static_cast<Unk_7ee6b0_Field*>(object);
    if (!isActive(self, slot))
        return false;
    u32 count = self->field_158[slot];
    u8 id8 = id;
    bool found = false;
    for (u32 i = 0; i < count; i++) {
        if (self->field_90[slot][i] == id8) {
            found = true;
            break;
        }
    }
    if (!found)
        return false;
    u32 index = 0;
    for (; index < count; index++) {
        if (self->field_90[slot][index] == id8)
            break;
    }
    if (index >= count)
        return false;
    for (u32 i = index; i < Unk_7ee6b0_Field::kIds - 1; i++)
        self->field_90[slot][i] = self->field_90[slot][i + 1];
    self->field_90[slot][Unk_7ee6b0_Field::kIds - 1] = 0x1f;
    if (--self->field_158[slot] == 0) {
        Unk_7ee6b0_Field_clearSlot(self, slot);
        return true;
    }
    if (Unk_7f88e0(&self->field_18[slot]) == id8)
        Unk_7f8910(&self->field_18[slot], self->field_90[slot][0]);
    return false;
}

// 0x7100800000
bool Unk_800000(const Unk_7ee6b0_Field* self,
                void* arg1,
                Unk_7ecc90_Con* con,
                const Unk_7ee6b0* poke,
                u32 arg4) {
    u8 pokeId = Unk_7ee6b0_getField7d(poke);
    u32 count = self->field_158[3];
    for (u64 i = 0; i < count; i++) {
        u32 id = self->field_90[3][i];
        if (Unk_7cbf80(arg1, pokeId, id))
            continue;
        if (Unk_7f0500(Unk_7ed1e0(con, id), arg4))
            return true;
    }
    return false;
}

// 0x71008000b0
bool Unk_8000b0(Unk_7ee6b0_Field* self, u32 slot) {
    if (isActive(self, slot)) {
        u8 turns = Unk_7f8960(&self->field_18[slot]);
        if (turns != 0) {
            if (++self->field_68[slot] >= turns)
                return true;
        }
    }
    return false;
}

// 0x7100800130
bool Unk_800130(void* object, u32 slot, u16 value) {
    const Unk_7ee6b0_Field* self = static_cast<const Unk_7ee6b0_Field*>(object);
    if (isActive(self, slot)) {
        if (self->field_1a8[slot] == value)
            return true;
    }
    return false;
}

// 0x7100800170
u32 Unk_800170(const Unk_7ee6b0_Field* self, u32 slot) {
    return getTurnsLeft(self, slot);
}

// 0x71008001d0
u32 Unk_8001d0(const Unk_7ee6b0_Field* self, u32 slot) {
    return getTurnsGone(self, slot) + getTurnsLeft(self, slot);
}

// 0x7100800240
u32 Unk_800240(const Unk_7ee6b0_Field* self, u32 slot) {
    if (!isActive(self, slot))
        return 0;
    return self->field_158[slot];
}
