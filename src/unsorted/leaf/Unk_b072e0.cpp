// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

struct Unk_b072e0 {
    u8 _0[0x10];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b072e0, field_10, 0x10);

// 0x7100b072e0
void Unk_b072e0_call(Unk_b072e0* self) {
    if (self->field_10 != nullptr) {
        static_cast<Unk_239a458*>(self->field_10)->vf5();
        self->field_10 = nullptr;
    }
}

struct Unk_b073c0 {
    u8 _0[0x10];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b073c0, field_10, 0x10);

// 0x7100b073c0
void Unk_b073c0_call(Unk_b073c0* self) {
    if (self->field_10 != nullptr) {
        static_cast<Unk_239a458*>(self->field_10)->vf5();
        self->field_10 = nullptr;
    }
}

struct Unk_b07590 {
    u8 _0[0x10];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b07590, field_10, 0x10);

// 0x7100b07590
void Unk_b07590_call(Unk_b07590* self) {
    if (self->field_10 != nullptr) {
        static_cast<Unk_239a458*>(self->field_10)->vf5();
        self->field_10 = nullptr;
    }
}

struct Unk_b075d0_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b075d0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b075d0_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b075d0_arg1, field_10, 0x10);

struct Unk_b075d0 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b075d0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b075d0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b075d0, field_10, 0x10);

// 0x7100b075d0
void Unk_b075d0_call(const Unk_b075d0* self, Unk_b075d0_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b07600_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b07600_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b07600_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b07600_arg1, field_10, 0x10);

struct Unk_b07600 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b07600, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b07600, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b07600, field_10, 0x10);

// 0x7100b07600
void Unk_b07600_call(const Unk_b07600* self, Unk_b07600_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b07660 {
    u8 _0[0x10];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b07660, field_10, 0x10);

// 0x7100b07660
void Unk_b07660_call(Unk_b07660* self) {
    if (self->field_10 != nullptr) {
        static_cast<Unk_239a458*>(self->field_10)->vf5();
        self->field_10 = nullptr;
    }
}

struct Unk_b076a0_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b076a0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b076a0_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b076a0_arg1, field_10, 0x10);

struct Unk_b076a0 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b076a0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b076a0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b076a0, field_10, 0x10);

// 0x7100b076a0
void Unk_b076a0_call(const Unk_b076a0* self, Unk_b076a0_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b076d0_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b076d0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b076d0_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b076d0_arg1, field_10, 0x10);

struct Unk_b076d0 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b076d0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b076d0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b076d0, field_10, 0x10);

// 0x7100b076d0
void Unk_b076d0_call(const Unk_b076d0* self, Unk_b076d0_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b07790 {
    u8 _0[0x18];
    Unk_239a418* field_18;
};
PKMN_OFFSET_ASSERT(Unk_b07790, field_18, 0x18);

// 0x7100b07790
void Unk_b07790_call(Unk_b07790* self) {
    if (self->field_18 != nullptr) {
        static_cast<Unk_239a458*>(self->field_18)->vf5();
        self->field_18 = nullptr;
    }
}

struct Unk_b07df0 {
    u8 _0[0x10];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b07df0, field_10, 0x10);

// 0x7100b07df0
void Unk_b07df0_call(Unk_b07df0* self) {
    if (self->field_10 != nullptr) {
        static_cast<Unk_239a458*>(self->field_10)->vf5();
        self->field_10 = nullptr;
    }
}

struct Unk_b07fd0 {
    u8 _0[0x10];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b07fd0, field_10, 0x10);

// 0x7100b07fd0
void Unk_b07fd0_call(Unk_b07fd0* self) {
    if (self->field_10 != nullptr) {
        static_cast<Unk_239a458*>(self->field_10)->vf5();
        self->field_10 = nullptr;
    }
}

struct Unk_b08010_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b08010_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b08010_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b08010_arg1, field_10, 0x10);

struct Unk_b08010 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b08010, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b08010, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b08010, field_10, 0x10);

// 0x7100b08010
void Unk_b08010_call(const Unk_b08010* self, Unk_b08010_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b08040_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b08040_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b08040_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b08040_arg1, field_10, 0x10);

struct Unk_b08040 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b08040, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b08040, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b08040, field_10, 0x10);

// 0x7100b08040
void Unk_b08040_call(const Unk_b08040* self, Unk_b08040_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b080a0 {
    u8 _0[0x10];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b080a0, field_10, 0x10);

// 0x7100b080a0
void Unk_b080a0_call(Unk_b080a0* self) {
    if (self->field_10 != nullptr) {
        static_cast<Unk_239a458*>(self->field_10)->vf5();
        self->field_10 = nullptr;
    }
}

struct Unk_b080e0_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b080e0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b080e0_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b080e0_arg1, field_10, 0x10);

struct Unk_b080e0 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b080e0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b080e0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b080e0, field_10, 0x10);

// 0x7100b080e0
void Unk_b080e0_call(const Unk_b080e0* self, Unk_b080e0_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b08110_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b08110_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b08110_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b08110_arg1, field_10, 0x10);

struct Unk_b08110 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b08110, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b08110, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b08110, field_10, 0x10);

// 0x7100b08110
void Unk_b08110_call(const Unk_b08110* self, Unk_b08110_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b08210 {
    u8 _0[0x10];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b08210, field_10, 0x10);

// 0x7100b08210
void Unk_b08210_call(Unk_b08210* self) {
    if (self->field_10 != nullptr) {
        static_cast<Unk_239a458*>(self->field_10)->vf5();
        self->field_10 = nullptr;
    }
}

struct Unk_b08250_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b08250_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b08250_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b08250_arg1, field_10, 0x10);

struct Unk_b08250 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b08250, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b08250, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b08250, field_10, 0x10);

// 0x7100b08250
void Unk_b08250_call(const Unk_b08250* self, Unk_b08250_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b08280_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b08280_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b08280_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b08280_arg1, field_10, 0x10);

struct Unk_b08280 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b08280, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b08280, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b08280, field_10, 0x10);

// 0x7100b08280
void Unk_b08280_call(const Unk_b08280* self, Unk_b08280_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b082e0 {
    u8 _0[0x10];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b082e0, field_10, 0x10);

// 0x7100b082e0
void Unk_b082e0_call(Unk_b082e0* self) {
    if (self->field_10 != nullptr) {
        static_cast<Unk_239a458*>(self->field_10)->vf5();
        self->field_10 = nullptr;
    }
}

struct Unk_b08320_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b08320_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b08320_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b08320_arg1, field_10, 0x10);

struct Unk_b08320 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b08320, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b08320, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b08320, field_10, 0x10);

// 0x7100b08320
void Unk_b08320_call(const Unk_b08320* self, Unk_b08320_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b08350_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b08350_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b08350_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b08350_arg1, field_10, 0x10);

struct Unk_b08350 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b08350, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b08350, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b08350, field_10, 0x10);

// 0x7100b08350
void Unk_b08350_call(const Unk_b08350* self, Unk_b08350_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b083f0 {
    u8 _0[0x20];
    Unk_239a418* field_20;
};
PKMN_OFFSET_ASSERT(Unk_b083f0, field_20, 0x20);

// 0x7100b083f0
void Unk_b083f0_call(Unk_b083f0* self) {
    if (self->field_20 != nullptr) {
        static_cast<Unk_239a458*>(self->field_20)->vf5();
        self->field_20 = nullptr;
    }
}

struct Unk_b085c0 {
    u8 _0[0x10];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b085c0, field_10, 0x10);

// 0x7100b085c0
void Unk_b085c0_call(Unk_b085c0* self) {
    if (self->field_10 != nullptr) {
        static_cast<Unk_239a458*>(self->field_10)->vf5();
        self->field_10 = nullptr;
    }
}

struct Unk_b08600_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b08600_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b08600_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b08600_arg1, field_10, 0x10);

struct Unk_b08600 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b08600, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b08600, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b08600, field_10, 0x10);

// 0x7100b08600
void Unk_b08600_call(const Unk_b08600* self, Unk_b08600_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b08630_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b08630_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b08630_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b08630_arg1, field_10, 0x10);

struct Unk_b08630 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_b08630, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b08630, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b08630, field_10, 0x10);

// 0x7100b08630
void Unk_b08630_call(const Unk_b08630* self, Unk_b08630_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_b086a0 {
    u8 _0[0x18];
    Unk_239a418* field_18;
};
PKMN_OFFSET_ASSERT(Unk_b086a0, field_18, 0x18);

// 0x7100b086a0
void Unk_b086a0_call(Unk_b086a0* self) {
    if (self->field_18 != nullptr) {
        static_cast<Unk_239a458*>(self->field_18)->vf5();
        self->field_18 = nullptr;
    }
}

struct Unk_b086e0_arg1 {
    u64 field_0;
    u64 field_8;
    u32 field_10;
    u8 _14[0x4];
    Unk_239a418* field_18;
};
PKMN_OFFSET_ASSERT(Unk_b086e0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b086e0_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b086e0_arg1, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_b086e0_arg1, field_18, 0x18);

struct Unk_b086e0 {
    u64 field_0;
    u64 field_8;
    u32 field_10;
    u8 _14[0x4];
    Unk_239a418* field_18;
};
PKMN_OFFSET_ASSERT(Unk_b086e0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b086e0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b086e0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_b086e0, field_18, 0x18);

// 0x7100b086e0
void Unk_b086e0_call(const Unk_b086e0* self, Unk_b086e0_arg1* value) {
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

struct Unk_b08710_arg1 {
    u64 field_0;
    u64 field_8;
    u32 field_10;
    u8 _14[0x4];
    Unk_239a418* field_18;
};
PKMN_OFFSET_ASSERT(Unk_b08710_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b08710_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b08710_arg1, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_b08710_arg1, field_18, 0x18);

struct Unk_b08710 {
    u64 field_0;
    u64 field_8;
    u32 field_10;
    u8 _14[0x4];
    Unk_239a418* field_18;
};
PKMN_OFFSET_ASSERT(Unk_b08710, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_b08710, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_b08710, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_b08710, field_18, 0x18);

// 0x7100b08710
void Unk_b08710_call(const Unk_b08710* self, Unk_b08710_arg1* value) {
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

struct Unk_b087a0 {
    u8 _0[0x18];
    Unk_239a418* field_18;
};
PKMN_OFFSET_ASSERT(Unk_b087a0, field_18, 0x18);

// 0x7100b087a0
void Unk_b087a0_call(Unk_b087a0* self) {
    if (self->field_18 != nullptr) {
        static_cast<Unk_239a458*>(self->field_18)->vf5();
        self->field_18 = nullptr;
    }
}
