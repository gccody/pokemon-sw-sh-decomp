// PPFX::CRenderTextureArray (RTTI; C:/workspace/YEBIS_draft/src/GPU/GPURenderTextureArray.cpp
// is the __FILE__ of its allocations): a chain of render textures and the
// device objects that go with it. Placeholder members.
#pragma once

#include <yebis/YEBIS_draft/src/GPU/GPURenderTexture.h>

namespace PPFX {

struct Unk_GPUTexture;
struct Unk_Float4;

class CRenderTextureArray : public CGPUResourceManage {
public:
    explicit CRenderTextureArray(const char* name);  // 0x71004a4660
    s32 vf0(IGPUDevice* device) override;            // 0x71004a47e0
    s32 vf1() override;                              // 0x71004a52a0
    s32 vf2() override;                              // 0x71004a5460
    s32 vf3() override;                              // 0x71004a54b0
    ~CRenderTextureArray() override;                 // 0x71004a4760, 0x71004a47a0

    s32 Unk_4a46a0(const char* name);  // 0x71004a46a0
    // 0x71004a5610 (its log lines name it): `count` textures from one description
    // (`same`) or one each, and the chain of mip textures for the first that
    // needs it (placeholder parameter names)
    s32 Initialize(s32 count, const Unk_49ab20_Desc* descs, s32 arg3, bool same, u32 flags);
    // 0x71004a5f50: a texture's (-1: the current one's, 0x7fffffff: every texture's) two values
    s32 Unk_4a5f50(s32 index, f32 a, f32 b);
    // 0x71004a5ff0: a texture's field_a0, likewise
    s32 Unk_4a5ff0(s32 value, s32 index);
    // 0x71004a6070: a texture (-1: the current one) as the device's target `slot`
    // 0x71004a6aa0 ("CRenderTextureArray::CopyToSurface()" in its log line):
    // draws a texture's rectangle into a surface
    static s32 CopyToSurface(Unk_49b230_Object* surface, Unk_GPUTexture* source, s32 index, f32 scale,
                             const Unk_Float4* rect, f32 u1, bool arg4, f32 v1, s32 arg5);
    // 0x71004a6a50: the same from a render texture's viewport
    static s32 Unk_4a6a50(Unk_49b230_Object* surface, CRenderTexture* source, s32 index, const Unk_Float4* rect,
                          bool arg4, s32 arg5, f32 scale);
    s32 Unk_4a6070(s32 index, bool depth, s32 arg2, void* arg3, s32 arg4, s32 slot, s32 arg6, s32 arg7, f32 arg8);
    // 0x71004a65a0: `count` textures from `source` on, weighted by `scale`,
    // drawn into `target`
    s32 Unk_4a65a0(s32 target, s32 source, u32 count, s32 index, bool flag, f32 scale);
    // a texture (-1: the current one; none past the last) (inline)
    CRenderTexture* Unk_Texture(s32 index) {
        if (index == -1)
            index = field_90;
        return index < field_30 ? field_38[index] : nullptr;
    }

    u32 field_2c;  // flags (Initialize's; bit 16: no 0x200 for the cleared textures)
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
