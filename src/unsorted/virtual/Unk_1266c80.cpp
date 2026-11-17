// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_12666d0(void* self);
void Unk_1268040(void* self);

class Unk_2428128 {
public:
    virtual ~Unk_2428128();
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

// 0x7101266c80
void Unk_2428128::vf6() {
    Unk_12666d0(this);
}

class Unk_24281c0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101266cb0
void Unk_24281c0::vf5() {
    Unk_12666d0(this);
}

class Unk_2428200 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101266cc0
void Unk_2428200::vf0() {
    Unk_12666d0(this);
}

class Unk_2428228 {
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

// 0x7101267d90
void Unk_2428228::vf6() {
    Unk_1268040(this);
}

class Unk_24282c0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101267ee0
void Unk_24282c0::vf5() {
    Unk_1268040(this);
}

class Unk_2428300 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101267ef0
void Unk_2428300::vf0() {
    Unk_1268040(this);
}
