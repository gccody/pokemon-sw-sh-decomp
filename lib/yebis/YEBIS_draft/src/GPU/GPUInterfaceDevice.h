// PPFX::IGPUDevice (RTTI names the class; members are placeholders), as far
// as the functions written so far read it.
#pragma once

#include <string.h>

#include <unordered_map>
#include <vector>

#include <yebis/YEBIS_draft/include/PPFX/ppfxTypes.h>
#include <yebis/YEBIS_draft/src/GPU/GPUMemoryAllocator.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_Array.h>
#include <yebis/YEBIS_draft/src/GPU/GPUInterface.h>
#include <yebis/YEBIS_draft/src/GPU/Unk_SiGfx.h>

namespace PPFX {

struct Unk_SiGfxTextureCreateDesc;

// one element of a vertex layout: what it is (0 position, 2 texture
// coordinate), its index and its format
struct Unk_InputElement {
    Unk_InputElement() {}
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

// ISiGfxPipelineState (SiSDK3::SiGfxNXPipelineState's interface): slot 10
// gives its description, which slot 9 makes the NVN states of
struct Unk_SiGfxPipelineState : Unk_SiGfxInterface {
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual u32 vf8();
    virtual bool vf9();
    virtual void* vf10();
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
    u32 field_0;  // the kind (1, 3 and 5 are attached differently)
    u8 pad_4[0x4];
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
    virtual bool vf22(const Unk_SiGfxTextureCreateDesc* desc);  // "ISiGfxTexture::Create()"
    virtual void vf23();
    virtual void vf24();
    virtual void* vf25(u32 index);
    virtual void* vf26(u32 layer, u32 level);  // a level's surface in a layer
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

// what vf6 keeps in Unk_24e1500 (the TU's initialiser leaves field_18 as it
// is)
struct Unk_DeviceSettings {
    Unk_DeviceSettings() : field_0(0), field_4(0), field_8(0), field_10(0), field_20(-1), field_24(-1), field_28(0) {}

    u32 field_0;  // the back buffer's width (0: the viewport's)
    u32 field_4;  // and height
    u64 field_8;
    u32 field_10;  // the number of frame slots
    u64 field_18;
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

// SiGfx's description of a pipeline state as the device keeps one for each
// blend state (0x530 bytes, placeholder names; SiGfx's own view of it is
// SiGfxNXPipelineState::Unk_Desc). The parts the blend states are copied to
// from constants are plain structs.
struct Unk_PipelineDesc {
    // the rasterizer: the faces culled, the polygon mode, the samples, the
    // front face and multisampling
    struct Unk_Raster {
        u32 field_0;
        u32 field_4;
        u32 field_8;
        u32 field_c;
        u32 field_10;
        u32 field_14;
        bool field_18;
        bool field_19;
        bool field_1a;
        bool field_1b;
        bool field_1c;
        bool field_1d;
        u8 pad_1e[2];
    };
    // the depth function, test and writes
    struct Unk_Depth {
        u32 field_0;
        bool field_4;
        bool field_5;
        u8 pad_6[2];
    };
    // the stencil test, its masks and the two faces' operations
    struct Unk_Stencil {
        bool field_0;
        u8 field_1;
        u8 field_2;
        u8 field_3;
        u32 field_4;
        u32 field_8;
        u32 field_c;
        u32 field_10;
        u32 field_14;
        u32 field_18;
        u32 field_1c;
        u32 field_20;
    };
    struct Unk_5c {
        bool field_0;
        bool field_1;
    };
    // a colour target's blending: enabled, the colour's factors and
    // operation, the alpha's, and the channels written
    struct Unk_Blend {
        bool field_0;
        u32 field_4;
        u32 field_8;
        u32 field_c;
        u32 field_10;
        u32 field_14;
        u32 field_18;
        u8 field_1c[4];
    };
    struct Unk_VertexElement {
        bool operator==(const Unk_VertexElement& other) const {
            return field_0 == other.field_0 && field_4 == other.field_4 && field_8 == other.field_8 &&
                   field_c == other.field_c && field_10 == other.field_10 && field_14 == other.field_14 &&
                   field_18 == other.field_18;
        }

        u32 field_0;
        s32 field_4;
        u32 field_8;
        s32 field_c;
        s32 field_10;
        u32 field_14;
        u32 field_18;
    };
    // the vertex attributes: what SetupSiGfxDrawContext copies from the
    // vertex format the effect set
    struct Unk_VertexLayout {
        Unk_VertexElement field_0[32];
        s32 field_380;  // how many there are
    };
    // what SetupSiGfxDrawContext copies from the first render target's
    // resource
    struct Unk_4ec {
        s32 field_0;  // how many of field_4 there are
        s32 field_4[9];
    };

    inline Unk_PipelineDesc() {
        memset(this, 0, sizeof(*this));
        field_10.field_0 = 3;
        field_10.field_4 = 3;
        field_10.field_8 = 0;
        field_10.field_c = 0;
        field_10.field_10 = 0;
        field_10.field_14 = 0;
        field_10.field_18 = false;
        field_10.field_19 = false;
        field_10.field_1a = false;
        field_10.field_1b = false;
        field_10.field_1c = false;
        field_10.field_1d = false;
        field_30.field_0 = 2;
        field_30.field_4 = false;
        field_30.field_5 = true;
        field_38.field_0 = false;
        field_38.field_1 = 0xff;
        field_38.field_2 = 0xff;
        field_38.field_3 = 0;
        field_38.field_4 = 1;
        field_38.field_8 = 1;
        field_38.field_c = 1;
        field_38.field_10 = 8;
        field_38.field_14 = 1;
        field_38.field_18 = 1;
        field_38.field_1c = 1;
        field_38.field_20 = 8;
        field_5c.field_0 = false;
        field_5c.field_1 = false;
        for (s32 i = 0; i < 8; i++) {
            field_60[i].field_0 = false;
            field_60[i].field_c = 1;
            field_60[i].field_4 = 2;
            field_60[i].field_8 = 1;
            field_60[i].field_18 = 1;
            field_60[i].field_10 = 2;
            field_60[i].field_14 = 1;
            field_60[i].field_1c[0] = 1;
            field_60[i].field_1c[1] = 1;
            field_60[i].field_1c[2] = 1;
            field_60[i].field_1c[3] = 1;
        }
        field_514 = 0;
        field_518 = 0;
        field_51c = -1;
        field_52c = false;
    }

    void* field_0;  // the shaders (SetupSiGfxDrawContext)
    void* field_8;
    Unk_Raster field_10;
    Unk_Depth field_30;
    Unk_Stencil field_38;
    Unk_5c field_5c;
    Unk_Blend field_60[8];
    u32 field_160;  // what is drawn
    u8 field_164[4];
    Unk_VertexLayout field_168;
    Unk_4ec field_4ec;
    u32 field_514;
    u32 field_518;
    s32 field_51c;
    void* field_520;  // the render target
    u8 field_528[4];
    bool field_52c;
    u8 field_52d[3];
};
PKMN_OFFSET_ASSERT(Unk_PipelineDesc, field_30, 0x30);
PKMN_OFFSET_ASSERT(Unk_PipelineDesc, field_5c, 0x5c);
PKMN_OFFSET_ASSERT(Unk_PipelineDesc, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_PipelineDesc, field_168, 0x168);
PKMN_OFFSET_ASSERT(Unk_PipelineDesc, field_4ec, 0x4ec);
PKMN_OFFSET_ASSERT(Unk_PipelineDesc, field_520, 0x520);
PKMN_SIZE_ASSERT(Unk_PipelineDesc, 0x530);

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
    virtual u32 vf30(s32 arg);
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

    // what the states are kept by (0x120 bytes; placeholder names)
    struct Unk_PipelineKey {
        typedef Unk_PipelineDesc::Unk_VertexElement Unk_Element;

        Unk_PipelineKey() : field_0(0), field_8(0) {}

        bool operator==(const Unk_PipelineKey& other) const;  // 0x710043e640

        u64 field_0;  // the hash, which is all the table compares
        void* field_8;  // the shaders
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
    // RTTI: SiSDK3::SiArray<PPFX::IGPUDevice::PipelineStateData, 16>. A
    // pipeline state SiGfx made and what it was made for.
    struct PipelineStateData {
        Unk_PipelineKey field_0;
        Unk_SiGfxInterface* field_120;
    };
    typedef SiSDK3::SiArray<PipelineStateData, 16> Unk_PipelineStates;
    struct Unk_PipelineKeyHash {
        size_t operator()(const Unk_PipelineKey& key) const { return key.field_0; }
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
    s32 field_28;  // the number of frame slots (Unk_DeviceSettings::field_10)
    u32 field_2c;
    Unk_SiGfxDrawContext* field_30;
    Unk_SiGfxDevice* field_38;
    std::vector<void*, Unk_StlAllocator<void*>> field_40;
    bool field_58;  // the viewport's origin is the lower left
    bool field_59;  // the clip volume's near plane is at -1
    Unk_PipelineStateMap field_60;  // the pipeline states made so far
    Unk_PipelineDesc field_88[64];  // one for each blend state
    Unk_SiGfxInterface* field_14c88[16];  // SiGfx objects the device holds
    bool field_14d08;  // set when a target changes
    bool field_14d09;  // set while the draw context is between its begin and end
    u8 field_14d0a[2];
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
    // flags Unk_43fdd0 sets (the last three from the number of frame slots)
    bool field_14ef0;
    bool field_14ef1;
    bool field_14ef2;
    bool field_14ef3;
    bool field_14ef4;
    bool field_14ef5;
    bool field_14ef6;
    bool field_14ef7;
    bool field_14ef8;
    bool field_14ef9;
    bool field_14efa;
    bool field_14efb;
    u8 field_14efc[0x14f00 - 0x14efc];
    Unk_PixelContainer* field_14f00[8];  // the render targets
    IGPUInterface* field_14f40;          // the depth target
    IGPUInterface* field_14f48[16];      // the textures
    Unk_IndexBuffer* field_14fc8;  // the index buffer
    s32 field_14fd0;               // and its format
    Unk_Viewport field_14fd4;      // the back buffer's viewport
    u8 field_14fec[0x14ff0 - 0x14fec];
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
