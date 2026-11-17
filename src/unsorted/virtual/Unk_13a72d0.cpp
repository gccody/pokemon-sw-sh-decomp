// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_13a7aa0(void* self);

class Unk_2433fe8 {
public:
    virtual ~Unk_2433fe8();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual u32 vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
};

// 0x71013a7a30
void Unk_2433fe8::vf6() {
    Unk_13a7aa0(this);
}

// 0x71013a72d0
u32 Unk_2433fe8::vf7() {
    return 1;
}

class Unk_2434050 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71013a7a60
void Unk_2434050::vf5() {
    Unk_13a7aa0(this);
}

class Unk_2434090 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71013a7a70
void Unk_2434090::vf0() {
    Unk_13a7aa0(this);
}

class Unk_24348d0 {
public:
    virtual ~Unk_24348d0();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x71013b2090, 0x71013b1fe0
Unk_24348d0::~Unk_24348d0() {}

// 0x71013b2050
void Unk_24348d0::vf4() {}
