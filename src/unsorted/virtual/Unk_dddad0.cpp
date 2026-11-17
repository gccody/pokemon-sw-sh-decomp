// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_ddf8c0(void* self);

class Unk_23f0920 {
public:
    virtual ~Unk_23f0920();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
};

// 0x7100dddad0
void Unk_23f0920::vf7() {}

class Unk_23f0a88 {
public:
    virtual ~Unk_23f0a88();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100ddf850
void Unk_23f0a88::vf6() {
    Unk_ddf8c0(this);
}

class Unk_23f0ad0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100ddf880
void Unk_23f0ad0::vf5() {
    Unk_ddf8c0(this);
}

class Unk_23f0b10 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100ddf890
void Unk_23f0b10::vf0() {
    Unk_ddf8c0(this);
}
