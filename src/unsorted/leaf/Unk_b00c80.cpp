// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

struct Unk_b00c80 {
    u8 _0[0x8];
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b00c80, field_8, 0x8);

// 0x7100b00c80
void Unk_b00c80_call(Unk_b00c80* self) {
    if (self->field_8 != nullptr) {
        static_cast<Unk_239a458*>(self->field_8)->vf5();
        self->field_8 = nullptr;
    }
}

struct Unk_b00cc0_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b00cc0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b00cc0_arg1, field_8, 0x8);

struct Unk_b00cc0 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b00cc0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b00cc0, field_8, 0x8);

// 0x7100b00cc0
void Unk_b00cc0_call(const Unk_b00cc0* self, Unk_b00cc0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_b00cf0_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b00cf0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b00cf0_arg1, field_8, 0x8);

struct Unk_b00cf0 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b00cf0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b00cf0, field_8, 0x8);

// 0x7100b00cf0
void Unk_b00cf0_call(const Unk_b00cf0* self, Unk_b00cf0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_b00d50 {
    u8 _0[0x8];
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b00d50, field_8, 0x8);

// 0x7100b00d50
void Unk_b00d50_call(Unk_b00d50* self) {
    if (self->field_8 != nullptr) {
        static_cast<Unk_239a458*>(self->field_8)->vf5();
        self->field_8 = nullptr;
    }
}

struct Unk_b00d90_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b00d90_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b00d90_arg1, field_8, 0x8);

struct Unk_b00d90 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b00d90, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b00d90, field_8, 0x8);

// 0x7100b00d90
void Unk_b00d90_call(const Unk_b00d90* self, Unk_b00d90_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_b00dc0_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b00dc0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b00dc0_arg1, field_8, 0x8);

struct Unk_b00dc0 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b00dc0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b00dc0, field_8, 0x8);

// 0x7100b00dc0
void Unk_b00dc0_call(const Unk_b00dc0* self, Unk_b00dc0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_b00e20 {
    u8 _0[0x8];
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b00e20, field_8, 0x8);

// 0x7100b00e20
void Unk_b00e20_call(Unk_b00e20* self) {
    if (self->field_8 != nullptr) {
        static_cast<Unk_239a458*>(self->field_8)->vf5();
        self->field_8 = nullptr;
    }
}

struct Unk_b00e60_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b00e60_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b00e60_arg1, field_8, 0x8);

struct Unk_b00e60 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b00e60, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b00e60, field_8, 0x8);

// 0x7100b00e60
void Unk_b00e60_call(const Unk_b00e60* self, Unk_b00e60_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_b00e90_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b00e90_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b00e90_arg1, field_8, 0x8);

struct Unk_b00e90 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b00e90, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b00e90, field_8, 0x8);

// 0x7100b00e90
void Unk_b00e90_call(const Unk_b00e90* self, Unk_b00e90_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_b00ef0 {
    u8 _0[0x8];
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b00ef0, field_8, 0x8);

// 0x7100b00ef0
void Unk_b00ef0_call(Unk_b00ef0* self) {
    if (self->field_8 != nullptr) {
        static_cast<Unk_239a458*>(self->field_8)->vf5();
        self->field_8 = nullptr;
    }
}

struct Unk_b00f30_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b00f30_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b00f30_arg1, field_8, 0x8);

struct Unk_b00f30 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b00f30, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b00f30, field_8, 0x8);

// 0x7100b00f30
void Unk_b00f30_call(const Unk_b00f30* self, Unk_b00f30_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_b00f60_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b00f60_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b00f60_arg1, field_8, 0x8);

struct Unk_b00f60 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b00f60, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b00f60, field_8, 0x8);

// 0x7100b00f60
void Unk_b00f60_call(const Unk_b00f60* self, Unk_b00f60_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_b011c0 {
    u8 _0[0x10];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b011c0, field_10, 0x10);

// 0x7100b011c0
void Unk_b011c0_call(Unk_b011c0* self) {
    if (self->field_10 != nullptr) {
        static_cast<Unk_239a458*>(self->field_10)->vf5();
        self->field_10 = nullptr;
    }
}

struct Unk_b01200_head {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_b01200_head, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b01200_head, field_8, 0x8);

struct Unk_b01200_arg1 {
    Unk_b01200_head field_0;
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b01200_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b01200_arg1, field_10, 0x10);

struct Unk_b01200 {
    Unk_b01200_head field_0;
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b01200, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b01200, field_10, 0x10);

// 0x7100b01200
void Unk_b01200_call(const Unk_b01200* self, Unk_b01200_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_10;
    value->field_10 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_b01230_head {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_b01230_head, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b01230_head, field_8, 0x8);

struct Unk_b01230_arg1 {
    Unk_b01230_head field_0;
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b01230_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b01230_arg1, field_10, 0x10);

struct Unk_b01230 {
    Unk_b01230_head field_0;
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b01230, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b01230, field_10, 0x10);

// 0x7100b01230
void Unk_b01230_call(const Unk_b01230* self, Unk_b01230_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_10;
    value->field_10 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_b01290 {
    u8 _0[0x10];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b01290, field_10, 0x10);

// 0x7100b01290
void Unk_b01290_call(Unk_b01290* self) {
    if (self->field_10 != nullptr) {
        static_cast<Unk_239a458*>(self->field_10)->vf5();
        self->field_10 = nullptr;
    }
}

struct Unk_b012d0_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b012d0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b012d0_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b012d0_arg1, field_10, 0x10);

struct Unk_b012d0 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b012d0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b012d0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b012d0, field_10, 0x10);

// 0x7100b012d0
void Unk_b012d0_call(const Unk_b012d0* self, Unk_b012d0_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b01300_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b01300_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b01300_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b01300_arg1, field_10, 0x10);

struct Unk_b01300 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b01300, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b01300, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b01300, field_10, 0x10);

// 0x7100b01300
void Unk_b01300_call(const Unk_b01300* self, Unk_b01300_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b01370 {
    u8 _0[0x10];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b01370, field_10, 0x10);

// 0x7100b01370
void Unk_b01370_call(Unk_b01370* self) {
    if (self->field_10 != nullptr) {
        static_cast<Unk_239a458*>(self->field_10)->vf5();
        self->field_10 = nullptr;
    }
}

struct Unk_b013b0_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b013b0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b013b0_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b013b0_arg1, field_10, 0x10);

struct Unk_b013b0 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b013b0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b013b0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b013b0, field_10, 0x10);

// 0x7100b013b0
void Unk_b013b0_call(const Unk_b013b0* self, Unk_b013b0_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b013e0_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b013e0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b013e0_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b013e0_arg1, field_10, 0x10);

struct Unk_b013e0 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b013e0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b013e0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b013e0, field_10, 0x10);

// 0x7100b013e0
void Unk_b013e0_call(const Unk_b013e0* self, Unk_b013e0_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b01440 {
    u8 _0[0x10];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b01440, field_10, 0x10);

// 0x7100b01440
void Unk_b01440_call(Unk_b01440* self) {
    if (self->field_10 != nullptr) {
        static_cast<Unk_239a458*>(self->field_10)->vf5();
        self->field_10 = nullptr;
    }
}

struct Unk_b01480_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b01480_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b01480_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b01480_arg1, field_10, 0x10);

struct Unk_b01480 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b01480, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b01480, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b01480, field_10, 0x10);

// 0x7100b01480
void Unk_b01480_call(const Unk_b01480* self, Unk_b01480_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b014b0_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b014b0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b014b0_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b014b0_arg1, field_10, 0x10);

struct Unk_b014b0 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b014b0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b014b0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b014b0, field_10, 0x10);

// 0x7100b014b0
void Unk_b014b0_call(const Unk_b014b0* self, Unk_b014b0_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b01500 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_b01500, field_0, 0x0);

// 0x7100b01500
void Unk_b01500_call(Unk_b01500* self) {
    if (self->field_0 != nullptr) {
        static_cast<Unk_239a458*>(self->field_0)->vf5();
        self->field_0 = nullptr;
    }
}

struct Unk_b01540_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_b01540_arg1, field_0, 0x0);

struct Unk_b01540 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_b01540, field_0, 0x0);

// 0x7100b01540
void Unk_b01540_call(const Unk_b01540* self, Unk_b01540_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_b01560_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_b01560_arg1, field_0, 0x0);

struct Unk_b01560 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_b01560, field_0, 0x0);

// 0x7100b01560
void Unk_b01560_call(const Unk_b01560* self, Unk_b01560_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_b015b0 {
    u8 _0[0x10];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b015b0, field_10, 0x10);

// 0x7100b015b0
void Unk_b015b0_call(Unk_b015b0* self) {
    if (self->field_10 != nullptr) {
        static_cast<Unk_239a458*>(self->field_10)->vf5();
        self->field_10 = nullptr;
    }
}

struct Unk_b015f0_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b015f0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b015f0_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b015f0_arg1, field_10, 0x10);

struct Unk_b015f0 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b015f0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b015f0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b015f0, field_10, 0x10);

// 0x7100b015f0
void Unk_b015f0_call(const Unk_b015f0* self, Unk_b015f0_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b01620_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b01620_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b01620_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b01620_arg1, field_10, 0x10);

struct Unk_b01620 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b01620, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b01620, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b01620, field_10, 0x10);

// 0x7100b01620
void Unk_b01620_call(const Unk_b01620* self, Unk_b01620_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b016a0 {
    u8 _0[0x10];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b016a0, field_10, 0x10);

// 0x7100b016a0
void Unk_b016a0_call(Unk_b016a0* self) {
    if (self->field_10 != nullptr) {
        static_cast<Unk_239a458*>(self->field_10)->vf5();
        self->field_10 = nullptr;
    }
}

struct Unk_b016e0_head {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_b016e0_head, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b016e0_head, field_8, 0x8);

struct Unk_b016e0_arg1 {
    Unk_b016e0_head field_0;
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b016e0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b016e0_arg1, field_10, 0x10);

struct Unk_b016e0 {
    Unk_b016e0_head field_0;
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b016e0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b016e0, field_10, 0x10);

// 0x7100b016e0
void Unk_b016e0_call(const Unk_b016e0* self, Unk_b016e0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_10;
    value->field_10 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_b01710_head {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_b01710_head, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b01710_head, field_8, 0x8);

struct Unk_b01710_arg1 {
    Unk_b01710_head field_0;
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b01710_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b01710_arg1, field_10, 0x10);

struct Unk_b01710 {
    Unk_b01710_head field_0;
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b01710, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b01710, field_10, 0x10);

// 0x7100b01710
void Unk_b01710_call(const Unk_b01710* self, Unk_b01710_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_10;
    value->field_10 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_b01770 {
    u8 _0[0x10];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b01770, field_10, 0x10);

// 0x7100b01770
void Unk_b01770_call(Unk_b01770* self) {
    if (self->field_10 != nullptr) {
        static_cast<Unk_239a458*>(self->field_10)->vf5();
        self->field_10 = nullptr;
    }
}

struct Unk_b017b0_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b017b0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b017b0_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b017b0_arg1, field_10, 0x10);

struct Unk_b017b0 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b017b0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b017b0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b017b0, field_10, 0x10);

// 0x7100b017b0
void Unk_b017b0_call(const Unk_b017b0* self, Unk_b017b0_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b017e0_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b017e0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b017e0_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b017e0_arg1, field_10, 0x10);

struct Unk_b017e0 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b017e0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b017e0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b017e0, field_10, 0x10);

// 0x7100b017e0
void Unk_b017e0_call(const Unk_b017e0* self, Unk_b017e0_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b01840 {
    u8 _0[0x10];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b01840, field_10, 0x10);

// 0x7100b01840
void Unk_b01840_call(Unk_b01840* self) {
    if (self->field_10 != nullptr) {
        static_cast<Unk_239a458*>(self->field_10)->vf5();
        self->field_10 = nullptr;
    }
}

struct Unk_b01880_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b01880_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b01880_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b01880_arg1, field_10, 0x10);

struct Unk_b01880 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b01880, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b01880, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b01880, field_10, 0x10);

// 0x7100b01880
void Unk_b01880_call(const Unk_b01880* self, Unk_b01880_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b018b0_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b018b0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b018b0_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b018b0_arg1, field_10, 0x10);

struct Unk_b018b0 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b018b0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b018b0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b018b0, field_10, 0x10);

// 0x7100b018b0
void Unk_b018b0_call(const Unk_b018b0* self, Unk_b018b0_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b01910 {
    u8 _0[0x10];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b01910, field_10, 0x10);

// 0x7100b01910
void Unk_b01910_call(Unk_b01910* self) {
    if (self->field_10 != nullptr) {
        static_cast<Unk_239a458*>(self->field_10)->vf5();
        self->field_10 = nullptr;
    }
}

struct Unk_b01950_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b01950_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b01950_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b01950_arg1, field_10, 0x10);

struct Unk_b01950 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b01950, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b01950, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b01950, field_10, 0x10);

// 0x7100b01950
void Unk_b01950_call(const Unk_b01950* self, Unk_b01950_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b01980_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b01980_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b01980_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b01980_arg1, field_10, 0x10);

struct Unk_b01980 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b01980, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b01980, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b01980, field_10, 0x10);

// 0x7100b01980
void Unk_b01980_call(const Unk_b01980* self, Unk_b01980_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}
