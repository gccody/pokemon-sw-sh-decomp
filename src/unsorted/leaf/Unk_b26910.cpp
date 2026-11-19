// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

struct Unk_b26910 {
    u8 _0[0x8];
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b26910, field_8, 0x8);

// 0x7100b26910
void Unk_b26910_call(Unk_b26910* self) {
    if (self->field_8 != nullptr) {
        static_cast<Unk_239a458*>(self->field_8)->vf5();
        self->field_8 = nullptr;
    }
}

struct Unk_b26950_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b26950_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b26950_arg1, field_8, 0x8);

struct Unk_b26950 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b26950, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b26950, field_8, 0x8);

// 0x7100b26950
void Unk_b26950_call(const Unk_b26950* self, Unk_b26950_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_b26980_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b26980_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b26980_arg1, field_8, 0x8);

struct Unk_b26980 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b26980, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b26980, field_8, 0x8);

// 0x7100b26980
void Unk_b26980_call(const Unk_b26980* self, Unk_b26980_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_b269e0 {
    u8 _0[0x8];
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b269e0, field_8, 0x8);

// 0x7100b269e0
void Unk_b269e0_call(Unk_b269e0* self) {
    if (self->field_8 != nullptr) {
        static_cast<Unk_239a458*>(self->field_8)->vf5();
        self->field_8 = nullptr;
    }
}

struct Unk_b26a20_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b26a20_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b26a20_arg1, field_8, 0x8);

struct Unk_b26a20 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b26a20, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b26a20, field_8, 0x8);

// 0x7100b26a20
void Unk_b26a20_call(const Unk_b26a20* self, Unk_b26a20_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_b26a50_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b26a50_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b26a50_arg1, field_8, 0x8);

struct Unk_b26a50 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b26a50, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b26a50, field_8, 0x8);

// 0x7100b26a50
void Unk_b26a50_call(const Unk_b26a50* self, Unk_b26a50_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_b26b90 {
    u8 _0[0x8];
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b26b90, field_8, 0x8);

// 0x7100b26b90
void Unk_b26b90_call(Unk_b26b90* self) {
    if (self->field_8 != nullptr) {
        static_cast<Unk_239a458*>(self->field_8)->vf5();
        self->field_8 = nullptr;
    }
}

struct Unk_b26bd0_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b26bd0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b26bd0_arg1, field_8, 0x8);

struct Unk_b26bd0 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b26bd0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b26bd0, field_8, 0x8);

// 0x7100b26bd0
void Unk_b26bd0_call(const Unk_b26bd0* self, Unk_b26bd0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_b26c00_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b26c00_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b26c00_arg1, field_8, 0x8);

struct Unk_b26c00 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b26c00, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b26c00, field_8, 0x8);

// 0x7100b26c00
void Unk_b26c00_call(const Unk_b26c00* self, Unk_b26c00_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_b26d20 {
    u8 _0[0x8];
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b26d20, field_8, 0x8);

// 0x7100b26d20
void Unk_b26d20_call(Unk_b26d20* self) {
    if (self->field_8 != nullptr) {
        static_cast<Unk_239a458*>(self->field_8)->vf5();
        self->field_8 = nullptr;
    }
}

struct Unk_b26d60_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b26d60_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b26d60_arg1, field_8, 0x8);

struct Unk_b26d60 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b26d60, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b26d60, field_8, 0x8);

// 0x7100b26d60
void Unk_b26d60_call(const Unk_b26d60* self, Unk_b26d60_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_b26d90_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b26d90_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b26d90_arg1, field_8, 0x8);

struct Unk_b26d90 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b26d90, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b26d90, field_8, 0x8);

// 0x7100b26d90
void Unk_b26d90_call(const Unk_b26d90* self, Unk_b26d90_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}
