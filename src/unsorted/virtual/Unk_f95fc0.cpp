// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_f96030(void* self);

class Unk_2401a78 {
public:
    virtual ~Unk_2401a78();
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

// 0x7100f95fc0
void Unk_2401a78::vf6() {
    Unk_f96030(this);
}

class Unk_2401ae0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100f95ff0
void Unk_2401ae0::vf5() {
    Unk_f96030(this);
}

class Unk_2401b20 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100f96000
void Unk_2401b20::vf0() {
    Unk_f96030(this);
}
