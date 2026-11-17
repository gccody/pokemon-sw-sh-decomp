// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_2433448 {
public:
    virtual ~Unk_2433448();
    virtual void vf2();
    virtual void vf3();
};

// 0x7101399690, 0x710139a8f0
Unk_2433448::~Unk_2433448() {}

class Unk_2433528 {
public:
    virtual ~Unk_2433528();
    virtual void vf2();
    virtual void vf3();
};

// 0x7101399d20, 0x710139cf50
Unk_2433528::~Unk_2433528() {}

class Unk_24334b8 {
public:
    virtual ~Unk_24334b8();
    virtual void vf2();
    virtual void vf3();
};

// 0x710139ad30, 0x710139c7f0
Unk_24334b8::~Unk_24334b8() {}
