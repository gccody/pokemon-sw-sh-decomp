// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_102b0b0(void* self);
void Unk_102bda0(void* self);

class Unk_2409238 {
public:
    virtual ~Unk_2409238();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6() = 0;
    virtual void vf7() = 0;
    virtual void vf8() = 0;
};

// 0x710102b030
void Unk_2409238::vf5() {
    Unk_102b0b0(this);
}

class Unk_2409290 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710102b040
void Unk_2409290::vf0() {
    Unk_102b0b0(this);
}

class Unk_24093d8 {
public:
    virtual ~Unk_24093d8();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6() = 0;
    virtual void vf7() = 0;
    virtual void vf8() = 0;
};

// 0x710102bd20
void Unk_24093d8::vf5() {
    Unk_102bda0(this);
}

class Unk_2409430 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710102bd30
void Unk_2409430::vf0() {
    Unk_102bda0(this);
}
