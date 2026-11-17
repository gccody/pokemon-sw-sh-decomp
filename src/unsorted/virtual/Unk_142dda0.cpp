// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_14302c0(void* self);
void Unk_1430b90(void* self);
void Unk_14314e0(void* self);

class Unk_243a558 {
public:
    virtual ~Unk_243a558();
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

// 0x710142dda0
u32 Unk_243a558::vf20() {
    return 1;
}

// 0x710142ddb0
void Unk_243a558::vf21() {}

// 0x710142ddc0
void Unk_243a558::vf22() {}

class Unk_243a988 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x710142fff0
u32 Unk_243a988::vf0() {
    return 1;
}

class Unk_243a9d0 {
public:
    virtual ~Unk_243a9d0();
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

// 0x7101433690
void Unk_243a9d0::vf6() {
    Unk_14314e0(this);
}

class Unk_243aa68 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71014336c0
void Unk_243aa68::vf5() {
    Unk_14314e0(this);
}

class Unk_243aaa8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71014336d0
void Unk_243aaa8::vf0() {
    Unk_14314e0(this);
}

class Unk_243ab18 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7101434b30
void Unk_243ab18::vf6() {
    Unk_14302c0(this);
}

class Unk_243ab60 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101434ce0
void Unk_243ab60::vf5() {
    Unk_14302c0(this);
}

class Unk_243aba0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101434cf0
void Unk_243aba0::vf0() {
    Unk_14302c0(this);
}

class Unk_243abc8 {
public:
    virtual ~Unk_243abc8();
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

// 0x71014357b0
void Unk_243abc8::vf9() {}

class Unk_243ac98 {
public:
    virtual ~Unk_243ac98();
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

// 0x7101435ee0
void Unk_243ac98::vf6() {
    Unk_1430b90(this);
}

class Unk_243ad00 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101435f10
void Unk_243ad00::vf5() {
    Unk_1430b90(this);
}

class Unk_243ad40 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101435f20
void Unk_243ad40::vf0() {
    Unk_1430b90(this);
}

class Unk_243ad68 {
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

// 0x71014363b0
void Unk_243ad68::vf9() {}

class Unk_243b008 {
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

// 0x7101437ad0
void Unk_243b008::vf9() {}

class Unk_243b0d8 {
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

// 0x71014382f0
void Unk_243b0d8::vf9() {}

class Unk_243b1a8 {
public:
    virtual ~Unk_243b1a8();
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

// 0x71014387f0
void Unk_243b1a8::vf9() {}

class Unk_243b278 {
public:
    virtual ~Unk_243b278();
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

// 0x7101438a50
void Unk_243b278::vf9() {}

class Unk_243b348 {
public:
    virtual ~Unk_243b348();
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
};

// 0x7101439330
void Unk_243b348::vf22() {}
