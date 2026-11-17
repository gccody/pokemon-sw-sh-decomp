// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_f0ce40(void* self);
void Unk_14e1f30(void* self);

// Tail-called by lifted functions. Placeholders, like the forwarders' callees.
void Unk_14e65e0(void*, u32, u32, u32);

class Unk_2444570 {
public:
    virtual ~Unk_2444570();
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
    virtual void vf12() = 0;
    virtual void vf13();
    virtual void vf14();
    virtual void vf15() = 0;
    virtual void vf16();
    virtual void vf17();
    virtual void vf18() = 0;
    virtual void vf19() = 0;
    virtual void vf20() = 0;
    virtual void vf21();
    virtual void vf22() = 0;
    virtual void vf23() = 0;
    virtual u32 vf24();
    virtual u8 vf25();
    virtual void vf26();
    u8 _8[0x7c];
    u8 field_84;
};
PKMN_OFFSET_ASSERT(Unk_2444570, field_84, 0x84);

// 0x71014e1c70
void Unk_2444570::vf6() {
    Unk_14e1f30(this);
}

// 0x71014e1ce0
void Unk_2444570::vf11() {}

// 0x71014e1cf0
void Unk_2444570::vf13() {}

// 0x71014e1d00
void Unk_2444570::vf14() {}

// 0x71014e1d10
void Unk_2444570::vf16() {}

// 0x71014e1d40
void Unk_2444570::vf21() {}

// 0x71014e1d50
u32 Unk_2444570::vf24() {
    return 0;
}

// 0x71014e1d60
u8 Unk_2444570::vf25() {
    return field_84;
}

class Unk_2444658 {
public:
    virtual ~Unk_2444658();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71014e1e40
void Unk_2444658::vf5() {
    Unk_14e1f30(this);
}

class Unk_2444698 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71014e1e50
void Unk_2444698::vf0() {
    Unk_14e1f30(this);
}

class Unk_24446c0 {
public:
    virtual ~Unk_24446c0();
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
    virtual bool vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    u8 _8[0x79];
    u8 field_81;
};
PKMN_OFFSET_ASSERT(Unk_24446c0, field_81, 0x81);

// 0x71014e28f0
bool Unk_24446c0::vf22() {
    return field_81 == 0;
}

// 0x71014e2c40
void Unk_24446c0::vf30() {}

// 0x71014e2c50
void Unk_24446c0::vf31() {}

class Unk_2444b38 {
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
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual u32 vf22();
    virtual u32 vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
};

// 0x71014e5a50
void Unk_2444b38::vf6() {
    Unk_f0ce40(this);
}

// 0x71014e5a60
void Unk_2444b38::vf12() {}

// 0x71014e5a70
void Unk_2444b38::vf15() {}

// 0x71014e5a80
void Unk_2444b38::vf18() {}

// 0x71014e5a90
void Unk_2444b38::vf19() {}

// 0x71014e5aa0
void Unk_2444b38::vf20() {}

// 0x71014e5ab0
u32 Unk_2444b38::vf22() {
    return 1;
}

// 0x71014e5ac0
u32 Unk_2444b38::vf23() {
    return 1;
}

// 0x71014e5980
void Unk_2444b38::vf26() {}

// 0x71014e2c30
void Unk_2444b38::vf28() {}

// 0x71014e5ad0
void Unk_2444b38::vf29() {}

class Unk_2444850 {
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
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual u32 vf22();
    virtual u32 vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
};

// 0x71014e2f00
void Unk_2444850::vf12() {}

// 0x71014e2f10
void Unk_2444850::vf15() {}

// 0x71014e2f20
void Unk_2444850::vf18() {}

// 0x71014e2f30
void Unk_2444850::vf19() {}

// 0x71014e2f40
void Unk_2444850::vf20() {}

// 0x71014e2f50
u32 Unk_2444850::vf22() {
    return 1;
}

// 0x71014e2f60
u32 Unk_2444850::vf23() {
    return 1;
}

class Unk_24449a0 {
public:
    virtual ~Unk_24449a0();
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
    virtual u32 vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
};

// 0x71014e5740
void Unk_24449a0::vf13() {}

// 0x71014e5750
void Unk_24449a0::vf18() {}

// 0x71014e5040
u32 Unk_24449a0::vf22() {
    return 1;
}

class Unk_2444c38 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71014e5c60
void Unk_2444c38::vf5() {
    Unk_f0ce40(this);
}

class Unk_2444c78 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71014e5c70
void Unk_2444c78::vf0() {
    Unk_f0ce40(this);
}

struct Unk_2444ca0_408 {
    u8 _0[0x8];
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_2444ca0_408, field_8, 0x8);

class Unk_2444ca0 {
public:
    virtual ~Unk_2444ca0();
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
    virtual u32 vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    u8 _8[0x400];
    Unk_2444ca0_408* field_408;
};
PKMN_OFFSET_ASSERT(Unk_2444ca0, field_408, 0x408);

// 0x71014e7340
void Unk_2444ca0::vf10() {
    Unk_14e65e0(this, field_408->field_8, field_408->field_8, 0);
}

// 0x71014e6e00
void Unk_2444ca0::vf12() {}

// 0x71014e6f30
u32 Unk_2444ca0::vf22() {
    return 1;
}
