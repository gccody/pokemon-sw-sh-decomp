// Scope: common
// Constructors that call their base's and set the vptr: `Unk_D::Unk_D() {}`.
// Placeholder classes, named after their vtables: only what the constructors
// need (a base constructor to call, and a key function elsewhere, so that the
// vtable is another TU's).

class Unk_2450d20 {
public:
    Unk_2450d20();
    virtual ~Unk_2450d20();
};

// 0x71015de560
Unk_2450d20::Unk_2450d20() {}
