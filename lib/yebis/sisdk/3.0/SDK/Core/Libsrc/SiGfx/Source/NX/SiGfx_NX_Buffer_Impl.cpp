// Scope: common
// SiSDK3::SiGfxNXBuffer: its construction and destruction, its name, its
// release, and the reference counts its header defines. (Its small accessors
// are lib/yebis/class's; the functions that make and map it aren't written
// yet.)
#define UNK_SIGFX_NX_BUFFER_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_Buffer_Impl.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_StringFuncs.h>

namespace SiSDK3 {

// The greater of two values (inline: placeholder name). A ternary written in
// the function is threaded into the branch before it; the original's selects
// stay as they are.
template <class T>
inline T Unk_Max(T a, T b) {
    return a > b ? a : b;
}

// 0x7100537200
SiGfxNXBuffer::SiGfxNXBuffer(ISiAllocator* pAllocator, SiGfxNXDevice* pDevice)
    : field_10(pAllocator), field_20(pDevice), field_28(0), field_30(pAllocator), field_a0(0), field_100(0),
      field_108(nullptr), field_110(true), field_111(false), field_118(0), field_120(0), field_128(false), field_12c(1),
      field_130(-1), field_150(0), field_154(0), field_170(pAllocator) {
    memset(&field_a4, 0, sizeof(field_a4) + sizeof(field_b8) + sizeof(field_d0));
    field_a4.field_0 = 10;
    memset(field_158, 0, sizeof(field_158));
    field_170.Unk_SetBuffer(field_158, 3);
}

// 0x7100537370 (D2), 0x71005374f0 (D0); 0x71005374e0 and 0x7100537520 are
// their thunks for the second base
SiGfxNXBuffer::~SiGfxNXBuffer() {
    if (field_28 != 0) {
        field_20->Unk_4f9640(Unk_NXResource(this));
        field_28 = 0;
    }
    vf22();
}

// 0x7100537560 (0x71005375d0: its thunk)
bool SiGfxNXBuffer::vf30(const char* name) {
    Unk_4c4700(&field_30, const_cast<char*>(name));
    field_a0 = Unk_4c3510(&field_30);
    if (field_128) {
        nvnBufferSetDebugLabel(field_d0, Unk_StringCStr(&field_30));
    }
    return true;
}

// 0x7100537640 (0x7100537650: its thunk)
const SiString<char>* SiGfxNXBuffer::vf31() {
    return &field_30;
}

// 0x7100537660 (0x7100537670: its thunk)
u32 SiGfxNXBuffer::vf32() {
    return field_a0;
}

// 0x7100537760
bool SiGfxNXBuffer::vf21(Unk_MakeDesc* desc) {
    vf22();
    if (desc->field_28 <= 0) {
        desc->field_28 = desc->field_4;
    }
    if (desc->field_30 == nullptr) {
        desc->field_28 = 0;
    }
    bool result;
    if (desc->field_1c & 1) {
        field_110 = false;
        result = Unk_537930(desc);
    } else if (desc->field_1c & 2) {
        field_110 = false;
        result = Unk_537b60(desc);
    } else if (desc->field_1c & 4) {
        field_110 = false;
        result = Unk_537df0(desc);
    } else {
        field_110 = true;
        result = Unk_538090(desc);
    }
    if (!result) {
        return false;
    }
    if ((desc->field_1c & 0x10000) && !Unk_538340(desc)) {
        return false;
    }
    field_170.Unk_SetCount(desc->field_10);
    for (s32 i = 0; i < static_cast<s32>(field_170.m_itemCount); i++) {
        field_170.m_pData[i] = 0;
    }
    field_150 = 0;
    if (field_128) {
        nvnBufferSetDebugLabel(field_d0, Unk_StringCStr(&field_30));
    }
    return true;
}

// 0x7100537930
bool SiGfxNXBuffer::Unk_537930(const Unk_MakeDesc* desc) {
    void* device = Unk_NXDevice(field_20)->vf85();
    u64 builder[8] = {};  // NVNbufferBuilder
    nvnBufferBuilderSetDefaults(builder);
    nvnBufferBuilderSetDevice(builder, device);
    s32 size = desc->field_4;
    s64 alignment = desc->field_8;
    s32 count = 0;
    if (alignment > 0) {
        count = size / desc->field_8;
    }
    s64 total = size;
    if (desc->field_10 > 1) {
        total = desc->field_10 * size;
    }
    if (desc->field_38 != nullptr) {
        field_108 = desc->field_38;
        field_108->vf2();
    }
    s64 align = alignment;
    if (!Unk_5386d0(&total, &align, desc)) {
        return false;
    }
    nvnBufferBuilderSetStorage(builder, field_108->vf16(), field_118, size);
    if (Unk_nvnBufferInitialize(field_d0, builder) != 1) {
        return false;
    }
    u32 flags = field_108->field_74;
    if (!(flags & 1) && desc->field_30 != nullptr) {
        memcpy(nvnBufferMap(field_d0), desc->field_30, size);
        if (flags & 4) {
            nvnBufferFlushMappedRange(field_d0, 0, size);
        }
    }
    field_100 = nvnBufferGetAddress(field_d0);
    field_128 = true;
    field_b8.field_4 = size;
    field_b8.field_8 = desc->field_8;
    field_b8.field_c = field_118;
    field_b8.field_10 = count;
    field_b8.field_14 = desc->field_10;
    field_a4.field_4[1] = desc->field_1c;
    field_a4.field_4[2] = desc->field_20;
    field_a4.field_4[3] = desc->field_24;
    field_a4.field_0 = 10;
    field_a4.field_4[0] = desc->field_18;
    return true;
}

// 0x7100537b60
bool SiGfxNXBuffer::Unk_537b60(const Unk_MakeDesc* desc) {
    void* device = Unk_NXDevice(field_20)->vf85();
    u64 builder[8] = {};  // NVNbufferBuilder
    nvnBufferBuilderSetDefaults(builder);
    nvnBufferBuilderSetDevice(builder, device);
    s64 align = 2;
    switch (desc->field_0) {
    case 0x2a:
        align = 4;
        break;
    case 0x39:
        align = 2;
        break;
    }
    s32 size = desc->field_4;
    s32 count = 0;
    if (desc->field_8 > 0) {
        count = size / desc->field_8;
    }
    s64 total = size;
    if (desc->field_10 > 1) {
        total = desc->field_10 * size;
    }
    if (desc->field_38 != nullptr) {
        field_108 = desc->field_38;
        field_108->vf2();
    }
    if (!Unk_5386d0(&total, &align, desc)) {
        return false;
    }
    nvnBufferBuilderSetStorage(builder, field_108->vf16(), field_118, size);
    if (Unk_nvnBufferInitialize(field_d0, builder) != 1) {
        return false;
    }
    u32 flags = field_108->field_74;
    if (!(flags & 1) && desc->field_30 != nullptr) {
        void* data = nvnBufferMap(field_d0);
        s32 dataSize = desc->field_28 > 0 ? desc->field_28 : desc->field_4;
        memcpy(data, desc->field_30, dataSize);
        if (flags & 4) {
            nvnBufferFlushMappedRange(field_d0, 0, size);
        }
    }
    switch (desc->field_0) {
    case 0x2a:
        field_12c = 2;
        break;
    case 0x39:
        field_12c = 1;
        break;
    }
    field_100 = nvnBufferGetAddress(field_d0);
    field_128 = true;
    field_b8.field_0 = desc->field_0;
    field_b8.field_4 = desc->field_4;
    field_b8.field_8 = desc->field_8;
    field_b8.field_c = field_118;
    field_b8.field_10 = count;
    field_b8.field_14 = desc->field_4;
    field_a4.field_4[1] = desc->field_1c;
    field_a4.field_4[2] = desc->field_20;
    field_a4.field_4[3] = desc->field_24;
    field_a4.field_0 = 10;
    field_a4.field_4[0] = desc->field_18;
    return true;
}

// NON_MATCHING: registers: the rounded total and the alignment less one
// are exchanged between w24 and w25, and the failed nvnBufferInitialize sets
// the result before its test instead of sharing the other failure's block
// (0x7100538090 is the same code without the flush and matches).
// 0x7100537df0
bool SiGfxNXBuffer::Unk_537df0(const Unk_MakeDesc* desc) {
    void* device = Unk_NXDevice(field_20)->vf85();
    u64 builder[8] = {};  // NVNbufferBuilder
    nvnBufferBuilderSetDefaults(builder);
    nvnBufferBuilderSetDevice(builder, device);
    u32 alignment = 8;
    if (desc->field_1c & 4) {
        int value;
        nvnDeviceGetInteger(device, 4, &value);
        alignment = Unk_Max<s32>(alignment, value);
    }
    if (desc->field_1c & 0x8000) {
        alignment = Unk_Max<u32>(alignment, 0x20);
    }
    if (desc->field_1c & 0x4028) {
        alignment = Unk_Max<u32>(alignment, 0x200);
    }
    s32 size = desc->field_4;
    s32 count = 0;
    if (desc->field_8 > 0) {
        count = size / desc->field_8;
    }
    s64 total = size;
    if (desc->field_10 > 1) {
        total = desc->field_10 * size;
    }
    if (desc->field_38 != nullptr) {
        field_108 = desc->field_38;
        field_108->vf2();
    }
    s64 align = alignment;
    if (!Unk_5386d0(&total, &align, desc)) {
        return false;
    }
    s32 storageSize = (static_cast<s32>(total) + alignment - 1) & ~(alignment - 1);
    nvnBufferBuilderSetStorage(builder, field_108->vf16(), field_118, storageSize);
    if (Unk_nvnBufferInitialize(field_d0, builder) != 1) {
        return false;
    }
    s32 alignedSize = (size + alignment - 1) & ~(alignment - 1);
    field_100 = nvnBufferGetAddress(field_d0);
    u32 poolFlags = field_108->field_74;
    if (!(poolFlags & 1) && desc->field_30 != nullptr) {
        memcpy(nvnBufferMap(field_d0), desc->field_30, desc->field_4);
        if (poolFlags & 4) {
            nvnBufferFlushMappedRange(field_d0, 0, desc->field_4);
        }
    }
    field_128 = true;
    field_b8.field_0 = desc->field_0;
    field_b8.field_4 = alignedSize;
    field_b8.field_8 = desc->field_8;
    field_b8.field_c = field_118;
    field_b8.field_10 = count;
    field_b8.field_14 = desc->field_10;
    field_a4.field_4[1] = desc->field_1c;
    field_a4.field_4[2] = desc->field_20;
    field_a4.field_4[3] = desc->field_24;
    field_a4.field_0 = 10;
    field_a4.field_4[0] = desc->field_18;
    return true;
}

// NON_MATCHING: the failed nvnBufferInitialize sets the result before its
// test instead of sharing the other failure's block (as in 0x7100537df0),
// and the heap's flags are read as a byte (ldrb) where the original reads
// the word.
// (Round 3: the flags in a u32 local, as a bool, `% 2`, `== 0`; the result in a
// variable with one exit, nested tests, the initialisation's result in a
// local: none changes either difference.)
// 0x7100538090
bool SiGfxNXBuffer::Unk_538090(const Unk_MakeDesc* desc) {
    void* device = Unk_NXDevice(field_20)->vf85();
    u64 builder[8] = {};  // NVNbufferBuilder
    nvnBufferBuilderSetDefaults(builder);
    nvnBufferBuilderSetDevice(builder, device);
    u32 alignment = 8;
    if (desc->field_1c & 4) {
        int value;
        nvnDeviceGetInteger(device, 4, &value);
        alignment = Unk_Max<s32>(alignment, value);
    }
    if (desc->field_1c & 0x8000) {
        alignment = Unk_Max<u32>(alignment, 0x20);
    }
    if (desc->field_1c & 8) {
        alignment = Unk_Max<u32>(alignment, 0x80);
    }
    if (desc->field_1c & 0x4020) {
        alignment = Unk_Max<u32>(alignment, 0x200);
    }
    s32 size = desc->field_4;
    s32 count = 0;
    if (desc->field_8 > 0) {
        count = size / desc->field_8;
    }
    s64 total = size;
    if (desc->field_10 > 1) {
        total = desc->field_10 * size;
    }
    if (desc->field_38 != nullptr) {
        desc->field_38->vf2();
    }
    if (field_108 != nullptr) {
        field_108->vf3();
    }
    field_108 = desc->field_38;
    s64 align = alignment;
    if (!Unk_5386d0(&total, &align, desc)) {
        return false;
    }
    s32 storageSize = (static_cast<s32>(total) + alignment - 1) & ~(alignment - 1);
    nvnBufferBuilderSetStorage(builder, field_108->vf16(), field_120, storageSize);
    if (Unk_nvnBufferInitialize(field_d0, builder) != 1) {
        return false;
    }
    s32 alignedSize = (size + alignment - 1) & ~(alignment - 1);
    field_100 = nvnBufferGetAddress(field_d0);
    if (!(field_108->field_74 & 1) && desc->field_30 != nullptr) {
        memcpy(nvnBufferMap(field_d0), desc->field_30, desc->field_4);
    }
    field_128 = true;
    field_b8.field_0 = desc->field_0;
    field_b8.field_4 = alignedSize;
    field_b8.field_8 = desc->field_8;
    field_b8.field_c = field_118;
    field_b8.field_10 = count;
    field_b8.field_14 = desc->field_10;
    field_a4.field_4[1] = desc->field_1c;
    field_a4.field_4[2] = desc->field_20;
    field_a4.field_4[3] = desc->field_24;
    field_a4.field_0 = 10;
    field_a4.field_4[0] = desc->field_18;
    return true;
}

// (SiGfxNXDevice::Unk_4fb200 returns an s32, as what it forwards does.)
// 0x7100538340
bool SiGfxNXBuffer::Unk_538340(const Unk_MakeDesc* desc) {
    void* device = Unk_NXDevice(field_20)->vf85();
    u64 builder[16] = {};  // NVNtextureBuilder
    nvnTextureBuilderSetDefaults(builder);
    nvnTextureBuilderSetDevice(builder, device);
    nvnTextureBuilderSetWidth(builder, desc->field_4);
    nvnTextureBuilderSetHeight(builder, 1);
    nvnTextureBuilderSetDepth(builder, 1);
    nvnTextureBuilderSetLevels(builder, 1);
    nvnTextureBuilderSetFormat(builder, 3);
    nvnTextureBuilderSetTarget(builder, 10);
    nvnTextureBuilderSetFlags(builder, 4);
    nvnTextureBuilderSetStride(builder, 1);
    nvnTextureBuilderSetStorage(builder, field_108->vf16(), field_118);
#line 601
    field_138 = field_10.m_pAllocator->vf7(0xc0, 0x10, __FILE__, __LINE__);
    if (field_138 == nullptr) {
        return false;
    }
#line 608
    field_140 = field_10.m_pAllocator->vf7(0x28, 0x10, __FILE__, __LINE__);
    if (field_140 == nullptr) {
        return false;
    }
    if (nvnTextureInitialize(field_138, builder) != 1) {
        return false;
    }
    nvnTextureViewSetDefaults(field_140);
    nvnTextureViewSetLevels(field_140, 0, 1);
    nvnTextureViewSetFormat(field_140, nvnTextureGetFormat(field_138));
    nvnTextureViewSetLayers(field_140, 0, 1);
    nvnTextureViewSetTarget(field_140, nvnTextureGetTarget(field_138));
    field_130 = field_20->Unk_4fb200(reinterpret_cast<u64>(field_138), reinterpret_cast<u64>(field_140));
    if (field_130 == -1) {
        return false;
    }
    field_148 = nvnDeviceGetImageHandle(device, field_130);
    return true;
}

// 0x7100538620
void SiGfxNXBuffer::vf22() {
    if (field_128) {
        nvnBufferFinalize(field_d0);
        field_128 = false;
        memset(field_d0, 0, sizeof(field_d0) + sizeof(field_100));
    }
    if (field_130 != -1) {
        field_20->Unk_4fb290(field_130);
    }
    if (field_108 != nullptr) {
        if (field_111) {
            field_108->Unk_553010(field_118);
            field_111 = false;
            field_118 = 0;
            field_120 = 0;
        }
        if (field_108 != nullptr) {
            field_108->vf3();
            field_108 = nullptr;
        }
    }
    memset(&field_a4, 0, sizeof(field_a4) + sizeof(field_b8));
    field_a4.field_0 = 10;
}

// 0x71005386d0
bool SiGfxNXBuffer::Unk_5386d0(s64* size, s64* alignment, const Unk_MakeDesc* desc) {
    s64 alignedSize = Unk_NXAlign(*size, *alignment);
    if (field_108 == nullptr) {
        if (field_110) {
            // a heap of its own
            field_108 = vf5()->vf30(0, nullptr);
            Unk_NXMemoryHeapDesc heapDesc(alignedSize);
            heapDesc.field_24 = 1;
            heapDesc.field_1c = desc->field_20;
            heapDesc.field_10 = desc->field_18;
            heapDesc.field_18 = desc->field_1c;
            heapDesc.field_40 = desc->field_30;
            heapDesc.field_34 = desc->field_28;
            if (!field_108->vf8(&heapDesc)) {
                return false;
            }
        } else {
            // the device's memory for the kind of buffer (its requests are
            // the buffer's own description)
            s64 offset = 0;
            Unk_MakeDesc request = *desc;
            request.field_4 = alignedSize;
            request.field_c = *alignment;
            request.field_18 = 0;
            request.field_20 = 0x10000;
            const Unk_4faac0_Request* pRequest = reinterpret_cast<const Unk_4faac0_Request*>(&request);
            SiGfxNXMemoryHeap* heap;
            if (desc->field_1c & 1) {
                heap = field_20->Unk_4facb0(pRequest, &offset);
            } else if (desc->field_1c & 2) {
                heap = field_20->Unk_4faea0(pRequest, &offset);
            } else if (desc->field_1c & 4) {
                heap = field_20->Unk_4faac0(pRequest, &offset);
            } else {
                return false;
            }
            if (heap == nullptr) {
                return false;
            }
            heap->vf2();
            if (field_108 != nullptr) {
                field_108->vf3();
                field_108 = nullptr;
            }
            field_108 = heap;
            field_111 = true;
            field_118 = offset;
            field_120 = Unk_NXAlign(field_118, *alignment);
            return true;
        }
    }
    if (desc->field_40 > 0) {
        field_118 = desc->field_40;
    } else {
        if (!field_108->Unk_552fc0(static_cast<s32>(alignedSize), *alignment, &field_118)) {
            return false;
        }
        field_111 = true;
    }
    field_120 = Unk_NXAlign(field_118, *alignment);
    return true;
}

// 0x7100538910
void SiGfxNXBuffer::Unk_538910() {
    nvnBufferFlushMappedRange(field_d0, 0, field_b8.field_4);
}

// 0x71005389a0
void SiGfxNXBuffer::vf24(unsigned long long value) {
    s32 index = field_150;
    field_170.m_pData[index] = value;
}

// 0x71005389b0
unsigned long long SiGfxNXBuffer::vf25() {
    s32 index = field_150;
    return field_170.m_pData[index];
}

}  // namespace SiSDK3
