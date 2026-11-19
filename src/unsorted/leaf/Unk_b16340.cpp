// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

struct Unk_b16340 {
    u8 _0[0x10];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b16340, field_10, 0x10);

// 0x7100b16340
void Unk_b16340_call(Unk_b16340* self) {
    if (self->field_10 != nullptr) {
        static_cast<Unk_239a458*>(self->field_10)->vf5();
        self->field_10 = nullptr;
    }
}

struct Unk_b16380_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b16380_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b16380_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b16380_arg1, field_10, 0x10);

struct Unk_b16380 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b16380, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b16380, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b16380, field_10, 0x10);

// 0x7100b16380
void Unk_b16380_call(const Unk_b16380* self, Unk_b16380_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b163b0_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b163b0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b163b0_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b163b0_arg1, field_10, 0x10);

struct Unk_b163b0 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b163b0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b163b0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b163b0, field_10, 0x10);

// 0x7100b163b0
void Unk_b163b0_call(const Unk_b163b0* self, Unk_b163b0_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b16450 {
    u8 _0[0x10];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b16450, field_10, 0x10);

// 0x7100b16450
void Unk_b16450_call(Unk_b16450* self) {
    if (self->field_10 != nullptr) {
        static_cast<Unk_239a458*>(self->field_10)->vf5();
        self->field_10 = nullptr;
    }
}

struct Unk_b16490_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b16490_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b16490_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b16490_arg1, field_10, 0x10);

struct Unk_b16490 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b16490, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b16490, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b16490, field_10, 0x10);

// 0x7100b16490
void Unk_b16490_call(const Unk_b16490* self, Unk_b16490_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b164c0_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b164c0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b164c0_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b164c0_arg1, field_10, 0x10);

struct Unk_b164c0 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b164c0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b164c0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b164c0, field_10, 0x10);

// 0x7100b164c0
void Unk_b164c0_call(const Unk_b164c0* self, Unk_b164c0_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b16560 {
    u8 _0[0x20];
    Unk_239a418* field_20;
};
PKMN_OFFSET_ASSERT(Unk_b16560, field_20, 0x20);

// 0x7100b16560
void Unk_b16560_call(Unk_b16560* self) {
    if (self->field_20 != nullptr) {
        static_cast<Unk_239a458*>(self->field_20)->vf5();
        self->field_20 = nullptr;
    }
}

struct Unk_b165a0_head {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_b165a0_head, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b165a0_head, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b165a0_head, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_b165a0_head, field_18, 0x18);

struct Unk_b165a0_arg1 {
    Unk_b165a0_head field_0;
    Unk_239a418* field_20;
};
PKMN_OFFSET_ASSERT(Unk_b165a0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b165a0_arg1, field_20, 0x20);

struct Unk_b165a0 {
    Unk_b165a0_head field_0;
    Unk_239a418* field_20;
};
PKMN_OFFSET_ASSERT(Unk_b165a0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b165a0, field_20, 0x20);

// 0x7100b165a0
void Unk_b165a0_call(const Unk_b165a0* self, Unk_b165a0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_20;
    value->field_20 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_b165d0_head {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_b165d0_head, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b165d0_head, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b165d0_head, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_b165d0_head, field_18, 0x18);

struct Unk_b165d0_arg1 {
    Unk_b165d0_head field_0;
    Unk_239a418* field_20;
};
PKMN_OFFSET_ASSERT(Unk_b165d0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b165d0_arg1, field_20, 0x20);

struct Unk_b165d0 {
    Unk_b165d0_head field_0;
    Unk_239a418* field_20;
};
PKMN_OFFSET_ASSERT(Unk_b165d0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b165d0, field_20, 0x20);

// 0x7100b165d0
void Unk_b165d0_call(const Unk_b165d0* self, Unk_b165d0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_20;
    value->field_20 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_b16630 {
    u8 _0[0x10];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b16630, field_10, 0x10);

// 0x7100b16630
void Unk_b16630_call(Unk_b16630* self) {
    if (self->field_10 != nullptr) {
        static_cast<Unk_239a458*>(self->field_10)->vf5();
        self->field_10 = nullptr;
    }
}

struct Unk_b16670_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b16670_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b16670_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b16670_arg1, field_10, 0x10);

struct Unk_b16670 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b16670, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b16670, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b16670, field_10, 0x10);

// 0x7100b16670
void Unk_b16670_call(const Unk_b16670* self, Unk_b16670_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b166a0_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b166a0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b166a0_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b166a0_arg1, field_10, 0x10);

struct Unk_b166a0 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b166a0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b166a0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b166a0, field_10, 0x10);

// 0x7100b166a0
void Unk_b166a0_call(const Unk_b166a0* self, Unk_b166a0_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b16750 {
    u8 _0[0x18];
    Unk_239a418* field_18;
};
PKMN_OFFSET_ASSERT(Unk_b16750, field_18, 0x18);

// 0x7100b16750
void Unk_b16750_call(Unk_b16750* self) {
    if (self->field_18 != nullptr) {
        static_cast<Unk_239a458*>(self->field_18)->vf5();
        self->field_18 = nullptr;
    }
}

struct Unk_b16790_head {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_b16790_head, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b16790_head, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b16790_head, field_10, 0x10);

struct Unk_b16790_arg1 {
    Unk_b16790_head field_0;
    Unk_239a418* field_18;
};
PKMN_OFFSET_ASSERT(Unk_b16790_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b16790_arg1, field_18, 0x18);

struct Unk_b16790 {
    Unk_b16790_head field_0;
    Unk_239a418* field_18;
};
PKMN_OFFSET_ASSERT(Unk_b16790, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b16790, field_18, 0x18);

// 0x7100b16790
void Unk_b16790_call(const Unk_b16790* self, Unk_b16790_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_18;
    value->field_18 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_b167c0_head {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_b167c0_head, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b167c0_head, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b167c0_head, field_10, 0x10);

struct Unk_b167c0_arg1 {
    Unk_b167c0_head field_0;
    Unk_239a418* field_18;
};
PKMN_OFFSET_ASSERT(Unk_b167c0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b167c0_arg1, field_18, 0x18);

struct Unk_b167c0 {
    Unk_b167c0_head field_0;
    Unk_239a418* field_18;
};
PKMN_OFFSET_ASSERT(Unk_b167c0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b167c0, field_18, 0x18);

// 0x7100b167c0
void Unk_b167c0_call(const Unk_b167c0* self, Unk_b167c0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_18;
    value->field_18 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_b16820 {
    u8 _0[0x10];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b16820, field_10, 0x10);

// 0x7100b16820
void Unk_b16820_call(Unk_b16820* self) {
    if (self->field_10 != nullptr) {
        static_cast<Unk_239a458*>(self->field_10)->vf5();
        self->field_10 = nullptr;
    }
}

struct Unk_b16860_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b16860_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b16860_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b16860_arg1, field_10, 0x10);

struct Unk_b16860 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b16860, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b16860, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b16860, field_10, 0x10);

// 0x7100b16860
void Unk_b16860_call(const Unk_b16860* self, Unk_b16860_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b16890_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b16890_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b16890_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b16890_arg1, field_10, 0x10);

struct Unk_b16890 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b16890, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b16890, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b16890, field_10, 0x10);

// 0x7100b16890
void Unk_b16890_call(const Unk_b16890* self, Unk_b16890_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}
