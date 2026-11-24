// Scope: common
// SiSDK3::SiGfxNXRootSignature: its construction and destruction, its
// samplers' entries, and the reference counts its header defines. (Its small
// accessors are lib/yebis/class's; the functions that set its parameters
// aren't written yet.)
#define UNK_SIGFX_NX_ROOTSIGNATURE_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_RootSignature_Impl.h>

namespace SiSDK3 {

// (Slot 9's ranges read the stages into a local before the range: the load
// isn't sunk past the range's first test then.)
// The device as slot 9 asks it for a sampler (placeholder name: slot 52, as
// the draw context calls it too).
class Unk_RootSignatureDevice {
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
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual Unk_NXRootSampler* vf52(const SiGfxNXRootSignature::Unk_SamplerDesc* desc, void* a2, u32 a3, void* a4);
};

// Gives the slots from first on (count of them, or up to the limit for a
// negative count) the stages that see them; false for a slot outside the
// table (inline in slot 9: placeholder name).
static inline bool Unk_SetSlots(SiGfxNXRootSignature::Unk_Slot* slots, s32 limit, s32 first, s32 count, u32 stages) {
    s64 end = count >= 0 ? first + count : limit;
    if (first < 0) {
        return false;
    }
    s64 i = first;
    do {
        if (i >= limit) {
            return false;
        }
        slots[i].field_0 |= stages;
        i++;
    } while (i < end);
    return true;
}

// 0x7100558360: SiCore_Array.h's reserve with the clear called where that
// one frees the buffer and zeroes the members after it (the original calls
// 0x71005581e0 there)
template <>
bool SiArray<SiGfxNXRootSignature::RootParameterEntry, 16>::Unk_4bf190(size_t count, bool keep) {
    if (m_reservedCount == count) {
        return true;
    }
    if (count == 0) {
        Unk_4e3050();
        return true;
    }
    if (m_pAllocator == nullptr) {
        return false;
    }
    size_t itemCount = m_itemCount;
#line 1489 "../../../../Include\\SiCore/SiCore_Array.h"
    SiGfxNXRootSignature::RootParameterEntry* pData; SI_NEW_ARRAY(pData, m_pAllocator, SiGfxNXRootSignature::RootParameterEntry, count, 16)
    size_t n = itemCount > count ? count : itemCount;
    if (pData == nullptr) {
        return false;
    }
    if (n != 0 && keep) {
        for (size_t i = 0; i < n; i++) {
            pData[i] = m_pData[i];
        }
    }
    Unk_4e3050();
    m_pData = pData;
    m_itemCount = n;
    m_reservedCount = count;
    return true;
}

// 0x7100556cf0
SiGfxNXRootSignature::SiGfxNXRootSignature(ISiAllocator* pAllocator, SiGfxNXDevice* pDevice)
    : field_8(pAllocator), field_18(pDevice), field_20(0), field_24(false), field_25(false), field_28(pAllocator),
      field_78(pAllocator) {}

// (Both arrays are emptied here before their own destructors run: each
// array's vtable is stored after its buffer is freed.)
// NON_MATCHING (only the parameters' array's clear, 0x71005581e0, which this
// file instantiates): the same code, but in the loop over the parameters the
// original counts down before it advances the pointer (`subs ; add`), and
// this advances first. The samplers' array has the original's order with the
// same array delete. (Tried: the entry's destructor with a local pointer, an
// early return, a helper; the delete's counter as s64 or int. The delete's
// loop written over a pointer, `for (T* q = p; q != p + count; q++)`, or
// counting down gives the original's order here, but in SiCore_Memory.h it
// breaks 20 to 30 matched array deletes elsewhere.)
// (Round 3: the entry's destructor through a member helper, with an early
// return, a local pointer, or destroying and freeing by hand: no change.)
// 0x7100556db0 (D2), 0x7100556fb0 (D0)
SiGfxNXRootSignature::~SiGfxNXRootSignature() {
    field_28.Unk_FreeAll();
    field_78.Unk_FreeAll();
}

// 0x7100557020
bool SiGfxNXRootSignature::vf8() {
    if (field_25) {
        return false;
    }
    field_28.Unk_4e3050();
    field_78.Unk_FreeAll();
    field_24 = false;
    memset(field_c8, 0, sizeof(field_c8) + sizeof(field_1c8) + sizeof(field_2c8) + sizeof(field_300));
    field_25 = true;
    return true;
}

// 0x7100557120
bool SiGfxNXRootSignature::vf9() {
    if (!field_25) {
        return false;
    }
    field_24 = false;
    field_25 = false;
    memset(field_c8, 0, sizeof(field_c8) + sizeof(field_1c8) + sizeof(field_2c8) + sizeof(field_300));
    for (s64 i = 0; i < static_cast<s32>(field_28.m_itemCount); i++) {
        RootParameterEntry& entry = field_28.m_pData[i];
        switch (entry.field_0) {
        case 1:
            if (!Unk_SetSlots(field_1c8, 64, entry.field_8, entry.field_c, entry.field_4)) {
                return false;
            }
            break;
        case 2:
            if (!Unk_SetSlots(field_2c8, 14, entry.field_8, entry.field_c, entry.field_4)) {
                return false;
            }
            break;
        case 3:
            if (!Unk_SetSlots(field_300, 14, entry.field_8, entry.field_c, entry.field_4)) {
                return false;
            }
            break;
        case 4:
            return false;
        case 5: {
            if (entry.field_20 == nullptr) {
                return false;
            }
            s32 count = entry.field_20->field_8.m_itemCount;
            if (count < 1) {
                return false;
            }
            for (s32 k = 0; k < count; k++) {
                DescriptorRangeEntry& range = entry.field_20->field_8.m_pData[k];
                Unk_Slot* slots = field_1c8;
                s32 limit = 64;
                switch (range.field_0) {
                case 1:
                    break;
                case 2:
                    slots = field_2c8;
                    limit = 14;
                    break;
                case 3:
                    slots = field_300;
                    limit = 14;
                    break;
                case 4:
                    slots = field_c8;
                    limit = 64;
                    break;
                default:
                    return false;
                }
                u32 stages = entry.field_4;
                if (!Unk_SetSlots(slots, limit, range.field_4, range.field_8, stages)) {
                    return false;
                }
                // (a range of several slots takes as many entries)
                k += static_cast<s32>(range.field_8) > 1 ? range.field_8 - 1 : 0;
            }
            break;
        }
        }
    }
    for (s64 i = 0; i < static_cast<s32>(field_78.m_itemCount); i++) {
        RootSamplerEntry& entry = field_78.m_pData[i];
        if (entry.field_50 == nullptr) {
            Unk_NXRootSampler* sampler =
                reinterpret_cast<Unk_RootSignatureDevice*>(field_18)->vf52(&entry.field_c, nullptr, 0, nullptr);
            if (sampler == nullptr) {
                return false;
            }
            entry.field_50 = sampler;
        }
    }
    field_24 = true;
    return true;
}

// (The reserve this calls, 0x7100558360, calls the array's clear,
// 0x71005581e0, where SiCore_Array.h's frees the buffer and empties the array
// itself: the reserve is specialised for the parameters with that call. The
// samplers' array's reserve, 0x7100558530, is SiCore_Array.h's: its
// constructor stores the sampler pointer before the description's last
// words, which the entry's constructor clears in its body.)
// 0x7100557430
bool SiGfxNXRootSignature::vf10(s32 count) {
    if (!field_25) {
        return false;
    }
    field_28.Unk_SetCount(count);
    return true;
}

// NON_MATCHING: slot 12's test of the kind is made before the flag is read
// (the frame and the one epilogue are the original's now). The two early
// returns are joined into one `or` of the conditions, which Reassociate
// orders by rank (the kind's test is computed from an argument, the flag's
// from a load); the original keeps the flag's test first and sets `w0` to
// zero again in the kind's block, so its kind test has a return value of its
// own there.
// Tried: the flag in an int-sized local, a result variable, the tests as one
// condition and one by one; (round 12) slot 13's form (a result variable,
// `field_25 && index >= 0`, which matches there) with the kind's test in the
// outer condition, an inner if, its own return or a switch: the kind's test
// is always hoisted before the flag's.
// 0x71005574f0
bool SiGfxNXRootSignature::vf12(s32 index, u32 kind, u32 a3, u32 a4, u32 a5) {
    if (index < 0) {
        return false;
    }
    if (!field_25) {
        return false;
    }
    if (kind < 1 || kind > 3) {
        return false;
    }
    if (static_cast<s32>(field_28.m_itemCount) <= index) {
        return false;
    }
    RootParameterEntry& entry = field_28.m_pData[index];
    entry.Unk_Reset();
    entry.field_0 = kind;
    entry.field_4 = a3;
    entry.field_8 = a4;
    entry.field_c = a5;
    return true;
}

// 0x7100557660
bool SiGfxNXRootSignature::vf13(s32 index, u32 a2, u32 a3, u32 a4, u32 a5) {
    bool result = false;
    if (field_25 && index >= 0) {
        if (index < static_cast<s32>(field_28.m_itemCount)) {
            RootParameterEntry& entry = field_28.m_pData[index];
            entry.Unk_Reset();
            entry.field_0 = 4;
            entry.field_4 = a2;
            entry.field_8 = a3;
            entry.field_c = a4;
            entry.field_10 = a5;
            result = true;
        }
    }
    return result;
}

// NON_MATCHING: the original keeps the count known to be zero after the
// ranges' constructor in one register through the default allocator's call
// (`mov x8, xzr`, then the reload); here the null allocator's path is
// threaded into a copy of the count's test. With the parameter stored
// before the count is set, the code is the original's but for that store's
// place. Tried: every single-line move.
// 0x71005577e0
bool SiGfxNXRootSignature::vf14(s32 index, u32 a2, s32 count) {
    bool result = false;
    if (field_25 && index >= 0) {
        if (index < static_cast<s32>(field_28.m_itemCount)) {
            RootParameterEntry& entry = field_28.m_pData[index];
            entry.Unk_Reset();
            entry.field_0 = 5;
            entry.field_4 = a2;
#line 547
            Unk_Ranges* ranges = UNK_SI_NEW(field_8.m_pAllocator, 0x10) Unk_Ranges(field_8.m_pAllocator);
            ranges->field_8.Unk_SetCount(count);
            entry.field_20 = ranges;
            result = true;
        }
    }
    return result;
}

// 0x7100557aa0
bool SiGfxNXRootSignature::vf16(s32 count) {
    if (!field_25) {
        return false;
    }
    field_78.Unk_SetCount(count);
    return true;
}

// 0x7100557a00
bool SiGfxNXRootSignature::vf15(s32 index, s32 range, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 changing = field_25;
    if (index >= 0 && changing != 0) {
        if (static_cast<s32>(field_28.m_itemCount) <= index) {
            return false;
        }
        Unk_Ranges* ranges = field_28.m_pData[index].field_20;
        if (range >= 0) {
            if (ranges != nullptr) {
                if (static_cast<s32>(ranges->field_8.m_itemCount) <= range) {
                    return false;
                }
                ranges->field_8.m_pData[range].field_0 = a3;
                ranges->field_8.m_pData[range].field_4 = a4;
                ranges->field_8.m_pData[range].field_8 = a5;
                ranges->field_8.m_pData[range].field_c = a6;
                ranges->field_8.m_pData[range].field_10 = a7;
                return true;
            }
        }
    }
    return false;
}

// (In these two the flag is read into an int-sized local before the tests:
// the original has the index's test and the flag's as one condition, which
// LLVM only makes of two when the second costs one instruction besides its
// compare, and a byte's promotion would be a second.)
// 0x7100557b60
bool SiGfxNXRootSignature::vf18(s32 index, u32 a2, u32 a3, u32 a4, const Unk_SamplerDesc* desc) {
    u32 changing = field_25;
    if (index >= 0 && changing != 0) {
        if (static_cast<s32>(field_78.m_itemCount) <= index) {
            return false;
        }
        RootSamplerEntry& entry = field_78.m_pData[index];
        entry.field_0 = a2;
        entry.field_4 = a3;
        entry.field_8 = a4;
        entry.field_c = *desc;
        entry.field_50 = nullptr;
        return true;
    }
    return false;
}

// 0x7100557be0
bool SiGfxNXRootSignature::vf19(s32 index, u32 a2, u32 a3, u32 a4, Unk_NXRootSampler* sampler) {
    u32 changing = field_25;
    if (index >= 0 && changing != 0) {
        if (static_cast<s32>(field_78.m_itemCount) <= index) {
            return false;
        }
        RootSamplerEntry& entry = field_78.m_pData[index];
        entry.field_0 = a2;
        entry.field_4 = a3;
        entry.field_8 = a4;
        entry.field_50 = sampler;
        sampler->vf2();
        return true;
    }
    return false;
}

// 0x7100557c60
Unk_NXRootSampler* SiGfxNXRootSignature::vf21(s32 index) {
    return field_78.m_pData[index].field_50;
}

}  // namespace SiSDK3
