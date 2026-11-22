// Scope: common
// SiSDK3::SiGfxNXShaderProgram: its construction and destruction, its
// shaders, its name, and the reference counts its header defines. (Its small
// accessors are lib/yebis/class's.)
#define UNK_SIGFX_NX_SHADERPROGRAM_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_ShaderProgram_Impl.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_StringFuncs.h>

// NVN's entry points that only the shader program calls (nvn.h has them
// without their types).
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
    field_180 = 0;
    field_188 = 0;
    field_190 = 0;
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
