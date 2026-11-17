// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_f42da0(void* self);

// Tail-called by lifted functions. Placeholders, like the forwarders' callees.
void Unk_f43570(u64);

class Unk_23fd850 {
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
    u8 _8[0x70];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_23fd850, field_78, 0x78);

// 0x7100f429e0
void Unk_23fd850::vf6() {
    Unk_f42da0(this);
}

// 0x7100f42910
void Unk_23fd850::vf9() {
    Unk_f43570(field_78);
}

class Unk_23fd8b8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100f42ab0
void Unk_23fd8b8::vf5() {
    Unk_f42da0(this);
}

class Unk_23fd8f8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100f42ac0
void Unk_23fd8f8::vf0() {
    Unk_f42da0(this);
}
