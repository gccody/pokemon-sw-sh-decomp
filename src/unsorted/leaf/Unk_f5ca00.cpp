// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

struct Unk_f5ca00 {
    u8 _0[0x8];
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f5ca00, field_8, 0x8);

// 0x7100f5ca00
void Unk_f5ca00_call(Unk_f5ca00* self) {
    if (self->field_8 != nullptr) {
        static_cast<Unk_239a458*>(self->field_8)->vf5();
        self->field_8 = nullptr;
    }
}

struct Unk_f5ca40_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f5ca40_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f5ca40_arg1, field_8, 0x8);

struct Unk_f5ca40 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f5ca40, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f5ca40, field_8, 0x8);

// 0x7100f5ca40
void Unk_f5ca40_call(const Unk_f5ca40* self, Unk_f5ca40_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_f5ca70_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f5ca70_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f5ca70_arg1, field_8, 0x8);

struct Unk_f5ca70 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f5ca70, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f5ca70, field_8, 0x8);

// 0x7100f5ca70
void Unk_f5ca70_call(const Unk_f5ca70* self, Unk_f5ca70_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_f5cad0 {
    u8 _0[0x8];
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f5cad0, field_8, 0x8);

// 0x7100f5cad0
void Unk_f5cad0_call(Unk_f5cad0* self) {
    if (self->field_8 != nullptr) {
        static_cast<Unk_239a458*>(self->field_8)->vf5();
        self->field_8 = nullptr;
    }
}

struct Unk_f5cb10_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f5cb10_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f5cb10_arg1, field_8, 0x8);

struct Unk_f5cb10 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f5cb10, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f5cb10, field_8, 0x8);

// 0x7100f5cb10
void Unk_f5cb10_call(const Unk_f5cb10* self, Unk_f5cb10_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_f5cb40_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f5cb40_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f5cb40_arg1, field_8, 0x8);

struct Unk_f5cb40 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_f5cb40, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f5cb40, field_8, 0x8);

// 0x7100f5cb40
void Unk_f5cb40_call(const Unk_f5cb40* self, Unk_f5cb40_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_27e153c_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27e153c_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27e153c_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27e153c_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27e153c_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27e153c_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27e153c_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27e153c_Data, field_18, 0x18);

extern Unk_27e153c_Data Unk_27e153c __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x7100f5cb70
void Unk_f5cb70_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27e153c.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27e153c.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27e153c.field_18 = 0xffff;
    Unk_27e153c.field_10 = 0;
    Unk_27e153c.field_8 = r2;
    Unk_27e153c.field_c = 0;
    Unk_27e153c.field_14 = 0xffffffff;
}
