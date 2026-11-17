// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_da6030(void* self);
void Unk_da63d0(void* self);
void Unk_da6d70(void* self);

class Unk_23eee38 {
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
    u32 field_90;
};
PKMN_OFFSET_ASSERT(Unk_23eee38, field_90, 0x90);

// 0x7100da6000
void Unk_23eee38::vf6() {
    Unk_da6030(this);
}

// 0x7100da5f70
u32 Unk_23eee38::vf7() {
    return 1;
}

// 0x7100da5f80
void Unk_23eee38::vf8() {
    field_90 = 0xa;
}

// 0x7100da5ff0
void Unk_23eee38::vf10() {}

class Unk_23eeea0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100da6010
void Unk_23eeea0::vf5() {
    Unk_da6030(this);
}

class Unk_23eeee0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100da6020
void Unk_23eeee0::vf0() {
    Unk_da6030(this);
}

class Unk_23eef08 {
public:
    virtual ~Unk_23eef08();
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

// 0x7100da6330
void Unk_23eef08::vf6() {
    Unk_da63d0(this);
}

// 0x7100da6340
u32 Unk_23eef08::vf7() {
    return 1;
}

// 0x7100da6350
void Unk_23eef08::vf8() {}

// 0x7100da6360
void Unk_23eef08::vf10() {}

class Unk_23eef70 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100da6390
void Unk_23eef70::vf5() {
    Unk_da63d0(this);
}

class Unk_23eefb0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100da63a0
void Unk_23eefb0::vf0() {
    Unk_da63d0(this);
}

class Unk_23eefd8 {
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

// 0x7100da6bc0
void Unk_23eefd8::vf6() {
    Unk_da6d70(this);
}

// 0x7100da6580
u32 Unk_23eefd8::vf7() {
    return 1;
}

// 0x7100da6590
void Unk_23eefd8::vf8() {}

// 0x7100da6af0
void Unk_23eefd8::vf10() {}

class Unk_23ef040 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100da6c90
void Unk_23ef040::vf5() {
    Unk_da6d70(this);
}

class Unk_23ef080 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100da6ca0
void Unk_23ef080::vf0() {
    Unk_da6d70(this);
}
