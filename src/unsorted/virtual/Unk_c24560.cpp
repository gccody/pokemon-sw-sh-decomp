// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_c24980(void* self);
void Unk_c28d00(void* self);

class Unk_23d9f88 {
public:
    virtual ~Unk_23d9f88();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100c24560
void Unk_23d9f88::vf6() {
    Unk_c24980(this);
}

class Unk_23d9fd0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100c24590
void Unk_23d9fd0::vf5() {
    Unk_c24980(this);
}

class Unk_23da010 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100c245a0
void Unk_23da010::vf0() {
    Unk_c24980(this);
}

class Unk_23da038 {
public:
    virtual ~Unk_23da038();
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
    virtual u32 vf25();
    virtual u32 vf26();
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
    virtual u32 vf38();
    virtual u32 vf39();
    virtual void vf40();
    virtual void vf41();
};

// 0x7100c278d0
void Unk_23da038::vf18() {}

// 0x7100c278e0
u32 Unk_23da038::vf25() {
    return 1;
}

// 0x7100c278f0
u32 Unk_23da038::vf26() {
    return 1;
}

// 0x7100c27900
void Unk_23da038::vf32() {}

// 0x7100c27910
void Unk_23da038::vf33() {}

// 0x7100c27920
u32 Unk_23da038::vf38() {
    return 1;
}

// 0x7100c27930
u32 Unk_23da038::vf39() {
    return 1;
}

class Unk_23da1c8 {
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
};

// 0x7100c28b50
void Unk_23da1c8::vf6() {
    Unk_c28d00(this);
}

class Unk_23da230 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100c28c20
void Unk_23da230::vf5() {
    Unk_c28d00(this);
}

class Unk_23da270 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100c28c30
void Unk_23da270::vf0() {
    Unk_c28d00(this);
}
