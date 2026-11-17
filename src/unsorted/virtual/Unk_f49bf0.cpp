// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_f49c60(void* self);
void Unk_f4a7a0(void* self);
void Unk_f4ba90(void* self);
void Unk_f4ce50(void* self);

class Unk_23fdce0 {
public:
    virtual ~Unk_23fdce0();
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

// 0x7100f49bf0
void Unk_23fdce0::vf6() {
    Unk_f49c60(this);
}

class Unk_23fdd78 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100f49c20
void Unk_23fdd78::vf5() {
    Unk_f49c60(this);
}

class Unk_23fddb8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100f49c30
void Unk_23fddb8::vf0() {
    Unk_f49c60(this);
}

class Unk_23fde10 {
public:
    virtual ~Unk_23fde10();
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

// 0x7100f4a730
void Unk_23fde10::vf6() {
    Unk_f4a7a0(this);
}

// 0x7100f4a270
void Unk_23fde10::vf10() {}

// 0x7100f4a280
u32 Unk_23fde10::vf16() {
    return 0;
}

class Unk_23fdea8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100f4a760
void Unk_23fdea8::vf5() {
    Unk_f4a7a0(this);
}

class Unk_23fdee8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100f4a770
void Unk_23fdee8::vf0() {
    Unk_f4a7a0(this);
}

class Unk_23fdf10 {
public:
    virtual ~Unk_23fdf10();
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

// 0x7100f4ba20
void Unk_23fdf10::vf6() {
    Unk_f4ba90(this);
}

// 0x7100f4b290
void Unk_23fdf10::vf10() {}

class Unk_23fdfa8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100f4ba50
void Unk_23fdfa8::vf5() {
    Unk_f4ba90(this);
}

class Unk_23fdfe8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100f4ba60
void Unk_23fdfe8::vf0() {
    Unk_f4ba90(this);
}

class Unk_23fe058 {
public:
    virtual ~Unk_23fe058();
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

// 0x7100f4cde0
void Unk_23fe058::vf6() {
    Unk_f4ce50(this);
}

// 0x7100f4c650
void Unk_23fe058::vf10() {}

class Unk_23fe0f0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100f4ce10
void Unk_23fe0f0::vf5() {
    Unk_f4ce50(this);
}

class Unk_23fe130 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100f4ce20
void Unk_23fe130::vf0() {
    Unk_f4ce50(this);
}
