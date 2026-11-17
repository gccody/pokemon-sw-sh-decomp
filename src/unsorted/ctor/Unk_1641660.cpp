// Scope: common
// Constructors that call their base's and set the vptr: `Unk_D::Unk_D() {}`.
// Placeholder classes, named after their vtables: only what the constructors
// need (a base constructor to call, and a key function elsewhere, so that the
// vtable is another TU's).

class Unk_2455720 {
public:
    Unk_2455720();
    virtual ~Unk_2455720();
};

// 0x7101641660
Unk_2455720::Unk_2455720() {}
