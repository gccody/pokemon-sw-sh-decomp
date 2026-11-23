// Scope: common
// SiSDK3::SiGfxNXPipelineState: its construction and destruction and the
// reference counts its header defines. (Its small accessors are
// lib/yebis/class's; the function that makes the NVN states isn't written
// yet.)
#define UNK_SIGFX_NX_PIPELINESTATE_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_PipelineState_Impl.h>

namespace SiSDK3 {

// 0x7100553180
// The colour targets' defaults are set twice: by their constructor, as the
// description is constructed (those stores die in the memset, but their
// addresses, computed before it, are what the later stores use: the ten
// `add x21, x19, #0x10c` before the memset), and in this loop, in the same
// order, which decides how their stores are merged.
SiGfxNXPipelineState::SiGfxNXPipelineState(ISiAllocator* pAllocator, SiGfxNXDevice* pDevice)
    : field_8(pAllocator), field_18(pDevice), field_20(0), field_6c8(0), field_6cc(0), field_6d0(0) {
    memset(&field_28, 0, sizeof(field_28));
    field_28.field_10 = 3;
    field_28.field_14 = 3;
    field_28.field_28 = false;
    field_28.field_2d = false;
    field_28.field_34 = false;
    field_28.field_35 = true;
    field_28.field_30 = 2;
    field_28.field_39 = 0xff;
    field_28.field_3a = 0xff;
    field_28.field_3c = 1;
    field_28.field_40 = 1;
    field_28.field_44 = 1;
    field_28.field_48 = 8;
    field_28.field_4c = 1;
    field_28.field_50 = 1;
    field_28.field_54 = 1;
    field_28.field_58 = 8;
    field_28.field_5c = false;
    field_28.field_5d = false;
    for (s32 i = 0; i < 8; i++) {
        field_28.field_60[i].field_0 = false;
        field_28.field_60[i].field_c = 1;
        field_28.field_60[i].field_4 = 2;
        field_28.field_60[i].field_8 = 1;
        field_28.field_60[i].field_18 = 1;
        field_28.field_60[i].field_10 = 2;
        field_28.field_60[i].field_14 = 1;
        field_28.field_60[i].field_1c[0] = 1;
        field_28.field_60[i].field_1c[1] = 1;
        field_28.field_60[i].field_1c[2] = 1;
        field_28.field_60[i].field_1c[3] = 1;
    }
}

// 0x7100553330 (D2), 0x7100553640 (D0)
SiGfxNXPipelineState::~SiGfxNXPipelineState() {
    Unk_553370(reinterpret_cast<Unk_553370_States*>(this));
}

}  // namespace SiSDK3
