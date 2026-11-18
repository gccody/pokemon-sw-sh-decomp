// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_5fbe30(void* self);
void Unk_60e5a0(void* self);

// Tail-called by lifted functions. Placeholders, like the forwarders' callees.
void Unk_60f060(u64);
void Unk_612ef0(u64);

class Unk_239b1a8 {
public:
    virtual ~Unk_239b1a8();
    virtual void vf2();
    virtual void vf3();
};

// 0x71005f9d30
void Unk_239b1a8::vf2() {}

class Unk_239b1d8 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x71005f9d40
void Unk_239b1d8::vf0() {}

class Unk_239b398 {
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
};

// 0x71005fbc20
void Unk_239b398::vf6() {
    Unk_5fbe30(this);
}

class Unk_239b3f8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71005fbd50
void Unk_239b3f8::vf5() {
    Unk_5fbe30(this);
}

class Unk_239b438 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71005fbd60
void Unk_239b438::vf0() {
    Unk_5fbe30(this);
}

class Unk_239b548 {
public:
    virtual ~Unk_239b548();
    virtual void vf2();
    virtual void vf3();
};

// 0x71005fd510
void Unk_239b548::vf2() {}

class Unk_239b578 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x71005fd590
void Unk_239b578::vf0() {}

class Unk_239b720 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
};

// 0x71005fe3a0
void Unk_239b720::vf1() {}

class Unk_239b758 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x71005fe3b0
void Unk_239b758::vf0() {}

// 0x71005fe3c0
void Unk_239b758::vf1() {}

class Unk_239b788 {
public:
    virtual ~Unk_239b788();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual u32 vf8();
    virtual u32 vf9();
    u8 _8[0x498];
    u32 field_4a0;
    u32 field_4a4;
};
PKMN_OFFSET_ASSERT(Unk_239b788, field_4a0, 0x4a0);
PKMN_OFFSET_ASSERT(Unk_239b788, field_4a4, 0x4a4);

// 0x71005ff310
u32 Unk_239b788::vf8() {
    return field_4a0;
}

// 0x71005ff320
u32 Unk_239b788::vf9() {
    return field_4a4;
}

class Unk_239c100 {
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
    virtual void vf17();
};

// 0x7100609a40
void Unk_239c100::vf17() {}

class Unk_239c568 {
public:
    virtual ~Unk_239c568();
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
};

// 0x710060e530
void Unk_239c568::vf6() {
    Unk_60e5a0(this);
}

class Unk_239c5f0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710060e560
void Unk_239c5f0::vf5() {
    Unk_60e5a0(this);
}

class Unk_239c630 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710060e570
void Unk_239c630::vf0() {
    Unk_60e5a0(this);
}

class Unk_239c7a8 {
public:
    virtual ~Unk_239c7a8();
    virtual void vf2();
};

// 0x7100612340, 0x7100612350
Unk_239c7a8::~Unk_239c7a8() {}

class Unk_239ca40 {
public:
    virtual ~Unk_239ca40();
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
    u8 _8[0x348];
    u64 field_350;
};
PKMN_OFFSET_ASSERT(Unk_239ca40, field_350, 0x350);

// 0x7100618c60
void Unk_239ca40::vf16() {
    Unk_612ef0(field_350);
}

class Unk_239cc00 {
public:
    virtual ~Unk_239cc00();
    virtual void vf2();
    virtual void vf3();
    virtual u32 vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
};

// 0x7100619a80
u32 Unk_239cc00::vf4() {
    return 1;
}

class Unk_239cc70 {
public:
    virtual ~Unk_239cc70();
    virtual void vf2();
    virtual u32 vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6() = 0;
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
};

// 0x710061b1f0
u32 Unk_239cc70::vf3() {
    return 1;
}

class Unk_239cd48 {
public:
    virtual ~Unk_239cd48();
    virtual void vf2();
    virtual void vf3();
    virtual u32 vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
};

// 0x710061d200
u32 Unk_239cd48::vf4() {
    return 5;
}

class Unk_239cde8 {
public:
    virtual ~Unk_239cde8();
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
    u8 _8[0x200];
    u64 field_208;
};
PKMN_OFFSET_ASSERT(Unk_239cde8, field_208, 0x208);

// 0x710061e170
void Unk_239cde8::vf15() {
    Unk_60f060(field_208);
}
