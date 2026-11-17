// Scope: common
// Constructors that call their base's and set the vptr: `Unk_D::Unk_D() {}`.
// Placeholder classes, named after their vtables: only what the constructors
// need (a base constructor to call, and a key function elsewhere, so that the
// vtable is another TU's).
#include <types.h>

class Unk_2385eb8 {
public:
    Unk_2385eb8();
    virtual ~Unk_2385eb8();
};

class Unk_2385ed8 {
public:
    Unk_2385ed8();
    virtual ~Unk_2385ed8();
};

class Unk_2385ab8 {
public:
    Unk_2385ab8();
    virtual ~Unk_2385ab8();
};

class Unk_2385f30 : public Unk_2385ab8 {
public:
    Unk_2385f30();
    ~Unk_2385f30() override;
};

class Unk_23862c0 : public Unk_2385ab8 {
public:
    Unk_23862c0();
    ~Unk_23862c0() override;
    u8 _8[0x620];
    u32 field_628;
    u8 _62c[0x4];
    u64 field_630;
    u64 field_638;
    u64 field_640;
};
PKMN_OFFSET_ASSERT(Unk_23862c0, field_628, 0x628);
PKMN_OFFSET_ASSERT(Unk_23862c0, field_630, 0x630);
PKMN_OFFSET_ASSERT(Unk_23862c0, field_638, 0x638);
PKMN_OFFSET_ASSERT(Unk_23862c0, field_640, 0x640);

// 0x71003fe230
Unk_2385eb8::Unk_2385eb8() {}

// 0x71003ff8e0
Unk_2385ed8::Unk_2385ed8() {}

// 0x71003ffef0
Unk_2385f30::Unk_2385f30() {}

// 0x7100401220
Unk_23862c0::Unk_23862c0() : field_628(0), field_630(0), field_638(0), field_640(0) {}
