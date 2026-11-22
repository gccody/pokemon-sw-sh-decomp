// Scope: common
// SiSDK3::SiGfxNXPipelineState: its destruction and the reference counts its
// header defines. (Its small accessors are lib/yebis/class's; its constructor
// and the function that makes the NVN states aren't written yet.)
#define UNK_SIGFX_NX_PIPELINESTATE_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_PipelineState_Impl.h>

namespace SiSDK3 {

// 0x7100553330 (D2), 0x7100553640 (D0)
SiGfxNXPipelineState::~SiGfxNXPipelineState() {
    Unk_553370(reinterpret_cast<Unk_553370_States*>(this));
}

}  // namespace SiSDK3
