// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_cdc0d0(void* self);
void Unk_d54e90(void* self);

// Globals other TUs define, named after their addresses.
extern u32 Unk_27dcdd8;
extern u32 Unk_27dcddc;

class Unk_23ebb88 {
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
    virtual bool vf43();
    virtual void vf44();
    virtual void vf45();
    virtual bool vf46();
};

// 0x7100d55ba0
void Unk_23ebb88::vf6() {
    Unk_cdc0d0(this);
}

// 0x7100d54e80
void Unk_23ebb88::vf8() {
    Unk_d54e90(this);
}

// 0x7100d55bd0
void Unk_23ebb88::vf40() {
    Unk_27dcdd8 = Unk_27dcdd8 + 1;
}

// 0x7100d55bf0
void Unk_23ebb88::vf41() {
    if (Unk_27dcdd8 != 0) {
        Unk_27dcdd8 = Unk_27dcdd8 - 1;
    }
}

// 0x7100d55c10
void Unk_23ebb88::vf42() {
    Unk_27dcdd8 = 0;
}

// 0x7100d55c20
bool Unk_23ebb88::vf43() {
    return Unk_27dcdd8 > 4;
}

// 0x7100d55c40
void Unk_23ebb88::vf44() {
    Unk_27dcddc = Unk_27dcddc + 1;
}

// 0x7100d55c60
void Unk_23ebb88::vf45() {
    Unk_27dcddc = 0;
}

// 0x7100d55c70
bool Unk_23ebb88::vf46() {
    return Unk_27dcddc > 4;
}

class Unk_23ebd10 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100d55e10
void Unk_23ebd10::vf5() {
    Unk_cdc0d0(this);
}

class Unk_23ebd50 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100d55e20
void Unk_23ebd50::vf0() {
    Unk_cdc0d0(this);
}
