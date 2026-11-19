// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

struct Unk_b0a340 {
    u8 _0[0x10];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b0a340, field_10, 0x10);

// 0x7100b0a340
void Unk_b0a340_call(Unk_b0a340* self) {
    if (self->field_10 != nullptr) {
        static_cast<Unk_239a458*>(self->field_10)->vf5();
        self->field_10 = nullptr;
    }
}

struct Unk_b0a380_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b0a380_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b0a380_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b0a380_arg1, field_10, 0x10);

struct Unk_b0a380 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b0a380, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b0a380, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b0a380, field_10, 0x10);

// 0x7100b0a380
void Unk_b0a380_call(const Unk_b0a380* self, Unk_b0a380_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b0a3b0_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b0a3b0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b0a3b0_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b0a3b0_arg1, field_10, 0x10);

struct Unk_b0a3b0 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b0a3b0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b0a3b0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b0a3b0, field_10, 0x10);

// 0x7100b0a3b0
void Unk_b0a3b0_call(const Unk_b0a3b0* self, Unk_b0a3b0_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b0a420 {
    u8 _0[0x10];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b0a420, field_10, 0x10);

// 0x7100b0a420
void Unk_b0a420_call(Unk_b0a420* self) {
    if (self->field_10 != nullptr) {
        static_cast<Unk_239a458*>(self->field_10)->vf5();
        self->field_10 = nullptr;
    }
}

struct Unk_b0a460_head {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_b0a460_head, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b0a460_head, field_8, 0x8);

struct Unk_b0a460_arg1 {
    Unk_b0a460_head field_0;
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b0a460_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b0a460_arg1, field_10, 0x10);

struct Unk_b0a460 {
    Unk_b0a460_head field_0;
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b0a460, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b0a460, field_10, 0x10);

// 0x7100b0a460
void Unk_b0a460_call(const Unk_b0a460* self, Unk_b0a460_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_10;
    value->field_10 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_b0a490_head {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_b0a490_head, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b0a490_head, field_8, 0x8);

struct Unk_b0a490_arg1 {
    Unk_b0a490_head field_0;
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b0a490_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b0a490_arg1, field_10, 0x10);

struct Unk_b0a490 {
    Unk_b0a490_head field_0;
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b0a490, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b0a490, field_10, 0x10);

// 0x7100b0a490
void Unk_b0a490_call(const Unk_b0a490* self, Unk_b0a490_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_10;
    value->field_10 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_b0a510 {
    u8 _0[0x18];
    Unk_239a418* field_18;
};
PKMN_OFFSET_ASSERT(Unk_b0a510, field_18, 0x18);

// 0x7100b0a510
void Unk_b0a510_call(Unk_b0a510* self) {
    if (self->field_18 != nullptr) {
        static_cast<Unk_239a458*>(self->field_18)->vf5();
        self->field_18 = nullptr;
    }
}

struct Unk_b0a550_arg1 {
    u64 field_0;
    u64 field_8;
    u32 field_10;
    u8 _14[0x4];
    Unk_239a418* field_18;
};
PKMN_OFFSET_ASSERT(Unk_b0a550_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b0a550_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b0a550_arg1, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_b0a550_arg1, field_18, 0x18);

struct Unk_b0a550 {
    u64 field_0;
    u64 field_8;
    u32 field_10;
    u8 _14[0x4];
    Unk_239a418* field_18;
};
PKMN_OFFSET_ASSERT(Unk_b0a550, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b0a550, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b0a550, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_b0a550, field_18, 0x18);

// 0x7100b0a550
void Unk_b0a550_call(const Unk_b0a550* self, Unk_b0a550_arg1* value) {
    u64 v0 = self->field_0;
    u64 v1 = self->field_8;
    value->field_10 = self->field_10;
    value->field_0 = v0;
    value->field_8 = v1;
    Unk_239a418* v2 = self->field_18;
    value->field_18 = v2;
    if (v2 != nullptr) {
        static_cast<Unk_239a458*>(v2)->vf4();
    }
}

struct Unk_b0a580_arg1 {
    u64 field_0;
    u64 field_8;
    u32 field_10;
    u8 _14[0x4];
    Unk_239a418* field_18;
};
PKMN_OFFSET_ASSERT(Unk_b0a580_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b0a580_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b0a580_arg1, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_b0a580_arg1, field_18, 0x18);

struct Unk_b0a580 {
    u64 field_0;
    u64 field_8;
    u32 field_10;
    u8 _14[0x4];
    Unk_239a418* field_18;
};
PKMN_OFFSET_ASSERT(Unk_b0a580, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b0a580, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b0a580, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_b0a580, field_18, 0x18);

// 0x7100b0a580
void Unk_b0a580_call(const Unk_b0a580* self, Unk_b0a580_arg1* value) {
    u64 v0 = self->field_0;
    u64 v1 = self->field_8;
    value->field_10 = self->field_10;
    value->field_0 = v0;
    value->field_8 = v1;
    Unk_239a418* v2 = self->field_18;
    value->field_18 = v2;
    if (v2 != nullptr) {
        static_cast<Unk_239a458*>(v2)->vf4();
    }
}

struct Unk_b0a5e0 {
    u8 _0[0x10];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b0a5e0, field_10, 0x10);

// 0x7100b0a5e0
void Unk_b0a5e0_call(Unk_b0a5e0* self) {
    if (self->field_10 != nullptr) {
        static_cast<Unk_239a458*>(self->field_10)->vf5();
        self->field_10 = nullptr;
    }
}

struct Unk_b0a620_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b0a620_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b0a620_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b0a620_arg1, field_10, 0x10);

struct Unk_b0a620 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b0a620, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b0a620, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b0a620, field_10, 0x10);

// 0x7100b0a620
void Unk_b0a620_call(const Unk_b0a620* self, Unk_b0a620_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b0a650_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b0a650_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b0a650_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b0a650_arg1, field_10, 0x10);

struct Unk_b0a650 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b0a650, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b0a650, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b0a650, field_10, 0x10);

// 0x7100b0a650
void Unk_b0a650_call(const Unk_b0a650* self, Unk_b0a650_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b0a7a0 {
    u8 _0[0x10];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b0a7a0, field_10, 0x10);

// 0x7100b0a7a0
void Unk_b0a7a0_call(Unk_b0a7a0* self) {
    if (self->field_10 != nullptr) {
        static_cast<Unk_239a458*>(self->field_10)->vf5();
        self->field_10 = nullptr;
    }
}

struct Unk_b0a7e0_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b0a7e0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b0a7e0_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b0a7e0_arg1, field_10, 0x10);

struct Unk_b0a7e0 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b0a7e0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b0a7e0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b0a7e0, field_10, 0x10);

// 0x7100b0a7e0
void Unk_b0a7e0_call(const Unk_b0a7e0* self, Unk_b0a7e0_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b0a810_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b0a810_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b0a810_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b0a810_arg1, field_10, 0x10);

struct Unk_b0a810 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b0a810, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b0a810, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b0a810, field_10, 0x10);

// 0x7100b0a810
void Unk_b0a810_call(const Unk_b0a810* self, Unk_b0a810_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b0a870 {
    u8 _0[0x10];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b0a870, field_10, 0x10);

// 0x7100b0a870
void Unk_b0a870_call(Unk_b0a870* self) {
    if (self->field_10 != nullptr) {
        static_cast<Unk_239a458*>(self->field_10)->vf5();
        self->field_10 = nullptr;
    }
}

struct Unk_b0a8b0_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b0a8b0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b0a8b0_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b0a8b0_arg1, field_10, 0x10);

struct Unk_b0a8b0 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b0a8b0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b0a8b0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b0a8b0, field_10, 0x10);

// 0x7100b0a8b0
void Unk_b0a8b0_call(const Unk_b0a8b0* self, Unk_b0a8b0_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b0a8e0_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b0a8e0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b0a8e0_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b0a8e0_arg1, field_10, 0x10);

struct Unk_b0a8e0 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b0a8e0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b0a8e0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b0a8e0, field_10, 0x10);

// 0x7100b0a8e0
void Unk_b0a8e0_call(const Unk_b0a8e0* self, Unk_b0a8e0_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}
