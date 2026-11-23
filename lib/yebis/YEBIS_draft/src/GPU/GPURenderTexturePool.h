// PPFX::CRenderTexturePool (RTTI): the render textures PPFX's effects share,
// in a std::list. AllocateTextures is named by its log line; the other
// members are placeholders.
#pragma once

#include <list>

#include <yebis/YEBIS_draft/src/GPU/GPURenderTexture.h>

namespace PPFX {

class CRenderTexturePool : public CGPUResourceManage {
public:
    // A texture of the pool, and whether the pool made it
    struct Unk_Entry {
        bool field_0;
        CRenderTexture* field_8;
    };
    typedef std::list<Unk_Entry*, Unk_StlAllocator<Unk_Entry*>> Unk_List;

    explicit CRenderTexturePool(const char* name);  // 0x710049f650
    s32 vf0(IGPUDevice* device) override;           // 0x71004a0070
    s32 vf1() override;                             // 0x71004a0100
    s32 vf2() override;                             // 0x71004a0170
    s32 vf3() override;                             // 0x71004a0190
    ~CRenderTexturePool() override;                 // 0x710049ff40, 0x710049ffd0

    s32 Unk_49f6a0(const char* name);  // 0x710049f6a0
    // 0x710049f7b0: whether a texture is what's asked for
    static bool Unk_49f7b0(const CRenderTexture* texture, s32 width, s32 height, s32 format, u32 flags, u32 mask);
    // 0x710049f7f0: fills `textures` with `count` textures, shared ones first; returns how many it made
    s32 AllocateTextures(s32 count, CRenderTexture** textures, s32 width, s32 height, s32 format, bool shared,
                         u32 flags, u32 mask);
    // 0x710049fc10: one texture
    s32 Unk_49fc10(CRenderTexture** texture, s32 width, s32 height, s32 format, bool shared, u32 flags, u32 mask);
    // 0x710049fdf0: adds a texture made elsewhere
    void Unk_49fdf0(CRenderTexture* texture, bool front);
    // 0x710049fed0
    s32 Unk_49fed0(void* arg);

    Unk_List field_30;
};
PKMN_SIZE_ASSERT(CRenderTexturePool, 0x48);

}  // namespace PPFX

// 0x710049fc60: gives `count` textures back; returns how many it destroyed.
// It keeps the placeholder name its matched caller in lib/yebis/leaf has. The
// pool is a typed parameter: as a cast `void*` its list's end would be a
// bitcast, which InstCombine orders after a pointer phi in one compare.
s32 Unk_49fc60(PPFX::CRenderTexturePool* pool, u32 count, void* textures);
