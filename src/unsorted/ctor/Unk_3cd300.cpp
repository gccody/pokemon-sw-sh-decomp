// Scope: common
// Constructors that call their base's and set the vptr: `Unk_D::Unk_D() {}`.
// Placeholder classes, named after their vtables: only what the constructors
// need (a base constructor to call, and a key function elsewhere, so that the
// vtable is another TU's).
#include <types.h>

class Unk_2384190 {
public:
    Unk_2384190();
    virtual ~Unk_2384190();
};

class Unk_2383f80 {
public:
    Unk_2383f80();
    virtual ~Unk_2383f80();
};

class Unk_2384ec0 : public Unk_2383f80 {
public:
    Unk_2384ec0();
    ~Unk_2384ec0() override;
};

class Unk_2384080 {
public:
    Unk_2384080();
    virtual ~Unk_2384080();
};

class Unk_2384fc0 : public Unk_2384080 {
public:
    Unk_2384fc0();
    ~Unk_2384fc0() override;
    u8 _8[0x80];
    u64 field_88;
    u64 field_90;
};
PKMN_OFFSET_ASSERT(Unk_2384fc0, field_88, 0x88);
PKMN_OFFSET_ASSERT(Unk_2384fc0, field_90, 0x90);

class Unk_23850d8 : public Unk_2383f80 {
public:
    Unk_23850d8();
    ~Unk_23850d8() override;
    u8 _8[0x50];
    u64 field_58;
    u8 _60[0x8];
    u64 field_68;
};
PKMN_OFFSET_ASSERT(Unk_23850d8, field_58, 0x58);
PKMN_OFFSET_ASSERT(Unk_23850d8, field_68, 0x68);

class Unk_23851d8 : public Unk_2384080 {
public:
    Unk_23851d8();
    ~Unk_23851d8() override;
    u8 _8[0x80];
    u64 field_88;
    u64 field_90;
    u16 field_98;
};
PKMN_OFFSET_ASSERT(Unk_23851d8, field_88, 0x88);
PKMN_OFFSET_ASSERT(Unk_23851d8, field_90, 0x90);
PKMN_OFFSET_ASSERT(Unk_23851d8, field_98, 0x98);

class Unk_2383cc0 {
public:
    Unk_2383cc0();
    virtual ~Unk_2383cc0();
};

class Unk_2385670 : public Unk_2383cc0 {
public:
    Unk_2385670();
    ~Unk_2385670() override;
};

// 0x71003cd300
Unk_2384190::Unk_2384190() {}

// 0x71003ddd90
Unk_2384ec0::Unk_2384ec0() {}

// 0x71003de160
Unk_2384fc0::Unk_2384fc0() : field_88(0), field_90(0) {}

// 0x71003de830
Unk_23850d8::Unk_23850d8() : field_58(0), field_68(0) {}

// 0x71003df030
Unk_23851d8::Unk_23851d8() : field_88(0), field_90(0), field_98(0) {}

// 0x71003e1550
Unk_2385670::Unk_2385670() {}
