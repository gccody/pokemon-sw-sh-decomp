// Scope: common
// Constructors that call their base's and set the vptr: `Unk_D::Unk_D() {}`.
// Placeholder classes, named after their vtables: only what the constructors
// need (a base constructor to call, and a key function elsewhere, so that the
// vtable is another TU's).

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

// 0x71003fe230
Unk_2385eb8::Unk_2385eb8() {}

// 0x71003ff8e0
Unk_2385ed8::Unk_2385ed8() {}

// 0x71003ffef0
Unk_2385f30::Unk_2385f30() {}
