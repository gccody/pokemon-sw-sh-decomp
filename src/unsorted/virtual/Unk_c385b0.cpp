// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23dabf8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
};

// 0x7100c385b0
void Unk_23dabf8::vf1() {}

class Unk_23dac30 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x7100c385c0
void Unk_23dac30::vf0() {}

// 0x7100c385d0
void Unk_23dac30::vf1() {}

class Unk_23dac60 {
public:
    virtual ~Unk_23dac60();
    virtual void vf2();
    virtual u64 vf3();
    virtual void vf4();
    virtual void vf5();
    u8 _8[0x50];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_23dac60, field_58, 0x58);

// 0x7100c38e50
u64 Unk_23dac60::vf3() {
    return field_58;
}

class Unk_23dace0 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x7100c38ff0
u32 Unk_23dace0::vf0() {
    return 1;
}

class Unk_23dad10 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x7100c39120
u32 Unk_23dad10::vf0() {
    return 1;
}

class Unk_23dad40 {
public:
    virtual ~Unk_23dad40();
    virtual void vf2();
    virtual u64 vf3();
    virtual void vf4();
    virtual void vf5();
    u8 _8[0x50];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_23dad40, field_58, 0x58);

// 0x7100c397b0
u64 Unk_23dad40::vf3() {
    return field_58;
}

class Unk_23dad80 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x7100c39920
u32 Unk_23dad80::vf0() {
    return 1;
}

class Unk_23dadb0 {
public:
    virtual ~Unk_23dadb0();
    virtual void vf2();
    virtual u64 vf3();
    virtual void vf4();
    virtual void vf5();
    u8 _8[0x50];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_23dadb0, field_58, 0x58);

// 0x7100c3a510
u64 Unk_23dadb0::vf3() {
    return field_58;
}

class Unk_23dadf0 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x7100c3a680
u32 Unk_23dadf0::vf0() {
    return 1;
}
