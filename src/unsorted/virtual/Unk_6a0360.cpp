// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_6a0380(void* self);

class Unk_23a2430 {
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
};

// 0x71006a0360
void Unk_23a2430::vf5() {
    Unk_6a0380(this);
}

class Unk_23a24c0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71006a0370
void Unk_23a24c0::vf0() {
    Unk_6a0380(this);
}
