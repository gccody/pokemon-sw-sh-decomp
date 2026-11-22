// SiSDK3::SiGfxShaderGraphUtility (RTTI names the class and its interface):
// the shader graph's registry of data types, node types and factories.
// Placeholder members; the virtual functions are vf<slot>. The reference
// counts are defined in this header (their __FILE__), at the original's
// lines, for the class's own translation unit
// (UNK_SIGFX_SHADERGRAPH_UTILITY_IMPL).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_Array.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_4bf660.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_Interface.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/ShaderGraph/SiGfx_ShaderGraph_NodeType_Operator.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/ShaderGraph/Unk_4dbcf0.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/ShaderGraph/Unk_4dd4b0.h>

namespace SiSDK3 {

// RTTI: SiSDK3::SiArray<SiSDK3::ISiGfxShaderGraphFactory*, 16>. The utility
// only counts its references (slots 2 and 3).
class ISiGfxShaderGraphFactory : public ISiInterface {};

// RTTI: SiSDK3::SiArray<SiSDK3::SiGfxShaderGraphIntrinsicNodeType*, 16>. A
// node type by its name; the utility only releases the ones it has (slot 3),
// and nothing in the executable makes one.
class SiGfxShaderGraphIntrinsicNodeType : public SiGfxShaderGraphNodeType {};

// RTTI: SiSDK3::ISiGfxShaderGraphUtility
class ISiGfxShaderGraphUtility : public ISiInterface {
public:
    virtual bool vf5() = 0;
    virtual bool vf6(ISiGfxShaderGraphFactory* pFactory) = 0;
    virtual void vf7(ISiGfxShaderGraphFactory* pFactory) = 0;
    virtual void vf8() = 0;
    virtual u32 vf9() = 0;
    virtual ISiGfxShaderGraphFactory* vf10(int index) = 0;
    virtual SiGfxShaderGraphDataType* vf11(const char* name) = 0;
    virtual bool vf12(SiGfxShaderGraphNodeType* pType) = 0;
    virtual void vf13(SiGfxShaderGraphNodeType* pType) = 0;
    virtual SiGfxShaderGraphNodeType* vf14(const char* name) = 0;
};

class SiGfxShaderGraphUtility : public ISiGfxShaderGraphUtility {
public:
    explicit SiGfxShaderGraphUtility(ISiAllocator* pAllocator);  // 0x71004d9a50
    virtual ~SiGfxShaderGraphUtility();                          // 0x71004d9be0, 0x71004da450
    UNK_REFCOUNT_DECLARE;                                        // 0x71004db360, 0x71004db380
    virtual u32 vf4();                                           // 0x71004db400 (lib/yebis/class)
    virtual bool vf5();                                          // 0x71004da490: the types every graph has
    virtual bool vf6(ISiGfxShaderGraphFactory* pFactory);        // 0x71004dab30: one more factory
    virtual void vf7(ISiGfxShaderGraphFactory* pFactory);        // 0x71004dabd0: one less
    virtual void vf8();                                          // 0x71004daca0: none
    virtual u32 vf9();                                           // 0x71004dad50 (lib/yebis/class): how many
    virtual ISiGfxShaderGraphFactory* vf10(int index);           // 0x71004dad60
    virtual SiGfxShaderGraphDataType* vf11(const char* name);    // 0x71004dad70: a data type by its name
    virtual bool vf12(SiGfxShaderGraphNodeType* pType);          // 0x71004db0a0: one more node type
    virtual void vf13(SiGfxShaderGraphNodeType* pType);          // 0x71004db150: one less
    virtual SiGfxShaderGraphNodeType* vf14(const char* name);    // 0x71004db220: a node type by its name

    void Unk_4d9e80();  // 0x71004d9e80: releases everything
    bool Unk_4da4c0();  // 0x71004da4c0: the scalar, vector and matrix types
    bool Unk_4da8c0();  // 0x71004da8c0: the operators' node types

    Unk_4bf660 field_8;
    SiArray<ISiGfxShaderGraphFactory*, 16> field_18;
    SiArray<SiGfxShaderGraphDataType*, 16> field_68;                     // the scalar types
    SiArray<SiGfxShaderGraphDataType*, 16> field_b8;                     // the vector types
    SiArray<SiGfxShaderGraphDataType*, 16> field_108;                    // the matrix types
    SiArray<SiGfxShaderGraphOperatorNodeType*, 16> field_158;
    SiArray<SiGfxShaderGraphIntrinsicNodeType*, 16> field_1a8;
    SiArray<SiGfxShaderGraphNodeType*, 16> field_1f8;
};
PKMN_OFFSET_ASSERT(SiGfxShaderGraphUtility, field_18, 0x18);
PKMN_OFFSET_ASSERT(SiGfxShaderGraphUtility, field_158, 0x158);
PKMN_OFFSET_ASSERT(SiGfxShaderGraphUtility, field_1f8, 0x1f8);
PKMN_SIZE_ASSERT(SiGfxShaderGraphUtility, 0x248);

}  // namespace SiSDK3

#ifdef UNK_SIGFX_SHADERGRAPH_UTILITY_IMPL
// 0x71004db360 (vf2), 0x71004db380 (vf3)
#line 31
UNK_REFCOUNT_DEFINE(SiSDK3::SiGfxShaderGraphUtility, field_8.m_pAllocator, field_8.m_count)
#endif
