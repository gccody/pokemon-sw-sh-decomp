// SiSDK3::SiGfxPerformanceUtility: what draws the performance bars. As far as
// the executable's functions show it, with placeholder members (RTTI names
// the classes). The reference counts are defined in this header (their
// __FILE__), at the original's lines, for the file that asks with
// UNK_SIGFX_PERFORMANCEUTILITY_IMPL. The virtual functions declared and not
// defined here or in the .cpp are lib/yebis/class's or not decompiled yet
// (placeholder signatures).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_Array.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_4bf660.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_Interface.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>

namespace SiSDK3 {

// A reference counted pointer that drops its reference when it's destroyed
// (placeholder name).
template <class T>
struct Unk_RefPtr {
    Unk_RefPtr() : m_p(nullptr) {}
    ~Unk_RefPtr() { Unk_Release(); }
    void Unk_Release() {
        if (m_p != nullptr) {
            m_p->vf3();
            m_p = nullptr;
        }
    }

    T* m_p;
};

// What the utility draws with (placeholder name): two objects and up to four
// pairs of them.
struct Unk_4e2120 {
    struct Unk_Pair {
        Unk_RefPtr<ISiInterface> field_0;
        Unk_RefPtr<ISiInterface> field_8;
    };

    Unk_4e2120() : field_0(nullptr), field_8(nullptr), field_10(0), field_14(4) {}
    // 0x71004e2120
    ~Unk_4e2120();
    // drops them all (inline: placeholder name)
    void Unk_Release() {
        for (s64 i = 0; i < field_14; i++) {
            field_18[i].field_8.Unk_Release();
            field_18[i].field_0.Unk_Release();
        }
        if (field_8 != nullptr) {
            field_8->vf3();
            field_8 = nullptr;
        }
        if (field_0 != nullptr) {
            field_0->vf3();
            field_0 = nullptr;
        }
        field_10 = 0;
    }

    ISiInterface* field_0;
    ISiInterface* field_8;
    u32 field_10;
    s32 field_14;  // how many pairs
    Unk_Pair field_18[4];
};
PKMN_SIZE_ASSERT(Unk_4e2120, 0x58);

class SiGfxPerformanceUtility {
public:
    // RTTI: the elements of the utility's arrays
    struct RenderPerfBarSegmentData {
        u32 field_0;
        u32 field_4;
        u32 field_8;
    };
    struct RenderPerfBarTextData {
        u8 field_0[0x88];
    };
    template <class T>
    struct RollingPerfData {
        ~RollingPerfData() { field_8.Unk_FreeAll(); }
        // empties it (inline: placeholder name)
        void Unk_Reset() {
            field_8.Unk_Clear();
            field_58 = 0;
        }

        u64 field_0;
        SiArray<T> field_8;
        u64 field_58;
        u64 field_60;
    };

    // a value of 16 bytes (placeholder name)
    struct Unk_Value {
        u32 field_0[4];
    };

    // 0x71004e1bd0
    explicit SiGfxPerformanceUtility(ISiAllocator* pAllocator);
    virtual ~SiGfxPerformanceUtility();
    UNK_REFCOUNT_DECLARE;
    virtual u32 vf4();
    // 0x71004e25f0: makes its drawing objects for a render target's device
    virtual bool vf5(ISiInterface* target);
    virtual bool vf6(const Unk_Value* value);  // 0x71004e2c30
    virtual u32 vf7();
    virtual bool vf8(u32 mode);  // 0x71004e2c50: empties the bars for another mode

    // 0x71004e1f40: releases what it holds
    void Unk_4e1f40();
    // 0x71004e2430: drops the drawing objects and empties the rolling data,
    // for a device that goes (the device isn't read)
    void Unk_4e2430(void* pDevice);

    Unk_4bf660 field_8;
    u32 field_18;  // the mode
    u32 field_1c;
    bool field_20;
    bool field_21;
    Unk_Value field_24;
    f32 field_34;
    f32 field_38;
    f32 field_3c;
    f32 field_40;
    f32 field_44;
    u32 field_48;
    s32 field_4c;
    u64 field_50;
    u64 field_58;
    SiArray<RenderPerfBarSegmentData> field_60;
    SiArray<RenderPerfBarTextData> field_b0;
    u32 field_100;
    Unk_4e2120 field_108;
    SiArray<RollingPerfData<float>> field_160;
    SiArray<RollingPerfData<int>> field_1b0;
    SiArray<RollingPerfData<float>> field_200;
    SiArray<RollingPerfData<int>> field_250;
};
PKMN_SIZE_ASSERT(SiGfxPerformanceUtility::RollingPerfData<float>, 0x68);
PKMN_OFFSET_ASSERT(SiGfxPerformanceUtility, field_24, 0x24);
PKMN_OFFSET_ASSERT(SiGfxPerformanceUtility, field_108, 0x108);
PKMN_SIZE_ASSERT(SiGfxPerformanceUtility, 0x2a0);

}  // namespace SiSDK3

#ifdef UNK_SIGFX_PERFORMANCEUTILITY_IMPL
// 0x71004e2d90 (vf2), 0x71004e2db0 (vf3)
#line 33
UNK_REFCOUNT_DEFINE(SiSDK3::SiGfxPerformanceUtility, field_8.m_pAllocator, field_8.m_count)
#endif
