// Scope: common
// Constructors that call their base's and set the vptr: `Unk_D::Unk_D() {}`.
// Placeholder classes, named after their vtables: only what the constructors
// need (a base constructor to call, and a key function elsewhere, so that the
// vtable is another TU's).
#include <types.h>

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

class Unk_245a3d8 : public Unk_245fb18 {
public:
    Unk_245a3d8();
    ~Unk_245a3d8() override;
};

class Unk_245f368 {
public:
    Unk_245f368();
    virtual ~Unk_245f368();
};

class Unk_245a928 : public Unk_245f368 {
public:
    Unk_245a928();
    ~Unk_245a928() override;
};

class Unk_245ffb8 {
public:
    Unk_245ffb8();
    virtual ~Unk_245ffb8();
};

class Unk_245b538 : public Unk_245ffb8 {
public:
    Unk_245b538();
    ~Unk_245b538() override;
    u8 _8[0x4];
    u32 field_c;
};
PKMN_OFFSET_ASSERT(Unk_245b538, field_c, 0xc);

class Unk_2460698 {
public:
    Unk_2460698();
    virtual ~Unk_2460698();
};

class Unk_245bc18 : public Unk_2460698 {
public:
    Unk_245bc18();
    ~Unk_245bc18() override;
};

class Unk_2460ce8 {
public:
    Unk_2460ce8();
    virtual ~Unk_2460ce8();
};

class Unk_245bdf8 : public Unk_2460ce8 {
public:
    Unk_245bdf8();
    ~Unk_245bdf8() override;
    u8 _8[0x150];
    u64 field_158;
};
PKMN_OFFSET_ASSERT(Unk_245bdf8, field_158, 0x158);

class Unk_2461018 {
public:
    Unk_2461018();
    virtual ~Unk_2461018();
};

class Unk_245c008 : public Unk_2461018 {
public:
    Unk_245c008();
    ~Unk_245c008() override;
};

// 0x710168df70
Unk_245a3d8::Unk_245a3d8() {}

// 0x710168f8a0
Unk_245a928::Unk_245a928() {}

// 0x710169ae90
Unk_245b538::Unk_245b538() : field_c(0) {}

// 0x71016a8a10
Unk_245b938::Unk_245b938() {}

// 0x71016a9a20
Unk_245bc18::Unk_245bc18() {}

// 0x71016b03a0
Unk_245bdf8::Unk_245bdf8() : field_158(0) {}

// 0x71016b3ea0
Unk_245c008::Unk_245c008() {}
