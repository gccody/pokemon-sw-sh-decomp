// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_c2a3e0(void* self);
void Unk_c2c3b0(void* self);
void Unk_c2c8a0(void* self);
void Unk_c2cd70(void* self);
void Unk_c33460(void* self);
void Unk_c38220(void* self);

class Unk_23da2b0 {
public:
    virtual ~Unk_23da2b0();
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

// 0x7100c2a370
void Unk_23da2b0::vf6() {
    Unk_c2a3e0(this);
}

class Unk_23da318 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100c2a3a0
void Unk_23da318::vf5() {
    Unk_c2a3e0(this);
}

class Unk_23da358 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100c2a3b0
void Unk_23da358::vf0() {
    Unk_c2a3e0(this);
}

class Unk_23da398 {
public:
    virtual ~Unk_23da398();
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

// 0x7100c2c340
void Unk_23da398::vf6() {
    Unk_c2c3b0(this);
}

class Unk_23da400 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100c2c370
void Unk_23da400::vf5() {
    Unk_c2c3b0(this);
}

class Unk_23da440 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100c2c380
void Unk_23da440::vf0() {
    Unk_c2c3b0(this);
}

class Unk_23da498 {
public:
    virtual ~Unk_23da498();
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

// 0x7100c2c830
void Unk_23da498::vf6() {
    Unk_c2c8a0(this);
}

class Unk_23da500 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100c2c860
void Unk_23da500::vf5() {
    Unk_c2c8a0(this);
}

class Unk_23da540 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100c2c870
void Unk_23da540::vf0() {
    Unk_c2c8a0(this);
}

class Unk_23da568 {
public:
    virtual ~Unk_23da568();
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

// 0x7100c2cd00
void Unk_23da568::vf6() {
    Unk_c2cd70(this);
}

class Unk_23da5d0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100c2cd30
void Unk_23da5d0::vf5() {
    Unk_c2cd70(this);
}

class Unk_23da610 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100c2cd40
void Unk_23da610::vf0() {
    Unk_c2cd70(this);
}

class Unk_23da768 {
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
    virtual u32 vf10();
    u8 _8[0xe0];
    u32 field_e8;
};
PKMN_OFFSET_ASSERT(Unk_23da768, field_e8, 0xe8);

// 0x7100c2d6f0
u32 Unk_23da768::vf10() {
    return field_e8;
}

class Unk_23da838 {
public:
    virtual ~Unk_23da838();
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

// 0x7100c333f0
void Unk_23da838::vf6() {
    Unk_c33460(this);
}

class Unk_23da8a0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100c33420
void Unk_23da8a0::vf5() {
    Unk_c33460(this);
}

class Unk_23da8e0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100c33430
void Unk_23da8e0::vf0() {
    Unk_c33460(this);
}

class Unk_23da950 {
public:
    virtual ~Unk_23da950();
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
};

// 0x7100c36430
void Unk_23da950::vf16() {}

// 0x7100c36440
void Unk_23da950::vf41() {}

class Unk_23daae0 {
public:
    virtual ~Unk_23daae0();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100c364e0
void Unk_23daae0::vf4() {}

class Unk_23dab28 {
public:
    virtual ~Unk_23dab28();
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

// 0x7100c38040
void Unk_23dab28::vf6() {
    Unk_c38220(this);
}

// 0x7100c38050
u32 Unk_23dab28::vf7() {
    return 1;
}

// 0x7100c37d70
void Unk_23dab28::vf10() {}

class Unk_23dab90 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100c38080
void Unk_23dab90::vf5() {
    Unk_c38220(this);
}

class Unk_23dabd0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100c38090
void Unk_23dabd0::vf0() {
    Unk_c38220(this);
}
