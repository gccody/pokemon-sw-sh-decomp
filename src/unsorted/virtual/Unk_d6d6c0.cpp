// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_d6e3e0(void* self);
void Unk_d6ec10(void* self);

class Unk_23ed370 {
public:
    virtual void vf0();
    virtual void vf1();
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

// 0x7100d6e230
void Unk_23ed370::vf6() {
    Unk_d6e3e0(this);
}

// 0x7100d6d6c0
u32 Unk_23ed370::vf7() {
    return 1;
}

class Unk_23ed3d8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100d6e300
void Unk_23ed3d8::vf5() {
    Unk_d6e3e0(this);
}

class Unk_23ed418 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100d6e310
void Unk_23ed418::vf0() {
    Unk_d6e3e0(this);
}

class Unk_23ed440 {
public:
    virtual void vf0();
    virtual void vf1();
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

// 0x7100d6ea60
void Unk_23ed440::vf6() {
    Unk_d6ec10(this);
}

// 0x7100d6e660
u32 Unk_23ed440::vf7() {
    return 1;
}

// 0x7100d6e670
void Unk_23ed440::vf8() {}

// 0x7100d6e990
void Unk_23ed440::vf10() {}

class Unk_23ed4a8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100d6eb30
void Unk_23ed4a8::vf5() {
    Unk_d6ec10(this);
}

class Unk_23ed4e8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100d6eb40
void Unk_23ed4e8::vf0() {
    Unk_d6ec10(this);
}
