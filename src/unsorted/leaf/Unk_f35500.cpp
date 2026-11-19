// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// 0x7100f35500
void Unk_f35500_update() {}

struct Unk_f35510_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f35510_arg1, field_0, 0x0);

struct Unk_f35510 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f35510, field_0, 0x0);

// 0x7100f35510
void Unk_f35510_set(const Unk_f35510* self, Unk_f35510_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f35520_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f35520_arg1, field_0, 0x0);

struct Unk_f35520 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f35520, field_0, 0x0);

// 0x7100f35520
void Unk_f35520_set(const Unk_f35520* self, Unk_f35520_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100f35800
void Unk_f35800_update() {}

struct Unk_f35a70_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f35a70_arg1, field_0, 0x0);

struct Unk_f35a70 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f35a70, field_0, 0x0);

// 0x7100f35a70
void Unk_f35a70_set(const Unk_f35a70* self, Unk_f35a70_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f35a80_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f35a80_arg1, field_0, 0x0);

struct Unk_f35a80 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f35a80, field_0, 0x0);

// 0x7100f35a80
void Unk_f35a80_set(const Unk_f35a80* self, Unk_f35a80_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100f35b30
void Unk_f35b30_update() {}

struct Unk_f35b40_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f35b40_arg1, field_0, 0x0);

struct Unk_f35b40 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f35b40, field_0, 0x0);

// 0x7100f35b40
void Unk_f35b40_set(const Unk_f35b40* self, Unk_f35b40_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f35b50_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f35b50_arg1, field_0, 0x0);

struct Unk_f35b50 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f35b50, field_0, 0x0);

// 0x7100f35b50
void Unk_f35b50_set(const Unk_f35b50* self, Unk_f35b50_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f35c00 {
    u8 _0[0x8];
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f35c00, field_8, 0x8);

// 0x7100f35c00
void Unk_f35c00_call(Unk_f35c00* self) {
    if (self->field_8 != nullptr) {
        static_cast<Unk_239a458*>(self->field_8)->vf5();
        self->field_8 = nullptr;
    }
}

struct Unk_f35c40_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f35c40_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f35c40_arg1, field_8, 0x8);

struct Unk_f35c40 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f35c40, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f35c40, field_8, 0x8);

// 0x7100f35c40
void Unk_f35c40_call(const Unk_f35c40* self, Unk_f35c40_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_f35c70_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f35c70_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f35c70_arg1, field_8, 0x8);

struct Unk_f35c70 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f35c70, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f35c70, field_8, 0x8);

// 0x7100f35c70
void Unk_f35c70_call(const Unk_f35c70* self, Unk_f35c70_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_f35d00 {
    u8 _0[0x8];
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f35d00, field_8, 0x8);

// 0x7100f35d00
void Unk_f35d00_call(Unk_f35d00* self) {
    if (self->field_8 != nullptr) {
        static_cast<Unk_239a458*>(self->field_8)->vf5();
        self->field_8 = nullptr;
    }
}

struct Unk_f35d40_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f35d40_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f35d40_arg1, field_8, 0x8);

struct Unk_f35d40 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f35d40, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f35d40, field_8, 0x8);

// 0x7100f35d40
void Unk_f35d40_call(const Unk_f35d40* self, Unk_f35d40_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_f35d70_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f35d70_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f35d70_arg1, field_8, 0x8);

struct Unk_f35d70 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f35d70, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f35d70, field_8, 0x8);

// 0x7100f35d70
void Unk_f35d70_call(const Unk_f35d70* self, Unk_f35d70_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_27e1154_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27e1154_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27e1154_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27e1154_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27e1154_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27e1154_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27e1154_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27e1154_Data, field_18, 0x18);

extern Unk_27e1154_Data Unk_27e1154 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x7100f35da0
void Unk_f35da0_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27e1154.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27e1154.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27e1154.field_18 = 0xffff;
    Unk_27e1154.field_10 = 0;
    Unk_27e1154.field_8 = r2;
    Unk_27e1154.field_c = 0;
    Unk_27e1154.field_14 = 0xffffffff;
}
