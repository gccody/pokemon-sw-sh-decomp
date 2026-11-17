// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23b7ea8 {
public:
    virtual ~Unk_23b7ea8();
};

// 0x71008923e0, 0x71008923f0
Unk_23b7ea8::~Unk_23b7ea8() {}

class Unk_23b7ec8 {
public:
    virtual ~Unk_23b7ec8();
};

// 0x7100892af0, 0x7100892b00
Unk_23b7ec8::~Unk_23b7ec8() {}

class Unk_23b8078 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
};

// 0x7100898d20
void Unk_23b8078::vf2() {}

// 0x7100898d30
void Unk_23b8078::vf3() {}

// 0x7100898d40
void Unk_23b8078::vf6() {}

// 0x7100898d50
void Unk_23b8078::vf7() {}

class Unk_23b80c8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100898d60
void Unk_23b80c8::vf1() {}

class Unk_23b80f0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
};

// 0x7100898d70
void Unk_23b80f0::vf1() {}
