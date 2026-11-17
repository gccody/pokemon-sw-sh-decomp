// Scope: common
// Constructors that call their base's and set the vptr: `Unk_D::Unk_D() {}`.
// Placeholder classes, named after their vtables: only what the constructors
// need (a base constructor to call, and a key function elsewhere, so that the
// vtable is another TU's).

class Unk_2459e98 {
public:
    Unk_2459e98();
    virtual ~Unk_2459e98();
};

class Unk_2459708 : public Unk_2459e98 {
public:
    Unk_2459708();
    ~Unk_2459708() override;
};

class Unk_2459f68 {
public:
    Unk_2459f68();
    virtual ~Unk_2459f68();
};

class Unk_2459768 : public Unk_2459f68 {
public:
    Unk_2459768();
    ~Unk_2459768() override;
};

// 0x7101685480
Unk_2459708::Unk_2459708() {}

// 0x7101685500
Unk_2459768::Unk_2459768() {}
