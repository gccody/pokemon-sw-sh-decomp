// Scope: common
// Constructors that call their base's and set the vptr: `Unk_D::Unk_D() {}`.
// Placeholder classes, named after their vtables: only what the constructors
// need (a base constructor to call, and a key function elsewhere, so that the
// vtable is another TU's).

class Unk_245b408 {
public:
    Unk_245b408();
    virtual ~Unk_245b408();
};

class Unk_24598a8 : public Unk_245b408 {
public:
    Unk_24598a8();
    ~Unk_24598a8() override;
};

// 0x7101685a70
Unk_24598a8::Unk_24598a8() {}
