// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_da6030(void* self);

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
