// Scope: common
// SiSDK3::SiGfxShaderGraphDataValue (0x71004ddcf0 to 0x71004de4f0).
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/ShaderGraph/SiGfx_ShaderGraph_DataValue_POD.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/ShaderGraph/SiGfx_ShaderGraph_DataValue_Vector.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/ShaderGraph/Unk_4ddcf0.h>

// 0x710276d810
void* Unk_276d810;

namespace SiSDK3 {

// 0x71004ddcf0
SiGfxShaderGraphDataValue::SiGfxShaderGraphDataValue(ISiAllocator* pAllocator, SiGfxShaderGraphDataType* pType)
    : SiGfxShaderGraphObject(pAllocator), field_b8(1), field_c0(pType), field_c8(pAllocator) {
    field_8 = this;
    field_10 = Unk_276d810;
}

// 0x71004ddd90 (D2), 0x71004ddf70 (D0); the other bases' thunks: 0x71004ddf40,
// 0x71004ddf50, 0x71004ddf60 and 0x71004ddfa0, 0x71004ddfd0, 0x71004de000
SiGfxShaderGraphDataValue::~SiGfxShaderGraphDataValue() {
    SiGfxShaderGraphDataValue::vf8();
}

// 0x71004de030
bool SiGfxShaderGraphDataValue::vf7() {
    if (!SiGfxShaderGraphObject::vf7()) {
        return false;
    }
    vf18(Unk_StringCStr(field_c0->vf19()));
    vf12(Unk_StringCStr(field_c0->vf13()));
    s32 count = static_cast<s32>(field_c0->field_b8.m_itemCount);
    if (count > 0) {
        field_c8.Unk_ReserveAtLeast(count);
        for (s64 i = 0; i < static_cast<s32>(field_c0->field_b8.m_itemCount); i++) {
            SiGfxShaderGraphDataType* pType = field_c0->field_b8.m_pData[i];
            SiGfxShaderGraphDataValue* pValue = nullptr;
            switch (pType->vf16()) {
            case 1:
                pValue = SiGfxShaderGraphDataValuePOD::Unk_4dd820(Unk_Allocator(),
                                                                  static_cast<SiGfxShaderGraphDataTypePOD*>(pType));
                break;
            case 2:
                pValue = SiGfxShaderGraphDataValueVector::Unk_4de570(
                    Unk_Allocator(), static_cast<SiGfxShaderGraphDataTypeVector*>(pType));
                break;
            }
            if (pValue != nullptr) {
                field_c8.Unk_Add(pValue);
            }
        }
    }
    return true;
}

// 0x71004de240
void SiGfxShaderGraphDataValue::vf8() {
    Unk_ReleaseItems(&field_c8);
    SiGfxShaderGraphObject::vf8();
}

}  // namespace SiSDK3
