// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

struct Unk_10f5bf0 {
    u8 _0[0x60];
    Unk_239a418* field_60;
};
PKMN_OFFSET_ASSERT(Unk_10f5bf0, field_60, 0x60);

// 0x71010f5bf0
void Unk_10f5bf0_call(Unk_10f5bf0* self) {
    Unk_239a418* v0 = self->field_60;
    self->field_60 = nullptr;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf5();
    }
}

struct Unk_10f5c10 {
    u8 _0[0x68];
    Unk_239a418* field_68;
};
PKMN_OFFSET_ASSERT(Unk_10f5c10, field_68, 0x68);

// 0x71010f5c10
void Unk_10f5c10_call(Unk_10f5c10* self) {
    Unk_239a418* v0 = self->field_68;
    self->field_68 = nullptr;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf5();
    }
}

struct Unk_10f5c30 {
    u8 _0[0x70];
    Unk_239a418* field_70;
};
PKMN_OFFSET_ASSERT(Unk_10f5c30, field_70, 0x70);

// 0x71010f5c30
void Unk_10f5c30_call(Unk_10f5c30* self) {
    Unk_239a418* v0 = self->field_70;
    self->field_70 = nullptr;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf5();
    }
}

struct Unk_10f5c50 {
    u8 _0[0x78];
    Unk_239a418* field_78;
};
PKMN_OFFSET_ASSERT(Unk_10f5c50, field_78, 0x78);

// 0x71010f5c50
void Unk_10f5c50_call(Unk_10f5c50* self) {
    Unk_239a418* v0 = self->field_78;
    self->field_78 = nullptr;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf5();
    }
}

struct Unk_27e4f54_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27e4f54_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27e4f54_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27e4f54_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27e4f54_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27e4f54_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27e4f54_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27e4f54_Data, field_18, 0x18);

extern Unk_27e4f54_Data Unk_27e4f54 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x71010f6320
void Unk_10f6320_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27e4f54.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27e4f54.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27e4f54.field_10 = 0xffff;
    Unk_27e4f54.field_8 = r2;
    Unk_27e4f54.field_c = 0xffffffff;
    Unk_27e4f54.field_18 = 0;
    Unk_27e4f54.field_14 = 0;
}
