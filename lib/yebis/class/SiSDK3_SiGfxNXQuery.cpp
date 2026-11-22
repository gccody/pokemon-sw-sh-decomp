// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N6SiSDK312SiGfxNXQueryE
#include <types.h>

struct Unk_555030 {
    u8 _0[0x18];
    u32 field_18;
};
PKMN_OFFSET_ASSERT(Unk_555030, field_18, 0x18);

struct Unk_554c50 {
    u8 _0[0x20];
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_554c50, field_20, 0x20);

struct Unk_554c60 {
    u8 _0[0x20];
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_554c60, field_20, 0x20);

struct Unk_554c70 {
    u8 _0[0x28];
    u64 field_28;
};
PKMN_OFFSET_ASSERT(Unk_554c70, field_28, 0x28);

struct Unk_554c80 {
    u8 _0[0x64];
    u8 field_64;
};
PKMN_OFFSET_ASSERT(Unk_554c80, field_64, 0x64);

struct Unk_554ca0 {
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

struct Unk_554cf0 {
    u8 _0[0x78];
    u8 field_78;
};
PKMN_OFFSET_ASSERT(Unk_554cf0, field_78, 0x78);

namespace SiSDK3 {
class SiGfxNXQuery {
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
};
}  // namespace SiSDK3

// 0x7100554c50
u64 SiSDK3::SiGfxNXQuery::vf5() {
    const Unk_554c50* self = reinterpret_cast<const Unk_554c50*>(this);
    return self->field_20;
}

// 0x7100554c60
u64 SiSDK3::SiGfxNXQuery::vf6() {
    const Unk_554c60* self = reinterpret_cast<const Unk_554c60*>(this);
    return self->field_20;
}

// 0x7100554c70
u64 SiSDK3::SiGfxNXQuery::vf7() {
    const Unk_554c70* self = reinterpret_cast<const Unk_554c70*>(this);
    return self->field_28;
}

// 0x7100554c80
const u8* SiSDK3::SiGfxNXQuery::vf8() {
    const Unk_554c80* self = reinterpret_cast<const Unk_554c80*>(this);
    return &self->field_64;
}

// 0x7100554c90
void SiSDK3::SiGfxNXQuery::vf9() {
}

// 0x7100554ca0
void SiSDK3::SiGfxNXQuery::vf10() {
    Unk_554ca0* self = reinterpret_cast<Unk_554ca0*>(this);
    self->vf19();
}

// 0x7100554cb0
void SiSDK3::SiGfxNXQuery::vf11() {
}

// 0x7100554cc0
void SiSDK3::SiGfxNXQuery::vf12() {
}

// 0x7100554cd0
void SiSDK3::SiGfxNXQuery::vf13() {
}

// 0x7100554ce0
void SiSDK3::SiGfxNXQuery::vf14() {
}

// 0x7100554cf0
const u8* SiSDK3::SiGfxNXQuery::vf17() {
    const Unk_554cf0* self = reinterpret_cast<const Unk_554cf0*>(this);
    return &self->field_78;
}

// 0x7100554f70
void SiSDK3::SiGfxNXQuery::vf15() {
}

// 0x7100554f80
u32 SiSDK3::SiGfxNXQuery::vf16() {
    return 0;
}

// 0x7100555030
u32 SiSDK3::SiGfxNXQuery::vf4() {
    const Unk_555030* self = reinterpret_cast<const Unk_555030*>(this);
    return self->field_18;
}
