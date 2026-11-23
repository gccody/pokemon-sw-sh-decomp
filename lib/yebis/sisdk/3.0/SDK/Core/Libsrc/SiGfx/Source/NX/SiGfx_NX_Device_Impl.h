// SiSDK3::SiGfxNXDevice (RTTI: SiGfxNXDevice : ISiGfxNXDevice : ISiGfxDevice :
// ISiInterface; written as one class), as far as the executable's functions
// show it, with placeholder members. The reference counts are defined in this
// header (their __FILE__), at the original's lines, for the class's own
// translation unit (UNK_SIGFX_NX_DEVICE_IMPL).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_Array.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_4bf660.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiOS/Source/Unk_596410.h>

namespace SiSDK3 {

class SiGfxNXManager;

class SiGfxNXBufferPool;
class SiGfxNXCanvasPool;
class SiGfxNXFontPool;
class SiGfxNXQueryPool;
class SiGfxNXRenderTargetPool;
class SiGfxNXSamplerPool;
class SiGfxNXShaderPool;
class SiGfxNXShaderProgramPool;
class SiGfxNXSurfacePool;
class SiGfxNXTexturePool;
class SiGfxNXVertexFormatPool;
class SiGfxNXVolumePool;

// What the device makes (RTTI names the classes and the interfaces they
// implement; their headers are their own translation units').
class ISiGfxBuffer;
class ISiGfxCanvas;
class ISiGfxCommandCache;
class ISiGfxCommandList;
class ISiGfxCommandListPool;
class ISiGfxDescriptorSet;
class ISiGfxDescriptorTable;
class ISiGfxDrawContext;
class ISiGfxFont;
class ISiGfxMemoryHeap;
class ISiGfxPipelineState;
class ISiGfxQuery;
class ISiGfxRenderPassState;
class ISiGfxRenderTarget;
class ISiGfxResource;
class ISiGfxRootSignature;
class ISiGfxSampler;
class ISiGfxShader;
class ISiGfxShaderProgram;
class ISiGfxSurface;
class ISiGfxTexture;
class ISiGfxVertexFormat;
class SiGfxNXCanvas;
class SiGfxNXCommandList;
class SiGfxNXCommandQueue;
class SiGfxNXDeviceInfo;
class SiGfxNXFreeTypeManager;
class SiGfxNXMemoryHeap;
class SiGfxNXRootSignature;
class SiGfxResourcePool;
class Unk_5518d0_Pool;
class Unk_5520b0_Pool;

// A canvas's description (placeholder name, after the device's slot 13 that
// gives the one of an index): 0x48 bytes, a size of 1024 by 768 by default.
struct Unk_4f96e0_Desc {
    Unk_4f96e0_Desc()
        : field_0(0), field_4(0), field_8(0), field_c(0), field_10(0), field_14(0x400), field_18(0x300), field_1c(1),
          field_20(0x1c), field_24(0x2d), field_28(0), field_2c(0), field_30(0), field_34(0), field_38(1), field_3c(1),
          field_40(0), field_44(true), field_45(false), field_46(false), field_47(false) {}

    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u32 field_10;
    u32 field_14;  // width
    u32 field_18;  // height
    u32 field_1c;
    u32 field_20;
    u32 field_24;
    u32 field_28;
    u32 field_2c;
    u32 field_30;
    u32 field_34;
    u32 field_38;
    u32 field_3c;
    u32 field_40;
    bool field_44;
    bool field_45;
    bool field_46;
    bool field_47;
};
PKMN_SIZE_ASSERT(Unk_4f96e0_Desc, 0x48);

// The device's description (placeholder name, after the device's slot 11 that
// gives it): what slot 5 and slot 88 copy 0xb6 bytes of.
struct Unk_4f96c0_Desc {
    // the defaults the device's constructor stores (which its body then
    // zeroes). Which members the body assigns, and in what order, decides
    // how LLVM merges and pairs the stores (the original's 8-byte stores
    // start at field_c and leave field_8 and field_a0 alone): the formats
    // cleared by a loop and then set, the count after them, field_a0 before
    // and the last heap kind's members after.
    Unk_4f96c0_Desc()
        : field_0(0xffffffff), field_4(1), field_8(1), field_50(0), field_51(1), field_52(1), field_53(1),
          field_54(0), field_58(0x100), field_5c(4), field_60(4), field_64(4), field_68(4), field_6c(8),
          field_70(0x20000), field_74(0x100), field_78(0x100), field_7c(8), field_80(0x10), field_84(0x100000),
          field_88(0), field_8c(0x400000), field_90(0), field_94(0x400000), field_98(0), field_9c(0x400000),
          field_b4(1), field_b5(1) {
        field_a0 = 0;
        for (s32 i = 0; i < 16; i++) {
            field_10[i] = 0;
        }
        field_10[0] = 0xc100;
        field_10[1] = 0xc000;
        field_10[2] = 0xb300;
        field_10[3] = 0xb200;
        field_10[4] = 0xb100;
        field_10[5] = 0xb000;
        field_10[6] = 0xa100;
        field_10[7] = 0xa000;
        field_10[8] = 0x9300;
        field_10[9] = 0x9200;
        field_10[10] = 0x9100;
        field_c = 11;
        field_a4 = 0x100000;
        field_a8 = 0;
        field_ac = 0;
        field_b0 = 0;
    }

    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;        // how many of field_10 there are
    u32 field_10[16];
    u8 field_50;
    u8 field_51;
    u8 field_52;
    u8 field_53;  // whether the device has a FreeType manager
    u8 field_54;
    // how many of each resource its pools are made for
    u32 field_58;
    u32 field_5c;
    u32 field_60;
    u32 field_64;
    u32 field_68;
    u32 field_6c;
    u32 field_70;
    u32 field_74;
    u32 field_78;
    u32 field_7c;
    u32 field_80;
    // the size and number of the heaps of each of three kinds
    s32 field_84;
    s32 field_88;
    s32 field_8c;
    s32 field_90;
    s32 field_94;
    s32 field_98;
    u32 field_9c;
    u32 field_a0;
    s32 field_a4;
    u32 field_a8;
    u32 field_ac;
    u32 field_b0;
    u8 field_b4;
    u8 field_b5;
};
PKMN_SIZE_ASSERT(Unk_4f96c0_Desc, 0xb8);

// What asks for room in one of the device's memory heaps (placeholder name):
// a size and the kind of memory, as far as the device reads it.
struct Unk_4faac0_Request {
    u32 field_0;
    s32 field_4;  // the size
    u8 field_8[0x10];
    u32 field_18;
    u32 field_1c;
    u32 field_20;
    u32 field_24;
};

class SiGfxNXDevice {
public:
    // The allocator and count every object has (Unk_4bf660), also read as
    // the allocator: the pools' constructors were written when the member
    // was declared as the allocator alone.
    struct Unk_AllocatorAndCount : Unk_4bf660 {
        explicit Unk_AllocatorAndCount(ISiAllocator* pAllocator) : Unk_4bf660(pAllocator) {}
        operator ISiAllocator*() const { return m_pAllocator; }
    };

    // A pointer that its destructor clears (placeholder name).
    struct Unk_Ptr {
        Unk_Ptr() : field_0(0) {}
        ~Unk_Ptr() { field_0 = 0; }

        u64 field_0;
    };

    explicit SiGfxNXDevice(SiGfxNXManager* pManager);
    virtual ~SiGfxNXDevice();
    UNK_REFCOUNT_DECLARE;
    virtual u32 vf4();
    virtual bool vf5(u64 a1, const Unk_4f96c0_Desc* desc, s32 canvasCount, const Unk_4f96e0_Desc* canvasDescs);
    virtual u32 vf6();
    virtual u32 vf7();
    virtual void vf8();
    virtual u64 vf9();
    virtual u64 vf10();
    virtual const u8* vf11();
    virtual u32 vf12();
    virtual Unk_4f96e0_Desc* vf13(s32 index);
    virtual u32 vf14();
    virtual u32 vf15();
    virtual u32 vf16();
    virtual u64 vf17();
    virtual u64 vf18();
    virtual u64 vf19();
    virtual u64 vf20();
    virtual ISiGfxDrawContext* vf21(u32 a1, u64 a2, const void* desc, ISiAllocator* pAllocator);
    virtual ISiGfxCommandList* vf22(u32 a1, u64 a2, ISiAllocator* pAllocator);
    virtual ISiGfxCommandListPool* vf23(u32 a1, u64 a2, ISiAllocator* pAllocator);
    virtual ISiGfxCommandCache* vf24(u32 a1, u64 a2, ISiAllocator* pAllocator);
    virtual ISiGfxPipelineState* vf25(u32 a1, u64 a2, ISiAllocator* pAllocator);
    virtual ISiGfxRootSignature* vf26(u32 a1, u32 a2, ISiAllocator* pAllocator);
    virtual ISiGfxDescriptorTable* vf27(u32 a1, u32 a2, ISiAllocator* pAllocator);
    virtual ISiGfxDescriptorSet* vf28(u32 a1, u64 a2, ISiAllocator* pAllocator);
    virtual ISiGfxRenderPassState* vf29(u32 a1, u64 a2, ISiAllocator* pAllocator);
    virtual ISiGfxMemoryHeap* vf30(u32 a1, ISiAllocator* pAllocator);
    virtual u32 vf31();
    virtual ISiGfxCanvas* vf32(s32 index);
    virtual ISiGfxCanvas* vf33(s32 index);
    virtual u32 vf34();
    virtual u8 vf35();
    virtual u32 vf36();
    virtual u32 vf37();
    virtual ISiGfxVertexFormat* vf38(const void* desc, u64 a2, ISiAllocator* pAllocator);
    virtual ISiGfxVertexFormat* vf39(size_t index);
    virtual ISiGfxVertexFormat* vf40(const char* name);
    virtual u64 vf41();
    virtual ISiGfxShader* vf42(u32 a1, const void* desc, u64 a3, ISiAllocator* pAllocator);
    virtual ISiGfxShader* vf43(size_t index);
    virtual ISiGfxShader* vf44(const char* name);
    virtual ISiGfxShaderProgram* vf45(const void* desc, u64 a2, ISiAllocator* pAllocator);
    virtual ISiGfxShaderProgram* vf46(size_t index);
    virtual ISiGfxShaderProgram* vf47(const char* name);
    virtual void vf48(u64 value, u64 arg2, u64 arg3, u64 arg4, u64 arg5);
    virtual ISiGfxTexture* vf49(u32 a1, const void* desc, u32 a3, ISiAllocator* pAllocator);
    virtual ISiGfxTexture* vf50(size_t index);
    virtual ISiGfxTexture* vf51(const char* name);
    virtual ISiGfxSampler* vf52(const void* desc, u64 a2, u64 a3, ISiAllocator* pAllocator);
    virtual ISiGfxSampler* vf53(size_t index);
    virtual ISiGfxSampler* vf54(const char* name);
    virtual ISiGfxFont* vf55(const void* desc, u64 a2, ISiAllocator* pAllocator);
    virtual ISiGfxFont* vf56(size_t index);
    virtual ISiGfxFont* vf57(const char* name);
    virtual f32 vf58();
    virtual ISiGfxBuffer* vf59(const void* desc, u64 a2, ISiAllocator* pAllocator);
    virtual ISiGfxBuffer* vf60(size_t index);
    virtual ISiGfxBuffer* vf61(const char* name);
    virtual ISiGfxCanvas* vf62(const void* desc, u64 a2, ISiAllocator* pAllocator);
    virtual ISiGfxCanvas* vf63(size_t index);
    virtual ISiGfxCanvas* vf64(const char* name);
    virtual ISiGfxCanvas* vf65(u64 window);
    virtual ISiGfxQuery* vf66(const void* desc, u64 a2, ISiAllocator* pAllocator);
    virtual ISiGfxQuery* vf67(size_t index);
    virtual ISiGfxQuery* vf68(const char* name);
    virtual ISiGfxSurface* vf69(const void* desc, u64 a2, ISiAllocator* pAllocator);
    virtual ISiGfxSurface* vf70(size_t index);
    virtual ISiGfxSurface* vf71(const char* name);
    virtual ISiGfxRenderTarget* vf72(const void* desc, u64 a2, ISiAllocator* pAllocator);
    virtual ISiGfxRenderTarget* vf73(size_t index);
    virtual ISiGfxRenderTarget* vf74(const char* name);
    virtual void vf75(u64 a1, u32 a2, u32 a3);
    virtual s64 vf76(u64 a1, u64 a2, s32 a3, s32 a4, s32* a5, u32* a6);
    virtual void vf77();
    virtual bool vf78();
    virtual bool vf79();
    virtual void vf80(bool value);
    virtual u8 vf81();
    virtual u32 vf82();
    virtual u32 vf83();
    virtual u32 vf84();
    virtual u64 vf85();
    virtual u32 vf86();
    virtual u32 vf87();
    virtual bool vf88(const Unk_4f96c0_Desc* desc, void* nvnDevice, u64 window, u64 a4, u64 a5, u64 a6, u64 a7, u64 a8, u64 a9,
                      u64 a10, u64 a11);
    virtual s32 vf89();
    virtual s32 vf90();
    virtual u64 vf91();
    virtual u64 vf92();
    virtual u64 vf93();
    virtual u64 vf94();
    virtual void vf95(s32* a1, s32* a2);
    virtual void vf96(s32* a1, s32* a2);

    // 0x71004f7760: releases what the device made
    void Unk_4f7760();
    // 0x71004f78c0: makes its info
    bool Unk_4f78c0();
    // 0x71004f7960: releases the pools
    void Unk_4f7960();
    // 0x71004f7b20: releases the memory heaps
    void Unk_4f7b20();
    // 0x71004f82a0: makes its resource pools
    bool Unk_4f82a0();
    // 0x71004f8660: makes its command queues and its command list
    bool Unk_4f8660();
    // 0x71004f87b0: makes its canvases
    bool Unk_4f87b0();
    // 0x71004f88f0
    void Unk_4f88f0();
    // 0x71004f8c90: makes its memory heaps
    bool Unk_4f8c90();
    // 0x71004f9480
    void Unk_4f9480();
    // 0x71004f9640: gives a resource back to its kind's pool
    void Unk_4f9640(ISiGfxResource* resource);
    // 0x71004fa590
    bool Unk_4fa590();
    // 0x71004faac0, 0x71004facb0, 0x71004faea0: room in a memory heap of
    // each of the three kinds, a new heap if the others are full
    SiGfxNXMemoryHeap* Unk_4faac0(const Unk_4faac0_Request* request, s64* offset);
    SiGfxNXMemoryHeap* Unk_4facb0(const Unk_4faac0_Request* request, s64* offset);
    SiGfxNXMemoryHeap* Unk_4faea0(const Unk_4faac0_Request* request, s64* offset);
    // 0x71004fb090
    bool Unk_4fb090();
    // 0x71004fb1d0 to 0x71004fb380: descriptors from its pools, or from the
    // functions it was given with another's NVN device
    s32 Unk_4fb1d0(u64 a1, u64 a2);
    s32 Unk_4fb200(u64 a1, u64 a2);
    s32 Unk_4fb230(u64 a1, u64 a2);
    u64 Unk_4fb260(u64 a1);
    u64 Unk_4fb290(u32 a1);
    u64 Unk_4fb2c0(u32 a1);
    u64 Unk_4fb2f0(u32 a1);
    s32 Unk_4fb380(u64 a1, u64 a2);

    ISiAllocator* Unk_Allocator() const { return field_8.m_pAllocator; }
    inline void Unk_MakeFreeTypeManager();

    Unk_AllocatorAndCount field_8;
    SiGfxNXManager* field_18;
    Unk_CriticalSection field_20;
    Unk_4f96c0_Desc field_50;
    s32 field_108;  // how many canvases it has
    Unk_4f96e0_Desc field_10c[4];
    u64 field_230;
    u64 field_238;
    u32 field_240;
    u32 field_244;
    bool field_248;
    SiGfxNXDeviceInfo* field_250;
    SiGfxNXCommandQueue* field_258;
    SiGfxNXCommandQueue* field_260;
    SiGfxNXCommandList* field_268;
    u8 field_270;
    SiGfxNXCanvas* field_278[8];
    void* field_2b8;  // the NVN device
    s32 field_2c0;
    s32 field_2c4;
    bool field_2c8;
    bool field_2c9;  // whether the NVN device is another's
    // the pool of each kind of resource (a resource's slot 8 tells its
    // kind): 1 textures, 2 fonts, 3 surfaces, 4 volumes, 5 canvases, 6 vertex
    // formats, 7 shaders, 8 shader programs, 9 queries, 10 buffers, 11 render
    // targets, 12 samplers
    SiGfxResourcePool* field_2d0[13];
    // the pools
    SiGfxNXSurfacePool* field_338;
    SiGfxNXTexturePool* field_340;
    SiGfxNXCanvasPool* field_348;
    SiGfxNXRenderTargetPool* field_350;
    SiGfxNXBufferPool* field_358;
    SiGfxNXVolumePool* field_360;
    SiGfxNXVertexFormatPool* field_368;
    SiGfxNXShaderPool* field_370;
    SiGfxNXShaderProgramPool* field_378;
    SiGfxNXFontPool* field_380;
    SiGfxNXQueryPool* field_388;
    SiGfxNXSamplerPool* field_390;
    SiGfxNXFreeTypeManager* field_398;
    // what its own drawing uses: a root signature, and a shader program and
    // a vertex format for each of 6 by 7 cases
    SiGfxNXRootSignature* field_3a0;
    ISiGfxShaderProgram* field_3a8[6][7];
    ISiGfxVertexFormat* field_4f8[6][7];
    Unk_Ptr field_648;
    SiArray<SiGfxNXMemoryHeap*, 16> field_650;
    SiArray<SiGfxNXMemoryHeap*, 16> field_6a0;
    SiArray<SiGfxNXMemoryHeap*, 16> field_6f0;
    bool field_740;
    bool field_741;
    // its pools of NVN descriptors, unless the NVN device is another's
    Unk_5518d0_Pool* field_748;
    Unk_5520b0_Pool* field_750;
    Unk_5518d0_Pool* field_758;
    // what gives descriptors for another's NVN device: four functions and
    // what each is called with
    s32 (*field_760)(u64 a1, u64 a2, u64 user);
    u64 (*field_768)(u64 a1, u64 user);
    u64 (*field_770)(u32 a1, u64 user);
    u64 (*field_778)(u32 a1, u64 user);
    u64 field_780;
    u64 field_788;
    u64 field_790;
    u64 field_798;
    SiGfxNXMemoryHeap* field_7a0;
    s32 field_7a8;
    u64 field_7b0;
    u64 field_7b8;
};
PKMN_SIZE_ASSERT(SiGfxNXDevice, 0x7c0);
PKMN_OFFSET_ASSERT(SiGfxNXDevice, field_50, 0x50);
PKMN_OFFSET_ASSERT(SiGfxNXDevice, field_108, 0x108);
PKMN_OFFSET_ASSERT(SiGfxNXDevice, field_230, 0x230);
PKMN_OFFSET_ASSERT(SiGfxNXDevice, field_278, 0x278);
PKMN_OFFSET_ASSERT(SiGfxNXDevice, field_2d0, 0x2d0);
PKMN_OFFSET_ASSERT(SiGfxNXDevice, field_338, 0x338);
PKMN_OFFSET_ASSERT(SiGfxNXDevice, field_3a0, 0x3a0);
PKMN_OFFSET_ASSERT(SiGfxNXDevice, field_650, 0x650);
PKMN_OFFSET_ASSERT(SiGfxNXDevice, field_748, 0x748);
PKMN_OFFSET_ASSERT(SiGfxNXDevice, field_7a0, 0x7a0);

}  // namespace SiSDK3

#ifdef UNK_SIGFX_NX_DEVICE_IMPL
// 0x71004fb3a0 (vf2), 0x71004fb3c0 (vf3)
#line 69
UNK_REFCOUNT_DEFINE(SiSDK3::SiGfxNXDevice, field_8.m_pAllocator, field_8.m_count)
#endif
