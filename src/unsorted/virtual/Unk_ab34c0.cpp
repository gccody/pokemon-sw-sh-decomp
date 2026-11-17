// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_a8af70(void* self);
void Unk_ab34d0(void* self);
void Unk_ab7560(void* self);

class Unk_23c8530 {
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
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
};

// 0x7100ab4330
void Unk_23c8530::vf6() {
    Unk_a8af70(this);
}

// 0x7100ab34c0
void Unk_23c8530::vf8() {
    Unk_ab34d0(this);
}

// 0x7100ab3620
void Unk_23c8530::vf10() {}

class Unk_23c85c8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100ab4400
void Unk_23c85c8::vf5() {
    Unk_a8af70(this);
}

class Unk_23c8608 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100ab4410
void Unk_23c8608::vf0() {
    Unk_a8af70(this);
}

class Unk_23c8660 {
public:
    virtual ~Unk_23c8660();
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

// 0x7100ab7530
void Unk_23c8660::vf6() {
    Unk_ab7560(this);
}

// 0x7100ab4dd0
u32 Unk_23c8660::vf7() {
    return 1;
}

class Unk_23c86c8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100ab7540
void Unk_23c86c8::vf5() {
    Unk_ab7560(this);
}

class Unk_23c8708 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100ab7550
void Unk_23c8708::vf0() {
    Unk_ab7560(this);
}

class Unk_23c8798 {
public:
    virtual ~Unk_23c8798();
    virtual void vf2();
    virtual u64 vf3();
    virtual void vf4();
    virtual void vf5();
    u8 _8[0x50];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_23c8798, field_58, 0x58);

// 0x7100ab8c20
u64 Unk_23c8798::vf3() {
    return field_58;
}

class Unk_23c87d8 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x7100ab8d90
u32 Unk_23c87d8::vf0() {
    return 1;
}
