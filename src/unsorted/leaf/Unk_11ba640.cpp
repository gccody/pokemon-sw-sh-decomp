// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_11ba640 {
    u8 _0[0x138];
    void* field_138;
};
PKMN_OFFSET_ASSERT(Unk_11ba640, field_138, 0x138);

void Unk_11bba20(void*, u64);

// 0x71011ba640
void Unk_11ba640_call(const Unk_11ba640* self, u64 value) {
    Unk_11bba20(self->field_138, value);
}

struct Unk_11ba650 {
    u8 _0[0x138];
    void* field_138;
};
PKMN_OFFSET_ASSERT(Unk_11ba650, field_138, 0x138);

void Unk_11bbe00(void*);

// 0x71011ba650
void Unk_11ba650_call(const Unk_11ba650* self) {
    Unk_11bbe00(self->field_138);
}

// 0x71011bb2e0
void Unk_11bb2e0_update() {}

struct Unk_11bb2f0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_11bb2f0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_11bb2f0, field_8, 0x8);

// 0x71011bb2f0
void Unk_11bb2f0_set(const Unk_11bb2f0* self, Unk_11bb2f0* value) {
    *value = *self;
}

struct Unk_11bb300 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_11bb300, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_11bb300, field_8, 0x8);

// 0x71011bb300
void Unk_11bb300_set(const Unk_11bb300* self, Unk_11bb300* value) {
    *value = *self;
}
