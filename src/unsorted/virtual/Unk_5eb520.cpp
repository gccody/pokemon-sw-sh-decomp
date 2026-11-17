// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_5eb880(void* self);

class Unk_239a840 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x71005eb520
u32 Unk_239a840::vf0() {
    return 2;
}

class Unk_239a870 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71005eb690
u32 Unk_239a870::vf0() {
    return 2;
}

class Unk_239a8c0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x71005ec250
void Unk_239a8c0::vf2() {}

class Unk_239a8f0 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x71005ec2d0
void Unk_239a8f0::vf0() {}

class Unk_239a2f0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71005ece00
void Unk_239a2f0::vf5() {}

class Unk_239abd0 {
public:
    virtual ~Unk_239abd0();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6() = 0;
    virtual void vf7() = 0;
    virtual void vf8() = 0;
};

// 0x71005ede40
void Unk_239abd0::vf5() {
    Unk_5eb880(this);
}

class Unk_239ac28 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71005ede50
void Unk_239ac28::vf0() {
    Unk_5eb880(this);
}

class Unk_239ac50 {
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
    virtual u8* vf12();
    virtual void vf13();
    u8 _8[0x160];
    u8 field_168;
};
PKMN_OFFSET_ASSERT(Unk_239ac50, field_168, 0x168);

// 0x71005ee4c0
u8* Unk_239ac50::vf12() {
    return &field_168;
}
