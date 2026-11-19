// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

struct Unk_b18c80 {
    u8 _0[0x8];
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b18c80, field_8, 0x8);

// 0x7100b18c80
void Unk_b18c80_call(Unk_b18c80* self) {
    if (self->field_8 != nullptr) {
        static_cast<Unk_239a458*>(self->field_8)->vf5();
        self->field_8 = nullptr;
    }
}

struct Unk_b18cc0_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b18cc0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b18cc0_arg1, field_8, 0x8);

struct Unk_b18cc0 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b18cc0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b18cc0, field_8, 0x8);

// 0x7100b18cc0
void Unk_b18cc0_call(const Unk_b18cc0* self, Unk_b18cc0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_b18cf0_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b18cf0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b18cf0_arg1, field_8, 0x8);

struct Unk_b18cf0 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b18cf0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b18cf0, field_8, 0x8);

// 0x7100b18cf0
void Unk_b18cf0_call(const Unk_b18cf0* self, Unk_b18cf0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_b18d50 {
    u8 _0[0x8];
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b18d50, field_8, 0x8);

// 0x7100b18d50
void Unk_b18d50_call(Unk_b18d50* self) {
    if (self->field_8 != nullptr) {
        static_cast<Unk_239a458*>(self->field_8)->vf5();
        self->field_8 = nullptr;
    }
}

struct Unk_b18d90_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b18d90_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b18d90_arg1, field_8, 0x8);

struct Unk_b18d90 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b18d90, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b18d90, field_8, 0x8);

// 0x7100b18d90
void Unk_b18d90_call(const Unk_b18d90* self, Unk_b18d90_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_b18dc0_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b18dc0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b18dc0_arg1, field_8, 0x8);

struct Unk_b18dc0 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b18dc0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b18dc0, field_8, 0x8);

// 0x7100b18dc0
void Unk_b18dc0_call(const Unk_b18dc0* self, Unk_b18dc0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_b18e30 {
    u8 _0[0x8];
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b18e30, field_8, 0x8);

// 0x7100b18e30
void Unk_b18e30_call(Unk_b18e30* self) {
    if (self->field_8 != nullptr) {
        static_cast<Unk_239a458*>(self->field_8)->vf5();
        self->field_8 = nullptr;
    }
}

struct Unk_b18e70_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b18e70_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b18e70_arg1, field_8, 0x8);

struct Unk_b18e70 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b18e70, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b18e70, field_8, 0x8);

// 0x7100b18e70
void Unk_b18e70_call(const Unk_b18e70* self, Unk_b18e70_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_b18ea0_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b18ea0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b18ea0_arg1, field_8, 0x8);

struct Unk_b18ea0 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b18ea0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b18ea0, field_8, 0x8);

// 0x7100b18ea0
void Unk_b18ea0_call(const Unk_b18ea0* self, Unk_b18ea0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_b18f00 {
    u8 _0[0x8];
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b18f00, field_8, 0x8);

// 0x7100b18f00
void Unk_b18f00_call(Unk_b18f00* self) {
    if (self->field_8 != nullptr) {
        static_cast<Unk_239a458*>(self->field_8)->vf5();
        self->field_8 = nullptr;
    }
}

struct Unk_b18f40_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b18f40_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b18f40_arg1, field_8, 0x8);

struct Unk_b18f40 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b18f40, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b18f40, field_8, 0x8);

// 0x7100b18f40
void Unk_b18f40_call(const Unk_b18f40* self, Unk_b18f40_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_b18f70_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b18f70_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b18f70_arg1, field_8, 0x8);

struct Unk_b18f70 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b18f70, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b18f70, field_8, 0x8);

// 0x7100b18f70
void Unk_b18f70_call(const Unk_b18f70* self, Unk_b18f70_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_b18fe0 {
    u8 _0[0x8];
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b18fe0, field_8, 0x8);

// 0x7100b18fe0
void Unk_b18fe0_call(Unk_b18fe0* self) {
    if (self->field_8 != nullptr) {
        static_cast<Unk_239a458*>(self->field_8)->vf5();
        self->field_8 = nullptr;
    }
}

struct Unk_b19020_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b19020_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b19020_arg1, field_8, 0x8);

struct Unk_b19020 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b19020, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b19020, field_8, 0x8);

// 0x7100b19020
void Unk_b19020_call(const Unk_b19020* self, Unk_b19020_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_b19050_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b19050_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b19050_arg1, field_8, 0x8);

struct Unk_b19050 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b19050, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b19050, field_8, 0x8);

// 0x7100b19050
void Unk_b19050_call(const Unk_b19050* self, Unk_b19050_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_b190b0 {
    u8 _0[0x8];
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b190b0, field_8, 0x8);

// 0x7100b190b0
void Unk_b190b0_call(Unk_b190b0* self) {
    if (self->field_8 != nullptr) {
        static_cast<Unk_239a458*>(self->field_8)->vf5();
        self->field_8 = nullptr;
    }
}

struct Unk_b190f0_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b190f0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b190f0_arg1, field_8, 0x8);

struct Unk_b190f0 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b190f0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b190f0, field_8, 0x8);

// 0x7100b190f0
void Unk_b190f0_call(const Unk_b190f0* self, Unk_b190f0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_b19120_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b19120_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b19120_arg1, field_8, 0x8);

struct Unk_b19120 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b19120, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b19120, field_8, 0x8);

// 0x7100b19120
void Unk_b19120_call(const Unk_b19120* self, Unk_b19120_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}
