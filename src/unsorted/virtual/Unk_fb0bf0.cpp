// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_fb0e40(void* self);

class Unk_24028d0 {
public:
    virtual ~Unk_24028d0();
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

// 0x7100fb0dd0
void Unk_24028d0::vf6() {
    Unk_fb0e40(this);
}

// 0x7100fb0bf0
void Unk_24028d0::vf9() {}

class Unk_2402938 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100fb0e00
void Unk_2402938::vf5() {
    Unk_fb0e40(this);
}

class Unk_2402978 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100fb0e10
void Unk_2402978::vf0() {
    Unk_fb0e40(this);
}
