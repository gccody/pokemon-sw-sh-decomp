// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_11ba640 {
    u8 _0[0x138];
    u64 field_138;
};
PKMN_OFFSET_ASSERT(Unk_11ba640, field_138, 0x138);

void Unk_11bba20(u64);

// 0x71011ba640
void Unk_11ba640_call(const Unk_11ba640* self) {
    Unk_11bba20(self->field_138);
}

struct Unk_11ba650 {
    u8 _0[0x138];
    u64 field_138;
};
PKMN_OFFSET_ASSERT(Unk_11ba650, field_138, 0x138);

void Unk_11bbe00(u64);

// 0x71011ba650
void Unk_11ba650_call(const Unk_11ba650* self) {
    Unk_11bbe00(self->field_138);
}
