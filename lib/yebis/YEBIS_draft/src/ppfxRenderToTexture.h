// PPFX::IPfxBaseRenderToTexture and PPFX::IPfxRenderToTexture_Nvn (RTTI), as
// ppfxRenderToTexture.cpp defines them, for the context that makes them
// (ppfx.cpp). Placeholder names.
#pragma once

#include <types.h>
#include <yebis/YEBIS_draft/src/Unk_4b9860.h>

// 0x71004b9840 (lib/yebis/leaf): what an interface holds at 0x10
struct Unk_4b9840;
const u8* Unk_4b9840_get(const Unk_4b9840* self);

namespace PPFX {

class CGPUBaseResourceManage;

class IPfxBaseRenderToTexture : public IPfxInterface {
public:
    IPfxBaseRenderToTexture() : field_18(nullptr) {}
    ~IPfxBaseRenderToTexture() override;  // 0x71004b9b60, 0x71004b9cd0
    // 0x71004b9d00 (its log lines name it): makes the render texture
    virtual s32 Initialize(void* context, s32 width, s32 height, s32 arg3, s32 format, s32 samples, s32 quality,
                           s32 arg7);
    virtual s32 Uninitialize();  // 0x71004ba140

    // 0x71004ba020
    s32 Initialize(void* context, CGPUBaseResourceManage* util);

    // what the interface holds (field_10), and what its context does
    CGPUBaseResourceManage** Unk_Util() {
        return reinterpret_cast<CGPUBaseResourceManage**>(
            const_cast<u8*>(Unk_4b9840_get(reinterpret_cast<const Unk_4b9840*>(this))));
    }

    void* field_18;  // the context
};
PKMN_SIZE_ASSERT(IPfxBaseRenderToTexture, 0x20);

// RTTI: PPFX::IPfxRenderToTexture_Nvn. Its deleting destructor is 0x71004ba2a0.
class IPfxRenderToTexture_Nvn : public IPfxBaseRenderToTexture {
public:
    ~IPfxRenderToTexture_Nvn() override {}
};

// 0x71004ba2d0: "IPfxRenderToTexture::Instantiate()" is the name its
// allocation is made under.
IPfxRenderToTexture_Nvn* Unk_4ba2d0();

}  // namespace PPFX
