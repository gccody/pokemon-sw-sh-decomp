// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

struct Unk_10ed580 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10ed580, field_0, 0x0);

// 0x71010ed580
void Unk_10ed580_call(Unk_10ed580* self) {
    if (self->field_0 != nullptr) {
        static_cast<Unk_239a458*>(self->field_0)->vf5();
        self->field_0 = nullptr;
    }
}

struct Unk_10ed5c0_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10ed5c0_arg1, field_0, 0x0);

struct Unk_10ed5c0 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10ed5c0, field_0, 0x0);

// 0x71010ed5c0
void Unk_10ed5c0_call(const Unk_10ed5c0* self, Unk_10ed5c0_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_10ed5e0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10ed5e0_arg1, field_0, 0x0);

struct Unk_10ed5e0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10ed5e0, field_0, 0x0);

// 0x71010ed5e0
void Unk_10ed5e0_set(Unk_10ed5e0* self, Unk_10ed5e0_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_10ed600 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10ed600, field_0, 0x0);

// 0x71010ed600
void Unk_10ed600_call(Unk_10ed600* self) {
    if (self->field_0 != nullptr) {
        static_cast<Unk_239a458*>(self->field_0)->vf5();
        self->field_0 = nullptr;
    }
}

struct Unk_10ed640_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10ed640_arg1, field_0, 0x0);

struct Unk_10ed640 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10ed640, field_0, 0x0);

// 0x71010ed640
void Unk_10ed640_call(const Unk_10ed640* self, Unk_10ed640_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_10ed660_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10ed660_arg1, field_0, 0x0);

struct Unk_10ed660 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10ed660, field_0, 0x0);

// 0x71010ed660
void Unk_10ed660_set(Unk_10ed660* self, Unk_10ed660_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_10ed6d0 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10ed6d0, field_0, 0x0);

// 0x71010ed6d0
void Unk_10ed6d0_call(Unk_10ed6d0* self) {
    if (self->field_0 != nullptr) {
        static_cast<Unk_239a458*>(self->field_0)->vf5();
        self->field_0 = nullptr;
    }
}

struct Unk_10ed710_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10ed710_arg1, field_0, 0x0);

struct Unk_10ed710 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10ed710, field_0, 0x0);

// 0x71010ed710
void Unk_10ed710_call(const Unk_10ed710* self, Unk_10ed710_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_10ed730_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10ed730_arg1, field_0, 0x0);

struct Unk_10ed730 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10ed730, field_0, 0x0);

// 0x71010ed730
void Unk_10ed730_set(Unk_10ed730* self, Unk_10ed730_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_10f04e0_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_10f04e0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_10f04e0_arg1, field_8, 0x8);

struct Unk_10f04e0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_10f04e0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_10f04e0, field_8, 0x8);

// 0x71010f04e0
void Unk_10f04e0_set(Unk_10f04e0* self, Unk_10f04e0_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
    u64 v1 = self->field_8;
    self->field_8 = 0;
    value->field_8 = v1;
}

struct Unk_10f0540 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10f0540, field_0, 0x0);

// 0x71010f0540
void Unk_10f0540_call(Unk_10f0540* self) {
    if (self->field_0 != nullptr) {
        static_cast<Unk_239a458*>(self->field_0)->vf5();
        self->field_0 = nullptr;
    }
}

struct Unk_10f0580_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10f0580_arg1, field_0, 0x0);

struct Unk_10f0580 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10f0580, field_0, 0x0);

// 0x71010f0580
void Unk_10f0580_call(const Unk_10f0580* self, Unk_10f0580_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_10f05a0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10f05a0_arg1, field_0, 0x0);

struct Unk_10f05a0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10f05a0, field_0, 0x0);

// 0x71010f05a0
void Unk_10f05a0_set(Unk_10f05a0* self, Unk_10f05a0_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_10f0610 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10f0610, field_0, 0x0);

// 0x71010f0610
void Unk_10f0610_call(Unk_10f0610* self) {
    if (self->field_0 != nullptr) {
        static_cast<Unk_239a458*>(self->field_0)->vf5();
        self->field_0 = nullptr;
    }
}

struct Unk_10f0650_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10f0650_arg1, field_0, 0x0);

struct Unk_10f0650 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10f0650, field_0, 0x0);

// 0x71010f0650
void Unk_10f0650_call(const Unk_10f0650* self, Unk_10f0650_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_10f0670_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10f0670_arg1, field_0, 0x0);

struct Unk_10f0670 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10f0670, field_0, 0x0);

// 0x71010f0670
void Unk_10f0670_set(Unk_10f0670* self, Unk_10f0670_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}
