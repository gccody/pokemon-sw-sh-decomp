// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_1470910(void* self);

class Unk_243d920 {
public:
    virtual ~Unk_243d920();
};

// 0x710146cc90, 0x710146cf90
Unk_243d920::~Unk_243d920() {}

class Unk_243dc10 {
public:
    virtual void vf0();
    virtual void vf1();
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
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
};

// 0x7101470720
void Unk_243dc10::vf6() {
    Unk_1470910(this);
}

class Unk_243dca8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101470810
void Unk_243dca8::vf5() {
    Unk_1470910(this);
}

class Unk_243dce8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101470820
void Unk_243dce8::vf0() {
    Unk_1470910(this);
}
