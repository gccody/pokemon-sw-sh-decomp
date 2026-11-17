// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_12a0da0(void* self);

class Unk_242b6f0 {
public:
    virtual ~Unk_242b6f0();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x71012a4560
void Unk_242b6f0::vf6() {
    Unk_12a0da0(this);
}

class Unk_242b738 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71012a4590
void Unk_242b738::vf5() {
    Unk_12a0da0(this);
}

class Unk_242b778 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71012a45a0
void Unk_242b778::vf0() {
    Unk_12a0da0(this);
}
