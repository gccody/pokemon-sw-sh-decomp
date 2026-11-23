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
        Unk_MapInfo() : field_0(3), field_4(0), field_8(-1), field_10(0), field_18(false), field_20(nullptr) {
            field_28[0] = 0;
            field_28[1] = 0;
            field_28[2] = 0;
        }

        u32 field_0;
        u32 field_4;
        s32 field_8;
        u64 field_10;
        bool field_18;
        u8* field_20;  // the mapped bytes
        u64 field_28[3];
    };

    // inline in the functions that make a buffer
    explicit IGPUBuffer(IGPUDevice* device)
        : IGPUResource(device), field_44(0), field_48(0), field_50(nullptr), field_58(0), field_5d(false),
          field_5e(false) {
        field_20 = false;
    }
    ~IGPUBuffer() override;                     // 0x7100448b70, 0x7100448c30
    // 0x7100448c60 (its log lines name it): makes SiGfx's buffers (what the
    // makers' log lines call BuildVertexBuffer and BuildIndexBuffer)
    s32 BuildBuffer(u32 size, u32 count, void* data);
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

// PPFX::IGPUVertexBuffer and PPFX::IGPUIndexBuffer (RTTI): the buffers'
// kinds, which add nothing to IGPUBuffer
class IGPUVertexBuffer : public IGPUBuffer {
public:
    IGPUVertexBuffer(IGPUDevice* device, u32 usage, u32 flags) : IGPUBuffer(device) {
        field_a0 = nullptr;
        field_a8 = &field_50;
        field_c = 8;
        field_10 = 6;
        field_24 = usage;
        field_28 = (usage & 0x800) != 0 ? flags & ~0x300 : flags;
    }
    ~IGPUVertexBuffer() override;  // 0x7100448b70 (IGPUBuffer's), 0x7100449420
};
class IGPUIndexBuffer : public IGPUBuffer {
public:
    IGPUIndexBuffer(IGPUDevice* device, s32 format, u32 usage, u32 flags) : IGPUBuffer(device) {
        field_a0 = nullptr;
        field_a8 = &field_50;
        field_c = 9;
        field_10 = 7;
        field_24 = usage;
        field_28 = (usage & 0x800) != 0 ? flags & ~0x300 : flags;
        field_b0 = format;
    }
    ~IGPUIndexBuffer() override;  // 0x7100448b70 (IGPUBuffer's), 0x71004495d0

    s32 field_b0;  // the index format
};
PKMN_SIZE_ASSERT(IGPUIndexBuffer, 0xb8);

// PPFX::IGPUInputAttribute (RTTI; its maker's log line names it and
// BuildInputAttribute): a vertex layout and the SiGfx object made of it.
class IGPUInputAttribute : public IGPUInterface {
public:
    explicit IGPUInputAttribute(IGPUDevice* device)
        : field_10(device), field_18(0), field_20(nullptr), field_28(nullptr), field_30(nullptr), field_78(nullptr) {}
    ~IGPUInputAttribute() override;  // 0x7100449790, 0x7100449860
    // 0x7100449890
    s32 BuildInputAttribute(const Unk_InputElement* elements, s32 count, void* arg3, s32 arg4);

    IGPUDevice* field_10;
    u32 field_18;  // how many elements
    Unk_InputElement* field_20;
    u32* field_28;
    u32* field_30;
    u32 field_38[16];  // how many bytes a vertex of each stream is
    Unk_SiGfxInterface* field_78;
};
PKMN_SIZE_ASSERT(IGPUInputAttribute, 0x80);
PKMN_OFFSET_ASSERT(IGPUBuffer, field_44, 0x44);
PKMN_OFFSET_ASSERT(IGPUBuffer, field_a0, 0xa0);

}  // namespace PPFX
