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
// 0x7100447030: a vertex element's usage as SiGfx has it
u32 Unk_447030(s32 usage);
struct Unk_SiGfxVertexFormat;

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

// how many bytes an element of a vertex format is (inline)
static inline u32 Unk_ElementSize(s32 format) {
    switch (format) {
    case 2:
        return 16;
    case 6:
        return 12;
    case 14:
    case 16:
        return 8;
    case 30:
    case 38:
    case 41:
        return 4;
    default:
        return 0;
    }
}

// how many components an element of a vertex format has (inline)
static inline u32 Unk_ElementComponents(s32 format) {
    switch (format) {
    case 2:
    case 14:
    case 30:
        return 4;
    case 6:
        return 3;
    case 16:
    case 38:
        return 2;
    case 41:
        return 1;
    default:
        return 0;
    }
}

// SiGfx's vertex format, as the input attribute makes it (placeholder)
struct Unk_SiGfxVertexFormat {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();  // releases
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual bool vf18();  // "BeginCreate()"
    // an element: what it is, its index, format, stream and offset, and
    // whether (and how often) it steps per instance
    virtual void vf19(u32 usage, u32 index, u32 format, u32 stream, u32 offset, bool instanced, u32 rate);
    virtual bool vf20();  // "EndCreate()"
};

// SiGfx's vertex format for a layout (inline; the arguments it is handed
// aren't used)
inline Unk_SiGfxVertexFormat* Unk_CreateVertexFormat(IGPUDevice* device, void* arg3, s32 arg4) {
    return device->field_38->vf38(nullptr, 0, nullptr);
}

// 0x7100449890 (its log lines name it)
// NON_MATCHING: the element loop's two format switches: the original sets
// each result to 0 before the range check and lays the jump table's blocks
// out with the 0 case joining, and its registers for the two results are
// swapped (w13/w14); the rest is the same.
s32 IGPUInputAttribute::BuildInputAttribute(const Unk_InputElement* elements, s32 count, void* arg3, s32 arg4) {
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
    field_18 = count;
#line 1617
    field_20 = UNK_NEW_ARRAY(Unk_InputElement, static_cast<u32>(count));
    field_28 = UNK_NEW_ARRAY(u32, field_18);
    field_30 = UNK_NEW_ARRAY(u32, field_18);
    for (s32 i = 0; i < 16; i++) {
        field_38[i] = 0;
    }
    u32 offset = 0;
    for (u32 i = 0; i < field_18; i++) {
        field_20[i] = elements[i];
        field_28[i] = Unk_ElementSize(field_20[i].field_8);
        field_30[i] = Unk_ElementComponents(field_20[i].field_8);
        if (field_20[i].field_c != 0) {
            offset = field_20[i].field_c;
        } else {
            field_20[i].field_c = offset;
        }
        offset += field_28[i];
        field_38[field_20[i].field_10] += field_28[i];
    }
    Unk_SiGfxVertexFormat* format = Unk_CreateVertexFormat(field_10, arg3, arg4);
    if (format == nullptr) {
#line 1721
        PPFX_ERROR("IGPUInputAttribute::BuildInputAttribute(): pSiGfxDevice->CreateVertexFormat() failed.\n");
        return -1;
    }
    if (!format->vf18()) {
#line 1730
        PPFX_ERROR("IGPUInputAttribute::BuildInputAttribute(): pSiGfxVertexFormat->BeginCreate() failed.\n");
        format->vf3();
        return -1;
    }
    for (u32 i = 0; i < field_18; i++) {
        const Unk_InputElement& element = field_20[i];
        format->vf19(Unk_447030(element.field_0), element.field_4, element.field_8, element.field_10, element.field_c,
                     element.field_14 != 0, element.field_14);
    }
    if (!format->vf20()) {
#line 1764
        PPFX_ERROR("IGPUInputAttribute::BuildInputAttribute(): pSiGfxVertexFormat->EndCreate() failed.\n");
        format->vf3();
        return -1;
    }
    field_78 = reinterpret_cast<Unk_SiGfxInterface*>(format);
    return 0;
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
