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
class SiGfxNXShaderProgram;

#define UNK_NX_POOL_WITH(Class, Extra)                 \
    class Class : public SiGfxResourcePool {           \
    public:                                            \
        explicit Class(SiGfxNXDevice* pDevice);        \
        ~Class() override;                             \
        bool vf5(s32 count) override;                  \
        void vf6() override;                           \
        Extra                                          \
                                                       \
        SiGfxNXDevice* field_178;                      \
    };                                                 \
    PKMN_SIZE_ASSERT(Class, 0x180)
#define UNK_NX_POOL(Class) UNK_NX_POOL_WITH(Class, )
// the pools that make resources of their own when the device asks for it
// (slot 7, before the base's: 0x7100537000 and 0x710055d900 make them)
#define UNK_NX_POOL_VF7(Make) \
    void vf7() override;      \
    void Make();

UNK_NX_POOL(SiGfxNXSurfacePool);
UNK_NX_POOL_WITH(SiGfxNXTexturePool, UNK_NX_POOL_VF7(Unk_55d900));
UNK_NX_POOL(SiGfxNXCanvasPool);
UNK_NX_POOL(SiGfxNXRenderTargetPool);
UNK_NX_POOL(SiGfxNXVolumePool);
UNK_NX_POOL_WITH(SiGfxNXVertexFormatPool, UNK_NX_POOL_VF7(Unk_563a40));
UNK_NX_POOL(SiGfxNXShaderPool);
UNK_NX_POOL_WITH(SiGfxNXFontPool, UNK_NX_POOL_VF7(Unk_4fe990));
UNK_NX_POOL_WITH(SiGfxNXBufferPool, UNK_NX_POOL_VF7(Unk_537000));
UNK_NX_POOL(SiGfxNXQueryPool);
UNK_NX_POOL(SiGfxNXSamplerPool);
#undef UNK_NX_POOL
#undef UNK_NX_POOL_WITH
#undef UNK_NX_POOL_VF7

// The shader programs' pool's base (RTTI: it derives from SiGfxResourcePool,
// and its functions are in SiGfx_ResourcePool.cpp's translation unit): its
// constructor (0x7100535080) takes the device too.
class SiGfxShaderProgramPoolBase : public SiGfxResourcePool {
public:
    // The pool's own programs' shaders (placeholder name): eleven references,
    // released by 0x7100535380.
    struct Unk_Shaders {
        Unk_Shaders() {
            for (int i = 0; i < 11; i++) {
                field_0[i] = nullptr;
            }
        }
        ~Unk_Shaders() { Unk_535380(); }
        void Unk_535380();

        Unk_534460_Resource* field_0[11];
    };
    // One more reference that its destructor releases (placeholder name).
    struct Unk_Ref {
        Unk_Ref() : field_0(nullptr) {}
        ~Unk_Ref() { Unk_Release(); }
        void Unk_Release() {
            if (field_0 != nullptr) {
                field_0->vf3();
                field_0 = nullptr;
            }
        }

        Unk_534460_Resource* field_0;
    };

    explicit SiGfxShaderProgramPoolBase(SiGfxNXDevice* pDevice);
    ~SiGfxShaderProgramPoolBase() override;
    bool vf5(s32 count) override;  // 0x7100535310
    void vf6() override;           // 0x7100535330: releases the programs
    void vf7() override;           // 0x71005354b0
    virtual void* vf14();          // 0x7100535540
    // gives a program the item of an index
    virtual void vf15(SiGfxNXShaderProgram* program, size_t index) = 0;
    virtual bool vf16();  // 0x7100535550: makes the pool's own programs
    virtual bool vf17();  // 0x7100536000: and its debug programs
    virtual void vf18();  // 0x71005362b0: makes them again
    virtual void vf19();  // 0x7100536320

    // what vf6, vf18, vf19 and the destructor release first (inline:
    // placeholder name)
    void Unk_ReleaseShaders() {
        field_1e8.Unk_535380();
        field_240.Unk_Release();
    }

    SiGfxNXDevice* field_178;
    bool field_180;
    u32 field_184;
    SiString<char> field_188;
    SiString<char> field_1b8;
    Unk_Shaders field_1e8;
    Unk_Ref field_240;
};
PKMN_OFFSET_ASSERT(SiGfxShaderProgramPoolBase, field_178, 0x178);
PKMN_OFFSET_ASSERT(SiGfxShaderProgramPoolBase, field_1e8, 0x1e8);
PKMN_SIZE_ASSERT(SiGfxShaderProgramPoolBase, 0x248);

class SiGfxNXShaderProgramPool : public SiGfxShaderProgramPoolBase {
public:
    explicit SiGfxNXShaderProgramPool(SiGfxNXDevice* pDevice);
    ~SiGfxNXShaderProgramPool() override;  // 0x71005597d0, 0x7100559820
    bool vf5(s32 count) override;          // 0x7100559880
    void vf6() override;                   // 0x71005598a0
    void vf7() override;                   // 0x7100559b60
    void vf15(SiGfxNXShaderProgram* program, size_t index) override;  // 0x7100559ac0

    // 0x7100559bf0: the special shader effect's copy program
    bool Unk_559bf0(s32* index);

    void* field_248;
    u64 field_250;
};
PKMN_SIZE_ASSERT(SiGfxNXShaderProgramPool, 0x258);

}  // namespace SiSDK3
