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

class Unk_245d2a8 : public Unk_245fb18 {
public:
    Unk_245d2a8();
    ~Unk_245d2a8() override;
};

class Unk_245b6a8 {
public:
    Unk_245b6a8();
    virtual ~Unk_245b6a8();
};

class Unk_245d728 : public Unk_245b6a8 {
public:
    Unk_245d728();
    ~Unk_245d728() override;
};

class Unk_245b638 {
public:
    Unk_245b638();
    virtual ~Unk_245b638();
};

class Unk_245d898 : public Unk_245b638 {
public:
    Unk_245d898();
    ~Unk_245d898() override;
};

// 0x71016d6b00
Unk_245d2a8::Unk_245d2a8() {}

// 0x71016d8320
Unk_245d728::Unk_245d728() {}

// 0x71016d9000
Unk_245d898::Unk_245d898() {}
