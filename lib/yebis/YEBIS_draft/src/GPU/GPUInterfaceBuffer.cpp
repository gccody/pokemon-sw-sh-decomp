// Scope: common
// PPFX::IGPUBuffer (C:/workspace/YEBIS_draft/src/GPU/GPUInterfaceBuffer.cpp, the __FILE__ of its log lines).
#define PPFX_FILE "C:/workspace/YEBIS_draft/src/GPU/GPUInterfaceBuffer.cpp"
#include <yebis/YEBIS_draft/src/GPU/Unk_Statics.h>
#include <yebis/YEBIS_draft/src/GPU/GPUInterfaceBuffer.h>
#include <yebis/YEBIS_draft/src/GPU/Unk_Log.h>

// 0x7100446df0: a result's name
const char* Unk_446df0(s32 result);

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

// how SiGfx maps for a mode (inline)
static inline u32 Unk_MapAccess(s32 mode) {
    switch (mode) {
    case 1:
        return 1;
    case 2:
        return 2;
    case 3:
        return 3;
    case 6:
        return 4;
    default:
        return 0;
    }
}

// 0x71004491b0
void* IGPUBuffer::Map(s32 mode, u32 offset, u32 size) {
    if (field_5c) {
#line 793
        PPFX_ERROR("IGPUBuffer::Map(): Buffer is already mapped.\n");
        return nullptr;
    }
    field_5d = false;
    s32 wrapped = 0;
    u64 index;
    if (mode & 4) {
        if (!(field_24 & 0x200)) {
#line 814
            PPFX_ERROR("IGPUBuffer::Map(): GPUUSAGE_DYNAMIC must be set at initialize for Map() with GPUMAPA_FLAG_DISCARD.\n");
            return nullptr;
        }
        index = ++field_58;
        if (index >= field_48) {
            field_58 = 0;
            field_5d = true;
            field_5e = true;
            index = 0;
            wrapped = 1;
        }
    } else {
        index = field_58;
    }
    Unk_SiGfxInterface** buffers = field_50;
    u32 kind = field_c;
    Unk_SiGfxDrawContext* context = field_18 != nullptr ? field_18->field_30 : nullptr;
    u32 access = Unk_MapAccess(mode);
    field_60.field_0 = wrapped ? access : 5;
    u8* bytes = nullptr;
    if (kind == 8 || kind == 9) {
        if (context->vf69(buffers[index], &field_60)) {
            bytes = field_60.field_20;
        }
    }
    void* result = bytes != nullptr ? bytes + offset : nullptr;
    if (result != nullptr) {
        field_5c = true;
    }
    return result;
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

// 0x7100449420 (deleting; the others are IGPUBuffer's)
IGPUVertexBuffer::~IGPUVertexBuffer() {}

// 0x71004495d0 (deleting; the others are IGPUBuffer's)
IGPUIndexBuffer::~IGPUIndexBuffer() {}

// 0x7100449450: IGPUVertexBuffer::CreateVertexBuffer (its log line)
IGPUBuffer* Unk_449450(IGPUDevice* device, u32 size, u32 count, u32 usage, u32 flags, void* data) {
#line 1404
    IGPUVertexBuffer* buffer = UNK_NEW(IGPUVertexBuffer)(device, usage, flags);
    s32 result = buffer->Unk_448c60(size, count, data);
    if (result < 0) {
#line 1409
        PPFX_ERROR("IGPUVertexBuffer::CreateVertexBufferpGPUVertexBuffer->BuildVertexBuffer(Size: %d, nBuffers: %d, Usage: 0x%x, Flag:0x%x) failed (0x%x: %s).\n",
                   size, count, usage, flags, result, Unk_446df0(result));
        PPFX_SAFE_RELEASE_INTERFACE(buffer);
    }
    return buffer;
}

// 0x7100446d60: an index format's name
const char* Unk_446d60(s32 format, char* buffer);

// 0x7100449600: IGPUIndexBuffer::CreateIndexBuffer (its log line)
IGPUBuffer* Unk_449600(IGPUDevice* device, u32 size, u32 count, s32 format, u32 usage, u32 flags, void* data) {
#line 1498
    IGPUIndexBuffer* buffer = UNK_NEW(IGPUIndexBuffer)(device, format, usage, flags);
    s32 result = buffer->Unk_448c60(size, count, data);
    if (result < 0) {
#line 1503
        PPFX_ERROR("IGPUIndexBuffer::CreateIndexBufferpGPUIndexBuffer->BuildIndexBuffer(Size: %d, nBuffers: %d, %s, Usage: 0x%x, Flag:0x%x) failed (0x%x: %s).\n",
                   size, count, Unk_446d60(format, nullptr), usage, flags, result, Unk_446df0(result));
        PPFX_SAFE_RELEASE_INTERFACE(buffer);
    }
    return buffer;
}

// 0x7100449790, 0x7100449860 (deleting)
IGPUInputAttribute::~IGPUInputAttribute() {
    UNK_DELETE_ARRAY(field_20);
    if (field_28 != nullptr) {
        Unk_4b9a60(Unk_238d5f8, reinterpret_cast<u64*>(field_28) - 1);
        field_28 = nullptr;
    }
    if (field_30 != nullptr) {
        Unk_4b9a60(Unk_238d5f8, reinterpret_cast<u64*>(field_30) - 1);
        field_30 = nullptr;
    }
    field_18 = 0;
    if (field_78 != nullptr) {
        field_78->vf3();
        field_78 = nullptr;
    }
}

// 0x7100449cc0: IGPUInputAttribute::CreateInputAttribute (its log line)
IGPUInterface* Unk_449cc0(IGPUDevice* device, const Unk_InputElement* elements, s32 count, void* arg3, s32 arg4) {
#line 1790
    IGPUInputAttribute* attribute = UNK_NEW(IGPUInputAttribute)(device);
    s32 result = attribute->BuildInputAttribute(elements, count, arg3, arg4);
    if (result < 0) {
#line 1795
        PPFX_ERROR("IGPUInputAttribute::CreateInputAttributepGPUInputAttribute->BuildInputAttribute() failed (0x%x: %s).\n",
                   result, Unk_446df0(result));
        PPFX_SAFE_RELEASE_INTERFACE(attribute);
    }
    return attribute;
}

}  // namespace PPFX

// 0x7100449de0: _GLOBAL__sub_I_GPUInterfaceBuffer.cpp
