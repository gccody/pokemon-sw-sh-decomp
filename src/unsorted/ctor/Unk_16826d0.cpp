// Scope: common
// Constructors that call their base's and set the vptr: `Unk_D::Unk_D() {}`.
// Placeholder classes, named after their vtables: only what the constructors
// need (a base constructor to call, and a key function elsewhere, so that the
// vtable is another TU's).

class Unk_2459d48 {
public:
    Unk_2459d48();
    virtual ~Unk_2459d48();
};

class Unk_2459578 : public Unk_2459d48 {
public:
    Unk_2459578();
    ~Unk_2459578() override;
};

// 0x71016826d0
Unk_2459578::Unk_2459578() {}
