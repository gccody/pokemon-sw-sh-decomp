// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_117dca0(void* self);

class Unk_241cb78 {
public:
    virtual ~Unk_241cb78();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7101180870
void Unk_241cb78::vf6() {
    Unk_117dca0(this);
}

class Unk_241cbc0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71011808a0
void Unk_241cbc0::vf5() {
    Unk_117dca0(this);
}

class Unk_241cc00 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71011808b0
void Unk_241cc00::vf0() {
    Unk_117dca0(this);
}
