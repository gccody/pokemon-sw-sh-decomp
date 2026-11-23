// PPFX::IGPUDevice (RTTI names the class; members are placeholders), as far
// as the functions written so far read it.
#pragma once

#include <unordered_map>
#include <vector>

#include <yebis/YEBIS_draft/include/PPFX/ppfxTypes.h>
#include <yebis/YEBIS_draft/src/GPU/GPUMemoryAllocator.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_Array.h>
#include <yebis/YEBIS_draft/src/GPU/GPUInterface.h>
#include <yebis/YEBIS_draft/src/GPU/Unk_SiGfx.h>

namespace PPFX {

// one element of a vertex layout: what it is (0 position, 2 texture
// coordinate), its index and its format
struct Unk_InputElement {
    Unk_InputElement(u32 usage, u32 index, u32 format)
        : field_0(usage), field_4(index), field_8(format), field_c(0), field_10(0), field_14(0) {}

    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u32 field_10;
    u32 field_14;
};
PKMN_SIZE_ASSERT(Unk_InputElement, 0x18);

// what vf17 fills in
struct Unk_Viewport {
    s32 field_0;
    s32 field_4;
    u32 field_8;  // width
    u32 field_c;  // height
    f32 field_10;  // the depth range
    f32 field_14;
};
PKMN_SIZE_ASSERT(Unk_Viewport, 0x18);

// the viewport as the device keeps it
struct Unk_ViewportF {
    f32 field_0;
    f32 field_4;
    f32 field_8;
    f32 field_c;
    f32 field_10;
    f32 field_14;
};

// a scissor rectangle's edges: left, top, right, bottom
struct Unk_ScissorRect {
    s64 field_0;
    s64 field_8;
    s64 field_10;
    s64 field_18;
};

// a blend colour: four floats, copied as they are
struct Unk_BlendColor {
    u32 field_0[4];
};

// any SiGfx object: slot 3 drops a reference
struct Unk_SiGfxInterface {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// SiGfx's render target as the device uses it: slot 10 gives its resource
struct Unk_SiGfxRenderTarget {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual bool vf8();  // whether its resources can be set (vf10, then vf9)
    virtual void vf9();
    virtual void** vf10();
    virtual Unk_SiGfxInterface** vf11();
};

// what a SiGfx texture's slots 19 and 8 give (placeholders): its description
// and its format's
struct Unk_SiGfxTextureDesc {
    u32 field_0;  // the kind (2: 2D, 3: volume)
    u32 field_4;  // the format
    u32 field_8;  // the formats of other views
    u32 field_c;
    u32 field_10;
    u32 field_14;  // the width
    u32 field_18;  // the height
    u32 field_1c;  // the depth
    u32 field_20;  // how many levels
    u8 pad_24[0xc];
    u32 field_30;
    u32 field_34;
};
struct Unk_SiGfxFormatInfo {
    u8 pad_0[0x8];
    u32 field_8;  // flags
};
// a SiGfx texture as a lazy command and the textures' slot 22 read it: slot
// 25 gives a level's surface (placeholder)
struct Unk_SiGfxTexture {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();  // adds a reference
    virtual void vf3();  // releases one
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual const Unk_SiGfxFormatInfo* vf8();
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
    virtual const Unk_SiGfxTextureDesc* vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void* vf25(u32 index);
};

// GPUSiGfxLazyDrawCommand (its Execute() is named in CPostEffect's log): a
// copy between two textures' surfaces, done when the post effect asks
struct GPUSiGfxLazyDrawCommand {
    s32 Execute(Unk_SiGfxDrawContext* context);  // 0x710043dc70

    u32 field_0;  // the kind (0: the copy)
    u8 pad_4[0x4];
    Unk_SiGfxTexture* field_8;
    Unk_SiGfxTexture* field_10;
    u32 field_18;
    u32 field_1c;
};
PKMN_OFFSET_ASSERT(GPUSiGfxLazyDrawCommand, field_1c, 0x1c);

// An index buffer as the device reads it (PPFX::IGPUIndexBuffer by RTTI:
// placeholder until that class is written): SiGfx buffers and which is used.
struct Unk_IndexBuffer : IGPUInterface {
    u8 pad_c[0x44];
    void** field_50;
    u32 field_58;
};
PKMN_OFFSET_ASSERT(Unk_IndexBuffer, field_50, 0x50);

// what vf6 keeps in Unk_24e1500
struct Unk_DeviceSettings {
    u64 field_0[4];
    u32 field_20;  // the viewport's origin (m_eViewportOriginMode)
    u32 field_24;  // the clip volume's near plane (eClipVolumeNearPlaneMode)
    u64 field_28;
};
PKMN_SIZE_ASSERT(Unk_DeviceSettings, 0x30);

// A surface or texture as the device reads it when it becomes a render
// target (PPFX::IGPUPixelContainer by RTTI: placeholder until that class is
// written).
struct Unk_PixelContainer : IGPUInterface {
    u8 pad_c[0x40];
    u32 field_4c;  // its size
    u32 field_50;
    u8 pad_54[0x54];
    void* field_a8;                // its SiGfx resource
    u8 pad_b0[0x8];
    Unk_SiGfxRenderTarget* field_b8;  // and what SiGfx draws to
};
PKMN_OFFSET_ASSERT(Unk_PixelContainer, field_a8, 0xa8);
PKMN_OFFSET_ASSERT(Unk_PixelContainer, field_4c, 0x4c);

// PPFX::IGPUBuffer: GPUInterfaceBuffer.h
class IGPUBuffer;

class IGPUQueryOcclusion;
class IGPUResource;

class IGPUDevice : public IGPUInterface {
public:
    // slots 4 to 75: only those this code calls are typed
    IGPUDevice();                        // 0x710043dd00
    ~IGPUDevice() override;              // 0x710043e170, 0x710043e5d0
    // 0x7100442c60 (its log lines name it)
    static IGPUDevice* CreateDevice(const Unk_DeviceSettings* settings, void* arg);
    virtual s32 vf4(IGPUDevice* other);  // 0x71004400a0
    virtual void vf5();
    virtual s32 vf6(const Unk_DeviceSettings* settings);  // 0x71004400d0
    virtual s32 vf7(u32 index, void* target, s32 arg3);  // 0x7100440130: sets a render target
    virtual s32 vf8(void* target);  // 0x7100440230: sets the depth target
    virtual s32 vf9(void* object, s32 arg2);  // 0x71004402b0
    virtual s32 vf10(u32 index, Unk_PixelContainer** target);  // 0x7100440320: a render target
    virtual s32 vf11(IGPUInterface** target);  // 0x7100440380: the depth target
    virtual s32 vf12(IGPUInterface** object);  // 0x7100440420
    virtual s32 vf13(IGPUInterface** object);  // 0x71004403d0: what vf9 set
    virtual s32 vf14(u32 index, IGPUInterface* texture);  // 0x7100440460: sets a texture
    virtual s32 vf15(u32 index, IGPUInterface** texture);  // 0x71004404c0: a texture
    virtual s32 vf16(const Unk_Viewport* viewport);  // 0x7100440520: sets the viewport
    virtual s32 vf17(Unk_Viewport* viewport);  // 0x71004405a0: the viewport
    virtual s32 vf18(const Unk_Viewport* rect);  // 0x7100440640: sets the scissor rectangle (null: the viewport)
    virtual s32 vf19(const Unk_ScissorRect* rect);  // 0x71004406f0: the same from its edges
    virtual void vf20();
    virtual void vf21();
    virtual s32 vf22();  // 0x7100440aa0: "IGPUDevice::ApplyRenderState_DepthTestEnable() is not supported."
    virtual s32 vf23();  // 0x7100440b50: "IGPUDevice::ApplyRenderState_DepthFunc() is not supported."
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33(s32 arg);  // (called with 0 before targets are cleared)
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual s32 vf39();  // 0x7100440d60: forgets the blend state that is set
    virtual void vf40(s32 arg);
    virtual s32 vf41(s32 state, bool cached);  // 0x7100440d90: applies a blend state (-1: the one vf42 set)
    virtual s32 vf42(s32 state);  // 0x7100440ed0: sets the blend state
    virtual s32 vf43();  // 0x7100440f00: the blend state
    virtual s32 vf44(s32 arg);  // 0x7100440f10: sets the blend state's bits 0 to 2
    virtual s32 vf45(s32 arg);  // 0x7100440fa0: its bits 3 and 4
    virtual s32 vf46(s32 arg);  // 0x7100440ff0: its bit 5
    virtual s32 vf47();  // what vf44 set
    virtual s32 vf48();  // 0x7100440fd0
    virtual s32 vf49();  // 0x7100441020
    virtual s32 vf50(const Unk_BlendColor* color);  // 0x7100440f60: sets the blend colour
    virtual s32 vf51(u32 flags, const f32* color, f32 depth, u32 stencil);  // 0x7100440790: sets what the target is cleared with, and begins drawing to it
    virtual s32 vf52(u32 flags, u32 color, f32 depth, u32 stencil);  // 0x7100440a20: vf51 with the colour as 0xAARRGGBB
    virtual void vf53();
    virtual s32 vf54(bool enable, s32 value);  // 0x7100442de0
    virtual s32 vf55(f32 a, f32 b);  // 0x7100442e10
    virtual void vf56();
    virtual s32 vf57(s32 primitive, u32 arg2, u32 arg3);  // 0x7100441050: "IGPUDevice::DrawVertices"
    virtual s32 vf58(s32 primitive, s32 count, s32 arg3, s32 arg4, s32 arg5);  // 0x71004411e0: "IGPUDevice::DrawIndices"
    virtual s32 vf59(s32 primitive, u32 arg2, u32 instances, u32 arg4);  // 0x71004413d0: "IGPUDevice::DrawIndicesInstanced"
    virtual s32 vf60(u32 width, u32 height, u32 arg3, u32 usage, s32 format, s32 msaa, u32 arg7, IGPUInterface** texture, u32 flags);  // 0x71004415d0: "IGPUDevice::CreateTexture"
    virtual s32 vf61(u32 width, u32 height, u32 depth, u32 arg4, u32 usage, s32 format, IGPUInterface** texture, u32 flags);  // 0x71004417b0: "IGPUDevice::CreateVolumeTexture"
    virtual s32 vf62(u32 width, u32 height, u32 arg3, u32 usage, s32 format, void* deviceTexture, IGPUInterface** texture);  // 0x7100441980: "IGPUDevice::CreateTexture" from a device texture
    virtual s32 vf63(u32 width, u32 height, u32 depth, u32 arg4, u32 usage, s32 format, void* deviceTexture, IGPUInterface** texture);  // 0x7100441b50: "IGPUDevice::CreateVolumeTexture" from a device texture
    virtual s32 vf64(u32 width, u32 height, s32 format, s32 msaa, u32 quality, IGPUInterface** surface, u32 flags, void* arg8, u32 arg9, bool unordered);  // 0x7100441d20: "IGPUDevice::CreateRenderTarget"
    virtual s32 vf65(u32 width, u32 height, s32 format, s32 msaa, u32 quality, IGPUInterface** surface, u32 flags, void* arg8, u32 arg9);  // 0x7100441f50: "IGPUDevice::CreateDepthStencilSurface"
    virtual s32 vf66(u32 width, u32 height, s32 format, IGPUInterface** surface, u32 flags);  // 0x7100442140: "IGPUDevice::CreateSurface"
    virtual s32 vf67(u32 width, u32 height, s32 format, s32 msaa, u32 quality, void* deviceSurface, IGPUInterface** surface);  // 0x7100442320: "IGPUDevice::CreateSurface" from a device surface
    virtual s32 vf68(u32 count, u32 stride, u32 usage, IGPUBuffer** buffer, u32 flags, void* arg6);  // 0x71004425c0: "IGPUDevice::CreateVertexBuffer"
    virtual s32 vf69(u32 count, u32 stride, s32 format, u32 usage, IGPUBuffer** buffer, u32 flags, void* arg7);  // 0x7100442770: "IGPUDevice::CreateIndexBuffer"
    virtual s32 vf70(const Unk_InputElement* elements, s32 count, void* arg3, s32 arg4, IGPUInterface** attribute);  // "IGPUDevice::CreateInputAttribute"
    virtual s32 vf71(IGPUQueryOcclusion** query);  // 0x71004424f0: "IGPUDevice::CreateQueryOcclusion"
    virtual s32 vf72(s32 arg1, s32 arg2, s32 arg3);  // 0x7100442a20
    virtual u32 vf73(s32 arg1, s32 arg2);  // 0x7100442a90
    virtual s32 vf74(s32 arg1, s32 arg2, s32 arg3);  // 0x7100442a30
    virtual s32 vf75(s32 arg1, s32 arg2, s32 arg3);  // 0x7100442b70

    // 0x710043e780: what the log lines call it
    s32 SetupSiGfxDrawContext(s32 primitive);

    // RTTI: SiSDK3::SiArray<PPFX::IGPUDevice::PipelineStateData, 16>. A
    // pipeline state SiGfx made, after 0x120 bytes that tell which.
    struct PipelineStateData {
        PipelineStateData() : field_0(0), field_8(0) {}

        u64 field_0;
        u64 field_8;
        u8 field_10[0x110];
        Unk_SiGfxInterface* field_120;
    };
    typedef SiSDK3::SiArray<PipelineStateData, 16> Unk_PipelineStates;
    // what the states are kept by (0x120 bytes; placeholder names)
    struct Unk_PipelineKey {
        struct Unk_Element {
            bool operator==(const Unk_Element& other) const {
                return field_0 == other.field_0 && field_4 == other.field_4 && field_8 == other.field_8 &&
                       field_c == other.field_c && field_10 == other.field_10 && field_14 == other.field_14 &&
                       field_18 == other.field_18;
            }

            u32 field_0;
            u32 field_4;
            u32 field_8;
            u32 field_c;
            u32 field_10;
            u32 field_14;
            u32 field_18;
        };

        bool operator==(const Unk_PipelineKey& other) const;  // 0x710043e640

        u64 field_0;  // the hash, which is all the table compares
        u8 pad_8[0x8];
        void* field_10;
        u32 field_18;
        Unk_Element field_1c[8];
        s32 field_fc;  // how many of field_1c there are
        u32 field_100[4];
        s32 field_110;  // how many of field_100 there are
        u8 pad_114[0x4];
        void* field_118;
    };
    static_assert(sizeof(Unk_PipelineKey) == 0x120, "Unk_PipelineKey");
    struct Unk_PipelineKeyHash {
        size_t operator()(const Unk_PipelineKey& key) const;
    };
    struct Unk_PipelineKeyEqual {
        bool operator()(const Unk_PipelineKey& a, const Unk_PipelineKey& b) const { return a.field_0 == b.field_0; }
    };
    typedef std::unordered_map<Unk_PipelineKey, Unk_PipelineStates*, Unk_PipelineKeyHash, Unk_PipelineKeyEqual,
                               Unk_StlAllocator<std::pair<const Unk_PipelineKey, Unk_PipelineStates*>>>
        Unk_PipelineStateMap;

    // begins drawing to the first render target if the targets changed
    // (inline in the functions that draw)
    void Unk_BeginTarget() {
        if (field_14d08) {
            if (field_14d09) {
                field_30->vf12();
                Unk_PixelContainer* container = field_14f00[0];
                field_30->vf30(container->field_a8, 0x10, 0x300);
            }
            Unk_SiGfxRenderTarget* target = field_14f00[0]->field_b8;
            void* resource = *target->vf10();
            field_30->vf30(resource, 0x300, 0x10);
            field_30->vf11(target, field_14d38);
            field_14d08 = false;
            field_14d09 = true;
            field_14dc0 = 0;
        }
    }

    // the resources made with the device (IGPUResource's constructor and
    // destructor keep the list)
    std::vector<IGPUResource*, Unk_StlAllocator<IGPUResource*>> field_10;
    u64 field_28;
    Unk_SiGfxDrawContext* field_30;
    Unk_SiGfxDevice* field_38;
    std::vector<void*, Unk_StlAllocator<void*>> field_40;
    bool field_58;  // the viewport's origin is the lower left
    bool field_59;  // the clip volume's near plane is at -1
    Unk_PipelineStateMap field_60;  // the pipeline states made so far
    u8 field_88[0x14c88 - 0x88];
    Unk_SiGfxInterface* field_14c88[16];  // SiGfx objects the device holds
    bool field_14d08;  // set when a target changes
    bool field_14d09;  // set while the draw context is between its begin and end
    s32 field_14d0c;
    // the viewport and its depth range
    Unk_ViewportF field_14d10;
    // the scissor rectangle: left, right, top, bottom
    s32 field_14d28;
    s32 field_14d2c;
    s32 field_14d30;
    s32 field_14d34;
    // what a target is cleared with: a colour for each of eight, the depth,
    // the stencil value and what to clear
    f32 field_14d38[8][4];
    f32 field_14db8;
    u32 field_14dbc;
    u32 field_14dc0;
    s32 field_14dc4;  // the blend state handed to the draw context
    void* field_14dc8;
    void* field_14dd0;
    void* field_14dd8;
    void* field_14de0;
    // what Unk_43fd20 keeps: two numbers and three arrays of the second's length
    u32 field_14de8;
    u32 field_14dec;
    u64 field_14df0[16];
    u32 field_14e70[16];
    u32 field_14eb0[16];
    u8 field_14ef0[0x14efa - 0x14ef0];
    bool field_14efa;
    u8 field_14efb[0x14f00 - 0x14efb];
    Unk_PixelContainer* field_14f00[8];  // the render targets
    IGPUInterface* field_14f40;          // the depth target
    IGPUInterface* field_14f48[16];      // the textures
    Unk_IndexBuffer* field_14fc8;  // the index buffer
    s32 field_14fd0;               // and its format
    u8 field_14fd4[0x14ff0 - 0x14fd4];
    IGPUInterface* field_14ff0;
    IGPUInterface* field_14ff8;
    s32 field_15000;
    bool field_15004;
    s32 field_15008;
    Unk_Float2 field_1500c;  // two floats set together
    s32 field_15014;  // the blend state that is applied (-1: none)
    s32 field_15018;  // the blend state: bits 0 to 2, 3 and 4, 5
    Unk_BlendColor field_1501c;
};
PKMN_OFFSET_ASSERT(IGPUDevice, field_14d08, 0x14d08);
PKMN_OFFSET_ASSERT(IGPUDevice, field_14d10, 0x14d10);
PKMN_OFFSET_ASSERT(IGPUDevice, field_14f00, 0x14f00);
PKMN_OFFSET_ASSERT(IGPUDevice, field_14ff0, 0x14ff0);
PKMN_OFFSET_ASSERT(IGPUDevice, field_14dc4, 0x14dc4);
PKMN_OFFSET_ASSERT(IGPUDevice, field_1501c, 0x1501c);
PKMN_OFFSET_ASSERT(IGPUDevice, field_14c88, 0x14c88);
PKMN_OFFSET_ASSERT(IGPUDevice, field_14dc8, 0x14dc8);
PKMN_OFFSET_ASSERT(IGPUDevice, field_15000, 0x15000);
PKMN_OFFSET_ASSERT(IGPUDevice, field_30, 0x30);
PKMN_OFFSET_ASSERT(IGPUDevice, field_38, 0x38);

}  // namespace PPFX
