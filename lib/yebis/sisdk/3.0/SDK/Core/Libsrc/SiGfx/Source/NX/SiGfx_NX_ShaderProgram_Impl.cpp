// Scope: common
// SiSDK3::SiGfxNXShaderProgram: its construction and destruction, its
// shaders, its name, and the reference counts its header defines. (Its small
// accessors are lib/yebis/class's.)
#define UNK_SIGFX_NX_SHADERPROGRAM_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_ShaderProgram_Impl.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_StringFuncs.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_Device_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_ShaderInput_Impl.h>

// NVN's entry points that only the shader program calls (nvn.h has them
// without their types).
inline NvnBoolean Unk_nvnProgramInitialize(void* program, u64 device) {
    return reinterpret_cast<NvnBoolean (*)(void*, u64)>(Unk_27fc918)(program, device);
}
inline NvnBoolean Unk_nvnProgramSetShaders(void* program, s32 count, const SiSDK3::Unk_NXShaderData* stages) {
    return reinterpret_cast<NvnBoolean (*)(void*, s32, const SiSDK3::Unk_NXShaderData*)>(Unk_27fc930)(program, count, stages);
}
inline void Unk_nvnProgramFinalize(void* program) {
    reinterpret_cast<void (*)(void*)>(Unk_27fc920)(program);
}
inline void Unk_nvnProgramSetDebugLabel(void* program, const char* label) {
    reinterpret_cast<void (*)(void*, const char*)>(Unk_27fc928)(program, label);
}

// Drops a reference and clears the pointer (placeholder name).
#define UNK_SAFE_RELEASE(p)   \
    if ((p) != nullptr) {     \
        (p)->vf3();           \
        (p) = nullptr;        \
    }

namespace SiSDK3 {

// 0x7100559dc0
SiGfxNXShaderProgram::SiGfxNXShaderProgram(ISiAllocator* pAllocator, SiGfxNXDevice* pDevice)
    : field_10(pAllocator), field_20(pDevice), field_28(0), field_30(pAllocator), field_60(0), field_198(false) {
    field_80 = nullptr;
    field_88 = nullptr;
    field_90 = nullptr;
    field_98 = nullptr;
    field_a0 = nullptr;
    field_a8 = nullptr;
    field_b0 = nullptr;
    field_178 = 0;
    field_17c = 0;
    field_180[0] = 0;
    field_180[1] = 0;
    field_180[2] = 0;
    field_180[3] = 0;
    field_180[4] = 0;
    field_180[5] = 0;
    memset(&field_64, 0, sizeof(field_64));
    field_64.field_0 = 8;
    field_78.field_0 = 2;
}

// 0x7100559e70 (D2), 0x7100559fb0 (D0); 0x7100559f10 and 0x710055a050 are
// their thunks for the second base
SiGfxNXShaderProgram::~SiGfxNXShaderProgram() {
    if (field_28 != 0) {
        field_20->Unk_4f9640(Unk_NXResource(this));
        field_28 = 0;
    }
    vf22();
}

// 0x710055a100 (0x710055a170: its thunk)
bool SiGfxNXShaderProgram::vf40(const char* name) {
    Unk_4c4700(&field_30, const_cast<char*>(name));
    field_60 = Unk_4c3510(&field_30);
    if (field_198) {
        Unk_nvnProgramSetDebugLabel(field_b8, Unk_StringCStr(&field_30));
    }
    return true;
}

// 0x710055a1e0 (0x710055a1f0: its thunk)
const SiString<char>* SiGfxNXShaderProgram::vf41() {
    return &field_30;
}

// 0x710055a200 (0x710055a210: its thunk)
u32 SiGfxNXShaderProgram::vf42() {
    return field_60;
}

// 0x710055a2d0
bool SiGfxNXShaderProgram::vf18(Unk_NXProgramPart* a1, Unk_NXProgramPart* a2, Unk_NXProgramPart* a3,
                                Unk_NXProgramPart* a4, Unk_NXProgramPart* a5) {
    return Unk_55a2e0(a1, a2, a3, a4, a5, nullptr);
}

// 0x710055a2e0
bool SiGfxNXShaderProgram::Unk_55a2e0(Unk_NXProgramPart* a1, Unk_NXProgramPart* a2, Unk_NXProgramPart* a3,
                                      Unk_NXProgramPart* a4, Unk_NXProgramPart* a5, Unk_NXProgramPart* a6) {
    field_80 = a1;
    field_88 = a2;
    field_90 = a3;
    field_98 = a4;
    field_a0 = a5;
    field_a8 = a6;
    Unk_NXShaderData stages[5] = {};
    field_178 = 0;
    field_17c = 0;
    u32 coded = 0;
    u32 count = 0;
    if (field_a8 != nullptr) {
        field_a8->vf2();
        if (field_a8->vf20()) {
            stages[coded++] = *field_a8->vf21();
            field_178 |= 0x20;
            field_180[field_17c] = 5;
            field_17c++;
        }
        count++;
    }
    if (field_80 != nullptr) {
        field_80->vf2();
        if (field_80->vf20()) {
            stages[coded++] = *field_80->vf21();
            field_178 |= 0x1f;
            field_180[field_17c] = 0;
            field_17c++;
        }
        count++;
    }
    if (field_88 != nullptr) {
        field_88->vf2();
        if (field_88->vf20()) {
            stages[coded++] = *field_88->vf21();
            field_178 |= 2;
            field_180[field_17c] = 1;
            field_17c++;
        }
        count++;
    }
    if (field_90 != nullptr) {
        field_90->vf2();
        if (field_90->vf20()) {
            stages[coded++] = *field_90->vf21();
            field_178 |= 4;
            field_180[field_17c] = 2;
            field_17c++;
        }
        count++;
    }
    // (the original asks the vertex shader whether this one has its code)
    if (field_98 != nullptr) {
        field_98->vf2();
        if (field_80->vf20()) {
            stages[coded++] = *field_98->vf21();
            field_178 |= 8;
            field_180[field_17c] = 3;
            field_17c++;
        }
        count++;
    }
    if (field_a0 != nullptr) {
        field_a0->vf2();
        if (field_a0->vf20()) {
            stages[coded++] = *field_a0->vf21();
            field_178 |= 0x10;
            field_180[field_17c] = 4;
            field_17c++;
        }
        count++;
    }
    if (count == coded) {
        field_78.field_4 = true;
        UNK_SAFE_RELEASE(field_b0);
        if (field_80 != nullptr) {
#line 674
            SiGfxNXShaderInput* pInput = UNK_SI_NEW(field_10.m_pAllocator, 0x10) SiGfxNXShaderInput(field_10.m_pAllocator, field_20);
            field_b0 = reinterpret_cast<Unk_NXProgramPart*>(pInput);
            pInput->Unk_55ac60(this);
        }
    } else {
        field_78.field_4 = false;
    }
    u64 device = field_20->vf85();
    if (Unk_nvnProgramInitialize(field_b8, device) == 1) {
        if (Unk_nvnProgramSetShaders(field_b8, count, stages) == 1) {
            field_198 = true;
            Unk_nvnProgramSetDebugLabel(field_b8, Unk_StringCStr(&field_30));
            return true;
        }
        Unk_nvnProgramFinalize(field_b8);
    }
    return false;
}

// 0x710055a760
bool SiGfxNXShaderProgram::vf20(Unk_NXProgramPart* a1) {
    Unk_55a2e0(nullptr, nullptr, nullptr, nullptr, nullptr, a1);
    return true;
}

// 0x710055a7a0
void SiGfxNXShaderProgram::vf22() {
    UNK_SAFE_RELEASE(field_b0);
    UNK_SAFE_RELEASE(field_80);
    UNK_SAFE_RELEASE(field_88);
    UNK_SAFE_RELEASE(field_90);
    UNK_SAFE_RELEASE(field_98);
    UNK_SAFE_RELEASE(field_a0);
    UNK_SAFE_RELEASE(field_a8);
    if (field_198) {
        Unk_nvnProgramFinalize(field_b8);
        memset(field_b8, 0, sizeof(field_b8));
        field_198 = false;
    }
    field_78.field_4 = false;
}

// 0x710055aa70
bool SiGfxNXShaderProgram::vf37() {
    if (vf26() != nullptr && vf28() != nullptr && vf36() == nullptr) {
        return true;
    }
    if (vf26() == nullptr && vf28() == nullptr && vf36() == nullptr) {
        return false;
    }
    return false;
}

}  // namespace SiSDK3
