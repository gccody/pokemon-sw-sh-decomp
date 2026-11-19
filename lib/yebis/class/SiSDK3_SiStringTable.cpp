// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_4c7c70 {
    u8 _0[0x18];
    u32 field_18;
};
PKMN_OFFSET_ASSERT(Unk_4c7c70, field_18, 0x18);

struct Unk_4c7100 {
    u8 _0[0x54];
    u8 field_54;
};
PKMN_OFFSET_ASSERT(Unk_4c7100, field_54, 0x54);

struct Unk_4c7120 {
    u8 _0[0x64];
    u8 field_64;
};
PKMN_OFFSET_ASSERT(Unk_4c7120, field_64, 0x64);

struct Unk_4c7130 {
    u8 _0[0x140];
    u32 field_140;
};
PKMN_OFFSET_ASSERT(Unk_4c7130, field_140, 0x140);

struct Unk_4c7b10 {
    u8 _0[0x80];
    u32 field_80;
};
PKMN_OFFSET_ASSERT(Unk_4c7b10, field_80, 0x80);

struct Unk_4c70b0 {
    u8 _0[0x20];
    u8 field_20;
};
PKMN_OFFSET_ASSERT(Unk_4c70b0, field_20, 0x20);

struct Unk_4c70d0 {
    u8 _0[0x50];
    u32 field_50;
};
PKMN_OFFSET_ASSERT(Unk_4c70d0, field_50, 0x50);

struct Unk_4c70c0 {
    u8 _0[0x18];
    u8 field_18;
};
PKMN_OFFSET_ASSERT(Unk_4c70c0, field_18, 0x18);

namespace SiSDK3 {
class SiStringTable {
public:
    u32 vf4();
    const u8* vf5();
    const u8* vf7();
    void vf8();
    u32 vf17();
    const u8* vf19();
    u32 vf20();
    const u8* vf3();
};
}  // namespace SiSDK3

// 0x71004c70b0
const u8* SiSDK3::SiStringTable::vf19() {
    const Unk_4c70b0* self = reinterpret_cast<const Unk_4c70b0*>(this);
    return &self->field_20;
}

// 0x71004c70c0
const u8* SiSDK3::SiStringTable::vf3() {
    const Unk_4c70c0* self = reinterpret_cast<const Unk_4c70c0*>(this);
    return &self->field_18;
}

// 0x71004c70d0
u32 SiSDK3::SiStringTable::vf20() {
    const Unk_4c70d0* self = reinterpret_cast<const Unk_4c70d0*>(this);
    return self->field_50;
}

// 0x71004c7100
const u8* SiSDK3::SiStringTable::vf5() {
    const Unk_4c7100* self = reinterpret_cast<const Unk_4c7100*>(this);
    return &self->field_54;
}

// 0x71004c7120
const u8* SiSDK3::SiStringTable::vf7() {
    const Unk_4c7120* self = reinterpret_cast<const Unk_4c7120*>(this);
    return &self->field_64;
}

// 0x71004c7130
void SiSDK3::SiStringTable::vf8() {
    Unk_4c7130* self = reinterpret_cast<Unk_4c7130*>(this);
    self->field_140 = self->field_140 + 1;
}

// 0x71004c7b10
u32 SiSDK3::SiStringTable::vf17() {
    const Unk_4c7b10* self = reinterpret_cast<const Unk_4c7b10*>(this);
    return self->field_80;
}

// 0x71004c7c70
u32 SiSDK3::SiStringTable::vf4() {
    const Unk_4c7c70* self = reinterpret_cast<const Unk_4c7c70*>(this);
    return self->field_18;
}
