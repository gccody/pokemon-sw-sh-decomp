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

// 0x71016a8a10
Unk_245b938::Unk_245b938() {}

// 0x71016a9a20
Unk_245bc18::Unk_245bc18() {}

// 0x71016b3ea0
Unk_245c008::Unk_245c008() {}
