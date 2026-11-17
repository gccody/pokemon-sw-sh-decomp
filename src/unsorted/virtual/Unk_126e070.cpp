// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_126e670(void* self);

class Unk_2428780 {
public:
    virtual ~Unk_2428780();
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

// 0x710126e600
void Unk_2428780::vf6() {
    Unk_126e670(this);
}

// 0x710126e070
void Unk_2428780::vf7() {}

// 0x710126e5e0
void Unk_2428780::vf9() {}

class Unk_24287e8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710126e630
void Unk_24287e8::vf5() {
    Unk_126e670(this);
}

class Unk_2428828 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710126e640
void Unk_2428828::vf0() {
    Unk_126e670(this);
}
