// Scope: common
// PPFX::CRenderGlare (C:/workspace/YEBIS_draft/src/GPU/GPURenderGlare.cpp, the
// __FILE__ of its log lines).
#include <math.h>

#include <yebis/YEBIS_draft/src/GPU/Unk_Statics.h>
#include <yebis/YEBIS_draft/src/GPU/GPUClassUtil.h>
#include <yebis/YEBIS_draft/src/GPU/GPURenderGlare.h>

#define PPFX_FILE "C:/workspace/YEBIS_draft/src/GPU/GPURenderGlare.cpp"
#include <yebis/YEBIS_draft/src/GPU/Unk_Log.h>

// 0x7101b3499c: "CRenderGlare"
extern const char Unk_1b3499c[];

// 0x71004a06e0, 0x71004a1010, 0x71004a15b0, 0x71004a0a30, 0x71004a2b80
void Unk_4a06e0();
void Unk_4a1010();
void Unk_4a15b0();
void Unk_4a0a30();
void Unk_4a2b80();

namespace PPFX {

// an object without members that CRenderGlare's constructor makes and its
// destructor deletes
struct Unk_24e6c68_Class {
    Unk_24e6c68_Class() {
        Unk_4a06e0();
        Unk_4a1010();
    }
    ~Unk_24e6c68_Class() {
        Unk_4a15b0();
        Unk_4a0a30();
        Unk_4a2b80();
    }
};

}  // namespace PPFX

// 0x71024e6c68
extern PPFX::Unk_24e6c68_Class* Unk_24e6c68;

namespace PPFX {

// 0x71004530b0
CRenderGlare::CRenderGlare(const char* name) : CGPUResourceManage(nullptr) {
#line 306
    Unk_24e6c68 = UNK_NEW(Unk_24e6c68_Class);
    Unk_4531d0(name);
}

// 0x71004531d0
s32 CRenderGlare::Unk_4531d0(const char* name) {
    if (name != nullptr && name[0] != '\0') {
        field_10 = Unk_TFXString(Unk_1b3499c) + " " + name;
    } else {
        field_10 = Unk_1b3499c;
    }
    Unk_Clear();
    return 0;
}

// 0x7100455750, 0x71004557d0 (deleting)
CRenderGlare::~CRenderGlare() {
    Unk_49ec80();
    UNK_DELETE(Unk_24e6c68);
}

// 0x7100455b00
s32 CRenderGlare::vf0(IGPUDevice* device) {
    s32 result = CGPUResourceManage::vf0(device);
    if (result < 0) {
        return result;
    }
    if (field_20 == nullptr) {
        return 0;
    }
    result = CreateDeviceResources();
    return result < 0 ? result : 0;
}

// 0x7100456190: lets go of the device's resources
s32 CRenderGlare::vf1() {
    field_2f0->vf1();
    field_318->vf1();
    field_398->vf1();
    if (field_3a0 != nullptr) {
        field_3a0->vf1();
    }
    if (field_3a8 != nullptr) {
        field_3a8->vf1();
    }
    if (field_3b0 != nullptr) {
        field_3b0->vf1();
    }
    if (field_3b8 != nullptr) {
        field_3b8->vf1();
    }
    s32 count = field_b0.field_18[5];
    for (s32 i = 0; i < count; i++) {
        field_310[i]->vf1();
    }
    if (field_328 != nullptr) {
        field_328->vf1();
    }
    if (field_330 != nullptr) {
        field_330->vf1();
    }
    if (field_338 != nullptr) {
        field_338->vf1();
    }
    if (field_340 != nullptr) {
        field_340->vf1();
    }
    if (field_390 != nullptr) {
        field_390->vf1();
    }
    if (field_350 != nullptr) {
        for (u32 i = 0; i < field_b0.field_4c; i++) {
            field_350[i]->vf1();
        }
    }
    if (field_3c0 != nullptr) {
        field_3c0->vf1();
    }
    if (field_3d0 != nullptr) {
        field_3d0->vf1();
    }
    if (field_3c8 != nullptr) {
        field_3c8->vf1();
    }
    PPFX_SAFE_RELEASE_INTERFACE(field_348);
    return CGPUResourceManage::vf1();
}

// 0x7100456380
s32 CRenderGlare::vf2() {
    s32 result = CGPUResourceManage::vf2();
    if (result < 0) {
        return result;
    }
    return Unk_455850() ? 0 : -1;
}

// 0x71004563c0
s32 CRenderGlare::vf3() {
    CTextureUtil* util = Unk_GetTextureUtil();
    Unk_ReleaseTextureUtil();
    UNK_DELETE(field_318);
    UNK_DELETE(field_398);
    UNK_DELETE(field_3a0);
    UNK_DELETE(field_3a8);
    UNK_DELETE(field_3b0);
    UNK_DELETE(field_3b8);
    UNK_DELETE(field_2f0);
    UNK_DELETE(field_328);
    UNK_DELETE(field_330);
    UNK_DELETE(field_338);
    UNK_DELETE(field_3c0);
    UNK_DELETE(field_3d0);
    UNK_DELETE(field_3c8);
    UNK_DELETE_ARRAY(field_1f8);
    UNK_DELETE_ARRAY(field_208);
    UNK_DELETE(field_340);
    UNK_DELETE(field_390);
    if (field_350 != nullptr) {
        for (u32 i = 0; i < field_b0.field_4c; i++) {
            UNK_DELETE(field_350[i]);
        }
        UNK_DELETE_ARRAY(field_350);
    }
    UNK_DELETE_ARRAY(field_358);
    s32 count = field_b0.field_18[5];
    for (s32 i = 0; i < count; i++) {
        UNK_DELETE(field_310[i]);
    }
    UNK_DELETE_ARRAY(field_310);
    UNK_DELETE_ARRAY(field_320);
    if (field_300 != nullptr) {
        Unk_49fc60(util->field_29a58, field_308, field_300);
        UNK_DELETE_ARRAY(field_300);
        field_308 = 0;
    }
    Unk_Clear();
    s32 result = CGPUResourceManage::vf3();
    return result < 0 ? result : 0;
}

}  // namespace PPFX

// 0x710045fbe0: _GLOBAL__sub_I_GPURenderGlare.cpp
