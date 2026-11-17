// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_da3110(void* self);

class Unk_23eeaf0 {
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

// 0x7100da30e0
void Unk_23eeaf0::vf6() {
    Unk_da3110(this);
}

// 0x7100da2e80
u32 Unk_23eeaf0::vf7() {
    return 1;
}

// 0x7100da2e90
void Unk_23eeaf0::vf8() {}

// 0x7100da30d0
void Unk_23eeaf0::vf10() {}

class Unk_23eeb58 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100da30f0
void Unk_23eeb58::vf5() {
    Unk_da3110(this);
}

class Unk_23eeb98 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100da3100
void Unk_23eeb98::vf0() {
    Unk_da3110(this);
}

class Unk_23eebc0 {
public:
    virtual ~Unk_23eebc0();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual u32 vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    u8 _8[0x60];
    u32 field_68;
};
PKMN_OFFSET_ASSERT(Unk_23eebc0, field_68, 0x68);

// 0x7100da3240
u32 Unk_23eebc0::vf7() {
    return 1;
}

// 0x7100da3250
void Unk_23eebc0::vf8() {
    field_68 = 0;
}

// 0x7100da34a0
void Unk_23eebc0::vf10() {}
