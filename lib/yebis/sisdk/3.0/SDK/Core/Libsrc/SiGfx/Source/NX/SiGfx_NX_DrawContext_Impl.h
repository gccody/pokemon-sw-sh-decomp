// SiSDK3::SiGfxNXDrawContext: as far as the executable's functions show
// them, with placeholder members (RTTI names the classes). The reference
// counts are defined in this header (their __FILE__), at the original's lines.
// (Unk_DeviceObjects.h has the class as the device's translation unit needs
// it: its constructor and the function that sets it up.)
#pragma once

#include <nx_middleware/gfx/nvn.h>
#include <string.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>

// 0x71004fb320 (leafgen's name and type: the device and an NVN command buffer)
struct Unk_4fb320;
void Unk_4fb320_update(const Unk_4fb320* self, u64 value);
// 0x71005474b0, 0x7100544280 (leafgen's names and types: the two helpers)
struct Unk_5474b0;
u32 Unk_5474b0_get(Unk_5474b0* self);
struct Unk_544280;
u64 Unk_544280_get(const Unk_544280* self);
// 0x710055ba30: what the draw context's member at 0x30 is applied with
// (placeholder name and type)
void Unk_55ba30(void* states);
// 0x71004c4cf0 (leafgen's name and type: a name, a buffer and its size)
void Unk_4c4cf0_update(u64, u64, u32);

namespace SiSDK3 {

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
    virtual void* vf56(size_t index);
};

// The command list the draw context records into (placeholder name): slot 15
// is its NVN command buffer.
class Unk_NXDrawCommandList {
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
    virtual void* vf15();

    u8 field_8[0x120];
    s32 field_128;  // how many draws it has
    u8 field_12c[8];
    u32 field_134;  // how many compute dispatches
    s32 field_138;  // how many triangles
    u32 field_13c;
    s32 field_140;  // how many points and lines
    s32 field_144;  // how many vertices
    s32 field_148;  // how many indices
    u32 field_14c;
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

// The draw context's two helpers (placeholder names: their classes aren't
// identified here, and their functions' arguments, which the draw context's
// slots pass on as they come, aren't either).
class Unk_NXDrawHelper {
public:
    void Unk_5472d0();
    void Unk_547760();
    void Unk_547810();
    void Unk_5478f0();
    void Unk_547930();
    void Unk_547a40();
    void Unk_547b60();
    void Unk_547ca0();
    void Unk_547df0();
    void Unk_547f50();
    void Unk_5480c0();
    void Unk_548230();
    void Unk_548380();
    void Unk_5484f0();
    void Unk_548640();
    void Unk_54cab0();

    u8 field_0[0xb10];
};
class Unk_NXTextHelper {
public:
    void Unk_544010(void* font);
    void Unk_544290();
    void Unk_544540();
    void Unk_544610();
    void Unk_544b00();
    void Unk_545910();

    u8 field_0[0x2e0];
};

class SiGfxNXDrawContext {
public:
    // A viewport and a scissor rectangle as slots 14 and 15 are given them,
    // and as they are kept (placeholder names).
    struct Unk_Viewport {
        s32 field_0;
        s32 field_4;
        s32 field_8;
        s32 field_c;
        s32 field_10;
        s32 field_14;
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
    struct Unk_Range {
        s32 field_0;
        s32 field_4;
    };

    virtual ~SiGfxNXDrawContext();
    UNK_REFCOUNT_DECLARE;

    // 0x710053c340
    void Unk_53c340();
    // Counts a draw's primitives in the command list (inline in the draw
    // slots: placeholder name).
    void Unk_CountPrimitives(Unk_NXDrawCommandList* pList, s32 count, s32 instances) {
        switch (field_40c) {
        case 1:
            pList->field_140 += instances * count;
            break;
        case 2:
            pList->field_140 += instances * (count / 2);
            break;
        case 3:
            pList->field_140 += instances * (count + 1);
            break;
        case 4:
            pList->field_138 += instances * (count / 3);
            break;
        case 5:
            pList->field_138 += instances * (count + 2);
            break;
        }
    }
    void vf12();                                   // 0x710053c9c0
    void vf14(s32 count, const Unk_Viewport* viewports);  // 0x710053c9f0
    void vf15(s32 count, const Unk_Scissor* scissors);    // 0x710053ca70
    void vf20(Unk_NXDrawIndirect* pBuffer, s32 offset);  // 0x710053d490: the index buffer
    bool vf24(s32 count, s32 first, s32 instances, s32 baseInstance);  // 0x7100540080
    bool vf25(s32 count, s32 first, s32 baseVertex, s32 instances, s32 baseInstance);  // 0x71005401c0
    u32 vf26(Unk_NXDrawIndirect* pBuffer);         // 0x7100540320
    u32 vf28(s32 x, s32 y, s32 z);                 // 0x71005403c0
    void vf31(const char* description);            // 0x71005405c0
    void vf34();                                   // 0x7100540750
    void vf35();
    void vf36();
    void vf37();
    void vf38();
    void vf39();
    void vf40();
    void vf41();
    void vf42();
    void vf43();
    void vf44();
    void vf45();
    void vf46();
    void vf47();
    void vf48();
    void vf49();
    void vf50(u32 index);                          // 0x7100540760
    void vf51(void* font);                         // 0x71005407a0
    void vf52();
    void vf53();
    void vf54();
    void vf55();
    void vf56();
    void vf57();
    void vf58();
    void vf59();
    bool vf61(Unk_NXDrawQuery* query);             // 0x7100540840
    bool vf62(Unk_NXDrawQuery* query);             // 0x7100540890
    bool vf64(Unk_NXDrawQuery* query);             // 0x71005408e0
    void vf83(bool more);                          // 0x7100542260
    void vf95(u32 kind, s32 index, s32 count, const u32* values);  // 0x7100542840
    void vf98(Unk_NXDrawCommandList* pCommandList);  // 0x7100541db0
    void vf99(const void* pool);                   // 0x7100541e00
    void vf100(const void* pool);                  // 0x7100541e20
    void vf101();                                  // 0x7100541e40

    SiSDK3::ISiAllocator* field_8;
    u32 field_10;
    Unk_NXDrawDevice* field_18;
    u64 field_20;
    Unk_NXDrawCommandList* field_28;
    u32 field_30;  // what changed (2: the viewports, 4: the scissors)
    u8 field_34[0x1c];
    u8 field_50[0x18];
    void* field_68;
    u8 field_70[8];
    s32 field_78;
    u8 field_7c[0x180];
    s32 field_1fc;
    u8 field_200[0x200];
    Unk_NXDrawIndirect* field_400;  // the index buffer
    u32 field_408;
    u32 field_40c;  // what is drawn (1: points, 2 and 3: lines, 4 and 5: triangles)
    u8 field_410[0x128];
    s32 field_538;  // how many viewports
    s32 field_53c;  // how many scissors
    u32 field_540;
    Unk_Rect field_544[16];   // the viewports' rectangles
    Unk_Range field_644[16];  // and depth ranges
    Unk_Rect field_6c4[16];   // the scissors (left, top, width, height)
    u8 field_7c4[0x104];
    u64 field_8c8;  // the index buffer's address
    s32 field_8d0;  // the indices' NVN type
    s32 field_8d4;  // and size
    s32 field_8d8;  // the NVN draw mode
    u8 field_8dc[0x18ac];
    u32 field_2188[10][64];  // values by kind (slot 95)
    u8 field_2b88[0xe8];
    Unk_NXDrawHelper field_2c70;
    Unk_NXTextHelper field_3780;
    void* field_3a60;  // the command list's NVN command buffer
    s32 field_3a68;
    u8 field_3a6c[0x584];
};
PKMN_OFFSET_ASSERT(SiGfxNXDrawContext, field_2188, 0x2188);
PKMN_OFFSET_ASSERT(SiGfxNXDrawContext, field_2c70, 0x2c70);
PKMN_OFFSET_ASSERT(SiGfxNXDrawContext, field_3780, 0x3780);
PKMN_OFFSET_ASSERT(SiGfxNXDrawContext, field_3a60, 0x3a60);
PKMN_SIZE_ASSERT(SiGfxNXDrawContext, 0x3ff0);

}  // namespace SiSDK3

// 0x7100542880 (vf2), 0x71005428a0 (vf3)
#line 39
UNK_REFCOUNT_DEFINE(SiSDK3::SiGfxNXDrawContext, field_8, field_10)
