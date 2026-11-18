// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

extern const u8 Unk_23b4de0[] __attribute__((visibility("hidden")));
struct Unk_87d610 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_87d610, field_0, 0x0);

// 0x710087d610
const u8* Unk_87d610_update(Unk_87d610* self) {
    self->field_0 = 1;
    return Unk_23b4de0;
}

extern const u8 Unk_23b4df0[] __attribute__((visibility("hidden")));
struct Unk_87d630 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_87d630, field_0, 0x0);

// 0x710087d630
const u8* Unk_87d630_update(Unk_87d630* self) {
    self->field_0 = 3;
    return Unk_23b4df0;
}

extern const u8 Unk_23b4e30[] __attribute__((visibility("hidden")));
struct Unk_87d650 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_87d650, field_0, 0x0);

// 0x710087d650
const u8* Unk_87d650_update(Unk_87d650* self) {
    self->field_0 = 1;
    return Unk_23b4e30;
}

extern const u8 Unk_23b4e20[] __attribute__((visibility("hidden")));
struct Unk_87d670 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_87d670, field_0, 0x0);

// 0x710087d670
const u8* Unk_87d670_update(Unk_87d670* self) {
    self->field_0 = 1;
    return Unk_23b4e20;
}

extern const u8 Unk_23b4e40[] __attribute__((visibility("hidden")));
struct Unk_87d690 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_87d690, field_0, 0x0);

// 0x710087d690
const u8* Unk_87d690_update(Unk_87d690* self) {
    self->field_0 = 1;
    return Unk_23b4e40;
}

extern const u8 Unk_23b4e50[] __attribute__((visibility("hidden")));
struct Unk_87d6b0 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_87d6b0, field_0, 0x0);

// 0x710087d6b0
const u8* Unk_87d6b0_update(Unk_87d6b0* self) {
    self->field_0 = 1;
    return Unk_23b4e50;
}

extern const u8 Unk_23b4e60[] __attribute__((visibility("hidden")));
struct Unk_87d6d0 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_87d6d0, field_0, 0x0);

// 0x710087d6d0
const u8* Unk_87d6d0_update(Unk_87d6d0* self) {
    self->field_0 = 2;
    return Unk_23b4e60;
}

extern const u8 Unk_23b4e80[] __attribute__((visibility("hidden")));
struct Unk_87d740 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_87d740, field_0, 0x0);

// 0x710087d740
const u8* Unk_87d740_update(Unk_87d740* self) {
    self->field_0 = 1;
    return Unk_23b4e80;
}

// 0x710087dad0
void Unk_87dad0_update() {}

struct Unk_819640;
void Unk_819640_call(const Unk_819640*, u32, u32);

// 0x710087dae0
void Unk_87dae0_call(const Unk_819640* self) {
    Unk_819640_call(self, 0x51, 1);
}

void Unk_87e280(void*, u32, u32);

// 0x710087dfa0
void Unk_87dfa0_call(void* self) {
    Unk_87e280(self, 0x11, 0x674);
}

void Unk_87e280(void*, u32, u32);

// 0x710087e0f0
void Unk_87e0f0_call(void* self) {
    Unk_87e280(self, 0x10, 0x65c);
}
