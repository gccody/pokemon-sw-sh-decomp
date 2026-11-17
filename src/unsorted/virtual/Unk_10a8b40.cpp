// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_24112a8 {
public:
    virtual ~Unk_24112a8();
    virtual void vf2() = 0;
    virtual void vf3() = 0;
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
PKMN_OFFSET_ASSERT(Unk_24112a8, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_24112a8, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_24112a8, field_14, 0x14);

// 0x71010a8d70
void Unk_24112a8::vf5() {
    field_14 = 0;
    field_10 = 1;
}

// 0x71010a8d80
void Unk_24112a8::vf6(u64 value) {
    field_8 = value;
}

// 0x71010a8d90
u64 Unk_24112a8::vf7() {
    return field_8;
}

// 0x71010a8da0
u8 Unk_24112a8::vf8() {
    return field_10;
}

// 0x71010a8b50
void Unk_24112a8::vf9(u32 value) {
    field_14 = value;
}

// 0x71010a8b40
u32 Unk_24112a8::vf10() {
    return field_14;
}

class Unk_24111a8 {
public:
    virtual ~Unk_24111a8();
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
    virtual void vf12(u32 value);
    virtual void vf13();
    u8 _8[0xc];
    u32 field_14;
    u8 _18[0x2a];
    u8 field_42;
};
PKMN_OFFSET_ASSERT(Unk_24111a8, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_24111a8, field_42, 0x42);

// 0x71010a8b60
u32 Unk_24111a8::vf3() {
    return 1;
}

// 0x71010a8b70
void Unk_24111a8::vf12(u32 value) {
    field_42 = value == 0x914;
    field_14 = 2;
}

class Unk_2411228 {
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
};

// 0x71010a8db0
void Unk_2411228::vf0() {}
