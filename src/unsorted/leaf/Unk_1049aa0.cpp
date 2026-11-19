// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

extern void* Unk_27790f0;
void Unk_6c2e30(void*);

// 0x7101049aa0
void Unk_1049aa0_call(u64 /*unused*/) {
    if (Unk_27790f0 != 0) {
        Unk_6c2e30(Unk_27790f0);
    }
}

extern void* Unk_27790f0;
void Unk_6c2fa0(void*, u64);

// 0x7101049ac0
void Unk_1049ac0_call(void* /*unused*/, u64 value) {
    if (Unk_27790f0 != 0) {
        Unk_6c2fa0(Unk_27790f0, value);
    }
}

extern void* Unk_27790f0;
void Unk_6c2ea0(void*, u64);

// 0x7101049ae0
void Unk_1049ae0_call(void* /*unused*/, u64 value) {
    if (Unk_27790f0 != 0) {
        Unk_6c2ea0(Unk_27790f0, value);
    }
}

extern void* Unk_27790f0;
void Unk_6c2e60(void*);

// 0x7101049b00
void Unk_1049b00_call(u64 /*unused*/) {
    if (Unk_27790f0 != 0) {
        Unk_6c2e60(Unk_27790f0);
    }
}

extern void* Unk_27790f0;
void Unk_6c3140(void*);

// 0x7101049b20
void Unk_1049b20_call(u64 /*unused*/) {
    if (Unk_27790f0 != 0) {
        Unk_6c3140(Unk_27790f0);
    }
}

struct Unk_1049d00 {
    u8 _0[0x70];
    u8 field_70;
};
PKMN_OFFSET_ASSERT(Unk_1049d00, field_70, 0x70);

// 0x7101049d00
u8 Unk_1049d00_getField70(const Unk_1049d00* self) {
    return self->field_70;
}

struct Unk_1049d10 {
    u8 _0[0x71];
    u8 field_71;
};
PKMN_OFFSET_ASSERT(Unk_1049d10, field_71, 0x71);

// 0x7101049d10
u8 Unk_1049d10_getField71(const Unk_1049d10* self) {
    return self->field_71;
}

struct Unk_27e3784_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27e3784_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27e3784_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27e3784_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27e3784_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27e3784_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27e3784_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27e3784_Data, field_18, 0x18);

extern Unk_27e3784_Data Unk_27e3784 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x710104a040
void Unk_104a040_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27e3784.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27e3784.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27e3784.field_10 = 0xffff;
    Unk_27e3784.field_8 = r2;
    Unk_27e3784.field_c = 0xffffffff;
    Unk_27e3784.field_18 = 0;
    Unk_27e3784.field_14 = 0;
}
