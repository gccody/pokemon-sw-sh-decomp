// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_c38220(void* self);

// Tail-called by lifted functions. Placeholders, like the forwarders' callees.
void Unk_c54770(u64);

// Lifted through their own placeholder structs (cast_member).
struct Unk_c358c0 {
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
};

class Unk_23da768 {
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
    virtual u32 vf10();
    u8 _8[0xe0];
    u32 field_e8;
};
PKMN_OFFSET_ASSERT(Unk_23da768, field_e8, 0xe8);

// 0x7100c2d6f0
u32 Unk_23da768::vf10() {
    return field_e8;
}

class Unk_23da950 {
public:
    virtual ~Unk_23da950();
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
    u8 _8[0x118];
    u64 field_120;
};
PKMN_OFFSET_ASSERT(Unk_23da950, field_120, 0x120);

// 0x7100c36430
void Unk_23da950::vf16() {}

// 0x7100c358c0
void Unk_23da950::vf27() {
    Unk_c358c0* self = reinterpret_cast<Unk_c358c0*>(this);
    self->vf28();
    self->vf31();
    self->vf32();
    self->vf33();
}

// 0x7100c35ac0
void Unk_23da950::vf31() {
    Unk_c54770(field_120);
}

// 0x7100c36440
void Unk_23da950::vf41() {}

class Unk_23daae0 {
public:
    virtual ~Unk_23daae0();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100c364e0
void Unk_23daae0::vf4() {}

// 0x7100c364f0
void Unk_23daae0::vf5() {
    ::operator delete(this);
}

class Unk_23dab28 {
public:
    virtual ~Unk_23dab28();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual u32 vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
};

// 0x7100c38040
void Unk_23dab28::vf6() {
    Unk_c38220(this);
}

// 0x7100c38050
u32 Unk_23dab28::vf7() {
    return 1;
}

// 0x7100c37d70
void Unk_23dab28::vf10() {}

class Unk_23dab90 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100c38080
void Unk_23dab90::vf5() {
    Unk_c38220(this);
}

class Unk_23dabd0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100c38090
void Unk_23dabd0::vf0() {
    Unk_c38220(this);
}
