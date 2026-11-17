// Scope: common
// Constructors that call their base's and set the vptr: `Unk_D::Unk_D() {}`.
// Placeholder classes, named after their vtables: only what the constructors
// need (a base constructor to call, and a key function elsewhere, so that the
// vtable is another TU's).

class Unk_23acc98 {
public:
    Unk_23acc98();
    virtual ~Unk_23acc98();
};

class Unk_23ae240 : public Unk_23acc98 {
public:
    Unk_23ae240();
    ~Unk_23ae240() override;
};

// 0x710084e540
Unk_23ae240::Unk_23ae240() {}
