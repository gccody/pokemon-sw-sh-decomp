// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_d95190(void* self);
void Unk_d963c0(void* self);

class Unk_23ee328 {
public:
    virtual ~Unk_23ee328();
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

// 0x7100d95120
void Unk_23ee328::vf6() {
    Unk_d95190(this);
}

// 0x7100d94e50
u32 Unk_23ee328::vf7() {
    return 1;
}

// 0x7100d94e60
void Unk_23ee328::vf8() {}

// 0x7100d95100
void Unk_23ee328::vf10() {}

class Unk_23ee390 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100d95150
void Unk_23ee390::vf5() {
    Unk_d95190(this);
}

class Unk_23ee3d0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100d95160
void Unk_23ee3d0::vf0() {
    Unk_d95190(this);
}

class Unk_23ee3f8 {
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

// 0x7100d96210
void Unk_23ee3f8::vf6() {
    Unk_d963c0(this);
}

// 0x7100d95470
u32 Unk_23ee3f8::vf7() {
    return 1;
}

// 0x7100d95480
void Unk_23ee3f8::vf8() {}

// 0x7100d96140
void Unk_23ee3f8::vf10() {}

class Unk_23ee460 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100d962e0
void Unk_23ee460::vf5() {
    Unk_d963c0(this);
}

class Unk_23ee4a0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100d962f0
void Unk_23ee4a0::vf0() {
    Unk_d963c0(this);
}
