// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_ac7630(void* self);

struct Unk_23c9028_630 {
    u8 _0[0x58];
    u8 field_58;
};
PKMN_OFFSET_ASSERT(Unk_23c9028_630, field_58, 0x58);

class Unk_23c9028 {
public:
    virtual ~Unk_23c9028();
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
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    u8 _8[0x5f8];
    u64 field_600;
    u32 field_608;
    u8 _60c[0x24];
    Unk_23c9028_630* field_630;
};
PKMN_OFFSET_ASSERT(Unk_23c9028, field_600, 0x600);
PKMN_OFFSET_ASSERT(Unk_23c9028, field_608, 0x608);
PKMN_OFFSET_ASSERT(Unk_23c9028, field_630, 0x630);

// 0x7100aced10
void Unk_23c9028::vf20() {
    field_600 = 0;
    field_608 = 0;
}

class Unk_23c9470 {
public:
    virtual ~Unk_23c9470();
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
    virtual void vf17();
    virtual u32 vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
};

// 0x7100ad0bc0
void Unk_23c9470::vf6() {
    Unk_ac7630(this);
}

// 0x7100ad0bd0
void Unk_23c9470::vf17() {}

// 0x7100ad0be0
u32 Unk_23c9470::vf18() {
    return 1;
}

// 0x7100ad0bf0
void Unk_23c9470::vf19() {}

class Unk_23c9530 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100ad0c20
void Unk_23c9530::vf5() {
    Unk_ac7630(this);
}

class Unk_23c9570 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100ad0c30
void Unk_23c9570::vf0() {
    Unk_ac7630(this);
}
