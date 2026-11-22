// SiSDK3::SiGfxNXCommandList as the command list pool and the command queue
// use it (a placeholder header: the class's own header is its translation
// unit's, which isn't written): its constructor, the function that makes its
// command buffer, its slot 16 (the handle of what it recorded), what it
// counted and how many times it's in use.
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/Unk_NXResource.h>

namespace SiSDK3 {

class SiGfxNXCommandList {
public:
    SiGfxNXCommandList(ISiAllocator* pAllocator, SiGfxNXDevice* pDevice, void* pPool);  // 0x7100539920
    virtual void vf0();
    virtual void vf1();
    virtual u32 vf2();
    virtual u32 vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual u64 vf16();
    bool Unk_53a000(u32 kind);  // 0x710053a000

    u8 field_8[0x11c];
    u32 field_124[10];  // what it counted, which the queue adds up
    s32 field_14c;      // how many times it's in use
    u8 field_150[0xa0];
};
PKMN_OFFSET_ASSERT(SiGfxNXCommandList, field_124, 0x124);
PKMN_SIZE_ASSERT(SiGfxNXCommandList, 0x1f0);

}  // namespace SiSDK3
