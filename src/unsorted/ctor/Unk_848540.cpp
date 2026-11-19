// Scope: common
// Constructors that call their base's and set the vptr: `Unk_D::Unk_D() {}`.
// Placeholder classes, named after their vtables: only what the constructors
// need (a base constructor to call, and a key function elsewhere, so that the
// vtable is another TU's).
// A class with nothing but its destructors has no key function: its destructor
// is implicit, and its vtable and D0 are emitted here, with its constructor.

class Unk_23acc98 {
public:
    Unk_23acc98();
    virtual ~Unk_23acc98() {}
};

class Unk_23ade78 : public Unk_23acc98 {
public:
    Unk_23ade78();
};

// 0x7100848540
Unk_23ade78::Unk_23ade78() {}
