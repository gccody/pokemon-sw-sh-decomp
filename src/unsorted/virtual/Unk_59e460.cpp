// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_5b2f90(void* self);
void Unk_5c1b90(void* self);
void Unk_5cbcf0(void* self);
void Unk_5cc540(void* self);

class Unk_2398480 {
public:
    virtual ~Unk_2398480();
    virtual void vf2() = 0;
    virtual void vf3() = 0;
    virtual void vf4() = 0;
    virtual void vf5() = 0;
};

// 0x710059e460, 0x710059e470
Unk_2398480::~Unk_2398480() {}

class Unk_23984c0 {
public:
    virtual ~Unk_23984c0();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
};

// 0x710059fa50
void Unk_23984c0::vf5() {}

// 0x710059fa60
void Unk_23984c0::vf6() {}

class Unk_2398548 {
public:
    virtual ~Unk_2398548();
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
};

// 0x71005a1180
void Unk_2398548::vf3() {}

// 0x71005a12c0
void Unk_2398548::vf5() {}

// 0x71005a2420
void Unk_2398548::vf7() {}

// 0x71005a28c0
void Unk_2398548::vf12() {}

class Unk_23985e0 {
public:
    virtual ~Unk_23985e0();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual u32 vf7();
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
};

// 0x71005a4e60
void Unk_23985e0::vf3() {}

// 0x71005a5060
void Unk_23985e0::vf5() {}

// 0x71005a6840
u32 Unk_23985e0::vf7() {
    return 0;
}

class Unk_23986b8 {
public:
    virtual ~Unk_23986b8();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x71005a8740, 0x71005a8730
Unk_23986b8::~Unk_23986b8() {}

// 0x71005a8600
void Unk_23986b8::vf3() {}

// 0x71005a8610
void Unk_23986b8::vf4() {}

// 0x71005a8720
void Unk_23986b8::vf6() {}

class Unk_2398700 {
public:
    virtual ~Unk_2398700();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x71005a8d70
void Unk_2398700::vf3() {}

// 0x71005a8e60
void Unk_2398700::vf5() {}

class Unk_2398748 : public Unk_2398480 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
};

// 0x71005a9a40
void Unk_2398748::vf4() {}

// 0x71005a9a50
void Unk_2398748::vf5() {}

class Unk_23987c8 : public Unk_2398480 {
public:
    void vf5() override;
    void vf2() override;
    void vf3() override;
    void vf4() override;
};

// 0x71005abaf0
void Unk_23987c8::vf5() {}

class Unk_2398af8 {
public:
    virtual ~Unk_2398af8();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6() = 0;
    virtual void vf7() = 0;
    virtual void vf8() = 0;
    virtual void vf9() = 0;
    virtual void vf10() = 0;
    virtual void vf11() = 0;
    virtual void vf12() = 0;
    virtual void vf13() = 0;
    virtual void vf14() = 0;
    virtual void vf15() = 0;
    virtual void vf16() = 0;
    virtual void vf17() = 0;
    virtual void vf18() = 0;
    virtual void vf19() = 0;
    virtual void vf20() = 0;
    virtual void vf21() = 0;
    virtual void vf22() = 0;
    virtual void vf23() = 0;
    virtual void vf24() = 0;
    virtual void vf25() = 0;
    virtual void vf26() = 0;
    virtual void vf27() = 0;
    virtual void vf28() = 0;
    virtual void vf29() = 0;
    virtual void vf30() = 0;
    virtual void vf31() = 0;
    virtual void vf32() = 0;
    virtual void vf33() = 0;
};

// 0x71005b2f10
void Unk_2398af8::vf5() {
    Unk_5b2f90(this);
}

class Unk_2398c18 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71005b2f20
void Unk_2398c18::vf0() {
    Unk_5b2f90(this);
}

class Unk_2398df8 {
public:
    virtual ~Unk_2398df8();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x71005bd6b0
void Unk_2398df8::vf2() {}

// 0x71005bd6c0
void Unk_2398df8::vf3() {}

// 0x71005bd750
void Unk_2398df8::vf5() {}

class Unk_2398e40 {
public:
    virtual ~Unk_2398e40();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
};

// 0x71005bdff0
void Unk_2398e40::vf2() {}

// 0x71005be000
void Unk_2398e40::vf3() {}

// 0x71005be010
void Unk_2398e40::vf4() {}

// 0x71005be020
void Unk_2398e40::vf5() {}

// 0x71005be040
void Unk_2398e40::vf6() {}

// 0x71005be2c0
void Unk_2398e40::vf9() {}

class Unk_2398ea0 {
public:
    virtual ~Unk_2398ea0();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void* vf7();
    virtual void vf8();
    virtual void vf9();
};

// 0x71005be7c0
void Unk_2398ea0::vf2() {}

// 0x71005be7d0
void Unk_2398ea0::vf3() {}

// 0x71005be7e0
void Unk_2398ea0::vf4() {}

// 0x71005be7f0
void Unk_2398ea0::vf5() {}

// 0x71005be810
void Unk_2398ea0::vf6() {}

// 0x71005be800
void* Unk_2398ea0::vf7() {
    return nullptr;
}

// 0x71005be820
void Unk_2398ea0::vf8() {}

// 0x71005be830
void Unk_2398ea0::vf9() {}

class Unk_2399080 {
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
};

// 0x71005c19a0
void Unk_2399080::vf6() {
    Unk_5c1b90(this);
}

class Unk_23990d8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71005c1ab0
void Unk_23990d8::vf5() {
    Unk_5c1b90(this);
}

class Unk_2399118 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71005c1ac0
void Unk_2399118::vf0() {
    Unk_5c1b90(this);
}

class Unk_2399140 {
public:
    virtual ~Unk_2399140();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
};

// 0x71005c6850, 0x71005c6860
Unk_2399140::~Unk_2399140() {}

class Unk_23991b0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
};

// 0x71005cbb80
void Unk_23991b0::vf6() {
    Unk_5cbcf0(this);
}

class Unk_2399200 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71005cbc30
void Unk_2399200::vf5() {
    Unk_5cbcf0(this);
}

class Unk_2399240 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71005cbc40
void Unk_2399240::vf0() {
    Unk_5cbcf0(this);
}

class Unk_2399268 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
};

// 0x71005cc210
void Unk_2399268::vf6() {
    Unk_5cc540(this);
}

class Unk_23992b8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71005cc3a0
void Unk_23992b8::vf5() {
    Unk_5cc540(this);
}

class Unk_23992f8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71005cc3b0
void Unk_23992f8::vf0() {
    Unk_5cc540(this);
}

class Unk_2399320 {
public:
    virtual ~Unk_2399320();
    virtual void vf2();
};

// 0x71005cc690, 0x71005cc6a0
Unk_2399320::~Unk_2399320() {}

class Unk_23994d8 {
public:
    virtual ~Unk_23994d8();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8() = 0;
    virtual void vf9();
};

// 0x71005cf860
void Unk_23994d8::vf7() {}
