// SiSDK3::SiGfxNXBuffer (RTTI names the class; like the other NX resources it
// is on ISiInterface and, at 8, ISiNamedObject): an NVN buffer in a memory
// heap. Placeholder members; the virtual functions are vf<slot>. The
// reference counts are defined in this header (their __FILE__), at the
// original's lines, for the class's own translation unit
// (UNK_SIGFX_NX_BUFFER_IMPL).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCountDeferred.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_MemoryHeap_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/Unk_NXResource.h>

namespace SiSDK3 {

// The named object's functions are the buffer's slots 30 to 32.
UNK_NAMED_OBJECT(Unk_NXBufferNamedObject, vf30, vf31, vf32);

class SiGfxNXBuffer : public Unk_NXInterface, public Unk_NXBufferNamedObject {
public:
    // What a buffer is described by (placeholder name and members).
    struct Unk_Desc {
        u32 field_0;
        s32 field_4;  // its size
        u32 field_8;
        u32 field_c;
        u32 field_10;
        u32 field_14;
    };

    SiGfxNXBuffer(ISiAllocator* pAllocator, SiGfxNXDevice* pDevice);  // 0x7100537200
    ~SiGfxNXBuffer() override;                  // 0x7100537370, 0x71005374f0
    u32 vf2() override;                         // 0x71005389c0
    u32 vf3() override;                         // 0x71005389e0
    u32 vf4() override;
    virtual Unk_NXDeviceInterface* vf5();
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
    virtual void vf22();                        // 0x7100538620: lets go of the NVN buffer and its memory
    virtual void vf23();
    virtual void vf24(unsigned long long value);  // 0x71005389a0
    virtual unsigned long long vf25();          // 0x71005389b0
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    bool vf30(const char* name) override;       // 0x7100537560
    const SiString<char>* vf31() override;      // 0x7100537640
    u32 vf32() override;                        // 0x7100537660

    // 0x7100538910: tells NVN that the mapped buffer was written
    void Unk_538910();

    Unk_538d70 field_10;
    SiGfxNXDevice* field_20;
    size_t field_28;             // its index in the pool (0: it isn't in one)
    Unk_NXString<0x40> field_30;  // the name
    u32 field_a0;                // its hash
    Unk_NXResourceInfo field_a4;
    Unk_Desc field_b8;
    u64 field_d0[6];  // NVNbuffer
    u64 field_100;
    SiGfxNXMemoryHeap* field_108;  // its memory's heap
    bool field_110;
    bool field_111;   // whether the memory is its own
    s64 field_118;    // where the memory is in the heap
    u64 field_120;
    bool field_128;   // whether the NVN buffer is made
    u32 field_12c;
    s32 field_130;    // its number in the device's table (-1: none)
    u8 field_134[0x1c];
    s32 field_150;    // which of field_170's values is current
    u32 field_154;
    unsigned long long field_158[3];
    SiArray<unsigned long long, 16> field_170;
};
PKMN_OFFSET_ASSERT(SiGfxNXBuffer, field_a0, 0xa0);
PKMN_OFFSET_ASSERT(SiGfxNXBuffer, field_d0, 0xd0);
PKMN_OFFSET_ASSERT(SiGfxNXBuffer, field_170, 0x170);
PKMN_SIZE_ASSERT(SiGfxNXBuffer, 0x1c0);

}  // namespace SiSDK3

#ifdef UNK_SIGFX_NX_BUFFER_IMPL
// 0x71005389c0 (vf2), 0x71005389e0 (vf3)
#line 39
UNK_REFCOUNT_DEFERRED_DEFINE(SiSDK3::SiGfxNXBuffer, field_10.m_pAllocator, field_10.m_count, field_10.field_c)
#endif
