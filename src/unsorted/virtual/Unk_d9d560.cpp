// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_da1430(void* self);

class Unk_23eea20 {
public:
    virtual ~Unk_23eea20();
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

// 0x7100da0320
void Unk_23eea20::vf6() {
    Unk_da1430(this);
}

// 0x7100d9d560
u32 Unk_23eea20::vf7() {
    return 1;
}

// 0x7100d9d570
void Unk_23eea20::vf8() {}

// 0x7100d9fc10
void Unk_23eea20::vf10() {}

class Unk_23eea88 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100da0350
void Unk_23eea88::vf5() {
    Unk_da1430(this);
}

class Unk_23eeac8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100da0360
void Unk_23eeac8::vf0() {
    Unk_da1430(this);
}
