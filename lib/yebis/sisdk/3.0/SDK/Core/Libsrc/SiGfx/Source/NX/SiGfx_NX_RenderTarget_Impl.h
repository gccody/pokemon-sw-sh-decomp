// SiSDK3::SiGfxNXRenderTarget (RTTI names the class; it derives from
// ISiGfxNXRenderTarget, ISiGfxRenderTarget and ISiGfxResource, which is on
// ISiInterface and, at 8, ISiNamedObject): up to eight colour attachments and
// a depth attachment, each a texture, a surface or a volume's slice.
// Placeholder members; the virtual functions are vf<slot>. The reference
// counts, with deferred deletion, are defined in this header (their
// __FILE__), at the original's lines, for the class's own translation unit
// (UNK_SIGFX_NX_RENDERTARGET_IMPL).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCountDeferred.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/Unk_NXResource.h>

namespace SiSDK3 {

// The named object's functions are the render target's slots 40 to 42.
UNK_NAMED_OBJECT(Unk_NXRenderTargetNamedObject, vf40, vf41, vf42);

// What an attachment's slots 17 and 19 describe it by, as the render target
// reads them (placeholder names): a surface's description and a volume's,
// both with the format second.
struct Unk_NXAttachmentSurfaceDesc {
    u32 field_0;
    u32 field_4;  // the format
    s32 field_8;  // a texture's width
    s32 field_c;  // and height
    u32 field_10;
    s32 field_14;  // a surface's width
    s32 field_18;  // and height
};
struct Unk_NXAttachmentVolumeDesc {
    u32 field_0;  // its kind
    u32 field_4;  // the format
    u32 field_8;
    u32 field_c;
    u32 field_10;
    s32 field_14;  // its width
    s32 field_18;  // and height
};

// What a render target is attached to, as it calls it (placeholder name):
// slots 2 and 3 count its references, slots 15 and 16 are what the render
// target's own slots 15 and 16 call on every attachment.
class Unk_NXAttachment {
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
    virtual void vf15(u32 value);
    virtual u32 vf16();
    // slots 17 and 19: its resource's information (a surface's and a
    // volume's); 24 and 25: a texture's level's surface (in a layer)
    virtual const Unk_NXAttachmentSurfaceDesc* vf17();
    virtual void vf18();
    virtual const Unk_NXAttachmentVolumeDesc* vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual Unk_NXAttachment* vf24(u32 level);
    // slot 25 is also a surface's NVN texture, 26 its view; 40 is a
    // texture's NVN texture, 42 the view of a level in a layer
    virtual Unk_NXAttachment* vf25();
    virtual u64 vf26();
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
    virtual u64 vf40();
    virtual void vf41();
    virtual u64 vf42(s32 level, s32 layer);
};

class SiGfxNXRenderTarget : public Unk_NXInterface, public Unk_NXRenderTargetNamedObject {
public:
    // A colour attachment (placeholder name): its kind (0: none) and what it
    // is for each kind.
    struct Unk_Color {
        u32 field_0;
        Unk_NXAttachment* field_8;   // kind 1
        u32 field_10;
        Unk_NXAttachment* field_18;  // kind 2
        Unk_NXAttachment* field_20;  // kind 3
        u32 field_28;
        u32 field_2c;
        u32 field_30;
        u32 field_34;
    };
    // The depth attachment (placeholder name).
    struct Unk_Depth {
        u32 field_0;
        Unk_NXAttachment* field_8;   // kind 1
        Unk_NXAttachment* field_10;  // kind 2
        Unk_NXAttachment* field_18;  // kind 3
        u32 field_20;
        u32 field_24;
        u32 field_28;
        u32 field_2c;
        bool field_30;
    };
    // What the constructor clears as one block before the attachments, which
    // it clears one by one: a member with an inline function that clears it
    // (placeholder names).
    struct Unk_298 {
        void Unk_Clear() {
            field_0 = 0;
            for (int i = 0; i < 8; i++) {
                field_4[i] = 0;
            }
            field_24 = 0;
        }

        s32 field_0;      // how many colour attachments there are
        u32 field_4[8];   // their formats
        u32 field_24;     // the depth attachment's
    };
    // What slot 17 returns (placeholder name).
    struct Unk_Desc {
        s32 field_0;  // the width
        s32 field_4;  // and height
        u32 field_8;
        s32 field_c;   // the first colour attachment
        s32 field_10;  // how many colour attachments it has
        u32 field_14;
        bool field_18;  // whether it has a depth attachment
        bool field_19;  // whose format has a stencil
        u8 field_1a[6];
        u64 field_20;
    };
    PKMN_SIZE_ASSERT(Unk_Desc, 0x28);

    SiGfxNXRenderTarget(ISiAllocator* pAllocator, SiGfxNXDevice* pDevice);  // 0x71005556d0
    ~SiGfxNXRenderTarget() override;                                        // 0x71005558c0, 0x7100555a00
    u32 vf2() override;                                                     // 0x7100556b00
    u32 vf3() override;                                                     // 0x7100556b20
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
    virtual void vf15(u32 value);  // 0x71005569c0
    virtual u32 vf16();            // 0x7100556a60
    virtual const Unk_Desc* vf17();
    virtual bool vf18();  // starts a change of the attachments
    // 0x7100555d00, 0x7100555d90, 0x7100555e20: a colour attachment of each kind
    virtual bool vf19(s32 index, Unk_NXAttachment* attachment, u32 a3);
    virtual bool vf20(s32 index, Unk_NXAttachment* attachment);
    virtual bool vf21(s32 index, Unk_NXAttachment* attachment, u32 a3, u32 a4, u32 a5, u32 a6);
    // 0x7100555ed0, 0x7100555f40, 0x7100555fb0: the depth attachment of each kind
    virtual bool vf22(Unk_NXAttachment* attachment, bool flag);
    virtual bool vf23(Unk_NXAttachment* attachment, bool flag);
    virtual bool vf24(u64 a1, Unk_NXAttachment* attachment, bool flag, u32 a4, u32 a5, u32 a6, u32 a7);
    virtual bool vf25();  // 0x7100556050: ends the change
    virtual void vf26();  // 0x7100556840: detaches everything
    virtual Unk_Color* vf27(s32 index);  // 0x7100556930
    virtual Unk_Color* vf28(s32 index);  // 0x7100556940
    virtual const u8* vf29();
    virtual const u8* vf30();
    virtual u32 vf31();
    virtual u64 vf32();
    virtual u64 vf33();
    virtual u8 vf34();
    virtual const u8* vf35();
    virtual const u8* vf36();
    virtual const u8* vf37();
    virtual u64 vf38();
    virtual u64 vf39();
    bool vf40(const char* name) override;       // 0x7100555b50
    const SiString<char>* vf41() override;      // 0x7100555bd0
    u32 vf42() override;                        // 0x7100555bf0

    // 0x71005560c0 (the size and the attachments there are), 0x71005564a0
    // (the attachments' NVN textures and views), 0x7100556730: what slot 25
    // does
    bool Unk_5560c0();
    bool Unk_5564a0();
    bool Unk_556730();

    Unk_538d70 field_10;
    SiGfxNXDevice* field_20;
    size_t field_28;          // its index in the pool (0: it isn't in one)
    SiString<char> field_30;  // the name
    u32 field_60;             // its hash
    Unk_NXResourceInfo field_64;
    Unk_Desc field_78;
    Unk_Color field_a0[8];
    Unk_Depth field_260;
    Unk_298 field_298;
    u64 field_2c0[8];
    u64 field_300;
    u64 field_308[8];
    u64 field_348;
    bool field_350;
    bool field_351;  // whether the attachments are being changed
};
PKMN_SIZE_ASSERT(SiGfxNXRenderTarget::Unk_Color, 0x38);
PKMN_SIZE_ASSERT(SiGfxNXRenderTarget::Unk_Depth, 0x38);
PKMN_OFFSET_ASSERT(SiGfxNXRenderTarget, field_a0, 0xa0);
PKMN_OFFSET_ASSERT(SiGfxNXRenderTarget, field_260, 0x260);
PKMN_OFFSET_ASSERT(SiGfxNXRenderTarget, field_2c0, 0x2c0);
PKMN_SIZE_ASSERT(SiGfxNXRenderTarget, 0x358);

}  // namespace SiSDK3

#ifdef UNK_SIGFX_NX_RENDERTARGET_IMPL
// 0x7100556b00 (vf2), 0x7100556b20 (vf3)
#line 36
UNK_REFCOUNT_DEFERRED_DEFINE(SiSDK3::SiGfxNXRenderTarget, field_10.m_pAllocator, field_10.m_count, field_10.field_c)
#endif
