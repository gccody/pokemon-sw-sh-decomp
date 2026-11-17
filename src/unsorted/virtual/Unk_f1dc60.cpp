// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_f1f170(void* self);

class Unk_23d71b0 {
public:
    virtual ~Unk_23d71b0();
    virtual void vf2();
    virtual void vf3();
};

// 0x7100f1dc60
void Unk_23d71b0::vf2() {}

// 0x7100f1dc70
void Unk_23d71b0::vf3() {}

class Unk_23fb870 {
public:
    virtual ~Unk_23fb870();
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

// 0x7100f1efc0
void Unk_23fb870::vf6() {
    Unk_f1f170(this);
}

// 0x7100f1deb0
u32 Unk_23fb870::vf7() {
    return 1;
}

class Unk_23fb8d8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100f1eff0
void Unk_23fb8d8::vf5() {
    Unk_f1f170(this);
}

class Unk_23fb918 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100f1f000
void Unk_23fb918::vf0() {
    Unk_f1f170(this);
}

class Unk_23fb998 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x7100f1faa0
u32 Unk_23fb998::vf0() {
    return 1;
}
