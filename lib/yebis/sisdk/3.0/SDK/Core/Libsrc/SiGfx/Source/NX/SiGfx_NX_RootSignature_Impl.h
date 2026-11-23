// SiSDK3::SiGfxNXRootSignature (RTTI names the class and its entries; it
// derives from ISiGfxNXRootSignature, ISiGfxRootSignature and ISiInterface):
// the parameters and the samplers a pipeline's shaders take. Placeholder
// members; the virtual functions are vf<slot>. The reference counts are
// defined in this header (their __FILE__), at the original's lines, for the
// class's own translation unit (UNK_SIGFX_NX_ROOTSIGNATURE_IMPL).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_Array.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_Sampler_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/Unk_NXResource.h>

namespace SiSDK3 {

// A sampler as a root signature's entry holds it (placeholder name; it is
// a SiGfxNXSampler): slot 17 is its description, slot 19 its hash, field_120
// its number in the device's sampler pool.
class Unk_NXRootSampler {
public:
    virtual void vf0();
    virtual void vf1();
    virtual u32 vf2();
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
    virtual const SiGfxNXSampler::Unk_Desc* vf17();
    virtual void vf18();
    virtual u32 vf19();

    u8 field_8[0x118];
    s32 field_120;
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
        explicit Unk_Ranges(ISiAllocator* pAllocator) : field_0(pAllocator), field_8(pAllocator) {}
        // (it empties the array itself before the array's destructor does:
        // the array's vtable is stored after its buffer is freed)
        ~Unk_Ranges() { field_8.Unk_FreeAll(); }

        ISiAllocator* field_0;
        SiArray<DescriptorRangeEntry, 16> field_8;
    };
    // A parameter: its ranges go with it. (The delete's line is this
    // header's.)
    struct RootParameterEntry {
        RootParameterEntry() : field_0(0), field_4(0), field_8(0), field_c(-1), field_10(0), field_20(nullptr) {}
        ~RootParameterEntry() {
            if (field_20 != nullptr) {
#line 313
                SI_DELETE(field_20->field_0, field_20);
                field_20 = nullptr;
            }
        }
        // empties it (inline in slots 12 and 13: placeholder name; its
        // delete's line is the header's too)
        void Unk_Reset() {
            field_0 = 0;
            field_4 = 0;
            field_8 = 0;
            field_c = -1;
            field_10 = 0;
            if (field_20 != nullptr) {
#line 328
                SI_DELETE(field_20->field_0, field_20);
                field_20 = nullptr;
            }
        }

        u32 field_0;
        u32 field_4;
        u32 field_8;
        s32 field_c;
        u32 field_10;
        u32 field_14;
        u64 field_18;
        Unk_Ranges* field_20;
    };
    // What a sampler's entry is made from when it isn't a sampler object
    // (placeholder name). (The entry clears field_24.)
    struct Unk_SamplerDesc {
        Unk_SamplerDesc()
            : field_0(0xc), field_4(1), field_8(1), field_c(1), field_10(0), field_14(0), field_18(100.0f),
              field_1c(1), field_20(8) {}

        u32 field_0;
        u32 field_4;
        u32 field_8;
        u32 field_c;
        u32 field_10;
        u32 field_14;
        f32 field_18;
        u32 field_1c;
        u32 field_20;
        u32 field_24[7];
    };
    // A sampler: a description or a sampler object, which it holds a
    // reference to.
    struct RootSamplerEntry {
        // (field_c's last words are cleared in the body: the array's reserve,
        // 0x7100558530, stores the sampler pointer before them)
        RootSamplerEntry() : field_0(0), field_4(0), field_8(0), field_50(nullptr) {
            for (int i = 0; i < 7; i++) {
                field_c.field_24[i] = 0;
            }
        }
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

    // What a shader slot's visibility is kept in (placeholder name): the
    // constructor clears the four tables as one 0x270-byte memset that isn't
    // a tail call, which elements with a constructor give (their loops become
    // a memset after the tail calls are marked).
    struct Unk_Slot {
        Unk_Slot() : field_0(0) {}

        u32 field_0;
    };

    SiGfxNXRootSignature(ISiAllocator* pAllocator, SiGfxNXDevice* pDevice);  // 0x7100556cf0
    ~SiGfxNXRootSignature() override;                                        // 0x7100556db0, 0x7100556fb0
    u32 vf2() override;                                                      // 0x7100557c80
    u32 vf3() override;                                                      // 0x7100557ca0
    u32 vf4() override;
    virtual Unk_NXDeviceInterface* vf5();
    virtual Unk_NXDeviceInterface* vf6();
    virtual u32 vf7();
    virtual bool vf8();    // 0x7100557020: starts changes
    virtual bool vf9();    // 0x7100557120: ends the changes
    // 0x7100557430: how many parameters (not written: its array's reserve,
    // 0x7100558360, instantiated here, changes how the clear is inlined in
    // the destructor)
    virtual bool vf10(s32 count);
    virtual u32 vf11();
    // 0x71005574f0, 0x7100557660: a parameter of a kind (1 to 3), or of
    // kind 4 with one more number
    virtual bool vf12(s32 index, u32 kind, u32 a3, u32 a4, u32 a5);
    virtual bool vf13(s32 index, u32 a2, u32 a3, u32 a4, u32 a5);
    // 0x71005577e0: a parameter of kind 5, with count ranges
    virtual bool vf14(s32 index, u32 a2, s32 count);
    // 0x7100557a00: a parameter's range
    virtual bool vf15(s32 index, s32 range, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);
    virtual bool vf16(s32 count);  // 0x7100557aa0: how many samplers
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
    // the stages that see each slot, by the kind of descriptor (slot 9 fills
    // them in: kinds 4, 1, 2 and 3)
    Unk_Slot field_c8[64];
    Unk_Slot field_1c8[64];
    Unk_Slot field_2c8[14];
    Unk_Slot field_300[14];
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
