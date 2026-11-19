// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

struct Unk_10d6990_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_10d6990_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_10d6990_arg1, field_8, 0x8);

struct Unk_10d6990 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_10d6990, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_10d6990, field_8, 0x8);

// 0x71010d6990
void Unk_10d6990_set(Unk_10d6990* self, Unk_10d6990_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
    u64 v1 = self->field_8;
    self->field_8 = 0;
    value->field_8 = v1;
}

struct Unk_10d69c0 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10d69c0, field_0, 0x0);

// 0x71010d69c0
void Unk_10d69c0_call(Unk_10d69c0* self) {
    if (self->field_0 != nullptr) {
        static_cast<Unk_239a458*>(self->field_0)->vf5();
        self->field_0 = nullptr;
    }
}

struct Unk_10d6a00_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10d6a00_arg1, field_0, 0x0);

struct Unk_10d6a00 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10d6a00, field_0, 0x0);

// 0x71010d6a00
void Unk_10d6a00_call(const Unk_10d6a00* self, Unk_10d6a00_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_10d6a20_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10d6a20_arg1, field_0, 0x0);

struct Unk_10d6a20 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10d6a20, field_0, 0x0);

// 0x71010d6a20
void Unk_10d6a20_set(Unk_10d6a20* self, Unk_10d6a20_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_10d6a90 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10d6a90, field_0, 0x0);

// 0x71010d6a90
void Unk_10d6a90_call(Unk_10d6a90* self) {
    if (self->field_0 != nullptr) {
        static_cast<Unk_239a458*>(self->field_0)->vf5();
        self->field_0 = nullptr;
    }
}

struct Unk_10d6ad0_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10d6ad0_arg1, field_0, 0x0);

struct Unk_10d6ad0 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10d6ad0, field_0, 0x0);

// 0x71010d6ad0
void Unk_10d6ad0_call(const Unk_10d6ad0* self, Unk_10d6ad0_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_10d6af0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10d6af0_arg1, field_0, 0x0);

struct Unk_10d6af0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10d6af0, field_0, 0x0);

// 0x71010d6af0
void Unk_10d6af0_set(Unk_10d6af0* self, Unk_10d6af0_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_10d98b0_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_10d98b0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_10d98b0_arg1, field_8, 0x8);

struct Unk_10d98b0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_10d98b0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_10d98b0, field_8, 0x8);

// 0x71010d98b0
void Unk_10d98b0_set(Unk_10d98b0* self, Unk_10d98b0_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
    u64 v1 = self->field_8;
    self->field_8 = 0;
    value->field_8 = v1;
}

struct Unk_10d9910 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10d9910, field_0, 0x0);

// 0x71010d9910
void Unk_10d9910_call(Unk_10d9910* self) {
    if (self->field_0 != nullptr) {
        static_cast<Unk_239a458*>(self->field_0)->vf5();
        self->field_0 = nullptr;
    }
}

struct Unk_10d9950_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10d9950_arg1, field_0, 0x0);

struct Unk_10d9950 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10d9950, field_0, 0x0);

// 0x71010d9950
void Unk_10d9950_call(const Unk_10d9950* self, Unk_10d9950_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_10d9970_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10d9970_arg1, field_0, 0x0);

struct Unk_10d9970 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10d9970, field_0, 0x0);

// 0x71010d9970
void Unk_10d9970_set(Unk_10d9970* self, Unk_10d9970_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_10d99e0 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10d99e0, field_0, 0x0);

// 0x71010d99e0
void Unk_10d99e0_call(Unk_10d99e0* self) {
    if (self->field_0 != nullptr) {
        static_cast<Unk_239a458*>(self->field_0)->vf5();
        self->field_0 = nullptr;
    }
}

struct Unk_10d9a20_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10d9a20_arg1, field_0, 0x0);

struct Unk_10d9a20 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10d9a20, field_0, 0x0);

// 0x71010d9a20
void Unk_10d9a20_call(const Unk_10d9a20* self, Unk_10d9a20_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_10d9a40_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10d9a40_arg1, field_0, 0x0);

struct Unk_10d9a40 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10d9a40, field_0, 0x0);

// 0x71010d9a40
void Unk_10d9a40_set(Unk_10d9a40* self, Unk_10d9a40_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_27e4b24_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27e4b24_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27e4b24_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27e4b24_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27e4b24_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27e4b24_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27e4b24_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27e4b24_Data, field_18, 0x18);

extern Unk_27e4b24_Data Unk_27e4b24 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x71010d9a50
void Unk_10d9a50_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27e4b24.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27e4b24.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27e4b24.field_10 = 0xffff;
    Unk_27e4b24.field_8 = r2;
    Unk_27e4b24.field_c = 0xffffffff;
    Unk_27e4b24.field_18 = 0;
    Unk_27e4b24.field_14 = 0;
}
