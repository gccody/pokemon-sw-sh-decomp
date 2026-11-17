// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_c3d130(void* self);

class Unk_23daf18 {
public:
    virtual ~Unk_23daf18();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual u32 vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
};

// 0x7100c3ce00
void Unk_23daf18::vf6() {
    Unk_c3d130(this);
}

// 0x7100c3bcd0
u32 Unk_23daf18::vf7() {
    return 1;
}

class Unk_23daf80 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100c3ce30
void Unk_23daf80::vf5() {
    Unk_c3d130(this);
}

class Unk_23dafc0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100c3ce40
void Unk_23dafc0::vf0() {
    Unk_c3d130(this);
}
