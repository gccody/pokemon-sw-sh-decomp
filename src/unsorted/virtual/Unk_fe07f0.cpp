// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_fe0050(void* self);
void Unk_fe0bb0(void* self);

class Unk_24051e8 {
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
};

// 0x7100fe0930
void Unk_24051e8::vf6() {
    Unk_fe0bb0(this);
}

// 0x7100fe07f0
void Unk_24051e8::vf11() {
    Unk_fe0050(this);
}

class Unk_2405258 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100fe0a60
void Unk_2405258::vf5() {
    Unk_fe0bb0(this);
}

class Unk_2405298 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100fe0a70
void Unk_2405298::vf0() {
    Unk_fe0bb0(this);
}

class Unk_24052c0 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x7100fe0ba0
void Unk_24052c0::vf0() {}
