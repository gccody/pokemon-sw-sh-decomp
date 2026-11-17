// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_fa1210(void* self);

class Unk_2402180 {
public:
    virtual ~Unk_2402180();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100fa24e0
void Unk_2402180::vf6() {
    Unk_fa1210(this);
}

class Unk_24021c8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100fa2510
void Unk_24021c8::vf5() {
    Unk_fa1210(this);
}

class Unk_2402208 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100fa2520
void Unk_2402208::vf0() {
    Unk_fa1210(this);
}
