// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_1460b20(void* self);
void Unk_1461290(void* self);

class Unk_243d398 {
public:
    virtual ~Unk_243d398();
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

// 0x7101460ab0
void Unk_243d398::vf6() {
    Unk_1460b20(this);
}

// 0x7101460a90
void Unk_243d398::vf9() {}

class Unk_243d400 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101460ae0
void Unk_243d400::vf5() {
    Unk_1460b20(this);
}

class Unk_243d440 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101460af0
void Unk_243d440::vf0() {
    Unk_1460b20(this);
}

class Unk_243d468 {
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

// 0x71014610e0
void Unk_243d468::vf6() {
    Unk_1461290(this);
}

// 0x7101460e00
u32 Unk_243d468::vf7() {
    return 1;
}

// 0x7101460e10
void Unk_243d468::vf8() {}

// 0x7101460f00
void Unk_243d468::vf10() {}

class Unk_243d4d0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71014611b0
void Unk_243d4d0::vf5() {
    Unk_1461290(this);
}

class Unk_243d510 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71014611c0
void Unk_243d510::vf0() {
    Unk_1461290(this);
}

class Unk_243d538 {
public:
    virtual ~Unk_243d538();
    virtual void vf2();
    virtual u64 vf3();
    virtual void vf4();
    virtual void vf5();
    u8 _8[0xb0];
    u64 field_b8;
};
PKMN_OFFSET_ASSERT(Unk_243d538, field_b8, 0xb8);

// 0x7101461b40
u64 Unk_243d538::vf3() {
    return field_b8;
}

class Unk_243d578 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x7101461cd0
u32 Unk_243d578::vf0() {
    return 4;
}
