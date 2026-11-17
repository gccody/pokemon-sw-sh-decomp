// Scope: common
// Constructors that call their base's and set the vptr: `Unk_D::Unk_D() {}`.
// Placeholder classes, named after their vtables: only what the constructors
// need (a base constructor to call, and a key function elsewhere, so that the
// vtable is another TU's).

class Unk_237ea98 {
public:
    Unk_237ea98();
    virtual ~Unk_237ea98();
};

class Unk_237ea10 : public Unk_237ea98 {
public:
    Unk_237ea10();
    ~Unk_237ea10() override;
};

class Unk_237ec30 : public Unk_237ea98 {
public:
    Unk_237ec30();
    ~Unk_237ec30() override;
};

// 0x710033cfb0
Unk_237ea10::Unk_237ea10() {}

// 0x710033ebb0
Unk_237ec30::Unk_237ec30() {}
