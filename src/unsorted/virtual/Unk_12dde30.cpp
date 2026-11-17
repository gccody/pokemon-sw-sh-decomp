// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_12de2a0(void* self);

class Unk_242da78 {
public:
    virtual ~Unk_242da78();
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

// 0x71012de230
void Unk_242da78::vf6() {
    Unk_12de2a0(this);
}

// 0x71012dde30
void Unk_242da78::vf9() {}

class Unk_242dae0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71012de260
void Unk_242dae0::vf5() {
    Unk_12de2a0(this);
}

class Unk_242db20 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71012de270
void Unk_242db20::vf0() {
    Unk_12de2a0(this);
}
