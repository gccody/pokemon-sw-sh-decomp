// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_113d0f0(void* self);
void Unk_113d1e0(void* self);

// Tail-called by lifted functions. Placeholders, like the forwarders' callees.
void Unk_68ef10(u64, u32, u32);

class Unk_2419550 {
public:
    virtual ~Unk_2419550();
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
};

// 0x710112daf0
void Unk_2419550::vf14() {}

// 0x710112db00
void Unk_2419550::vf16() {}

// 0x710112e560
void Unk_2419550::vf17() {}

// 0x710112e570
void Unk_2419550::vf18() {}

class Unk_241f3f0 {
public:
    virtual ~Unk_241f3f0();
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
};

// 0x710112eb00
void Unk_241f3f0::vf15() {}

class Unk_2419690 {
public:
    virtual ~Unk_2419690();
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
};

// 0x7101130330
u32 Unk_2419690::vf22() {
    return 1;
}

class Unk_2419800 {
public:
    virtual ~Unk_2419800();
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
};

// 0x7101130b50
void Unk_2419800::vf15() {}

class Unk_2419ad0 {
public:
    virtual ~Unk_2419ad0();
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
    virtual void vf23(bool value);
    u8 _8[0x98];
    u64 field_a0;
};
PKMN_OFFSET_ASSERT(Unk_2419ad0, field_a0, 0xa0);

// 0x7101132c30
void Unk_2419ad0::vf23(bool value) {
    Unk_68ef10(field_a0, value, 0);
}

class Unk_2419c38 {
public:
    virtual ~Unk_2419c38();
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
};

// 0x710113c630
void Unk_2419c38::vf6() {
    Unk_113d0f0(this);
}

class Unk_2419ce8 {
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

// 0x710113c660
void Unk_2419ce8::vf5() {
    Unk_113d0f0(this);
}

class Unk_2419d58 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710113c670
void Unk_2419d58::vf0() {
    Unk_113d0f0(this);
}

class Unk_2419fb8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x710113d550
void Unk_2419fb8::vf6() {
    Unk_113d1e0(this);
}

class Unk_241a000 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710113d660
void Unk_241a000::vf5() {
    Unk_113d1e0(this);
}

class Unk_241a040 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710113d670
void Unk_241a040::vf0() {
    Unk_113d1e0(this);
}
