// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_d504a0(void* self);
void Unk_d514e0(void* self);
void Unk_d51aa0(void* self);

// Globals other TUs define, named after their addresses.
extern u32 Unk_27dcbd8;
extern u32 Unk_27dcbdc;

class Unk_23eab80 {
public:
    virtual ~Unk_23eab80();
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
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
};

// 0x7100d50430
void Unk_23eab80::vf6() {
    Unk_d504a0(this);
}

class Unk_23ead10 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100d50460
void Unk_23ead10::vf5() {
    Unk_d504a0(this);
}

class Unk_23ead50 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100d50470
void Unk_23ead50::vf0() {
    Unk_d504a0(this);
}

class Unk_23ead78 {
public:
    virtual ~Unk_23ead78();
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
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual bool vf43();
    virtual void vf44();
    virtual void vf45();
    virtual bool vf46();
};

// 0x7100d50f10
void Unk_23ead78::vf40() {
    Unk_27dcbd8 = Unk_27dcbd8 + 1;
}

// 0x7100d50f30
void Unk_23ead78::vf41() {
    if (Unk_27dcbd8 != 0) {
        Unk_27dcbd8 = Unk_27dcbd8 - 1;
    }
}

// 0x7100d50f50
void Unk_23ead78::vf42() {
    Unk_27dcbd8 = 0;
}

// 0x7100d50f60
bool Unk_23ead78::vf43() {
    return Unk_27dcbd8 > 9;
}

// 0x7100d50f80
void Unk_23ead78::vf44() {
    Unk_27dcbdc = Unk_27dcbdc + 1;
}

// 0x7100d50fa0
void Unk_23ead78::vf45() {
    Unk_27dcbdc = 0;
}

// 0x7100d50fb0
bool Unk_23ead78::vf46() {
    return Unk_27dcbdc > 9;
}

class Unk_23eaf68 {
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
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
};

// 0x7100d51230
void Unk_23eaf68::vf6() {
    Unk_d514e0(this);
}

class Unk_23eb0f0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100d51380
void Unk_23eb0f0::vf5() {
    Unk_d514e0(this);
}

class Unk_23eb130 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100d51390
void Unk_23eb130::vf0() {
    Unk_d514e0(this);
}

class Unk_23eb158 {
public:
    virtual ~Unk_23eb158();
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
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
};

// 0x7100d51a30
void Unk_23eb158::vf6() {
    Unk_d51aa0(this);
}

class Unk_23eb2e8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100d51a60
void Unk_23eb2e8::vf5() {
    Unk_d51aa0(this);
}

class Unk_23eb328 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100d51a70
void Unk_23eb328::vf0() {
    Unk_d51aa0(this);
}
