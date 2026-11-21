// PPFX::IGPUDevice (RTTI names the class; members are placeholders), as far
// as the functions written so far read it.
#pragma once

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
    u8 field_10[0x10];
};

// PPFX::IGPUBuffer (GPUInterfaceBuffer.cpp names it and these two in its log lines)
class IGPUBuffer : public IGPUInterface {
public:
    void* Map(s32 mode, u32 offset, u32 size);  // 0x71004491b0
    s32 Unmap();                                // 0x7100449380
};

class IGPUDevice : public IGPUInterface {
public:
    // slots 4 to 75: only those this code calls are typed
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9(void* arg1, s32 arg2);
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17(Unk_Viewport* viewport);  // the current target's rectangle
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
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40(s32 arg);
    virtual void vf41(s32 arg1, s32 arg2);
    virtual void vf42(s32 arg);
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
    virtual void vf58(s32 primitive, s32 count, s32 arg3, s32 arg4, s32 arg5);  // draws
    virtual void vf59();
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
    virtual s32 vf70(const Unk_InputElement* elements, s32 count, void* arg3, s32 arg4, IGPUInterface** attribute);  // "IGPUDevice::CreateInputAttribute"
    virtual void vf71();
    virtual void vf72();
    virtual void vf73();
    virtual void vf74();
    virtual void vf75();

    u8 field_10[0x20];
    Unk_SiGfxDrawContext* field_30;
    Unk_SiGfxDevice* field_38;
    u8 field_40[0x18];
    bool field_58;
};
PKMN_OFFSET_ASSERT(IGPUDevice, field_30, 0x30);
PKMN_OFFSET_ASSERT(IGPUDevice, field_38, 0x38);

}  // namespace PPFX
