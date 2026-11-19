// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_58b820 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_58b820, field_10, 0x10);

struct Unk_588940 {
    u8 _0[0x20];
    u8 field_20;
};
PKMN_OFFSET_ASSERT(Unk_588940, field_20, 0x20);

struct Unk_588950 {
    u8 _0[0x20];
    u8 field_20;
};
PKMN_OFFSET_ASSERT(Unk_588950, field_20, 0x20);

struct Unk_58b750 {
    u8 _0[0x90];
    u64 field_90;
};
PKMN_OFFSET_ASSERT(Unk_58b750, field_90, 0x90);

struct Unk_58b760 {
    u8 _0[0x90];
    u64 field_90;
};
PKMN_OFFSET_ASSERT(Unk_58b760, field_90, 0x90);

struct Unk_58b630 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_58b630, field_18, 0x18);

struct Unk_58b640 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_58b640, field_18, 0x18);

struct Unk_58b650 {
    u8 _0[0x30];
    u8 field_30;
};
PKMN_OFFSET_ASSERT(Unk_58b650, field_30, 0x30);

struct Unk_58b660 {
    u8 _0[0x60];
    u8 field_60;
};
PKMN_OFFSET_ASSERT(Unk_58b660, field_60, 0x60);

namespace SiSDK3 {
class SiIONXFileStream {
public:
    u32 vf4();
    u32 vf5();
    u32 vf11();
    u32 vf12();
    u64 vf73();
    u64 vf74();
    u64 vf75();
    u64 vf76();
    const u8* vf77();
    const u8* vf78();
    u32 vf80();
    u32 vf81();
};
}  // namespace SiSDK3

// 0x7100588940
u32 SiSDK3::SiIONXFileStream::vf11() {
    const Unk_588940* self = reinterpret_cast<const Unk_588940*>(this);
    return (self->field_20 >> 3) & 1;
}

// 0x7100588950
u32 SiSDK3::SiIONXFileStream::vf12() {
    const Unk_588950* self = reinterpret_cast<const Unk_588950*>(this);
    return (self->field_20 >> 4) & 1;
}

// 0x710058b630
u64 SiSDK3::SiIONXFileStream::vf75() {
    const Unk_58b630* self = reinterpret_cast<const Unk_58b630*>(this);
    return self->field_18;
}

// 0x710058b640
u64 SiSDK3::SiIONXFileStream::vf76() {
    const Unk_58b640* self = reinterpret_cast<const Unk_58b640*>(this);
    return self->field_18;
}

// 0x710058b650
const u8* SiSDK3::SiIONXFileStream::vf77() {
    const Unk_58b650* self = reinterpret_cast<const Unk_58b650*>(this);
    return &self->field_30;
}

// 0x710058b660
const u8* SiSDK3::SiIONXFileStream::vf78() {
    const Unk_58b660* self = reinterpret_cast<const Unk_58b660*>(this);
    return &self->field_60;
}

// 0x710058b730
u32 SiSDK3::SiIONXFileStream::vf80() {
    return 0;
}

// 0x710058b740
u32 SiSDK3::SiIONXFileStream::vf81() {
    return 0;
}

// 0x710058b750
u64 SiSDK3::SiIONXFileStream::vf73() {
    const Unk_58b750* self = reinterpret_cast<const Unk_58b750*>(this);
    return self->field_90;
}

// 0x710058b760
u64 SiSDK3::SiIONXFileStream::vf74() {
    const Unk_58b760* self = reinterpret_cast<const Unk_58b760*>(this);
    return self->field_90;
}

// 0x710058b820
u32 SiSDK3::SiIONXFileStream::vf4() {
    const Unk_58b820* self = reinterpret_cast<const Unk_58b820*>(this);
    return self->field_10;
}

// 0x710058b830
u32 SiSDK3::SiIONXFileStream::vf5() {
    return 1;
}
