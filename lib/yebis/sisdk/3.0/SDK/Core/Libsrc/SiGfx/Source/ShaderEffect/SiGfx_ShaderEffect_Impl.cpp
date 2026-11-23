// Scope: common
// SiSDK3::SiGfxShaderEffect, SiSDK3::SiGfxShaderEffect::CompileRequestCallback,
// SiSDK3::SiGfxShaderEffect::ShaderProgramMap: the effect's factory,
// construction, destruction and some of its slots, and the reference counts
// their header defines.
#define UNK_SIGFX_SHADEREFFECT_IMPL
#define UNK_SIMAP_MEMBERS_DEFINE
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/ShaderEffect/SiGfx_ShaderEffect_Impl.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_StringFuncs.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/ShaderEffect/SiGfx_ShaderEffectPackage_Impl.h>

// 0x71004cbf40: SiGfx's kernel (leafgen's name and type)
u64 Unk_4cbf40_get();
// 0x71004c3510: a string's hash, 0x71004c3410: bytes'
u32 Unk_4c3510(const SiSDK3::SiString<char>* s);
u32 Unk_4c3410(s64 size, const u8* bytes);

using SiSDK3::SiGfxShaderEffect;

// (the strings' arrays' destructor is instantiated in lib/yebis/instances, the
// programs' by the package's translation unit)
extern template SiSDK3::SiArray<SiSDK3::SiString<char>, 16>::~SiArray();
extern template SiSDK3::SiArray<SiGfxShaderEffect::ShaderProgramData, 16>::~SiArray();

// SiGfx's kernel as the effect uses it (placeholders): slot 12 is what keeps
// the shaders, whose slot 17 queues compile requests and whose slot 8 gives
// what an owner's effects are added to.
class Unk_CompileQueue {
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
    virtual void vf10(SiSDK3::ISiGfxShaderCache::CompileRequest* request);  // queues one
    virtual void vf11();
    virtual void vf12();
    virtual void vf13(SiGfxShaderEffect::CompileRequestCallback* callback);  // adds one
    virtual void vf14(SiGfxShaderEffect::CompileRequestCallback* callback);  // removes it
};

class Unk_EffectOwner {
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
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual bool vf22(SiGfxShaderEffect* effect);
};

class Unk_ShaderSystem {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual Unk_EffectOwner* vf8(void* owner);
    virtual void vf9();
    virtual bool vf10();  // whether names that aren't found are told
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual Unk_CompileQueue* vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    // the shader of a compile request, if it's known
    virtual SiSDK3::ISiInterface* vf21(SiSDK3::ISiGfxShaderCache::CompileRequest* request, void* device);
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    // fills a compile request
    virtual void vf25(SiSDK3::ISiGfxShaderCache::CompileRequest* request, u32 a1, u32 a2,
                      const SiSDK3::Unk_567750_Pair* pair0, u32 b1, u32 b2, const SiSDK3::Unk_567750_Pair* pair1,
                      u32 stage, u32 c1, u32 c2, const char* code0, const char* code1,
                      const SiSDK3::SiGfxShaderEffectKey* key0, const char* text0,
                      const SiSDK3::SiGfxShaderEffectKey* key1, const char* text1,
                      const SiSDK3::SiArray<SiSDK3::SiString<char>, 16>* strings);
};

class Unk_GfxKernel {
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
    virtual Unk_ShaderSystem* vf12();
};

inline Unk_GfxKernel* Unk_GetGfxKernel() {
    return reinterpret_cast<Unk_GfxKernel*>(Unk_4cbf40_get());
}

// A new effect, with its compile requests' callback (placeholder name).
// 0x7100576110
SiSDK3::SiGfxShaderEffect* Unk_576110(SiSDK3::ISiAllocator* pAllocator, void* owner) {
#line 68
    SiSDK3::SiGfxShaderEffect* effect = UNK_SI_NEW(pAllocator, 0x10) SiSDK3::SiGfxShaderEffect(pAllocator, owner);
    if (effect != nullptr) {
        Unk_CompileQueue* queue = Unk_GetGfxKernel()->vf12()->vf17();
        if (queue != nullptr) {
#line 523
            SiGfxShaderEffect::CompileRequestCallback* callback = UNK_SI_NEW(effect->field_8.m_pAllocator, 0x10)
                SiGfxShaderEffect::CompileRequestCallback(effect);
            effect->field_170 = callback;
            queue->vf13(callback);
        }
    }
    return effect;
}

namespace SiSDK3 {

// 0x71005761f0
SiGfxShaderEffect::SiGfxShaderEffect(ISiAllocator* pAllocator, void* owner)
    : field_8(pAllocator), field_18(owner), field_20(pAllocator), field_50(0), field_54(0), field_58(false),
      field_60(0), field_94(), field_a0(nullptr), field_a8(nullptr), field_b0(nullptr), field_b8(nullptr),
      field_c0(pAllocator), field_110(nullptr), field_118(pAllocator) {
    field_5b = 0;
    field_59 = 0;
    field_5a = 0;
    field_90 = 0;
    field_94 = Unk_567750_Pair();
    field_168 = 0;
    field_170 = nullptr;
    field_118.Unk_ReserveAtLeast(8);
}

// 0x7100576480 (D2), 0x7100576750 (D0)
SiGfxShaderEffect::~SiGfxShaderEffect() {
    Unk_5765b0();
}

// 0x71005765b0
void SiGfxShaderEffect::Unk_5765b0() {
    Unk_576780();
    if (field_170 != nullptr) {
        Unk_ShaderSystem* system = Unk_GetGfxKernel()->vf12();
        if (system != nullptr) {
            Unk_CompileQueue* queue = system->vf17();
            if (queue != nullptr) {
                queue->vf14(field_170);
            }
        }
        if (field_170 != nullptr) {
            field_170->vf3();
            field_170 = nullptr;
        }
    }
    Unk_5769e0();
    if (field_b0 != nullptr) {
        field_b0->Unk_56d040(this);
    }
}

// 0x7100576bb0
void SiGfxShaderEffect::vf7(const char* name) {
    Unk_StringAssign(&field_20, name);
    field_50 = Unk_4c3510(&field_20);
}

// 0x7100578a30
bool SiGfxShaderEffect::vf14(void* owner, const char* name) {
    Unk_ShaderSystem* system = Unk_GetGfxKernel()->vf12();
    if (system == nullptr) {
        return false;
    }
    Unk_EffectOwner* effects = system->vf8(owner);
    if (effects == nullptr) {
        return false;
    }
    if (owner != nullptr) {
        vf7(name);
    }
    return effects->vf22(this);
}

// 0x7100578be0
void SiGfxShaderEffect::vf20() {
    Unk_596640 lock(&field_60, true);
    field_118.Unk_Clear();
}

// 0x7100578890
void SiGfxShaderEffect::vf13(Unk_ProgramRequest* request) {
    Unk_596640 lock(&field_60, true);
    if (request->field_8 != 4) {
        return;
    }
    ShaderProgramKey key;
    key.field_0 = request->field_c.field_0;
    key.field_4 = request->field_c.field_4;
    key.field_8 = request->field_c.field_8;
    key.field_c = request->field_c.field_c;
    key.field_10 = request->field_c.field_10;
    key.field_14 = request->field_c.field_14;
    if (field_110 == nullptr) {
        request->field_8 = 1;
        return;
    }
    Unk_596640 mapLock(field_110->field_18.Unk_Get(), true);
    auto it = field_110->field_48.Unk_Find(key);
    if (it.m_pNode == nullptr) {
        request->field_8 = 1;
    } else {
        ShaderProgramCompileEntry* entry = it.m_pNode->m_value;
        request->field_8 = entry->field_168;
        request->field_0 = reinterpret_cast<u64>(entry->field_160);
    }
}

// What a program's shaders are found from (placeholder names): the stages it
// has, then the index of its shader of each stage.
// a key's bytes made room for, from another key (inline: placeholder name)
static inline void Unk_ReserveKey(SiGfxShaderEffectKey* key, SiArray<u8, 16>* bytes, const SiGfxShaderEffectKey* src) {
    s32 count = src->field_c;
    if (count >= 1) {
        bytes->Unk_SetCount(count);
        key->Unk_Set(src->field_c, bytes->m_pData);
    }
}
// and copied (inline: placeholder name)
static inline void Unk_CopyKey(SiGfxShaderEffectKey* key, const SiGfxShaderEffectKey* src) {
    key->field_8 = src->field_8;
    if (key->field_c >= 1) {
        memcpy(key->field_10, src->field_10, key->field_c);
    }
}

// 0x7100577730
SiGfxShaderEffect::ShaderProgramCompileEntry::ShaderProgramCompileEntry(ISiAllocator* pAllocator,
                                                                        const SiGfxShaderEffectKey* key0,
                                                                        const SiGfxShaderEffectKey* key1,
                                                                        const u32* indices)
    : field_0(pAllocator), field_20(pAllocator), field_88(pAllocator) {
    for (int i = 0; i < 6; i++) {
        field_d8[i] = indices[i];
    }
    field_f0 = 0;
    field_168 = 4;
    field_160 = nullptr;
    for (int i = 0; i < 6; i++) {
        field_f8[i] = nullptr;
        field_128[i] = nullptr;
        field_158[i] = false;
    }
    Unk_ReserveKey(&field_8, &field_20, key0);
    Unk_ReserveKey(&field_70, &field_88, key1);
    Unk_CopyKey(&field_8, key0);
    Unk_CopyKey(&field_70, key1);
}

// What the package's slot 18 returns as the effect reads it (placeholder):
// nonzero at 0x20 when its shaders can't be made from its code.
struct Unk_PackageCodeInfo {
    u8 _0[0x20];
    u32 field_20;
};
struct Unk_ProgramStageInfo {
    u8 _0[8];
    u32 field_8;  // a bit for each stage
};
struct Unk_ProgramShaderIndices {
    u8 _0[0x118];
    s32 field_118[6];  // the vertex shader's first, the compute shader's last
};
// The effect's variation (placeholder view): slots 9 and 13 write the values
// of a key into a string (SiGfxShaderEffectVariation's).
class Unk_EffectVariation {
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
    virtual bool vf9(SiString<char>* out, u32 a1, u32 a2, const SiGfxShaderEffectKey* key);
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual bool vf13(SiString<char>* out, u32 a1, u32 a2, const SiGfxShaderEffectKey* key);
};

// The device and its programs as the effect makes them (placeholders): the
// device's slot 45 makes a program, whose slot 18 takes its graphics shaders
// and slot 20 its compute shader.
class Unk_EffectProgram {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual u32 vf3();
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
    virtual bool vf18(ISiGfxShader* s1, ISiGfxShader* s2, ISiGfxShader* s3, ISiGfxShader* s5, ISiGfxShader* s4);
    virtual void vf19();
    virtual bool vf20(ISiGfxShader* s6);
    virtual void vf21();
    virtual void vf22();
    virtual bool vf23();  // whether it's linked
};
class Unk_EffectDevice {
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
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual ISiGfxShader* vf42(u32 stage, void* a2, u32 a3, void* a4);  // makes a shader of a stage
    virtual void vf43();
    virtual void vf44();
    virtual Unk_EffectProgram* vf45(void* a1, u32 a2, void* a3);
};

// the shader of a stage if the program has it (inline: placeholder name; it
// is passed the builder's second argument, which it doesn't use)
inline bool Unk_GetStageShader(SiGfxShaderEffect* self, SiGfxShaderEffect::ShaderProgramData* program, void*,
                               Unk_ProgramStageInfo** info, u32 bit, s32 stage, s32 slot, ISiGfxShader** shader) {
    *shader = nullptr;
    if ((*info)->field_8 & bit) {
        if (reinterpret_cast<const Unk_PackageCodeInfo*>(self->field_b0->vf18())->field_20 != 0) {
            return false;
        }
        s32 index = reinterpret_cast<const Unk_ProgramShaderIndices*>(program->field_8)->field_118[slot];
        if (index < 0) {
            return false;
        }
        *shader = self->field_b0->Unk_56ce60(static_cast<ISiGfxDevice*>(self->field_18), stage, index);
        if (*shader == nullptr) {
            return false;
        }
    }
    return true;
}

// 0x71005785d0
bool SiGfxShaderEffect::Unk_5785d0(void* p, void* unused) {
    ShaderProgramData* program = static_cast<ShaderProgramData*>(p);
    void* device = field_18;
    if (program == nullptr || device == nullptr) {
        return false;
    }
    if (program->field_8 == 0) {
        return false;
    }
    Unk_ProgramStageInfo** info = reinterpret_cast<Unk_ProgramStageInfo**>(program->field_10);
    ISiGfxShader* s1;
    ISiGfxShader* s2;
    ISiGfxShader* s3;
    ISiGfxShader* s5;
    ISiGfxShader* s4;
    ISiGfxShader* s6;
    if (!Unk_GetStageShader(this, program, unused, info, 1, 1, 0, &s1) ||
        !Unk_GetStageShader(this, program, unused, info, 2, 2, 1, &s2) ||
        !Unk_GetStageShader(this, program, unused, info, 4, 3, 2, &s3) ||
        !Unk_GetStageShader(this, program, unused, info, 0x10, 5, 3, &s5) ||
        !Unk_GetStageShader(this, program, unused, info, 8, 4, 4, &s4) ||
        !Unk_GetStageShader(this, program, unused, info, 0x20, 6, 5, &s6)) {
        return false;
    }
    Unk_EffectProgram* made = reinterpret_cast<Unk_EffectDevice*>(field_18)->vf45(nullptr, 0, nullptr);
    if (made == nullptr) {
        return false;
    }
    if (s6 != nullptr ? made->vf20(s6) : made->vf18(s1, s2, s3, s5, s4)) {
        program->field_0 = reinterpret_cast<ISiInterface*>(made);
        return true;
    }
    made->vf3();
    return false;
}

// whether a technique's program is the one of two keys (inline: placeholder
// name)
static inline bool Unk_ProgramMatches(const SiGfxShaderEffect::ShaderProgramData* program,
                                      const SiGfxShaderEffectKey* key0, const SiGfxShaderEffectKey* key1) {
    const ISiGfxShaderEffectPackage::ShaderProgramData* data =
        reinterpret_cast<const ISiGfxShaderEffectPackage::ShaderProgramData*>(program->field_8);
    return data->field_38.Unk_Compare(*key0) == 0 && data->field_a8.Unk_Compare(*key1) == 0;
}

// the program of two keys among sorted programs, by a binary search (inline:
// placeholder name; its keys are references, whose loads are hoisted out of
// the search before it's inlined)
static inline SiGfxShaderEffect::ShaderProgramData* Unk_FindProgram(SiGfxShaderEffect::ShaderProgramData** programs,
                                                                   s32 count, const SiGfxShaderEffectKey& key0,
                                                                   const SiGfxShaderEffectKey& key1) {
    s32 low = 0;
    s32 high = count - 1;
    while (low < high - 1) {
        s32 mid = (low + high) >> 1;
        const ISiGfxShaderEffectPackage::ShaderProgramData* data =
            reinterpret_cast<const ISiGfxShaderEffectPackage::ShaderProgramData*>(programs[mid]->field_8);
        int c0 = data->field_38.Unk_Compare(key0);
        int c1 = data->field_a8.Unk_Compare(key1);
        if (c0 > 0) {
            high = mid;
        } else if (c0 < 0) {
            low = mid;
        } else if (c1 > 0) {
            high = mid;
        } else if (c1 < 0) {
            low = mid;
        } else {
            return programs[mid];
        }
    }
    if (Unk_ProgramMatches(programs[low], &key0, &key1)) {
        return programs[low];
    }
    if (Unk_ProgramMatches(programs[high], &key0, &key1)) {
        return programs[high];
    }
    return nullptr;
}

// 0x7100578100
// NON_MATCHING: the returns: the original has a `mov x0, xzr ; ret` of its own
// for each `return nullptr` (each early test, each byte compare), this one
// block they all branch to; and a register order in the search's midpoint
// (`add w17, w12, w18` for the original's `add w17, w18, w12`). The tests
// and the search are the original's (the keys' loads are hoisted out of it
// because the search's keys are references). Tried: the function not
// inline, the midpoint as `(high + low) >> 1`.
inline SiGfxShaderEffect::ShaderProgramData* SiGfxShaderEffect::Unk_578100(const SiGfxShaderEffectKey* key0,
                                                                          const SiGfxShaderEffectKey* key1) {
    s32 index = key0->field_8;
    if (index < 0) {
        return nullptr;
    }
    if (index >= static_cast<s32>(field_c0.m_itemCount)) {
        return nullptr;
    }
    TechniqueData* technique = field_c0.m_pData[index];
    if (technique == nullptr) {
        return nullptr;
    }
    if (key0->field_10 == nullptr && key1->field_10 == nullptr) {
        if (technique->field_10.m_itemCount == 0) {
            return nullptr;
        }
        return technique->field_10.m_pData;
    }
    size_t count = technique->field_60.m_itemCount;
    if (count == 0) {
        return nullptr;
    }
    ShaderProgramData** programs = technique->field_60.m_pData;
    if (count == 1) {
        if (Unk_ProgramMatches(programs[0], key0, key1)) {
            return programs[0];
        }
        return nullptr;
    }
    return Unk_FindProgram(programs, count, *key0, *key1);
}

// SiArray's RemoveByIndex as the original has it here (as
// SiGfx_NX_CommandList_Impl.cpp has it): an assert that the build's NDEBUG
// doesn't compile out, at its line of the header, then the elements after it
// moved down (inline: the strings are the header's). The loop is tested
// before it's entered with the count first: written as a plain `for`, its
// guard is the same compare as its latch and the two are merged, which puts
// the assert, shared by two copies, between them.
template <class T, int ALIGN>
inline void Unk_RemoveByIndexAt(SiArray<T, ALIGN>* array, size_t iIndex) {
    if (!(iIndex < array->m_itemCount)) {
        __assert_fail("iIndex<m_itemCount", "../../../../Include\\SiCore/SiCore_Array.h", 1007, "RemoveByIndex");
    }
    s64 i = iIndex + 1;
    if (static_cast<s64>(array->m_itemCount) > i) {
        do {
            array->m_pData[i - 1] = array->m_pData[i];
            i++;
        } while (i < static_cast<s64>(array->m_itemCount));
    }
    array->m_itemCount--;
    array->Unk_UpdateRange();
}

// The bit of each stage in a technique's stages, and the stage's number
// (placeholder names: the order of the six shaders, compute last).
static const u32 Unk_StageBits[6] = {1, 2, 4, 0x10, 8, 0x20};
static const u32 Unk_Stages[6] = {1, 2, 3, 5, 4, 6};

// releases the shaders a compile entry's requests made (inline: placeholder
// name)
static inline void Unk_ReleaseShaders(SiGfxShaderEffect::ShaderProgramCompileEntry* entry) {
    for (s32 k = 0; k < 6; k++) {
        if (entry->field_128[k] != nullptr) {
            entry->field_128[k]->vf3();
            entry->field_128[k] = nullptr;
        }
    }
}

// 0x7100578c30
void SiGfxShaderEffect::Unk_578c30(ISiGfxShaderCache::CompileRequest* request) {
    Unk_596640 lock(&field_60, true);
    size_t i = field_118.m_itemCount;
    ShaderProgramCompileEntry* entry;
    s64 stage;
    while (i != 0) {
        i--;
        entry = field_118.m_pData[i];
        for (stage = 0; stage < 6; stage++) {
            if (entry->field_f8[stage] != nullptr && entry->field_f8[stage]->field_30 == request->field_30) {
                goto found;
            }
        }
    }
    return;
found:
    ISiGfxShader* shader = reinterpret_cast<Unk_EffectDevice*>(field_18)->vf42(Unk_Stages[stage], nullptr, 0, nullptr);
    if (shader != nullptr) {
        bool failed;
        if (shader->vf18(request->field_2c0.m_itemCount, request->field_2c0.m_pData, true)) {
            entry->field_128[stage] = reinterpret_cast<ISiInterface*>(shader);
            failed = false;
        } else {
            shader->vf3();
            failed = true;
        }
        entry->field_158[stage] = failed;
        request->field_310 |= 0xc;
    }
    bool done = true;
    bool failed = false;
    for (s32 k = 0; k < 6; k++) {
        if (entry->field_f0 & Unk_StageBits[k]) {
            if (entry->field_128[k] != nullptr || entry->field_158[k]) {
                if (entry->field_158[k]) {
                    failed = true;
                }
            } else {
                done = false;
            }
        }
    }
    if (!done) {
        if (!failed) {
            return;
        }
        Unk_RemoveByIndexAt(&field_118, i);
        Unk_ReleaseShaders(entry);
    } else {
        if (!failed) {
            Unk_EffectProgram* program = reinterpret_cast<Unk_EffectDevice*>(field_18)->vf45(nullptr, 0, nullptr);
            if (program != nullptr) {
                if (entry->field_128[5] != nullptr) {
                    program->vf20(reinterpret_cast<ISiGfxShader*>(entry->field_128[5]));
                } else {
                    program->vf18(reinterpret_cast<ISiGfxShader*>(entry->field_128[0]),
                                  reinterpret_cast<ISiGfxShader*>(entry->field_128[1]),
                                  reinterpret_cast<ISiGfxShader*>(entry->field_128[2]),
                                  reinterpret_cast<ISiGfxShader*>(entry->field_128[3]),
                                  reinterpret_cast<ISiGfxShader*>(entry->field_128[4]));
                }
                if (program->vf23()) {
                    entry->field_160 = reinterpret_cast<ISiInterface*>(program);
                } else {
                    program->vf3();
                }
            }
        }
        Unk_ReleaseShaders(entry);
        Unk_RemoveByIndexAt(&field_118, i);
        if (entry->field_160 != nullptr) {
            entry->field_168 = 5;
            return;
        }
    }
    entry->field_168 = 3;
}

// an effect's package's data (inline: placeholder name)
static inline ISiGfxShaderEffectPackage::ShaderEffectData* Unk_EffectData(SiGfxShaderEffect* effect) {
    return static_cast<ISiGfxShaderEffectPackage::ShaderEffectData*>(effect->field_b8);
}

// SiArray's insertion at the front as the original has it here: room made as
// Unk_Add makes it, then ShiftData's assert (which the build's NDEBUG doesn't
// compile out) and the elements moved up (inline: placeholder name; the
// strings are the header's).
template <class T, int ALIGN>
inline bool Unk_InsertFirst(SiArray<T, ALIGN>* array, const T& value) {
    if (array->m_itemCount >= array->m_reservedCount) {
        size_t step = array->field_40;
        size_t count;
        if (step != 0) {
            count = step + array->m_reservedCount;
        } else {
            count = array->m_reservedCount * 2 != 0 ? array->m_reservedCount * 2 : 1;
        }
        if (!array->Unk_4bf190(count, true)) {
            array->m_itemCount = 0;
            array->field_30 = nullptr;
            array->field_38 = nullptr;
            return false;
        }
    }
    if (!(static_cast<s64>(array->m_itemCount) + 1 <= static_cast<s64>(array->m_reservedCount))) {
        __assert_fail("((SI_INT_T)m_itemCount+iDirection)<=(SI_INT_T)m_reservedCount",
                      "../../../../Include\\SiCore/SiCore_Array.h", 1551, "ShiftData");
    }
    for (s64 i = static_cast<s64>(array->m_itemCount) - 1; i >= 0; i--) {
        array->m_pData[i + 1] = array->m_pData[i];
    }
    array->m_pData[0] = value;
    array->m_itemCount++;
    array->field_30 = array->m_pData;
    array->field_38 = array->m_pData + array->m_itemCount;
    return true;
}

// 0x7100576c30
// NON_MATCHING: registers and spills: the original keeps key1 in x21 until
// the compile entry is made (and spills it then, to sp+0x70), this spills it
// right after the hashes; the stack slots of the technique, the description
// and the options are 8 bytes off; the found key's copy pairs other stores
// (the original stores the program's state alone, then the key's words in
// pairs from 0xc; tried: the key assigned as a whole, which copies it in
// 64-bit words, and the three assignments in other orders).
// (The hash 0x71004c3410 takes a 64-bit size now, which gives the keys'
// sizes' `ldrsw x0`.)
SiGfxShaderEffect::Unk_ProgramRequest SiGfxShaderEffect::vf12(const char* name, const SiGfxShaderEffectKey* key0,
                                                              const SiGfxShaderEffectKey* key1,
                                                              const SiArray<SiString<char>, 16>* strings) {
    Unk_596640 lock(&field_60, true);
    Unk_ShaderSystem* system = Unk_GetGfxKernel()->vf12();
    Unk_ProgramRequest result;
    result.field_8 = 1;
    if (field_168 != 0 && !field_b0->vf25() && !field_58 && Unk_GetGfxKernel()->vf12()->vf10()) {
        reinterpret_cast<SiGfxShaderEffectVariationList*>(field_168)
            ->vf5(reinterpret_cast<Unk_571440_Arg*>(this), nullptr, *key0, *key1, strings);
    }
    if (field_54 != 1) {
        ShaderProgramData* program = Unk_578100(key0, key1);
        if (program != nullptr) {
            if (program->field_0 == nullptr && field_18 != nullptr) {
                Unk_5785d0(program, nullptr);
            }
            if (program->field_0 != nullptr) {
                result.field_0 = reinterpret_cast<u64>(program->field_0);
                result.field_8 = 5;
                return result;
            }
        }
        result.field_8 = 1;
        return result;
    }
    if (field_b0 == nullptr || field_b8 == nullptr) {
        return result;
    }
    s32 index = key0->field_8;
    if (index >= static_cast<s32>(Unk_EffectData(this)->field_60.m_itemCount)) {
        return result;
    }
    ShaderProgramKey key = ShaderProgramKey();
    key.field_0 = index;
    key.field_4 = key0->field_c;
    key.field_8 = key0->field_c >= 1 ? Unk_4c3410(key0->field_c, key0->field_10) : 0;
    key.field_c = key1->field_c;
    key.field_10 = key1->field_c >= 1 ? Unk_4c3410(key1->field_c, key1->field_10) : 0;
    if (strings != nullptr && strings->m_itemCount != 0) {
        key.field_14 = 0;
        for (size_t i = 0; i < strings->m_itemCount; i++) {
            key.field_14 ^= Unk_4c3510(&strings->m_pData[i]);
        }
    } else {
        key.field_14 = 0;
    }
    if (field_110 != nullptr) {
        field_110->field_18.Unk_Get()->SiOSCriticalSection::vf2();
    }
    if (field_110 != nullptr) {
        auto it = field_110->field_48.Unk_Find(key);
        if (it.m_pNode != nullptr) {
            ShaderProgramCompileEntry* entry = it.m_pNode->m_value;
            result.field_8 = entry->field_168;
            result.field_c.field_0 = key.field_0;
            result.field_c.field_4 = key.field_4;
            result.field_c.field_8 = key.field_8;
            result.field_c.field_c = key.field_c;
            result.field_c.field_10 = key.field_10;
            result.field_c.field_14 = key.field_14;
            result.field_0 = reinterpret_cast<u64>(entry->field_160);
            field_110->field_18.Unk_Get()->SiOSCriticalSection::vf3();
            return result;
        }
    }
    {
        ISiGfxShaderEffectPackage::TechniqueData* technique = Unk_EffectData(this)->field_60.m_pData[index];
        Unk_CompileQueue* queue = system->vf17();
        const Unk_567750_Desc* desc = reinterpret_cast<const Unk_567750_Desc*>(field_b0->vf18());
        const Unk_567b80* options = reinterpret_cast<const Unk_567b80*>(field_b0->vf17());
        SiString<char> text0(field_8.m_pAllocator);
        SiString<char> text1(field_8.m_pAllocator);
        if (field_a0 != nullptr) {
            if (key0->field_c >= 1 &&
                !reinterpret_cast<Unk_EffectVariation*>(field_a0)->vf9(&text0, desc->field_0.field_0,
                                                                      desc->field_0.field_4, key0)) {
                result.field_8 = 2;
                if (field_110 != nullptr) {
                    field_110->field_18.Unk_Get()->SiOSCriticalSection::vf3();
                }
                return result;
            }
            if (key1->field_c != 0 &&
                !reinterpret_cast<Unk_EffectVariation*>(field_a0)->vf13(&text1, desc->field_0.field_0,
                                                                       desc->field_0.field_4, key1)) {
                result.field_8 = 2;
                if (field_110 != nullptr) {
                    field_110->field_18.Unk_Get()->SiOSCriticalSection::vf3();
                }
                return result;
            }
        }
#line 832
        ShaderProgramCompileEntry* entry = UNK_SI_NEW(field_8.m_pAllocator, 0x10)
            ShaderProgramCompileEntry(field_8.m_pAllocator, key0, key1, reinterpret_cast<const u32*>(&key));
        if (entry == nullptr) {
            result.field_8 = 2;
            if (field_110 != nullptr) {
                field_110->field_18.Unk_Get()->SiOSCriticalSection::vf3();
            }
            return result;
        }
        const SiString<char>* sources[6] = {&technique->field_10,  &technique->field_70,  &technique->field_d0,
                                            &technique->field_130, &technique->field_190, &technique->field_1f0};
        for (s64 k = 0; k < 6; k++) {
            if (technique->field_8 & Unk_StageBits[k]) {
                if (entry->field_128[k] != nullptr) {
                    continue;
                }
#line 866
                ISiGfxShaderCache::CompileRequest* request = UNK_SI_NEW(field_8.m_pAllocator, 0x10)
                    ISiGfxShaderCache::CompileRequest(field_8.m_pAllocator);
                system->vf25(request, desc->field_0.field_0, desc->field_0.field_4, &desc->field_0.field_8,
                             desc->field_10.field_0, desc->field_10.field_4, &desc->field_10.field_8, Unk_Stages[k],
                             options->field_f0, options->field_e8, Unk_StringCStr(sources[k]),
                             Unk_StringCStr(sources[k] + 1), key0, Unk_StringCStr(&text0), key1,
                             Unk_StringCStr(&text1), strings);
                entry->field_f8[k] = request;
                ISiInterface* shader = system->vf21(request, field_18);
                if (shader != nullptr) {
                    entry->field_128[k] = shader;
                    shader->vf2();
                } else {
                    if (field_168 != 0 && !field_58 && Unk_GetGfxKernel()->vf12()->vf10() && name != nullptr &&
                        *name != 0) {
                        reinterpret_cast<SiGfxShaderEffectVariationList*>(field_168)->vf7(name);
                    }
                    if (queue != nullptr) {
                        queue->vf10(request);
                    }
                }
            } else {
                entry->field_f8[k] = nullptr;
            }
        }
        entry->field_f0 = technique->field_8;
        if (field_110 != nullptr) {
            field_110->field_48.Unk_4c09a0(key, entry);
        }
        bool ready = true;
        for (s32 k = 0; k < 6; k++) {
            if (entry->field_f0 & Unk_StageBits[k]) {
                ready &= entry->field_128[k] != nullptr;
            }
        }
        if (ready) {
            entry->field_168 = 5;
            result.field_8 = 5;
            Unk_EffectProgram* program = reinterpret_cast<Unk_EffectDevice*>(field_18)->vf45(nullptr, 0, nullptr);
            if (entry->field_128[5] != nullptr) {
                program->vf20(reinterpret_cast<ISiGfxShader*>(entry->field_128[5]));
            } else {
                program->vf18(reinterpret_cast<ISiGfxShader*>(entry->field_128[0]),
                              reinterpret_cast<ISiGfxShader*>(entry->field_128[1]),
                              reinterpret_cast<ISiGfxShader*>(entry->field_128[2]),
                              reinterpret_cast<ISiGfxShader*>(entry->field_128[3]),
                              reinterpret_cast<ISiGfxShader*>(entry->field_128[4]));
            }
            Unk_ReleaseShaders(entry);
            entry->field_160 = reinterpret_cast<ISiInterface*>(program);
            result.field_0 = reinterpret_cast<u64>(program);
        } else {
            Unk_InsertFirst(&field_118, entry);
            entry->field_168 = 4;
            result.field_8 = 4;
        }
        result.field_c.field_0 = key.field_0;
        result.field_c.field_4 = key.field_4;
        result.field_c.field_8 = key.field_8;
        result.field_c.field_c = key.field_c;
        result.field_c.field_10 = key.field_10;
        result.field_c.field_14 = key.field_14;
    }
    if (field_110 != nullptr) {
        field_110->field_18.Unk_Get()->SiOSCriticalSection::vf3();
    }
    return result;
}

// 0x7100578980
// NON_MATCHING: the program's address is computed before its first word is
// tested in the original (`add x1; ldr [x1]`); here the add is sunk into the
// call's block and the load takes the register offset. Tried: continue, two
// element expressions, `+ j`, a reference, s32/size_t j, the field in a local,
// a bool, the array in a local, `!`, a while loop, an inline helper.
void SiGfxShaderEffect::vf17() {
    for (s64 i = 0; i < static_cast<s32>(field_c0.m_itemCount); i++) {
        TechniqueData* technique = field_c0.m_pData[i];
        for (s64 j = 0; j < static_cast<s32>(technique->field_10.m_itemCount); j++) {
            ShaderProgramData* program = &technique->field_10.m_pData[j];
            if (program->field_0 == nullptr) {
                Unk_5785d0(program, nullptr);
            }
        }
    }
}

// 0x7100576780
// NON_MATCHING: registers only: this keeps the free's line (0x5f2) in a
// callee-saved register (MachineLICM hoists it; the original keeps the
// second array vtable there instead and rematerialises the line) and the
// effect in another; 8 bytes longer. Tried: an s32 index, the count in a
// local, the slot as a reference or pointer, a `continue` for the null test.
void SiGfxShaderEffect::Unk_576780() {
    if (field_a8 != nullptr) {
        field_a8->vf3();
        field_a8 = nullptr;
    }
    if (field_a0 != nullptr) {
        field_a0->vf3();
        field_a0 = nullptr;
    }
    ISiAllocator* pAllocator = field_8.m_pAllocator;
    for (s64 i = 0; i < static_cast<s32>(field_c0.m_itemCount); i++) {
        TechniqueData* technique = field_c0.m_pData[i];
        if (technique != nullptr) {
            field_c0.m_pData[i] = nullptr;
#line 1685
            SI_DELETE(pAllocator, technique);
        }
    }
    field_c0.Unk_FreeAll();
    field_168 = 0;
}

// 0x71005769e0
void SiGfxShaderEffect::Unk_5769e0() {
    field_118.Unk_Clear();
    if (field_110 == nullptr) {
        return;
    }
    {
        Unk_596640 lock(field_110->field_18.Unk_Get(), true);
        while (field_110->field_48.m_count != 0) {
            auto first = decltype(field_110->field_48)::Unk_Iterator(&field_110->field_48, field_110->field_48.m_pRoot);
            ShaderProgramCompileEntry* entry = first.m_pNode->m_value;
            field_110->field_48.Unk_4c0e60(first);
            if (entry != nullptr) {
                ISiAllocator* pAllocator = field_8.m_pAllocator;
                if (pAllocator != nullptr) {
                    entry->~ShaderProgramCompileEntry();
#line 605
                    SI_FREE(pAllocator, entry);
                }
            }
        }
    }
    if (field_110 != nullptr) {
        field_110->vf3();
        field_110 = nullptr;
    }
}

}  // namespace SiSDK3

// Reads the effect again under its own name (placeholder name).
// 0x7100578b10
void Unk_578b10(SiSDK3::SiGfxShaderEffect* effect) {
    SiSDK3::SiString<char> name(*reinterpret_cast<const SiSDK3::SiString<char>*>(effect->vf8()), nullptr);
    effect->Unk_576780();
    effect->vf7(SiSDK3::Unk_StringCStr(&name));
}
