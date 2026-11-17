// Scope: common
// Constructors that call their base's and set the vptr: `Unk_D::Unk_D() {}`.
// Placeholder classes, named after their vtables: only what the constructors
// need (a base constructor to call, and a key function elsewhere, so that the
// vtable is another TU's).
#include <types.h>

class Unk_245f898 {
public:
    Unk_245f898();
    virtual ~Unk_245f898();
};

class Unk_24603f8 {
public:
    Unk_24603f8();
    virtual ~Unk_24603f8();
};

class Unk_245b938 : public Unk_24603f8 {
public:
    Unk_245b938();
    ~Unk_245b938() override;
};

class Unk_245fb18 : public Unk_245b938 {
public:
    Unk_245fb18();
    ~Unk_245fb18() override;
};

class Unk_2460778 {
public:
    Unk_2460778();
    virtual ~Unk_2460778();
};

class Unk_2460358 : public Unk_2460778 {
public:
    Unk_2460358();
    ~Unk_2460358() override;
};

class Unk_2460b28 : public Unk_2460778 {
public:
    Unk_2460b28();
    ~Unk_2460b28() override;
    u8 _8[0x50];
    u64 field_58;
    u16 field_60;
    u8 field_62;
};
PKMN_OFFSET_ASSERT(Unk_2460b28, field_58, 0x58);
PKMN_OFFSET_ASSERT(Unk_2460b28, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_2460b28, field_62, 0x62);

class Unk_2460d78 {
public:
    Unk_2460d78();
    virtual ~Unk_2460d78();
};

class Unk_2460f78 : public Unk_2460778 {
public:
    Unk_2460f78();
    ~Unk_2460f78() override;
};

// 0x710172ead0
Unk_245f898::Unk_245f898() {}

// 0x71017315f0
Unk_245fb18::Unk_245fb18() {}

// 0x7101739c30
Unk_2460358::Unk_2460358() {}

// 0x7101739cf0
Unk_24603f8::Unk_24603f8() {}

// 0x7101747bc0
Unk_2460b28::Unk_2460b28() : field_58(0), field_60(0), field_62(0) {}

// 0x710174a680
Unk_2460d78::Unk_2460d78() {}

// 0x710174e3c0
Unk_2460f78::Unk_2460f78() {}
