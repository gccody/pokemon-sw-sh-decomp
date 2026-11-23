// ../src/GPU\GPUClassUtil.h (the __FILE__ of its allocation): the texture
// utilities every GPU class shares, counted by their users. The functions'
// names are placeholders.
#pragma once

#include <yebis/YEBIS_draft/src/GPU/GPUTextureUtil.h>

namespace PPFX {

// 0x71024e0c28, 0x71024e0c30: the users, and the object
extern s32 Unk_24e0c28;
extern CTextureUtil* Unk_24e0c30;

// the shared object, made for its first user (the count's increment wraps:
// the code after it still tests whether the count is over 1)
inline CTextureUtil* Unk_GetTextureUtil() {
    if (Unk_24e0c28 < 1) {
#line 73
        Unk_24e0c30 = UNK_NEW(CTextureUtil)(nullptr);
        Unk_24e0c28 = 1;
        return Unk_24e0c30;
    }
    CTextureUtil* instance = Unk_24e0c30;
    Unk_24e0c28 = static_cast<u32>(Unk_24e0c28) + 1;
    return instance;
}

// a user less; deletes the object with the last
inline void Unk_ReleaseTextureUtil() {
    if (Unk_24e0c28 <= 1) {
        UNK_DELETE(Unk_24e0c30);
        Unk_24e0c28 = 0;
    } else {
        Unk_24e0c28--;
    }
}

// the same, given the object Unk_GetTextureUtil returned (what is deleted is
// that pointer: BeginPostEffectScene keeps the object's read for it)
inline void Unk_ReleaseTextureUtil(CTextureUtil* instance) {
    if (Unk_24e0c28 <= 1) {
        if (instance != nullptr) {
            Unk_Delete(Unk_238d5f8, instance);
            Unk_24e0c30 = nullptr;
        }
        Unk_24e0c28 = 0;
    } else {
        Unk_24e0c28--;
    }
}

}  // namespace PPFX
