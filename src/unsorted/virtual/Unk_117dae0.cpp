// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_117db70(void* self);

class Unk_241caa8 {
public:
    virtual ~Unk_241caa8();
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

// 0x710117db00
void Unk_241caa8::vf6() {
    Unk_117db70(this);
}

// 0x710117dae0
void Unk_241caa8::vf9() {}

class Unk_241cb10 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710117db30
void Unk_241cb10::vf5() {
    Unk_117db70(this);
}

class Unk_241cb50 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710117db40
void Unk_241cb50::vf0() {
    Unk_117db70(this);
}
