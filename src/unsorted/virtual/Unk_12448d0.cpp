// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_1244f60(void* self);

class Unk_24264f8 {
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

// 0x7101244db0
void Unk_24264f8::vf6() {
    Unk_1244f60(this);
}

// 0x71012448d0
u32 Unk_24264f8::vf7() {
    return 1;
}

class Unk_2426560 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101244e80
void Unk_2426560::vf5() {
    Unk_1244f60(this);
}

class Unk_24265a0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101244e90
void Unk_24265a0::vf0() {
    Unk_1244f60(this);
}

class Unk_24265c8 {
public:
    virtual ~Unk_24265c8();
    virtual void vf2();
    virtual u64 vf3();
    virtual void vf4();
    virtual void vf5();
    u8 _8[0x50];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_24265c8, field_58, 0x58);

// 0x7101245680
u64 Unk_24265c8::vf3() {
    return field_58;
}

class Unk_2426608 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x71012457f0
u32 Unk_2426608::vf0() {
    return 1;
}
