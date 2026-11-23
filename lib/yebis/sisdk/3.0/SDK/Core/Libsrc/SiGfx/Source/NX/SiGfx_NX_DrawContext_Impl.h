// SiSDK3::SiGfxNXDrawContext: as far as the executable's functions show
// them, with placeholder members (RTTI names the classes). The reference
// counts are defined in this header (their __FILE__), at the original's lines,
// for the class's own translation unit (UNK_SIGFX_NX_DRAWCONTEXT_IMPL).
// (Unk_DeviceObjects.h has the class as the device's translation unit needs
// it: its constructor and the function that sets it up.)
#pragma once

#include <nx_middleware/gfx/nvn.h>
#include <string.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_Array.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_4bf660.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_Buffer_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_CommandList_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_DescriptorSet_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_DescriptorTable_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_MemoryHeap_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_RootSignature_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/SiGfx_FontDrawHelper.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/SiGfx_PrimitiveDrawHelper.h>

// 0x71004fb320 (leafgen's name and type: the device and an NVN command buffer)
struct Unk_4fb320;
void Unk_4fb320_update(const Unk_4fb320* self, u64 value);
// 0x7100544280 (leafgen's name and type: the font helper)
struct Unk_544280;
u64 Unk_544280_get(const Unk_544280* self);
// 0x710055ba30: what the draw context's member at 0x30 is reset with
// (placeholder name and type)
void Unk_55ba30(void* states);
// 0x710055bc90 (Unk_55bc90.cpp): resets the NVN states of a draw
struct Unk_55bc90_States;
void Unk_55bc90(Unk_55bc90_States* self);
// 0x71004c4cf0 (leafgen's name and type: a name, a buffer and its size)
void Unk_4c4cf0_update(u64, u64, u32);

namespace SiSDK3 {

class SiGfxNXCommandQueue;

// SiGfx's kernel as the frames' buffers ask it for its allocator (placeholder
// name: slot 6).
class Unk_DrawContextKernel {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual ISiAllocator* vf6();
};
inline ISiAllocator* Unk_DrawContextKernelAllocator() {
    return reinterpret_cast<Unk_DrawContextKernel*>(Unk_4cbf40_get())->vf6();
}

// What the draw context keeps a reference of at 0x3e00, and what its
// buffers keep (placeholder name).
class Unk_53b550_Object {
public:
    virtual void vf0();
    virtual void vf1();
    virtual u32 vf2();
    virtual u32 vf3();
};

// The device as the draw context calls it (placeholder name): slot 56 is one
// of its fonts.
class Unk_NXDrawDevice {
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
    virtual SiGfxNXMemoryHeap* vf30(u32 kind, ISiAllocator* pAllocator);
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
    virtual Unk_53b550_Object* vf52(const Unk_546c60_Desc* desc, void* a2, u32 a3, void* a4);  // a sampler
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void* vf56(size_t index);
    virtual void vf57();
    virtual void vf58();
    virtual SiGfxNXBuffer* vf59(void* a1, u32 a2, void* a3);  // a buffer
    virtual void vf60();
    virtual void vf61();
    virtual void vf62();
    virtual void vf63();
    virtual void vf64();
    virtual void vf65();
    virtual void vf66();
    virtual void vf67();
    virtual void vf68();
    virtual void vf69();
    virtual void vf70();
    virtual void vf71();
    virtual void vf72();
    virtual void vf73();
    virtual void vf74();
    virtual void vf75();
    virtual void vf76();
    virtual void vf77();
    virtual void vf78();
    virtual void vf79();
    virtual void vf80();
    virtual void vf81();
    virtual void vf82();
    virtual void vf83();
    virtual void vf84();
    virtual void* vf85();  // the NVN device
    virtual void vf86();
    virtual void vf87();
    virtual void vf88();
    virtual void vf89();
    virtual void vf90();
    virtual SiGfxNXCommandQueue* vf91();  // its queue
    virtual SiGfxNXCommandList* vf92();   // a command list of its own
};

// The buffer of an indirect draw as the draw context calls it (placeholder
// name): slot 27 is its address.
class Unk_NXDrawIndirect {
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
    virtual u64 vf27();
    virtual s32 vf28();  // an index buffer's NVN index type
};

// What a resource's slots 18 to 20 return, as slot 30 reads it (placeholder
// name): bit 2 of field_74 is whether NVN has to be told of its memory.
struct Unk_NXDrawUsage {
    u32 field_0;  // (a texture's slot 19: its kind, 2: 2D, 4: cube, 5 and 6: their arrays)
    s32 field_4;  // (a buffer's slot 17: its size)
    s32 field_8;  // (a vertex buffer's slot 17: its stride)
    u8 field_c[8];
    s32 field_14;  // (a texture's slot 19, a surface's slot 17: the width and height)
    s32 field_18;
    u8 field_1c[0x58];
    u32 field_74;
    u8 field_78[0x3d8];
    void* field_450;  // its memory, mapped (slot 69)
};
PKMN_OFFSET_ASSERT(Unk_NXDrawUsage, field_450, 0x450);

class Unk_NXDrawSurface;

// A texture and a buffer as the draw context binds them (placeholder names:
// SiGfxNXTexture's and SiGfxNXBuffer's slots and members). A texture's slot
// 33 is its sampler, slot 43 its number in the device's texture pool,
// field_340 its NVN handle; a buffer's field_100 is its memory's address,
// field_bc the size of a copy and field_154 the copy in use, slot 29 the
// handle of its texture.
class Unk_NXDrawTexture : public ISiGfxResource {
public:
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15(u32 state);  // the state it is in now
    virtual u32 vf16();            // the states that need a barrier
    virtual const Unk_NXDrawUsage* vf17();
    virtual const Unk_NXDrawUsage* vf18();
    virtual const Unk_NXDrawUsage* vf19();
    virtual const Unk_NXDrawUsage* vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual u64 vf27();  // a buffer's address
    virtual void vf28();
    virtual u64 vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual Unk_NXRootSampler* vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void* vf40();  // a texture's NVN texture and view
    virtual void* vf41();
    virtual void vf42();
    virtual u32 vf43();

    u8 field_8[0xb4];
    s32 field_bc;      // (a buffer's)
    u8 field_c0[0x10];
    u64 field_d0[6];   // NVNbuffer
    u64 field_100;
    u8 field_108[0x4c];
    s32 field_154;
    u8 field_158[0xf0];
    u64 field_248;     // a texture's surfaces: how many
    u8 field_250[0x10];
    Unk_NXDrawSurface* field_260;  // and where
    u8 field_268[0xc0];
    void* field_328;   // NVNtexture
    u8 field_330[0x10];
    u64 field_340;
};
PKMN_OFFSET_ASSERT(Unk_NXDrawTexture, field_bc, 0xbc);
PKMN_OFFSET_ASSERT(Unk_NXDrawTexture, field_100, 0x100);
PKMN_OFFSET_ASSERT(Unk_NXDrawTexture, field_154, 0x154);
PKMN_OFFSET_ASSERT(Unk_NXDrawTexture, field_260, 0x260);
PKMN_OFFSET_ASSERT(Unk_NXDrawTexture, field_328, 0x328);
PKMN_OFFSET_ASSERT(Unk_NXDrawTexture, field_340, 0x340);

// A resource of kind 3 as slots 69 and 70 map and flush it (placeholder name,
// SiGfxNXSurface's members): its NVN texture, its row's bytes (field_110) and
// rows (field_90, field_ac in blocks when field_a4 says it is of blocks).
class Unk_NXDrawSurface : public ISiGfxResource {
public:
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual const Unk_NXDrawUsage* vf17();
    virtual const Unk_NXDrawUsage* vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void* vf25();  // its NVN texture and view
    virtual void* vf26();

    u8 field_8[0x88];
    s32 field_90;
    u8 field_94[0x10];
    bool field_a4;
    u8 field_a5[7];
    s32 field_ac;
    u8 field_b0[0x30];
    void* field_e0;  // NVNtexture
    u8 field_e8[0x28];
    u32 field_110;
};
PKMN_OFFSET_ASSERT(Unk_NXDrawSurface, field_ac, 0xac);
PKMN_OFFSET_ASSERT(Unk_NXDrawSurface, field_e0, 0xe0);
PKMN_OFFSET_ASSERT(Unk_NXDrawSurface, field_110, 0x110);

// What slots 69 and 70 are given with the resource (placeholder name): where
// and how much of it to map or flush (negative: all of it), and what slot 69
// gives back: the memory, a row's bytes and the bytes of all of them.
struct Unk_NXDrawFlush {
    u8 field_0[4];
    s32 field_4;
    s32 field_8;
    u8 field_c[0x14];
    void* field_20;
    u32 field_28;
    u32 field_2c;
};
PKMN_OFFSET_ASSERT(Unk_NXDrawFlush, field_20, 0x20);

// What a render target's slot 17 gives, as slot 11 reads it (placeholder
// name and members): its size and whether it has depth and stencil.
struct Unk_NXDrawTargetInfo {
    s32 field_0;  // the width
    s32 field_4;  // and height
    u8 field_8[0x10];
    u8 field_18;  // the depth's mask
    u8 field_19;  // whether it has stencil
};
// A render target as slot 11 binds it (placeholder name: SiGfxNXRenderTarget's
// slots): its colours and their views, its depth and its view (36 to 39) and
// how many colours (35).
class Unk_NXDrawRenderTarget {
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
    virtual const Unk_NXDrawTargetInfo* vf17();
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
    virtual const u32* vf35();
    virtual void* vf36();
    virtual void* vf37();
    virtual void* vf38();
    virtual void* vf39();
};
// What slot 11 is given (placeholder names and members): the canvas's pass
// with its render target, and what to clear it with.
struct Unk_NXDrawPass {
    u8 field_0[0x28];
    Unk_NXDrawRenderTarget* field_28;
};
struct Unk_NXDrawClear {
    f32 field_0[8][4];  // the colours
    f32 field_80;       // the depth
    s32 field_84;       // the stencil
    u32 field_88;       // what to clear (1: depth, 2: stencil, 0x10 and up: the colours)
};
PKMN_OFFSET_ASSERT(Unk_NXDrawClear, field_88, 0x88);

// A region of a copy (placeholder name and members, NVNcopyRegion's):
// where, and how large (one deep at first).
struct Unk_NXCopyRegion {
    Unk_NXCopyRegion() : field_0(0), field_4(0), field_8(0), field_c(0), field_10(0), field_14(1) {}

    s32 field_0;
    s32 field_4;
    s32 field_8;
    s32 field_c;  // the width
    s32 field_10;  // the height
    s32 field_14;  // the depth
};

// What the draw context's slot 94 binds (placeholder name): slot 19 is what
// it is bound as.
class Unk_5427a0_Object {
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
    virtual u32 vf19();
};

// What the draw context's slots 61, 62 and 64 are given (placeholder name
// and members): a query.
struct Unk_NXDrawQuery {
    u8 field_0[0x78];
    u32 field_78;  // its kind (1: the counter the two functions report)
    u32 field_7c;
    s32 field_80;  // its result's size
    u32 field_84;
    u64 field_88[6];  // NVNbuffer
    u64 field_b8;     // its address
    u8 field_c0[0x18];
    u8 field_d8[1];   // the result
};

// What the draw context's initialisation takes (placeholder name, as
// Unk_DeviceObjects.h has it): which helpers it sets up.
struct Unk_53b680_Desc {
    Unk_53b680_Desc() : field_0(true), field_1(true) {}

    bool field_0;  // the font helper
    bool field_1;  // the primitive helper
};

class SiGfxNXDevice;
class SiGfxNXPipelineState;

// A shader program as slot 16 binds it (placeholder name and members): its
// NVN program, its stages and the stages it is used in.
struct Unk_NXDrawProgram {
    u8 field_0[0xb8];
    u8 field_b8[0xc0];  // NVNprogram
    s32 field_178;      // its stages
    s32 field_17c;      // how many stages it is used in
    u32 field_180[6];   // which
};
PKMN_OFFSET_ASSERT(Unk_NXDrawProgram, field_178, 0x178);

// A vertex format as the context's own states set it (placeholder name and
// members): its attributes' formats, streams and offsets.
struct Unk_NXDrawVertexFormat {
    struct Attribute {
        u8 field_0[8];
        u32 field_8;   // the format
        u32 field_c;   // the stream
        s32 field_10;  // the offset
        u8 field_14[8];
    };

    u8 field_0[0x7c];
    Attribute field_7c[32];
    s32 field_3fc;  // how many
};
PKMN_OFFSET_ASSERT(Unk_NXDrawVertexFormat, field_3fc, 0x3fc);

// What SiGfxNXPipelineState's slot 10 gives (placeholder name and members:
// its description as slot 16 reads it): the program and the polygon offset.
struct Unk_NXDrawPipelineDesc {
    u8 field_0[8];
    Unk_NXDrawProgram* field_8;
    u8 field_10[8];
    f32 field_18;  // the polygon offset's factor, clamp and units
    f32 field_1c;
    f32 field_20;
    u8 field_24[8];
    u8 field_2c;  // whether depth is clamped
};
PKMN_OFFSET_ASSERT(Unk_NXDrawPipelineDesc, field_2c, 0x2c);

// 0x710053f630: whether two samplers' descriptions are the same
bool Unk_53f630(const SiGfxNXSampler::Unk_Desc* a, const SiGfxNXSampler::Unk_Desc* b);

class SiGfxNXDrawContext {
public:
    // The NVN states the context starts a draw with (placeholder name and
    // members): eight blend states and what goes with them.
    struct Unk_DrawStates {
        Unk_DrawStates() {
            for (int i = 0; i < 2; i++) {
                field_178[i] = 0;
            }
            Unk_53b3f0();
        }
        // 0x710053b3f0: gives the states their defaults
        void Unk_53b3f0();

        // A colour target's blending (placeholder name and members, as
        // SiGfxNXPipelineState's description has it).
        struct Unk_Blend {
            bool field_0;
            u32 field_4;
            u32 field_8;
            u32 field_c;
            u32 field_10;
            u32 field_14;
            u32 field_18;
            u8 field_1c[4];  // the channels written
        };

        Unk_NXDrawProgram* field_0;
        Unk_NXDrawVertexFormat* field_8;
        u32 field_10;  // the faces culled
        u32 field_14;  // the polygons' mode
        struct {
            u8 field_0[0xc];
            u32 field_c;  // the samples
        } field_18;
        bool field_28;
        u8 field_29[4];
        bool field_2d;
        u32 field_30;
        bool field_34;
        bool field_35;
        u8 field_36[2];
        u8 field_38;
        u8 field_39;
        u8 field_3a;
        u8 field_3b;
        u32 field_3c;
        u32 field_40;
        u32 field_44;
        u32 field_48;
        u32 field_4c;
        u32 field_50;
        u32 field_54;
        u32 field_58;
        bool field_5c;
        bool field_5d;
        Unk_Blend field_60[8];
        u32 field_160;
        u32 field_164;
        s32 field_168;
        u32 field_16c;
        u64 field_170;
        u64 field_178[2];
        // what changed (0x88: the polygon and multisample states, 0x40: the
        // blending, 0x10: the depth and stencil, 1: the program, 2: the
        // vertex format, 4: what is drawn)
        union {
            u32 field_188;
            struct {
                u32 field_188_0 : 16;
                u32 field_188_16 : 16;
            };
        };
        u8 field_18c[4];
        ISiGfxResource* field_190[64];  // the images (slot 92)
    };
    PKMN_OFFSET_ASSERT(Unk_DrawStates, field_60, 0x60);
    PKMN_OFFSET_ASSERT(Unk_DrawStates, field_160, 0x160);
    PKMN_OFFSET_ASSERT(Unk_DrawStates, field_178, 0x178);
    PKMN_SIZE_ASSERT(Unk_DrawStates, 0x390);

    // What the context keeps three of at 0x3f00 (placeholder name and
    // members): the direct buffers' memory of a kind (uniform, vertex and
    // index buffers) as it is mapped. The last one's array is longer: it
    // holds the blocks last handed out (Unk_Blocks), and its zeros are one
    // loop.
    template <int N>
    struct Unk_3f00 {
        Unk_3f00() : field_0(3), field_8(-1), field_10(0), field_18(0) {
            for (int i = 0; i < N; i++) {
                field_20[i] = 0;
            }
        }

        u64 field_0;
        s32 field_8;
        u64 field_10;
        u8 field_18;
        u8* field_20[N];  // field_20[0]: the memory, mapped
    };
    PKMN_SIZE_ASSERT(Unk_3f00<4>, 0x40);
    struct DirectBuffer;
    // A part of a direct buffer handed out (placeholder name).
    struct Unk_DirectBlock {
        DirectBuffer* field_0;
        s32 field_8;  // where in the buffer
        s32 field_c;  // how much
    };

    // A buffer of a frame (RTTI names the class; placeholder members): two
    // references.
    struct DirectBuffer {
        DirectBuffer() : field_0(nullptr), field_8(nullptr), field_10(0) {}
        ~DirectBuffer() {
            if (field_0 != nullptr) {
                field_0->vf3();
                field_0 = nullptr;
            }
            if (field_8 != nullptr) {
                field_8->vf3();
                field_8 = nullptr;
            }
        }

        SiGfxNXBuffer* field_0;
        SiGfxNXMemoryHeap* field_8;  // its memory
        s32 field_10;  // how much of it is used
    };
    // A frame's buffers (RTTI names the class; placeholder members): the
    // allocator that deletes them.
    struct FrameDirectBufferArray {
        FrameDirectBufferArray() : field_0(Unk_DrawContextKernelAllocator()), field_8(0) {}
        ~FrameDirectBufferArray() { Unk_566a00(field_0, &field_10, false); }

        ISiAllocator* field_0;
        s32 field_8;  // the buffer in use
        SiArray<DirectBuffer*, 16> field_10;
    };

    // A viewport and a scissor rectangle as slots 14 and 15 are given them,
    // and as they are kept (placeholder names).
    struct Unk_Viewport {
        f32 field_0;
        f32 field_4;
        f32 field_8;
        f32 field_c;
        f32 field_10;  // the depth range
        f32 field_14;
    };
    struct Unk_Scissor {
        s32 field_0;  // left and right
        s32 field_4;
        s32 field_8;  // top and bottom
        s32 field_c;
    };
    struct Unk_Rect {
        s32 field_0;
        s32 field_4;
        s32 field_8;
        s32 field_c;
    };
    // A color as slot 21 is given it (placeholder name).
    struct Unk_Color {
        f32 field_0;
        f32 field_4;
        f32 field_8;
        f32 field_c;
    };
    struct Unk_Range {
        f32 field_0;
        f32 field_4;
    };
    struct Unk_FRect {
        f32 field_0;
        f32 field_4;
        f32 field_8;
        f32 field_c;
    };
    // A vertex buffer as it is bound (placeholder name).
    struct Unk_VertexBuffer {
        u64 field_0;  // its address
        u64 field_8;  // its size
    };

    // The NVN states of a draw (placeholder name and members; 0x710055bc90
    // resets them as its own placeholder of the object).
    struct Unk_NXDrawState {
        s32 field_0;  // how many viewports
        s32 field_4;  // how many scissors
        s32 field_8;  // how many colour targets
        Unk_FRect field_c[16];    // the viewports' rectangles
        Unk_Range field_10c[16];  // and depth ranges
        Unk_Rect field_18c[16];   // the scissors (left, top, width, height)
        u32 field_28c;
        Unk_VertexBuffer field_290[16];  // the vertex buffers
        u64 field_390;     // the index buffer's address
        s32 field_398;     // the indices' NVN type
        s32 field_39c;     // and size
        s32 field_3a0;     // the NVN draw mode
        f32 field_3a4[4];  // the clear color, as it is applied
        u8 field_3b4[4];
        u64 field_3b8[8];    // NVNblendState
        u32 field_3f8;       // NVNpolygonState
        u8 field_3fc[4];
        u64 field_400;       // NVNdepthStencilState
        u8 field_408[0x18];  // NVNmultisampleState
        u32 field_420;       // NVNcolorState
        u32 field_424;       // NVNchannelMaskState
        s32 field_428;       // how many vertex attributes there are
        u32 field_42c[32];   // NVNvertexAttribState
        s32 field_4ac;       // how many vertex buffers there are
        u64 field_4b0[16];   // NVNvertexStreamState
        f32 field_530;       // the polygon offset (units, factor, clamp)
        f32 field_534;
        f32 field_538;
        u8 field_53c;        // whether depth is clamped
        void* field_540;     // the NVN program
        s32 field_548;       // its stages
        void* field_550;     // the render targets: colors, their views, depth and its view
        void* field_558;
        void* field_560;
        void* field_568;
        u64 field_570[6][14];  // the uniform buffers' addresses, by stage
        s32 field_810[6][14];  // and sizes
        u64 field_960[6][14];  // the storage buffers' addresses
        s32 field_c00[6][14];  // and sizes
        u32 field_d50[64];     // the textures' numbers in the pool (slots 23 and 92)
        u32 field_e50[64];     // what each slot has bound (slots 17 and 94)
        u32 field_f50[64];     // the textures' samplers' slots
        u64 field_1050[6][64];  // the textures' handles, by stage
        u32 field_1c50[6][64];  // values by kind (slot 95)
        u32 field_2250[2];  // the barriers a draw needs first (slot 30)
    };
    PKMN_OFFSET_ASSERT(Unk_NXDrawState, field_290, 0x290);
    PKMN_OFFSET_ASSERT(Unk_NXDrawState, field_3b8, 0x3b8);
    PKMN_OFFSET_ASSERT(Unk_NXDrawState, field_428, 0x428);
    PKMN_OFFSET_ASSERT(Unk_NXDrawState, field_4b0, 0x4b0);
    PKMN_OFFSET_ASSERT(Unk_NXDrawState, field_540, 0x540);
    PKMN_OFFSET_ASSERT(Unk_NXDrawState, field_550, 0x550);
    PKMN_OFFSET_ASSERT(Unk_NXDrawState, field_570, 0x570);
    PKMN_OFFSET_ASSERT(Unk_NXDrawState, field_e50, 0xe50);
    PKMN_OFFSET_ASSERT(Unk_NXDrawState, field_1c50, 0x1c50);
    PKMN_SIZE_ASSERT(Unk_NXDrawState, 0x2258);

    // What a draw binds (placeholder name and members): the states before
    // the NVN ones, which the states' constructor and reset zero.
    struct Unk_DrawBindings {
            SiGfxNXPipelineState* field_0;  // the pipeline bound (slot 16)
            SiGfxNXRootSignature* field_8;  // the root signature bound (field_20 of the context 1)
            SiGfxNXRootSignature* field_10;  // (field_20 of the context 2)
            Unk_NXDrawPass* field_18;          // the pass bound (slot 11)
            Unk_NXDrawRenderTarget* field_20;  // and its render target
            s32 field_28;
            Unk_Viewport field_2c[16];
            s32 field_1ac;
            Unk_Scissor field_1b0[16];
            ISiGfxResource* field_2b0[16];  // the vertex buffers (slot 74 clears them)
            u32 field_330[16];  // their strides
            u32 field_370[16];
            Unk_NXDrawIndirect* field_3b0;  // the index buffer
            u32 field_3b8;
            u32 field_3bc;  // what is drawn (1: points, 2 and 3: lines, 4 and 5: triangles)
            u32 field_3c0;
            Unk_Color field_3c4;  // the clear color
            u8 field_3d4[4];
            SiGfxNXDescriptorSet* field_3d8;  // the descriptor set bound (slot 23)
            u64 field_3e0;                    // how many times it had changed then
            u64 field_3e8[32];  // what its tables' slot 31 said then
    };
    PKMN_OFFSET_ASSERT(Unk_DrawBindings, field_3b0, 0x3b0);
    PKMN_SIZE_ASSERT(Unk_DrawBindings, 0x4e8);

    // What Unk_States starts with (placeholder name): its viewports,
    // scissors, index buffer and NVN states (0x508 to 0x2760 are what
    // 0x710055bc90 resets). Its constructor is inline in Unk_States's.
    class Unk_StatesBase {
    public:
        Unk_StatesBase() : field_0(0), field_4(0) {
            // everything before the NVN states
            memset(&field_20, 0, sizeof(field_20));
            Unk_55bc90(reinterpret_cast<Unk_55bc90_States*>(&field_508));
        }

        u32 field_0;  // what changed (2: the viewports, 4: the scissors)
        s32 field_4;  // how many stages are used
        u32 field_8[6];  // which
        Unk_DrawBindings field_20;
        Unk_NXDrawState field_508;  // what 0x710055bc90 resets
    };
    PKMN_SIZE_ASSERT(Unk_StatesBase, 0x2760);

    // The range of slots of a kind that changed (placeholder name and
    // members): how many there are, the lowest and the highest changed and
    // a bit for each.
    struct Unk_SlotRange {
        Unk_SlotRange(u32 count = 0) : field_0(count), field_4(count + 1), field_8(-1), field_10(0) {}

        // forgets what changed (inline: placeholder name)
        void Unk_Reset() {
            field_4 = field_0 + 1;
            field_8 = -1;
            field_10 = 0;
        }
        // marks a slot changed: three inline functions that do it in other
        // orders (placeholder names), as their callers show
        void Unk_Mark(s32 slot) {
            field_4 = field_4 > slot ? slot : field_4;
            field_8 = field_8 < slot ? slot : field_8;
            field_10 |= static_cast<u64>(1) << slot;
        }
        void Unk_MarkOr(s32 slot) {
            field_4 = field_4 > slot ? slot : field_4;
            field_8 = field_8 < slot ? slot : field_8;
            field_10 = field_10 | static_cast<u64>(1) << slot;
        }
        void Unk_MarkBit(s32 slot) {
            field_10 |= static_cast<u64>(1) << slot;
            field_4 = field_4 > slot ? slot : field_4;
            field_8 = field_8 < slot ? slot : field_8;
        }
        void Unk_MarkBit2(s32 slot) {
            u64 changed = field_10;
            s32 lowest = field_4;
            field_10 = changed | static_cast<u64>(1) << slot;
            field_4 = lowest > slot ? slot : lowest;
            field_8 = field_8 < slot ? slot : field_8;
        }
        void Unk_MarkBit3(s32 slot) {
            u64 changed = field_10;
            s32 lowest = field_4;
            s32 highest = field_8;
            field_10 = changed | static_cast<u64>(1) << slot;
            field_4 = lowest > slot ? slot : lowest;
            field_8 = highest < slot ? slot : highest;
        }
        // marks the slots from first to last changed (inline: placeholder
        // name; the original's mask leaves the last one out)
        void Unk_MarkRange(s32 first, s32 last) {
            field_4 = field_4 > first ? first : field_4;
            field_8 = field_8 < last ? last : field_8;
            field_10 |= ~((~static_cast<u64>(0) >> (64 - first)) | (~static_cast<u64>(0) << last));
        }
        void Unk_MarkRead(s32 slot) {
            s32 lowest = field_4;
            s32 highest = field_8;
            u64 changed = field_10;
            field_4 = lowest > slot ? slot : lowest;
            field_8 = highest < slot ? slot : highest;
            field_10 = changed | static_cast<u64>(1) << slot;
        }

        u32 field_0;
        s32 field_4;
        s32 field_8;
        u64 field_10;
    };
    PKMN_SIZE_ASSERT(Unk_SlotRange, 0x18);

    // What the draw context draws with (placeholder name). Its destructor is
    // 0x710055ba20, in another translation unit (where 0x710055b740
    // constructs it and 0x710055ba30 resets it).
    class Unk_States : public Unk_StatesBase {
    public:
        Unk_States();  // 0x710055b740
        ~Unk_States();

        Unk_SlotRange field_2760;
        Unk_SlotRange field_2778[6];
        Unk_SlotRange field_2808[6];
        Unk_SlotRange field_2898[6];
        Unk_SlotRange field_2928[6];
        Unk_SlotRange field_29b8;  // the slots of slots 17 and 94
        u32 field_29d0[14];  // the uniform buffers' stages (slot 91)
        u32 field_2a08[64];  // the images' stages (slot 92)
        u8 field_2b08[0x38];
        u32 field_2b40[64];  // what goes with each slot's binding

        // marks a slot changed (inline: placeholder name)
        void Unk_MarkSlot(s32 slot) {
            s32 lowest = field_29b8.field_4;
            s32 highest = field_29b8.field_8;
            u64 changed = field_29b8.field_10;
            field_29b8.field_4 = lowest > slot ? slot : lowest;
            field_29b8.field_8 = highest < slot ? slot : highest;
            field_29b8.field_10 = changed | static_cast<u64>(1) << slot;
        }
    };
    PKMN_SIZE_ASSERT(Unk_States, 0x2c40);

    SiGfxNXDrawContext(ISiAllocator* pAllocator, SiGfxNXDevice* pDevice);  // 0x710053b200
    virtual ~SiGfxNXDrawContext();  // 0x710053b550, 0x710053b650
    UNK_REFCOUNT_DECLARE;

    // 0x710053b680: sets the context up (field_20 is a1)
    bool Unk_53b680(u32 a1, const Unk_53b680_Desc* desc);
    // 0x710053b750: gives the frames' buffers the context's allocator
    bool Unk_53b750();
    // 0x710053ba70: deletes the frames' buffers
    void Unk_53ba70();
    // 0x710053c340: applies what changed to the command buffer
    void Unk_53c340();
    // 0x710053f7d0: applies the context's own states (field_3a70)
    void Unk_53f7d0();
    // Counts a draw's primitives in the command list (inline in the draw
    // slots: placeholder name).
    void Unk_CountPrimitives(SiGfxNXCommandList* pList, s32 count, s32 instances) {
        switch (field_30.field_20.field_3bc) {
        case 1:
            pList->field_124.field_0[7] += instances * count;
            break;
        case 2:
            pList->field_124.field_0[7] += instances * (count / 2);
            break;
        case 3:
            pList->field_124.field_0[7] += instances * (count + 1);
            break;
        case 4:
            pList->field_124.field_0[5] += instances * (count / 3);
            break;
        case 5:
            pList->field_124.field_0[5] += instances * (count + 2);
            break;
        }
    }
    bool vf8(SiGfxNXCommandList* pCommandList);   // 0x710053bb80: begins recording into a command list
    void vf11(Unk_NXDrawPass* pPass, const Unk_NXDrawClear* pClear);  // 0x710053be40: begins a pass
    bool vf9();                                    // 0x710053bda0: ends the recording
    void vf12();                                   // 0x710053c9c0
    void vf14(s32 count, const Unk_Viewport* viewports);  // 0x710053c9f0
    void vf15(s32 count, const Unk_Scissor* scissors);    // 0x710053ca70
    void vf16(SiGfxNXPipelineState* pState);       // 0x710053cae0: binds a pipeline's states
    void vf17(SiGfxNXRootSignature* pSignature);   // 0x710053ce30: binds a root signature's samplers
    // binds a texture of the program bound (inline in slot 17: placeholder
    // name)
    void Unk_BindTexture(s32 index, Unk_NXRootSampler* pSampler) {
        SiGfxNXRootSignature* pSignature;
        if (field_20 == 1) {
            pSignature = field_30.field_20.field_8;
        } else if (field_20 == 2) {
            pSignature = field_30.field_20.field_10;
        } else {
            return;
        }
        if (pSignature == nullptr || index >= static_cast<s32>(pSignature->field_78.m_itemCount)) {
            return;
        }
        s32 slot = pSignature->field_78.m_pData[index].field_4;
        if (static_cast<u32>(slot) >= 64) {
            return;
        }
        u32 value = pSignature->field_c8[slot].field_0;
        if (pSampler == nullptr) {
            return;
        }
        u32 current = field_30.field_508.field_e50[slot];
        u32 bound = pSampler->field_120;
        if (current == bound) {
            return;
        }
        field_30.field_508.field_e50[slot] = bound;
        field_30.field_29b8.Unk_Mark(slot);
        field_30.field_2b40[slot] = value;
    }
    // 0x710053cfc0: binds vertex buffers (their strides are the buffers' own
    // if none are given)
    void vf19(s32 first, s32 count, ISiGfxResource** ppBuffers, const s32* strides, const s32* offsets);
    void vf20(Unk_NXDrawIndirect* pBuffer, s32 offset);  // 0x710053d490: the index buffer
    void vf21(const Unk_Color* color);             // 0x710053d5c0: the clear color
    void vf23(SiGfxNXDescriptorSet* pSet);         // 0x710053d660: binds a descriptor set's parameters
    // 0x710053d8a0, 0x710053da20, 0x710053e0c0, 0x710053ee60: a parameter of
    // each kind (a uniform buffer, ...)
    void Unk_53d8a0(s32 index, ISiGfxResource* pResource, s32 offset, s32 size);
    void Unk_53da20(s32 index, ISiGfxResource* pResource);
    void Unk_53e0c0(s32 index, SiGfxNXDescriptorTable* pTable);
    void Unk_53ee60(ISiGfxResource* pResource, u32 stages, s32 slot);
    // 0x710053ed20: the samplers of the set's textures
    void Unk_53ed20(SiGfxNXDescriptorSet* pSet);
    // 0x710053f2f0: the samplers of a table's textures
    void Unk_53f2f0(s32 index, SiGfxNXDescriptorTable* pTable);
    // 0x710053f490: the slot of a texture's sampler (-1 - the signature's
    // sampler that is like it, -1 for none)
    s32 Unk_53f490(Unk_NXDrawTexture* pTexture, SiGfxNXRootSignature* pSignature);
    // 0x710053fe70: the handles of the textures whose number or sampler
    // changed (placeholder name)
    void Unk_53fe70(const void* device, Unk_SlotRange* textures, Unk_SlotRange* samplers, u64* handles,
                    Unk_SlotRange* changed);
    bool vf24(s32 count, s32 first, s32 instances, s32 baseInstance);  // 0x7100540080
    bool vf25(s32 count, s32 first, s32 baseVertex, s32 instances, s32 baseInstance);  // 0x71005401c0
    u32 vf26(Unk_NXDrawIndirect* pBuffer);         // 0x7100540320
    u32 vf28(s32 x, s32 y, s32 z);                 // 0x71005403c0
    bool vf30(ISiGfxResource* pResource, u32 from, u32 to);  // 0x7100540440: a resource's state changes
    void vf31(const char* description);            // 0x71005405c0
    void vf34();                                   // 0x7100540750
    bool vf35(u32 mode);
    bool vf36();
    bool vf37();
    bool vf38(s32 count, const u8* pVertices);
    bool vf39(const void* pVertex);
    bool vf40(u32 row, s32 column, f32 x, f32 y, f32 z, f32 w);
    bool vf41(u32 row, s32 column, const f32* pValues);
    bool vf42(u32 row, s32 column, const f32* pValues);
    bool vf43(u32 row, s32 column, const f32* pValues);
    bool vf44(u32 row, s32 column, u8 r, u8 g, u8 b, u8 a);
    bool vf45(u32 row, s32 column, const u8* pValues);
    bool vf46(u32 row, s32 column, const u8* pValues);
    bool vf47(u32 row, s32 column, const f32* pValues);
    bool vf48(u32 row, s32 column, const u8* pValues);
    bool vf49(u32 row, s32 column, const f32* pValues);
    void vf50(u32 index);                          // 0x7100540760
    void vf51(void* font);                         // 0x71005407a0
    void vf52();
    bool vf53(const char* text, SiGfxFontDrawHelper::Unk_Vec2* pSize, u32 flags, f32 scale);
    void vf54();
    bool vf55(const char* text, const SiGfxFontDrawHelper::Unk_Vec4* pRect, u32 flags, const Unk_TextColor* pColor,
              f32 scale);
    bool vf56(const char* text, const SiGfxFontDrawHelper::Unk_Vec4* pRect, u32 flags, const Unk_TextColor* pColor,
              const Unk_TextColor* pOutlineColor, f32 scale, u32 outline);
    bool vf57();
    bool vf58(Unk_PrimitiveTexture* pTexture, const Unk_PrimitiveTextureDesc* desc, const Unk_PrimitiveRect* dest,
              const Unk_PrimitiveRect* source);
    bool vf59(Unk_PrimitiveTexture* pPlane0, Unk_PrimitiveTexture* pPlane1, Unk_PrimitiveTexture* pPlane2,
              Unk_PrimitiveTexture* pPlane3, const Unk_PrimitiveTextureDesc* desc, const Unk_PrimitiveRect* dest,
              const Unk_PrimitiveRect* source);
    bool vf61(Unk_NXDrawQuery* query);             // 0x7100540840
    bool vf62(Unk_NXDrawQuery* query);             // 0x7100540890
    bool vf64(Unk_NXDrawQuery* query);             // 0x71005408e0
    // 0x7100541e60: unbinds the textures of the stages given
    void vf78(u32 stages, s32 first, s32 count);
    // what slot 78 does for a stage (inline: placeholder name)
    void Unk_UnbindTextures(void* commandBuffer, s32 stage, s32 first, s32 count);
    void vf83(bool more);                          // 0x7100542260
    // 0x7100542300: a uniform buffer for the stages given (the copy's
    // offset, and its size if it isn't the buffer's)
    void vf91(u32 a1, u32 stages, s32 slot, ISiGfxResource* pResource, s32 offset, s32 size);
    // 0x7100542570: an image for the stages given
    void vf92(u32 a1, u32 stages, s32 slot, ISiGfxResource* pResource);
    bool vf69(ISiGfxResource* pResource, Unk_NXDrawFlush* pMap);  // 0x7100540990: maps a resource's memory
    bool vf70(ISiGfxResource* pResource, const Unk_NXDrawFlush* pFlush);  // 0x7100540c70: tells NVN of its memory
    bool vf71(ISiGfxResource* pDst, ISiGfxResource* pSrc);  // 0x7100540e00: copies one resource into another
    void vf94(u32 a1, u32 value, s32 slot, Unk_5427a0_Object* pObject);  // 0x71005427a0
    // 0x7100541210: a frame's direct buffer of a kind (0: uniform, 1: vertex,
    // 2: index buffers) with room for size bytes, made if there is none; its
    // memory is mapped into pMemory
    DirectBuffer* Unk_541210(u32 kind, s32 a2, s32 size, u32 format, Unk_3f00<4>* pMemory);
    // 0x71005416f0, 0x71005419f0, 0x7100541c80: memory for a uniform buffer,
    // a vertex buffer and an index buffer of this frame, bound
    u8* vf72(u32 a1, u32 stages, s32 slot, s32 size);
    u8* vf74(s32 slot, s32 count, s32 stride);
    u8* vf76(u32 format, s32 count);
    void vf95(u32 kind, s32 index, s32 count, const u32* values);  // 0x7100542840
    void vf98(SiGfxNXCommandList* pCommandList);  // 0x7100541db0
    void vf99(const void* pool);                   // 0x7100541e00
    void vf100(const void* pool);                  // 0x7100541e20
    void vf101();                                  // 0x7100541e40

    Unk_4bf660 field_8;
    Unk_NXDrawDevice* field_18;
    u32 field_20;
    u32 field_24;
    SiGfxNXCommandList* field_28;
    Unk_States field_30;
    SiGfxPrimitiveDrawHelper field_2c70;  // its helpers, whose functions its
    SiGfxFontDrawHelper field_3780;       // slots pass their arguments on to
    void* field_3a60;  // the command list's NVN command buffer
    s32 field_3a68;
    Unk_DrawStates field_3a70;
    Unk_53b550_Object* field_3e00;
    s32 field_3e08;  // how many frames
    s32 field_3e0c;  // the current frame
    SiArray<FrameDirectBufferArray, 16> field_3e10[3];  // the frames' buffers
    Unk_3f00<4> field_3f00[2];
    Unk_3f00<10> field_3f80;

    // the block of each kind last handed out (inline: placeholder name)
    Unk_DirectBlock* Unk_Blocks() { return reinterpret_cast<Unk_DirectBlock*>(&field_3f80.field_20[4]); }
};
PKMN_OFFSET_ASSERT(SiGfxNXDrawContext, field_30, 0x30);
PKMN_OFFSET_ASSERT(SiGfxNXDrawContext, field_2c70, 0x2c70);
PKMN_OFFSET_ASSERT(SiGfxNXDrawContext, field_3780, 0x3780);
PKMN_OFFSET_ASSERT(SiGfxNXDrawContext, field_3a60, 0x3a60);
PKMN_OFFSET_ASSERT(SiGfxNXDrawContext, field_3e10, 0x3e10);
PKMN_SIZE_ASSERT(SiGfxNXDrawContext, 0x3ff0);

}  // namespace SiSDK3

#ifdef UNK_SIGFX_NX_DRAWCONTEXT_IMPL
// 0x7100542880 (vf2), 0x71005428a0 (vf3)
#line 39
UNK_REFCOUNT_DEFINE(SiSDK3::SiGfxNXDrawContext, field_8.m_pAllocator, field_8.m_count)
#endif
