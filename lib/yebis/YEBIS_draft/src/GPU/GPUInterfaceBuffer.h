// PPFX::IGPUBuffer, the base of the vertex and index buffers (RTTI names the
// classes; GPUInterfaceBuffer.cpp's log lines name Map and Unmap). Members
// are placeholders, as far as the functions written so far read them.
#pragma once

#include <yebis/YEBIS_draft/src/GPU/GPUInterfaceDevice.h>
#include <yebis/YEBIS_draft/src/GPU/GPUInterfaceResource.h>

namespace PPFX {

class IGPUBuffer : public IGPUResource {
public:
    // what SiGfx's map and unmap are given (placeholder)
    struct Unk_MapInfo {
        u32 field_0;
        u32 field_4;
        s32 field_8;
        u64 field_10;
        bool field_18;
        u8* field_20;  // the mapped bytes
        u64 field_28[3];
    };

    ~IGPUBuffer() override;                     // 0x7100448b70, 0x7100448c30
    void* Map(s32 mode, u32 offset, u32 size);  // 0x71004491b0
    void Unmap();                               // 0x7100449380

    u32 field_44;  // how many bytes each of the buffers is
    u32 field_48;  // how many SiGfx buffers
    Unk_SiGfxInterface** field_50;
    u32 field_58;  // the one in use
    bool field_5c;  // mapped
    bool field_5d;
    bool field_5e;
    Unk_MapInfo field_60;
    Unk_SiGfxInterface* field_a0;
    Unk_SiGfxInterface*** field_a8;
};
PKMN_SIZE_ASSERT(IGPUBuffer, 0xb0);
PKMN_OFFSET_ASSERT(IGPUBuffer, field_44, 0x44);
PKMN_OFFSET_ASSERT(IGPUBuffer, field_a0, 0xa0);

}  // namespace PPFX
