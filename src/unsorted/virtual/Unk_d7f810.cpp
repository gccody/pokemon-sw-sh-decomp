// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_d842c0(void* self);
void Unk_d84970(void* self);

class Unk_23edc60 {
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

// 0x7100d7f810
u32 Unk_23edc60::vf7() {
    return 1;
}

// 0x7100d81c20
void Unk_23edc60::vf10() {}

class Unk_23ede30 {
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

// 0x7100d84290
void Unk_23ede30::vf6() {
    Unk_d842c0(this);
}

// 0x7100d83f40
u32 Unk_23ede30::vf7() {
    return 1;
}

class Unk_23ede98 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100d842a0
void Unk_23ede98::vf5() {
    Unk_d842c0(this);
}

class Unk_23eded8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100d842b0
void Unk_23eded8::vf0() {
    Unk_d842c0(this);
}

class Unk_23edf00 {
public:
    virtual ~Unk_23edf00();
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

// 0x7100d84900
void Unk_23edf00::vf6() {
    Unk_d84970(this);
}

// 0x7100d84440
u32 Unk_23edf00::vf7() {
    return 1;
}

// 0x7100d84450
void Unk_23edf00::vf8() {}

// 0x7100d848e0
void Unk_23edf00::vf10() {}

class Unk_23edf68 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100d84930
void Unk_23edf68::vf5() {
    Unk_d84970(this);
}

class Unk_23edfa8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100d84940
void Unk_23edfa8::vf0() {
    Unk_d84970(this);
}
