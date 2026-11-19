// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

struct Unk_b2acf0 {
    u8 _0[0x8];
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b2acf0, field_8, 0x8);

// 0x7100b2acf0
void Unk_b2acf0_call(Unk_b2acf0* self) {
    if (self->field_8 != nullptr) {
        static_cast<Unk_239a458*>(self->field_8)->vf5();
        self->field_8 = nullptr;
    }
}

struct Unk_b2ad30_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b2ad30_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b2ad30_arg1, field_8, 0x8);

struct Unk_b2ad30 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b2ad30, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b2ad30, field_8, 0x8);

// 0x7100b2ad30
void Unk_b2ad30_call(const Unk_b2ad30* self, Unk_b2ad30_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_b2ad60_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b2ad60_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b2ad60_arg1, field_8, 0x8);

struct Unk_b2ad60 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b2ad60, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b2ad60, field_8, 0x8);

// 0x7100b2ad60
void Unk_b2ad60_call(const Unk_b2ad60* self, Unk_b2ad60_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_b2add0 {
    u8 _0[0x8];
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b2add0, field_8, 0x8);

// 0x7100b2add0
void Unk_b2add0_call(Unk_b2add0* self) {
    if (self->field_8 != nullptr) {
        static_cast<Unk_239a458*>(self->field_8)->vf5();
        self->field_8 = nullptr;
    }
}

struct Unk_b2ae10_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b2ae10_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b2ae10_arg1, field_8, 0x8);

struct Unk_b2ae10 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b2ae10, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b2ae10, field_8, 0x8);

// 0x7100b2ae10
void Unk_b2ae10_call(const Unk_b2ae10* self, Unk_b2ae10_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_b2ae40_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b2ae40_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b2ae40_arg1, field_8, 0x8);

struct Unk_b2ae40 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b2ae40, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b2ae40, field_8, 0x8);

// 0x7100b2ae40
void Unk_b2ae40_call(const Unk_b2ae40* self, Unk_b2ae40_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_b2af00 {
    u8 _0[0x8];
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b2af00, field_8, 0x8);

// 0x7100b2af00
void Unk_b2af00_call(Unk_b2af00* self) {
    if (self->field_8 != nullptr) {
        static_cast<Unk_239a458*>(self->field_8)->vf5();
        self->field_8 = nullptr;
    }
}

struct Unk_b2af40_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b2af40_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b2af40_arg1, field_8, 0x8);

struct Unk_b2af40 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b2af40, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b2af40, field_8, 0x8);

// 0x7100b2af40
void Unk_b2af40_call(const Unk_b2af40* self, Unk_b2af40_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_b2af70_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b2af70_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b2af70_arg1, field_8, 0x8);

struct Unk_b2af70 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b2af70, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b2af70, field_8, 0x8);

// 0x7100b2af70
void Unk_b2af70_call(const Unk_b2af70* self, Unk_b2af70_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_b2afd0 {
    u8 _0[0x8];
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b2afd0, field_8, 0x8);

// 0x7100b2afd0
void Unk_b2afd0_call(Unk_b2afd0* self) {
    if (self->field_8 != nullptr) {
        static_cast<Unk_239a458*>(self->field_8)->vf5();
        self->field_8 = nullptr;
    }
}

struct Unk_b2b010_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b2b010_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b2b010_arg1, field_8, 0x8);

struct Unk_b2b010 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b2b010, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b2b010, field_8, 0x8);

// 0x7100b2b010
void Unk_b2b010_call(const Unk_b2b010* self, Unk_b2b010_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_b2b040_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b2b040_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b2b040_arg1, field_8, 0x8);

struct Unk_b2b040 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b2b040, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b2b040, field_8, 0x8);

// 0x7100b2b040
void Unk_b2b040_call(const Unk_b2b040* self, Unk_b2b040_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}
