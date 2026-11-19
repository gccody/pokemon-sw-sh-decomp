// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N6SiSDK319SiGfxTextureUtilityE
#include <types.h>

struct Unk_4ec910 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_4ec910, field_10, 0x10);

struct Unk_4eae50 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8(u64, u64, u64, u64, u64, u32, u32);
};

namespace SiSDK3 {
class SiGfxTextureUtility {
public:
    u32 vf4();
    void vf7(u64 value, u64 arg2, u64 arg3, u64 arg4);
    u32 vf14();
    u32 vf15();
    u32 vf16();
};
}  // namespace SiSDK3

// 0x71004eae50
void SiSDK3::SiGfxTextureUtility::vf7(u64 value, u64 arg2, u64 arg3, u64 arg4) {
    Unk_4eae50* self = reinterpret_cast<Unk_4eae50*>(this);
    self->vf8(value, arg2, arg3, arg4, 0, 0, 0);
}

// 0x71004ebaf0
u32 SiSDK3::SiGfxTextureUtility::vf14() {
    return 0;
}

// 0x71004ebb00
u32 SiSDK3::SiGfxTextureUtility::vf15() {
    return 0;
}

// 0x71004ebb10
u32 SiSDK3::SiGfxTextureUtility::vf16() {
    return 0;
}

// 0x71004ec910
u32 SiSDK3::SiGfxTextureUtility::vf4() {
    const Unk_4ec910* self = reinterpret_cast<const Unk_4ec910*>(this);
    return self->field_10;
}
