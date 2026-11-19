// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_58b820 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_58b820, field_10, 0x10);

struct Unk_5886c0 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6(u64, u64, u64);
};

struct Unk_588940 {
    u8 _0[0x20];
    u8 field_20;
};
PKMN_OFFSET_ASSERT(Unk_588940, field_20, 0x20);

struct Unk_588950 {
    u8 _0[0x20];
    u8 field_20;
};
PKMN_OFFSET_ASSERT(Unk_588950, field_20, 0x20);

struct Unk_589030 {
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
    virtual void vf23(u32);
};

struct Unk_58a7e0 {
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
    virtual void vf46(u64, u32);
};

struct Unk_58b840 {
    u8 _0[0x24];
    u32 field_24;
    u32 field_28;
};
PKMN_OFFSET_ASSERT(Unk_58b840, field_24, 0x24);
PKMN_OFFSET_ASSERT(Unk_58b840, field_28, 0x28);

struct Unk_58b750 {
    u8 _0[0x90];
    u64 field_90;
};
PKMN_OFFSET_ASSERT(Unk_58b750, field_90, 0x90);

struct Unk_58b760 {
    u8 _0[0x90];
    u64 field_90;
};
PKMN_OFFSET_ASSERT(Unk_58b760, field_90, 0x90);

struct Unk_58b630 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_58b630, field_18, 0x18);

struct Unk_58b640 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_58b640, field_18, 0x18);

struct Unk_58b650 {
    u8 _0[0x30];
    u8 field_30;
};
PKMN_OFFSET_ASSERT(Unk_58b650, field_30, 0x30);

struct Unk_58b660 {
    u8 _0[0x60];
    u8 field_60;
};
PKMN_OFFSET_ASSERT(Unk_58b660, field_60, 0x60);

namespace SiSDK3 {
class SiIONXFileStream {
public:
    u32 vf4();
    u32 vf5();
    void vf7(u64 value, u64 arg2, u64 arg3);
    u32 vf11();
    u32 vf12();
    void vf25(bool value);
    void vf48(u64 value, bool arg2);
    bool vf71();
    u64 vf73();
    u64 vf74();
    u64 vf75();
    u64 vf76();
    const u8* vf77();
    const u8* vf78();
    u32 vf80();
    u32 vf81();
};
}  // namespace SiSDK3

// 0x71005886c0
void SiSDK3::SiIONXFileStream::vf7(u64 value, u64 arg2, u64 arg3) {
    Unk_5886c0* self = reinterpret_cast<Unk_5886c0*>(this);
    self->vf6(value, arg2, arg3);
}

// 0x7100588940
u32 SiSDK3::SiIONXFileStream::vf11() {
    const Unk_588940* self = reinterpret_cast<const Unk_588940*>(this);
    return (self->field_20 >> 3) & 1;
}

// 0x7100588950
u32 SiSDK3::SiIONXFileStream::vf12() {
    const Unk_588950* self = reinterpret_cast<const Unk_588950*>(this);
    return (self->field_20 >> 4) & 1;
}

// 0x7100589030
void SiSDK3::SiIONXFileStream::vf25(bool value) {
    Unk_589030* self = reinterpret_cast<Unk_589030*>(this);
    self->vf23(value);
}

// 0x710058a7e0
void SiSDK3::SiIONXFileStream::vf48(u64 value, bool arg2) {
    Unk_58a7e0* self = reinterpret_cast<Unk_58a7e0*>(this);
    self->vf46(value, arg2);
}

// 0x710058b630
u64 SiSDK3::SiIONXFileStream::vf75() {
    const Unk_58b630* self = reinterpret_cast<const Unk_58b630*>(this);
    return self->field_18;
}

// 0x710058b640
u64 SiSDK3::SiIONXFileStream::vf76() {
    const Unk_58b640* self = reinterpret_cast<const Unk_58b640*>(this);
    return self->field_18;
}

// 0x710058b650
const u8* SiSDK3::SiIONXFileStream::vf77() {
    const Unk_58b650* self = reinterpret_cast<const Unk_58b650*>(this);
    return &self->field_30;
}

// 0x710058b660
const u8* SiSDK3::SiIONXFileStream::vf78() {
    const Unk_58b660* self = reinterpret_cast<const Unk_58b660*>(this);
    return &self->field_60;
}

// 0x710058b730
u32 SiSDK3::SiIONXFileStream::vf80() {
    return 0;
}

// 0x710058b740
u32 SiSDK3::SiIONXFileStream::vf81() {
    return 0;
}

// 0x710058b750
u64 SiSDK3::SiIONXFileStream::vf73() {
    const Unk_58b750* self = reinterpret_cast<const Unk_58b750*>(this);
    return self->field_90;
}

// 0x710058b760
u64 SiSDK3::SiIONXFileStream::vf74() {
    const Unk_58b760* self = reinterpret_cast<const Unk_58b760*>(this);
    return self->field_90;
}

// 0x710058b820
u32 SiSDK3::SiIONXFileStream::vf4() {
    const Unk_58b820* self = reinterpret_cast<const Unk_58b820*>(this);
    return self->field_10;
}

// 0x710058b830
u32 SiSDK3::SiIONXFileStream::vf5() {
    return 1;
}

// 0x710058b840
bool SiSDK3::SiIONXFileStream::vf71() {
    const Unk_58b840* self = reinterpret_cast<const Unk_58b840*>(this);
    return self->field_28 != self->field_24;
}
