// What PPFX's surfaces and textures hand ISiGfxTexture's slot 22 (its
// Create(), the log lines say) to make a SiGfx texture: 0x110 bytes, two
// strings among them (placeholder names and members). It is the description
// SiSDK3's NX texture reads (SiGfxNXTexture::Unk_Desc), as PPFX's code fills
// it in: 32-bit members at 8, 0xc, 0x28 and 0x2c, which PPFX's stores keep
// apart.
#pragma once

#include <types.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_String.h>

namespace PPFX {

struct Unk_SiGfxTextureCreateDesc {
    // the members a surface gives (placeholder parameters) or the defaults
    inline explicit Unk_SiGfxTextureCreateDesc(u32 format = 0, u32 width = 0, u32 height = 0, u32 a18 = 0, u32 a1c = 0,
                                               u32 a20 = 0, u32 a24 = 0, u32 a28 = 0, u32 a30 = 0, u32 a34 = 8,
                                               u32 a38 = 0, u32 a54 = 0,
                                               const void* a60 = nullptr)
        : field_0(format), field_4(0), field_8(0), field_c(0), field_10(width), field_14(height), field_18(a18),
          field_1c(a1c), field_20(a20), field_24(a24), field_28(a28), field_2c(0), field_30(a30), field_34(a34),
          field_38(a38), field_3c(0), field_40(0), field_44(0), field_50(0), field_54(a54), field_58(0), field_60(a60),
          field_68(0), field_70(0), field_78(1.0f), field_7c(0), field_80(0), field_84(0), field_e8(0), field_ec(-1),
          field_f0(-1) {
        field_f4 = Unk_Pair();
        field_fe = false;
        field_fc = false;
        field_fd = false;
        field_48 = 0;
        field_100 = -1;
        field_108 = -1;
    }

    // two numbers stored together (placeholder)
    struct Unk_Pair {
        Unk_Pair() : field_0(-1), field_4(0) {}
        s32 field_0;
        u32 field_4;
    };

    u32 field_0;  // the format
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u32 field_10;  // the width
    u32 field_14;  // the height
    u32 field_18;
    u32 field_1c;
    u32 field_20;
    u32 field_24;  // the multisampling
    u32 field_28;
    u32 field_2c;
    u32 field_30;
    u32 field_34;  // the views' flags (0x20: a render target's, 0x4000: a depth target's)
    u32 field_38;
    u32 field_3c;
    u32 field_40;
    u32 field_44;
    u64 field_48;
    u32 field_50;
    u32 field_54;
    u64 field_58;
    const void* field_60;
    u64 field_68;
    u64 field_70;
    f32 field_78;
    u32 field_7c;
    u32 field_80;
    u32 field_84;
    SiSDK3::SiString<char> field_88;
    SiSDK3::SiString<char> field_b8;
    u32 field_e8;
    s32 field_ec;
    s32 field_f0;
    Unk_Pair field_f4;
    bool field_fc;
    bool field_fd;
    bool field_fe;
    s64 field_100;
    s64 field_108;
};
PKMN_SIZE_ASSERT(Unk_SiGfxTextureCreateDesc, 0x110);
PKMN_OFFSET_ASSERT(Unk_SiGfxTextureCreateDesc, field_88, 0x88);
PKMN_OFFSET_ASSERT(Unk_SiGfxTextureCreateDesc, field_f4, 0xf4);

// the pixels of a level a description points to (placeholder; SiSDK3's NX
// texture has it as SiGfxNXTexture::Unk_LevelData)
struct Unk_SiGfxTextureLevelData {
    const void* field_0;
    u64 field_8;   // how many bytes
    u32 field_10;  // how many bytes a row is
    u32 field_14;
};
PKMN_SIZE_ASSERT(Unk_SiGfxTextureLevelData, 0x18);

}  // namespace PPFX
