// Scope: common
// Constructors that call their base's and set the vptr: `Unk_D::Unk_D() {}`.
// Placeholder classes, named after their vtables: only what the constructors
// need (a base constructor to call, and a key function elsewhere, so that the
// vtable is another TU's).

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

// 0x71003ddd90
Unk_2384ec0::Unk_2384ec0() {}

// 0x71003e1550
Unk_2385670::Unk_2385670() {}
