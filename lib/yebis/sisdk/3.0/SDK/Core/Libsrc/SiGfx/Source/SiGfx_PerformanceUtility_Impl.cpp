// Scope: common
// SiSDK3::SiGfxPerformanceUtility: its constructor and destructors and the
// release of what it holds, with its arrays' instances. The reference counts
// are its header's.
#define UNK_SIGFX_PERFORMANCEUTILITY_IMPL
#include <string.h>

#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/SiGfx_PerformanceUtility_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_Buffer_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_Device_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_RootSignature_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_VertexFormat_Impl.h>

namespace SiSDK3 {

class Unk_PerfDevice;

// The objects slot 5 makes, as it calls them (placeholder names and slots).
// What it draws into: slot 5 is its device, slot 35 what its colour target
// is (copied into the pipeline state's description).
class Unk_PerfTarget : public ISiInterface {
public:
    virtual Unk_PerfDevice* vf5();
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
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual const void* vf35();
};

// A pipeline state's description, as far as slot 5 fills it in.
struct Unk_PerfPipelineDesc {
    ISiInterface* field_0;  // the root signature
    ISiGfxShaderProgram* field_8;
    u32 field_10;
    u8 field_14[0x20];
    u8 field_34;
    u8 field_35;
    u8 field_36[0x2a];
    u8 field_60;
    s32 field_64;
    s32 field_68;
    s32 field_6c;
    s32 field_70;
    s32 field_74;
    s32 field_78;
    u8 field_7c[0xe4];
    s32 field_160;
    u8 field_164[4];
    u8 field_168[0x384];  // the vertex format's elements
    u8 field_4ec[0x28];   // the target's
};
PKMN_OFFSET_ASSERT(Unk_PerfPipelineDesc, field_160, 0x160);
PKMN_OFFSET_ASSERT(Unk_PerfPipelineDesc, field_4ec, 0x4ec);

// A pipeline state: slot 8 starts the changes, slot 9 makes it, slot 10 is
// its description.
class Unk_PerfPipelineState : public ISiInterface {
public:
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual u32 vf8();
    virtual bool vf9();
    virtual Unk_PerfPipelineDesc* vf10();
};

// A descriptor set: slot 8 starts it for a root signature, slot 9 sets the
// parameters' count, slot 10 one parameter's buffer, slot 16 ends it.
class Unk_PerfDescriptorSet : public ISiInterface {
public:
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual u32 vf8(ISiInterface* signature);
    virtual bool vf9(s32 count);
    virtual bool vf10(s32 index, u32 a2, SiGfxNXBuffer* buffer, u32 a4, u32 a5);
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual bool vf16();
};

// The device, as slot 5 asks it for the objects (SiGfxNXDevice's slots; their
// second parameters are 32-bit here).
class Unk_PerfDevice : public ISiInterface {
public:
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
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual Unk_PerfPipelineState* vf25(u32 a1, u32 a2, ISiAllocator* pAllocator);
    virtual SiGfxNXRootSignature* vf26(u32 a1, u32 a2, ISiAllocator* pAllocator);
    virtual void vf27();
    virtual Unk_PerfDescriptorSet* vf28(u32 a1, u32 a2, ISiAllocator* pAllocator);
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual SiGfxNXVertexFormat* vf39(size_t index);
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual ISiGfxShaderProgram* vf46(size_t index);
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual SiGfxNXBuffer* vf59(const void* desc, u32 a2, ISiAllocator* pAllocator);
};

// 0x71004e1bd0
SiGfxPerformanceUtility::SiGfxPerformanceUtility(ISiAllocator* pAllocator)
    : field_8(pAllocator), field_18(0), field_1c(0), field_20(true), field_21(false), field_24(), field_34(60.0f),
      field_38(14.0f), field_3c(5.0f), field_40(10.0f), field_44(0.5f), field_48(1), field_4c(-1), field_50(0),
      field_58(0), field_60(pAllocator), field_b0(pAllocator), field_100(0), field_160(pAllocator),
      field_1b0(pAllocator), field_200(pAllocator), field_250(pAllocator) {}

// 0x71004e1dc0 (D2), 0x71004e23d0 (D0)
SiGfxPerformanceUtility::~SiGfxPerformanceUtility() {
    Unk_4e1f40();
}

// 0x71004e1f40
void SiGfxPerformanceUtility::Unk_4e1f40() {
    field_60.Unk_FreeAll();
    field_b0.Unk_FreeAll();
    field_108.Unk_Release();
    field_160.Unk_4e3050();
    field_1b0.Unk_4e3050();
    field_200.Unk_4e3050();
    field_250.Unk_4e3050();
}

// 0x71004e2120
Unk_4e2120::~Unk_4e2120() {
    Unk_Release();
}

// 0x71004e2430
void SiGfxPerformanceUtility::Unk_4e2430(void*) {
    field_108.Unk_Release();
    for (s32 i = 0; i < static_cast<s32>(field_160.m_itemCount); i++) {
        field_160.m_pData[i].Unk_Reset();
    }
    for (s32 i = 0; i < static_cast<s32>(field_1b0.m_itemCount); i++) {
        field_1b0.m_pData[i].Unk_Reset();
    }
    for (s32 i = 0; i < static_cast<s32>(field_200.m_itemCount); i++) {
        field_200.m_pData[i].Unk_Reset();
    }
    for (s32 i = 0; i < static_cast<s32>(field_250.m_itemCount); i++) {
        field_250.m_pData[i].Unk_Reset();
    }
}

// 0x71004e25f0
// (it starts with Unk_4e2430's statements, written out: a call of it would
// be too costly to inline)
bool SiGfxPerformanceUtility::vf5(ISiInterface* target) {
    field_108.Unk_Release();
    for (s32 i = 0; i < static_cast<s32>(field_160.m_itemCount); i++) {
        field_160.m_pData[i].Unk_Reset();
    }
    for (s32 i = 0; i < static_cast<s32>(field_1b0.m_itemCount); i++) {
        field_1b0.m_pData[i].Unk_Reset();
    }
    for (s32 i = 0; i < static_cast<s32>(field_200.m_itemCount); i++) {
        field_200.m_pData[i].Unk_Reset();
    }
    for (s32 i = 0; i < static_cast<s32>(field_250.m_itemCount); i++) {
        field_250.m_pData[i].Unk_Reset();
    }
    if (target == nullptr) {
        return false;
    }
    Unk_PerfDevice* device = static_cast<Unk_PerfTarget*>(target)->vf5();
    ISiGfxShaderProgram* program = device->vf46(0x47);
    if (program == nullptr) {
        return false;
    }
    SiGfxNXVertexFormat* format = device->vf39(2);
    if (format == nullptr) {
        return false;
    }
    SiGfxNXRootSignature* signature = device->vf26(1, 0, nullptr);
    signature->vf8();
    signature->vf10(1);
    signature->vf12(0, 2, 1, 0, 0);
    signature->vf9();
    if (signature != nullptr) {
        signature->vf2();
    }
    if (field_108.field_0 != nullptr) {
        field_108.field_0->vf3();
    }
    field_108.field_0 = reinterpret_cast<ISiInterface*>(signature);
    Unk_PerfPipelineState* state = device->vf25(1, 0, nullptr);
    state->vf8();
    state->vf10()->field_0 = reinterpret_cast<ISiInterface*>(signature);
    state->vf10()->field_160 = 5;
    state->vf10()->field_10 = 1;
    state->vf10()->field_34 = 0;
    state->vf10()->field_35 = 0;
    state->vf10()->field_60 = 1;
    state->vf10()->field_6c = 1;
    state->vf10()->field_64 = 5;
    state->vf10()->field_68 = 6;
    state->vf10()->field_78 = 1;
    state->vf10()->field_70 = 5;
    state->vf10()->field_74 = 6;
    state->vf10()->field_8 = program;
    const void* targetInfo = static_cast<Unk_PerfTarget*>(target)->vf35();
    memcpy(state->vf10()->field_4ec, targetInfo, sizeof(Unk_PerfPipelineDesc::field_4ec));
    const void* elements = format->vf32();
    memcpy(state->vf10()->field_168, elements, sizeof(Unk_PerfPipelineDesc::field_168));
    state->vf9();
    if (state != nullptr) {
        state->vf2();
    }
    if (field_108.field_8 != nullptr) {
        field_108.field_8->vf3();
    }
    field_108.field_8 = state;
    if (signature != nullptr) {
        signature->vf3();
    }
    if (state != nullptr) {
        state->vf3();
    }
    for (s64 i = 0; i < field_108.field_14; i++) {
        SiGfxNXBuffer* buffer = device->vf59(nullptr, 0, nullptr);
        SiGfxNXBuffer::Unk_MakeDesc desc(0, 0, 0, 1, 1, 0);
        desc.field_4 = 0x80;
        desc.field_18 = 2;
        desc.field_1c = 4;
        desc.field_20 = 0x10000;
        buffer->vf21(&desc);
        field_108.field_18[i].field_8.m_p = reinterpret_cast<ISiInterface*>(buffer);
        Unk_PerfDescriptorSet* set = device->vf28(1, 0, nullptr);
        set->vf8(field_108.field_0);
        set->vf9(1);
        set->vf10(0, 0, reinterpret_cast<SiGfxNXBuffer*>(field_108.field_18[i].field_8.m_p), 0, 0);
        set->vf16();
        field_108.field_18[i].field_0.m_p = set;
    }
    return true;
}

// 0x71004e2c30
bool SiGfxPerformanceUtility::vf6(const Unk_Value* value) {
    field_24 = *value;
    return true;
}

// 0x71004e2c50
bool SiGfxPerformanceUtility::vf8(u32 mode) {
    if (field_18 != mode) {
        field_160.Unk_4e3050();
        field_1b0.Unk_4e3050();
        field_200.Unk_4e3050();
        field_250.Unk_4e3050();
        field_b0.Unk_FreeAll();
    }
    field_18 = mode;
    return true;
}

}  // namespace SiSDK3
