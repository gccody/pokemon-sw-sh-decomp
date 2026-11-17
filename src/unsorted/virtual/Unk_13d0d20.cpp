// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_13d0d90(void* self);
void Unk_13d1880(void* self);

class Unk_2435958 {
public:
    virtual ~Unk_2435958();
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

// 0x71013d0d20
void Unk_2435958::vf6() {
    Unk_13d0d90(this);
}

class Unk_24359c8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71013d0d50
void Unk_24359c8::vf5() {
    Unk_13d0d90(this);
}

class Unk_2435a08 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71013d0d60
void Unk_2435a08::vf0() {
    Unk_13d0d90(this);
}

class Unk_2435a30 {
public:
    virtual ~Unk_2435a30();
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

// 0x71013d1810
void Unk_2435a30::vf6() {
    Unk_13d1880(this);
}

class Unk_2435aa0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71013d1840
void Unk_2435aa0::vf5() {
    Unk_13d1880(this);
}

class Unk_2435ae0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71013d1850
void Unk_2435ae0::vf0() {
    Unk_13d1880(this);
}
