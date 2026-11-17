// Scope: common
// Constructors that call their base's and set the vptr: `Unk_D::Unk_D() {}`.
// Placeholder classes, named after their vtables: only what the constructors
// need (a base constructor to call, and a key function elsewhere, so that the
// vtable is another TU's).

class Unk_23837a8 {
public:
    Unk_23837a8();
    virtual ~Unk_23837a8();
};

// 0x71003b7880
Unk_23837a8::Unk_23837a8() {}
