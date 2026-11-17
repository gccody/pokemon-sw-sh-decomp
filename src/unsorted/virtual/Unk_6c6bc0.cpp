// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Tail-called by lifted functions. Placeholders, like the forwarders' callees.
void Unk_16c67f0(u64);

// Globals other TUs define, named after their addresses.
extern u64 Unk_27fb310;

class Unk_23a3f28 {
public:
    virtual ~Unk_23a3f28();
    virtual u32 vf2();
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
    virtual u8 vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    u8 _8[0x4ed];
    u8 field_4f5;
};
PKMN_OFFSET_ASSERT(Unk_23a3f28, field_4f5, 0x4f5);

// 0x71006c8cd0
u32 Unk_23a3f28::vf2() {
    return 2;
}

// 0x71006c6bc0
u8 Unk_23a3f28::vf22() {
    return field_4f5;
}

// 0x71006c84b0
void Unk_23a3f28::vf24() {
    Unk_16c67f0(Unk_27fb310);
}

class Unk_23a4018 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual const char* vf5();
};

// 0x71006c8ce0
const char* Unk_23a4018::vf5() {
    return "RandomSession";
}

class Unk_23a4058 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual u32 vf2();
    virtual void vf3();
    virtual void vf4();
    virtual const char* vf5();
};

// 0x71006c8cf0
u32 Unk_23a4058::vf2() {
    return 0;
}

// 0x71006c8d00
const char* Unk_23a4058::vf5() {
    return "BindNgs";
}

class Unk_23a4098 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual u32 vf2();
    virtual void vf3();
    virtual void vf4();
    virtual const char* vf5();
};

// 0x71006c8d10
u32 Unk_23a4098::vf2() {
    return 0;
}

// 0x71006c8d20
const char* Unk_23a4098::vf5() {
    return "UnbindNgs";
}

class Unk_23a40d8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual u32 vf2();
    virtual void vf3();
    virtual void vf4();
    virtual const char* vf5();
};

// 0x71006c8d30
u32 Unk_23a40d8::vf2() {
    return 0;
}

// 0x71006c8d40
const char* Unk_23a40d8::vf5() {
    return "SearchSession";
}

class Unk_23a4118 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual const char* vf5();
};

// 0x71006c8d50
const char* Unk_23a4118::vf5() {
    return "JoinSession";
}

class Unk_23a4158 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual const char* vf5();
};

// 0x71006c8d60
const char* Unk_23a4158::vf5() {
    return "JoinSessionWithId";
}

class Unk_23a4198 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual u32 vf2();
    virtual void vf3();
    virtual void vf4();
    virtual const char* vf5();
};

// 0x71006c8d70
u32 Unk_23a4198::vf2() {
    return 0;
}

// 0x71006c8d80
const char* Unk_23a4198::vf5() {
    return "CreateSession";
}

class Unk_23a41d8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual u32 vf2();
    virtual void vf3();
    virtual void vf4();
    virtual const char* vf5();
};

// 0x71006c8d90
u32 Unk_23a41d8::vf2() {
    return 1;
}

// 0x71006c8da0
const char* Unk_23a41d8::vf5() {
    return "CheckBlock";
}
