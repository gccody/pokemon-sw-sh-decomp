// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_1273700(void* self);
void Unk_1273cc0(void* self);

class Unk_2428b48 {
public:
    virtual ~Unk_2428b48();
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

// 0x7101273690
void Unk_2428b48::vf6() {
    Unk_1273700(this);
}

class Unk_2428be0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71012736c0
void Unk_2428be0::vf5() {
    Unk_1273700(this);
}

class Unk_2428c20 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71012736d0
void Unk_2428c20::vf0() {
    Unk_1273700(this);
}

class Unk_2428f78 {
public:
    virtual ~Unk_2428f78();
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

// 0x7101273c50
void Unk_2428f78::vf6() {
    Unk_1273cc0(this);
}

// 0x7101273c30
void Unk_2428f78::vf9() {}

class Unk_2428fe0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101273c80
void Unk_2428fe0::vf5() {
    Unk_1273cc0(this);
}

class Unk_2429020 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101273c90
void Unk_2429020::vf0() {
    Unk_1273cc0(this);
}
