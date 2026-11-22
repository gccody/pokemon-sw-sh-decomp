// Scope: common
// PPFX::IGPUBuffer (C:/workspace/YEBIS_draft/src/GPU/GPUInterfaceBuffer.cpp, the __FILE__ of its log lines).
#define PPFX_FILE "C:/workspace/YEBIS_draft/src/GPU/GPUInterfaceBuffer.cpp"
#include <yebis/YEBIS_draft/src/GPU/Unk_Statics.h>
#include <yebis/YEBIS_draft/src/GPU/GPUInterfaceBuffer.h>
#include <yebis/YEBIS_draft/src/GPU/Unk_Log.h>

namespace PPFX {

s32 Unk_43e620(IGPUDevice* self, s32 n);

// 0x7100448b70, 0x7100448c30 (deleting): releases SiGfx's buffers, giving
// back the memory the device counts for each
// NON_MATCHING: 0x7100448b70, in the two loads after the loop's calls: the
// original reloads the count, then the array; this the array, then the
// count (five spellings of the loop give the same).
IGPUBuffer::~IGPUBuffer() {
    if (field_50 != nullptr) {
        for (u32 i = 0; i < field_48; i++) {
            if (field_50[i] != nullptr) {
                field_50[i]->vf3();
                Unk_43e620(field_18, field_44);
            }
        }
        UNK_DELETE_ARRAY(field_50);
    }
    if (field_a0 != nullptr) {
        field_a0->vf3();
        field_a0 = nullptr;
    }
}

// 0x7100449380
void IGPUBuffer::Unmap() {
    if (!field_5c) {
#line 1243
        PPFX_ERROR("IGPUBuffer::Unmap(): Buffer is not mapped.\n");
        return;
    }
    // (read in this order, before the device)
    Unk_SiGfxInterface** buffers = field_50;
    u32 index = field_58;
    field_18->field_30->vf70(buffers[index], &field_60);
    field_5c = false;
}

}  // namespace PPFX

// 0x7100449de0: _GLOBAL__sub_I_GPUInterfaceBuffer.cpp
