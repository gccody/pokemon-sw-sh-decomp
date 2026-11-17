// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_932000(void* self);

class Unk_23bfac8 {
public:
    virtual ~Unk_23bfac8();
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

// 0x7100931f90
void Unk_23bfac8::vf6() {
    Unk_932000(this);
}

// 0x7100931f70
void Unk_23bfac8::vf9() {}

class Unk_23bfb30 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100931fc0
void Unk_23bfb30::vf5() {
    Unk_932000(this);
}

class Unk_23bfb70 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100931fd0
void Unk_23bfb70::vf0() {
    Unk_932000(this);
}
