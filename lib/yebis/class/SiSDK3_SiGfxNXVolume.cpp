// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N6SiSDK313SiGfxNXVolumeE
// (The class's other functions are SiGfx_NX_Volume_Impl.cpp's.)
#include <types.h>

struct Unk_565fe0 {
    u8 _0[0x18];
    u32 field_18;
};
PKMN_OFFSET_ASSERT(Unk_565fe0, field_18, 0x18);

struct Unk_565a80 {
    u8 _0[0x20];
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_565a80, field_20, 0x20);

struct Unk_565a90 {
    u8 _0[0x20];
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_565a90, field_20, 0x20);

struct Unk_565aa0 {
    u8 _0[0x28];
    u64 field_28;
};
PKMN_OFFSET_ASSERT(Unk_565aa0, field_28, 0x28);

struct Unk_565b70 {
    u8 _0[0x64];
    u8 field_64;
};
PKMN_OFFSET_ASSERT(Unk_565b70, field_64, 0x64);

struct Unk_565be0 {
    u8 _0[0x78];
    u8 field_78;
};
PKMN_OFFSET_ASSERT(Unk_565be0, field_78, 0x78);

namespace SiSDK3 {
class SiGfxNXVolume {
public:
    u32 vf4();
    u64 vf5();
    u64 vf6();
    u64 vf7();
    const u8* vf8();
    void vf9();
    void vf10();
    void vf11();
    void vf12();
    void vf13();
    void vf14();
    void vf15();
    u32 vf16();
    const u8* vf17();
    u64 vf18();
    u64 vf19();
};
}  // namespace SiSDK3

// 0x7100565a80
u64 SiSDK3::SiGfxNXVolume::vf5() {
    const Unk_565a80* self = reinterpret_cast<const Unk_565a80*>(this);
    return self->field_20;
}

// 0x7100565a90
u64 SiSDK3::SiGfxNXVolume::vf6() {
    const Unk_565a90* self = reinterpret_cast<const Unk_565a90*>(this);
    return self->field_20;
}

// 0x7100565aa0
u64 SiSDK3::SiGfxNXVolume::vf7() {
    const Unk_565aa0* self = reinterpret_cast<const Unk_565aa0*>(this);
    return self->field_28;
}

// 0x7100565b70
const u8* SiSDK3::SiGfxNXVolume::vf8() {
    const Unk_565b70* self = reinterpret_cast<const Unk_565b70*>(this);
    return &self->field_64;
}

// 0x7100565b80
void SiSDK3::SiGfxNXVolume::vf9() {
}

// 0x7100565b90
void SiSDK3::SiGfxNXVolume::vf10() {
}

// 0x7100565ba0
void SiSDK3::SiGfxNXVolume::vf11() {
}

// 0x7100565bb0
void SiSDK3::SiGfxNXVolume::vf12() {
}

// 0x7100565bc0
void SiSDK3::SiGfxNXVolume::vf13() {
}

// 0x7100565bd0
void SiSDK3::SiGfxNXVolume::vf14() {
}

// 0x7100565be0
const u8* SiSDK3::SiGfxNXVolume::vf17() {
    const Unk_565be0* self = reinterpret_cast<const Unk_565be0*>(this);
    return &self->field_78;
}

// 0x7100565bf0
u64 SiSDK3::SiGfxNXVolume::vf18() {
    return 0;
}

// 0x7100565c00
u64 SiSDK3::SiGfxNXVolume::vf19() {
    return 0;
}

// 0x7100565ea0
void SiSDK3::SiGfxNXVolume::vf15() {
}

// 0x7100565eb0
u32 SiSDK3::SiGfxNXVolume::vf16() {
    return 0;
}

// 0x7100565fe0
u32 SiSDK3::SiGfxNXVolume::vf4() {
    const Unk_565fe0* self = reinterpret_cast<const Unk_565fe0*>(this);
    return self->field_18;
}
