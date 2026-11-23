// SiSDK3's SiGfx interfaces as YEBIS's GPU layer calls them: placeholder
// names (their RTTI is in SiSDK3's part of the executable, not looked up
// yet), and only the slots YEBIS's functions call are typed.
#pragma once

#include <types.h>

namespace PPFX {

struct Unk_SiGfxInterface;
struct Unk_SiGfxRenderTarget;
struct Unk_SiGfxTexture;
struct Unk_SiGfxVertexFormat;

// what ISiGfxQuery::Create() takes
struct Unk_SiGfxQueryDesc {
    s32 field_0;
    s32 field_4;
};

// ISiGfxQuery
struct Unk_SiGfxQuery {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();  // releases
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
    virtual bool vf18(const Unk_SiGfxQueryDesc* desc);  // "ISiGfxQuery::Create()"
};

// ISiGfxDevice
struct Unk_SiGfxDevice {
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
    virtual Unk_SiGfxRenderTarget* vf29(u32 arg1, u32 arg2, void* arg3);  // "ISiGfxDevice::CreateRenderPassState()"
    virtual Unk_SiGfxInterface* vf30(u32 arg1, void* arg2);  // makes a memory heap (IGPUBuffer)
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual Unk_SiGfxVertexFormat* vf38(void* arg1, u32 arg2, void* arg3);  // "pSiGfxDevice->CreateVertexFormat()"
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
    virtual Unk_SiGfxTexture* vf49(u32 kind, void* arg2, u32 arg3, void* arg4);  // "ISiGfxDevice::CreateTexture()"
    virtual void vf50();
    virtual void vf51();
    virtual Unk_SiGfxInterface* vf52(const void* desc, void* arg2, u32 arg3, void* arg4);  // "pSiGfxDevice->CreateSampler()"
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual Unk_SiGfxInterface* vf59(void* arg1, u32 arg2, void* arg3);  // makes a buffer (IGPUBuffer)
    virtual void vf60();
    virtual void vf61();
    virtual void vf62();
    virtual void vf63();
    virtual void vf64();
    virtual void vf65();
    virtual Unk_SiGfxQuery* vf66(void* arg1, s32 arg2, void* arg3);  // "ISiGfxDevice::CreateQuery()"
    virtual void vf67();
    virtual void vf68();
    virtual void vf69();
    virtual void vf70();
    virtual void vf71();
    virtual Unk_SiGfxInterface* vf72(void* arg1, u32 arg2, void* arg3);  // "ISiGfxDevice::CreateRenderTarget()"
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
    virtual void vf85();
    virtual void vf86();
    virtual void vf87();
    virtual void vf88();
    virtual s32 vf89();  // IGPUDevice::CreateDevice's viewport origin (0: upper left)
    virtual s32 vf90();  // its clip volume's near plane (0: at zero)
};

// the draw context (pSiGfxDrawContext)
// what draw context slot 33 gives (placeholder): the back buffer's render
// target is at 0x18
struct Unk_SiGfxBackBuffer {
    u8 pad_0[0x18];
    Unk_SiGfxRenderTarget* field_18;
};

struct Unk_SiGfxDrawContext {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();  // adds a reference
    virtual void vf3();
    virtual void vf4();
    virtual Unk_SiGfxDevice* vf5();  // the device
    virtual void vf6();
    virtual void vf7();
    virtual bool vf8(void* list);  // BeginCommandList
    virtual void vf9();
    virtual void* vf10();  // the command list it records to
    virtual void vf11(void* target, const void* clearValues);  // begins drawing to a target
    virtual void vf12();  // ends what the device began
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20(void* buffer, s32 format);  // sets the index buffer
    virtual void vf21(const void* color);  // sets the blend colour
    virtual void vf22();
    virtual void vf23();
    virtual void vf24(u32 arg1, u32 arg2, u32 instances, u32 arg4);  // draws
    virtual void vf25(u32 arg1, u32 arg2, u32 arg3, u32 instances, u32 arg5);  // draws with indices
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30(void* resource, u32 from, u32 to);  // changes a resource's state
    virtual void vf31();
    virtual void vf32();
    virtual Unk_SiGfxBackBuffer* vf33();  // the back buffer
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
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual void vf59();
    virtual void vf60();
    virtual bool vf61(Unk_SiGfxQuery* query);  // "BeginQuery"
    virtual bool vf62(Unk_SiGfxQuery* query);  // "EndQuery"
    virtual void vf63();
    virtual bool vf64(Unk_SiGfxQuery* query, s32 wait);  // "ISiGfxQuery::CollectQueryData()"
    virtual u32* vf65(Unk_SiGfxQuery* query);  // "ISiGfxQuery::GetQueryData()"
    virtual void vf66();
    virtual void vf67();
    virtual void vf68();
    virtual bool vf69(void* buffer, void* info);  // maps a buffer
    virtual void vf70(void* buffer, void* info);  // unmaps a buffer
    virtual bool vf71(void* source, void* target);  // copies a surface
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
    virtual void vf85();
    virtual void vf86();
    virtual void vf87();
    virtual void vf88();
    virtual void vf89();
    virtual void vf90();
    virtual void vf91();
    virtual void vf92();
    virtual void vf93();
    virtual void vf94();
    virtual void vf95();
    virtual void vf96();
    virtual void vf97();
    virtual void vf98(void* list);  // records to a command list (null: the context's own)
};

}  // namespace PPFX
