// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_f7ac20(void* self);
void Unk_f7bcb0(void* self);

class Unk_24002a0 {
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

// 0x7100f7aa30
void Unk_24002a0::vf6() {
    Unk_f7ac20(this);
}

class Unk_2400308 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100f7ab20
void Unk_2400308::vf5() {
    Unk_f7ac20(this);
}

class Unk_2400348 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100f7ab30
void Unk_2400348::vf0() {
    Unk_f7ac20(this);
}

class Unk_24003a0 {
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
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual u32 vf18();
};

// 0x7100f7b920
void Unk_24003a0::vf6() {
    Unk_f7bcb0(this);
}

// 0x7100f7b930
u32 Unk_24003a0::vf18() {
    return 1;
}

class Unk_2400448 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100f7ba60
void Unk_2400448::vf5() {
    Unk_f7bcb0(this);
}

class Unk_2400488 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100f7ba70
void Unk_2400488::vf0() {
    Unk_f7bcb0(this);
}
