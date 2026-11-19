// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

extern u64 Unk_27d3200 __attribute__((visibility("hidden")));

// 0x7100917ad0
u64 Unk_917ad0_get() {
    return Unk_27d3200;
}

extern u64 Unk_27d3200 __attribute__((visibility("hidden")));
struct Unk_918980 {
    u8 _0[0x61d];
    u8 field_61d;
    u8 _61e[0xa];
    u32 field_628;
    u8 _62c[0x34];
    u64 field_660;
    u8 _668[0x14];
    u8 field_67c;
};
PKMN_OFFSET_ASSERT(Unk_918980, field_61d, 0x61d);
PKMN_OFFSET_ASSERT(Unk_918980, field_628, 0x628);
PKMN_OFFSET_ASSERT(Unk_918980, field_660, 0x660);
PKMN_OFFSET_ASSERT(Unk_918980, field_67c, 0x67c);

void Unk_918f70(void*, u32, u32);
void Unk_919060(void*, u8);

// 0x7100918980
void Unk_918980_call(Unk_918980* self) {
    self->field_628 = 0;
    self->field_67c = 0;
    self->field_61d = 0;
    Unk_918f70(self, 0, 0);
    Unk_919060(self, self->field_61d);
    self->field_660 = Unk_27d3200;
}

void Unk_eb6230(void*, u32);

// 0x7100919180
void Unk_919180_call(void* self) {
    Unk_eb6230(self, 3);
}

// 0x7100919be0
void Unk_919be0_update() {}

struct Unk_919bf0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_919bf0_arg1, field_0, 0x0);

struct Unk_919bf0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_919bf0, field_0, 0x0);

// 0x7100919bf0
void Unk_919bf0_set(const Unk_919bf0* self, Unk_919bf0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_919c00_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_919c00_arg1, field_0, 0x0);

struct Unk_919c00 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_919c00, field_0, 0x0);

// 0x7100919c00
void Unk_919c00_set(const Unk_919c00* self, Unk_919c00_arg1* value) {
    value->field_0 = self->field_0;
}
