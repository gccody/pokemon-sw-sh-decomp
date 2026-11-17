// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_1333e80(void* self);

class Unk_2430ba8 {
public:
    virtual ~Unk_2430ba8();
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

// 0x7101333e10
void Unk_2430ba8::vf6() {
    Unk_1333e80(this);
}

// 0x7101333ca0
void Unk_2430ba8::vf9() {}

class Unk_2430c10 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101333e40
void Unk_2430c10::vf5() {
    Unk_1333e80(this);
}

class Unk_2430c50 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101333e50
void Unk_2430c50::vf0() {
    Unk_1333e80(this);
}
