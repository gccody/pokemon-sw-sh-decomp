// Scope: common
// Constructors that call their base's and set the vptr: `Unk_D::Unk_D() {}`.
// Placeholder classes, named after their vtables: only what the constructors
// need (a base constructor to call, and a key function elsewhere, so that the
// vtable is another TU's).

class Unk_237eb18 {
public:
    Unk_237eb18();
    virtual ~Unk_237eb18();
};

class Unk_2380608 : public Unk_237eb18 {
public:
    Unk_2380608();
    ~Unk_2380608() override;
};

// 0x7100357ac0
Unk_2380608::Unk_2380608() {}
