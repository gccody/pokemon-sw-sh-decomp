// Scope: common
// SiSDK3::SiGfxShaderGraphUtility (0x71004d9a50 to 0x71004dbc70). Its
// reference counts are its header's; vf4 and vf9 are lib/yebis/class's.
//
// The tables of the types it registers end with an entry of zeroes (the
// executable has 0x18 zero bytes after the nine vector types, 0x20 after the
// 45 matrix types and 0x18 after the four operators), and their loops run
// until an entry without a name. The compiler works the counts out from the
// tables, so the loops are counted ones in the code; what is left of the
// source's form is where an entry's address is computed (ahead of the first
// call, where the name was tested).
#define UNK_SIGFX_SHADERGRAPH_UTILITY_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/ShaderGraph/SiGfx_ShaderGraph_Utility_Impl.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_StringCompare.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/ShaderGraph/SiGfx_ShaderGraph_DataType_Matrix.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/ShaderGraph/SiGfx_ShaderGraph_DataType_POD.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/ShaderGraph/SiGfx_ShaderGraph_DataType_Vector.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/ShaderGraph/SiGfx_ShaderGraph_IOSlotType.h>

namespace SiSDK3 {

namespace {

// A scalar type: which, its name and its text. This table isn't in the
// executable: its loop is unrolled, with the three entries as constants (what
// is left of the loop are the array's addresses, computed once ahead of the
// first entry), so its form is the other tables'.
struct Unk_PodType {
    u32 field_0;
    const char* field_8;
    const char* field_10;
};

const Unk_PodType Unk_PodTypes[] = {
    {1, "bool", "bool"},
    {6, "int", "int"},
    {11, "float", "float"},
    {0, nullptr, nullptr},
};

// A vector type: its elements' scalar type, how many, its name and its text.
struct Unk_VectorType {
    u32 field_0;
    s32 field_4;
    const char* field_8;
    const char* field_10;
};
PKMN_SIZE_ASSERT(Unk_VectorType, 0x18);

// 0x710238ef10
const Unk_VectorType Unk_238ef10[] = {
    {1, 2, "bool2", "bool2"},     {1, 3, "bool3", "bool3"},     {1, 4, "bool4", "bool4"},
    {6, 2, "int2", "int2"},       {6, 3, "int3", "int3"},       {6, 4, "int4", "int4"},
    {11, 2, "float2", "float2"},  {11, 3, "float3", "float3"},  {11, 4, "float4", "float4"},
    {0, 0, nullptr, nullptr},
};

// A matrix type: its elements' scalar type, its two sizes, its name and its
// text.
struct Unk_MatrixType {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    const char* field_10;
    const char* field_18;
};
PKMN_SIZE_ASSERT(Unk_MatrixType, 0x20);

// 0x710238f000
const Unk_MatrixType Unk_238f000[] = {
    {1, 1, 2, "bool1x2", "bool1x2"},     {1, 1, 3, "bool1x3", "bool1x3"},     {1, 1, 4, "bool1x4", "bool1x4"},
    {1, 2, 1, "bool2x1", "bool2x1"},     {1, 2, 2, "bool2x2", "bool2x2"},     {1, 2, 3, "bool2x3", "bool2x3"},
    {1, 2, 4, "bool2x4", "bool2x4"},     {1, 3, 1, "bool3x1", "bool3x1"},     {1, 3, 2, "bool3x2", "bool3x2"},
    {1, 3, 3, "bool3x3", "bool3x3"},     {1, 3, 4, "bool3x4", "bool3x4"},     {1, 4, 1, "bool4x1", "bool4x1"},
    {1, 4, 2, "bool4x2", "bool4x2"},     {1, 4, 3, "bool4x3", "bool4x3"},     {1, 4, 4, "bool4x4", "bool4x4"},
    {6, 1, 2, "int1x2", "int1x2"},       {6, 1, 3, "int1x3", "int1x3"},       {6, 1, 4, "int1x4", "int1x4"},
    {6, 2, 1, "int2x1", "int2x1"},       {6, 2, 2, "int2x2", "int2x2"},       {6, 2, 3, "int2x3", "int2x3"},
    {6, 2, 4, "int2x4", "int2x4"},       {6, 3, 1, "int3x1", "int3x1"},       {6, 3, 2, "int3x2", "int3x2"},
    {6, 3, 3, "int3x3", "int3x3"},       {6, 3, 4, "int3x4", "int3x4"},       {6, 4, 1, "int4x1", "int4x1"},
    {6, 4, 2, "int4x2", "int4x2"},       {6, 4, 3, "int4x3", "int4x3"},       {6, 4, 4, "int4x4", "int4x4"},
    {11, 1, 2, "float1x2", "float1x2"},  {11, 1, 3, "float1x3", "float1x3"},  {11, 1, 4, "float1x4", "float1x4"},
    {11, 2, 1, "float2x1", "float2x1"},  {11, 2, 2, "float2x2", "float2x2"},  {11, 2, 3, "float2x3", "float2x3"},
    {11, 2, 4, "float2x4", "float2x4"},  {11, 3, 1, "float3x1", "float3x1"},  {11, 3, 2, "float3x2", "float3x2"},
    {11, 3, 3, "float3x3", "float3x3"},  {11, 3, 4, "float3x4", "float3x4"},  {11, 4, 1, "float4x1", "float4x1"},
    {11, 4, 2, "float4x2", "float4x2"},  {11, 4, 3, "float4x3", "float4x3"},  {11, 4, 4, "float4x4", "float4x4"},
    {0, 0, 0, nullptr, nullptr},
};

// An operator: its node type's name and text, and the operator.
struct Unk_Operator {
    const char* field_0;
    const char* field_8;
    const char* field_10;
};

// 0x710238f5c0
const Unk_Operator Unk_238f5c0[] = {
    {"A + B", "A + B", "+"},
    {"A - B", "A - B", "-"},
    {"A * B", "A * B", "*"},
    {"A / B", "A / B", "/"},
    {nullptr, nullptr, nullptr},
};

}  // namespace

// 0x71004d9a50
SiGfxShaderGraphUtility::SiGfxShaderGraphUtility(ISiAllocator* pAllocator)
    : field_8(pAllocator), field_18(pAllocator), field_68(pAllocator), field_b8(), field_108(), field_158(pAllocator),
      field_1a8(pAllocator), field_1f8(pAllocator) {}

// 0x71004d9be0 (D2), 0x71004da450 (D0)
SiGfxShaderGraphUtility::~SiGfxShaderGraphUtility() {
    Unk_4d9e80();
}

// 0x71004d9e80
void SiGfxShaderGraphUtility::Unk_4d9e80() {
    Unk_ReleaseItems(&field_68);
    Unk_ReleaseItems(&field_b8);
    Unk_ReleaseItems(&field_108);
    Unk_ReleaseItems(&field_158);
    Unk_ReleaseItems(&field_1a8);
    Unk_ReleaseItems(&field_1f8);
    vf8();
}

// 0x71004da490
bool SiGfxShaderGraphUtility::vf5() {
    Unk_4da4c0();
    Unk_4da8c0();
    return true;
}

// 0x71004da4c0
bool SiGfxShaderGraphUtility::Unk_4da4c0() {
    ISiAllocator* pAllocator = field_8.m_pAllocator;
    for (int i = 0; Unk_PodTypes[i].field_8 != nullptr; i++) {
        const Unk_PodType& type = Unk_PodTypes[i];
        SiGfxShaderGraphDataTypePOD* pType = SiGfxShaderGraphDataTypePOD::Unk_4dd0a0(pAllocator, type.field_0);
        pType->vf18(type.field_8);
        pType->vf12(type.field_10);
        field_68.Unk_Add(pType);
    }
    for (int i = 0; Unk_238ef10[i].field_8 != nullptr; i++) {
        const Unk_VectorType& type = Unk_238ef10[i];
        SiGfxShaderGraphDataTypeVector* pType =
            SiGfxShaderGraphDataTypeVector::Unk_4df1c0(pAllocator, type.field_0, type.field_4);
        pType->vf18(type.field_8);
        pType->vf12(type.field_10);
        field_b8.Unk_Add(pType);
    }
    for (int i = 0; Unk_238f000[i].field_10 != nullptr; i++) {
        const Unk_MatrixType& type = Unk_238f000[i];
        SiGfxShaderGraphDataTypeMatrix* pType =
            SiGfxShaderGraphDataTypeMatrix::Unk_4de980(pAllocator, type.field_0, type.field_4, type.field_8);
        pType->vf18(type.field_10);
        pType->vf12(type.field_18);
        field_108.Unk_Add(pType);
    }
    return true;
}

// 0x71004da8c0
bool SiGfxShaderGraphUtility::Unk_4da8c0() {
    ISiAllocator* pAllocator = field_8.m_pAllocator;
    for (int i = 0; Unk_238f5c0[i].field_0 != nullptr; i++) {
        const Unk_Operator& op = Unk_238f5c0[i];
        SiGfxShaderGraphOperatorNodeType* pType = SiGfxShaderGraphOperatorNodeType::Unk_4df9b0(pAllocator);
        pType->vf18(op.field_0);
        pType->vf12(op.field_8);
        Unk_StringAssign(&pType->field_160, op.field_10);
        {
            SiGfxShaderGraphIOSlotType* pSlotType = SiGfxShaderGraphIOSlotType::Unk_4dcbf0(pAllocator, 1);
            pSlotType->vf18("A");
            pSlotType->vf12("A");
            pSlotType->field_bc = true;
            pSlotType->field_bd = true;
            pSlotType->field_be = true;
            pType->Unk_4dc1e0(pSlotType);
            if (pSlotType != nullptr) {
                pSlotType->vf3();
            }
        }
        {
            SiGfxShaderGraphIOSlotType* pSlotType = SiGfxShaderGraphIOSlotType::Unk_4dcbf0(pAllocator, 1);
            pSlotType->vf18("B");
            pSlotType->vf12("B");
            pSlotType->field_bc = true;
            pSlotType->field_bd = true;
            pSlotType->field_be = true;
            pType->Unk_4dc1e0(pSlotType);
            if (pSlotType != nullptr) {
                pSlotType->vf3();
            }
        }
        {
            SiGfxShaderGraphIOSlotType* pSlotType = SiGfxShaderGraphIOSlotType::Unk_4dcbf0(pAllocator, 2);
            pSlotType->vf18("Out");
            pSlotType->vf12("Out");
            pSlotType->field_bc = true;
            pSlotType->field_bd = true;
            pSlotType->field_be = true;
            pType->Unk_4dc290(pSlotType);
            if (pSlotType != nullptr) {
                pSlotType->vf3();
            }
        }
        field_158.Unk_Add(pType);
    }
    return true;
}

// 0x71004dab30
bool SiGfxShaderGraphUtility::vf6(ISiGfxShaderGraphFactory* pFactory) {
    field_18.Unk_Add(pFactory);
    pFactory->vf2();
    return true;
}

// 0x71004dabd0
void SiGfxShaderGraphUtility::vf7(ISiGfxShaderGraphFactory* pFactory) {
    field_18.Unk_RemoveValue(pFactory);
    if (pFactory != nullptr) {
        pFactory->vf3();
    }
}

// 0x71004daca0
void SiGfxShaderGraphUtility::vf8() {
    Unk_ReleaseItems(&field_18);
}

// 0x71004dad60
ISiGfxShaderGraphFactory* SiGfxShaderGraphUtility::vf10(int index) {
    return field_18.m_pData[index];
}

// 0x71004dad70
SiGfxShaderGraphDataType* SiGfxShaderGraphUtility::vf11(const char* name) {
    for (s64 i = 0; i < static_cast<s32>(field_68.m_itemCount); i++) {
        SiGfxShaderGraphDataType* pType = field_68.m_pData[i];
        if (Unk_CompareNoCase(pType->vf19(), name) == 0) {
            return pType;
        }
    }
    for (s64 i = 0; i < static_cast<s32>(field_b8.m_itemCount); i++) {
        SiGfxShaderGraphDataType* pType = field_b8.m_pData[i];
        if (Unk_CompareNoCase(pType->vf19(), name) == 0) {
            return pType;
        }
    }
    for (s64 i = 0; i < static_cast<s32>(field_108.m_itemCount); i++) {
        SiGfxShaderGraphDataType* pType = field_108.m_pData[i];
        if (Unk_CompareNoCase(pType->vf19(), name) == 0) {
            return pType;
        }
    }
    return nullptr;
}

// 0x71004db0a0
bool SiGfxShaderGraphUtility::vf12(SiGfxShaderGraphNodeType* pType) {
    field_1f8.Unk_Add(pType);
    pType->vf2();
    return true;
}

// 0x71004db150
void SiGfxShaderGraphUtility::vf13(SiGfxShaderGraphNodeType* pType) {
    field_1f8.Unk_RemoveValue(pType);
    if (pType != nullptr) {
        pType->vf3();
    }
}

// 0x71004db220
SiGfxShaderGraphNodeType* SiGfxShaderGraphUtility::vf14(const char* name) {
    for (s64 i = 0; i < static_cast<s32>(field_1f8.m_itemCount); i++) {
        SiGfxShaderGraphNodeType* pType = field_1f8.m_pData[i];
        if (Unk_CompareNoCase(pType->vf19(), name) == 0) {
            return pType;
        }
    }
    return nullptr;
}

}  // namespace SiSDK3
