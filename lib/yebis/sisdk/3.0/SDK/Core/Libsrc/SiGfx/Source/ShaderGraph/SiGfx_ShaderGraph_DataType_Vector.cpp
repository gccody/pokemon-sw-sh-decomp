// Scope: common
// SiSDK3::SiGfxShaderGraphDataTypeVector (0x71004df1c0 to 0x71004df930). The
// file's name is the __FILE__ of its allocation. vf16 is lib/yebis/class's.
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/ShaderGraph/SiGfx_ShaderGraph_DataType_POD.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/ShaderGraph/SiGfx_ShaderGraph_DataType_Vector.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/ShaderGraph/SiGfx_ShaderGraph_DataValue_Vector.h>

// 0x710276da10
void* Unk_276da10;

namespace SiSDK3 {

// 0x71004df1c0
SiGfxShaderGraphDataTypeVector* SiGfxShaderGraphDataTypeVector::Unk_4df1c0(ISiAllocator* pAllocator, u32 kind,
                                                                           s32 count) {
    SiGfxShaderGraphDataTypeVector* p;
#line 38
    p = UNK_SI_NEW(pAllocator, 0x10) SiGfxShaderGraphDataTypeVector(pAllocator, kind, count);
    if (p != nullptr) {
        if (!p->vf7()) {
            p->vf3();
            p = nullptr;
        }
    }
    return p;
}

// 0x71004df280 (D2), 0x71004df3c0 (D0); the other bases' thunks: 0x71004df2d0,
// 0x71004df320, 0x71004df370 and 0x71004df410, 0x71004df470, 0x71004df4d0
SiGfxShaderGraphDataTypeVector::~SiGfxShaderGraphDataTypeVector() {
    SiGfxShaderGraphDataTypeVector::vf8();
}

// 0x71004df530
bool SiGfxShaderGraphDataTypeVector::vf7() {
    if (!SiGfxShaderGraphDataType::vf7()) {
        return false;
    }
    field_b8.Unk_ReserveAtLeast(field_10c);
    if (field_10c > 0) {
        SiGfxShaderGraphDataTypePOD* pType = SiGfxShaderGraphDataTypePOD::Unk_4dd0a0(Unk_Allocator(), field_108);
        pType->vf18("x");
        pType->vf12("x");
        field_b8.Unk_Add(pType);
    }
    if (field_10c > 1) {
        SiGfxShaderGraphDataTypePOD* pType = SiGfxShaderGraphDataTypePOD::Unk_4dd0a0(Unk_Allocator(), field_108);
        pType->vf18("y");
        pType->vf12("y");
        field_b8.Unk_Add(pType);
    }
    if (field_10c > 2) {
        SiGfxShaderGraphDataTypePOD* pType = SiGfxShaderGraphDataTypePOD::Unk_4dd0a0(Unk_Allocator(), field_108);
        pType->vf18("z");
        pType->vf12("z");
        field_b8.Unk_Add(pType);
    }
    if (field_10c > 3) {
        SiGfxShaderGraphDataTypePOD* pType = SiGfxShaderGraphDataTypePOD::Unk_4dd0a0(Unk_Allocator(), field_108);
        pType->vf18("w");
        pType->vf12("w");
        field_b8.Unk_Add(pType);
    }
    return true;
}

// 0x71004df900
void SiGfxShaderGraphDataTypeVector::vf8() {
    SiGfxShaderGraphDataType::vf8();
}

// 0x71004df910
SiGfxShaderGraphDataValue* SiGfxShaderGraphDataTypeVector::vf17() {
    return SiGfxShaderGraphDataValueVector::Unk_4de570(Unk_Allocator(), this);
}

}  // namespace SiSDK3
