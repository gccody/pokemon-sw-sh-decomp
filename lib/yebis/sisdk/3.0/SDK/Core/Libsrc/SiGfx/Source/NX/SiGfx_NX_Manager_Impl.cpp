// Scope: common
// SiSDK3::SiGfxNXManager: it makes SiGfx's NVN devices and keeps the ones
// there are. The reference counts are its header's.
#define UNK_SIGFX_NX_MANAGER_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_Manager_Impl.h>

#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_Device_Impl.h>

// 0x71004bf7b0: the kernel (leafgen's name and type)
u64 Unk_4bf7b0_get();
// 0x71004cbec0: the object that keeps the resources to destroy later
// (Unk_RefCountDeferred.h's declaration)
void* Unk_4cbec0();

// 0x71004f6f70
template bool SiSDK3::SiArray<SiSDK3::SiGfxNXDevice*, 16>::Unk_4bf190(size_t, bool);

namespace SiSDK3 {

// The kernel as the manager uses it: slots 40 to 42 set a number it keeps,
// tell it, and give a value for one.
class Unk_4f6bd0_Kernel {
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
    virtual void vf40(s32 count);
    virtual s32 vf41();
    virtual void vf42(s32 index, u64 value);
};
inline Unk_4f6bd0_Kernel* Unk_Kernel() {
    return reinterpret_cast<Unk_4f6bd0_Kernel*>(Unk_4bf7b0_get());
}

// What keeps the resources to destroy later, as the manager uses it.
class Unk_4f6d80_Keeper {
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
    virtual void vf11(SiGfxNXDevice* pDevice);
};

// 0x71004f6920
SiGfxNXManager::SiGfxNXManager(ISiAllocator* pAllocator) : field_8(pAllocator), field_18(pAllocator), field_68(-1), field_70(0) {}

// 0x71004f69a0 (D2), 0x71004f6af0 (D0)
SiGfxNXManager::~SiGfxNXManager() {
    Unk_ReleaseAll(&field_18);
}

// 0x71004f6bd0
void SiGfxNXManager::vf5(u64 a1) {
    field_70 = a1;
    if (a1 != 0) {
        Unk_4f6bd0_Kernel* kernel = Unk_Kernel();
        kernel->vf40(Unk_Kernel()->vf41() + 1);
        field_68 = Unk_Kernel()->vf41() - 1;
        Unk_Kernel()->vf42(field_68, field_70);
    }
}

// 0x71004f6c80
SiGfxNXDevice* SiGfxNXManager::Unk_4f6c80() {
#line 99
    SiGfxNXDevice* pDevice = UNK_SI_NEW(field_8.m_pAllocator, 0x10) SiGfxNXDevice(this);
    if (pDevice != nullptr) {
        if (!pDevice->Unk_4f78c0()) {
            pDevice->vf3();
            return nullptr;
        }
        field_18.Unk_Add(pDevice);
    }
    return pDevice;
}

// 0x71004f6d80
void SiGfxNXManager::Unk_4f6d80(SiGfxNXDevice* pDevice) {
    field_18.Unk_RemoveValue(pDevice);
    static_cast<Unk_4f6d80_Keeper*>(Unk_4cbec0())->vf11(pDevice);
}

}  // namespace SiSDK3
