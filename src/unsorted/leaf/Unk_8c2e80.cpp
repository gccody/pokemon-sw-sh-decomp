// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_7ee6b0;

struct Unk_8c2e80_170 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual u32 vf9();
};

struct Unk_8c2e80 {
    u8 _0[0x170];
    Unk_8c2e80_170* field_170;
    u32 field_178;
};
PKMN_OFFSET_ASSERT(Unk_8c2e80, field_170, 0x170);
PKMN_OFFSET_ASSERT(Unk_8c2e80, field_178, 0x178);

// 0x71008c2e80
bool Unk_8c2e80_call(const Unk_8c2e80* self) {
    if (self->field_178 != 2) {
        return true;
    }
    u32 r0 = self->field_170->vf9();
    return r0 == 0;
}

struct Unk_8c3220_arg1 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8c3220_arg1, field_0, 0x0);

struct Unk_7ee6b0;
u32 Unk_7ef6a0(const Unk_7ee6b0*);
const Unk_7ee6b0* Unk_8c20a0(void*, u32);

// 0x71008c3220
bool Unk_8c3220_call(void* self, const Unk_8c3220_arg1* value) {
    u32 r1 = Unk_7ef6a0(Unk_8c20a0(self, value->field_0));
    return r1 != 0;
}

struct Unk_8c3250_arg1 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8c3250_arg1, field_0, 0x0);

struct Unk_7ee6b0;
u32 Unk_7ef6a0(const Unk_7ee6b0*);
const Unk_7ee6b0* Unk_8c20a0(void*, u32);

// 0x71008c3250
bool Unk_8c3250_call(void* self, const Unk_8c3250_arg1* value) {
    u32 r1 = Unk_7ef6a0(Unk_8c20a0(self, value->field_0));
    return r1 == 0;
}

struct Unk_8c32f0_arg1 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8c32f0_arg1, field_0, 0x0);

u64 Unk_7ef630();
const Unk_7ee6b0* Unk_8c20a0(void*, u32);

// 0x71008c32f0
u64 Unk_8c32f0_call(void* self, const Unk_8c32f0_arg1* value) {
    Unk_8c20a0(self, value->field_0);
    u64 r1 = Unk_7ef630();
    return r1 & 1;
}

struct Unk_8c3b80_arg1 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8c3b80_arg1, field_0, 0x0);

u64 Unk_780ec0(u32);

// 0x71008c3b80
u64 Unk_8c3b80_call(void* /*unused*/, const Unk_8c3b80_arg1* value) {
    u64 r0 = Unk_780ec0(value->field_0);
    return r0 & 1;
}

struct Unk_8c4400_arg1 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8c4400_arg1, field_0, 0x0);

u64 Unk_8c6230(void*, u32);

// 0x71008c4400
u64 Unk_8c4400_call(void* self, const Unk_8c4400_arg1* value) {
    u64 r0 = Unk_8c6230(self, value->field_0);
    return r0 & 1;
}

u64 Unk_8c6180(void*);

// 0x71008c4560
u64 Unk_8c4560_call(void* self) {
    u64 r0 = Unk_8c6180(self);
    return r0 & 1;
}

struct Unk_8c4710_arg1 {
    u32 field_0;
    u8 _4[0x4];
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_8c4710_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_8c4710_arg1, field_8, 0x8);

u64 Unk_8c62f0(void*, u32, u32);

// 0x71008c4710
u64 Unk_8c4710_call(void* self, const Unk_8c4710_arg1* value) {
    u64 r0 = Unk_8c62f0(self, value->field_0, value->field_8);
    return r0 & 1;
}

struct Unk_8c5740_arg1 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8c5740_arg1, field_0, 0x0);

struct Unk_7ee6b0;
u64 Unk_7ef2b0_call(void*);
const Unk_7ee6b0* Unk_8c20a0(void*, u32);

// 0x71008c5740
u64 Unk_8c5740_call(void* self, const Unk_8c5740_arg1* value) {
    u64 r1 = Unk_7ef2b0_call(const_cast<Unk_7ee6b0*>(Unk_8c20a0(self, value->field_0)));
    return r1 & 1;
}

struct Unk_8c5820_arg1 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8c5820_arg1, field_0, 0x0);

u64 Unk_8a82d0_get();

// 0x71008c5820
bool Unk_8c5820_call(void* /*unused*/, const Unk_8c5820_arg1* value) {
    u32 v0 = value->field_0;
    u64 r0 = Unk_8a82d0_get();
    return r0 < v0;
}

struct Unk_8c5850_arg1 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8c5850_arg1, field_0, 0x0);

u64 Unk_8a82d0_get();

// 0x71008c5850
bool Unk_8c5850_call(void* /*unused*/, const Unk_8c5850_arg1* value) {
    u32 v0 = value->field_0;
    u64 r0 = Unk_8a82d0_get();
    return r0 > v0;
}

struct Unk_8c5880_arg1 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8c5880_arg1, field_0, 0x0);

u64 Unk_8a82d0_get();

// 0x71008c5880
bool Unk_8c5880_call(void* /*unused*/, const Unk_8c5880_arg1* value) {
    u32 v0 = value->field_0;
    u64 r0 = Unk_8a82d0_get();
    return r0 == v0;
}

struct Unk_8c58b0_arg1 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8c58b0_arg1, field_0, 0x0);

u64 Unk_8a82d0_get();

// 0x71008c58b0
bool Unk_8c58b0_call(void* /*unused*/, const Unk_8c58b0_arg1* value) {
    u32 v0 = value->field_0;
    u64 r0 = Unk_8a82d0_get();
    return r0 != v0;
}

// 0x71008c5b00
u64 Unk_8c5b00_get() {
    return 0;
}

// 0x71008c5b10
u64 Unk_8c5b10_get() {
    return 0;
}

struct Unk_8c5b20_arg1 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8c5b20_arg1, field_0, 0x0);

u32 Unk_7f0b30();
const Unk_7ee6b0* Unk_8c20a0(void*, u32);

// 0x71008c5b20
bool Unk_8c5b20_call(void* self, const Unk_8c5b20_arg1* value) {
    Unk_8c20a0(self, value->field_0);
    u32 r1 = Unk_7f0b30();
    return r1 != 0x19;
}

struct Unk_27d170c_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27d170c_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27d170c_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27d170c_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27d170c_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27d170c_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27d170c_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27d170c_Data, field_18, 0x18);

extern Unk_27d170c_Data Unk_27d170c __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x71008c64d0
void Unk_8c64d0_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27d170c.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27d170c.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27d170c.field_18 = 0xffff;
    Unk_27d170c.field_10 = 0;
    Unk_27d170c.field_8 = r2;
    Unk_27d170c.field_c = 0;
    Unk_27d170c.field_14 = 0xffffffff;
}
