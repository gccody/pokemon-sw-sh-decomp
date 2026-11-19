// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_fe1cb0(void* self);

class Unk_24053b0 {
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
};

// 0x7100fe2560
void Unk_24053b0::vf11() {
    Unk_fe1cb0(this);
}

class Unk_2405488 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x7100fe28b0
void Unk_2405488::vf1() {}
