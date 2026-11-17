// Scope: common
// Constructors that call their base's and set the vptr: `Unk_D::Unk_D() {}`.
// Placeholder classes, named after their vtables: only what the constructors
// need (a base constructor to call, and a key function elsewhere, so that the
// vtable is another TU's).

class Unk_23cfd38 {
public:
    Unk_23cfd38();
    virtual ~Unk_23cfd38();
};

class Unk_23d19a8 : public Unk_23cfd38 {
public:
    Unk_23d19a8();
    ~Unk_23d19a8() override;
};

// 0x7100b84370
Unk_23d19a8::Unk_23d19a8() {}
