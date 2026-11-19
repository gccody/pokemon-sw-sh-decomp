// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_b2d2b0(void* self);

class Unk_23cea48 {
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
    u8 _8[0x7c];
    u32 field_84;
};
PKMN_OFFSET_ASSERT(Unk_23cea48, field_84, 0x84);

// 0x7100b2d2a0
void Unk_23cea48::vf8() {
    Unk_b2d2b0(this);
}

// 0x7100b2d500
void Unk_23cea48::vf9() {}

// 0x7100b2d510
void Unk_23cea48::vf11() {
    field_84 = 3;
}

// 0x7100b2d530
void Unk_23cea48::vf12() {
    field_84 = 4;
}

// 0x7100b2d550
void Unk_23cea48::vf13() {
    field_84 = 4;
}

// 0x7100b2d570
void Unk_23cea48::vf14() {
    field_84 = 4;
}

class Unk_23ceb40 {
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
    u8 _8[0x4];
    u32 field_c;
};
PKMN_OFFSET_ASSERT(Unk_23ceb40, field_c, 0xc);

// 0x7100b2d520
void Unk_23ceb40::vf2() {
    field_c = 3;
}

// 0x7100b2d540
void Unk_23ceb40::vf4() {
    field_c = 4;
}

// 0x7100b2d560
void Unk_23ceb40::vf5() {
    field_c = 4;
}

// 0x7100b2d580
void Unk_23ceb40::vf6() {
    field_c = 4;
}

class Unk_23ceba0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual u32 vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
};

// 0x7100b2dd00
u32 Unk_23ceba0::vf7() {
    return 1;
}

// 0x7100b2dd10
void Unk_23ceba0::vf8() {}
