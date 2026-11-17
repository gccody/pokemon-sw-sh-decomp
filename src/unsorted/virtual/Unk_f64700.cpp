// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_f64ab0(void* self);
void Unk_f6ed70(void* self);
void Unk_f73ae0(void* self);
void Unk_f75ac0(void* self);

class Unk_23ff0f0 {
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
};

// 0x7100f648c0
void Unk_23ff0f0::vf6() {
    Unk_f64ab0(this);
}

// 0x7100f64700
void Unk_23ff0f0::vf9() {}

class Unk_23ff158 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100f649b0
void Unk_23ff158::vf5() {
    Unk_f64ab0(this);
}

class Unk_23ff198 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100f649c0
void Unk_23ff198::vf0() {
    Unk_f64ab0(this);
}

class Unk_23ff270 {
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
    virtual u32 vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
};

// 0x7100f67830
u32 Unk_23ff270::vf16() {
    return 1;
}

struct Unk_23ff9f0_98 {
    u8 _0[0x648];
    u64 field_648;
};
PKMN_OFFSET_ASSERT(Unk_23ff9f0_98, field_648, 0x648);

class Unk_23ff9f0 {
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
    u8 _8[0x90];
    Unk_23ff9f0_98* field_98;
};
PKMN_OFFSET_ASSERT(Unk_23ff9f0, field_98, 0x98);

// 0x7100f6e8c0
void Unk_23ff9f0::vf6() {
    Unk_f6ed70(this);
}

// 0x7100f6de90
void Unk_23ff9f0::vf9() {
    field_98->field_648 = 0;
}

class Unk_23ffa68 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100f6ea50
void Unk_23ffa68::vf5() {
    Unk_f6ed70(this);
}

class Unk_23ffaa8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100f6ea60
void Unk_23ffaa8::vf0() {
    Unk_f6ed70(this);
}

class Unk_23ffd30 {
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
};

// 0x7100f738f0
void Unk_23ffd30::vf6() {
    Unk_f73ae0(this);
}

// 0x7100f73800
void Unk_23ffd30::vf9() {}

class Unk_23ffd98 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100f739e0
void Unk_23ffd98::vf5() {
    Unk_f73ae0(this);
}

class Unk_23ffdd8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100f739f0
void Unk_23ffdd8::vf0() {
    Unk_f73ae0(this);
}

class Unk_23fff88 {
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
};

// 0x7100f75770
void Unk_23fff88::vf6() {
    Unk_f75ac0(this);
}

// 0x7100f755c0
void Unk_23fff88::vf9() {}

// 0x7100f755d0
void Unk_23fff88::vf11() {}

class Unk_2400060 {
public:
    virtual void vf0();
};

// 0x7100f755e0
void Unk_2400060::vf0() {}

class Unk_23ffff8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100f75900
void Unk_23ffff8::vf5() {
    Unk_f75ac0(this);
}

class Unk_2400038 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100f75910
void Unk_2400038::vf0() {
    Unk_f75ac0(this);
}
