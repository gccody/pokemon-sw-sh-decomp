// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_f37d80(void* self);

class Unk_23fd150 {
public:
    virtual ~Unk_23fd150();
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

// 0x7100f37d10
void Unk_23fd150::vf6() {
    Unk_f37d80(this);
}

// 0x7100f37cf0
void Unk_23fd150::vf9() {}

class Unk_23fd1b8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100f37d40
void Unk_23fd1b8::vf5() {
    Unk_f37d80(this);
}

class Unk_23fd1f8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100f37d50
void Unk_23fd1f8::vf0() {
    Unk_f37d80(this);
}
