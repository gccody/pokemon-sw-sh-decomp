// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_240fcf0 {
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
    u8 _8[0x60];
    u16 field_68;
};
PKMN_OFFSET_ASSERT(Unk_240fcf0, field_68, 0x68);

// 0x710109db50
void Unk_240fcf0::vf8() {
    field_68 = 1;
}

class Unk_240fdb0 {
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
    u16 field_8;
};
PKMN_OFFSET_ASSERT(Unk_240fdb0, field_8, 0x8);

// 0x710109e3d0
void Unk_240fdb0::vf2() {}

// 0x710109db60
void Unk_240fdb0::vf11() {
    field_8 = 1;
}

class Unk_240fe28 {
public:
    virtual ~Unk_240fe28();
    virtual void vf2();
    virtual u32 vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6(u64 value);
    virtual u64 vf7();
    virtual u8 vf8();
    virtual void vf9(u32 value);
    virtual u32 vf10();
    virtual void vf11();
    u64 field_8;
    u8 field_10;
    u8 _11[0x3];
    u32 field_14;
};
PKMN_OFFSET_ASSERT(Unk_240fe28, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_240fe28, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_240fe28, field_14, 0x14);

// 0x710109df50
u32 Unk_240fe28::vf3() {
    return 1;
}

// 0x710109e540
void Unk_240fe28::vf5() {
    field_14 = 0;
    field_10 = 1;
}

// 0x710109e550
void Unk_240fe28::vf6(u64 value) {
    field_8 = value;
}

// 0x710109e560
u64 Unk_240fe28::vf7() {
    return field_8;
}

// 0x710109e570
u8 Unk_240fe28::vf8() {
    return field_10;
}

// 0x710109df40
void Unk_240fe28::vf9(u32 value) {
    field_14 = value;
}

// 0x710109df30
u32 Unk_240fe28::vf10() {
    return field_14;
}
