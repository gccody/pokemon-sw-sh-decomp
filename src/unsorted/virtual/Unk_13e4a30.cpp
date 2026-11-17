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

struct Unk_2436008_88 {
    u8 _0[0x180];
    u64 field_180;
    u8 _188[0x8];
    u64 field_190;
};
PKMN_OFFSET_ASSERT(Unk_2436008_88, field_180, 0x180);
PKMN_OFFSET_ASSERT(Unk_2436008_88, field_190, 0x190);

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
    virtual u64 vf8();
    virtual void vf9();
    virtual u64 vf10();
    u8 _8[0x80];
    Unk_2436008_88* field_88;
};
PKMN_OFFSET_ASSERT(Unk_2436008, field_88, 0x88);

// 0x71013e6080
void Unk_2436008::vf6() {
    Unk_13e6430(this);
}

// 0x71013e6090
u64 Unk_2436008::vf8() {
    return field_88->field_190;
}

// 0x71013e60a0
u64 Unk_2436008::vf10() {
    return field_88->field_180;
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
