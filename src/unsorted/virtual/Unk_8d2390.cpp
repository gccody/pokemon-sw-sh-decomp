// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23f43c8.h"

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_8d3f10(void* self);
void Unk_8da520(void* self);

// Lifted through their own placeholder structs (cast_member).
struct Unk_8d2390_700 {
    u8 _0[0x8c];
    u32 field_8c;
};
PKMN_OFFSET_ASSERT(Unk_8d2390_700, field_8c, 0x8c);

struct Unk_8d2390 {
    u8 _0[0x2c0];
    u8 field_2c0;
    u8 _2c1[0x43f];
    Unk_8d2390_700* field_700;
};
PKMN_OFFSET_ASSERT(Unk_8d2390, field_2c0, 0x2c0);
PKMN_OFFSET_ASSERT(Unk_8d2390, field_700, 0x700);

class Unk_23bba38 {
public:
    virtual ~Unk_23bba38();
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
};

// 0x71008d2390
u32 Unk_23bba38::vf25() {
    const Unk_8d2390* self = reinterpret_cast<const Unk_8d2390*>(this);
    if (self->field_2c0 != 0) {
        self->field_700->field_8c = 4;
    }
    return 1;
}

class Unk_23bbc80 : public Unk_23f43c8 {
public:
    void vf9() override;
    void vf7() override;
    u32 vf8() override;
};

// 0x71008d5c00
void Unk_23bbc80::vf9() {}

class Unk_23bbd50 {
public:
    virtual ~Unk_23bbd50();
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
};

// 0x71008d8670
void Unk_23bbd50::vf6() {
    Unk_8d3f10(this);
}

class Unk_23bbde8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71008d86a0
void Unk_23bbde8::vf5() {
    Unk_8d3f10(this);
}

class Unk_23bbe28 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71008d86b0
void Unk_23bbe28::vf0() {
    Unk_8d3f10(this);
}

class Unk_23bbe68 {
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
};

// 0x71008da230
void Unk_23bbe68::vf6() {
    Unk_8da520(this);
}

class Unk_23bbf00 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71008da3a0
void Unk_23bbf00::vf5() {
    Unk_8da520(this);
}

class Unk_23bbf40 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71008da3b0
void Unk_23bbf40::vf0() {
    Unk_8da520(this);
}

class Unk_23bc050 : public Unk_23f43c8 {
public:
    void vf9() override;
    void vf7() override;
    u32 vf8() override;
};

// 0x71008dc120
void Unk_23bc050::vf9() {}

class Unk_23bc120 {
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

// 0x71008dc670
void Unk_23bc120::vf9() {}

class Unk_23bc1f0 : public Unk_23f43c8 {
public:
    void vf9() override;
    void vf7() override;
    u32 vf8() override;
};

// 0x71008dc9f0
void Unk_23bc1f0::vf9() {}

class Unk_23bc2c0 {
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

// 0x71008dd190
void Unk_23bc2c0::vf9() {}

class Unk_23bc390 : public Unk_23f43c8 {
public:
    void vf9() override;
    void vf7() override;
    u32 vf8() override;
};

// 0x71008dd7e0
void Unk_23bc390::vf9() {}

class Unk_23bc460 : public Unk_23f43c8 {
public:
    void vf9() override;
    void vf7() override;
    u32 vf8() override;
};

// 0x71008ddba0
void Unk_23bc460::vf9() {}

class Unk_23bc760 {
public:
    virtual ~Unk_23bc760();
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

// 0x71008e2200
u32 Unk_23bc760::vf7() {
    return 1;
}

// 0x71008e2330
void Unk_23bc760::vf10() {}
