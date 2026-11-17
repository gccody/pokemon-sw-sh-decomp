// Scope: common
// Constructors that call their base's and set the vptr: `Unk_D::Unk_D() {}`.
// Placeholder classes, named after their vtables: only what the constructors
// need (a base constructor to call, and a key function elsewhere, so that the
// vtable is another TU's).

class Unk_245b728 {
public:
    Unk_245b728();
    virtual ~Unk_245b728();
};

class Unk_245dcb8 : public Unk_245b728 {
public:
    Unk_245dcb8();
    ~Unk_245dcb8() override;
};

class Unk_245f368 {
public:
    Unk_245f368();
    virtual ~Unk_245f368();
};

class Unk_245df48 : public Unk_245f368 {
public:
    Unk_245df48();
    ~Unk_245df48() override;
};

class Unk_245b868 {
public:
    Unk_245b868();
    virtual ~Unk_245b868();
};

class Unk_245e0f8 : public Unk_245b868 {
public:
    Unk_245e0f8();
    ~Unk_245e0f8() override;
};

// 0x71016f61d0
Unk_245dcb8::Unk_245dcb8() {}

// 0x71017075d0
Unk_245df48::Unk_245df48() {}

// 0x710170b9d0
Unk_245e0f8::Unk_245e0f8() {}
