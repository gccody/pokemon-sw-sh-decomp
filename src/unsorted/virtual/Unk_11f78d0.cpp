// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_11f79a0(void* self);

class Unk_2422a08 {
public:
    virtual ~Unk_2422a08();
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

// 0x71011f78f0
void Unk_2422a08::vf6() {
    Unk_11f79a0(this);
}

// 0x71011f78d0
void Unk_2422a08::vf9() {}

class Unk_2422a70 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71011f7920
void Unk_2422a70::vf5() {
    Unk_11f79a0(this);
}

class Unk_2422ab0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71011f7930
void Unk_2422ab0::vf0() {
    Unk_11f79a0(this);
}
