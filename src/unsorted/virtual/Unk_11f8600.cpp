// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_11f8690(void* self);

class Unk_2422ad8 {
public:
    virtual ~Unk_2422ad8();
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

// 0x71011f8620
void Unk_2422ad8::vf6() {
    Unk_11f8690(this);
}

// 0x71011f8600
void Unk_2422ad8::vf9() {}

class Unk_2422b40 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71011f8650
void Unk_2422b40::vf5() {
    Unk_11f8690(this);
}

class Unk_2422b80 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71011f8660
void Unk_2422b80::vf0() {
    Unk_11f8690(this);
}
