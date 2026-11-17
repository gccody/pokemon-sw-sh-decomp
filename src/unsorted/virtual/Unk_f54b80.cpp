// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_f54c10(void* self);

class Unk_23fe7f8 {
public:
    virtual ~Unk_23fe7f8();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
};

// 0x7100f54ba0
void Unk_23fe7f8::vf6() {
    Unk_f54c10(this);
}

// 0x7100f54b80
void Unk_23fe7f8::vf9() {}

class Unk_23fe860 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100f54bd0
void Unk_23fe860::vf5() {
    Unk_f54c10(this);
}

class Unk_23fe8a0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100f54be0
void Unk_23fe8a0::vf0() {
    Unk_f54c10(this);
}
