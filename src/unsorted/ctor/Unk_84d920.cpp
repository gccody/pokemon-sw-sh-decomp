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

class Unk_23ae180 : public Unk_23acc98 {
public:
    Unk_23ae180();
    ~Unk_23ae180() override;
};

// 0x710084d920
Unk_23ae180::Unk_23ae180() {}
