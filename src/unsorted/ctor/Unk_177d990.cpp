// Scope: common
// Constructors that call their base's and set the vptr: `Unk_D::Unk_D() {}`.
// Placeholder classes, named after their vtables: only what the constructors
// need (a base constructor to call, and a key function elsewhere, so that the
// vtable is another TU's).

class Unk_246a9e8 {
public:
    Unk_246a9e8();
    virtual ~Unk_246a9e8();
};

class Unk_246aa70 {
public:
    Unk_246aa70();
    virtual ~Unk_246aa70();
};

// 0x710177d990
Unk_246a9e8::Unk_246a9e8() {}

// 0x710177dd40
Unk_246aa70::Unk_246aa70() {}
