// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N6SiSDK318SiGfxNXCommandListE
#include <types.h>

struct Unk_53abc0 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_53abc0, field_10, 0x10);

struct Unk_53a640 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_53a640, field_18, 0x18);

struct Unk_53a650 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_53a650, field_18, 0x18);

struct Unk_53a680 {
    u8 _0[0x20];
    u8 field_20;
};
PKMN_OFFSET_ASSERT(Unk_53a680, field_20, 0x20);

struct Unk_53a690 {
    u8 _0[0x50];
    u64 field_50;
};
PKMN_OFFSET_ASSERT(Unk_53a690, field_50, 0x50);

struct Unk_53a6a0 {
    u8 _0[0x50];
    u64 field_50;
};
PKMN_OFFSET_ASSERT(Unk_53a6a0, field_50, 0x50);

struct Unk_53a6b0 {
    u8 _0[0x80];
    u32 field_80;
};
PKMN_OFFSET_ASSERT(Unk_53a6b0, field_80, 0x80);

struct Unk_53a6c0 {
    u8 _0[0x124];
    u8 field_124;
};
PKMN_OFFSET_ASSERT(Unk_53a6c0, field_124, 0x124);

struct Unk_53a6d0 {
    u8 _0[0x124];
    u8 field_124;
};
PKMN_OFFSET_ASSERT(Unk_53a6d0, field_124, 0x124);

struct Unk_53a6e0 {
    u8 _0[0x121];
    u8 field_121;
};
PKMN_OFFSET_ASSERT(Unk_53a6e0, field_121, 0x121);

struct Unk_53abd0 {
    u8 _0[0x88];
    u64 field_88;
};
PKMN_OFFSET_ASSERT(Unk_53abd0, field_88, 0x88);

struct Unk_53abe0 {
    u8 _0[0x90];
    u64 field_90;
};
PKMN_OFFSET_ASSERT(Unk_53abe0, field_90, 0x90);

namespace SiSDK3 {
class SiGfxNXCommandList {
public:
    u32 vf4();
    u64 vf5();
    u64 vf6();
    const u8* vf8();
    u64 vf9();
    u64 vf10();
    u32 vf11();
    const u8* vf12();
    const u8* vf13();
    u8 vf14();
    u64 vf15();
    u64 vf16();
};
}  // namespace SiSDK3

// 0x710053a640
u64 SiSDK3::SiGfxNXCommandList::vf5() {
    const Unk_53a640* self = reinterpret_cast<const Unk_53a640*>(this);
    return self->field_18;
}

// 0x710053a650
u64 SiSDK3::SiGfxNXCommandList::vf6() {
    const Unk_53a650* self = reinterpret_cast<const Unk_53a650*>(this);
    return self->field_18;
}

// 0x710053a680
const u8* SiSDK3::SiGfxNXCommandList::vf8() {
    const Unk_53a680* self = reinterpret_cast<const Unk_53a680*>(this);
    return &self->field_20;
}

// 0x710053a690
u64 SiSDK3::SiGfxNXCommandList::vf9() {
    const Unk_53a690* self = reinterpret_cast<const Unk_53a690*>(this);
    return self->field_50;
}

// 0x710053a6a0
u64 SiSDK3::SiGfxNXCommandList::vf10() {
    const Unk_53a6a0* self = reinterpret_cast<const Unk_53a6a0*>(this);
    return self->field_50;
}

// 0x710053a6b0
u32 SiSDK3::SiGfxNXCommandList::vf11() {
    const Unk_53a6b0* self = reinterpret_cast<const Unk_53a6b0*>(this);
    return self->field_80;
}

// 0x710053a6c0
const u8* SiSDK3::SiGfxNXCommandList::vf12() {
    const Unk_53a6c0* self = reinterpret_cast<const Unk_53a6c0*>(this);
    return &self->field_124;
}

// 0x710053a6d0
const u8* SiSDK3::SiGfxNXCommandList::vf13() {
    const Unk_53a6d0* self = reinterpret_cast<const Unk_53a6d0*>(this);
    return &self->field_124;
}

// 0x710053a6e0
u8 SiSDK3::SiGfxNXCommandList::vf14() {
    const Unk_53a6e0* self = reinterpret_cast<const Unk_53a6e0*>(this);
    return self->field_121;
}

// 0x710053abc0
u32 SiSDK3::SiGfxNXCommandList::vf4() {
    const Unk_53abc0* self = reinterpret_cast<const Unk_53abc0*>(this);
    return self->field_10;
}

// 0x710053abd0
u64 SiSDK3::SiGfxNXCommandList::vf15() {
    const Unk_53abd0* self = reinterpret_cast<const Unk_53abd0*>(this);
    return self->field_88;
}

// 0x710053abe0
u64 SiSDK3::SiGfxNXCommandList::vf16() {
    const Unk_53abe0* self = reinterpret_cast<const Unk_53abe0*>(this);
    return self->field_90;
}
