// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_925d50(void* self);

class Unk_23bef08 {
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
};

// 0x7100925ba0
void Unk_23bef08::vf6() {
    Unk_925d50(this);
}

// 0x7100925ad0
void Unk_23bef08::vf9() {}

class Unk_23bef70 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100925c70
void Unk_23bef70::vf5() {
    Unk_925d50(this);
}

class Unk_23befb0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100925c80
void Unk_23befb0::vf0() {
    Unk_925d50(this);
}
