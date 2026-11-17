// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_9386e0(void* self);

class Unk_23c0010 {
public:
    virtual ~Unk_23c0010();
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

// 0x7100938670
void Unk_23c0010::vf6() {
    Unk_9386e0(this);
}

class Unk_23c0078 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71009386a0
void Unk_23c0078::vf5() {
    Unk_9386e0(this);
}

class Unk_23c00b8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71009386b0
void Unk_23c00b8::vf0() {
    Unk_9386e0(this);
}
