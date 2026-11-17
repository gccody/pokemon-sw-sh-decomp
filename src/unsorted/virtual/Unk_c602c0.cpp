// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_c668b0(void* self);

class Unk_23dc748 {
public:
    virtual ~Unk_23dc748();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100c609f0, 0x7100c60270
Unk_23dc748::~Unk_23dc748() {}

// 0x7100c602c0
void Unk_23dc748::vf4() {}

class Unk_23dc790 : public Unk_23dc748 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100c60850
void Unk_23dc790::vf4() {}

class Unk_23dc7d8 : public Unk_23dc748 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100c60a50
void Unk_23dc7d8::vf4() {}

class Unk_23dc940 {
public:
    virtual ~Unk_23dc940();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual u32 vf9();
    virtual u32 vf10();
    virtual u8 vf11();
    virtual u32 vf12();
    virtual void vf13();
    virtual u8 vf14();
    virtual u8 vf15();
    virtual void vf16();
    virtual bool vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual u32 vf33();
    virtual void vf34();
    virtual void vf35();
    virtual u32 vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual u32 vf43();
    virtual void vf44();
    virtual void vf45();
    virtual u32 vf46();
    u8 _8[0xa8];
    u64 field_b0;
    u64 field_b8;
    u8 _c0[0x120];
    u8 field_1e0;
    u8 field_1e1;
    u8 field_1e2;
    u8 _1e3[0x5];
    u32 field_1e8;
    u8 _1ec[0x114];
    u64 field_300;
    u64 field_308;
};
PKMN_OFFSET_ASSERT(Unk_23dc940, field_b0, 0xb0);
PKMN_OFFSET_ASSERT(Unk_23dc940, field_b8, 0xb8);
PKMN_OFFSET_ASSERT(Unk_23dc940, field_1e0, 0x1e0);
PKMN_OFFSET_ASSERT(Unk_23dc940, field_1e1, 0x1e1);
PKMN_OFFSET_ASSERT(Unk_23dc940, field_1e2, 0x1e2);
PKMN_OFFSET_ASSERT(Unk_23dc940, field_1e8, 0x1e8);
PKMN_OFFSET_ASSERT(Unk_23dc940, field_300, 0x300);
PKMN_OFFSET_ASSERT(Unk_23dc940, field_308, 0x308);

// 0x7100c628b0
u32 Unk_23dc940::vf10() {
    field_1e0 = 1;
    return 1;
}

// 0x7100c628c0
u32 Unk_23dc940::vf12() {
    return 1;
}

// 0x7100c63380
void Unk_23dc940::vf24() {}

// 0x7100c63390
void Unk_23dc940::vf25() {
    field_308 = field_b8;
    field_300 = field_b0;
}

// 0x7100c64d60
u32 Unk_23dc940::vf36() {
    return 0;
}

class Unk_23dcb30 {
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
    u8 _8[0x60];
    u8 field_68;
};
PKMN_OFFSET_ASSERT(Unk_23dcb30, field_68, 0x68);

// 0x7100c65b20
void Unk_23dcb30::vf9() {}

// 0x7100c65b30
void Unk_23dcb30::vf10() {}

// 0x7100c65b40
void Unk_23dcb30::vf11() {
    field_68 = 0;
}

// 0x7100c65b50
void Unk_23dcb30::vf12() {
    field_68 = 1;
}

// 0x7100c65be0
void Unk_23dcb30::vf15() {}

// 0x7100c65bf0
void Unk_23dcb30::vf16() {}

class Unk_23dcc30 {
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
};

// 0x7100c66560
void Unk_23dcc30::vf6() {
    Unk_c668b0(this);
}

class Unk_23dccb0 {
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
};

// 0x7100c666f0
void Unk_23dccb0::vf5() {
    Unk_c668b0(this);
}

class Unk_23dcd20 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100c66700
void Unk_23dcd20::vf0() {
    Unk_c668b0(this);
}
