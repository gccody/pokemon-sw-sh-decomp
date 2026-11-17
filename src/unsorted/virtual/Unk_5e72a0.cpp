// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_5e7300(void* self);

class Unk_239a5a8 {
public:
    virtual ~Unk_239a5a8();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
};

// 0x71005e72a0
void Unk_239a5a8::vf5() {
    Unk_5e7300(this);
}

class Unk_239a638 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71005e72d0
void Unk_239a638::vf0() {
    Unk_5e7300(this);
}
