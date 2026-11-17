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

class Unk_245a3d8 : public Unk_245fb18 {
public:
    Unk_245a3d8();
    ~Unk_245a3d8() override;
};

class Unk_2458be8 : public Unk_245a3d8 {
public:
    Unk_2458be8();
    ~Unk_2458be8() override;
};

// 0x710167c410
Unk_2458be8::Unk_2458be8() {}
