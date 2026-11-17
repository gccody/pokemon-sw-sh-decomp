// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_15b6e10(void* self);

class Unk_23a2b20 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x71006ab9e0
void Unk_23a2b20::vf1() {
    Unk_15b6e10(this);
}

class Unk_23a2bc0 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x71006abe10
void Unk_23a2bc0::vf1() {
    Unk_15b6e10(this);
}

class Unk_23a2be0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x71006abe20
void Unk_23a2be0::vf1() {
    Unk_15b6e10(this);
}
