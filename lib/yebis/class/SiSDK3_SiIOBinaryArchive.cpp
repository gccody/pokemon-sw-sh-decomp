// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N6SiSDK317SiIOBinaryArchiveE
#include <types.h>

struct Unk_57c670 {
    u8 _0[0x20];
    u32 field_20;
};
PKMN_OFFSET_ASSERT(Unk_57c670, field_20, 0x20);

struct Unk_57b4f0 {
    u8 _0[0x30];
    u8 field_30;
};
PKMN_OFFSET_ASSERT(Unk_57b4f0, field_30, 0x30);

struct Unk_57afc0 {
    u8 _0[0xe8];
    u64 field_e8;
};
PKMN_OFFSET_ASSERT(Unk_57afc0, field_e8, 0xe8);

struct Unk_57afd0 {
    u8 _0[0xf0];
    u64 field_f0;
};
PKMN_OFFSET_ASSERT(Unk_57afd0, field_f0, 0xf0);

struct Unk_57bef0 {
    u8 _0[0x130];
    u8 field_130;
};
PKMN_OFFSET_ASSERT(Unk_57bef0, field_130, 0x130);

struct Unk_57b430 {
    u8 _0[0xe8];
    u64 field_e8;
};
PKMN_OFFSET_ASSERT(Unk_57b430, field_e8, 0xe8);

struct Unk_57b440 {
    u8 _0[0x88];
    u64 field_88;
    u64 field_90;
    u64 field_98;
    u8 _a0[0x8];
    u64 field_a8;
    u8 _b0[0x78];
    u64 field_128;
};
PKMN_OFFSET_ASSERT(Unk_57b440, field_88, 0x88);
PKMN_OFFSET_ASSERT(Unk_57b440, field_90, 0x90);
PKMN_OFFSET_ASSERT(Unk_57b440, field_98, 0x98);
PKMN_OFFSET_ASSERT(Unk_57b440, field_a8, 0xa8);
PKMN_OFFSET_ASSERT(Unk_57b440, field_128, 0x128);

struct Unk_57bf30 {
    u8 _0[0x160];
    u32 field_160;
};
PKMN_OFFSET_ASSERT(Unk_57bf30, field_160, 0x160);

struct Unk_57bf40 {
    u8 _0[0x160];
    u32 field_160;
};
PKMN_OFFSET_ASSERT(Unk_57bf40, field_160, 0x160);

struct Unk_57bf50 {
    u8 _0[0xe0];
    u32 field_e0;
};
PKMN_OFFSET_ASSERT(Unk_57bf50, field_e0, 0xe0);

struct Unk_57bf60 {
    u8 _0[0xe0];
    u32 field_e0;
};
PKMN_OFFSET_ASSERT(Unk_57bf60, field_e0, 0xe0);

struct Unk_57bf70 {
    u8 _0[0xc0];
    u64 field_c0;
};
PKMN_OFFSET_ASSERT(Unk_57bf70, field_c0, 0xc0);

struct Unk_57c5c0 {
    u8 _0[0x1c0];
    u32 field_1c0;
};
PKMN_OFFSET_ASSERT(Unk_57c5c0, field_1c0, 0x1c0);

namespace SiSDK3 {
class SiIOBinaryArchive {
public:
    u32 vf4();
    const u8* vf9();
    u64 vf10();
    u64 vf11();
    const u8* vf18();
    bool vf19();
    u32 vf20();
    void vf26(u32 value);
    u32 vf27();
    void vf28(u32 value);
    u32 vf29();
    u64 vf30();
    u32 vf34();
};
}  // namespace SiSDK3

// 0x710057afc0
u64 SiSDK3::SiIOBinaryArchive::vf10() {
    const Unk_57afc0* self = reinterpret_cast<const Unk_57afc0*>(this);
    return self->field_e8;
}

// 0x710057afd0
u64 SiSDK3::SiIOBinaryArchive::vf11() {
    const Unk_57afd0* self = reinterpret_cast<const Unk_57afd0*>(this);
    return self->field_f0;
}

// 0x710057b430
bool SiSDK3::SiIOBinaryArchive::vf19() {
    const Unk_57b430* self = reinterpret_cast<const Unk_57b430*>(this);
    return self->field_e8 == 0;
}

// 0x710057b440
u32 SiSDK3::SiIOBinaryArchive::vf20() {
    Unk_57b440* self = reinterpret_cast<Unk_57b440*>(this);
    self->field_88 = 0xb0;
    self->field_90 = 3;
    self->field_98 = 0xa000000000;
    self->field_a8 = self->field_128;
    return 1;
}

// 0x710057b4f0
const u8* SiSDK3::SiIOBinaryArchive::vf9() {
    const Unk_57b4f0* self = reinterpret_cast<const Unk_57b4f0*>(this);
    return &self->field_30;
}

// 0x710057bef0
const u8* SiSDK3::SiIOBinaryArchive::vf18() {
    const Unk_57bef0* self = reinterpret_cast<const Unk_57bef0*>(this);
    return &self->field_130;
}

// 0x710057bf30
void SiSDK3::SiIOBinaryArchive::vf26(u32 value) {
    Unk_57bf30* self = reinterpret_cast<Unk_57bf30*>(this);
    self->field_160 = value;
}

// 0x710057bf40
u32 SiSDK3::SiIOBinaryArchive::vf27() {
    const Unk_57bf40* self = reinterpret_cast<const Unk_57bf40*>(this);
    return self->field_160;
}

// 0x710057bf50
void SiSDK3::SiIOBinaryArchive::vf28(u32 value) {
    Unk_57bf50* self = reinterpret_cast<Unk_57bf50*>(this);
    self->field_e0 = value;
}

// 0x710057bf60
u32 SiSDK3::SiIOBinaryArchive::vf29() {
    const Unk_57bf60* self = reinterpret_cast<const Unk_57bf60*>(this);
    return self->field_e0;
}

// 0x710057bf70
u64 SiSDK3::SiIOBinaryArchive::vf30() {
    const Unk_57bf70* self = reinterpret_cast<const Unk_57bf70*>(this);
    return self->field_c0;
}

// 0x710057c5c0
u32 SiSDK3::SiIOBinaryArchive::vf34() {
    const Unk_57c5c0* self = reinterpret_cast<const Unk_57c5c0*>(this);
    return self->field_1c0;
}

// 0x710057c670
u32 SiSDK3::SiIOBinaryArchive::vf4() {
    const Unk_57c670* self = reinterpret_cast<const Unk_57c670*>(this);
    return self->field_20;
}
