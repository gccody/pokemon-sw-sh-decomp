// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_127d900(void* self);

class Unk_2429938 {
public:
    virtual ~Unk_2429938();
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

// 0x710127d890
void Unk_2429938::vf6() {
    Unk_127d900(this);
}

// 0x710127d610
void Unk_2429938::vf7() {}

// 0x710127d870
void Unk_2429938::vf9() {}

class Unk_24299a0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710127d8c0
void Unk_24299a0::vf5() {
    Unk_127d900(this);
}

class Unk_24299e0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710127d8d0
void Unk_24299e0::vf0() {
    Unk_127d900(this);
}
