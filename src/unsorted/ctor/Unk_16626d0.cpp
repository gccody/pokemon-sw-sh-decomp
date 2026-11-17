// Scope: common
// Constructors that call their base's and set the vptr: `Unk_D::Unk_D() {}`.
// Placeholder classes, named after their vtables: only what the constructors
// need (a base constructor to call, and a key function elsewhere, so that the
// vtable is another TU's).

class Unk_245f4a8 {
public:
    Unk_245f4a8();
    virtual ~Unk_245f4a8();
};

class Unk_24573a8 : public Unk_245f4a8 {
public:
    Unk_24573a8();
    ~Unk_24573a8() override;
};

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

class Unk_2457418 : public Unk_245fb18 {
public:
    Unk_2457418();
    ~Unk_2457418() override;
};

class Unk_245f5f8 {
public:
    Unk_245f5f8();
    virtual ~Unk_245f5f8();
};

class Unk_2457d08 : public Unk_245f5f8 {
public:
    Unk_2457d08();
    ~Unk_2457d08() override;
};

class Unk_245f368 {
public:
    Unk_245f368();
    virtual ~Unk_245f368();
};

class Unk_2457e38 : public Unk_245f368 {
public:
    Unk_2457e38();
    ~Unk_2457e38() override;
};

class Unk_245b868 {
public:
    Unk_245b868();
    virtual ~Unk_245b868();
};

class Unk_24580c8 : public Unk_245b868 {
public:
    Unk_24580c8();
    ~Unk_24580c8() override;
};

// 0x71016626d0
Unk_24573a8::Unk_24573a8() {}

// 0x7101662760
Unk_2457418::Unk_2457418() {}

// 0x710166a5c0
Unk_2457d08::Unk_2457d08() {}

// 0x710166ae70
Unk_2457e38::Unk_2457e38() {}

// 0x710166d3c0
Unk_24580c8::Unk_24580c8() {}
