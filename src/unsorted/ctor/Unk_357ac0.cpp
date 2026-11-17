// Scope: common
// Constructors that call their base's and set the vptr: `Unk_D::Unk_D() {}`.
// Placeholder classes, named after their vtables: only what the constructors
// need (a base constructor to call, and a key function elsewhere, so that the
// vtable is another TU's).
#include <types.h>

class Unk_237eb18 {
public:
    Unk_237eb18();
    virtual ~Unk_237eb18();
};

class Unk_2380608 : public Unk_237eb18 {
public:
    Unk_2380608();
    ~Unk_2380608() override;
};

class Unk_23836c0 {
public:
    Unk_23836c0();
    virtual ~Unk_23836c0();
};

class Unk_2380c68 : public Unk_23836c0 {
public:
    Unk_2380c68();
    ~Unk_2380c68() override;
    u8 _8[0x8];
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_2380c68, field_10, 0x10);

class Unk_2380db0 {
public:
    Unk_2380db0();
    virtual ~Unk_2380db0();
};

class Unk_2381750 {
public:
    Unk_2381750();
    virtual ~Unk_2381750();
};

class Unk_23817c8 {
public:
    Unk_23817c8();
    virtual ~Unk_23817c8();
};

class Unk_2381808 {
public:
    Unk_2381808();
    virtual ~Unk_2381808();
};

class Unk_2381848 {
public:
    Unk_2381848();
    virtual ~Unk_2381848();
};

class Unk_2381888 {
public:
    Unk_2381888();
    virtual ~Unk_2381888();
};

class Unk_23818c8 {
public:
    Unk_23818c8();
    virtual ~Unk_23818c8();
};

// 0x7100357ac0
Unk_2380608::Unk_2380608() {}

// 0x71003629e0
Unk_2380c68::Unk_2380c68() : field_10(0) {}

// 0x7100363530
Unk_2380db0::Unk_2380db0() {}

// 0x710036a9c0
Unk_2381750::Unk_2381750() {}

// 0x710036ff90
Unk_23817c8::Unk_23817c8() {}

// 0x71003705b0
Unk_2381808::Unk_2381808() {}

// 0x7100370b10
Unk_2381848::Unk_2381848() {}

// 0x7100371050
Unk_2381888::Unk_2381888() {}

// 0x71003714f0
Unk_23818c8::Unk_23818c8() {}
