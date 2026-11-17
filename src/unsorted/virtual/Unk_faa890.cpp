// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_faaba0(void* self);

class Unk_2402730 {
public:
    virtual ~Unk_2402730();
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

// 0x7100faaa10
void Unk_2402730::vf6() {
    Unk_faaba0(this);
}

// 0x7100faa890
void Unk_2402730::vf9() {}

class Unk_2402798 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100faaa40
void Unk_2402798::vf5() {
    Unk_faaba0(this);
}

class Unk_24027d8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100faaa50
void Unk_24027d8::vf0() {
    Unk_faaba0(this);
}
