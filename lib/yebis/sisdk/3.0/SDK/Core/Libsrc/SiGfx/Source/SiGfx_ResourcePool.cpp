// Scope: common
// SiSDK3::SiGfxResourcePool: its construction and destruction and the
// reference counts its header defines.
#define UNK_SIGFX_RESOURCEPOOL_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/SiGfx_ResourcePool.h>

#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/Unk_NXResource.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/Unk_Pools.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_StringFuncs.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/ShaderEffect/SiGfx_ShaderEffectKey.h>

// 0x71004c34a0: a name's hash
u32 Unk_4c34a0(const char* name);

namespace SiSDK3 {

class SiGfxNXShaderProgram;
class SiGfxShaderEffect;

// What the shader programs' pool makes its own programs with, as it calls
// them (placeholder names and slots): SiGfx's kernel's package manager (slot
// 12) and its package of a name (slot 8), the shader effects it adds to that
// package (slot 22; 0x7100576110 makes them), an effect's technique (slot 10)
// and its keys of a name (the technique's slot 12, the effect's slot 15), and
// the program of a pair of keys (the effect's slot 12, returned by value).
class Unk_535550_Technique {
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
    virtual void vf12(SiGfxShaderEffectKey* key, const char* name);
};
struct Unk_535550_Program {
    SiGfxNXShaderProgram* field_0;
    u64 field_8[4];
};
class Unk_535550_Effect {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7(const char* name);
    virtual void vf8();
    virtual void vf9();
    virtual Unk_535550_Technique* vf10();
    virtual void vf11();
    virtual Unk_535550_Program vf12(void* a1, const SiGfxShaderEffectKey* key, const SiGfxShaderEffectKey* key2,
                                    void* a4);
    virtual void vf13();
    virtual void vf14();
    virtual void vf15(SiGfxShaderEffectKey* key, const char* name);
};
class Unk_535550_Package {
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
    virtual void vf22(Unk_535550_Effect* effect);
};
class Unk_535550_Manager {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual Unk_535550_Package* vf8(const char* name);
};
class Unk_535550_Kernel {
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
    virtual Unk_535550_Manager* vf12();
};

}  // namespace SiSDK3

// 0x7100576110: makes a shader effect (SiGfx_ShaderEffect_Impl.cpp)
SiSDK3::SiGfxShaderEffect* Unk_576110(SiSDK3::ISiAllocator* pAllocator, void* owner);
// 0x71004c9c20: sets bits of a key's bytes (placeholder name)
void Unk_4c9c20(int size, u8* bytes, int offset, int width, u32 value);

// The keys of the ShowTexture effect's programs (RTTI names the classes;
// placeholder members): a byte of their own, whose bits choose the program.
namespace SiGfxCommonShaderShowTexture {

class ShaderKey : public SiSDK3::SiGfxShaderEffectKey {
public:
    ShaderKey() : SiSDK3::SiGfxShaderEffectKey(1, field_18) {
        field_18[0] = 0;
    }

    // clears the byte (inline: placeholder name)
    void Unk_ClearBytes() {
        if (field_c >= 1 && field_10 != nullptr) {
            memset(field_10, 0, field_c);
        }
    }

    u8 field_18[1];
};

class PreprocessorShaderKey : public SiSDK3::SiGfxShaderEffectKey {
public:
    PreprocessorShaderKey() : SiSDK3::SiGfxShaderEffectKey(1, field_18) {
        field_18[0] = 0;
    }

    // clears the byte (inline: placeholder name)
    void Unk_ClearBytes() {
        if (field_c >= 1 && field_10 != nullptr) {
            memset(field_10, 0, field_c);
        }
    }

    u8 field_18[1];
};

}  // namespace SiGfxCommonShaderShowTexture

namespace SiSDK3 {

// 0x7100534000
SiGfxResourcePool::SiGfxResourcePool(ISiAllocator* pAllocator)
    : field_8(pAllocator), field_18(0), field_48(pAllocator, true), field_170(false) {
    field_48.field_120 = true;
}

// 0x71005341b0 (D2), 0x71005343b0 (D0)
SiGfxResourcePool::~SiGfxResourcePool() {
    SiGfxResourcePool::vf6();
}

// 0x7100534430
void SiGfxResourcePool::vf6() {
    Unk_534460();
    field_48.Unk_4be7d0();
}

// 0x7100534460
void SiGfxResourcePool::Unk_534460() {
    Unk_596640 lock(field_18.Unk_Get(), true);
    field_170 = true;
    Unk_534460_Resource* resource = Unk_534810();
    while (resource != nullptr) {
        Unk_534460_Resource* next = Unk_534870(resource);
        resource->vf3();
        resource = next;
    }
    field_170 = false;
}

// 0x7100534780
Unk_534460_Resource* SiGfxResourcePool::Unk_534780(size_t index) {
    Unk_596640 lock(field_18.Unk_Get(), true);
    if (index < field_48.field_118) {
        ResourceItem* item = field_48.Unk_Get(index);
        if (item->field_18) {
            return item->field_20;
        }
    }
    return nullptr;
}

// 0x7100534810
Unk_534460_Resource* SiGfxResourcePool::Unk_534810() {
    Unk_596640 lock(field_18.Unk_Get(), true);
    return field_48.m_usedList.m_count != 0 ? field_48.m_usedList.m_pHead->field_20 : nullptr;
}

// 0x7100534870
Unk_534460_Resource* SiGfxResourcePool::Unk_534870(Unk_534460_Resource* resource) {
    Unk_596640 lock(field_18.Unk_Get(), true);
    ResourceItem* next = field_48.Unk_Get(resource->vf7())->m_pNext;
    return next != nullptr ? next->field_20 : nullptr;
}

// 0x7100534900
Unk_534460_Resource* SiGfxResourcePool::Unk_534900(const char* name) {
    Unk_596640 lock(field_18.Unk_Get(), true);
    u32 hash = Unk_4c34a0(name);
    for (ResourceItem* item = field_48.m_usedList.m_pHead; item != nullptr; item = item->m_pNext) {
        if (item->field_20 != nullptr && item->field_20->named_vf4() == hash) {
            return item->field_20;
        }
    }
    return nullptr;
}

#define UNK_FOR_EACH(Slot, Call)                                                                              \
    void SiGfxResourcePool::Slot() {                                                                          \
        Unk_596640 lock(field_18.Unk_Get(), true);                                                            \
        for (Unk_534460_Resource* resource = Unk_534810(); resource != nullptr; resource = Unk_534870(resource)) { \
            resource->Call();                                                                                 \
        }                                                                                                     \
    }

// 0x7100534990 = _ZN6SiSDK317SiGfxResourcePool3vf7Ev
UNK_FOR_EACH(vf7, vf9)
// 0x7100534aa0 = _ZN6SiSDK317SiGfxResourcePool3vf8Ev
UNK_FOR_EACH(vf8, vf10)
// 0x7100534bb0 = _ZN6SiSDK317SiGfxResourcePool3vf9Ev
UNK_FOR_EACH(vf9, vf11)
// 0x7100534cc0 = _ZN6SiSDK317SiGfxResourcePool4vf10Ev
UNK_FOR_EACH(vf10, vf12)
// 0x7100534dd0 = _ZN6SiSDK317SiGfxResourcePool4vf11Ev
UNK_FOR_EACH(vf11, vf13)
// 0x7100534ee0 = _ZN6SiSDK317SiGfxResourcePool4vf12Ev
UNK_FOR_EACH(vf12, vf14)
#undef UNK_FOR_EACH

// 0x7100534ff0
void SiGfxResourcePool::vf13(Unk_534460_Resource* resource) {
    Unk_596640 lock(field_18.Unk_Get(), true);
    if (!field_170) {
        ResourceItem* item = field_48.Unk_Get(resource->vf7());
        item->field_20 = nullptr;
        field_48.Unk_4be3f0(item);
    }
}

// 0x7100535080
SiGfxShaderProgramPoolBase::SiGfxShaderProgramPoolBase(SiGfxNXDevice* pDevice)
    : SiGfxResourcePool(Unk_NXKernel()->vf6()), field_178(pDevice), field_180(false), field_184(0),
      field_188(Unk_NXKernel()->vf6()), field_1b8(Unk_NXKernel()->vf6()) {}

// 0x71005351c0 (D2; D0, 0x7100535300, is a trap: the class is abstract)
SiGfxShaderProgramPoolBase::~SiGfxShaderProgramPoolBase() {
    SiGfxShaderProgramPoolBase::vf6();
}

// 0x7100535310
bool SiGfxShaderProgramPoolBase::vf5(s32 count) {
    field_48.vf2(count);
    return true;
}

// 0x7100535330
void SiGfxShaderProgramPoolBase::vf6() {
    Unk_ReleaseShaders();
    SiGfxResourcePool::vf6();
}

// 0x7100535380
void SiGfxShaderProgramPoolBase::Unk_Shaders::Unk_535380() {
    for (int i = 0; i < 11; i++) {
        if (field_0[i] != nullptr) {
            field_0[i]->vf3();
            field_0[i] = nullptr;
        }
    }
}

// 0x71005354b0
void SiGfxShaderProgramPoolBase::vf7() {
    if (field_178 == nullptr) {
        return;
    }
    const Unk_4f96c0_Desc* desc = reinterpret_cast<const Unk_4f96c0_Desc*>(field_178->vf11());
    if (desc->field_52 != 0 && Unk_NXKernel()->vf27()->field_60) {
        field_180 = false;
        vf16();
        vf17();
        field_180 = true;
    }
    SiGfxResourcePool::vf7();
}

// NON_MATCHING: the same calls and loops: the keys' base constructor that
// takes the size and the bytes and the running index of the programs' table
// (its second run starts at an index computed without `nsw`, the original's
// `add x27, x9, x8, asr #29`) give the original's registers and spill slots.
// What's left: the original loads `names[i]` from the stack in every
// iteration, where GVN's load PRE forwards the first one here (`adrp x2`
// before the loop, the latch's load at the loop's top) and pairs the first
// two names' stores; and the key's size and number are a `stp wzr, w8`
// there, one 64-bit constant here. The parts before and after the loop are
// the original's.
// 0x7100535550 (0x71005363a0 and 0x71005363b0 are its ShowTexture keys'
// deleting destructors)
bool SiGfxShaderProgramPoolBase::vf16() {
    Unk_535550_Package* package =
        reinterpret_cast<Unk_535550_Kernel*>(Unk_4cbf40_get())->vf12()->vf8(Unk_StringCStr(&field_188));
    if (package == nullptr) {
        return false;
    }
    Unk_535550_Effect* effect = reinterpret_cast<Unk_535550_Effect*>(Unk_576110(field_8.m_pAllocator, field_178));
    if (effect == nullptr) {
        return false;
    }
    field_1e8.field_0[0] = reinterpret_cast<Unk_534460_Resource*>(effect);
    effect->vf7("SiGfx::CommonShaderEffect::SolidColor");
    package->vf22(effect);
    {
        SiGfxShaderEffectKey key;
        SiGfxShaderEffectKey key2;
        Unk_535550_Program program = effect->vf12(nullptr, &key, &key2, nullptr);
        if (program.field_0 != nullptr) {
            vf15(program.field_0, 1);
        }
        SiGfxShaderEffectKey keyL;
        SiGfxShaderEffectKey keyL2;
        effect->vf15(&keyL, "SolidColorByLargePoint");
        Unk_535550_Program programL = effect->vf12(nullptr, &keyL, &keyL2, nullptr);
        if (programL.field_0 != nullptr) {
            vf15(programL.field_0, 0x4a);
        }
    }
    effect = reinterpret_cast<Unk_535550_Effect*>(Unk_576110(field_8.m_pAllocator, field_178));
    if (effect == nullptr) {
        return false;
    }
    field_1e8.field_0[1] = reinterpret_cast<Unk_534460_Resource*>(effect);
    effect->vf7("SiGfx::CommonShaderEffect::VertexColor");
    package->vf22(effect);
    {
        SiGfxShaderEffectKey key;
        SiGfxShaderEffectKey key2;
        SiGfxNXShaderProgram* program = effect->vf12(nullptr, &key, &key2, nullptr).field_0;
        if (program != nullptr) {
            vf15(program, 2);
        }
    }
    effect = reinterpret_cast<Unk_535550_Effect*>(Unk_576110(field_8.m_pAllocator, field_178));
    if (effect == nullptr) {
        return false;
    }
    field_1e8.field_0[2] = reinterpret_cast<Unk_534460_Resource*>(effect);
    effect->vf7("SiGfx::CommonShaderEffect::ModulateColor");
    package->vf22(effect);
    {
        SiGfxShaderEffectKey key;
        SiGfxShaderEffectKey key2;
        SiGfxNXShaderProgram* program = effect->vf12(nullptr, &key, &key2, nullptr).field_0;
        if (program != nullptr) {
            vf15(program, 3);
        }
    }
    effect = reinterpret_cast<Unk_535550_Effect*>(Unk_576110(field_8.m_pAllocator, field_178));
    if (effect == nullptr) {
        return false;
    }
    field_1e8.field_0[3] = reinterpret_cast<Unk_534460_Resource*>(effect);
    effect->vf7("SiGfx::CommonShaderEffect::Scale");
    package->vf22(effect);
    {
        SiGfxShaderEffectKey key;
        SiGfxShaderEffectKey key2;
        SiGfxNXShaderProgram* program = effect->vf12(nullptr, &key, &key2, nullptr).field_0;
        if (program == nullptr) {
            vf15(program, 4);
        }
    }
    if (field_178->vf14() == 8) {
        effect = reinterpret_cast<Unk_535550_Effect*>(Unk_576110(field_8.m_pAllocator, field_178));
        if (effect == nullptr) {
            return false;
        }
        field_1e8.field_0[4] = reinterpret_cast<Unk_534460_Resource*>(effect);
        effect->vf7("SiGfx::CommonShaderEffect::Downsample");
        package->vf22(effect);
        SiGfxShaderEffectKey key;
        SiGfxShaderEffectKey key2;
        SiGfxNXShaderProgram* program = effect->vf12(nullptr, &key, &key2, nullptr).field_0;
        if (program != nullptr) {
            vf15(program, 0x4b);
        }
    }
    effect = reinterpret_cast<Unk_535550_Effect*>(Unk_576110(field_8.m_pAllocator, field_178));
    if (effect == nullptr) {
        return false;
    }
    field_1e8.field_0[5] = reinterpret_cast<Unk_534460_Resource*>(effect);
    effect->vf7("SiGfx::CommonShaderEffect::Composite");
    package->vf22(effect);
    {
        SiGfxShaderEffectKey key;
        SiGfxShaderEffectKey key2;
        SiGfxNXShaderProgram* program = effect->vf12(nullptr, &key, &key2, nullptr).field_0;
        if (program != nullptr) {
            vf15(program, 5);
        }
    }
    effect = reinterpret_cast<Unk_535550_Effect*>(Unk_576110(field_8.m_pAllocator, field_178));
    if (effect == nullptr) {
        return false;
    }
    field_1e8.field_0[6] = reinterpret_cast<Unk_534460_Resource*>(effect);
    effect->vf7("SiGfx::CommonShaderEffect::Blur");
    package->vf22(effect);
    {
        SiGfxShaderEffectKey key;
        SiGfxShaderEffectKey key2;
        SiGfxNXShaderProgram* program = effect->vf12(nullptr, &key, &key2, nullptr).field_0;
        if (program != nullptr) {
            vf15(program, 6);
        }
    }
    effect = reinterpret_cast<Unk_535550_Effect*>(Unk_576110(field_8.m_pAllocator, field_178));
    if (effect == nullptr) {
        return false;
    }
    field_1e8.field_0[7] = reinterpret_cast<Unk_534460_Resource*>(effect);
    effect->vf7("SiGfx::CommonShaderEffect::ShowTexture");
    package->vf22(effect);
    {
        const char* names[5];
        names[0] = "ShowTexture2D";
        names[1] = "ShowTextureCube";
        names[2] = "ShowTexture3D";
        names[3] = "ShowTexture2D_Array";
        names[4] = "ShowTextureCube_Array";
        static const u32 kinds[7] = {0, 1, 2, 3, 4, 5, 6};
        // the programs' indices: for each target, without and with the
        // option, one for each kind
        static const size_t indices[5 * 2 * 7] = {
            7,  8,  9,  10, 11, 12, 78, 13, 14, 15, 16, 17, 18, 79,  //
            19, 20, 21, 22, 23, 24, 80, 25, 26, 27, 28, 29, 30, 81,  //
            31, 32, 33, 34, 35, 36, 82, 37, 38, 39, 40, 41, 42, 83,  //
            43, 44, 45, 46, 47, 48, 84, 49, 50, 51, 52, 53, 54, 85,  //
            55, 56, 57, 58, 60, 59, 86, 61, 62, 63, 64, 65, 66, 87,
        };
        s32 n = 0;
        for (s32 i = 0; i < 5; i++) {
            SiGfxCommonShaderShowTexture::ShaderKey key;
            SiGfxCommonShaderShowTexture::PreprocessorShaderKey key2;
            effect->vf15(&key, names[i]);
            for (s32 k = 0; k < 2; k++) {
                for (s32 j = 0; j < 7; j++) {
                    u32 kind = kinds[j];
                    key.Unk_ClearBytes();
                    key2.Unk_ClearBytes();
                    Unk_4c9c20(1, key.field_10, 0, 1, k);
                    Unk_4c9c20(1, key2.field_10, 0, 3, kind);
                    SiGfxNXShaderProgram* program = effect->vf12(nullptr, &key, &key2, nullptr).field_0;
                    if (program != nullptr) {
                        vf15(program, indices[n]);
                    }
                    n++;
                }
            }
        }
    }
    effect = reinterpret_cast<Unk_535550_Effect*>(Unk_576110(field_8.m_pAllocator, field_178));
    if (effect == nullptr) {
        return false;
    }
    field_1e8.field_0[8] = reinterpret_cast<Unk_534460_Resource*>(effect);
    effect->vf7("SiGfx::CommonShaderEffect::BltTexture");
    package->vf22(effect);
    {
        SiGfxShaderEffectKey key;
        SiGfxShaderEffectKey key2;
        SiGfxNXShaderProgram* program = effect->vf12(nullptr, &key, &key2, nullptr).field_0;
        if (program != nullptr) {
            vf15(program, 0x43);
        }
    }
    effect = reinterpret_cast<Unk_535550_Effect*>(Unk_576110(field_8.m_pAllocator, field_178));
    if (effect == nullptr) {
        return false;
    }
    field_1e8.field_0[9] = reinterpret_cast<Unk_534460_Resource*>(effect);
    effect->vf7("SiGfx::CommonShaderEffect::Font");
    package->vf22(effect);
    {
        SiGfxShaderEffectKey key;
        SiGfxShaderEffectKey key2;
        SiGfxNXShaderProgram* program = effect->vf12(nullptr, &key, &key2, nullptr).field_0;
        if (program != nullptr) {
            vf15(program, 0x44);
        }
    }
    effect = reinterpret_cast<Unk_535550_Effect*>(Unk_576110(field_8.m_pAllocator, field_178));
    if (effect == nullptr) {
        return false;
    }
    field_1e8.field_0[10] = reinterpret_cast<Unk_534460_Resource*>(effect);
    effect->vf7("SiGfx::CommonShaderEffect::YUVBlt");
    package->vf22(effect);
    {
        SiGfxShaderEffectKey key;
        SiGfxShaderEffectKey key2;
        effect->vf15(&key, "YUVBlt");
        key.Unk_Clear();
        key2.Unk_Clear();
        SiGfxNXShaderProgram* program = effect->vf12(nullptr, &key, &key2, nullptr).field_0;
        if (program != nullptr) {
            vf15(program, 0x4c);
        }
        effect->vf15(&key, "YUVBltAlpha");
        key.Unk_Clear();
        key2.Unk_Clear();
        program = effect->vf12(nullptr, &key, &key2, nullptr).field_0;
        if (program != nullptr) {
            vf15(program, 0x4d);
        }
    }
    return true;
}

// 0x7100536000
bool SiGfxShaderProgramPoolBase::vf17() {
    Unk_535550_Package* package =
        reinterpret_cast<Unk_535550_Kernel*>(Unk_4cbf40_get())->vf12()->vf8(Unk_StringCStr(&field_1b8));
    if (package == nullptr) {
        return false;
    }
    Unk_535550_Effect* effect = reinterpret_cast<Unk_535550_Effect*>(Unk_576110(field_8.m_pAllocator, field_178));
    if (effect == nullptr) {
        return false;
    }
    effect->vf7("SiGfx::DebugShaderEffect");
    package->vf22(effect);
    Unk_535550_Technique* technique = effect->vf10();
    if (technique == nullptr) {
        return false;
    }
    field_240.field_0 = reinterpret_cast<Unk_534460_Resource*>(effect);
    SiGfxShaderEffectKey key;
    SiGfxShaderEffectKey key2;
    technique->vf12(&key, "ShowNormal");
    SiGfxNXShaderProgram* program = effect->vf12(nullptr, &key, &key2, nullptr).field_0;
    if (program != nullptr) {
        vf15(program, 0x45);
    }
    technique->vf12(&key, "ShowTexCoord");
    program = effect->vf12(nullptr, &key, &key2, nullptr).field_0;
    if (program == nullptr) {
        return false;
    }
    vf15(program, 0x46);
    technique->vf12(&key, "ShowVertexColor");
    program = effect->vf12(nullptr, &key, &key2, nullptr).field_0;
    if (program != nullptr) {
        vf15(program, 0x47);
    }
    technique->vf12(&key, "ShowVertexColorTex");
    program = effect->vf12(nullptr, &key, &key2, nullptr).field_0;
    if (program == nullptr) {
        return false;
    }
    vf15(program, 0x48);
    technique->vf12(&key, "ShowVertexColorWithWireframe");
    program = effect->vf12(nullptr, &key, &key2, nullptr).field_0;
    if (program != nullptr) {
        vf15(program, 0x49);
    }
    return true;
}

// 0x71005362b0
void SiGfxShaderProgramPoolBase::vf18() {
    Unk_ReleaseShaders();
    field_180 = false;
    vf16();
    vf17();
    field_180 = true;
}

// 0x7100536320
void SiGfxShaderProgramPoolBase::vf19() {
    Unk_ReleaseShaders();
    field_180 = false;
    vf16();
    vf17();
    field_180 = true;
}

}  // namespace SiSDK3
