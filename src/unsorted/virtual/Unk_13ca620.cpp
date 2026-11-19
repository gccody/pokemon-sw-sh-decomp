// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_13ceb20(void* self);

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

class Unk_24357a8 {
public:
    virtual ~Unk_24357a8();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
};

// 0x71013ceaf0
void Unk_24357a8::vf6() {
    Unk_13ceb20(this);
}

class Unk_2435818 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71013ceb00
void Unk_2435818::vf5() {
    Unk_13ceb20(this);
}

class Unk_2435858 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71013ceb10
void Unk_2435858::vf0() {
    Unk_13ceb20(this);
}
