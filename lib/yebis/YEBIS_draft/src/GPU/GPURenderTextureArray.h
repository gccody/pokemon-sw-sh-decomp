// PPFX::CRenderTextureArray (RTTI; C:/workspace/YEBIS_draft/src/GPU/GPURenderTextureArray.cpp
// is the __FILE__ of its allocations): a chain of render textures and the
// device objects that go with it. Placeholder members.
#pragma once

#include <yebis/YEBIS_draft/src/GPU/GPURenderTexture.h>

namespace PPFX {

class CRenderTextureArray : public CGPUResourceManage {
public:
    explicit CRenderTextureArray(const char* name);  // 0x71004a4660
    s32 vf0(IGPUDevice* device) override;            // 0x71004a47e0
    s32 vf1() override;                              // 0x71004a52a0
    s32 vf2() override;                              // 0x71004a5460
    s32 vf3() override;                              // 0x71004a54b0
    ~CRenderTextureArray() override;                 // 0x71004a4760, 0x71004a47a0

    s32 Unk_4a46a0(const char* name);  // 0x71004a46a0
    // 0x71004a5f50: a texture's (-1: the current one's, 0x7fffffff: every texture's) two values
    s32 Unk_4a5f50(s32 index, f32 a, f32 b);
    // 0x71004a5ff0: a texture's field_a0, likewise
    s32 Unk_4a5ff0(s32 value, s32 index);

    u32 _2c;       // nothing here uses it (the base's last member ends at 0x29)
    s32 field_30;  // the number of textures
    s32 field_34;
    CRenderTexture** field_38;
    CRenderTexture** field_40;
    u32 field_48;
    s32 field_4c;
    Unk_49b230_Object* field_50;
    Unk_49b230_Object* field_58;
    Unk_49b230_Object* field_60;
    Unk_49b230_Object* field_68;
    Unk_49b230_Object* field_70;
    Unk_49b230_Object* field_78;
    CGPUBaseResourceManage* field_80;
    CGPUBaseResourceManage* field_88;
    s32 field_90;  // the current texture
    s32 field_94;
};
PKMN_OFFSET_ASSERT(CRenderTextureArray, field_30, 0x30);
PKMN_SIZE_ASSERT(CRenderTextureArray, 0x98);

}  // namespace PPFX
