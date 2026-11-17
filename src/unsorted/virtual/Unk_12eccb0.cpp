// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_12ecfd0(void* self);

class Unk_242e738 {
public:
    virtual ~Unk_242e738();
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

// 0x71012ecf60
void Unk_242e738::vf6() {
    Unk_12ecfd0(this);
}

// 0x71012eccb0
void Unk_242e738::vf9() {}

class Unk_242e7a0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71012ecf90
void Unk_242e7a0::vf5() {
    Unk_12ecfd0(this);
}

class Unk_242e7e0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71012ecfa0
void Unk_242e7e0::vf0() {
    Unk_12ecfd0(this);
}
