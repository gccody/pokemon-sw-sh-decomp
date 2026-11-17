// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_a6e930(void* self);
void Unk_a70780(void* self);
void Unk_a71770(void* self);
void Unk_a73040(void* self);
void Unk_a741e0(void* self);
void Unk_a76020(void* self);

class Unk_23c5c28 {
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

// 0x7100a6e900
void Unk_23c5c28::vf6() {
    Unk_a6e930(this);
}

// 0x7100a6e6d0
u32 Unk_23c5c28::vf7() {
    return 1;
}

// 0x7100a6e6e0
void Unk_23c5c28::vf8() {}

// 0x7100a6e6f0
void Unk_23c5c28::vf10() {}

class Unk_23c5c90 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100a6e910
void Unk_23c5c90::vf5() {
    Unk_a6e930(this);
}

class Unk_23c5cd0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100a6e920
void Unk_23c5cd0::vf0() {
    Unk_a6e930(this);
}

class Unk_23c5d38 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x7100a6f0d0
u32 Unk_23c5d38::vf0() {
    return 1;
}

class Unk_23c5e18 {
public:
    virtual ~Unk_23c5e18();
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
    virtual u32 vf25();
};

// 0x7100a6fd90
u32 Unk_23c5e18::vf20() {
    return 1;
}

// 0x7100a6fda0
void Unk_23c5e18::vf21() {}

// 0x7100a6fdb0
void Unk_23c5e18::vf22() {}

// 0x7100a6ff90
u32 Unk_23c5e18::vf25() {
    return 1;
}

class Unk_23c5d68 {
public:
    virtual ~Unk_23c5d68();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100a70480
void Unk_23c5d68::vf6() {
    Unk_a70780(this);
}

class Unk_23c5db0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100a704b0
void Unk_23c5db0::vf5() {
    Unk_a70780(this);
}

class Unk_23c5df0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100a704c0
void Unk_23c5df0::vf0() {
    Unk_a70780(this);
}

class Unk_23c5f60 {
public:
    virtual ~Unk_23c5f60();
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

// 0x7100a71700
void Unk_23c5f60::vf6() {
    Unk_a71770(this);
}

// 0x7100a716e0
void Unk_23c5f60::vf9() {}

class Unk_23c5fc8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100a71730
void Unk_23c5fc8::vf5() {
    Unk_a71770(this);
}

class Unk_23c6008 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100a71740
void Unk_23c6008::vf0() {
    Unk_a71770(this);
}

class Unk_23c6030 {
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
};

// 0x7100a72d90
void Unk_23c6030::vf6() {
    Unk_a73040(this);
}

// 0x7100a72850
u32 Unk_23c6030::vf16() {
    return 0;
}

class Unk_23c60c8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100a72ee0
void Unk_23c60c8::vf5() {
    Unk_a73040(this);
}

class Unk_23c6108 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100a72ef0
void Unk_23c6108::vf0() {
    Unk_a73040(this);
}

class Unk_23c6148 {
public:
    virtual ~Unk_23c6148();
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

// 0x7100a74170
void Unk_23c6148::vf6() {
    Unk_a741e0(this);
}

// 0x7100a74150
void Unk_23c6148::vf9() {}

class Unk_23c61b0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100a741a0
void Unk_23c61b0::vf5() {
    Unk_a741e0(this);
}

class Unk_23c61f0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100a741b0
void Unk_23c61f0::vf0() {
    Unk_a741e0(this);
}

class Unk_23c6218 {
public:
    virtual ~Unk_23c6218();
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

// 0x7100a75fb0
void Unk_23c6218::vf6() {
    Unk_a76020(this);
}

// 0x7100a74c10
u32 Unk_23c6218::vf7() {
    return 1;
}

class Unk_23c6280 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100a75fc0
void Unk_23c6280::vf5() {
    Unk_a76020(this);
}

class Unk_23c62c0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100a75fd0
void Unk_23c62c0::vf0() {
    Unk_a76020(this);
}

class Unk_23c6328 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x7100a766d0
u32 Unk_23c6328::vf0() {
    return 7;
}

class Unk_23c6398 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x7100a76f90
u32 Unk_23c6398::vf0() {
    return 1;
}
