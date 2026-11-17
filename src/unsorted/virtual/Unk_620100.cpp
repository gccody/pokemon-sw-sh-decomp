// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_59b970(void* self);
void Unk_61e5b0(void* self);
void Unk_634540(void* self);
void Unk_64c9b0(void* self);
void Unk_64d460(void* self);
void Unk_64f430(void* self);
void Unk_65b030(void* self);
void Unk_699410(void* self);

class Unk_239cfd0 {
public:
    virtual ~Unk_239cfd0();
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
    virtual void vf16() = 0;
    virtual void vf17() = 0;
};

// 0x7100620100
void Unk_239cfd0::vf6() {
    Unk_61e5b0(this);
}

// 0x7100620110
void Unk_239cfd0::vf15() {}

class Unk_239d070 {
public:
    virtual ~Unk_239d070();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100620140
void Unk_239d070::vf5() {
    Unk_61e5b0(this);
}

class Unk_239d0b0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100620150
void Unk_239d0b0::vf0() {
    Unk_61e5b0(this);
}

class Unk_239d210 {
public:
    virtual ~Unk_239d210();
    virtual void vf2();
    virtual void vf3();
    virtual u32 vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
};

// 0x7100622350
u32 Unk_239d210::vf4() {
    return 2;
}

class Unk_239dbe0 {
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
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
};

// 0x7100634530
void Unk_239dbe0::vf12() {
    Unk_634540(this);
}

class Unk_239eab0 {
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

// 0x710064c010
void Unk_239eab0::vf6() {
    Unk_64c9b0(this);
}

class Unk_239eb30 {
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

// 0x710064c1a0
void Unk_239eb30::vf5() {
    Unk_64c9b0(this);
}

class Unk_239eba0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710064c1b0
void Unk_239eba0::vf0() {
    Unk_64c9b0(this);
}

class Unk_239ed38 {
public:
    virtual ~Unk_239ed38();
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

// 0x710064d3b0
void Unk_239ed38::vf6() {
    Unk_64d460(this);
}

class Unk_239edb8 {
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

// 0x710064d3e0
void Unk_239edb8::vf5() {
    Unk_64d460(this);
}

class Unk_239ee28 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710064d3f0
void Unk_239ee28::vf0() {
    Unk_64d460(this);
}

class Unk_239ee90 {
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

// 0x710064d9e0
void Unk_239ee90::vf6() {
    Unk_699410(this);
}

class Unk_239ef10 {
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

// 0x710064db70
void Unk_239ef10::vf5() {
    Unk_699410(this);
}

class Unk_239ef80 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710064db80
void Unk_239ef80::vf0() {
    Unk_699410(this);
}

class Unk_239f010 {
public:
    virtual ~Unk_239f010();
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

// 0x710064f400
void Unk_239f010::vf6() {
    Unk_64f430(this);
}

class Unk_239f090 {
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

// 0x710064f410
void Unk_239f090::vf5() {
    Unk_64f430(this);
}

class Unk_239f100 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710064f420
void Unk_239f100::vf0() {
    Unk_64f430(this);
}

class Unk_239f208 {
public:
    virtual ~Unk_239f208();
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

// 0x7100652e40
void Unk_239f208::vf15() {
    Unk_59b970(this);
}

class Unk_239f770 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x710065aa90
void Unk_239f770::vf6() {
    Unk_65b030(this);
}

class Unk_239f7b8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710065abc0
void Unk_239f7b8::vf5() {
    Unk_65b030(this);
}

class Unk_239f7f8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710065abd0
void Unk_239f7f8::vf0() {
    Unk_65b030(this);
}
