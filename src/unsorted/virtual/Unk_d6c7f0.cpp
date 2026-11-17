// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_d6c930(void* self);

struct Unk_23ed1d0_90 {
    u8 _0[0x8];
    u64 field_8;
    u64 field_10;
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_23ed1d0_90, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_23ed1d0_90, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_23ed1d0_90, field_18, 0x18);

class Unk_23ed1d0 {
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
    u8 _8[0x88];
    Unk_23ed1d0_90* field_90;
};
PKMN_OFFSET_ASSERT(Unk_23ed1d0, field_90, 0x90);

// 0x7100d6c900
void Unk_23ed1d0::vf6() {
    Unk_d6c930(this);
}

// 0x7100d6c7f0
u32 Unk_23ed1d0::vf7() {
    return 1;
}

// 0x7100d6c800
void Unk_23ed1d0::vf8() {
    if (field_90 != nullptr) {
        field_90->field_8 = 0;
        field_90->field_10 = 0;
        field_90->field_18 = 0;
    }
}

// 0x7100d6c8f0
void Unk_23ed1d0::vf10() {}

class Unk_23ed238 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100d6c910
void Unk_23ed238::vf5() {
    Unk_d6c930(this);
}

class Unk_23ed278 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100d6c920
void Unk_23ed278::vf0() {
    Unk_d6c930(this);
}

class Unk_23ed2a0 {
public:
    virtual ~Unk_23ed2a0();
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

// 0x7100d6cd30
u32 Unk_23ed2a0::vf7() {
    return 1;
}

// 0x7100d6cd40
void Unk_23ed2a0::vf8() {}

// 0x7100d6d0d0
void Unk_23ed2a0::vf10() {}
