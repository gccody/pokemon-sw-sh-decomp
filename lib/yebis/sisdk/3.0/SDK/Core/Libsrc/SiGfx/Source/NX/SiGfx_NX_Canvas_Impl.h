// SiSDK3::SiGfxNXCanvas (RTTI names the class; like the other NX resources it
// is on ISiInterface and, at 8, ISiNamedObject): a window's surfaces and
// render targets. Placeholder members; the virtual functions are vf<slot>.
// The reference counts are defined in this header (their __FILE__), at the
// original's lines, for the class's own translation unit
// (UNK_SIGFX_NX_CANVAS_IMPL). (Unk_DeviceObjects.h has the class as the
// device's translation unit needs it: its constructor and the two functions
// that make it.)
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/Unk_NXResource.h>

class NVNtexture;
class NVNtextureView;

namespace SiSDK3 {

// A colour or depth buffer's description as the canvas reads it (the
// surface's: placeholder name and members).
struct Unk_NXCanvasBufferDesc {
    u32 field_0;
    u32 field_4;  // the format
    u32 field_8;
    u32 field_c;
    u32 field_10;
    s32 field_14;  // the width
    s32 field_18;  // the height
    s32 field_1c;  // the samples
    u32 field_20;
};

// One of the canvas's colour buffers as the canvas calls it (placeholder
// name: they are surfaces): slot 3 lets it go, slot 17 is its description,
// slot 24 takes what the canvas's slot 44 was given.
class Unk_NXCanvasBuffer {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
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
    virtual void vf15();
    virtual void vf16();
    virtual const Unk_NXCanvasBufferDesc* vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual u32 vf24(u64 a1);
};

// The named object's functions are the canvas's slots 51 to 53.
UNK_NAMED_OBJECT(Unk_NXCanvasNamedObject, vf51, vf52, vf53);

class SiGfxNXCanvas : public Unk_NXInterface, public Unk_NXCanvasNamedObject {
public:
    SiGfxNXCanvas(ISiAllocator* pAllocator, SiGfxNXDevice* pDevice);  // 0x71004fb6d0
    ~SiGfxNXCanvas() override;                  // 0x71004fb850, 0x71004fbab0
    u32 vf2() override;                         // 0x71004fe070
    u32 vf3() override;                         // 0x71004fe090
    u32 vf4() override;
    virtual Unk_NXDeviceInterface* vf5();  // its device
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
    virtual u64 vf21();  // its window
    virtual bool vf22();  // shows the drawn texture and takes the next one
    virtual void vf23();
    virtual Unk_NXCanvasBuffer* vf24(s32 index);  // 0x71004fd030
    virtual void vf25();
    virtual bool vf26(u32 width, u32 height);  // 0x71004fd080
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void* vf32(s32 index);              // 0x71004fdce0
    virtual void* vf33(s32 index);              // 0x71004fdd20
    virtual void* vf34();                       // 0x71004fdd60
    virtual void* vf35();                       // 0x71004fdda0
    virtual void* vf36();                       // 0x71004fdde0
    virtual void* vf37();                       // 0x71004fde20
    virtual void* vf38(s32 index);              // 0x71004fde60
    virtual void* vf39(s32 index);              // 0x71004fdea0
    virtual void* vf40();                       // 0x71004fdee0
    virtual void* vf41();                       // 0x71004fdf20
    virtual void* vf42();                       // 0x71004fdf60
    virtual void* vf43();                       // 0x71004fdfa0
    virtual u32 vf44(u64 a1, s32 index);        // 0x71004fdfe0
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void* vf49(s32 index);              // 0x71004fe130
    virtual void* vf50(s32 index);              // 0x71004fe160
    bool vf51(const char* name) override;       // 0x71004fcaa0
    const SiString<char>* vf52() override;      // 0x71004fcb20
    u32 vf53() override;                        // 0x71004fcb40

    // One of the window's textures' two objects, or none (inline in the
    // slots that return them: placeholder names).
    // (The sign's test returns by itself; the two limits are tested without a
    // short circuit, `|`: the count is read before either, their block isn't
    // merged with the sign's, and the sign's test and the comparison with 3
    // stay two, `tbnz ; cmp w1, #3 ; b.gt`. With `||` the count's load is sunk
    // behind the comparison with 3, which then joins the sign's test as one
    // unsigned comparison.) The index is taken by reference: the slots that
    // pass a member compare it with the count in that order (`cmp w9, w10 ;
    // b.ge`), which is the order of two loads as written; by value this
    // function's own code has the count first, as for the slots that pass
    // their argument.
    void* Unk_Get150(const s32& index) {
        if (index < 0) {
            return nullptr;
        }
        if ((index > 3) | (index >= field_148)) {
            return nullptr;
        }
        return field_150[index];
    }
    void* Unk_Get178(const s32& index) {
        if (index < 0) {
            return nullptr;
        }
        if ((index > 3) | (index >= field_148)) {
            return nullptr;
        }
        return field_178[index];
    }

    // 0x71004fc790: a render target for each colour buffer
    bool Unk_4fc790();
    // 0x71004fc4d0: its colour buffers, from the window's textures, and its
    // depth buffer
    bool Unk_4fc4d0();
    // 0x71004fc8a0: the canvas of a window that was made for it
    bool Unk_4fc8a0(u64 window, const Unk_4f96e0_Desc* desc);
    // 0x71004fbb20: the canvas of a native window: it makes the NVN window
    // and its textures
    bool Unk_4fbb20(u64 window, const Unk_4f96e0_Desc* desc);

    Unk_4bf660 field_10;
    SiGfxNXDevice* field_20;
    size_t field_28;  // its index in the pool (0: it isn't in one)
    u64 field_30;     // its window
    SiString<char> field_38;  // the name
    u32 field_68;             // its hash
    u32 field_6c;
    // what its render targets are (placeholder name and members): their
    // sizes and formats, how many there are, the depth buffer's
    struct Unk_TargetInfo {
        u64 field_0;
        u64 field_8;
        u32 field_10;
        u32 field_14;
        u32 field_18;  // the colour buffers' width
        u32 field_1c;  // and height
        u32 field_20;
        u32 field_24;
        s32 field_28;  // how many colour buffers
        u32 field_2c;  // their format
        u64 field_30;
        u32 field_38;  // the depth buffer's format
        u32 field_3c;
        u32 field_40;
        u32 field_44;
        u32 field_48;
        bool field_4c;  // whether there is a depth buffer
        bool field_4d;  // whether it has stencil
    };
    Unk_TargetInfo field_70;
    Unk_4f96e0_Desc field_c0;  // what it was made from
    s32 field_108;
    bool field_10c;
    bool field_10d;
    s32 field_110;
    s32 field_114;  // which of the window's textures is drawn to
    s32 field_118;  // and which one is shown
    s32 field_11c;  // how many colour buffers
    Unk_NXCanvasBuffer* field_120[4];
    Unk_NXCanvasBuffer* field_140;  // the depth buffer
    s32 field_148;  // how many textures the window has
    Unk_NXInterface* field_150[4];  // the render targets
    s32 field_170;                  // how many render pass states
    Unk_NXInterface* field_178[4];  // the render pass states
    void* field_198;  // NVNwindow
    SiArray<NVNtexture*, 16> field_1a0;      // the window's textures
    SiArray<NVNtextureView*, 16> field_1f0;  // and their views
    // a part of the heap (placeholder name): where it is and its size
    struct Unk_HeapBlock {
        s64 field_0;
        u64 field_8;
    };
    SiGfxNXMemoryHeap* field_240;    // the heap of the window's textures
    Unk_HeapBlock field_248[4];   // and their parts of it
    u64 field_288[16];  // NVNtextureBuilder of the window's textures
    u64 field_308[8];   // NVNwindowBuilder
    u64 field_348[8];  // the window's NVNsync
    u64 field_388;
    u64 field_390;  // the storage size of a texture of the largest size
    bool field_398;
};
PKMN_OFFSET_ASSERT(SiGfxNXCanvas, field_c0, 0xc0);
PKMN_OFFSET_ASSERT(SiGfxNXCanvas, field_108, 0x108);
PKMN_OFFSET_ASSERT(SiGfxNXCanvas, field_170, 0x170);
PKMN_OFFSET_ASSERT(SiGfxNXCanvas, field_388, 0x388);
PKMN_OFFSET_ASSERT(SiGfxNXCanvas, field_114, 0x114);
PKMN_OFFSET_ASSERT(SiGfxNXCanvas, field_150, 0x150);
PKMN_OFFSET_ASSERT(SiGfxNXCanvas, field_1a0, 0x1a0);
PKMN_OFFSET_ASSERT(SiGfxNXCanvas, field_240, 0x240);
PKMN_OFFSET_ASSERT(SiGfxNXCanvas, field_288, 0x288);
PKMN_OFFSET_ASSERT(SiGfxNXCanvas, field_348, 0x348);
PKMN_SIZE_ASSERT(SiGfxNXCanvas, 0x3a0);

}  // namespace SiSDK3

#ifdef UNK_SIGFX_NX_CANVAS_IMPL
// 0x71004fe070 (vf2), 0x71004fe090 (vf3)
#line 40
UNK_REFCOUNT_DEFINE(SiSDK3::SiGfxNXCanvas, field_10.m_pAllocator, field_10.m_count)
#endif
