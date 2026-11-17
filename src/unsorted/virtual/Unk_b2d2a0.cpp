// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_b2cc40(void* self);
void Unk_b2d2b0(void* self);
void Unk_b2e480(void* self);

class Unk_23cea48 {
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
};

// 0x7100b2d790
void Unk_23cea48::vf6() {
    Unk_b2cc40(this);
}

// 0x7100b2d2a0
void Unk_23cea48::vf8() {
    Unk_b2d2b0(this);
}

// 0x7100b2d500
void Unk_23cea48::vf9() {}

class Unk_23cead8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100b2d7c0
void Unk_23cead8::vf5() {
    Unk_b2cc40(this);
}

class Unk_23ceb18 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100b2d7d0
void Unk_23ceb18::vf0() {
    Unk_b2cc40(this);
}

class Unk_23ceba0 {
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

// 0x7100b2e450
void Unk_23ceba0::vf6() {
    Unk_b2e480(this);
}

// 0x7100b2dd00
u32 Unk_23ceba0::vf7() {
    return 1;
}

// 0x7100b2dd10
void Unk_23ceba0::vf8() {}

class Unk_23cec08 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100b2e460
void Unk_23cec08::vf5() {
    Unk_b2e480(this);
}

class Unk_23cec48 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100b2e470
void Unk_23cec48::vf0() {
    Unk_b2e480(this);
}
