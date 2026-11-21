// PPFX::CDepthOfField (RTTI; C:/workspace/YEBIS_draft/src/GPU/GPUDepthOfField.cpp
// is the __FILE__ of its allocations): the depth of field's levels and their
// render textures. Placeholder members, as far as the functions written so
// far read them.
#pragma once

#include <yebis/YEBIS_draft/src/GPU/GPURenderTexturePool.h>

namespace PPFX {

class CDepthOfField : public CGPUResourceManage {
public:
    // a level's render textures (0x108 bytes)
    struct Unk_Level {
        u8 _0[0x48];
        CRenderTexture* field_48[7];
        CRenderTexture* field_80;
        CRenderTexture* field_88;
        CRenderTexture* field_90;
        CRenderTexture* field_98;
        CRenderTexture* field_a0;
        CRenderTexture* field_a8;
        CRenderTexture* field_b0;
        CRenderTexture* field_b8;
        u8 _c0[0x108 - 0xc0];
    };

    s32 vf0(IGPUDevice* device) override;  // 0x71004aa810
    s32 vf1() override;                    // 0x71004ac220
    s32 vf2() override;                    // 0x71004ac3a0
    s32 vf3() override;                    // 0x71004ac430
    ~CDepthOfField() override;             // 0x71004aa790, 0x71004aa7d0

    // 0x71004a7390: whether a description fits the source
    static s32 Unk_4a7390(void* source, void* desc);
    s32 Unk_4aa860();  // 0x71004aa860: makes the levels' textures

    u8 _29[0xc0 - 0x29];  // from the end of the base's members
    u8 field_c0[0x10];  // the description
    s32 field_d0;       // the number of levels
    u8 _d4[0x124 - 0xd4];
    bool field_124;
    u8 _125[0x180 - 0x125];
    s32 field_180;  // the number of a level's field_48
    u8 _184[0x228 - 0x184];
    void* field_228;
    u8 _230[0x4a0 - 0x230];
    CRenderTexturePool* field_4a0;
    Unk_Level* field_4a8;
};
PKMN_SIZE_ASSERT(CDepthOfField::Unk_Level, 0x108);
PKMN_OFFSET_ASSERT(CDepthOfField, field_c0, 0xc0);
PKMN_OFFSET_ASSERT(CDepthOfField, field_d0, 0xd0);
PKMN_OFFSET_ASSERT(CDepthOfField, field_124, 0x124);
PKMN_OFFSET_ASSERT(CDepthOfField, field_180, 0x180);
PKMN_OFFSET_ASSERT(CDepthOfField, field_228, 0x228);
PKMN_OFFSET_ASSERT(CDepthOfField, field_4a8, 0x4a8);

}  // namespace PPFX
