// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_a898c0(void* self);

class Unk_23c78f0 {
public:
    virtual ~Unk_23c78f0();
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

// 0x7100a89850
void Unk_23c78f0::vf6() {
    Unk_a898c0(this);
}

// 0x7100a89830
void Unk_23c78f0::vf9() {}

class Unk_23c7958 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100a89880
void Unk_23c7958::vf5() {
    Unk_a898c0(this);
}

class Unk_23c7998 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100a89890
void Unk_23c7998::vf0() {
    Unk_a898c0(this);
}
