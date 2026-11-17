// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_1485590(void* self);
void Unk_1485d90(void* self);

class Unk_243fd20 {
public:
    virtual ~Unk_243fd20();
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

// 0x7101485520
void Unk_243fd20::vf6() {
    Unk_1485590(this);
}

// 0x7101485500
void Unk_243fd20::vf9() {}

class Unk_243fd88 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101485550
void Unk_243fd88::vf5() {
    Unk_1485590(this);
}

class Unk_243fdc8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101485560
void Unk_243fdc8::vf0() {
    Unk_1485590(this);
}

class Unk_243fdf0 {
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

// 0x7101485d60
void Unk_243fdf0::vf6() {
    Unk_1485d90(this);
}

// 0x7101485a90
u32 Unk_243fdf0::vf7() {
    return 1;
}

// 0x7101485aa0
void Unk_243fdf0::vf8() {}

// 0x7101485c40
void Unk_243fdf0::vf10() {}

class Unk_243fe58 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101485d70
void Unk_243fe58::vf5() {
    Unk_1485d90(this);
}

class Unk_243fe98 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101485d80
void Unk_243fe98::vf0() {
    Unk_1485d90(this);
}

class Unk_243fec0 {
public:
    virtual ~Unk_243fec0();
    virtual void vf2();
    virtual u64 vf3();
    virtual void vf4();
    virtual void vf5();
    u8 _8[0x50];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_243fec0, field_58, 0x58);

// 0x7101486570
u64 Unk_243fec0::vf3() {
    return field_58;
}

class Unk_243ff00 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x71014866e0
u32 Unk_243ff00::vf0() {
    return 1;
}
