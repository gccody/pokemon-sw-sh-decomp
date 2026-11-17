// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_c42080(void* self);
void Unk_c48ff0(void* self);
void Unk_c49140(void* self);
void Unk_c4ea00(void* self);

// Tail-called by lifted functions. Placeholders, like the forwarders' callees.
void Unk_685b20(u64);

class Unk_23db268 {
public:
    virtual ~Unk_23db268();
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
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
};

// 0x7100c418f0
void Unk_23db268::vf22() {}

class Unk_23db1b8 {
public:
    virtual ~Unk_23db1b8();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100c41c30
void Unk_23db1b8::vf6() {
    Unk_c42080(this);
}

class Unk_23db200 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100c41c40
void Unk_23db200::vf5() {
    Unk_c42080(this);
}

class Unk_23db240 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100c41c50
void Unk_23db240::vf0() {
    Unk_c42080(this);
}

class Unk_23db550 {
public:
    virtual ~Unk_23db550();
    virtual void vf2();
    virtual void vf3();
};

// 0x7100c447b0
void Unk_23db550::vf2() {}

class Unk_23db580 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x7100c44830
void Unk_23db580::vf0() {}

class Unk_23db5a0 {
public:
    virtual ~Unk_23db5a0();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual u32 vf6();
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
    virtual u8 vf21();
    virtual void vf22();
    u8 _8[0x5c0];
    u64 field_5c8;
    u8 _5d0[0x82];
    u8 field_652;
};
PKMN_OFFSET_ASSERT(Unk_23db5a0, field_5c8, 0x5c8);
PKMN_OFFSET_ASSERT(Unk_23db5a0, field_652, 0x652);

// 0x7100c46fc0
u32 Unk_23db5a0::vf6() {
    return 1;
}

// 0x7100c46fd0
void Unk_23db5a0::vf8() {}

// 0x7100c45d70
void Unk_23db5a0::vf9() {}

// 0x7100c46fe0
void Unk_23db5a0::vf17() {}

// 0x7100c46ff0
u32 Unk_23db5a0::vf18() {
    return 0;
}

// 0x7100c461d0
void Unk_23db5a0::vf20() {
    if (field_5c8 != 0) {
        Unk_685b20(field_5c8);
    }
}

// 0x7100c47000
u8 Unk_23db5a0::vf21() {
    return field_652;
}

class Unk_23db958 {
public:
    virtual ~Unk_23db958();
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
    virtual bool vf16();
    virtual void vf17();
    virtual u32 vf18();
    virtual void vf19();
    virtual void vf20();
    virtual u32 vf21();
    virtual void vf22();
    u8 _8[0x68];
    u32 field_70;
};
PKMN_OFFSET_ASSERT(Unk_23db958, field_70, 0x70);

// 0x7100c48fd0
void Unk_23db958::vf9() {}

// 0x7100c48fe0
void Unk_23db958::vf10() {
    Unk_c48ff0(this);
}

// 0x7100c49130
void Unk_23db958::vf11() {
    Unk_c49140(this);
}

// 0x7100c49200
void Unk_23db958::vf12() {
    Unk_c49140(this);
}

// 0x7100c49d70
void Unk_23db958::vf13() {}

// 0x7100c49210
void Unk_23db958::vf14() {
    Unk_c48ff0(this);
}

// 0x7100c49320
bool Unk_23db958::vf16() {
    return (field_70 | 1) != 3;
}

// 0x7100c49d80
void Unk_23db958::vf17() {}

// 0x7100c49d90
u32 Unk_23db958::vf18() {
    return 0;
}

// 0x7100c49340
void Unk_23db958::vf19() {
    field_70 = 1;
}

// 0x7100c49da0
void Unk_23db958::vf20() {}

// 0x7100c49db0
u32 Unk_23db958::vf21() {
    return 0;
}

class Unk_23dbb10 {
public:
    virtual ~Unk_23dbb10();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual bool vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual bool vf16();
    virtual void vf17();
    virtual u32 vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    u8 _8[0x138];
    u32 field_140;
    u8 _144[0x214];
    u64 field_358;
    u8 _360[0x4];
    u32 field_364;
};
PKMN_OFFSET_ASSERT(Unk_23dbb10, field_140, 0x140);
PKMN_OFFSET_ASSERT(Unk_23dbb10, field_358, 0x358);
PKMN_OFFSET_ASSERT(Unk_23dbb10, field_364, 0x364);

// 0x7100c4b1c0
bool Unk_23dbb10::vf6() {
    return field_140 == 3;
}

// 0x7100c4b960
void Unk_23dbb10::vf9() {}

// 0x7100c4bd80
void Unk_23dbb10::vf14() {
    field_364 = 0;
}

// 0x7100c4bea0
bool Unk_23dbb10::vf16() {
    return (field_364 & 0xfffffffe) != 2;
}

// 0x7100c4c300
void Unk_23dbb10::vf17() {}

// 0x7100c4c310
u32 Unk_23dbb10::vf18() {
    return 0;
}

// 0x7100c4bb60
void Unk_23dbb10::vf20() {
    if (field_358 != 0) {
        Unk_685b20(field_358);
    }
}

class Unk_23dbde0 {
public:
    virtual ~Unk_23dbde0();
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
    virtual bool vf16();
    virtual void vf17();
    virtual u32 vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    u8 _8[0x2a0];
    u64 field_2a8;
    u8 _2b0[0x4];
    u32 field_2b4;
};
PKMN_OFFSET_ASSERT(Unk_23dbde0, field_2a8, 0x2a8);
PKMN_OFFSET_ASSERT(Unk_23dbde0, field_2b4, 0x2b4);

// 0x7100c4ce80
void Unk_23dbde0::vf9() {}

// 0x7100c4d220
void Unk_23dbde0::vf14() {
    field_2b4 = 0;
}

// 0x7100c4d330
bool Unk_23dbde0::vf16() {
    return (field_2b4 & 0xfffffffe) != 2;
}

// 0x7100c4d4e0
void Unk_23dbde0::vf17() {}

// 0x7100c4d4f0
u32 Unk_23dbde0::vf18() {
    return 0;
}

// 0x7100c4d040
void Unk_23dbde0::vf20() {
    if (field_2a8 != 0) {
        Unk_685b20(field_2a8);
    }
}

class Unk_23dbfd0 {
public:
    virtual ~Unk_23dbfd0();
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
    virtual u32 vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual u32 vf25();
};

// 0x7100c4d7f0
u32 Unk_23dbfd0::vf20() {
    return 1;
}

// 0x7100c4d800
void Unk_23dbfd0::vf21() {}

// 0x7100c4d810
void Unk_23dbfd0::vf22() {}

// 0x7100c4da20
u32 Unk_23dbfd0::vf25() {
    return 1;
}

class Unk_23dc118 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual u32 vf8();
    virtual void vf9();
    virtual void vf10();
};

// 0x7100c4e810
void Unk_23dc118::vf6() {
    Unk_c4ea00(this);
}

// 0x7100c4e710
u32 Unk_23dc118::vf8() {
    return 0;
}

// 0x7100c4e720
void Unk_23dc118::vf9() {}

class Unk_23dc180 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100c4e900
void Unk_23dc180::vf5() {
    Unk_c4ea00(this);
}

class Unk_23dc1c0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100c4e910
void Unk_23dc1c0::vf0() {
    Unk_c4ea00(this);
}
