// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N6SiSDK313SiGfxNXCanvasE
// (The class's other functions are SiGfx_NX_Canvas_Impl.cpp's.)
#include <types.h>

struct Unk_4fe110 {
    u8 _0[0x18];
    u32 field_18;
};
PKMN_OFFSET_ASSERT(Unk_4fe110, field_18, 0x18);

struct Unk_4fcb60 {
    u8 _0[0x20];
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_4fcb60, field_20, 0x20);

struct Unk_4fcb70 {
    u8 _0[0x20];
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_4fcb70, field_20, 0x20);

struct Unk_4fcb80 {
    u8 _0[0x28];
    u64 field_28;
};
PKMN_OFFSET_ASSERT(Unk_4fcb80, field_28, 0x28);

struct Unk_4fcb90 {
    u8 _0[0x6c];
    u8 field_6c;
};
PKMN_OFFSET_ASSERT(Unk_4fcb90, field_6c, 0x6c);

struct Unk_4fcbb0 {
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
};

struct Unk_4fcc00 {
    u8 _0[0x80];
    u8 field_80;
};
PKMN_OFFSET_ASSERT(Unk_4fcc00, field_80, 0x80);

struct Unk_4fcf40 {
    u8 _0[0xc0];
    u8 field_c0;
};
PKMN_OFFSET_ASSERT(Unk_4fcf40, field_c0, 0xc0);

struct Unk_4fcf50 {
    u8 _0[0x30];
    u64 field_30;
};
PKMN_OFFSET_ASSERT(Unk_4fcf50, field_30, 0x30);

struct Unk_4fd020 {
    u8 _0[0x10c];
    u8 field_10c;
};
PKMN_OFFSET_ASSERT(Unk_4fd020, field_10c, 0x10c);

struct Unk_4fd070 {
    u8 _0[0x140];
    u64 field_140;
};
PKMN_OFFSET_ASSERT(Unk_4fd070, field_140, 0x140);

struct Unk_4fdc90 {
    u8 _0[0x10d];
    bool field_10d;
};
PKMN_OFFSET_ASSERT(Unk_4fdc90, field_10d, 0x10d);

struct Unk_4fdca0 {
    u8 _0[0x10d];
    u8 field_10d;
};
PKMN_OFFSET_ASSERT(Unk_4fdca0, field_10d, 0x10d);

struct Unk_4fdcb0 {
    u8 _0[0x108];
    u32 field_108;
};
PKMN_OFFSET_ASSERT(Unk_4fdcb0, field_108, 0x108);

struct Unk_4fdcc0 {
    u8 _0[0x114];
    u32 field_114;
};
PKMN_OFFSET_ASSERT(Unk_4fdcc0, field_114, 0x114);

struct Unk_4fdcd0 {
    u8 _0[0x118];
    u32 field_118;
};
PKMN_OFFSET_ASSERT(Unk_4fdcd0, field_118, 0x118);

struct Unk_4fe010_140 {
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
    virtual void vf24(u64);
};

struct Unk_4fe010 {
    u8 _0[0x140];
    Unk_4fe010_140* field_140;
};
PKMN_OFFSET_ASSERT(Unk_4fe010, field_140, 0x140);

struct Unk_4fe120 {
    u8 _0[0x198];
    u64 field_198;
};
PKMN_OFFSET_ASSERT(Unk_4fe120, field_198, 0x198);

namespace SiSDK3 {
class SiGfxNXCanvas {
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
    u32 vf18();
    const u8* vf20();
    u64 vf21();
    u8 vf23();
    u64 vf25();
    void vf27(bool value);
    u8 vf28();
    u32 vf29();
    u32 vf30();
    u32 vf31();
    void vf45(u64 value);
    u32 vf46();
    u32 vf47();
    u64 vf48();
};
}  // namespace SiSDK3

// 0x71004fcb60
u64 SiSDK3::SiGfxNXCanvas::vf5() {
    const Unk_4fcb60* self = reinterpret_cast<const Unk_4fcb60*>(this);
    return self->field_20;
}

// 0x71004fcb70
u64 SiSDK3::SiGfxNXCanvas::vf6() {
    const Unk_4fcb70* self = reinterpret_cast<const Unk_4fcb70*>(this);
    return self->field_20;
}

// 0x71004fcb80
u64 SiSDK3::SiGfxNXCanvas::vf7() {
    const Unk_4fcb80* self = reinterpret_cast<const Unk_4fcb80*>(this);
    return self->field_28;
}

// 0x71004fcb90
const u8* SiSDK3::SiGfxNXCanvas::vf8() {
    const Unk_4fcb90* self = reinterpret_cast<const Unk_4fcb90*>(this);
    return &self->field_6c;
}

// 0x71004fcba0
void SiSDK3::SiGfxNXCanvas::vf9() {
}

// 0x71004fcbb0
void SiSDK3::SiGfxNXCanvas::vf10() {
    Unk_4fcbb0* self = reinterpret_cast<Unk_4fcbb0*>(this);
    self->vf19();
}

// 0x71004fcbc0
void SiSDK3::SiGfxNXCanvas::vf11() {
}

// 0x71004fcbd0
void SiSDK3::SiGfxNXCanvas::vf12() {
}

// 0x71004fcbe0
void SiSDK3::SiGfxNXCanvas::vf13() {
}

// 0x71004fcbf0
void SiSDK3::SiGfxNXCanvas::vf14() {
}

// 0x71004fcc00
const u8* SiSDK3::SiGfxNXCanvas::vf17() {
    const Unk_4fcc00* self = reinterpret_cast<const Unk_4fcc00*>(this);
    return &self->field_80;
}

// 0x71004fcc10
u32 SiSDK3::SiGfxNXCanvas::vf18() {
    return 1;
}

// 0x71004fcf40
const u8* SiSDK3::SiGfxNXCanvas::vf20() {
    const Unk_4fcf40* self = reinterpret_cast<const Unk_4fcf40*>(this);
    return &self->field_c0;
}

// 0x71004fcf50
u64 SiSDK3::SiGfxNXCanvas::vf21() {
    const Unk_4fcf50* self = reinterpret_cast<const Unk_4fcf50*>(this);
    return self->field_30;
}

// 0x71004fd020
u8 SiSDK3::SiGfxNXCanvas::vf23() {
    const Unk_4fd020* self = reinterpret_cast<const Unk_4fd020*>(this);
    return self->field_10c;
}

// 0x71004fd070
u64 SiSDK3::SiGfxNXCanvas::vf25() {
    const Unk_4fd070* self = reinterpret_cast<const Unk_4fd070*>(this);
    return self->field_140;
}

// 0x71004fdc90
void SiSDK3::SiGfxNXCanvas::vf27(bool value) {
    Unk_4fdc90* self = reinterpret_cast<Unk_4fdc90*>(this);
    self->field_10d = value;
}

// 0x71004fdca0
u8 SiSDK3::SiGfxNXCanvas::vf28() {
    const Unk_4fdca0* self = reinterpret_cast<const Unk_4fdca0*>(this);
    return self->field_10d;
}

// 0x71004fdcb0
u32 SiSDK3::SiGfxNXCanvas::vf29() {
    const Unk_4fdcb0* self = reinterpret_cast<const Unk_4fdcb0*>(this);
    return self->field_108;
}

// 0x71004fdcc0
u32 SiSDK3::SiGfxNXCanvas::vf30() {
    const Unk_4fdcc0* self = reinterpret_cast<const Unk_4fdcc0*>(this);
    return self->field_114;
}

// 0x71004fdcd0
u32 SiSDK3::SiGfxNXCanvas::vf31() {
    const Unk_4fdcd0* self = reinterpret_cast<const Unk_4fdcd0*>(this);
    return self->field_118;
}

// 0x71004fe010
void SiSDK3::SiGfxNXCanvas::vf45(u64 value) {
    const Unk_4fe010* self = reinterpret_cast<const Unk_4fe010*>(this);
    if (self->field_140 != nullptr) {
        self->field_140->vf24(value);
    }
}

// 0x71004fe030
u32 SiSDK3::SiGfxNXCanvas::vf46() {
    return 0;
}

// 0x71004fe040
u32 SiSDK3::SiGfxNXCanvas::vf47() {
    return 0;
}

// 0x71004fe050
void SiSDK3::SiGfxNXCanvas::vf15() {
}

// 0x71004fe060
u32 SiSDK3::SiGfxNXCanvas::vf16() {
    return 0;
}

// 0x71004fe110
u32 SiSDK3::SiGfxNXCanvas::vf4() {
    const Unk_4fe110* self = reinterpret_cast<const Unk_4fe110*>(this);
    return self->field_18;
}

// 0x71004fe120
u64 SiSDK3::SiGfxNXCanvas::vf48() {
    const Unk_4fe120* self = reinterpret_cast<const Unk_4fe120*>(this);
    return self->field_198;
}
