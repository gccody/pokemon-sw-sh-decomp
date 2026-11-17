// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_b30410(void* self);
void Unk_b317d0(void* self);

class Unk_23cee40 {
public:
    virtual ~Unk_23cee40();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100b30ae0
void Unk_23cee40::vf6() {
    Unk_b30410(this);
}

class Unk_23cee88 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100b30b10
void Unk_23cee88::vf5() {
    Unk_b30410(this);
}

class Unk_23ceec8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100b30b20
void Unk_23ceec8::vf0() {
    Unk_b30410(this);
}

class Unk_23ceef0 {
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

// 0x7100b315e0
void Unk_23ceef0::vf6() {
    Unk_b317d0(this);
}

// 0x7100b314f0
void Unk_23ceef0::vf9() {}

class Unk_23cef58 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100b316d0
void Unk_23cef58::vf5() {
    Unk_b317d0(this);
}

class Unk_23cef98 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100b316e0
void Unk_23cef98::vf0() {
    Unk_b317d0(this);
}
