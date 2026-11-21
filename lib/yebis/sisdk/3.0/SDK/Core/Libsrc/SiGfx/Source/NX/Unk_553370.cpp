// Scope: common
// SiGfx's NVN states' defaults (placeholder file and names: a function between
// SiGfxNXMemoryHeap's and SiGfxNXPipelineState's, which takes an object that
// holds the blend, vertex attribute and vertex stream states of a pipeline).
#include <nx_middleware/gfx/nvn.h>
#include <types.h>

// The object's states (placeholder name).
struct Unk_553370_States {
    u8 field_0[0x558];
    u64 field_558[8];   // NVNblendState
    u8 field_598[0x30];
    u32 field_5c8[32];  // NVNvertexAttribState
    u64 field_648[16];  // NVNvertexStreamState
};
PKMN_OFFSET_ASSERT(Unk_553370_States, field_5c8, 0x5c8);
PKMN_OFFSET_ASSERT(Unk_553370_States, field_648, 0x648);

namespace {

// nvn.h declares these two without their types
inline void Unk_VertexAttribStateSetDefaults(void* state) {
    reinterpret_cast<void (*)(void*)>(Unk_27fd118)(state);
}
inline void Unk_VertexStreamStateSetDefaults(void* state) {
    reinterpret_cast<void (*)(void*)>(Unk_27fd140)(state);
}

}  // namespace

// 0x7100553370
void Unk_553370(Unk_553370_States* self) {
    for (s32 i = 0; i < 8; i++) {
        nvnBlendStateSetDefaults(&self->field_558[i]);
    }
    for (s32 i = 0; i < 32; i++) {
        Unk_VertexAttribStateSetDefaults(&self->field_5c8[i]);
    }
    for (s32 i = 0; i < 16; i++) {
        Unk_VertexStreamStateSetDefaults(&self->field_648[i]);
    }
}
