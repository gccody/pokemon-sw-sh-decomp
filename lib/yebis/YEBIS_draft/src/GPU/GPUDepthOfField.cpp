// Scope: common
// PPFX::CDepthOfField (lib/yebis/YEBIS_draft/src/GPU/GPUDepthOfField.h): so
// far its destructors and three small virtual functions. The TU has statics
// of its own besides the common ones (its static initialiser, 0x71004b72d0,
// is 716 bytes), so Unk_Statics.h isn't included until they're known.
#include <yebis/YEBIS_draft/src/GPU/GPUDepthOfField.h>

namespace PPFX {

// 0x71004aa790, 0x71004aa7d0
CDepthOfField::~CDepthOfField() {
    Unk_49ec80();
}

// 0x71004aa810
s32 CDepthOfField::vf0(IGPUDevice* device) {
    s32 result = CGPUResourceManage::vf0(device);
    if (result < 0)
        return result;
    if (field_20 == nullptr)
        return 0;
    result = Unk_4aa860();
    return result < 0 ? result : 0;
}

// 0x71004ac220
s32 CDepthOfField::vf1() {
    field_4a0->vf1();
    for (s32 i = 0; i < field_d0; i++) {
        Unk_Level* level = &field_4a8[i];
        if (field_124) {
            if (level->field_80 != nullptr)
                level->field_80->vf1();
            if (level->field_88 != nullptr)
                level->field_88->vf1();
        } else {
            level->field_a0->vf1();
        }
        for (s32 j = 0; j < field_180; j++) {
            if (level->field_48[j] != nullptr)
                level->field_48[j]->vf1();
        }
        if (level->field_a8 != nullptr && level->field_a8 != level->field_48[0]) {
            if (field_124) {
                if (level->field_90 != nullptr)
                    level->field_90->vf1();
                if (level->field_98 != nullptr)
                    level->field_98->vf1();
            } else {
                level->field_a8->vf1();
            }
        }
        if (level->field_b0 != nullptr)
            level->field_b0->vf1();
        if (level->field_b8 != nullptr)
            level->field_b8->vf1();
    }
    return CGPUResourceManage::vf1();
}

// 0x71004ac3a0
s32 CDepthOfField::vf2() {
    s32 result = CGPUResourceManage::vf2();
    if (result < 0)
        return result;
    if (Unk_4a7390(field_228, field_c0) < 0)
        return -1;
    for (s32 i = 0; i < field_d0; i++) {
        if (field_4a8[i].field_a0->field_2c.field_c == 0)
            return -1;
    }
    return 0;
}

}  // namespace PPFX
