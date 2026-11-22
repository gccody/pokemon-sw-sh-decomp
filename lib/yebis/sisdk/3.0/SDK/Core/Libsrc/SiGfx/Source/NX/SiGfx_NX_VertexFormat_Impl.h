// SiSDK3::SiGfxNXVertexFormat (RTTI names the class; like the other NX
// resources it is on ISiInterface and, at 8, ISiNamedObject): a vertex
// format's elements and where each stream's attributes are. Placeholder
// members; the virtual functions are vf<slot>. The reference counts are
// defined in this header (their __FILE__), at the original's lines, for the
// class's own translation unit (UNK_SIGFX_NX_VERTEXFORMAT_IMPL).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/Unk_NXResource.h>

namespace SiSDK3 {

// The named object's functions are the vertex format's slots 35 to 37.
UNK_NAMED_OBJECT(Unk_NXVertexFormatNamedObject, vf35, vf36, vf37);

class SiGfxNXVertexFormat : public Unk_NXInterface, public Unk_NXVertexFormatNamedObject {
public:
    // An element (placeholder name and members).
    struct Unk_Element {
        u32 field_0;   // what it is (the row of the three tables below)
        s32 field_4;   // which of them (their column)
        u32 field_8;   // its format (0: none)
        s32 field_c;   // its stream
        s32 field_10;  // its offset in the stream (negative: after the one before)
        u32 field_14;
        u32 field_18;
    };

    SiGfxNXVertexFormat(ISiAllocator* pAllocator, SiGfxNXDevice* pDevice);  // 0x7100564560
    ~SiGfxNXVertexFormat() override;            // 0x71005646c0, 0x7100564800
    u32 vf2() override;                         // 0x7100565430
    u32 vf3() override;                         // 0x7100565450
    u32 vf4() override;
    virtual Unk_NXDeviceInterface* vf5();
    virtual Unk_NXDeviceInterface* vf6();
    virtual size_t vf7();  // its index in the pool
    virtual const Unk_NXResourceInfo* vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual u32 vf16();
    virtual bool vf17(s32 count, const Unk_Element* elements);  // 0x7100564ac0
    virtual u32 vf18();
    virtual bool vf19(u32 a1, s32 a2, u32 a3, s32 a4, s32 a5, u32 a6, u32 a7);  // 0x7100564e50
    virtual bool vf20();                         // 0x7100564ee0
    virtual void vf21();
    virtual u32 vf22();
    virtual const Unk_Element* vf23();
    virtual const Unk_Element* vf24(s32 index);  // 0x71005650e0
    virtual u32 vf25();
    virtual u32 vf26(s32 index);                 // 0x7100565130
    virtual s32 vf27(u32 stream, s32 index);     // 0x7100565150
    virtual s32 vf28(u32 stream, s32 index);     // 0x7100565160
    virtual u32 vf29(u32 stream, s32 index);     // 0x7100565180
    virtual bool vf30(u32 stream, s32 index);
    virtual s32 vf31(u32 stream);                // 0x71005651c0
    virtual const Unk_Element* vf32();
    virtual void vf33(s32 index, s32 value);     // 0x71005653f0
    virtual s32 vf34(s32 index);                 // 0x7100565400
    bool vf35(const char* name) override;        // 0x7100564960
    const SiString<char>* vf36() override;       // 0x71005649e0
    u32 vf37() override;                         // 0x7100564a00

    // 0x7100564cd0: the streams' sizes and how many there are
    void Unk_564cd0();

    Unk_4bf660 field_10;
    SiGfxNXDevice* field_20;
    size_t field_28;          // its index in the pool (0: it isn't in one)
    SiString<char> field_30;  // the name
    u32 field_60;             // its hash
    Unk_NXResourceInfo field_64;
    bool field_78;  // whether it's being changed
    Unk_Element field_7c[32];
    s32 field_3fc;  // how many elements
    s32 field_400[16];  // each stream's first element's field_14 (0x7fffffff: none)
    u32 field_440;
    u32 field_444;  // the elements' checksum
    s8 field_448[10][16];
    s16 field_4e8[10][16];
    u8 field_628[10][16];
    s32 field_6c8[16];  // each stream's size
    s32 field_708[16];  // each stream's alignment
};
PKMN_OFFSET_ASSERT(SiGfxNXVertexFormat, field_7c, 0x7c);
PKMN_OFFSET_ASSERT(SiGfxNXVertexFormat, field_3fc, 0x3fc);
PKMN_OFFSET_ASSERT(SiGfxNXVertexFormat, field_448, 0x448);
PKMN_OFFSET_ASSERT(SiGfxNXVertexFormat, field_6c8, 0x6c8);
PKMN_SIZE_ASSERT(SiGfxNXVertexFormat, 0x748);

}  // namespace SiSDK3

#ifdef UNK_SIGFX_NX_VERTEXFORMAT_IMPL
// 0x7100565430 (vf2), 0x7100565450 (vf3)
#line 36
UNK_REFCOUNT_DEFINE(SiSDK3::SiGfxNXVertexFormat, field_10.m_pAllocator, field_10.m_count)
#endif
