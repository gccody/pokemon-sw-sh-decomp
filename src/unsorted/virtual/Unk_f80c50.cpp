// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_f82850(void* self);

class Unk_2400900 {
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
};

// 0x7100f80c50
void Unk_2400900::vf8() {}

struct Unk_2400a60_130 {
    u8 _0[0x608];
    u64 field_608;
};
PKMN_OFFSET_ASSERT(Unk_2400a60_130, field_608, 0x608);

class Unk_2400a60 {
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
    u8 _8[0x128];
    Unk_2400a60_130* field_130;
};
PKMN_OFFSET_ASSERT(Unk_2400a60, field_130, 0x130);

// 0x7100f824a0
void Unk_2400a60::vf6() {
    Unk_f82850(this);
}

// 0x7100f818b0
void Unk_2400a60::vf9() {
    field_130->field_608 = 0;
}

class Unk_2400ad0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100f825d0
void Unk_2400ad0::vf5() {
    Unk_f82850(this);
}

class Unk_2400b10 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100f825e0
void Unk_2400b10::vf0() {
    Unk_f82850(this);
}

class Unk_2400d50 {
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
    virtual u32 vf18();
    virtual void vf19();
};

// 0x7100f855a0
u32 Unk_2400d50::vf18() {
    return 0;
}

// 0x7100f85410
void Unk_2400d50::vf19() {}

class Unk_2400e68 {
public:
    virtual void vf0();
};

// 0x7100f85420
void Unk_2400e68::vf0() {}
