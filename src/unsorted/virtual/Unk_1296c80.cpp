// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_1297810(void* self);

class Unk_242b430 {
public:
    virtual ~Unk_242b430();
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

// 0x71012977e0
void Unk_242b430::vf6() {
    Unk_1297810(this);
}

// 0x7101296c80
u32 Unk_242b430::vf7() {
    return 1;
}

class Unk_242b498 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71012977f0
void Unk_242b498::vf5() {
    Unk_1297810(this);
}

class Unk_242b4d8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101297800
void Unk_242b4d8::vf0() {
    Unk_1297810(this);
}

class Unk_242b540 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x7101297fc0
u32 Unk_242b540::vf0() {
    return 1;
}
