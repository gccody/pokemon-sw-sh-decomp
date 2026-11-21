// PPFX::IGPUDevice (RTTI names the class; members are placeholders), as far
// as the functions written so far read it.
#pragma once

#include <yebis/YEBIS_draft/src/GPU/GPUInterface.h>
#include <yebis/YEBIS_draft/src/GPU/Unk_SiGfx.h>

namespace PPFX {

class IGPUDevice : public IGPUInterface {
public:
    u8 field_10[0x20];
    Unk_SiGfxDrawContext* field_30;
    Unk_SiGfxDevice* field_38;
};
PKMN_OFFSET_ASSERT(IGPUDevice, field_30, 0x30);
PKMN_OFFSET_ASSERT(IGPUDevice, field_38, 0x38);

}  // namespace PPFX
