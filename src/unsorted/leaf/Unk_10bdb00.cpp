// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

struct Unk_10bdb00_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_10bdb00_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_10bdb00_arg1, field_8, 0x8);

struct Unk_10bdb00 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_10bdb00, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_10bdb00, field_8, 0x8);

// 0x71010bdb00
void Unk_10bdb00_set(Unk_10bdb00* self, Unk_10bdb00_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
    u64 v1 = self->field_8;
    self->field_8 = 0;
    value->field_8 = v1;
}

struct Unk_10bdb30 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10bdb30, field_0, 0x0);

// 0x71010bdb30
void Unk_10bdb30_call(Unk_10bdb30* self) {
    if (self->field_0 != nullptr) {
        static_cast<Unk_239a458*>(self->field_0)->vf5();
        self->field_0 = nullptr;
    }
}

struct Unk_10bdb70_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10bdb70_arg1, field_0, 0x0);

struct Unk_10bdb70 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10bdb70, field_0, 0x0);

// 0x71010bdb70
void Unk_10bdb70_call(const Unk_10bdb70* self, Unk_10bdb70_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_10bdb90_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10bdb90_arg1, field_0, 0x0);

struct Unk_10bdb90 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10bdb90, field_0, 0x0);

// 0x71010bdb90
void Unk_10bdb90_set(Unk_10bdb90* self, Unk_10bdb90_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_10bdc00 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10bdc00, field_0, 0x0);

// 0x71010bdc00
void Unk_10bdc00_call(Unk_10bdc00* self) {
    if (self->field_0 != nullptr) {
        static_cast<Unk_239a458*>(self->field_0)->vf5();
        self->field_0 = nullptr;
    }
}

struct Unk_10bdc40_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10bdc40_arg1, field_0, 0x0);

struct Unk_10bdc40 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10bdc40, field_0, 0x0);

// 0x71010bdc40
void Unk_10bdc40_call(const Unk_10bdc40* self, Unk_10bdc40_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_10bdc60_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10bdc60_arg1, field_0, 0x0);

struct Unk_10bdc60 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10bdc60, field_0, 0x0);

// 0x71010bdc60
void Unk_10bdc60_set(Unk_10bdc60* self, Unk_10bdc60_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_10bf400_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_10bf400_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_10bf400_arg1, field_8, 0x8);

struct Unk_10bf400 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_10bf400, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_10bf400, field_8, 0x8);

// 0x71010bf400
void Unk_10bf400_set(Unk_10bf400* self, Unk_10bf400_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
    u64 v1 = self->field_8;
    self->field_8 = 0;
    value->field_8 = v1;
}

struct Unk_10bf430 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10bf430, field_0, 0x0);

// 0x71010bf430
void Unk_10bf430_call(Unk_10bf430* self) {
    if (self->field_0 != nullptr) {
        static_cast<Unk_239a458*>(self->field_0)->vf5();
        self->field_0 = nullptr;
    }
}

struct Unk_10bf470_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10bf470_arg1, field_0, 0x0);

struct Unk_10bf470 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10bf470, field_0, 0x0);

// 0x71010bf470
void Unk_10bf470_call(const Unk_10bf470* self, Unk_10bf470_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_10bf490_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10bf490_arg1, field_0, 0x0);

struct Unk_10bf490 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10bf490, field_0, 0x0);

// 0x71010bf490
void Unk_10bf490_set(Unk_10bf490* self, Unk_10bf490_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_10bf500 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10bf500, field_0, 0x0);

// 0x71010bf500
void Unk_10bf500_call(Unk_10bf500* self) {
    if (self->field_0 != nullptr) {
        static_cast<Unk_239a458*>(self->field_0)->vf5();
        self->field_0 = nullptr;
    }
}

struct Unk_10bf540_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10bf540_arg1, field_0, 0x0);

struct Unk_10bf540 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10bf540, field_0, 0x0);

// 0x71010bf540
void Unk_10bf540_call(const Unk_10bf540* self, Unk_10bf540_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_10bf560_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10bf560_arg1, field_0, 0x0);

struct Unk_10bf560 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10bf560, field_0, 0x0);

// 0x71010bf560
void Unk_10bf560_set(Unk_10bf560* self, Unk_10bf560_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_10c0b30_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_10c0b30_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_10c0b30_arg1, field_8, 0x8);

struct Unk_10c0b30 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_10c0b30, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_10c0b30, field_8, 0x8);

// 0x71010c0b30
void Unk_10c0b30_set(Unk_10c0b30* self, Unk_10c0b30_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
    u64 v1 = self->field_8;
    self->field_8 = 0;
    value->field_8 = v1;
}

struct Unk_10c0b60 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10c0b60, field_0, 0x0);

// 0x71010c0b60
void Unk_10c0b60_call(Unk_10c0b60* self) {
    if (self->field_0 != nullptr) {
        static_cast<Unk_239a458*>(self->field_0)->vf5();
        self->field_0 = nullptr;
    }
}

struct Unk_10c0ba0_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10c0ba0_arg1, field_0, 0x0);

struct Unk_10c0ba0 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10c0ba0, field_0, 0x0);

// 0x71010c0ba0
void Unk_10c0ba0_call(const Unk_10c0ba0* self, Unk_10c0ba0_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_10c0bc0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10c0bc0_arg1, field_0, 0x0);

struct Unk_10c0bc0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10c0bc0, field_0, 0x0);

// 0x71010c0bc0
void Unk_10c0bc0_set(Unk_10c0bc0* self, Unk_10c0bc0_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_10c0c30 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10c0c30, field_0, 0x0);

// 0x71010c0c30
void Unk_10c0c30_call(Unk_10c0c30* self) {
    if (self->field_0 != nullptr) {
        static_cast<Unk_239a458*>(self->field_0)->vf5();
        self->field_0 = nullptr;
    }
}

struct Unk_10c0c70_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10c0c70_arg1, field_0, 0x0);

struct Unk_10c0c70 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10c0c70, field_0, 0x0);

// 0x71010c0c70
void Unk_10c0c70_call(const Unk_10c0c70* self, Unk_10c0c70_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_10c0c90_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10c0c90_arg1, field_0, 0x0);

struct Unk_10c0c90 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10c0c90, field_0, 0x0);

// 0x71010c0c90
void Unk_10c0c90_set(Unk_10c0c90* self, Unk_10c0c90_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_10c1de0_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_10c1de0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_10c1de0_arg1, field_8, 0x8);

struct Unk_10c1de0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_10c1de0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_10c1de0, field_8, 0x8);

// 0x71010c1de0
void Unk_10c1de0_set(Unk_10c1de0* self, Unk_10c1de0_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
    u64 v1 = self->field_8;
    self->field_8 = 0;
    value->field_8 = v1;
}

struct Unk_10c1e10 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10c1e10, field_0, 0x0);

// 0x71010c1e10
void Unk_10c1e10_call(Unk_10c1e10* self) {
    if (self->field_0 != nullptr) {
        static_cast<Unk_239a458*>(self->field_0)->vf5();
        self->field_0 = nullptr;
    }
}

struct Unk_10c1e50_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10c1e50_arg1, field_0, 0x0);

struct Unk_10c1e50 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10c1e50, field_0, 0x0);

// 0x71010c1e50
void Unk_10c1e50_call(const Unk_10c1e50* self, Unk_10c1e50_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_10c1e70_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10c1e70_arg1, field_0, 0x0);

struct Unk_10c1e70 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10c1e70, field_0, 0x0);

// 0x71010c1e70
void Unk_10c1e70_set(Unk_10c1e70* self, Unk_10c1e70_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_10c1ee0 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10c1ee0, field_0, 0x0);

// 0x71010c1ee0
void Unk_10c1ee0_call(Unk_10c1ee0* self) {
    if (self->field_0 != nullptr) {
        static_cast<Unk_239a458*>(self->field_0)->vf5();
        self->field_0 = nullptr;
    }
}

struct Unk_10c1f20_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10c1f20_arg1, field_0, 0x0);

struct Unk_10c1f20 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10c1f20, field_0, 0x0);

// 0x71010c1f20
void Unk_10c1f20_call(const Unk_10c1f20* self, Unk_10c1f20_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_10c1f40_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10c1f40_arg1, field_0, 0x0);

struct Unk_10c1f40 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10c1f40, field_0, 0x0);

// 0x71010c1f40
void Unk_10c1f40_set(Unk_10c1f40* self, Unk_10c1f40_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}
