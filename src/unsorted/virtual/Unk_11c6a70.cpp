// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_11c6ae0(void* self);

class Unk_2420058 {
public:
    virtual ~Unk_2420058();
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

// 0x71011c6a70
void Unk_2420058::vf6() {
    Unk_11c6ae0(this);
}

class Unk_24200c0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71011c6aa0
void Unk_24200c0::vf5() {
    Unk_11c6ae0(this);
}

class Unk_2420100 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71011c6ab0
void Unk_2420100::vf0() {
    Unk_11c6ae0(this);
}

class Unk_2420128 {
public:
    virtual ~Unk_2420128();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x71011ca580
void Unk_2420128::vf4() {}
