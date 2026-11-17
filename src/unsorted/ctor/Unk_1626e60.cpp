// Scope: common
// Constructors that call their base's and set the vptr: `Unk_D::Unk_D() {}`.
// Placeholder classes, named after their vtables: only what the constructors
// need (a base constructor to call, and a key function elsewhere, so that the
// vtable is another TU's).

class Unk_2453c58 {
public:
    Unk_2453c58();
    virtual ~Unk_2453c58();
};

// 0x7101626e60
Unk_2453c58::Unk_2453c58() {}
