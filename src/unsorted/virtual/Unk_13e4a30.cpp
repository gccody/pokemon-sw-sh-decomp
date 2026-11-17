// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_13e6430(void* self);

class Unk_2435f38 {
public:
    virtual ~Unk_2435f38();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7() = 0;
    virtual void vf8() = 0;
    virtual void vf9();
    virtual u32 vf10();
    u8 _8[0x68];
    u32 field_70;
};
PKMN_OFFSET_ASSERT(Unk_2435f38, field_70, 0x70);

// 0x71013e4a30
u32 Unk_2435f38::vf10() {
    return field_70;
}

class Unk_2436008 {
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
};

// 0x71013e6080
void Unk_2436008::vf6() {
    Unk_13e6430(this);
}

class Unk_2436070 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71013e6250
void Unk_2436070::vf5() {
    Unk_13e6430(this);
}

class Unk_24360b0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71013e6260
void Unk_24360b0::vf0() {
    Unk_13e6430(this);
}
