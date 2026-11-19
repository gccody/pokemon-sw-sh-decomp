// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_2435570 {
public:
    virtual ~Unk_2435570();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x71013ca6d0, 0x71013ca5b0
Unk_2435570::~Unk_2435570() {}

// 0x71013ca620
void Unk_2435570::vf4() {}

// 0x71013ca630
void Unk_2435570::vf5() {
    ::operator delete(this);
}

class Unk_2435688 {
public:
    virtual ~Unk_2435688();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x71013cd090
void Unk_2435688::vf4() {}

// 0x71013cd0a0
void Unk_2435688::vf5() {
    ::operator delete(this);
}
