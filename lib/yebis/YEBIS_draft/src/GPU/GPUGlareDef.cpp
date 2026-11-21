// Scope: common
// PPFX's glare definitions (lib/yebis/YEBIS_draft/src/GPU/GPUGlareDef.h).
#include <string.h>

#include <yebis/YEBIS_draft/src/GPU/GPUGlareDef.h>
#include <yebis/YEBIS_draft/src/GPU/Unk_Array.h>

namespace PPFX {

// 0x71004a0540
s32 Unk_4a0540::Unk_4a0540_Copy(const Unk_4a0540& other) {
    if (&other == this)
        return 0;
    Unk_4a0680();
    memmove(static_cast<Unk_4a0540_Base*>(this), &other, sizeof(Unk_4a0540_Base));
    if (other.field_20 != nullptr) {
#line 245
        field_20 = UNK_NEW_ARRAY(Unk_4a0540_Line, field_8);
        for (s32 i = 0; i < field_8; i++)
            field_20[i] = other.field_20[i];
    }
    return 0;
}

// 0x71004a0680
void Unk_4a0540::Unk_4a0680() {
    UNK_DELETE_ARRAY(field_20);
    Unk_Clear();
}

// 0x71004a0bb0
Unk_4a0540& Unk_4a0540::operator=(const Unk_4a0540& other) {
    if (&other == this)
        return *this;
    Unk_4a0680();
    memmove(static_cast<Unk_4a0540_Base*>(this), &other, sizeof(Unk_4a0540_Base));
    if (other.field_20 != nullptr) {
#line 245
        field_20 = UNK_NEW_ARRAY(Unk_4a0540_Line, field_8);
        for (s32 i = 0; i < field_8; i++)
            field_20[i] = other.field_20[i];
    }
    return *this;
}

}  // namespace PPFX
