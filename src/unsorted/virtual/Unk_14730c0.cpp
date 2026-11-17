// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_1473130(void* self);
void Unk_1473ba0(void* self);

class Unk_243df10 {
public:
    virtual ~Unk_243df10();
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

// 0x71014730c0
void Unk_243df10::vf6() {
    Unk_1473130(this);
}

class Unk_243df78 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71014730f0
void Unk_243df78::vf5() {
    Unk_1473130(this);
}

class Unk_243dfb8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101473100
void Unk_243dfb8::vf0() {
    Unk_1473130(this);
}

class Unk_243dfe0 {
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

// 0x71014739f0
void Unk_243dfe0::vf6() {
    Unk_1473ba0(this);
}

// 0x7101473920
void Unk_243dfe0::vf9() {}

class Unk_243e048 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101473ac0
void Unk_243e048::vf5() {
    Unk_1473ba0(this);
}

class Unk_243e088 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101473ad0
void Unk_243e088::vf0() {
    Unk_1473ba0(this);
}
