// Scope: common
// Constructors that call their base's and set the vptr: `Unk_D::Unk_D() {}`.
// Placeholder classes, named after their vtables: only what the constructors
// need (a base constructor to call, and a key function elsewhere, so that the
// vtable is another TU's).

class Unk_245bb18 {
public:
    Unk_245bb18();
    virtual ~Unk_245bb18();
};

class Unk_245c3d8 : public Unk_245bb18 {
public:
    Unk_245c3d8();
    ~Unk_245c3d8() override;
};

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

class Unk_245c4d8 : public Unk_245bc18 {
public:
    Unk_245c4d8();
    ~Unk_245c4d8() override;
};

// 0x71016c2a60
Unk_245c3d8::Unk_245c3d8() {}

// 0x71016c3050
Unk_245c4d8::Unk_245c4d8() {}
