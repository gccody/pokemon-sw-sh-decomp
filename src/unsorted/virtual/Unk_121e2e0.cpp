// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_121e460(void* self);

class Unk_2423fd0 {
public:
    virtual ~Unk_2423fd0();
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
};

// 0x710121e2e0
void Unk_2423fd0::vf6() {
    Unk_121e460(this);
}

class Unk_2424050 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710121e310
void Unk_2424050::vf5() {
    Unk_121e460(this);
}

class Unk_2424090 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710121e320
void Unk_2424090::vf0() {
    Unk_121e460(this);
}

class Unk_24240b8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x710121e350
void Unk_24240b8::vf1() {}

// 0x710121e360
void Unk_24240b8::vf2() {}

// 0x710121e370
void Unk_24240b8::vf3() {}

// 0x710121e380
void Unk_24240b8::vf5() {}
