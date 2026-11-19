// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_148fee0(void* self);
void Unk_1495000(void* self);
void Unk_149edc0(void* self);
void Unk_149fe90(void* self);
void Unk_14a6450(void* self);
void Unk_14a7d00(void* self);

class Unk_24417c0 {
public:
    virtual ~Unk_24417c0();
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

// 0x710149ed50
void Unk_24417c0::vf6() {
    Unk_149edc0(this);
}

class Unk_2441858 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710149ed80
void Unk_2441858::vf5() {
    Unk_149edc0(this);
}

class Unk_2441898 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710149ed90
void Unk_2441898::vf0() {
    Unk_149edc0(this);
}

class Unk_24418e0 {
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
};

// 0x710149fce0
void Unk_24418e0::vf6() {
    Unk_149fe90(this);
}

class Unk_2441978 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710149fdb0
void Unk_2441978::vf5() {
    Unk_149fe90(this);
}

class Unk_24419b8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710149fdc0
void Unk_24419b8::vf0() {
    Unk_149fe90(this);
}

class Unk_2441a00 {
public:
    virtual ~Unk_2441a00();
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

// 0x71014a1d40
void Unk_2441a00::vf6() {
    Unk_148fee0(this);
}

class Unk_2441a98 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71014a1d70
void Unk_2441a98::vf5() {
    Unk_148fee0(this);
}

class Unk_2441ad8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71014a1d80
void Unk_2441ad8::vf0() {
    Unk_148fee0(this);
}

class Unk_2441b28 {
public:
    virtual ~Unk_2441b28();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual u32 vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
};

// 0x71014a5630
void Unk_2441b28::vf6() {
    Unk_1495000(this);
}

// 0x71014a4290
u32 Unk_2441b28::vf9() {
    return 1;
}

class Unk_2441bc0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71014a5660
void Unk_2441bc0::vf5() {
    Unk_1495000(this);
}

class Unk_2441c00 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71014a5670
void Unk_2441c00::vf0() {
    Unk_1495000(this);
}

class Unk_2441c98 {
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
};

// 0x71014a6260
void Unk_2441c98::vf6() {
    Unk_14a6450(this);
}

class Unk_2441d30 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71014a6350
void Unk_2441d30::vf5() {
    Unk_14a6450(this);
}

class Unk_2441d70 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71014a6360
void Unk_2441d70::vf0() {
    Unk_14a6450(this);
}

class Unk_2441dc0 {
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
};

// 0x71014a7a10
void Unk_2441dc0::vf6() {
    Unk_14a7d00(this);
}

class Unk_2441e58 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71014a7b80
void Unk_2441e58::vf5() {
    Unk_14a7d00(this);
}

class Unk_2441e98 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71014a7b90
void Unk_2441e98::vf0() {
    Unk_14a7d00(this);
}

class Unk_2441f08 {
public:
    virtual ~Unk_2441f08();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8() = 0;
    virtual u32 vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13() = 0;
    virtual void vf14();
    virtual u32 vf15();
    virtual void vf16();
    virtual void vf17() = 0;
    virtual void vf18() = 0;
    virtual void vf19() = 0;
    virtual void vf20() = 0;
    virtual void vf21() = 0;
    virtual void vf22() = 0;
};

// 0x71014a96c0
u32 Unk_2441f08::vf9() {
    return 2;
}

// 0x71014a9360
void Unk_2441f08::vf12() {}

// 0x71014a9590
void Unk_2441f08::vf14() {}

// 0x71014a95a0
u32 Unk_2441f08::vf15() {
    return 0;
}

class Unk_2442038 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual u32 vf2();
};

// 0x71014a97b0
u32 Unk_2442038::vf0() {
    return 0;
}

// 0x71014a97c0
void Unk_2442038::vf1() {}

// 0x71014a97d0
u32 Unk_2442038::vf2() {
    return 0;
}
