// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

struct Unk_b28a60 {
    u8 _0[0x10];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b28a60, field_10, 0x10);

// 0x7100b28a60
void Unk_b28a60_call(Unk_b28a60* self) {
    if (self->field_10 != nullptr) {
        static_cast<Unk_239a458*>(self->field_10)->vf5();
        self->field_10 = nullptr;
    }
}

struct Unk_b28aa0_head {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_b28aa0_head, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b28aa0_head, field_8, 0x8);

struct Unk_b28aa0_arg1 {
    Unk_b28aa0_head field_0;
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b28aa0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b28aa0_arg1, field_10, 0x10);

struct Unk_b28aa0 {
    Unk_b28aa0_head field_0;
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b28aa0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b28aa0, field_10, 0x10);

// 0x7100b28aa0
void Unk_b28aa0_call(const Unk_b28aa0* self, Unk_b28aa0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_10;
    value->field_10 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_b28ad0_head {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_b28ad0_head, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b28ad0_head, field_8, 0x8);

struct Unk_b28ad0_arg1 {
    Unk_b28ad0_head field_0;
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b28ad0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b28ad0_arg1, field_10, 0x10);

struct Unk_b28ad0 {
    Unk_b28ad0_head field_0;
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b28ad0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b28ad0, field_10, 0x10);

// 0x7100b28ad0
void Unk_b28ad0_call(const Unk_b28ad0* self, Unk_b28ad0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_10;
    value->field_10 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_b28b30 {
    u8 _0[0x10];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b28b30, field_10, 0x10);

// 0x7100b28b30
void Unk_b28b30_call(Unk_b28b30* self) {
    if (self->field_10 != nullptr) {
        static_cast<Unk_239a458*>(self->field_10)->vf5();
        self->field_10 = nullptr;
    }
}

struct Unk_b28b70_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b28b70_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b28b70_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b28b70_arg1, field_10, 0x10);

struct Unk_b28b70 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b28b70, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b28b70, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b28b70, field_10, 0x10);

// 0x7100b28b70
void Unk_b28b70_call(const Unk_b28b70* self, Unk_b28b70_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b28ba0_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b28ba0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b28ba0_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b28ba0_arg1, field_10, 0x10);

struct Unk_b28ba0 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b28ba0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b28ba0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b28ba0, field_10, 0x10);

// 0x7100b28ba0
void Unk_b28ba0_call(const Unk_b28ba0* self, Unk_b28ba0_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b28e20 {
    u8 _0[0x10];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b28e20, field_10, 0x10);

// 0x7100b28e20
void Unk_b28e20_call(Unk_b28e20* self) {
    if (self->field_10 != nullptr) {
        static_cast<Unk_239a458*>(self->field_10)->vf5();
        self->field_10 = nullptr;
    }
}

struct Unk_b28e60_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b28e60_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b28e60_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b28e60_arg1, field_10, 0x10);

struct Unk_b28e60 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b28e60, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b28e60, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b28e60, field_10, 0x10);

// 0x7100b28e60
void Unk_b28e60_call(const Unk_b28e60* self, Unk_b28e60_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b28e90_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b28e90_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b28e90_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b28e90_arg1, field_10, 0x10);

struct Unk_b28e90 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b28e90, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b28e90, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b28e90, field_10, 0x10);

// 0x7100b28e90
void Unk_b28e90_call(const Unk_b28e90* self, Unk_b28e90_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b28ef0 {
    u8 _0[0x10];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b28ef0, field_10, 0x10);

// 0x7100b28ef0
void Unk_b28ef0_call(Unk_b28ef0* self) {
    if (self->field_10 != nullptr) {
        static_cast<Unk_239a458*>(self->field_10)->vf5();
        self->field_10 = nullptr;
    }
}

struct Unk_b28f30_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b28f30_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b28f30_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b28f30_arg1, field_10, 0x10);

struct Unk_b28f30 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b28f30, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b28f30, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b28f30, field_10, 0x10);

// 0x7100b28f30
void Unk_b28f30_call(const Unk_b28f30* self, Unk_b28f30_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b28f60_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b28f60_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b28f60_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b28f60_arg1, field_10, 0x10);

struct Unk_b28f60 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b28f60, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b28f60, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b28f60, field_10, 0x10);

// 0x7100b28f60
void Unk_b28f60_call(const Unk_b28f60* self, Unk_b28f60_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b290b0 {
    u8 _0[0x10];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b290b0, field_10, 0x10);

// 0x7100b290b0
void Unk_b290b0_call(Unk_b290b0* self) {
    if (self->field_10 != nullptr) {
        static_cast<Unk_239a458*>(self->field_10)->vf5();
        self->field_10 = nullptr;
    }
}

struct Unk_b290f0_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b290f0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b290f0_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b290f0_arg1, field_10, 0x10);

struct Unk_b290f0 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b290f0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b290f0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b290f0, field_10, 0x10);

// 0x7100b290f0
void Unk_b290f0_call(const Unk_b290f0* self, Unk_b290f0_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b29120_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b29120_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b29120_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b29120_arg1, field_10, 0x10);

struct Unk_b29120 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b29120, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b29120, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b29120, field_10, 0x10);

// 0x7100b29120
void Unk_b29120_call(const Unk_b29120* self, Unk_b29120_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b29180 {
    u8 _0[0x10];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b29180, field_10, 0x10);

// 0x7100b29180
void Unk_b29180_call(Unk_b29180* self) {
    if (self->field_10 != nullptr) {
        static_cast<Unk_239a458*>(self->field_10)->vf5();
        self->field_10 = nullptr;
    }
}

struct Unk_b291c0_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b291c0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b291c0_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b291c0_arg1, field_10, 0x10);

struct Unk_b291c0 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b291c0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b291c0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b291c0, field_10, 0x10);

// 0x7100b291c0
void Unk_b291c0_call(const Unk_b291c0* self, Unk_b291c0_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b291f0_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b291f0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b291f0_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b291f0_arg1, field_10, 0x10);

struct Unk_b291f0 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b291f0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b291f0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b291f0, field_10, 0x10);

// 0x7100b291f0
void Unk_b291f0_call(const Unk_b291f0* self, Unk_b291f0_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}
