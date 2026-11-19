// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N6SiSDK317SiGfxNXMemoryHeapE
#include <types.h>

struct Unk_5530f0 {
    u8 _0[0x18];
    u32 field_18;
};
PKMN_OFFSET_ASSERT(Unk_5530f0, field_18, 0x18);

struct Unk_552bc0 {
    u8 _0[0x20];
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_552bc0, field_20, 0x20);

struct Unk_552bd0 {
    u8 _0[0x20];
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_552bd0, field_20, 0x20);

struct Unk_552be0 {
    u8 _0[0x5c];
    u8 field_5c;
};
PKMN_OFFSET_ASSERT(Unk_552be0, field_5c, 0x5c);

struct Unk_552f00 {
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
};

struct Unk_553040 {
    u8 _0[0x80];
    u8 field_80;
};
PKMN_OFFSET_ASSERT(Unk_553040, field_80, 0x80);

struct Unk_552b80 {
    u8 _0[0x28];
    u8 field_28;
};
PKMN_OFFSET_ASSERT(Unk_552b80, field_28, 0x28);

struct Unk_552ba0 {
    u8 _0[0x58];
    u32 field_58;
};
PKMN_OFFSET_ASSERT(Unk_552ba0, field_58, 0x58);

struct Unk_552b90 {
    u8 _0[0x20];
    u8 field_20;
};
PKMN_OFFSET_ASSERT(Unk_552b90, field_20, 0x20);

namespace SiSDK3 {
class SiGfxNXMemoryHeap {
public:
    u32 vf4();
    u64 vf5();
    u64 vf6();
    const u8* vf7();
    void vf10();
    void vf11();
    void vf12();
    void vf13();
    void vf14();
    void vf15();
    const u8* vf16();
    const u8* vf18();
    u32 vf19();
    const u8* vf3();
};
}  // namespace SiSDK3

// 0x7100552b80
const u8* SiSDK3::SiGfxNXMemoryHeap::vf18() {
    const Unk_552b80* self = reinterpret_cast<const Unk_552b80*>(this);
    return &self->field_28;
}

// 0x7100552b90
const u8* SiSDK3::SiGfxNXMemoryHeap::vf3() {
    const Unk_552b90* self = reinterpret_cast<const Unk_552b90*>(this);
    return &self->field_20;
}

// 0x7100552ba0
u32 SiSDK3::SiGfxNXMemoryHeap::vf19() {
    const Unk_552ba0* self = reinterpret_cast<const Unk_552ba0*>(this);
    return self->field_58;
}

// 0x7100552bc0
u64 SiSDK3::SiGfxNXMemoryHeap::vf5() {
    const Unk_552bc0* self = reinterpret_cast<const Unk_552bc0*>(this);
    return self->field_20;
}

// 0x7100552bd0
u64 SiSDK3::SiGfxNXMemoryHeap::vf6() {
    const Unk_552bd0* self = reinterpret_cast<const Unk_552bd0*>(this);
    return self->field_20;
}

// 0x7100552be0
const u8* SiSDK3::SiGfxNXMemoryHeap::vf7() {
    const Unk_552be0* self = reinterpret_cast<const Unk_552be0*>(this);
    return &self->field_5c;
}

// 0x7100552ef0
void SiSDK3::SiGfxNXMemoryHeap::vf10() {
}

// 0x7100552f00
void SiSDK3::SiGfxNXMemoryHeap::vf11() {
    Unk_552f00* self = reinterpret_cast<Unk_552f00*>(this);
    self->vf9();
}

// 0x7100552f10
void SiSDK3::SiGfxNXMemoryHeap::vf12() {
}

// 0x7100552f20
void SiSDK3::SiGfxNXMemoryHeap::vf13() {
}

// 0x7100552f30
void SiSDK3::SiGfxNXMemoryHeap::vf14() {
}

// 0x7100552f40
void SiSDK3::SiGfxNXMemoryHeap::vf15() {
}

// 0x7100553040
const u8* SiSDK3::SiGfxNXMemoryHeap::vf16() {
    const Unk_553040* self = reinterpret_cast<const Unk_553040*>(this);
    return &self->field_80;
}

// 0x71005530f0
u32 SiSDK3::SiGfxNXMemoryHeap::vf4() {
    const Unk_5530f0* self = reinterpret_cast<const Unk_5530f0*>(this);
    return self->field_18;
}
