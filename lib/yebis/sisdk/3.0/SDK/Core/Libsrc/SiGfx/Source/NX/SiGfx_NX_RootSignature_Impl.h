// SiSDK3::SiGfxNXRootSignature (RTTI names the class and its entries; it
// derives from ISiGfxNXRootSignature, ISiGfxRootSignature and ISiInterface):
// the parameters and the samplers a pipeline's shaders take. Placeholder
// members; the virtual functions are vf<slot>. The reference counts are
// defined in this header (their __FILE__), at the original's lines, for the
// class's own translation unit (UNK_SIGFX_NX_ROOTSIGNATURE_IMPL).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_Array.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/Unk_NXResource.h>

namespace SiSDK3 {

// A sampler as a root signature's entry holds it (placeholder name).
class Unk_NXRootSampler {
public:
    virtual void vf0();
    virtual void vf1();
    virtual u32 vf2();
    virtual u32 vf3();
};

class SiGfxNXRootSignature : public Unk_NXInterface {
public:
    // A range of descriptors.
    struct DescriptorRangeEntry {
        DescriptorRangeEntry() : field_0(1), field_4(0), field_8(0), field_c(0), field_10(0) {}

        u32 field_0;
        u32 field_4;
        u32 field_8;
        u32 field_c;
        u32 field_10;
    };
    // A parameter's ranges, in an object of its own that remembers the
    // allocator it came from (placeholder name).
    struct Unk_Ranges {
        // (it empties the array itself before the array's destructor does:
        // the array's vtable is stored after its buffer is freed)
        ~Unk_Ranges() { field_8.Unk_FreeAll(); }

        ISiAllocator* field_0;
        SiArray<DescriptorRangeEntry, 16> field_8;
    };
    // A parameter: its ranges go with it. (The delete's line is this
    // header's.)
    struct RootParameterEntry {
        ~RootParameterEntry() {
            if (field_20 != nullptr) {
#line 313
                SI_DELETE(field_20->field_0, field_20);
                field_20 = nullptr;
            }
        }

        u32 field_0;
        u32 field_4;
        u32 field_8;
        u32 field_c;
        u64 field_10;
        u64 field_18;
        Unk_Ranges* field_20;
    };
    // What a sampler's entry is made from when it isn't a sampler object
    // (placeholder name).
    struct Unk_SamplerDesc {
        u32 field_0[16];
    };
    // A sampler: a description or a sampler object, which it holds a
    // reference to.
    struct RootSamplerEntry {
        ~RootSamplerEntry() {
            if (field_50 != nullptr) {
                field_50->vf3();
                field_50 = nullptr;
            }
        }

        u32 field_0;
        u32 field_4;
        u32 field_8;
        Unk_SamplerDesc field_c;
        Unk_NXRootSampler* field_50;
    };

    // What the constructor clears 0x270 bytes of, as merged stores (not a
    // tail-called memset): elements with a constructor, of a size that isn't
    // known (placeholder name).
    struct Unk_c8 {
        Unk_c8() : field_0(0) {}

        u64 field_0;
    };

    SiGfxNXRootSignature(ISiAllocator* pAllocator, SiGfxNXDevice* pDevice);  // 0x7100556cf0
    ~SiGfxNXRootSignature() override;                                        // 0x7100556db0, 0x7100556fb0
    u32 vf2() override;                                                      // 0x7100557c80
    u32 vf3() override;                                                      // 0x7100557ca0
    u32 vf4() override;
    virtual Unk_NXDeviceInterface* vf5();
    virtual Unk_NXDeviceInterface* vf6();
    virtual u32 vf7();
    virtual bool vf8();    // 0x7100557020 (not written yet)
    virtual bool vf9();    // 0x7100557120 (not written yet)
    virtual bool vf10();   // 0x7100557430 (not written yet)
    virtual u32 vf11();
    virtual bool vf12();   // 0x71005574f0 (not written yet)
    virtual bool vf13();   // 0x7100557660 (not written yet)
    virtual bool vf14();   // 0x71005577e0 (not written yet)
    virtual bool vf15();   // 0x7100557a00 (not written yet)
    virtual bool vf16();   // 0x7100557aa0 (not written yet)
    virtual u32 vf17();
    // 0x7100557b60, 0x7100557be0: a sampler's entry, from a description or
    // from a sampler object
    virtual bool vf18(s32 index, u32 a2, u32 a3, u32 a4, const Unk_SamplerDesc* desc);
    virtual bool vf19(s32 index, u32 a2, u32 a3, u32 a4, Unk_NXRootSampler* sampler);
    virtual u32 vf20();
    virtual Unk_NXRootSampler* vf21(s32 index);  // 0x7100557c60

    Unk_4bf660 field_8;
    SiGfxNXDevice* field_18;
    u32 field_20;
    bool field_24;
    bool field_25;  // whether it's being changed
    SiArray<RootParameterEntry, 16> field_28;
    SiArray<RootSamplerEntry, 16> field_78;
    Unk_c8 field_c8[78];
};
PKMN_SIZE_ASSERT(SiGfxNXRootSignature::DescriptorRangeEntry, 0x14);
PKMN_SIZE_ASSERT(SiGfxNXRootSignature::RootParameterEntry, 0x28);
PKMN_SIZE_ASSERT(SiGfxNXRootSignature::RootSamplerEntry, 0x58);
PKMN_SIZE_ASSERT(SiGfxNXRootSignature, 0x338);

}  // namespace SiSDK3

#ifdef UNK_SIGFX_NX_ROOTSIGNATURE_IMPL
// 0x7100557c80 (vf2), 0x7100557ca0 (vf3)
#line 37
UNK_REFCOUNT_DEFINE(SiSDK3::SiGfxNXRootSignature, field_8.m_pAllocator, field_8.m_count)
#endif
