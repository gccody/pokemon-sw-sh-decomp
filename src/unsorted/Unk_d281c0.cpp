// Scope: common
// The effect starter that forwards to the global effect manager.
#include "unsorted/Unk_d281c0.h"

extern void* Unk_27e0740;

// The manager's start function. It takes what its caller was passed by value
// in place, so the forwarder passes their addresses through unchanged.
void Unk_e43620(void* manager,
                u32 type,
                Unk_d281c0_Target& target,
                const float32x4_t& offset,
                const void* arg3,
                Unk_5cfaf0_Name& name,
                float scale);

// 0x7100d281c0
void Unk_d281c0_call(u32 type,
                     Unk_d281c0_Target target,
                     const float32x4_t& offset,
                     const void* arg3,
                     Unk_5cfaf0_Name name,
                     float scale) {
    Unk_e43620(Unk_27e0740, type, target, offset, arg3, name, scale);
}
