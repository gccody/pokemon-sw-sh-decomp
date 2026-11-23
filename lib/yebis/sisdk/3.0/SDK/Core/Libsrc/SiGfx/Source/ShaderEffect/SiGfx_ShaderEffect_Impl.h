// SiSDK3::SiGfxShaderEffect, SiSDK3::SiGfxShaderEffect::CompileRequestCallback, SiSDK3::SiGfxShaderEffect::ShaderProgramMap: as far as the executable's functions show
// them, with placeholder members (RTTI names the classes). The reference
// counts are defined in this header (their __FILE__), at the original's lines,
// for the classes' own translation unit (UNK_SIGFX_SHADEREFFECT_IMPL).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_Array.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_Map.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_String.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_Interface.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_4bf660.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiGfx/ShaderCache/SiGfx_ShaderCache.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/ShaderEffect/SiGfx_ShaderEffectKey.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiOS/Source/Unk_596410.h>

namespace SiSDK3 {

class SiGfxShaderEffectPackage;

// Two numbers that are read and written one after the other and copied as one
// (placeholder name: the package's description has them, an effect a copy).
struct Unk_567750_Pair {
    s32 field_0;
    s32 field_4;
};

template <class K, int ALIGN>
struct SiMapCompareLess;

class SiGfxShaderEffect {
public:
    // What a compile request calls when it is done (slot 5): it tells the
    // effect.
    class CompileRequestCallback {
    public:
        // (it reads the effect's allocator itself, after its vtable is stored)
        explicit CompileRequestCallback(SiGfxShaderEffect* effect);
        virtual ~CompileRequestCallback() {}  // 0x71005792d0, 0x71005792f0
        UNK_REFCOUNT_DECLARE;
        virtual u32 vf4();
        virtual void vf5(ISiGfxShaderCache::CompileRequest* request);  // 0x71005793e0

        Unk_4bf660 field_8;
        SiGfxShaderEffect* field_18;
    };

    // 0x7100578c30: a compile request is done: its shader is made, and the
    // program once all its stages are
    void Unk_578c30(ISiGfxShaderCache::CompileRequest* request);

    // A program's key in the map and what the map holds for it (RTTI: the
    // map's arguments). The key is the 0x18 bytes between a node's map and
    // its value.
    struct ShaderProgramKey {
        ShaderProgramKey() = default;
        // member by member: the map's insert (0x7100577ce0) copies the key
        // as six 32-bit values, which it keeps in registers for its search
        ShaderProgramKey(const ShaderProgramKey& other)
            : field_0(other.field_0), field_4(other.field_4), field_8(other.field_8), field_c(other.field_c),
              field_10(other.field_10), field_14(other.field_14) {}
        // in the order of its numbers (inline in the map's search)
        bool operator<(const ShaderProgramKey& other) const {
            if (field_0 < other.field_0) {
                return true;
            }
            if (field_0 > other.field_0) {
                return false;
            }
            if (field_4 < other.field_4) {
                return true;
            }
            if (field_4 > other.field_4) {
                return false;
            }
            if (field_8 < other.field_8) {
                return true;
            }
            if (field_8 > other.field_8) {
                return false;
            }
            if (field_c < other.field_c) {
                return true;
            }
            if (field_c > other.field_c) {
                return false;
            }
            if (field_10 < other.field_10) {
                return true;
            }
            if (field_10 > other.field_10) {
                return false;
            }
            return field_14 < other.field_14;
        }

        u32 field_0;
        s32 field_4;
        u32 field_8;
        s32 field_c;
        u32 field_10;
        u32 field_14;
    };
    PKMN_SIZE_ASSERT(ShaderProgramKey, 0x18);
    struct ShaderProgramCompileEntry {
        // 0x7100577730: for a program's two keys (copied into the entry's own
        // bytes) and the indices of its stages' shaders
        ShaderProgramCompileEntry(ISiAllocator* pAllocator, const SiGfxShaderEffectKey* key0,
                                  const SiGfxShaderEffectKey* key1, const u32* indices);
        ~ShaderProgramCompileEntry() { Unk_56e820(); }
        // 0x710056e820: releases what it holds
        void Unk_56e820();

        ISiAllocator* field_0;
        SiGfxShaderEffectKey field_8;  // the keys, in the bytes after them
        SiArray<u8, 16> field_20;
        SiGfxShaderEffectKey field_70;
        SiArray<u8, 16> field_88;
        u32 field_d8[6];  // the stages' shaders' indices
        u32 field_f0;
        ISiGfxShaderCache::CompileRequest* field_f8[6];  // the compile request of each stage
        ISiInterface* field_128[6];                      // and the shader made from it
        // (whether it failed)
        bool field_158[6];
        ISiInterface* field_160;
        s32 field_168;
    };
    PKMN_OFFSET_ASSERT(ShaderProgramCompileEntry, field_88, 0x88);
    PKMN_OFFSET_ASSERT(ShaderProgramCompileEntry, field_160, 0x160);
    // what slots 12 and 13 tell of a program (placeholder): the program, its
    // state and its key
    struct Unk_ProgramRequest {
        Unk_ProgramRequest() : field_0(0), field_8(0), field_c() {}

        u64 field_0;
        s32 field_8;  // 1: none, 2: failed, 4: asked for, 5: made
        ShaderProgramKey field_c;
    };
    PKMN_SIZE_ASSERT(Unk_ProgramRequest, 0x28);

    // The programs of an effect's data, by their keys, and a lock (RTTI
    // names the class and its map).
    class ShaderProgramMap {
    public:
        explicit ShaderProgramMap(ISiAllocator* pAllocator) : field_8(pAllocator), field_18(0), field_48(pAllocator) {}
        virtual ~ShaderProgramMap();
        UNK_REFCOUNT_DECLARE;
        virtual u32 vf4();

        Unk_4bf660 field_8;
        Unk_CriticalSection field_18;
        SiMap<ShaderProgramKey, ShaderProgramCompileEntry*, SiMapCompareLess<ShaderProgramKey, 16>, 16> field_48;
        u64 field_68;  // (its constructor leaves it as it is)
    };
    PKMN_SIZE_ASSERT(ShaderProgramMap, 0x70);

    // A technique's program and what it holds (RTTI: the arrays'
    // arguments).
    struct ShaderProgramData {
        // (zeroed: the arrays' reserve clears new elements with a memset)
        ShaderProgramData() : field_0(nullptr), field_8(0), field_10(0) {}
        ~ShaderProgramData() {
            if (field_0 != nullptr) {
                field_0->vf3();
                field_0 = nullptr;
            }
        }

        ISiInterface* field_0;
        u64 field_8;   // the package's program
        u64 field_10;  // the technique it's in
    };
    struct TechniqueData {
        explicit TechniqueData(ISiAllocator* pAllocator)
            : field_0(nullptr), field_8(0), field_10(pAllocator), field_60(pAllocator) {}

        void* field_0;  // the package's technique
        u32 field_8;    // its index
        SiArray<ShaderProgramData, 16> field_10;
        SiArray<ShaderProgramData*, 16> field_60;  // the same in the package's other order
    };
    PKMN_OFFSET_ASSERT(TechniqueData, field_60, 0x60);
    PKMN_SIZE_ASSERT(TechniqueData, 0xb0);

    // 0x71005761f0
    SiGfxShaderEffect(ISiAllocator* pAllocator, void* owner);
    virtual ~SiGfxShaderEffect();  // 0x7100576480, 0x7100576750
    UNK_REFCOUNT_DECLARE;
    virtual u32 vf4();
    virtual u64 vf5();
    virtual u64 vf6();
    virtual void vf7(const char* name);  // sets the name
    virtual const u8* vf8();             // the name
    virtual const u8* vf9();
    virtual u64 vf10();
    virtual u64 vf11();
    // a program of two keys and strings: what's known of it, asked for if
    // it isn't (name: the effect's, for the variation list)
    virtual Unk_ProgramRequest vf12(const char* name, const SiGfxShaderEffectKey* key0,
                                    const SiGfxShaderEffectKey* key1, const SiArray<SiString<char>, 16>* strings);
    virtual void vf13(Unk_ProgramRequest* request);  // what's known of a program
    virtual bool vf14(void* owner, const char* name);  // adds it to SiGfx's kernel's owner
    virtual void vf15(u64 value, u64 arg2);
    virtual void vf16(u64 value, u64 arg2);
    virtual void vf17();  // asks for the programs that are missing
    virtual void vf18(bool value);
    virtual u8 vf19();
    virtual void vf20();  // forgets the compile entries

    // 0x71005765b0: releases what it holds; 0x7100576780, 0x71005769e0: its
    // techniques and its programs
    void Unk_5765b0();
    void Unk_576780();
    void Unk_5769e0();
    // 0x71005785d0: asks for a program
    // 0x71005785d0: makes a program from its shaders
    bool Unk_5785d0(void* program, void* unused);
    // 0x7100578100: the program of two keys: the technique's first for
    // keys without bytes, else a binary search of its sorted programs
    // (inline: its caller's translation unit has its copy)
    inline ShaderProgramData* Unk_578100(const SiGfxShaderEffectKey* key0, const SiGfxShaderEffectKey* key1);

    Unk_4bf660 field_8;
    void* field_18;          // what made it
    SiString<char> field_20;  // the name
    u32 field_50;            // the name's hash
    u32 field_54;
    bool field_58;
    u8 field_59;
    u8 field_5a;
    u8 field_5b;
    SiOSCriticalSection field_60;
    // the package's numbers (its description's field_4 and field_8): the
    // constructor zeroes field_94 again as one 8-byte store, after field_90's
    u32 field_90;
    Unk_567750_Pair field_94;
    ISiInterface* field_a0;
    ISiInterface* field_a8;
    SiGfxShaderEffectPackage* field_b0;  // the package it's in
    void* field_b8;  // its package's data of its name (ISiGfxShaderEffectPackage::ShaderEffectData)
    SiArray<TechniqueData*, 16> field_c0;
    ShaderProgramMap* field_110;
    SiArray<ShaderProgramCompileEntry*, 16> field_118;
    u64 field_168;
    CompileRequestCallback* field_170;
};
PKMN_SIZE_ASSERT(SiGfxShaderEffect, 0x178);
PKMN_OFFSET_ASSERT(SiGfxShaderEffect, field_60, 0x60);
PKMN_OFFSET_ASSERT(SiGfxShaderEffect, field_118, 0x118);

inline SiGfxShaderEffect::CompileRequestCallback::CompileRequestCallback(SiGfxShaderEffect* effect)
    : field_8(effect->field_8.m_pAllocator), field_18(effect) {}

inline void SiGfxShaderEffect::CompileRequestCallback::vf5(ISiGfxShaderCache::CompileRequest* request) {
    if (field_18 != nullptr) {
        field_18->Unk_578c30(request);
    }
}

}  // namespace SiSDK3

#ifdef UNK_SIGFX_SHADEREFFECT_IMPL
// 0x710056db50 (vf2), 0x710056db70 (vf3)
#line 531
UNK_REFCOUNT_DEFINE(SiSDK3::SiGfxShaderEffect::ShaderProgramMap, field_8.m_pAllocator, field_8.m_count)

// 0x7100579220 (vf2), 0x7100579240 (vf3)
#line 36
UNK_REFCOUNT_DEFINE(SiSDK3::SiGfxShaderEffect, field_8.m_pAllocator, field_8.m_count)

// 0x7100579330 (vf2), 0x7100579350 (vf3)
#line 626
UNK_REFCOUNT_DEFINE(SiSDK3::SiGfxShaderEffect::CompileRequestCallback, field_8.m_pAllocator, field_8.m_count)
#endif

#ifdef UNK_SIGFX_SHADEREFFECTPACKAGE_IMPL
// 0x710056d950 (D2), 0x710056db20 (D0): the map's entries are deleted, each
// in its turn (an entry takes itself out of the map), under the lock. This
// header is its __FILE__; defined for the package's translation unit, where
// the original has it.
// NON_MATCHING: registers and frame: the original keeps the lock's address
// for the critical section's destructor in a register it spills (a frame 16
// bytes larger); this one computes it again. Tried: a scope, the critical
// section cast or in a local, `> 0`, the map by reference, the allocator read
// first, the two tests joined.
SiSDK3::SiGfxShaderEffect::ShaderProgramMap::~ShaderProgramMap() {
    Unk_596640 lock(field_18.Unk_Get(), true);
    while (field_48.m_count != 0) {
        ShaderProgramCompileEntry* entry = field_48.m_pRoot->m_value;
        if (entry != nullptr) {
            ISiAllocator* pAllocator = field_48.m_pAllocator;
            if (pAllocator != nullptr) {
                entry->~ShaderProgramCompileEntry();
#line 548
                SI_FREE(pAllocator, entry);
            }
        }
    }
}
#endif
