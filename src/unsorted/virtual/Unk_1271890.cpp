// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_1271900(void* self);

class Unk_2428950 {
public:
    virtual ~Unk_2428950();
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

// 0x7101271890
void Unk_2428950::vf6() {
    Unk_1271900(this);
}

class Unk_24289b8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71012718c0
void Unk_24289b8::vf5() {
    Unk_1271900(this);
}

class Unk_24289f8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71012718d0
void Unk_24289f8::vf0() {
    Unk_1271900(this);
}
