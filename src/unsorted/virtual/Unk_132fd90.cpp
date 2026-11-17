// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_132ff60(void* self);

class Unk_2430a28 {
public:
    virtual ~Unk_2430a28();
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

// 0x710132fef0
void Unk_2430a28::vf6() {
    Unk_132ff60(this);
}

// 0x710132fd90
void Unk_2430a28::vf9() {}

class Unk_2430a90 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710132ff20
void Unk_2430a90::vf5() {
    Unk_132ff60(this);
}

class Unk_2430ad0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710132ff30
void Unk_2430ad0::vf0() {
    Unk_132ff60(this);
}
