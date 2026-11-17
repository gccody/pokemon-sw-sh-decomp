// Scope: common
// Constructors that call their base's and set the vptr: `Unk_D::Unk_D() {}`.
// Placeholder classes, named after their vtables: only what the constructors
// need (a base constructor to call, and a key function elsewhere, so that the
// vtable is another TU's).

class Unk_24937a0 {
public:
    Unk_24937a0();
    virtual ~Unk_24937a0();
};

class Unk_2493bf0 : public Unk_24937a0 {
public:
    Unk_2493bf0();
    ~Unk_2493bf0() override;
};

// 0x71017b2ff0
Unk_2493bf0::Unk_2493bf0() {}
