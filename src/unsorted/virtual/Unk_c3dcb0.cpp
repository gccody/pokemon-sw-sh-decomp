// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_c3e6e0(void* self);

class Unk_23db008 {
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

// 0x7100c3e6b0
void Unk_23db008::vf6() {
    Unk_c3e6e0(this);
}

// 0x7100c3dcb0
u32 Unk_23db008::vf7() {
    return 1;
}

class Unk_23db070 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100c3e6c0
void Unk_23db070::vf5() {
    Unk_c3e6e0(this);
}

class Unk_23db0b0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100c3e6d0
void Unk_23db0b0::vf0() {
    Unk_c3e6e0(this);
}

class Unk_23db0d8 {
public:
    virtual ~Unk_23db0d8();
    virtual void vf2();
    virtual u64 vf3();
    virtual void vf4();
    virtual void vf5();
    u8 _8[0x70];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_23db0d8, field_78, 0x78);

// 0x7100c3ee80
u64 Unk_23db0d8::vf3() {
    return field_78;
}

class Unk_23db118 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x7100c3f010
u32 Unk_23db118::vf0() {
    return 2;
}

class Unk_23db148 {
public:
    virtual ~Unk_23db148();
    virtual void vf2();
    virtual u64 vf3();
    virtual void vf4();
    virtual void vf5();
    u8 _8[0x70];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_23db148, field_78, 0x78);

// 0x7100c3f7d0
u64 Unk_23db148::vf3() {
    return field_78;
}

class Unk_23db188 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x7100c3f960
u32 Unk_23db188::vf0() {
    return 2;
}
