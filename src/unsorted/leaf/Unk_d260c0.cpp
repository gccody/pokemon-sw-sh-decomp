// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

u32 Unk_d25f30();

// 0x7100d260c0
u32 Unk_d260c0_call() {
    u32 r0 = Unk_d25f30();
    return r0 == 2 ? r0 : (r0 == 1);
}

// 0x7100d29850
u32 Unk_d29850() {
    return 0;
}

extern bool Unk_23e1048;

// 0x7100d29c40
void Unk_d29c40_set(bool self) {
    Unk_23e1048 = self;
}

extern bool Unk_27da7a9;

// 0x7100d29e50
void Unk_d29e50_set(bool self) {
    Unk_27da7a9 = self;
}

struct Unk_d36900 {
    u8 _0[0x560];
    void* field_560;
    u8 _568[0xc8];
    void* field_630;
};
PKMN_OFFSET_ASSERT(Unk_d36900, field_560, 0x560);
PKMN_OFFSET_ASSERT(Unk_d36900, field_630, 0x630);

void Unk_d37660(void*, void*, void*);
void Unk_d38270(void*);

// 0x7100d36900
void Unk_d36900_call(const Unk_d36900* self, void* value, void* arg2) {
    Unk_d37660(self->field_630, value, arg2);
    Unk_d38270(self->field_560);
}

struct Unk_d369a0_4c0 {
    u8 _0[0x170];
    f32 field_170;
};
PKMN_OFFSET_ASSERT(Unk_d369a0_4c0, field_170, 0x170);

struct Unk_d369a0 {
    u8 _0[0x4c0];
    Unk_d369a0_4c0* field_4c0;
};
PKMN_OFFSET_ASSERT(Unk_d369a0, field_4c0, 0x4c0);

// 0x7100d369a0
void Unk_d369a0_set(const Unk_d369a0* self, f32 fvalue) {
    self->field_4c0->field_170 = fvalue;
}

struct Unk_d369b0_4c8 {
    u8 _0[0xec];
    u8 field_ec;
};
PKMN_OFFSET_ASSERT(Unk_d369b0_4c8, field_ec, 0xec);

struct Unk_d369b0 {
    u8 _0[0x4c8];
    Unk_d369b0_4c8* field_4c8;
};
PKMN_OFFSET_ASSERT(Unk_d369b0, field_4c8, 0x4c8);

// 0x7100d369b0
u8 Unk_d369b0_get(const Unk_d369b0* self) {
    return self->field_4c8->field_ec;
}

struct Unk_d36a60 {
    u8 _0[0x510];
    bool field_510;
};
PKMN_OFFSET_ASSERT(Unk_d36a60, field_510, 0x510);

// 0x7100d36a60
void Unk_d36a60_set(Unk_d36a60* self, bool value) {
    self->field_510 = value;
}

struct Unk_d36a70_4b0 {
    u8 _0[0x54];
    u32 field_54;
};
PKMN_OFFSET_ASSERT(Unk_d36a70_4b0, field_54, 0x54);
struct Unk_d36a70_568 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5(u64);
};
struct Unk_d36a70 {
    u8 _0[0x4b0];
    Unk_d36a70_4b0* field_4b0;
    u8 _4b8[0xb0];
    Unk_d36a70_568* field_568;
};
PKMN_OFFSET_ASSERT(Unk_d36a70, field_4b0, 0x4b0);
PKMN_OFFSET_ASSERT(Unk_d36a70, field_568, 0x568);

// 0x7100d36a70
void Unk_d36a70_update(const Unk_d36a70* self, u64 value) {
    if (self->field_4b0->field_54 == 3) {
        return;
    }
    self->field_568->vf5(value);
}

struct Unk_d36be0_568 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
};

struct Unk_d36be0 {
    u8 _0[0x568];
    Unk_d36be0_568* field_568;
};
PKMN_OFFSET_ASSERT(Unk_d36be0, field_568, 0x568);

// 0x7100d36be0
void Unk_d36be0_call(const Unk_d36be0* self) {
    self->field_568->vf14();
}

struct Unk_d36c10_4b0 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8(u64, u64);
};

struct Unk_d36c10 {
    u8 _0[0x4b0];
    Unk_d36c10_4b0* field_4b0;
};
PKMN_OFFSET_ASSERT(Unk_d36c10, field_4b0, 0x4b0);

// 0x7100d36c10
void Unk_d36c10_call(const Unk_d36c10* self, u64 value, u64 arg2) {
    self->field_4b0->vf8(value, arg2);
}

struct Unk_27dc29c_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27dc29c_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27dc29c_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27dc29c_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27dc29c_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27dc29c_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27dc29c_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27dc29c_Data, field_18, 0x18);

extern Unk_27dc29c_Data Unk_27dc29c __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x7100d37590
void Unk_d37590_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27dc29c.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27dc29c.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27dc29c.field_18 = 0xffff;
    Unk_27dc29c.field_10 = 0;
    Unk_27dc29c.field_8 = r2;
    Unk_27dc29c.field_c = 0;
    Unk_27dc29c.field_14 = 0xffffffff;
}
