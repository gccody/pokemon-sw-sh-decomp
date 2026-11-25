// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

extern u64 Unk_24ba638;
void Unk_c44310(u64, u32);

// 0x7100e7c1a0
void Unk_e7c1a0_call() {
    Unk_c44310(Unk_24ba638, 0);
}

struct Unk_e7c1c0 {
    u8 _0[0x540];
    u32 field_540;
};
PKMN_OFFSET_ASSERT(Unk_e7c1c0, field_540, 0x540);

// 0x7100e7c1c0
bool Unk_e7c1c0_check(const Unk_e7c1c0* self) {
    return self->field_540 == 0;
}

struct Unk_e7c1d0 {
    u8 _0[0x540];
    u32 field_540;
};
PKMN_OFFSET_ASSERT(Unk_e7c1d0, field_540, 0x540);

// 0x7100e7c1d0
bool Unk_e7c1d0_check(const Unk_e7c1d0* self) {
    return self->field_540 >= 1 && self->field_540 <= 2;
}

struct Unk_e7c1f0 {
    u8 _0[0x540];
    u32 field_540;
};
PKMN_OFFSET_ASSERT(Unk_e7c1f0, field_540, 0x540);

// 0x7100e7c1f0
bool Unk_e7c1f0_check(const Unk_e7c1f0* self) {
    return self->field_540 >= 3 && self->field_540 <= 4;
}

struct Unk_e7f7b0_8_60 {
    u8 _0[0xb0];
    u64 field_b0;
};
PKMN_OFFSET_ASSERT(Unk_e7f7b0_8_60, field_b0, 0xb0);

struct Unk_e7f7b0_8 {
    u8 _0[0x60];
    Unk_e7f7b0_8_60* field_60;
};
PKMN_OFFSET_ASSERT(Unk_e7f7b0_8, field_60, 0x60);

struct Unk_e7f7b0 {
    u8 _0[0x8];
    Unk_e7f7b0_8* field_8;
};
PKMN_OFFSET_ASSERT(Unk_e7f7b0, field_8, 0x8);

// 0x7100e7f7b0
u64 Unk_e7f7b0_get(const Unk_e7f7b0* self) {
    return self->field_8->field_60->field_b0;
}

struct Unk_e7f7c0_60 {
    u8 _0[0xb0];
    u64 field_b0;
};
PKMN_OFFSET_ASSERT(Unk_e7f7c0_60, field_b0, 0xb0);

struct Unk_e7f7c0 {
    u8 _0[0x60];
    Unk_e7f7c0_60* field_60;
};
PKMN_OFFSET_ASSERT(Unk_e7f7c0, field_60, 0x60);

// 0x7100e7f7c0
u64 Unk_e7f7c0_get(const Unk_e7f7c0* self) {
    return self->field_60->field_b0;
}

struct Unk_e7f7d0_8_60 {
    u8 _0[0xb0];
    u64 field_b0;
};
PKMN_OFFSET_ASSERT(Unk_e7f7d0_8_60, field_b0, 0xb0);

struct Unk_e7f7d0_8 {
    u8 _0[0x60];
    Unk_e7f7d0_8_60* field_60;
};
PKMN_OFFSET_ASSERT(Unk_e7f7d0_8, field_60, 0x60);

struct Unk_e7f7d0 {
    u8 _0[0x8];
    Unk_e7f7d0_8* field_8;
};
PKMN_OFFSET_ASSERT(Unk_e7f7d0, field_8, 0x8);

// 0x7100e7f7d0
u64 Unk_e7f7d0_get(const Unk_e7f7d0* self) {
    return self->field_8->field_60->field_b0;
}

struct Unk_e7f7e0_60 {
    u8 _0[0xb0];
    u64 field_b0;
};
PKMN_OFFSET_ASSERT(Unk_e7f7e0_60, field_b0, 0xb0);

struct Unk_e7f7e0 {
    u8 _0[0x60];
    Unk_e7f7e0_60* field_60;
};
PKMN_OFFSET_ASSERT(Unk_e7f7e0, field_60, 0x60);

// 0x7100e7f7e0
u64 Unk_e7f7e0_get(const Unk_e7f7e0* self) {
    return self->field_60->field_b0;
}

struct Unk_e806a0 {
    u8 _0[0x5a0];
    u64 field_5a0;
};
PKMN_OFFSET_ASSERT(Unk_e806a0, field_5a0, 0x5a0);

// 0x7100e806a0
u64 Unk_e806a0_getField5a0(const Unk_e806a0* self) {
    return self->field_5a0;
}

struct Unk_e807f0 {
    u8 _0[0x60];
    void* field_60;
};
PKMN_OFFSET_ASSERT(Unk_e807f0, field_60, 0x60);

void Unk_e7f120(void*, void*, u32);

// 0x7100e807f0
void Unk_e807f0_call(Unk_e807f0* self, bool value) {
    Unk_e7f120(self->field_60, self, value);
}

struct Unk_e809c0 {
    u8 _0[0x5a0];
    void* field_5a0;
};
PKMN_OFFSET_ASSERT(Unk_e809c0, field_5a0, 0x5a0);

void Unk_e809d0(void*, void*);

// 0x7100e809c0
void Unk_e809c0_call(const Unk_e809c0* self, void* value) {
    Unk_e809d0(self->field_5a0, value);
}

extern const u8 Unk_1f26328[] __attribute__((visibility("hidden")));

// 0x7100e81230
const u8* Unk_e81230_get() {
    return Unk_1f26328;
}

struct Unk_e831e0 {
    u8 _0[0x18];
    void* field_18;
    u8 _20[0x190];
    void* field_1b0;
};
PKMN_OFFSET_ASSERT(Unk_e831e0, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_e831e0, field_1b0, 0x1b0);

void Unk_14abd30(void*, void*);

// 0x7100e831e0
void Unk_e831e0_call(const Unk_e831e0* self) {
    if (self->field_1b0 != nullptr) {
        Unk_14abd30(self->field_1b0, self->field_18);
    }
}

struct Unk_e83370_3c0 {
    u8 _0[0x60];
    u8 field_60;
};
PKMN_OFFSET_ASSERT(Unk_e83370_3c0, field_60, 0x60);

struct Unk_e83370 {
    u8 _0[0x3c0];
    Unk_e83370_3c0* field_3c0;
};
PKMN_OFFSET_ASSERT(Unk_e83370, field_3c0, 0x3c0);

// 0x7100e83370
bool Unk_e83370_check(const Unk_e83370* self) {
    if (self->field_3c0 == nullptr) {
        return false;
    }
    return self->field_3c0->field_60 != 0;
}

struct Unk_14ac420;
struct Unk_e83390 {
    u8 _0[0x1b0];
    Unk_14ac420* field_1b0;
};
PKMN_OFFSET_ASSERT(Unk_e83390, field_1b0, 0x1b0);

u8 Unk_14ac420_getField2fc(const Unk_14ac420*);

// 0x7100e83390
void Unk_e83390_call(const Unk_e83390* self) {
    if (self->field_1b0 != nullptr) {
        Unk_14ac420_getField2fc(self->field_1b0);
    }
}

struct Unk_e83430 {
    u8 _0[0x1b0];
    u64 field_1b0;
};
PKMN_OFFSET_ASSERT(Unk_e83430, field_1b0, 0x1b0);

void Unk_14ab0c0(u64, u64);

// 0x7100e83430
u32 Unk_e83430_call(const Unk_e83430* self, void* key) {
    if (self->field_1b0 == 0) {
        return 0;
    }
    Unk_14ab0c0(self->field_1b0, reinterpret_cast<u64>(key));
    return 1;
}

struct Unk_e83850 {
    u8 _0[0x1b0];
    u64 field_1b0;
};
PKMN_OFFSET_ASSERT(Unk_e83850, field_1b0, 0x1b0);

void Unk_14ab200(u64, u64);

// 0x7100e83850
u32 Unk_e83850_call(const Unk_e83850* self, void* key) {
    if (self->field_1b0 == 0) {
        return 0;
    }
    Unk_14ab200(self->field_1b0, reinterpret_cast<u64>(key));
    return 1;
}

struct Unk_e83b20 {
    u8 _0[0x1b0];
    void* field_1b0;
};
PKMN_OFFSET_ASSERT(Unk_e83b20, field_1b0, 0x1b0);

void Unk_14abe00(void*, void*, void*, u32);

// 0x7100e83b20
void Unk_e83b20_call(const Unk_e83b20* self, void* value, void* arg2, u32 arg3) {
    Unk_14abe00(self->field_1b0, value, arg2, arg3);
}

// 0x7100e857b0
void Unk_e857b0_update() {}

struct Unk_e857c0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_e857c0_arg1, field_0, 0x0);

struct Unk_e857c0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_e857c0, field_0, 0x0);

// 0x7100e857c0
void Unk_e857c0_set(const Unk_e857c0* self, Unk_e857c0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_e857d0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_e857d0_arg1, field_0, 0x0);

struct Unk_e857d0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_e857d0, field_0, 0x0);

// 0x7100e857d0
void Unk_e857d0_set(const Unk_e857d0* self, Unk_e857d0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100e86680
void Unk_e86680_update() {}

struct Unk_e86690 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_e86690, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_e86690, field_8, 0x8);

// 0x7100e86690
void Unk_e86690_set(const Unk_e86690* self, Unk_e86690* value) {
    *value = *self;
}

struct Unk_e866a0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_e866a0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_e866a0, field_8, 0x8);

// 0x7100e866a0
void Unk_e866a0_set(const Unk_e866a0* self, Unk_e866a0* value) {
    *value = *self;
}

// 0x7100e866c0
void Unk_e866c0_update() {}

struct Unk_e866d0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_e866d0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_e866d0, field_8, 0x8);

// 0x7100e866d0
void Unk_e866d0_set(const Unk_e866d0* self, Unk_e866d0* value) {
    *value = *self;
}

struct Unk_e866e0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_e866e0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_e866e0, field_8, 0x8);

// 0x7100e866e0
void Unk_e866e0_set(const Unk_e866e0* self, Unk_e866e0* value) {
    *value = *self;
}

// 0x7100e86750
void Unk_e86750_update() {}

struct Unk_e86760 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_e86760, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_e86760, field_8, 0x8);

// 0x7100e86760
void Unk_e86760_set(const Unk_e86760* self, Unk_e86760* value) {
    *value = *self;
}

struct Unk_e86770 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_e86770, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_e86770, field_8, 0x8);

// 0x7100e86770
void Unk_e86770_set(const Unk_e86770* self, Unk_e86770* value) {
    *value = *self;
}

// 0x7100e87c40
void Unk_e87c40() {}

struct Unk_e87f00 {
    u8 _0[0x58];
    void* field_58;
};
PKMN_OFFSET_ASSERT(Unk_e87f00, field_58, 0x58);

void Unk_5e26a0(void*);

// 0x7100e87f00
void Unk_e87f00_call(const Unk_e87f00* self) {
    if (self->field_58 != nullptr) {
        Unk_5e26a0(self->field_58);
    }
}

// 0x7100e88350
void Unk_e88350() {}

struct Unk_e88610 {
    u8 _0[0x58];
    void* field_58;
};
PKMN_OFFSET_ASSERT(Unk_e88610, field_58, 0x58);

void Unk_5e26a0(void*);

// 0x7100e88610
void Unk_e88610_call(const Unk_e88610* self) {
    if (self->field_58 != nullptr) {
        Unk_5e26a0(self->field_58);
    }
}

struct Unk_e88fe0 {
    u8 _0[0xd30];
    u64 field_d30;
};
PKMN_OFFSET_ASSERT(Unk_e88fe0, field_d30, 0xd30);

// 0x7100e88fe0
bool Unk_e88fe0_check(const Unk_e88fe0* self) {
    return self->field_d30 != 0;
}

struct Unk_e88ff0 {
    u8 _0[0xd5c];
    s32 field_d5c;
};
PKMN_OFFSET_ASSERT(Unk_e88ff0, field_d5c, 0xd5c);

// 0x7100e88ff0
bool Unk_e88ff0_check(const Unk_e88ff0* self) {
    return self->field_d5c > 0;
}

// 0x7100e89540
void Unk_e89540_update() {}

struct Unk_e89550 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_e89550, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_e89550, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_e89550, field_10, 0x10);

// 0x7100e89550
void Unk_e89550_set(const Unk_e89550* self, Unk_e89550* value) {
    *value = *self;
}

struct Unk_e89570 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_e89570, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_e89570, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_e89570, field_10, 0x10);

// 0x7100e89570
void Unk_e89570_set(const Unk_e89570* self, Unk_e89570* value) {
    *value = *self;
}

struct Unk_27e066c_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27e066c_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27e066c_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27e066c_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27e066c_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27e066c_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27e066c_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27e066c_Data, field_18, 0x18);

extern Unk_27e066c_Data Unk_27e066c __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x7100e897f0
void Unk_e897f0_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27e066c.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27e066c.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27e066c.field_18 = 0xffff;
    Unk_27e066c.field_10 = 0;
    Unk_27e066c.field_8 = r2;
    Unk_27e066c.field_c = 0;
    Unk_27e066c.field_14 = 0xffffffff;
}
