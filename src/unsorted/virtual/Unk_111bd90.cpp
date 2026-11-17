// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_2418f90 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x710111bd90
u32 Unk_2418f90::vf0() {
    return 0x15;
}

class Unk_24191a0 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x7101121660
u32 Unk_24191a0::vf0() {
    return 1;
}

class Unk_2419210 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x71011222d0
u32 Unk_2419210::vf0() {
    return 1;
}

class Unk_2419280 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x7101122b80
u32 Unk_2419280::vf0() {
    return 1;
}

class Unk_24192b0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual u32 vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual u32 vf10();
    virtual void vf11();
};

// 0x7101122d20
void Unk_24192b0::vf5() {}

// 0x7101122d30
u32 Unk_24192b0::vf6() {
    return 1;
}

// 0x7101122d40
void Unk_24192b0::vf7() {}

// 0x7101122d50
void Unk_24192b0::vf8() {}

// 0x7101122d60
void Unk_24192b0::vf9() {}

// 0x7101122d70
u32 Unk_24192b0::vf10() {
    return 1;
}

// 0x7101122d80
void Unk_24192b0::vf11() {}
