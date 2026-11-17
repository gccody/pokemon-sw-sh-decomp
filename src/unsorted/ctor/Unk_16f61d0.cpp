// Scope: common
// Constructors that call their base's and set the vptr: `Unk_D::Unk_D() {}`.
// Placeholder classes, named after their vtables: only what the constructors
// need (a base constructor to call, and a key function elsewhere, so that the
// vtable is another TU's).
#include <types.h>

class Unk_245b728 {
public:
    Unk_245b728();
    virtual ~Unk_245b728();
};

class Unk_245dcb8 : public Unk_245b728 {
public:
    Unk_245dcb8();
    ~Unk_245dcb8() override;
};

class Unk_245f278 {
public:
    Unk_245f278();
    virtual ~Unk_245f278();
};

class Unk_245dec8 : public Unk_245f278 {
public:
    Unk_245dec8();
    ~Unk_245dec8() override;
    u8 _8[0x98];
    u64 field_a0;
    u8 _a8[0x18];
    u64 field_c0;
    u8 field_c8;
    u8 _c9[0x7];
    u64 field_d0;
};
PKMN_OFFSET_ASSERT(Unk_245dec8, field_a0, 0xa0);
PKMN_OFFSET_ASSERT(Unk_245dec8, field_c0, 0xc0);
PKMN_OFFSET_ASSERT(Unk_245dec8, field_c8, 0xc8);
PKMN_OFFSET_ASSERT(Unk_245dec8, field_d0, 0xd0);

class Unk_245f368 {
public:
    Unk_245f368();
    virtual ~Unk_245f368();
};

class Unk_245df48 : public Unk_245f368 {
public:
    Unk_245df48();
    ~Unk_245df48() override;
};

class Unk_245b868 {
public:
    Unk_245b868();
    virtual ~Unk_245b868();
};

class Unk_245e0f8 : public Unk_245b868 {
public:
    Unk_245e0f8();
    ~Unk_245e0f8() override;
};

class Unk_245fa38 {
public:
    Unk_245fa38();
    virtual ~Unk_245fa38();
};

class Unk_245e168 : public Unk_245fa38 {
public:
    Unk_245e168();
    ~Unk_245e168() override;
    u8 _8[0x90];
    u64 field_98;
};
PKMN_OFFSET_ASSERT(Unk_245e168, field_98, 0x98);

class Unk_2460028 {
public:
    Unk_2460028();
    virtual ~Unk_2460028();
};

class Unk_245e268 : public Unk_2460028 {
public:
    Unk_245e268();
    ~Unk_245e268() override;
    u8 _8[0x90];
    u64 field_98;
};
PKMN_OFFSET_ASSERT(Unk_245e268, field_98, 0x98);

class Unk_245faa8 {
public:
    Unk_245faa8();
    virtual ~Unk_245faa8();
};

class Unk_245e2e8 : public Unk_245faa8 {
public:
    Unk_245e2e8();
    ~Unk_245e2e8() override;
    u8 _8[0x90];
    u64 field_98;
};
PKMN_OFFSET_ASSERT(Unk_245e2e8, field_98, 0x98);

// 0x71016f61d0
Unk_245dcb8::Unk_245dcb8() {}

// 0x7101706080
Unk_245dec8::Unk_245dec8() : field_a0(0), field_c0(0), field_c8(0), field_d0(0) {}

// 0x71017075d0
Unk_245df48::Unk_245df48() {}

// 0x710170b9d0
Unk_245e0f8::Unk_245e0f8() {}

// 0x710170beb0
Unk_245e168::Unk_245e168() : field_98(0) {}

// 0x710170e860
Unk_245e268::Unk_245e268() : field_98(0) {}

// 0x710170fe40
Unk_245e2e8::Unk_245e2e8() : field_98(0) {}
