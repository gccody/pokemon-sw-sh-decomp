// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N6SiSDK313SiGfxNXBufferE
#include <types.h>

struct Unk_538ae0 {
    u8 _0[0x18];
    u32 field_18;
};
PKMN_OFFSET_ASSERT(Unk_538ae0, field_18, 0x18);

struct Unk_537680 {
    u8 _0[0x20];
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_537680, field_20, 0x20);

struct Unk_537690 {
    u8 _0[0x20];
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_537690, field_20, 0x20);

struct Unk_5376a0 {
    u8 _0[0x28];
    u64 field_28;
};
PKMN_OFFSET_ASSERT(Unk_5376a0, field_28, 0x28);

struct Unk_5376b0 {
    u8 _0[0xa4];
    u8 field_a4;
};
PKMN_OFFSET_ASSERT(Unk_5376b0, field_a4, 0xa4);

struct Unk_5376d0 {
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
};

struct Unk_537720 {
    u8 _0[0xb8];
    u8 field_b8;
};
PKMN_OFFSET_ASSERT(Unk_537720, field_b8, 0xb8);

struct Unk_537730 {
    u8 _0[0xc0];
    u32 field_c0;
};
PKMN_OFFSET_ASSERT(Unk_537730, field_c0, 0xc0);

struct Unk_537740 {
    u8 _0[0x108];
    u64 field_108;
};
PKMN_OFFSET_ASSERT(Unk_537740, field_108, 0x108);

struct Unk_537750 {
    u8 _0[0x108];
    u64 field_108;
};
PKMN_OFFSET_ASSERT(Unk_537750, field_108, 0x108);

struct Unk_538990 {
    u8 _0[0x150];
    u32 field_150;
};
PKMN_OFFSET_ASSERT(Unk_538990, field_150, 0x150);

struct Unk_538950 {
    u8 _0[0xd0];
    u8 field_d0;
};
PKMN_OFFSET_ASSERT(Unk_538950, field_d0, 0xd0);

struct Unk_538960 {
    u8 _0[0x100];
    u64 field_100;
};
PKMN_OFFSET_ASSERT(Unk_538960, field_100, 0x100);

struct Unk_538970 {
    u8 _0[0x12c];
    u32 field_12c;
};
PKMN_OFFSET_ASSERT(Unk_538970, field_12c, 0x12c);

struct Unk_538980 {
    u8 _0[0x148];
    u64 field_148;
};
PKMN_OFFSET_ASSERT(Unk_538980, field_148, 0x148);

struct Unk_537640 {
    u8 _0[0x30];
    u8 field_30;
};
PKMN_OFFSET_ASSERT(Unk_537640, field_30, 0x30);

struct Unk_537660 {
    u8 _0[0xa0];
    u32 field_a0;
};
PKMN_OFFSET_ASSERT(Unk_537660, field_a0, 0xa0);

struct Unk_537650 {
    u8 _0[0x28];
    u8 field_28;
};
PKMN_OFFSET_ASSERT(Unk_537650, field_28, 0x28);

namespace SiSDK3 {
class SiGfxNXBuffer {
public:
    u32 vf4();
    u64 vf5();
    u64 vf6();
    u64 vf7();
    const u8* vf8();
    void vf9();
    void vf10();
    void vf11();
    void vf12();
    void vf13();
    void vf14();
    void vf15();
    u32 vf16();
    const u8* vf17();
    void vf18(u32 value);
    u64 vf19();
    u64 vf20();
    u32 vf23();
    const u8* vf26();
    u64 vf27();
    u32 vf28();
    u64 vf29();
    const u8* vf31();
    u32 vf32();
    const u8* vf3();
};
}  // namespace SiSDK3

// 0x7100537640
const u8* SiSDK3::SiGfxNXBuffer::vf31() {
    const Unk_537640* self = reinterpret_cast<const Unk_537640*>(this);
    return &self->field_30;
}

// 0x7100537650
const u8* SiSDK3::SiGfxNXBuffer::vf3() {
    const Unk_537650* self = reinterpret_cast<const Unk_537650*>(this);
    return &self->field_28;
}

// 0x7100537660
u32 SiSDK3::SiGfxNXBuffer::vf32() {
    const Unk_537660* self = reinterpret_cast<const Unk_537660*>(this);
    return self->field_a0;
}

// 0x7100537680
u64 SiSDK3::SiGfxNXBuffer::vf5() {
    const Unk_537680* self = reinterpret_cast<const Unk_537680*>(this);
    return self->field_20;
}

// 0x7100537690
u64 SiSDK3::SiGfxNXBuffer::vf6() {
    const Unk_537690* self = reinterpret_cast<const Unk_537690*>(this);
    return self->field_20;
}

// 0x71005376a0
u64 SiSDK3::SiGfxNXBuffer::vf7() {
    const Unk_5376a0* self = reinterpret_cast<const Unk_5376a0*>(this);
    return self->field_28;
}

// 0x71005376b0
const u8* SiSDK3::SiGfxNXBuffer::vf8() {
    const Unk_5376b0* self = reinterpret_cast<const Unk_5376b0*>(this);
    return &self->field_a4;
}

// 0x71005376c0
void SiSDK3::SiGfxNXBuffer::vf9() {
}

// 0x71005376d0
void SiSDK3::SiGfxNXBuffer::vf10() {
    Unk_5376d0* self = reinterpret_cast<Unk_5376d0*>(this);
    self->vf22();
}

// 0x71005376e0
void SiSDK3::SiGfxNXBuffer::vf11() {
}

// 0x71005376f0
void SiSDK3::SiGfxNXBuffer::vf12() {
}

// 0x7100537700
void SiSDK3::SiGfxNXBuffer::vf13() {
}

// 0x7100537710
void SiSDK3::SiGfxNXBuffer::vf14() {
}

// 0x7100537720
const u8* SiSDK3::SiGfxNXBuffer::vf17() {
    const Unk_537720* self = reinterpret_cast<const Unk_537720*>(this);
    return &self->field_b8;
}

// 0x7100537730
void SiSDK3::SiGfxNXBuffer::vf18(u32 value) {
    Unk_537730* self = reinterpret_cast<Unk_537730*>(this);
    self->field_c0 = value;
}

// 0x7100537740
u64 SiSDK3::SiGfxNXBuffer::vf19() {
    const Unk_537740* self = reinterpret_cast<const Unk_537740*>(this);
    return self->field_108;
}

// 0x7100537750
u64 SiSDK3::SiGfxNXBuffer::vf20() {
    const Unk_537750* self = reinterpret_cast<const Unk_537750*>(this);
    return self->field_108;
}

// 0x7100538930
void SiSDK3::SiGfxNXBuffer::vf15() {
}

// 0x7100538940
u32 SiSDK3::SiGfxNXBuffer::vf16() {
    return 0;
}

// 0x7100538950
const u8* SiSDK3::SiGfxNXBuffer::vf26() {
    const Unk_538950* self = reinterpret_cast<const Unk_538950*>(this);
    return &self->field_d0;
}

// 0x7100538960
u64 SiSDK3::SiGfxNXBuffer::vf27() {
    const Unk_538960* self = reinterpret_cast<const Unk_538960*>(this);
    return self->field_100;
}

// 0x7100538970
u32 SiSDK3::SiGfxNXBuffer::vf28() {
    const Unk_538970* self = reinterpret_cast<const Unk_538970*>(this);
    return self->field_12c;
}

// 0x7100538980
u64 SiSDK3::SiGfxNXBuffer::vf29() {
    const Unk_538980* self = reinterpret_cast<const Unk_538980*>(this);
    return self->field_148;
}

// 0x7100538990
u32 SiSDK3::SiGfxNXBuffer::vf23() {
    const Unk_538990* self = reinterpret_cast<const Unk_538990*>(this);
    return self->field_150;
}

// 0x7100538ae0
u32 SiSDK3::SiGfxNXBuffer::vf4() {
    const Unk_538ae0* self = reinterpret_cast<const Unk_538ae0*>(this);
    return self->field_18;
}
