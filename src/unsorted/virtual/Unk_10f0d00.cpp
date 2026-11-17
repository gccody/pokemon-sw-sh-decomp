// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_15b6e10(void* self);

class Unk_24173f0 {
public:
    virtual ~Unk_24173f0();
    virtual void vf2();
    virtual u32 vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6(u64 value);
    virtual u64 vf7();
    virtual u8 vf8();
    virtual void vf9(u32 value);
    virtual u32 vf10();
    virtual void vf11();
    u64 field_8;
    u8 field_10;
    u8 _11[0x3];
    u32 field_14;
};
PKMN_OFFSET_ASSERT(Unk_24173f0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_24173f0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_24173f0, field_14, 0x14);

// 0x71010f0d20
u32 Unk_24173f0::vf3() {
    return 1;
}

// 0x71010f1340
void Unk_24173f0::vf5() {
    field_14 = 0;
    field_10 = 1;
}

// 0x71010f1350
void Unk_24173f0::vf6(u64 value) {
    field_8 = value;
}

// 0x71010f1360
u64 Unk_24173f0::vf7() {
    return field_8;
}

// 0x71010f1370
u8 Unk_24173f0::vf8() {
    return field_10;
}

// 0x71010f0d10
void Unk_24173f0::vf9(u32 value) {
    field_14 = value;
}

// 0x71010f0d00
u32 Unk_24173f0::vf10() {
    return field_14;
}

class Unk_24173b0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71010f11a0
void Unk_24173b0::vf0() {}

// 0x71010f11b0
void Unk_24173b0::vf1() {}

// 0x71010f11c0
void Unk_24173b0::vf3() {}

// 0x71010f11d0
void Unk_24173b0::vf5() {}

class Unk_2417460 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x71010f1380
void Unk_2417460::vf1() {
    Unk_15b6e10(this);
}
