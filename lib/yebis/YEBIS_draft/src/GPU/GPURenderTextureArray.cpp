// Scope: common
// PPFX::CRenderTextureArray (lib/yebis/YEBIS_draft/src/GPU/GPURenderTextureArray.h).
// The TU's statics are the ones every src/GPU TU has (Unk_Statics.h), which
// its static initialiser, 0x71004a6de0 (_GLOBAL__sub_I_GPURenderTextureArray.cpp),
// sets up.
#include <yebis/YEBIS_draft/src/GPU/GPURenderTextureArray.h>
#include <yebis/YEBIS_draft/src/GPU/Unk_Statics.h>

// one reference less, and the pointer cleared
#define UNK_RELEASE(object)        \
    do {                           \
        if ((object) != nullptr) { \
            (object)->vf1();       \
            (object) = nullptr;    \
        }                          \
    } while (0)
#define UNK_RELEASE_COUNTED(object)   \
    do {                              \
        if ((object) != nullptr) {    \
            (object)->Unk_Release();  \
            (object) = nullptr;       \
        }                             \
    } while (0)

// 0x710049afc0: a render texture's two values (lib/yebis/leaf)
struct Unk_49afc0;
u32 Unk_49afc0_update(Unk_49afc0* self, f32 fvalue, f32 farg1);

namespace PPFX {

// 0x7101eba12c: the class's name
extern const char Unk_1eba12c[];
const char Unk_1eba12c[] = "CRenderTextureArray";

// 0x71004a4660
CRenderTextureArray::CRenderTextureArray(const char* name) : CGPUResourceManage(nullptr) {
    Unk_4a46a0(name);
}

// 0x71004a46a0
s32 CRenderTextureArray::Unk_4a46a0(const char* name) {
    if (name != nullptr && name[0] != '\0')
        field_10 = Unk_TFXString(Unk_1eba12c) + " " + name;
    else
        field_10 = Unk_1eba12c;
    field_30 = 0;
    field_34 = 0;
    field_38 = nullptr;
    field_40 = nullptr;
    field_48 = 0;
    field_4c = 0;
    field_50 = nullptr;
    field_58 = nullptr;
    field_60 = nullptr;
    field_68 = nullptr;
    field_70 = nullptr;
    field_78 = nullptr;
    field_80 = nullptr;
    field_88 = nullptr;
    field_90 = 0;
    field_94 = 0;
    return 0;
}

// 0x71004a4760, 0x71004a47a0
CRenderTextureArray::~CRenderTextureArray() {
    Unk_49ec80();
}

// 0x71004a52a0
s32 CRenderTextureArray::vf1() {
    for (s32 i = 0; i < field_30; i++) {
        if (field_38[i] != nullptr)
            field_38[i]->vf1();
    }
    for (s32 i = 0; i < field_34; i++)
        field_40[i]->vf1();
    UNK_RELEASE(field_50);
    UNK_RELEASE(field_70);
    UNK_RELEASE(field_58);
    UNK_RELEASE(field_78);
    UNK_RELEASE_COUNTED(field_80);
    UNK_RELEASE(field_60);
    UNK_RELEASE_COUNTED(field_88);
    UNK_RELEASE(field_68);
    field_4c = 0;
    field_94 = 0;
    return CGPUResourceManage::vf1();
}

// 0x71004a5460
s32 CRenderTextureArray::vf2() {
    s32 result = CGPUResourceManage::vf2();
    if (result < 0)
        return result;
    if (field_30 == 0)
        return -1;
    return field_38 == nullptr ? -1 : 0;
}

// 0x71004a54b0
s32 CRenderTextureArray::vf3() {
    for (s32 i = 0; i < field_30; i++) {
        UNK_RELEASE_COUNTED(field_38[i]);
        if (field_40 != nullptr)
            UNK_RELEASE_COUNTED(field_40[i]);
    }
    UNK_DELETE_ARRAY(field_38);
    UNK_DELETE_ARRAY(field_40);
    field_90 = 0;
    field_94 = 0;
    field_30 = 0;
    field_34 = 0;
    field_48 = 0;
    field_4c = 0;
    s32 result = CGPUResourceManage::vf3();
    return result < 0 ? result : 0;
}

// 0x71004a5f50
s32 CRenderTextureArray::Unk_4a5f50(s32 index, f32 a, f32 b) {
    if (index == -1) {
        index = field_90;
    } else if (index == 0x7fffffff) {
        for (s32 i = 0; i < field_30; i++) {
            if (field_38[i] != nullptr)
                Unk_49afc0_update(reinterpret_cast<Unk_49afc0*>(field_38[i]), a, b);
        }
        return 0;
    }
    Unk_49afc0_update(reinterpret_cast<Unk_49afc0*>(field_38[index]), a, b);
    return 0;
}

// 0x71004a5ff0
s32 CRenderTextureArray::Unk_4a5ff0(s32 value, s32 index) {
    if (index == -1) {
        index = field_90;
    } else if (index == 0x7fffffff) {
        for (s32 i = 0; i < field_30; i++) {
            if (field_38[i] != nullptr)
                field_38[i]->Unk_SetA0(value);
        }
        return 0;
    }
    field_38[index]->Unk_SetA0(value);
    return 0;
}

}  // namespace PPFX
