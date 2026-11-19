// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_13a1bc0(void* self);

// Lifted through their own placeholder structs (cast_member).
struct Unk_13a1ac0 {
    u8 _0[0x27c];
    u16 field_27c;
    u16 field_27e;
};
PKMN_OFFSET_ASSERT(Unk_13a1ac0, field_27c, 0x27c);
PKMN_OFFSET_ASSERT(Unk_13a1ac0, field_27e, 0x27e);

class Unk_2433840 {
public:
    virtual ~Unk_2433840();
    virtual void vf2();
    virtual void vf3();
};

// 0x710139ff50, 0x710139ff40
Unk_2433840::~Unk_2433840() {}

class Unk_24339e0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual bool vf12();
};

// 0x71013a1ac0
bool Unk_24339e0::vf12() {
    const Unk_13a1ac0* self = reinterpret_cast<const Unk_13a1ac0*>(this);
    if (self->field_27c != 0) {
        return 0;
    }
    return self->field_27e == 0;
}

class Unk_2433b70 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
};

// 0x71013a3480
void Unk_2433b70::vf6() {
    Unk_13a1bc0(this);
}

class Unk_2433be8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71013a3490
void Unk_2433be8::vf5() {
    Unk_13a1bc0(this);
}

class Unk_2433c28 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71013a34a0
void Unk_2433c28::vf0() {
    Unk_13a1bc0(this);
}
