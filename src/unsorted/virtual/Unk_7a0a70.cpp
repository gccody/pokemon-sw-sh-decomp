// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_7a3af0(void* self);
void Unk_7a8880(void* self);

class Unk_23a8d48 {
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
    virtual u32 vf10();
    u8 _8[0xe0];
    u32 field_e8;
};
PKMN_OFFSET_ASSERT(Unk_23a8d48, field_e8, 0xe8);

// 0x71007a0a70
u32 Unk_23a8d48::vf10() {
    return field_e8;
}

class Unk_23a8bd8 {
public:
    virtual ~Unk_23a8bd8();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual u32 vf7();
    virtual void vf8();
    virtual u32 vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual u32 vf16();
};

// 0x71007a39a0
void Unk_23a8bd8::vf6() {
    Unk_7a3af0(this);
}

class Unk_23a8c70 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71007a39d0
void Unk_23a8c70::vf5() {
    Unk_7a3af0(this);
}

class Unk_23a8cb0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71007a39e0
void Unk_23a8cb0::vf0() {
    Unk_7a3af0(this);
}

class Unk_23a8e60 {
public:
    virtual ~Unk_23a8e60();
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

// 0x71007a8810
void Unk_23a8e60::vf6() {
    Unk_7a8880(this);
}

// 0x71007a87f0
void Unk_23a8e60::vf9() {}

class Unk_23a8ec8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71007a8840
void Unk_23a8ec8::vf5() {
    Unk_7a8880(this);
}

class Unk_23a8f08 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71007a8850
void Unk_23a8f08::vf0() {
    Unk_7a8880(this);
}
