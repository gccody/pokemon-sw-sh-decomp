// PPFX::CGPUResourceManage, the base of PPFX's GPU resource holders (RTTI:
// CRenderGlare, CTextureUtil, CRenderTexture, CRenderTexturePool,
// CRenderTextureArray, CDepthOfField, CTextureLuminance and
// CTextureLuminanceManage derive from it, and it from CGPUBaseResourceManage).
// RegisterStaticGPUDevice is named by its own log line; the other members are
// placeholders (vf<slot> for the virtual functions, as lib/yebis/class names
// them).
#pragma once

#include <types.h>
#include <yebis/YEBIS_draft/src/GPU/TinyEffect/TFXString.h>
#include <yebis/YEBIS_draft/src/GPU/Unk_Array.h>

// 0x7100417a30: printf to the log
s32 Unk_417a30(const char* format, ...);
// log switches: all messages, and the warnings
extern s32 Unk_238c1e0;
extern s32 Unk_238c1e4;

#define UNK_PPFX_WARNING(file, message)                                     \
    do {                                                                    \
        if (Unk_238c1e0 != 0 && Unk_238c1e4 != 0) {                         \
            Unk_417a30(file "(%d) : PPFX WARNING: ", __LINE__);             \
            Unk_417a30(message);                                            \
        }                                                                   \
    } while (0)

namespace PPFX {

class IGPUDevice;

// 0x71004529a0: a text, then a string
Unk_TFXString Unk_4529a0(const char* text, const Unk_TFXString& string);

// What the constructor sets before the class's own vtable: the base's members.
// Its vtable isn't in the executable (nothing but the inlined constructor
// would store it), so its virtual functions are the derived class's.
class CGPUBaseResourceManage {
public:
    CGPUBaseResourceManage() : field_8(1), field_c(true) {}
    virtual s32 vf0(IGPUDevice* device) = 0;
    virtual s32 vf1() = 0;
    virtual s32 vf2() = 0;
    virtual s32 vf3() = 0;
    virtual ~CGPUBaseResourceManage() {}

    // One reference less; the last one destroys the object (inline in its callers).
    s32 Unk_Release() {
        s32 count = --field_8;
        if (count == 0)
            Unk_Delete(Unk_238d5f8, this);
        return count;
    }

    // inline in its callers (the flag is converted where it's called)
    void Unk_SetC(bool value) { field_c = value; }

    s32 field_8;  // references
    bool field_c;
};

class CGPUResourceManage : public CGPUBaseResourceManage {
public:
    explicit CGPUResourceManage(const char* name);  // 0x710049eb30
    s32 vf0(IGPUDevice* device) override;           // 0x710049ed90: takes the device
    s32 vf1() override;                             // 0x710049f080: lets go of the device
    s32 vf2() override;                             // 0x710049f260
    s32 vf3() override;                             // 0x710049f270
    ~CGPUResourceManage() override;                 // 0x710049ecd0, 0x710049ed30

    // 0x710049eb80: names it "<class> <name>"
    s32 Unk_49eb80(const char* name);
    // 0x710049ec30: vf1, then vf0 with the device (the current one if null)
    s32 Unk_49ec30(IGPUDevice* device);
    // 0x710049ec80: vf1 if it has a device, then vf3
    s32 Unk_49ec80();
    // 0x710049edc0: adds `manage` to the users of the one device
    static s32 RegisterStaticGPUDevice(CGPUResourceManage* manage, IGPUDevice* device);
    // 0x710049f0b0: removes it; returns how many are left
    static s32 Unk_49f0b0(CGPUResourceManage* manage);

    Unk_TFXString field_10;  // name
    IGPUDevice* field_20;
    bool field_28;  // registered
};
PKMN_SIZE_ASSERT(CGPUResourceManage, 0x30);

}  // namespace PPFX
