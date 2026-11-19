// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N6SiSDK37SiIOVFSE
#include <types.h>

struct Unk_586af0 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_586af0, field_10, 0x10);

struct Unk_584d80 {
    u8 _0[0x18];
    u8 field_18;
};
PKMN_OFFSET_ASSERT(Unk_584d80, field_18, 0x18);

struct Unk_584d90 {
    u8 _0[0x18];
    u8 field_18;
    u8 field_19;
};
PKMN_OFFSET_ASSERT(Unk_584d90, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_584d90, field_19, 0x19);

struct Unk_584db0 {
    u8 _0[0x19];
    u8 field_19;
};
PKMN_OFFSET_ASSERT(Unk_584db0, field_19, 0x19);

struct Unk_584dc0 {
    u8 _0[0x19];
    u8 field_19;
};
PKMN_OFFSET_ASSERT(Unk_584dc0, field_19, 0x19);

struct Unk_584dd0 {
    u8 _0[0xe8];
    u64 field_e8;
};
PKMN_OFFSET_ASSERT(Unk_584dd0, field_e8, 0xe8);

struct Unk_584de0 {
    u8 _0[0xe8];
    u64 field_e8;
};
PKMN_OFFSET_ASSERT(Unk_584de0, field_e8, 0xe8);

struct Unk_5856c0 {
    u8 _0[0x1a];
    bool field_1a;
};
PKMN_OFFSET_ASSERT(Unk_5856c0, field_1a, 0x1a);

struct Unk_5856d0 {
    u8 _0[0x1a];
    u8 field_1a;
};
PKMN_OFFSET_ASSERT(Unk_5856d0, field_1a, 0x1a);

struct Unk_5856f0 {
    u8 _0[0x88];
    u8 field_88;
};
PKMN_OFFSET_ASSERT(Unk_5856f0, field_88, 0x88);

namespace SiSDK3 {
class SiIOVFS {
public:
    u32 vf4();
    u8 vf7();
    u32 vf8();
    u32 vf9();
    u8 vf10();
    u64 vf11();
    u64 vf12();
    u64 vf15();
    u64 vf16();
    void vf17(bool value);
    u8 vf18();
    const u8* vf20();
};
}  // namespace SiSDK3

// 0x7100584d80
u8 SiSDK3::SiIOVFS::vf7() {
    const Unk_584d80* self = reinterpret_cast<const Unk_584d80*>(this);
    return self->field_18;
}

// 0x7100584d90
u32 SiSDK3::SiIOVFS::vf8() {
    Unk_584d90* self = reinterpret_cast<Unk_584d90*>(this);
    if (self->field_18 == 0) {
        return 0;
    }
    self->field_19 = 1;
    return 1;
}

// 0x7100584db0
u32 SiSDK3::SiIOVFS::vf9() {
    Unk_584db0* self = reinterpret_cast<Unk_584db0*>(this);
    self->field_19 = 0;
    return 1;
}

// 0x7100584dc0
u8 SiSDK3::SiIOVFS::vf10() {
    const Unk_584dc0* self = reinterpret_cast<const Unk_584dc0*>(this);
    return self->field_19;
}

// 0x7100584dd0
u64 SiSDK3::SiIOVFS::vf11() {
    const Unk_584dd0* self = reinterpret_cast<const Unk_584dd0*>(this);
    return self->field_e8;
}

// 0x7100584de0
u64 SiSDK3::SiIOVFS::vf12() {
    const Unk_584de0* self = reinterpret_cast<const Unk_584de0*>(this);
    return self->field_e8;
}

// 0x71005856a0
u64 SiSDK3::SiIOVFS::vf15() {
    return 0;
}

// 0x71005856b0
u64 SiSDK3::SiIOVFS::vf16() {
    return 0;
}

// 0x71005856c0
void SiSDK3::SiIOVFS::vf17(bool value) {
    Unk_5856c0* self = reinterpret_cast<Unk_5856c0*>(this);
    self->field_1a = value;
}

// 0x71005856d0
u8 SiSDK3::SiIOVFS::vf18() {
    const Unk_5856d0* self = reinterpret_cast<const Unk_5856d0*>(this);
    return self->field_1a;
}

// 0x71005856f0
const u8* SiSDK3::SiIOVFS::vf20() {
    const Unk_5856f0* self = reinterpret_cast<const Unk_5856f0*>(this);
    return &self->field_88;
}

// 0x7100586af0
u32 SiSDK3::SiIOVFS::vf4() {
    const Unk_586af0* self = reinterpret_cast<const Unk_586af0*>(this);
    return self->field_10;
}
