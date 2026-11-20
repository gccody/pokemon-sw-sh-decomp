// Scope: common
// A client's party in battle (0x71007fc210 to 0x71007fc6c0). Placeholder
// names: rename once the class is known.
#include "battle/battle_engine/Unk_7fc210.h"

bool Unk_7ef580(Unk_7ee6b0* self);
u8 Unk_7ee6b0_getField7d(const Unk_7ee6b0* self);
struct Unk_7ef2d0;
u32 Unk_7ef2d0_getField272(const Unk_7ef2d0* self);

// 0x71007fc210
void Unk_7fc210(Unk_7fc430_Party* self, Unk_7ee6b0* poke) {
    self->field_0[self->field_30++] = poke;
}

// 0x71007fc230
void Unk_7fc230(Unk_7fc430_Party* self) {
    u32 i = 0;
    u32 index = 0;
    for (; i < self->field_30; i++) {
        if (Unk_7ef580(self->field_0[index])) {
            index++;
        } else {
            u8 j = index;
            Unk_7ee6b0* poke = self->field_0[j];
            for (; j < self->field_30 - 1; j++)
                self->field_0[j] = self->field_0[j + 1];
            self->field_0[j] = poke;
        }
    }
}

// 0x71007fc2f0
u8 Unk_7fc2f0(const Unk_7fc430_Party* self) {
    u8 count = 0;
    for (u32 i = 0; i < self->field_30; i++)
        count += Unk_7ef580(self->field_0[i]);
    return count;
}

// 0x71007fc350
u8 Unk_7fc350(const Unk_7fc430_Party* self, u8 start) {
    u8 count = 0;
    for (s32 i = start; i < self->field_30; i++)
        count += Unk_7ef580(self->field_0[i]);
    return count;
}

// 0x71007fc3c0
u8 Unk_7fc3c0(const Unk_7fc430_Party* self) {
    u8 alive = Unk_7fc2f0(self);
    if (alive > self->field_30)
        return 0;
    return self->field_30 - alive;
}

// 0x71007fc430
const Unk_7ee6b0* Unk_7fc430(const Unk_7fc430_Party* self, u8 index) {
    if (index < self->field_30)
        return self->field_0[index];
    return nullptr;
}

// 0x71007fc450
Unk_7ee6b0* Unk_7fc450(Unk_7fc430_Party* self, u8 index) {
    if (index < self->field_30)
        return self->field_0[index];
    return nullptr;
}

// 0x71007fc470
void Unk_7fc470(Unk_7fc430_Party* self, u8 index, u8 other) {
    Unk_7ee6b0* poke = self->field_0[index];
    self->field_0[index] = self->field_0[other];
    self->field_0[other] = poke;
}

// 0x71007fc4a0
s32 Unk_7fc4a0(const Unk_7fc430_Party* self, const Unk_7ee6b0* poke) {
    for (s32 i = 0; i < self->field_30; i++) {
        if (self->field_0[i] == poke)
            return i;
    }
    return -1;
}

// 0x71007fc4e0
s32 Unk_7fc4e0(const Unk_7fc430_Party* self, u8 pokeId) {
    for (u32 i = 0; i < self->field_30; i++) {
        if (Unk_7ee6b0_getField7d(self->field_0[i]) == pokeId)
            return i;
    }
    return -1;
}

// 0x71007fc550
u8 Unk_7fc550(const Unk_7fc430_Party* self, u8 pokeId) {
    for (u32 i = 0; i < self->field_30; i++) {
        if (Unk_7ee6b0_getField7d(self->field_0[i]) == pokeId)
            return i;
    }
    return 6;
}

// 0x71007fc5b0
u8 Unk_7fc5b0(Unk_7fc430_Party* self) {
    u8 count = self->field_30;
    if (count != 0) {
        for (u8 i = count - 1; i != 0; i--) {
            if (Unk_7ef580(Unk_7fc450(self, i)))
                return i;
        }
    }
    return 0;
}

// 0x71007fc630
u32 Unk_7fc630(Unk_7fc430_Party* self) {
    u32 total = 0;
    u8 count = self->field_30;
    for (u8 i = 0; i < count; i++)
        total += Unk_7ef2d0_getField272(reinterpret_cast<const Unk_7ef2d0*>(Unk_7fc450(self, i)));
    return total;
}
