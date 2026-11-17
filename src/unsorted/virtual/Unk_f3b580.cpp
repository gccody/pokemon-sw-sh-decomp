// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_f3cc70(void* self);

class Unk_23fd518 {
public:
    virtual ~Unk_23fd518();
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

// 0x7100f3c710
void Unk_23fd518::vf6() {
    Unk_f3cc70(this);
}

// 0x7100f3b580
u32 Unk_23fd518::vf7() {
    return 1;
}

class Unk_23fd580 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100f3c720
void Unk_23fd580::vf5() {
    Unk_f3cc70(this);
}

class Unk_23fd5c0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100f3c730
void Unk_23fd5c0::vf0() {
    Unk_f3cc70(this);
}

class Unk_23fd5e8 {
public:
    virtual ~Unk_23fd5e8();
    virtual void vf2();
    virtual u64 vf3();
    virtual void vf4();
    virtual void vf5();
    u8 _8[0xb0];
    u64 field_b8;
};
PKMN_OFFSET_ASSERT(Unk_23fd5e8, field_b8, 0xb8);

// 0x7100f3d480
u64 Unk_23fd5e8::vf3() {
    return field_b8;
}

class Unk_23fd628 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x7100f3d610
u32 Unk_23fd628::vf0() {
    return 4;
}
