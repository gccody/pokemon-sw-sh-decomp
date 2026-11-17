// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_1278230(void* self);
void Unk_127a6e0(void* self);

class Unk_24293e8 {
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
};

// 0x71012791c0
void Unk_24293e8::vf6() {
    Unk_1278230(this);
}

class Unk_2429480 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71012792d0
void Unk_2429480::vf5() {
    Unk_1278230(this);
}

class Unk_24294c0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71012792e0
void Unk_24294c0::vf0() {
    Unk_1278230(this);
}

class Unk_24295f8 {
public:
    virtual ~Unk_24295f8();
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

// 0x710127a670
void Unk_24295f8::vf6() {
    Unk_127a6e0(this);
}

// 0x710127a650
void Unk_24295f8::vf9() {}

class Unk_2429660 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710127a6a0
void Unk_2429660::vf5() {
    Unk_127a6e0(this);
}

class Unk_24296a0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710127a6b0
void Unk_24296a0::vf0() {
    Unk_127a6e0(this);
}
