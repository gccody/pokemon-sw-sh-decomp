// SiGfx's NX resource pools (RTTI names the classes), as far as their small
// functions and the device that makes them show them: a placeholder file for
// the twelve, whose own headers' names aren't known. Eleven derive from
// SiGfxResourcePool and add the device; the shader programs' derives from
// SiGfxShaderProgramPoolBase.
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_String.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/SiGfx_ResourcePool.h>

namespace SiSDK3 {

class SiGfxNXDevice;

#define UNK_NX_POOL(Class)                             \
    class Class : public SiGfxResourcePool {           \
    public:                                            \
        explicit Class(SiGfxNXDevice* pDevice);        \
        ~Class() override;                             \
        bool vf5(s32 count) override;                  \
        void vf6() override;                           \
                                                       \
        SiGfxNXDevice* field_178;                      \
    };                                                 \
    PKMN_SIZE_ASSERT(Class, 0x180)

UNK_NX_POOL(SiGfxNXSurfacePool);
UNK_NX_POOL(SiGfxNXTexturePool);
UNK_NX_POOL(SiGfxNXCanvasPool);
UNK_NX_POOL(SiGfxNXRenderTargetPool);
UNK_NX_POOL(SiGfxNXVolumePool);
UNK_NX_POOL(SiGfxNXVertexFormatPool);
UNK_NX_POOL(SiGfxNXShaderPool);
UNK_NX_POOL(SiGfxNXFontPool);
UNK_NX_POOL(SiGfxNXBufferPool);
UNK_NX_POOL(SiGfxNXQueryPool);
UNK_NX_POOL(SiGfxNXSamplerPool);
#undef UNK_NX_POOL

// The shader programs' pool's base: its constructor (0x7100535080) takes the
// device too.
class SiGfxShaderProgramPoolBase {
public:
    explicit SiGfxShaderProgramPoolBase(SiGfxNXDevice* pDevice);
    virtual ~SiGfxShaderProgramPoolBase();
    virtual u32 vf2();
    virtual u32 vf3();
    virtual void vf4();
    virtual bool vf5(s32 count);

    u8 field_8[0x180];
    SiString<char> field_188;
    SiString<char> field_1b8;
    u8 field_1e8[0x60];
};
PKMN_SIZE_ASSERT(SiGfxShaderProgramPoolBase, 0x248);

class SiGfxNXShaderProgramPool : public SiGfxShaderProgramPoolBase {
public:
    explicit SiGfxNXShaderProgramPool(SiGfxNXDevice* pDevice);
    ~SiGfxNXShaderProgramPool() override;

    void* field_248;
    u64 field_250;
};
PKMN_SIZE_ASSERT(SiGfxNXShaderProgramPool, 0x258);

}  // namespace SiSDK3
