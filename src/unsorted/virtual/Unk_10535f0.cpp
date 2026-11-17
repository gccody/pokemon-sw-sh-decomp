// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Tail-called by lifted functions. Placeholders, like the forwarders' callees.
void Unk_6a1ee0(u64);

class Unk_240b460 {
public:
    virtual ~Unk_240b460();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71010535f0
void Unk_240b460::vf2() {}

class Unk_240b4a0 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x7101053670
void Unk_240b4a0::vf0() {}

class Unk_240b658 {
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
    u8 _8[0x70];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_240b658, field_78, 0x78);

// 0x7101054650
void Unk_240b658::vf8() {
    Unk_6a1ee0(field_78);
}

class Unk_240b758 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101054f40
void Unk_240b758::vf0() {}

// 0x7101054f50
void Unk_240b758::vf1() {}

// 0x7101054f60
void Unk_240b758::vf2() {}

class Unk_240b780 {
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
    u8 _8[0x70];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_240b780, field_78, 0x78);

// 0x71010556b0
void Unk_240b780::vf8() {
    Unk_6a1ee0(field_78);
}

class Unk_240b880 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71010561a0
void Unk_240b880::vf0() {}

// 0x71010561b0
void Unk_240b880::vf1() {}

// 0x71010561c0
void Unk_240b880::vf2() {}

class Unk_240b970 {
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
    u8 _8[0x70];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_240b970, field_78, 0x78);

// 0x7101056cc0
void Unk_240b970::vf8() {
    Unk_6a1ee0(field_78);
}

class Unk_240ba70 {
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
    u8 _8[0x70];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_240ba70, field_78, 0x78);

// 0x71010578f0
void Unk_240ba70::vf8() {
    Unk_6a1ee0(field_78);
}

class Unk_240bb70 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101058440
void Unk_240bb70::vf0() {}

// 0x7101058450
void Unk_240bb70::vf1() {}

// 0x7101058460
void Unk_240bb70::vf2() {}

class Unk_240bc60 {
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
    u8 _8[0x70];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_240bc60, field_78, 0x78);

// 0x7101058f40
void Unk_240bc60::vf8() {
    Unk_6a1ee0(field_78);
}

class Unk_240bd60 {
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
    u8 _8[0x70];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_240bd60, field_78, 0x78);

// 0x7101059a60
void Unk_240bd60::vf8() {
    Unk_6a1ee0(field_78);
}

class Unk_240be60 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710105a1f0
void Unk_240be60::vf0() {}

// 0x710105a200
void Unk_240be60::vf1() {}

// 0x710105a210
void Unk_240be60::vf2() {}

class Unk_240be88 {
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
    u8 _8[0x70];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_240be88, field_78, 0x78);

// 0x710105a880
void Unk_240be88::vf8() {
    Unk_6a1ee0(field_78);
}

class Unk_240bf88 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710105b080
void Unk_240bf88::vf0() {}

// 0x710105b090
void Unk_240bf88::vf1() {}

// 0x710105b0a0
void Unk_240bf88::vf2() {}
