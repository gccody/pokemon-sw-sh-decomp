// Scope: common
// PPFX::CGPUResourceManage (lib/yebis/YEBIS_draft/src/GPU/GPUResourceManage.h):
// C:/workspace/YEBIS_draft/src/GPU/GPUResourceManage.cpp is the __FILE__ of
// its warnings and of its list's allocation. Its vf2 and vf3 are in
// lib/yebis/class. The TU's statics are the ones every src/GPU TU has
// (Unk_Statics.h), which its static initialiser, 0x710049f3e0, sets up.
#include <string.h>

#include <algorithm>
#include <vector>

#include <yebis/YEBIS_draft/src/GPU/GPUMemoryAllocator.h>
#include <yebis/YEBIS_draft/src/GPU/GPUResourceManage.h>
#include <yebis/YEBIS_draft/src/GPU/Unk_Statics.h>

#define UNK_WARNING(message) UNK_PPFX_WARNING("C:/workspace/YEBIS_draft/src/GPU/GPUResourceManage.cpp", message)

// 0x71024e55a8: how many use the device (lib/yebis/leaf reads it by this name)
s32 Unk_24e55a8;

namespace PPFX {

typedef std::vector<CGPUResourceManage*, Unk_StlAllocator<CGPUResourceManage*>> Unk_ManageList;

// 0x7101b614b8: the class's name
extern const char Unk_1b614b8[];
const char Unk_1b614b8[] = "CGPUResourceManage";
// 0x71024e55b0: the device; 0x71024e55b8: who uses it
extern IGPUDevice* Unk_24e55b0;
extern Unk_ManageList* Unk_24e55b8;
IGPUDevice* Unk_24e55b0;
Unk_ManageList* Unk_24e55b8;

#line 296
static inline void Unk_NewList() {
    Unk_24e55a8 = 0;
    Unk_24e55b8 = UNK_NEW(Unk_ManageList);
}

// 0x710049eb30
CGPUResourceManage::CGPUResourceManage(const char* name) {
    Unk_49eb80(name);
}

// 0x710049eb80
s32 CGPUResourceManage::Unk_49eb80(const char* name) {
    field_28 = false;
    if (name != nullptr && name[0] != '\0')
        field_10 = Unk_TFXString(Unk_1b614b8) + " " + name;
    else
        field_10 = Unk_1b614b8;
    field_20 = nullptr;
    return 0;
}

// 0x710049ec30
s32 CGPUResourceManage::Unk_49ec30(IGPUDevice* device) {
    if (device == nullptr)
        device = field_20;
    vf1();
    s32 result = vf0(device);
    return result < 0 ? result : 0;
}

// 0x710049ec80
s32 CGPUResourceManage::Unk_49ec80() {
    if (field_20 != nullptr) {
        s32 result = vf1();
        if (result < 0)
            return result;
    }
    s32 result = vf3();
    return result < 0 ? result : 0;
}

// 0x710049ecd0, 0x710049ed30
CGPUResourceManage::~CGPUResourceManage() {
    CGPUResourceManage::vf1();
    vf3();
}

// 0x710049ed90
s32 CGPUResourceManage::vf0(IGPUDevice* device) {
    if (field_20 == device)
        return 0;
    if (device == nullptr)
        device = field_20;
    field_20 = device;
    RegisterStaticGPUDevice(this, device);
    return 0;
}

// 0x710049edc0
s32 CGPUResourceManage::RegisterStaticGPUDevice(CGPUResourceManage* manage, IGPUDevice* device) {
    if (device == nullptr)
        return 0;
    if (Unk_24e55b0 == nullptr) {
        Unk_24e55b0 = device;
        Unk_NewList();
    } else if (Unk_24e55b0 != device) {
        char message[0x400];
        memset(message, 0, sizeof(message));
        strcat(message, "CGPUResourceManage::RegisterStaticGPUDevice():\n");
        strcat(message, "\tDiffurent device is already registered.\n");
        strcat(message, "\t");
        if (manage != nullptr)
            strcat(message, manage->field_10.field_8);
        strcat(message, " might not call UninitializeDevice().\n");
#line 378
        UNK_WARNING(message);
        Unk_24e55b0 = device;
        Unk_NewList();
    }
    Unk_ManageList* list = Unk_24e55b8;
    Unk_24e55a8++;
    if (std::find(list->begin(), list->end(), manage) != list->end()) {
        Unk_TFXString message = Unk_4529a0("\"", manage->field_10) + "\" is already registered.\n";
#line 402
        UNK_WARNING(message.field_8);
    }
    list->push_back(manage);
    manage->field_28 = true;
    return 0;
}

// 0x710049f080
s32 CGPUResourceManage::vf1() {
    if (field_20 != nullptr) {
        Unk_49f0b0(this);
        field_20 = nullptr;
    }
    return 0;
}

// 0x710049f0b0
s32 CGPUResourceManage::Unk_49f0b0(CGPUResourceManage* manage) {
    if (manage->field_20 == nullptr)
        return 0;
    Unk_24e55a8--;
    Unk_ManageList* list = Unk_24e55b8;
    Unk_ManageList::iterator it = std::find(list->begin(), list->end(), manage);
    if (it != list->end()) {
        list->erase(it);
    } else {
        Unk_TFXString message = Unk_4529a0("WORN: \"", manage->field_10) + "\" is not registered.\n";
#line 456
        UNK_WARNING(message.field_8);
    }
    manage->field_28 = false;
    if (Unk_24e55a8 <= 0) {
        Unk_24e55b0 = nullptr;
        Unk_24e55a8 = 0;
        UNK_DELETE(Unk_24e55b8);
    }
    return Unk_24e55a8;
}

}  // namespace PPFX
