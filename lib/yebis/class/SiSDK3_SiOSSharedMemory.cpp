// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N6SiSDK316SiOSSharedMemoryE
#include <types.h>

struct Unk_596380 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_596380, field_10, 0x10);

struct Unk_5961d0 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

struct Unk_5961f0 {
    u8 _0[0x18];
    u64 field_18;
    u32 field_20;
    u8 _24[0x4];
    u64 field_28;
};
PKMN_OFFSET_ASSERT(Unk_5961f0, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_5961f0, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_5961f0, field_28, 0x28);

struct Unk_596200 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    u8 _8[0x18];
    u32 field_20;
};
PKMN_OFFSET_ASSERT(Unk_596200, field_20, 0x20);

struct Unk_596230 {
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
    u8 _8[0x10];
    u64 field_18;
    u32 field_20;
    u8 _24[0x4];
    u64 field_28;
};
PKMN_OFFSET_ASSERT(Unk_596230, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_596230, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_596230, field_28, 0x28);

struct Unk_596270 {
    u8 _0[0x18];
    u8 field_18;
};
PKMN_OFFSET_ASSERT(Unk_596270, field_18, 0x18);

struct Unk_596280 {
    u8 _0[0x20];
    u32 field_20;
    u8 _24[0x4];
    u64 field_28;
};
PKMN_OFFSET_ASSERT(Unk_596280, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_596280, field_28, 0x28);

struct Unk_5962c0 {
    u8 _0[0x28];
    u64 field_28;
};
PKMN_OFFSET_ASSERT(Unk_5962c0, field_28, 0x28);

struct Unk_5962d0 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_5962d0, field_18, 0x18);

struct Unk_5961c0 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
};

namespace SiSDK3 {
class SiOSSharedMemory {
public:
    u32 vf4();
    u32 vf5();
    void vf6();
    u32 vf7();
    void vf8();
    const u8* vf9();
    u64 vf10();
    u64 vf12();
    u64 vf13();
    u32 vf14();
    void vf15();
};
}  // namespace SiSDK3

// 0x71005961b0
u32 SiSDK3::SiOSSharedMemory::vf14() {
    return 1;
}

// 0x71005961c0
void SiSDK3::SiOSSharedMemory::vf15() {
    Unk_5961c0* self = reinterpret_cast<Unk_5961c0*>(this);
    self->vf8();
}

// 0x71005961d0
u32 SiSDK3::SiOSSharedMemory::vf5() {
    Unk_5961d0* self = reinterpret_cast<Unk_5961d0*>(this);
    self->vf6();
    return 1;
}

// 0x71005961f0
void SiSDK3::SiOSSharedMemory::vf6() {
    Unk_5961f0* self = reinterpret_cast<Unk_5961f0*>(this);
    self->field_28 = 0;
    self->field_20 = 0;
    self->field_18 = 0;
}

// 0x7100596200
u32 SiSDK3::SiOSSharedMemory::vf7() {
    Unk_596200* self = reinterpret_cast<Unk_596200*>(this);
    self->vf8();
    self->field_20 = 0;
    return 1;
}

// 0x7100596230
void SiSDK3::SiOSSharedMemory::vf8() {
    Unk_596230* self = reinterpret_cast<Unk_596230*>(this);
    self->vf11();
    self->field_20 = 0;
    self->field_28 = 0;
    self->field_18 = 0;
}

// 0x7100596270
const u8* SiSDK3::SiOSSharedMemory::vf9() {
    const Unk_596270* self = reinterpret_cast<const Unk_596270*>(this);
    return &self->field_18;
}

// 0x7100596280
u64 SiSDK3::SiOSSharedMemory::vf10() {
    Unk_596280* self = reinterpret_cast<Unk_596280*>(this);
    self->field_20 = self->field_20 + 1;
    return self->field_28;
}

// 0x71005962c0
u64 SiSDK3::SiOSSharedMemory::vf12() {
    const Unk_5962c0* self = reinterpret_cast<const Unk_5962c0*>(this);
    return self->field_28;
}

// 0x71005962d0
u64 SiSDK3::SiOSSharedMemory::vf13() {
    const Unk_5962d0* self = reinterpret_cast<const Unk_5962d0*>(this);
    return self->field_18;
}

// 0x7100596380
u32 SiSDK3::SiOSSharedMemory::vf4() {
    const Unk_596380* self = reinterpret_cast<const Unk_596380*>(this);
    return self->field_10;
}
