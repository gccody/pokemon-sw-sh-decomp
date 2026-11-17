// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_12df4a0(void* self);

class Unk_242db48 {
public:
    virtual ~Unk_242db48();
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

// 0x71012df430
void Unk_242db48::vf6() {
    Unk_12df4a0(this);
}

// 0x71012df030
void Unk_242db48::vf9() {}

class Unk_242dbb0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71012df460
void Unk_242dbb0::vf5() {
    Unk_12df4a0(this);
}

class Unk_242dbf0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71012df470
void Unk_242dbf0::vf0() {
    Unk_12df4a0(this);
}
