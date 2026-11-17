// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_8e5870(void* self);
void Unk_8e82a0(void* self);
void Unk_8e8e50(void* self);

class Unk_23bc860 {
public:
    virtual ~Unk_23bc860();
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
    virtual u32 vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
};

// 0x71008e4150
u32 Unk_23bc860::vf20() {
    return 1;
}

// 0x71008e4a50
void Unk_23bc860::vf22() {}

class Unk_23bc9a8 {
public:
    virtual ~Unk_23bc9a8();
    virtual void vf2();
    virtual u64 vf3();
    virtual void vf4();
    virtual void vf5();
    u8 _8[0x50];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_23bc9a8, field_58, 0x58);

// 0x71008e54e0
u64 Unk_23bc9a8::vf3() {
    return field_58;
}

class Unk_23bc9e8 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x71008e5650
u32 Unk_23bc9e8::vf0() {
    return 1;
}

class Unk_23bcb40 {
public:
    virtual ~Unk_23bcb40();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x71008e6fa0
void Unk_23bcb40::vf6() {
    Unk_8e5870(this);
}

class Unk_23bcb88 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71008e6fd0
void Unk_23bcb88::vf5() {
    Unk_8e5870(this);
}

class Unk_23bcbc8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71008e6fe0
void Unk_23bcbc8::vf0() {
    Unk_8e5870(this);
}

class Unk_23bcc08 {
public:
    virtual ~Unk_23bcc08();
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

// 0x71008e8230
void Unk_23bcc08::vf6() {
    Unk_8e82a0(this);
}

class Unk_23bcca0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71008e8260
void Unk_23bcca0::vf5() {
    Unk_8e82a0(this);
}

class Unk_23bcce0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71008e8270
void Unk_23bcce0::vf0() {
    Unk_8e82a0(this);
}

class Unk_23bcd20 {
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

// 0x71008e87e0
void Unk_23bcd20::vf6() {
    Unk_8e8e50(this);
}

// 0x71008e8730
void Unk_23bcd20::vf9() {}

class Unk_23bcd88 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71008e8930
void Unk_23bcd88::vf5() {
    Unk_8e8e50(this);
}

class Unk_23bcdc8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71008e8940
void Unk_23bcdc8::vf0() {
    Unk_8e8e50(this);
}

class Unk_23bcec0 {
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

// 0x71008e9560
void Unk_23bcec0::vf9() {}

class Unk_23bcf90 {
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

// 0x71008e9910
void Unk_23bcf90::vf9() {}

class Unk_23bd060 {
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

// 0x71008e9d50
void Unk_23bd060::vf9() {}

class Unk_23bd130 {
public:
    virtual ~Unk_23bd130();
    virtual void vf2();
};

// 0x71008eb220, 0x71008eb1f0
Unk_23bd130::~Unk_23bd130() {}
