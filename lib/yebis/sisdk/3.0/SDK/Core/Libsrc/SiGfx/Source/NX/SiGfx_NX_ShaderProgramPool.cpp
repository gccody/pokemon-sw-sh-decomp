// Scope: common
// SiSDK3::SiGfxNXShaderProgramPool: its destruction and the slots that only
// call its base (the pool's constructor is in Unk_Pools.cpp; the functions
// that make and take programs aren't written yet).
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/Unk_Pools.h>

#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_ShaderProgram_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/ShaderEffect/SiGfx_ShaderEffectKey.h>

// 0x710055a0f0 (leafgen's name and type): the program's index in its pool
struct Unk_55a0f0;
bool Unk_55a0f0_update(Unk_55a0f0* self, u64 value);

namespace SiSDK3 {

// What field_248 points at, as the destructor releases it (placeholder name).
class Unk_5597d0_Object {
public:
    virtual void vf0();
    virtual void vf1();
    virtual u32 vf2();
    virtual u32 vf3();
};

// What Unk_559bf0 makes the pool's own copy program from, as it calls them
// (placeholder names and slots): SiGfx's kernel's package manager (slot 12)
// and its package of a name (slot 8), the shader effect it adds to that
// package (slot 22; 0x7100576110 makes it), the effect's technique (slot 10)
// and the program of a key (the effect's slot 12, returned by value).
class Unk_559bf0_Technique {
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
struct Unk_559bf0_Program {
    SiGfxNXShaderProgram* field_0;
    u64 field_8[4];
};
class Unk_559bf0_Effect {
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
    virtual Unk_559bf0_Technique* vf10();
    virtual void vf11();
    virtual Unk_559bf0_Program vf12(void* a1, const SiGfxShaderEffectKey* key, const SiGfxShaderEffectKey* key2,
                                    void* a4);
};
class Unk_559bf0_Package {
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
    virtual void vf22(Unk_559bf0_Effect* effect);
};
class Unk_559bf0_Manager {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual Unk_559bf0_Package* vf8(const char* name);
};
class Unk_559bf0_Kernel {
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
    virtual Unk_559bf0_Manager* vf12();
};

}  // namespace SiSDK3

namespace SiSDK3 {
class SiGfxShaderEffect;
}  // namespace SiSDK3
// 0x7100576110: makes a shader effect (SiGfx_ShaderEffect_Impl.cpp)
SiSDK3::SiGfxShaderEffect* Unk_576110(SiSDK3::ISiAllocator* pAllocator, void* owner);

namespace SiSDK3 {

// 0x71005598b0: under the name and type the device's translation unit calls
// it by (the pointer is the index of the pool's item to take, 0 for any).
// Until the pool has made its own programs (field_180) a program has no item.
SiGfxNXShaderProgram* Unk_5598b0(SiGfxNXShaderProgramPool* pool, ISiAllocator* pAllocator, const void* index) {
    Unk_596640 lock(pool->field_18.Unk_Get(), true);
    SiGfxResourcePool::ResourceItem* item = nullptr;
    size_t itemIndex = 0;
    if (pool->field_180) {
        if (index != nullptr) {
            item = pool->field_48.Unk_4fef10(reinterpret_cast<size_t>(index));
        } else {
            item = pool->field_48.Unk_Alloc();
        }
        if (item == nullptr) {
            return nullptr;
        }
        itemIndex = item->field_10;
    }
    SiGfxNXDevice* pDevice = pool->field_178;
#line 118
    SiGfxNXShaderProgram* program = UNK_SI_NEW(pAllocator, 0x10) SiGfxNXShaderProgram(pAllocator, pDevice);
    if (program == nullptr || !Unk_55a0f0_update(reinterpret_cast<Unk_55a0f0*>(program), itemIndex)) {
        if (item != nullptr) {
            pool->field_48.Unk_4be3f0(item);
        }
        return nullptr;
    }
    if (item != nullptr) {
        item->field_20 = reinterpret_cast<Unk_534460_Resource*>(program);
    }
    s32 number = ++pool->field_184;
    if (Unk_NXDevice(pool->field_178)->vf11()->field_b5) {
        char name[0x80];
        Unk_4c5a90(name, sizeof(name), "ShaderProgram_%d", number);
        program->vf40(name);
    }
    return program;
}

// 0x71005597d0 (D2), 0x7100559820 (D0)
SiGfxNXShaderProgramPool::~SiGfxNXShaderProgramPool() {
    SiGfxShaderProgramPoolBase::vf6();
    Unk_5597d0_Object* object = static_cast<Unk_5597d0_Object*>(field_248);
    if (object != nullptr) {
        object->vf3();
        field_248 = nullptr;
    }
}

// 0x7100559880
bool SiGfxNXShaderProgramPool::vf5(s32 count) {
    SiGfxShaderProgramPoolBase::vf5(count);
    return true;
}

// 0x71005598a0
void SiGfxNXShaderProgramPool::vf6() {
    SiGfxShaderProgramPoolBase::vf6();
}

// 0x7100559ac0
void SiGfxNXShaderProgramPool::vf15(SiGfxNXShaderProgram* program, size_t index) {
    if (program == nullptr) {
        return;
    }
    SiGfxResourcePool::ResourceItem* item = field_48.Unk_4fef10(index);
    if (item == nullptr) {
        return;
    }
    Unk_55a0f0_update(reinterpret_cast<Unk_55a0f0*>(program), index);
    if (Unk_NXDevice(field_178)->vf11()->field_b5) {
        char name[0x80];
        Unk_4c5a90(name, sizeof(name), "ShaderProgram_%d", static_cast<s32>(index));
        program->vf40(name);
    }
    item->field_20 = reinterpret_cast<Unk_534460_Resource*>(program);
}

// 0x7100559bf0: the pool's own program, which copies resources in a compute
// shader, at an index (the next one's after it)
bool SiGfxNXShaderProgramPool::Unk_559bf0(s32* index) {
    Unk_559bf0_Package* package =
        reinterpret_cast<Unk_559bf0_Kernel*>(Unk_4cbf40_get())->vf12()->vf8("SiGfx_NX_Special");
    if (package == nullptr) {
        return false;
    }
    SiGfxShaderEffectKey key;
    SiGfxShaderEffectKey key2;
    Unk_559bf0_Effect* effect = reinterpret_cast<Unk_559bf0_Effect*>(Unk_576110(field_8.m_pAllocator, field_178));
    effect->vf7("SiGfx::NXSpecialShaderEffect::CSCopyResource");
    package->vf22(effect);
    Unk_559bf0_Technique* technique = effect->vf10();
    field_248 = effect;
    technique->vf12(&key, "CSCopyBuffer");
    Unk_559bf0_Program program = effect->vf12(nullptr, &key, &key2, nullptr);
    if (program.field_0 == nullptr) {
        return false;
    }
    vf15(program.field_0, *index);
    (*index)++;
    field_250 = reinterpret_cast<u64>(program.field_0);
    return true;
}

// 0x7100559b60
// NON_MATCHING: the original tail-calls the base's slot 7. Here the index's
// address escapes into Unk_559bf0, which isn't written yet: in the original
// it's in this translation unit, where clang can tell that it doesn't keep
// the address (nocapture), which allows the tail call.
void SiGfxNXShaderProgramPool::vf7() {
    const Unk_4f96c0_Desc* desc = reinterpret_cast<const Unk_4f96c0_Desc*>(field_178->vf11());
    if (desc->field_52 != 0 && Unk_NXKernel()->vf27()->field_60) {
        field_180 = false;
        vf16();
        vf17();
        s32 index = 0x58;
        Unk_559bf0(&index);
        field_180 = true;
    }
    SiGfxResourcePool::vf7();
}

}  // namespace SiSDK3
