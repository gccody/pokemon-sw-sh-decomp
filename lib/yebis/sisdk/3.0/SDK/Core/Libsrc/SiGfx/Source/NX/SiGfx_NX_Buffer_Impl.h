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

    // What slot 21 makes a buffer from (placeholder name and members): 0x58
    // bytes.
    struct Unk_MakeDesc {
        Unk_MakeDesc(u32 a0, u32 a4, u32 a8, s32 count, u32 flags, u32 a24)
            : field_0(a0), field_4(a4), field_8(a8), field_c(0), field_10(count), field_18(0), field_1c(flags),
              field_20(0), field_24(a24), field_28(0), field_30(nullptr), field_38(0) {
            field_14 = 0;
            field_15 = 0;
            field_16 = 0;
            field_40 = 0;
            for (int i = 0; i < 4; i++) {
                field_44[i] = -1;
            }
        }

        u32 field_0;  // its format (0x2a, 0x39: an index buffer's)
        s32 field_4;  // its size
        s32 field_8;  // its alignment, or the size of an element
        u32 field_c;
        s32 field_10;  // how many copies of it there are
        u8 field_14;
        u8 field_15;
        u8 field_16;
        u32 field_18;
        u32 field_1c;  // flags
        u32 field_20;
        u32 field_24;
        s32 field_28;          // the data's size (0: the buffer's)
        const void* field_30;  // the data
        SiGfxNXMemoryHeap* field_38;  // a heap to make it in (null: one of its own or the device's)
        s32 field_40;  // where in that heap (0: anywhere)
        s32 field_44[4];
    };
    PKMN_SIZE_ASSERT(Unk_MakeDesc, 0x58);

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
    virtual SiGfxNXMemoryHeap* vf19();  // its memory's heap
    virtual void vf20();
    virtual bool vf21(Unk_MakeDesc* desc);  // 0x7100537760: makes it
    virtual void vf22();                        // 0x7100538620: lets go of the NVN buffer and its memory
    virtual void vf23();
    virtual void vf24(unsigned long long value);  // 0x71005389a0
    virtual unsigned long long vf25();          // 0x71005389b0
    virtual void vf26();
    virtual u64 vf27();  // its memory's address
    virtual void vf28();
    virtual void vf29();
    bool vf30(const char* name) override;       // 0x7100537560
    const SiString<char>* vf31() override;      // 0x7100537640
    u32 vf32() override;                        // 0x7100537660

    // 0x7100537930, 0x7100537b60, 0x7100537df0, 0x7100538090: make the NVN
    // buffer for the kinds of buffer slot 21's flags tell (1, 2, 4, none)
    bool Unk_537930(const Unk_MakeDesc* desc);
    bool Unk_537b60(const Unk_MakeDesc* desc);
    bool Unk_537df0(const Unk_MakeDesc* desc);
    bool Unk_538090(const Unk_MakeDesc* desc);
    // 0x7100538340: the texture and view of a buffer that is read as one
    bool Unk_538340(const Unk_MakeDesc* desc);
    // 0x71005386d0: finds the memory (a heap's, its own or the device's)
    bool Unk_5386d0(s64* size, s64* alignment, const Unk_MakeDesc* desc);
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
    u32 field_134;
    void* field_138;  // NVNtexture
    void* field_140;  // NVNtextureView
    u64 field_148;    // the image handle
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
