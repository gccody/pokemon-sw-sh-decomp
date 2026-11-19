// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N4PPFX17IGPUVolumeTextureE
#include <types.h>

struct Unk_447300 {
    u8 _0[0x80];
    u32 field_80;
};
PKMN_OFFSET_ASSERT(Unk_447300, field_80, 0x80);

struct Unk_447650 {
    u8 _0[0x7c];
    u32 field_7c;
};
PKMN_OFFSET_ASSERT(Unk_447650, field_7c, 0x7c);

struct Unk_447660 {
    u8 _0[0x78];
    u32 field_78;
};
PKMN_OFFSET_ASSERT(Unk_447660, field_78, 0x78);

struct Unk_447680 {
    u8 _0[0x78];
    u32 field_78;
};
PKMN_OFFSET_ASSERT(Unk_447680, field_78, 0x78);

struct Unk_4476c0 {
    u8 _0[0x78];
    u32 field_78;
};
PKMN_OFFSET_ASSERT(Unk_4476c0, field_78, 0x78);

struct Unk_447700 {
    u8 _0[0x78];
    u32 field_78;
};
PKMN_OFFSET_ASSERT(Unk_447700, field_78, 0x78);

namespace PPFX {
class IGPUVolumeTexture {
public:
    u32 vf12();
    void vf13();
    u32 vf14();
    u32 vf15(u32 value);
    u32 vf16();
    u32 vf19();
    u32 vf20();
    u32 vf10();
    u32 vf11();
};
}  // namespace PPFX

// 0x7100447300
u32 PPFX::IGPUVolumeTexture::vf12() {
    const Unk_447300* self = reinterpret_cast<const Unk_447300*>(this);
    return self->field_80;
}

// 0x7100447310
void PPFX::IGPUVolumeTexture::vf13() {
}

// 0x7100447650
u32 PPFX::IGPUVolumeTexture::vf14() {
    Unk_447650* self = reinterpret_cast<Unk_447650*>(this);
    self->field_7c = 0xffffffff;
    return 0;
}

// 0x7100447660
u32 PPFX::IGPUVolumeTexture::vf15(u32 value) {
    Unk_447660* self = reinterpret_cast<Unk_447660*>(this);
    if (value > 0xf) {
        return 0xfffffffa;
    }
    self->field_78 = value;
    return 0;
}

// 0x7100447680
u32 PPFX::IGPUVolumeTexture::vf16() {
    const Unk_447680* self = reinterpret_cast<const Unk_447680*>(this);
    return self->field_78;
}

// 0x71004476c0
u32 PPFX::IGPUVolumeTexture::vf19() {
    const Unk_4476c0* self = reinterpret_cast<const Unk_4476c0*>(this);
    return self->field_78 & 3;
}

// 0x7100447700
u32 PPFX::IGPUVolumeTexture::vf20() {
    const Unk_447700* self = reinterpret_cast<const Unk_447700*>(this);
    return (self->field_78 >> 2) & 3;
}

// 0x7100448680
u32 PPFX::IGPUVolumeTexture::vf10() {
    return 0xfffffffc;
}

// 0x7100448690
u32 PPFX::IGPUVolumeTexture::vf11() {
    return 0;
}
