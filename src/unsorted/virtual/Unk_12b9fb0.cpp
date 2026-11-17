// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_12ba950(void* self);
void Unk_12be010(void* self);
void Unk_12c2ef0(void* self);
void Unk_12c6840(void* self);
void Unk_12c70f0(void* self);
void Unk_12c8fc0(void* self);
void Unk_12c97c0(void* self);

class Unk_242c630 {
public:
    virtual ~Unk_242c630();
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
    virtual u32 vf25();
};

// 0x71012b9fb0
void Unk_242c630::vf22() {}

// 0x71012b9fc0
u32 Unk_242c630::vf25() {
    return 1;
}

class Unk_242c7b8 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x71012ba700
u32 Unk_242c7b8::vf0() {
    return 2;
}

class Unk_242c858 {
public:
    virtual ~Unk_242c858();
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

// 0x71012bdf10
void Unk_242c858::vf6() {
    Unk_12be010(this);
}

class Unk_242c8f0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71012bdfd0
void Unk_242c8f0::vf5() {
    Unk_12be010(this);
}

class Unk_242c930 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71012bdfe0
void Unk_242c930::vf0() {
    Unk_12be010(this);
}

class Unk_242c9a0 {
public:
    virtual ~Unk_242c9a0();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x71012bef30
void Unk_242c9a0::vf6() {
    Unk_12ba950(this);
}

class Unk_242c9e8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71012bef60
void Unk_242c9e8::vf5() {
    Unk_12ba950(this);
}

class Unk_242ca28 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71012bef70
void Unk_242ca28::vf0() {
    Unk_12ba950(this);
}

class Unk_242cae8 {
public:
    virtual ~Unk_242cae8();
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

// 0x71012c2e80
void Unk_242cae8::vf6() {
    Unk_12c2ef0(this);
}

class Unk_242cb80 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71012c2eb0
void Unk_242cb80::vf5() {
    Unk_12c2ef0(this);
}

class Unk_242cbc0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71012c2ec0
void Unk_242cbc0::vf0() {
    Unk_12c2ef0(this);
}

class Unk_242cc00 {
public:
    virtual ~Unk_242cc00();
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

// 0x71012c67d0
void Unk_242cc00::vf6() {
    Unk_12c6840(this);
}

// 0x71012c65f0
void Unk_242cc00::vf9() {}

class Unk_242cc68 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71012c6800
void Unk_242cc68::vf5() {
    Unk_12c6840(this);
}

class Unk_242cca8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71012c6810
void Unk_242cca8::vf0() {
    Unk_12c6840(this);
}

class Unk_242cd18 {
public:
    virtual ~Unk_242cd18();
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

// 0x71012c7080
void Unk_242cd18::vf6() {
    Unk_12c70f0(this);
}

// 0x71012c7060
void Unk_242cd18::vf9() {}

class Unk_242cd80 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71012c70b0
void Unk_242cd80::vf5() {
    Unk_12c70f0(this);
}

class Unk_242cdc0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71012c70c0
void Unk_242cdc0::vf0() {
    Unk_12c70f0(this);
}

class Unk_242ce00 {
public:
    virtual ~Unk_242ce00();
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

// 0x71012c8f50
void Unk_242ce00::vf6() {
    Unk_12c8fc0(this);
}

// 0x71012c81c0
void Unk_242ce00::vf9() {}

class Unk_242ce68 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71012c8f80
void Unk_242ce68::vf5() {
    Unk_12c8fc0(this);
}

class Unk_242cea8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71012c8f90
void Unk_242cea8::vf0() {
    Unk_12c8fc0(this);
}

class Unk_242cf00 {
public:
    virtual ~Unk_242cf00();
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

// 0x71012c9790
void Unk_242cf00::vf6() {
    Unk_12c97c0(this);
}

// 0x71012c9420
u32 Unk_242cf00::vf7() {
    return 1;
}

// 0x71012c9780
void Unk_242cf00::vf10() {}

class Unk_242cf68 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71012c97a0
void Unk_242cf68::vf5() {
    Unk_12c97c0(this);
}

class Unk_242cfa8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71012c97b0
void Unk_242cfa8::vf0() {
    Unk_12c97c0(this);
}
