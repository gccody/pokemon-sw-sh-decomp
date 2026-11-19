// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

struct Unk_1047a00 {
    u8 _0[0x68];
    u32 field_68;
};
PKMN_OFFSET_ASSERT(Unk_1047a00, field_68, 0x68);

// 0x7101047a00
void Unk_1047a00_clearField68(Unk_1047a00* self) {
    self->field_68 = 0;
}

struct Unk_1047f40 {
    u8 _0[0x8];
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_1047f40, field_8, 0x8);

// 0x7101047f40
void Unk_1047f40_call(Unk_1047f40* self) {
    if (self->field_8 != nullptr) {
        static_cast<Unk_239a458*>(self->field_8)->vf5();
        self->field_8 = nullptr;
    }
}

struct Unk_1047f80_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_1047f80_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1047f80_arg1, field_8, 0x8);

struct Unk_1047f80 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_1047f80, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1047f80, field_8, 0x8);

// 0x7101047f80
void Unk_1047f80_call(const Unk_1047f80* self, Unk_1047f80_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_1047fb0_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_1047fb0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1047fb0_arg1, field_8, 0x8);

struct Unk_1047fb0 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_1047fb0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1047fb0, field_8, 0x8);

// 0x7101047fb0
void Unk_1047fb0_call(const Unk_1047fb0* self, Unk_1047fb0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_1048030 {
    u8 _0[0x8];
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_1048030, field_8, 0x8);

// 0x7101048030
void Unk_1048030_call(Unk_1048030* self) {
    if (self->field_8 != nullptr) {
        static_cast<Unk_239a458*>(self->field_8)->vf5();
        self->field_8 = nullptr;
    }
}

struct Unk_1048070_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_1048070_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1048070_arg1, field_8, 0x8);

struct Unk_1048070 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_1048070, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1048070, field_8, 0x8);

// 0x7101048070
void Unk_1048070_call(const Unk_1048070* self, Unk_1048070_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_10480a0_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_10480a0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_10480a0_arg1, field_8, 0x8);

struct Unk_10480a0 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_10480a0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_10480a0, field_8, 0x8);

// 0x71010480a0
void Unk_10480a0_call(const Unk_10480a0* self, Unk_10480a0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}
