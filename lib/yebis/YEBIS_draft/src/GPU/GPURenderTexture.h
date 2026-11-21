// PPFX::CRenderTexture (RTTI; C:/workspace/YEBIS_draft/src/GPU/GPURenderTexture.cpp
// is the __FILE__ of its allocations): a render target and its description.
// Placeholder members.
#pragma once

#include <vector>

#include <yebis/YEBIS_draft/src/GPU/GPUMemoryAllocator.h>
#include <yebis/YEBIS_draft/src/GPU/GPUResourceManage.h>

namespace PPFX {

// What a render texture is made from. 0x21 bytes of members in 0x24: it has
// a constructor, so a copy leaves the padding alone.
struct Unk_49ab20_Desc {
    Unk_49ab20_Desc()
        : field_0(0), field_4(0), field_8(0), field_c(0), field_10(1), field_14(0), field_18(0), field_1c(0),
          field_20(false) {}
    Unk_49ab20_Desc(u32 flags, s32 width, s32 height, s32 format)
        : field_0(flags), field_4(width), field_8(height), field_c(format), field_10(1), field_14(0), field_18(0),
          field_1c(0), field_20(false) {}

    u32 field_0;  // flags
    s32 field_4;  // width
    s32 field_8;  // height
    s32 field_c;  // format
    s32 field_10;
    s32 field_14;
    s32 field_18;
    s32 field_1c;
    bool field_20;
};
PKMN_SIZE_ASSERT(Unk_49ab20_Desc, 0x24);

class CRenderTexture : public CGPUResourceManage {
public:
    explicit CRenderTexture(const char* name);  // 0x710049a9c0
    s32 vf0(IGPUDevice* device) override;       // 0x710049b080
    s32 vf1() override;                         // 0x710049c0b0
    s32 vf2() override;                         // 0x710049c610
    s32 vf3() override;                         // 0x710049c640
    ~CRenderTexture() override;                 // 0x710049afd0, 0x710049b020
    virtual s32 vf6();                          // 0x710049bb30

    s32 Unk_49aa20(const char* name);            // 0x710049aa20
    s32 Unk_49ab20(const Unk_49ab20_Desc* desc);  // 0x710049ab20: (re)creates it
    // inline in its callers (its description sits above their own locals)
    s32 Unk_Create(u32 flags, s32 width, s32 height, s32 format) {
        Unk_49ab20_Desc desc(flags, width, height, format);
        return Unk_49ab20(&desc);
    }

    Unk_49ab20_Desc field_2c;
    s32 field_50;
    s32 field_54;  // the width and height it has
    s32 field_58;
    u8 _5c[0x108 - 0x5c];
    std::vector<void*, Unk_StlAllocator<void*>> field_108;
    u64 field_120;
};
PKMN_OFFSET_ASSERT(CRenderTexture, field_2c, 0x2c);
PKMN_OFFSET_ASSERT(CRenderTexture, field_54, 0x54);
PKMN_SIZE_ASSERT(CRenderTexture, 0x128);

}  // namespace PPFX
