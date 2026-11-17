// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_127b330(void* self);

class Unk_24296c8 {
public:
    virtual ~Unk_24296c8();
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

// 0x710127b2c0
void Unk_24296c8::vf6() {
    Unk_127b330(this);
}

class Unk_2429730 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710127b2f0
void Unk_2429730::vf5() {
    Unk_127b330(this);
}

class Unk_2429770 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710127b300
void Unk_2429770::vf0() {
    Unk_127b330(this);
}
