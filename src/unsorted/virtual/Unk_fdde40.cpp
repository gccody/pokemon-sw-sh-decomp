// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_fddd80(void* self);
void Unk_fdde60(void* self);
void Unk_fde270(void* self);

class Unk_2404e78 {
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
    virtual void vf12();
};

// 0x7100fde040
void Unk_2404e78::vf6() {
    Unk_fde270(this);
}

// 0x7100fdde40
void Unk_2404e78::vf11() {
    Unk_fddd80(this);
}

// 0x7100fddf20
void Unk_2404e78::vf12() {
    Unk_fdde60(this);
}

class Unk_2404ef0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100fde150
void Unk_2404ef0::vf5() {
    Unk_fde270(this);
}

class Unk_2404f30 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100fde160
void Unk_2404f30::vf0() {
    Unk_fde270(this);
}
