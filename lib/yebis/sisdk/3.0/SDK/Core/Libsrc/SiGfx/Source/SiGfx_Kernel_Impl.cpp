// Scope: common
// SiSDK3::SiGfxKernel: its getter (a function-local static), constructor and
// destructors, the lists of devices and event handlers. The reference counts
// are its header's.
#define UNK_SIGFX_KERNEL_IMPL
#define UNK_SIGFX_SHADERGRAPH_REFLECTION
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_Reflection.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_StringFuncs.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiGfx/ShaderGraph/SiGfx_ShaderGraph.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiGfx/ShaderGraph/SiGfx_ShaderGraph_DataType.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiGfx/ShaderGraph/SiGfx_ShaderGraph_DataType_Array.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiGfx/ShaderGraph/SiGfx_ShaderGraph_DataType_Matrix.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiGfx/ShaderGraph/SiGfx_ShaderGraph_DataType_POD.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiGfx/ShaderGraph/SiGfx_ShaderGraph_DataType_Struct.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiGfx/ShaderGraph/SiGfx_ShaderGraph_DataType_Vector.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiGfx/ShaderGraph/SiGfx_ShaderGraph_DataValue.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiGfx/ShaderGraph/SiGfx_ShaderGraph_DataValue_POD.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiGfx/ShaderGraph/SiGfx_ShaderGraph_Node.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiGfx/ShaderGraph/SiGfx_ShaderGraph_NodeType.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiGfx/ShaderGraph/SiGfx_ShaderGraph_NodeType_Function.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiGfx/ShaderGraph/SiGfx_ShaderGraph_Node_Function.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiGfx/ShaderGraph/SiGfx_ShaderGraph_Object.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_Manager_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/SiGfx_Kernel_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/ShaderGraph/SiGfx_ShaderGraph_Utility_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/SiGfx_DisplayUtility_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/SiGfx_GeometryUtility_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/SiGfx_ImageUtility_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/SiGfx_PerformanceUtility_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/SiGfx_ShaderUtility_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/SiGfx_TextureUtility_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiIO/Source/SiIO_Kernel_Impl.h>

// 0x710276cff0: the kernel, while it exists (hidden: read without the GOT,
// lib/yebis/leaf's 0x71004cbf40 too)
extern SiSDK3::SiGfxKernel* Unk_276cff0 __attribute__((visibility("hidden")));
SiSDK3::SiGfxKernel* Unk_276cff0;

// 0x710276cfe8: set while the resources given to the kernel are destroyed
// (Unk_RefCountDeferred.h)
u8 Unk_276cfe8;

// 0x71004ee850, 0x71004ee860 (lib/yebis/leaf's names): the frame
u64 Unk_4ee850_get();
s32 Unk_4ee860_get();

// 0x71004c5930: a number with its digits in groups of three
void Unk_4c5930(char* dst, size_t size, u64 value);
// 0x71004ed060: a graphics interface's name
const char* Unk_4ed060(u32 index);

// 0x7100582eb0: the working directory (SiIO)
SiSDK3::SiString<char> Unk_582eb0();
// 0x71004ca0b0: replaces one string with another in a string
void Unk_4ca0b0(SiSDK3::SiString<char>* self, const char* from, const char* to, u64, u64, bool);

// 0x7100579c60: SiGfx's texts for a language
const void* Unk_579c60(const Unk_4ca820_arg0& language);
// 0x7101eeada8: the id of SiGfx's string table
extern const u8 Unk_1eeada8[] __attribute__((visibility("hidden")));

// A reference counted pointer's assignment (placeholder name): the new value
// is evaluated three times, as the original's code shows.
#define UNK_REF_ASSIGN(dst, src) \
    if ((src) != nullptr) {      \
        (src)->vf2();            \
    }                            \
    if ((dst) != nullptr) {      \
        (dst)->vf3();            \
    }                            \
    (dst) = (src)

// A reference counted pointer's release (placeholder name)
#define UNK_RELEASE(p)     \
    if ((p) != nullptr) {  \
        (p)->vf3();        \
        (p) = nullptr;     \
    }

// 0x710057d030: SiIO's kernel
u64 Unk_57d030_get();
// 0x7101eec778, 0x7101eec788, 0x7101eec798: the identifiers of SiGfx's chunks
// of binary archives (the texture's is the first)
extern const SiSDK3::ISiIOBinaryArchive::Unk_Id Unk_1eec778;
extern const SiSDK3::ISiIOBinaryArchive::Unk_Id Unk_1eec788;
extern const SiSDK3::ISiIOBinaryArchive::Unk_Id Unk_1eec798;
// 0x7102391358, 0x7102391360, 0x7102391368: the names of those chunks' types
extern const char* Unk_2391358;
extern const char* Unk_2391360;
extern const char* Unk_2391368;
// what the initialisation asks of the objects it makes (leafgen's names and
// types; they all succeed). 0x71004f6c70's result is tested as a bool.
bool Unk_4f6c70_get(u64);
u32 Unk_4e3c30_get(u64);
u32 Unk_4da480_get(u64);
u32 Unk_4eac50_get(u64);
u32 Unk_4d3180_get(u64);
struct Unk_4e2400;
u32 Unk_4e2400_call(Unk_4e2400* self);
// SiIO's kernel as the initialisation calls it (placeholder name): slot 19
// adds a type of chunk, its version given by reference (the temporaries are
// made after the kernel is fetched)
class Unk_IOKernelInterface {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
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
    virtual void vf18();
    virtual void vf19(const SiSDK3::ISiIOBinaryArchive::Unk_Id* id, const char* name,
                      const SiSDK3::Unk_567750_Version& version);
};

namespace SiSDK3 {
// takes out every element equal to value, from the last one, and tells how
// many there were (inline: placeholder name)
template <class T, int ALIGN>
inline size_t Unk_RemoveCounted(SiArray<T, ALIGN>* array, const T& value) {
    size_t removed = 0;
    for (int i = static_cast<int>(array->m_itemCount) - 1; i >= 0; i--) {
        if (array->m_pData[i] == value) {
            array->RemoveByIndex(i);
            removed++;
        }
    }
    array->Unk_UpdateRange();
    return removed;
}
}  // namespace SiSDK3

// 0x71004cbec0
SiSDK3::SiGfxKernel* Unk_4cbec0() {
    static SiSDK3::SiGfxKernel s_kernel;
    return &s_kernel;
}

// 0x71004ce9d0 (leafgen's name and types): gives the kernel a resource to
// destroy later
void Unk_4ce9d0(void* self, void* resource) {
    SiSDK3::SiGfxKernel* kernel = static_cast<SiSDK3::SiGfxKernel*>(self);
    Unk_596640 lock(&kernel->field_228, true);
    SiSDK3::SiGfxKernel::DelayedDeletionEntry entry;
    entry.field_0 = static_cast<SiSDK3::ISiInterface*>(resource);
    entry.field_8 = Unk_4ee850_get() + Unk_4ee860_get();
    kernel->field_258.Unk_Add(entry);
}

namespace SiSDK3 {

// 0x71004cbf50
SiGfxKernel::SiGfxKernel()
    : field_8(Unk_GetKernel()->vf12()), field_18(nullptr), field_20(0), field_28(0), field_30(0), field_38(0),
      field_40(0), field_48(0), field_50(0), field_58(0), field_60(0), field_68(0),
      field_98(Unk_GetKernel()->vf12()), field_e8(Unk_GetKernel()->vf12()), field_118(Unk_GetKernel()->vf12()),
      field_168(Unk_GetKernel()->vf12()), field_1d0(0), field_1d8(Unk_GetKernel()->vf12()), field_228(0),
      field_258(Unk_GetKernel()->vf12()), field_2a8(0) {
    Unk_276cff0 = this;
    UNK_REF_ASSIGN(field_18, Unk_GetKernel()->vf12());
    field_2b0 = 0;
}

// 0x71004cc1b0 (D2), 0x71004ccb00 (D0)
SiGfxKernel::~SiGfxKernel() {
    Unk_4cc450();
    Unk_276cff0 = nullptr;
}

// 0x71004ccb30
bool SiGfxKernel::Unk_4ccb30(ISiAllocator* pAllocator) {
    field_20++;
    if (field_20 != 1) {
        return true;
    }
    if (pAllocator != nullptr) {
        vf5(pAllocator);
    } else if (field_18 == nullptr) {
        vf5(Unk_GetKernel()->vf12());
    }
    Unk_4cd1b0();
    field_98.Unk_ReserveAtLeast(1);
    if (Unk_GetKernel()->vf15() == nullptr) {
        return false;
    }
#line 1798
    field_2b0 = UNK_SI_NEW(field_18, 0x10) SiGfxNXManager(field_18);
    if (field_2b0 != nullptr && !Unk_4f6c70_get(reinterpret_cast<u64>(field_2b0))) {
        UNK_RELEASE(field_2b0);
    }
#line 358
    field_30 = UNK_SI_NEW(field_18, 0x10) SiGfxShaderUtility(field_18);
    Unk_4e3c30_get(reinterpret_cast<u64>(field_30));
#line 361
    field_38 = UNK_SI_NEW(field_18, 0x10) SiGfxShaderGraphUtility(field_18);
    Unk_4da480_get(reinterpret_cast<u64>(field_38));
#line 364
    field_40 = reinterpret_cast<ISiInterface*>(UNK_SI_NEW(field_18, 0x10) SiGfxTextureUtility(field_18));
    Unk_4eac50_get(reinterpret_cast<u64>(field_40));
#line 367
    field_48 = reinterpret_cast<ISiInterface*>(UNK_SI_NEW(field_18, 0x10) SiGfxGeometryUtility(field_18));
    Unk_4d3180_get(reinterpret_cast<u64>(field_48));
#line 370
    SiGfxDisplayUtility* display = UNK_SI_NEW(field_18, 0x10) SiGfxDisplayUtility(field_18);
    field_50 = reinterpret_cast<ISiInterface*>(display);
    display->Unk_4d2e50();
#line 373
    SiGfxImageUtility* image = UNK_SI_NEW(field_18, 0x10) SiGfxImageUtility(field_18);
    field_58 = reinterpret_cast<ISiInterface*>(image);
    image->Unk_4d1150();
#line 376
    field_60 = reinterpret_cast<ISiInterface*>(UNK_SI_NEW(field_18, 0x10) SiGfxPerformanceUtility(field_18));
    Unk_4e2400_call(reinterpret_cast<Unk_4e2400*>(field_60));
    field_258.Unk_SetAllocator(field_18);
    field_258.Unk_ReserveAtLeast(0x100);
    Unk_4cd2a0();
    Unk_4cd490(field_18);
    reinterpret_cast<Unk_IOKernelInterface*>(Unk_57d030_get())
        ->vf19(&Unk_1eec778, Unk_2391358, Unk_567750_Version(3, 0, 0, 11));
    reinterpret_cast<Unk_IOKernelInterface*>(Unk_57d030_get())
        ->vf19(&Unk_1eec788, Unk_2391360, Unk_567750_Version(3, 0, 0, 2));
    reinterpret_cast<Unk_IOKernelInterface*>(Unk_57d030_get())
        ->vf19(&Unk_1eec798, Unk_2391368, Unk_567750_Version(3, 0, 0, 1));
    Unk_57d2a0_Info info;
    field_18->vf11(&info);
    char used[0x80];
    Unk_4c5930(used, sizeof(used), info.field_8);
    char total[0x80];
    Unk_4c5930(total, sizeof(total), info.field_28);
    return true;
}

// 0x71004cc450
void SiGfxKernel::Unk_4cc450() {
    if (field_20 == 0) {
        return;
    }
    field_20--;
    if (field_20 != 0) {
        return;
    }
    reinterpret_cast<SiIOKernel*>(Unk_57d030_get())->vf20(&Unk_1eec778);
    reinterpret_cast<SiIOKernel*>(Unk_57d030_get())->vf20(&Unk_1eec788);
    reinterpret_cast<SiIOKernel*>(Unk_57d030_get())->vf20(&Unk_1eec798);
    Unk_4cd960();
    Unk_276cfe8 = 1;
    vf36();
    field_118.Unk_4e3050();
    field_e8.Unk_Clear();
    field_168.field_30.Unk_Clear();
    field_168.field_0.Unk_Clear();
    field_98.Unk_4e3050();
    UNK_RELEASE(field_60);
    UNK_RELEASE(field_58);
    UNK_RELEASE(field_50);
    UNK_RELEASE(field_48);
    UNK_RELEASE(field_40);
    UNK_RELEASE(field_38);
    UNK_RELEASE(field_30);
    UNK_RELEASE(field_2b0);
    Unk_ReleaseAll(&field_1d8);
    Unk_GetKernel()->vf27(field_1d0);
    UNK_RELEASE(field_1d0);
    UNK_RELEASE(field_18);
}

// 0x71004cde00
void SiGfxKernel::vf5(ISiAllocator* pAllocator) {
    UNK_REF_ASSIGN(field_18, pAllocator);
    field_98.Unk_SetAllocator(field_18);
    field_e8.Unk_SetAllocator(field_18);
    field_118.Unk_SetAllocator(field_18);
    field_168.Unk_4ecd20(field_18);
}

// 0x71004ce080: the NX devices are the only kind (8) there is
ISiGfxDevice* SiGfxKernel::vf8(u32 kind, u32 arg2) {
    if (kind != 8 || field_2b0 == nullptr) {
        return nullptr;
    }
    // (SiGfxNXDevice derives from ISiGfxDevice: RTTI; the headers here don't say so)
    ISiGfxDevice* device = reinterpret_cast<ISiGfxDevice*>(field_2b0->Unk_4f6c80());
    if (device == nullptr) {
        return nullptr;
    }
    Unk_596640 lock(&field_68, true);
    field_98.Unk_Add(device);
    if (field_30 != nullptr && field_168.field_60) {
        field_30->Unk_4e65e0(8);
    }
    Unk_4ed060(8);
    Unk_57d2a0_Info info;
    field_18->vf11(&info);
    char used[0x80];
    Unk_4c5930(used, sizeof(used), info.field_8);
    char total[0x80];
    Unk_4c5930(total, sizeof(total), info.field_28);
    return device;
}

// 0x71004cd1b0
bool SiGfxKernel::Unk_4cd1b0() {
    field_1d0 = Unk_GetKernel()->vf23(nullptr);
    field_1d0->vf8();
    field_1d0->vf11(Unk_4ca820_arg0(), Unk_579c60(Unk_4ca820_arg0()));
    field_1d0->vf11(*Unk_GetKernel()->vf24(), Unk_579c60(*Unk_GetKernel()->vf24()));
    field_1d0->vf9();
    Unk_GetKernel()->vf26(Unk_1eeada8, field_1d0);
    return true;
}

// 0x71004ce1c0
ISiGfxDevice* SiGfxKernel::vf10(s32 index) {
    Unk_596640 lock(&field_68, true);
    return field_98.m_pData[index];
}

// 0x71004ce210
void SiGfxKernel::vf11(ISiGfxDevice* device) {
    Unk_596640 lock(&field_68, true);
    field_98.Unk_RemoveValue(device);
}

// 0x71004cd490
void SiGfxKernel::Unk_4cd490(ISiAllocator* pAllocator) {
    Unk_4cec00(pAllocator);
    Unk_RegisterDataType(pAllocator);
    Unk_RegisterDataTypeArray(pAllocator);
    Unk_RegisterDataTypeMatrix(pAllocator);
    Unk_4cef70(pAllocator);
    Unk_4cf0d0(pAllocator);
    Unk_4cf210(pAllocator);
    Unk_RegisterDataValue(pAllocator);
    Unk_RegisterDataValuePOD(pAllocator);
    Unk_RegisterNodeType(pAllocator);
    Unk_4cf400(pAllocator);
    Unk_RegisterFunctionNodeType(pAllocator);
    Unk_RegisterFunctionNode(pAllocator);
    Unk_RegisterShaderGraph(pAllocator);
}

// 0x71004cd960
void SiGfxKernel::Unk_4cd960() {
    Unk_UnregisterObject();
    Unk_UnregisterDataType();
    Unk_UnregisterDataTypeArray();
    Unk_UnregisterDataTypeMatrix();
    Unk_UnregisterDataTypePOD();
    Unk_UnregisterDataTypeStruct();
    Unk_UnregisterDataTypeVector();
    Unk_UnregisterDataValue();
    Unk_UnregisterDataValuePOD();
    Unk_UnregisterNodeType();
    Unk_UnregisterNode();
    Unk_UnregisterFunctionNodeType();
    Unk_UnregisterFunctionNode();
    Unk_UnregisterShaderGraph();
}

// 0x71004cd2a0
void SiGfxKernel::Unk_4cd2a0() {
    SiString<char> directory = Unk_582eb0();
    Unk_4ca0b0(&directory, "\\", "/", 0, 0, true);
    field_168.field_0 = directory;
    SiString<char> path(field_18);
    path = Unk_StringConcat(field_168.field_0, "/../shadercache");
    field_e8 = path;
}

// 0x71004ce3e0
void SiGfxKernel::vf26(const Unk_4ecbc0* settings) {
    field_168 = *settings;
    SiString<char> path(field_18);
    path = Unk_StringConcat(field_168.field_0, "/../shadercache");
    field_e8 = path;
}

// 0x71004ce580
void SiGfxKernel::vf28(const char* s) {
    Unk_StringAssign(&field_e8, s);
}

// 0x71004ce5b0
void SiGfxKernel::vf31(const char* name) {
    SiString<char> s;
    s.Unk_SetExternal(name);
    field_118.Unk_Add(s);
}

// 0x71004ce710
SiString<char>* SiGfxKernel::vf32(s32 index) {
    return &field_118.m_pData[index];
}

// 0x71004ce720
bool SiGfxKernel::vf33(ISiGfxKernel::EventHandler* pHandler) {
    if (pHandler == nullptr) {
        return false;
    }
    field_1d8.Unk_Add(pHandler);
    pHandler->vf2();
    return true;
}

// 0x71004ce7d0: takes it out, and drops the reference if it was there
void SiGfxKernel::vf34(ISiGfxKernel::EventHandler* pHandler) {
    if (pHandler == nullptr) {
        return;
    }
    if (Unk_RemoveCounted(&field_1d8, pHandler) != 0) {
        pHandler->vf3();
    }
}

// 0x71004ce8b0
void SiGfxKernel::Unk_4ce8b0() {
    for (s64 i = 0; i < static_cast<s32>(field_98.m_itemCount); i++) {
        field_98.m_pData[i]->vf78();
    }
    for (s64 i = 0; i < static_cast<s32>(field_1d8.m_itemCount); i++) {
        field_1d8.m_pData[i]->vf5();
    }
}

// 0x71004ce940
void SiGfxKernel::Unk_4ce940() {
    for (s64 i = 0; i < static_cast<s32>(field_98.m_itemCount); i++) {
        field_98.m_pData[i]->vf79();
    }
    for (s64 i = 0; i < static_cast<s32>(field_1d8.m_itemCount); i++) {
        field_1d8.m_pData[i]->vf6();
    }
}

// 0x71004cf5b0
void SiGfxKernel::vf36() {
    Unk_596640 lock(&field_228, true);
    Unk_276cfe8 = 1;
    for (DelayedDeletionEntry *p = field_258.field_30, *end = field_258.field_38; p != end; p++) {
        p->field_0->vf3();
    }
    field_258.Unk_4e3050();
    Unk_276cfe8 = 0;
}

}  // namespace SiSDK3

// 0x71004ceab0 (leafgen's name and type): destroys the resources whose frame
// has come, once a frame
void Unk_4ceab0(void* p) {
    SiSDK3::SiGfxKernel* self = static_cast<SiSDK3::SiGfxKernel*>(p);
    Unk_596640 lock(&self->field_228, true);
    Unk_276cfe8 = 1;
    u64 frame = Unk_4ee850_get();
    if (self->field_2a8 != frame) {
        self->field_2a8 = frame;
        size_t i = self->field_258.m_itemCount;
        while (i != 0) {
            i--;
            if (frame >= self->field_258.m_pData[i].field_8) {
                self->field_258.m_pData[i].field_0->vf3();
                self->field_258.RemoveByIndexNonStable(i);
            }
        }
        Unk_276cfe8 = 0;
    }
}

namespace SiSDK3 {

// 0x71004cf8b0 (SiCore's class, out of line in this translation unit, which
// makes the shader graph classes' properties)
SiReflectionPropertyBase::SiReflectionPropertyBase(const char* name, const char* typeName, s64 offset,
                                                   ISiAllocator* pAllocator)
    : m_pPrev(nullptr), m_pNext(nullptr), field_18(pAllocator, name), field_48(0), field_50(pAllocator, typeName),
      field_80(offset), field_88(0), field_90(0), field_98(0), field_a0(nullptr), field_a8(0) {
    field_48 = Unk_4c34a0(name);
}

}  // namespace SiSDK3

// The property classes this translation unit makes have their vtables and
// destructors here (implicit instantiations): SiReflectionPropertyEnum<
// SI_POD_TYPE>'s 0x71004cfcd0 (D2), 0x71004cfd80 (D0) and SiReflectionProperty<
// SiString<char>>'s 0x71004cf9f0 (D2), 0x71004cfa60 (D0). Explicitly
// instantiated, a D1 is an alias that its D0 doesn't inline.
