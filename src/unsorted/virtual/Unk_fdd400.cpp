// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_fdd670(void* self);

class Unk_2404da8 {
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
};

// 0x7100fdd400
void Unk_2404da8::vf6() {
    Unk_fdd670(this);
}

class Unk_2404e10 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100fdd530
void Unk_2404e10::vf5() {
    Unk_fdd670(this);
}

class Unk_2404e50 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100fdd540
void Unk_2404e50::vf0() {
    Unk_fdd670(this);
}
