// SiSDK3::SiGfxNXFreeTypeManager (RTTI names the class; it derives from
// SiGfxFreeTypeManager, which is on ISiInterface): the FreeType manager of
// the NVN back end, which adds the shader program, the vertex format and the
// index buffer its text is drawn with. A placeholder file name for the
// header (its translation unit is SiGfx_NX_FreeType_Manager.cpp, the
// __FILE__ of its allocations) and placeholder members; the virtual
// functions are vf<slot>.
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_4bf660.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_Buffer_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_VertexFormat_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/Unk_NXResource.h>

namespace SiSDK3 {

// SiGfxFreeTypeManager as its NVN class uses it (its own header is its
// translation unit's, which isn't written): its constructor and destructor,
// its slots, and the device it keeps.
class SiGfxFreeTypeManager {
public:
    explicit SiGfxFreeTypeManager(SiGfxNXDevice* pDevice);  // 0x710050aee0
    virtual ~SiGfxFreeTypeManager();                        // 0x710050af80
    virtual u32 vf2();
    virtual u32 vf3();
    virtual u32 vf4();
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

    Unk_4bf660 field_8;
    SiGfxNXDevice* field_18;
    u8 field_20[0x38];
};
PKMN_SIZE_ASSERT(SiGfxFreeTypeManager, 0x58);

// What the manager holds two of, as it releases them (placeholder name).
class Unk_551300_Object {
public:
    virtual void vf0();
    virtual void vf1();
    virtual u32 vf2();
    virtual u32 vf3();
};

class SiGfxNXFreeTypeManager : public SiGfxFreeTypeManager {
public:
    explicit SiGfxNXFreeTypeManager(SiGfxNXDevice* pDevice);  // 0x7100551300
    ~SiGfxNXFreeTypeManager() override;                       // 0x7100551340, 0x71005513c0
    void vf5() override;                                      // 0x7100551450
    void vf6() override;                                      // 0x7100551460: releases what it made
    void vf7() override;                                      // 0x7100551770: makes it
    void vf8() override;                                      // 0x71005517b0
    void vf9() override;                                      // 0x7100551810
    void vf10() override;                                     // 0x7100551820
    void vf11() override;                                     // 0x7100551830
    void vf12() override;                                     // 0x7100551840

    // 0x71005514c0: makes the vertex format and the index buffer
    bool Unk_5514c0();

    void* field_58;  // the device's shader program 0x44
    u32 field_60;
    SiGfxNXBuffer* field_68;        // the quads' indices
    SiGfxNXVertexFormat* field_70;  // the vertices' format
};
PKMN_SIZE_ASSERT(SiGfxNXFreeTypeManager, 0x78);

}  // namespace SiSDK3
