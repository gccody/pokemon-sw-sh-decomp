// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

struct Unk_13f86f0 {
    u8 _0[0x470];
    void* field_470;
};
PKMN_OFFSET_ASSERT(Unk_13f86f0, field_470, 0x470);

void Unk_e3e110(void*);

// 0x71013f86f0
void Unk_13f86f0_call(const Unk_13f86f0* self) {
    if (self->field_470 != nullptr) {
        Unk_e3e110(self->field_470);
    }
}

struct Unk_13f9140 {
    u8 _0[0x380];
    u64 field_380;
};
PKMN_OFFSET_ASSERT(Unk_13f9140, field_380, 0x380);

// 0x71013f9140
bool Unk_13f9140_check(const Unk_13f9140* self) {
    return self->field_380 == 0;
}

struct Unk_13fa0a0 {
    u8 _0[0x4b0];
    Unk_239a418* field_4b0;
};
PKMN_OFFSET_ASSERT(Unk_13fa0a0, field_4b0, 0x4b0);

// 0x71013fa0a0
void Unk_13fa0a0_call(Unk_13fa0a0* self) {
    Unk_239a418* v0 = self->field_4b0;
    self->field_4b0 = nullptr;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf5();
    }
}

struct Unk_13fa740 {
    u8 _0[0x460];
    void* field_460;
};
PKMN_OFFSET_ASSERT(Unk_13fa740, field_460, 0x460);

void Unk_13fa750(void*, u64);

// 0x71013fa740
void Unk_13fa740_call(const Unk_13fa740* self,
                      u64 value,
                      u64 /*unused*/,
                      u64 /*unused*/,
                      u64 /*unused*/,
                      u64 /*unused*/) {
    Unk_13fa750(self->field_460, value);
}

struct Unk_13faad0_460 {
    u8 _0[0x6c];
    u8 field_6c;
};
PKMN_OFFSET_ASSERT(Unk_13faad0_460, field_6c, 0x6c);

struct Unk_13faad0 {
    u8 _0[0x460];
    Unk_13faad0_460* field_460;
};
PKMN_OFFSET_ASSERT(Unk_13faad0, field_460, 0x460);

// 0x71013faad0
void Unk_13faad0_set(const Unk_13faad0* self) {
    self->field_460->field_6c = 1;
}

struct Unk_27f046c_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27f046c_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27f046c_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27f046c_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27f046c_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27f046c_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27f046c_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27f046c_Data, field_18, 0x18);

extern Unk_27f046c_Data Unk_27f046c __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x71013fb7b0
void Unk_13fb7b0_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27f046c.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27f046c.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27f046c.field_18 = 0xffff;
    Unk_27f046c.field_10 = 0;
    Unk_27f046c.field_8 = r2;
    Unk_27f046c.field_c = 0;
    Unk_27f046c.field_14 = 0xffffffff;
}
