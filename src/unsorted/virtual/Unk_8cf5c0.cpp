// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_8d0070(void* self);

class Unk_23bb818 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x71008cf5c0
u32 Unk_23bb818::vf0() {
    return 0xc;
}

class Unk_23bb848 {
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

// 0x71008d0040
void Unk_23bb848::vf6() {
    Unk_8d0070(this);
}

// 0x71008cfb90
u32 Unk_23bb848::vf7() {
    return 1;
}

// 0x71008cfd00
void Unk_23bb848::vf10() {}

class Unk_23bb8b0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71008d0050
void Unk_23bb8b0::vf5() {
    Unk_8d0070(this);
}

class Unk_23bb8f0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71008d0060
void Unk_23bb8f0::vf0() {
    Unk_8d0070(this);
}

class Unk_23bb918 {
public:
    virtual ~Unk_23bb918();
    virtual void vf2();
    virtual u64 vf3();
    virtual void vf4();
    virtual void vf5();
    u8 _8[0x50];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_23bb918, field_58, 0x58);

// 0x71008d07d0
u64 Unk_23bb918::vf3() {
    return field_58;
}

class Unk_23bb958 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x71008d0940
u32 Unk_23bb958::vf0() {
    return 1;
}
