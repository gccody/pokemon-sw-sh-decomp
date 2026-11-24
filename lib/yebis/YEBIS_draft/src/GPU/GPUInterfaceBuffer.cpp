// Scope: common
// PPFX::IGPUBuffer (C:/workspace/YEBIS_draft/src/GPU/GPUInterfaceBuffer.cpp, the __FILE__ of its log lines).
#include <string.h>

#define PPFX_FILE "C:/workspace/YEBIS_draft/src/GPU/GPUInterfaceBuffer.cpp"
#include <yebis/YEBIS_draft/src/GPU/Unk_Statics.h>
#include <yebis/YEBIS_draft/src/GPU/GPUInterfaceBuffer.h>
#include <yebis/YEBIS_draft/src/GPU/Unk_Log.h>

// 0x7100446df0: a result's name
const char* Unk_446df0(s32 result);
// 0x7100563620 (SiGfx's): an NVN memory pool's flags
u32 Unk_563620(u32 kind, u32 a1, u32 a2, u32 a3);

namespace PPFX {

s32 Unk_43e620(IGPUDevice* self, s32 n);
s32 Unk_43e600(IGPUDevice* self, s32 n);
// 0x7100447030: a vertex element's usage as SiGfx has it
u32 Unk_447030(s32 usage);
struct Unk_SiGfxVertexFormat;

// releases SiGfx's buffer `i`, giving back the memory the device counts for
// it (inline: written in the loop, the reloads after its calls come in the
// other order, the array first)
static inline void Unk_ReleaseBuffer(IGPUBuffer* self, u32 i) {
    if (self->field_50[i] != nullptr) {
        self->field_50[i]->vf3();
        Unk_43e620(self->field_18, self->field_44);
    }
}

// 0x7100448b70, 0x7100448c30 (deleting): releases SiGfx's buffers
IGPUBuffer::~IGPUBuffer() {
    if (field_50 != nullptr) {
        for (u32 i = 0; i < field_48; i++) {
            Unk_ReleaseBuffer(this, i);
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

// what SiGfx's memory heap is made with (placeholder)
struct Unk_SiGfxHeapDesc {
    u32 field_0;  // the size
    u32 field_4;
    u64 field_8;
    u32 field_10;  // the access: 1 static, 2 dynamic
    u32 field_14;
    u32 field_18;  // 1 for vertices, 2 for indices
    u32 field_1c;
    u32 field_20;
    u32 field_24;  // how many buffers
    u64 field_28;
    u32 field_30;  // the NVN pool's flags
    u32 field_34;
    u64 field_38;
    u64 field_40;
    s64 field_48;
    s64 field_50;
};
PKMN_SIZE_ASSERT(Unk_SiGfxHeapDesc, 0x58);

// what a SiGfx buffer is made with (placeholder)
struct Unk_SiGfxBufferDesc {
    u32 field_0;  // the index format
    u32 field_4;  // the size
    u32 field_8;  // the element's
    u32 field_c;
    u32 field_10;
    u16 field_14;
    u8 field_16;
    u32 field_18;
    u32 field_1c;
    u32 field_20;
    u32 field_24;
    u32 field_28;  // the size again
    void* field_30;  // the data
    Unk_SiGfxInterface* field_38;  // the heap
    u32 field_40;
    s32 field_44;
    s32 field_48;
    s32 field_4c;
    s32 field_50;
};
PKMN_SIZE_ASSERT(Unk_SiGfxBufferDesc, 0x58);

// SiGfx's heap and buffers as BuildBuffer makes them (placeholder)
struct Unk_SiGfxBufferObject {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual bool vf8(const Unk_SiGfxHeapDesc* desc);  // the heap's Create
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual bool vf21(const Unk_SiGfxBufferDesc* desc);  // the buffer's Create
};

// 0x7100448c60
// NON_MATCHING: the original's loop is unswitched on the kind (a loop for
// vertex buffers and one for the rest), this one is a little over
// LoopUnswitch's budget; the descriptors' stores also come in another order.
// The Map and Unmap at the end are inline.
s32 IGPUBuffer::BuildBuffer(u32 size, u32 count, void* data) {
    field_20 = false;
    field_44 = size;
    field_48 = count;
    field_50 = nullptr;
    if (size == 0 || count == 0) {
        return -6;
    }
    u32 usage = field_24;
    u32 kind = field_c;
    Unk_SiGfxHeapDesc heap;
    heap.field_0 = (size + 4) * count;
    heap.field_4 = 0;
    heap.field_8 = 0;
    heap.field_10 = 0;
    heap.field_14 = 0;
    heap.field_18 = 0;
    heap.field_1c = 0;
    heap.field_20 = 0;
    heap.field_24 = count;
    heap.field_28 = 0;
    heap.field_30 = 0;
    heap.field_34 = 0;
    heap.field_38 = 0;
    heap.field_40 = 0;
    heap.field_48 = -1;
    heap.field_50 = -1;
    if (usage & 0x200) {
        heap.field_1c = 0x10000;
        heap.field_10 = 2;
    }
    if (usage & 0x800) {
        heap.field_10 = 1;
    }
    if (kind == 8 || kind == 9) {
        heap.field_18 = kind == 8 ? 1 : 2;
    }
    heap.field_30 = (Unk_563620(10, heap.field_10, heap.field_18, heap.field_1c) & ~7) | 2;
    field_a0 = nullptr;
    field_a0 = field_18->field_38->vf30(0, nullptr);
    if (!reinterpret_cast<Unk_SiGfxBufferObject*>(field_a0)->vf8(&heap)) {
        if (field_a0 != nullptr) {
            field_a0->vf3();
            field_a0 = nullptr;
        }
#line 344
        PPFX_ERROR("error : m_pSiGfxMemoryHeap->Create()");
        return -1;
    }
#line 351
    field_50 = UNK_NEW_ARRAY(Unk_SiGfxInterface*, field_48);
    memset(field_50, 0, field_48 * sizeof(Unk_SiGfxInterface*));
    bool upload = (usage & 0x800) != 0;
    for (u64 i = 0; i < field_48; i++) {
        upload = false;
        Unk_SiGfxInterface** buffers = field_50;
        if (kind == 8) {
            Unk_SiGfxBufferObject* buffer =
                reinterpret_cast<Unk_SiGfxBufferObject*>(field_18->field_38->vf59(nullptr, 0, nullptr));
            bool created = false;
            if (buffer != nullptr) {
                Unk_SiGfxBufferDesc desc;
                desc.field_0 = 0;
                desc.field_4 = (size + 3) & ~3;
                desc.field_8 = 4;
                desc.field_c = 0;
                desc.field_10 = 1;
                desc.field_14 = 0;
                desc.field_16 = 0;
                desc.field_18 = heap.field_10;
                desc.field_1c = 1;
                desc.field_20 = heap.field_1c;
                desc.field_24 = heap.field_20;
                desc.field_28 = (size + 3) & ~3;
                desc.field_30 = data;
                desc.field_38 = field_a0;
                desc.field_40 = 0;
                desc.field_44 = -1;
                desc.field_48 = -1;
                desc.field_4c = -1;
                desc.field_50 = -1;
                created = buffer->vf21(&desc);
                if (!created) {
                    buffer->vf3();
                }
            }
            if (!created) {
#line 639
                PPFX_ERROR("IGPUBuffer::BuildBuffer(): ISiGfxVertexBuffer::Create() failed.\n");
                return -5;
            }
            buffers[i] = reinterpret_cast<Unk_SiGfxInterface*>(buffer);
        } else if (kind == 9) {
            Unk_SiGfxBufferObject* buffer =
                reinterpret_cast<Unk_SiGfxBufferObject*>(field_18->field_38->vf59(nullptr, 0, nullptr));
            bool created = false;
            if (buffer != nullptr) {
                s32 format = static_cast<IGPUIndexBuffer*>(this)->field_b0;
                u32 stride = format == 0x2a ? 4 : 2;
                u32 elements = format == 0x2a ? (size + 3) >> 2 : (size + 1) >> 1;
                Unk_SiGfxBufferDesc desc;
                desc.field_0 = format == 0x2a ? 0x2a : 0x39;
                desc.field_4 = elements * stride;
                desc.field_8 = stride;
                desc.field_c = 0;
                desc.field_10 = 1;
                desc.field_14 = 0;
                desc.field_16 = 0;
                desc.field_18 = heap.field_10;
                desc.field_1c = 2;
                desc.field_20 = heap.field_1c;
                desc.field_24 = heap.field_20;
                desc.field_28 = elements * stride;
                desc.field_30 = data;
                desc.field_38 = field_a0;
                desc.field_40 = 0;
                desc.field_44 = -1;
                desc.field_48 = -1;
                desc.field_4c = -1;
                desc.field_50 = -1;
                created = buffer->vf21(&desc);
                if (!created) {
                    buffer->vf3();
                }
            }
            if (!created) {
#line 692
                PPFX_ERROR("IGPUBuffer::BuildBuffer(): ISiGfxIndexBuffer::Create() failed.\n");
                return -5;
            }
            buffers[i] = reinterpret_cast<Unk_SiGfxInterface*>(buffer);
        }
        Unk_43e600(field_18, field_44);
    }
    field_5c = false;
    field_5d = false;
    field_58 = field_48 - 1;
    field_5e = false;
    if (upload) {
        void* bytes = Map(1, 0, field_44);
        memcpy(bytes, data, field_44);
        Unmap();
    }
    return 0;
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
    s32 result = buffer->BuildBuffer(size, count, data);
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
    s32 result = buffer->BuildBuffer(size, count, data);
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
    u32 size = 0;
    switch (format) {
    case 2:
        size = 16;
        break;
    case 6:
        size = 12;
        break;
    case 14:
    case 16:
        size = 8;
        break;
    case 30:
    case 38:
    case 41:
        size = 4;
        break;
    }
    return size;
}

// how many components an element of a vertex format has (inline)
static inline u32 Unk_ElementComponents(s32 format) {
    u32 count = 0;
    switch (format) {
    case 2:
    case 14:
    case 30:
        count = 4;
        break;
    case 6:
        count = 3;
        break;
    case 16:
    case 38:
        count = 2;
        break;
    case 41:
        count = 1;
        break;
    }
    return count;
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
// The helpers keep their result in a variable set to 0 before the switch: the
// original's 0 is set before the range check, which then joins directly.
// NON_MATCHING: the element loop's two format switches: the registers of the
// two results and their formats are exchanged (w13/w14), and the first
// switch's blocks for 16 and 12 bytes are laid out the other way round (every
// order of its cases gives the same); the rest is the same.
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
