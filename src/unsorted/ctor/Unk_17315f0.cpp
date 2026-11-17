// Scope: common
// Constructors that call their base's and set the vptr: `Unk_D::Unk_D() {}`.
// Placeholder classes, named after their vtables: only what the constructors
// need (a base constructor to call, and a key function elsewhere, so that the
// vtable is another TU's).

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

class Unk_2460f78 : public Unk_2460778 {
public:
    Unk_2460f78();
    ~Unk_2460f78() override;
};

// 0x71017315f0
Unk_245fb18::Unk_245fb18() {}

// 0x7101739c30
Unk_2460358::Unk_2460358() {}

// 0x710174e3c0
Unk_2460f78::Unk_2460f78() {}
