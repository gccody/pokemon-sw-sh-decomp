// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Tail-called by lifted functions. Placeholders, like the forwarders' callees.
void Unk_c1bce0(u64);

class Unk_24241b8 {
public:
    virtual ~Unk_24241b8();
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
    u8 _8[0x4a8];
    u64 field_4b0;
};
PKMN_OFFSET_ASSERT(Unk_24241b8, field_4b0, 0x4b0);

// 0x7101226580
void Unk_24241b8::vf15() {
    Unk_c1bce0(field_4b0);
}

// 0x7101226590
void Unk_24241b8::vf16() {}

class Unk_2424348 {
public:
    virtual ~Unk_2424348();
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

// 0x710122cb60
void Unk_2424348::vf4() {}

// 0x710122cb70
void Unk_2424348::vf5() {
    ::operator delete(this);
}
