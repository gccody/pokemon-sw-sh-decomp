// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_fc4520(void* self);

class Unk_2402dc8 {
public:
    virtual ~Unk_2402dc8();
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

// 0x7100fb9aa0
u32 Unk_2402dc8::vf7() {
    return 1;
}

class Unk_2402e98 {
public:
    virtual void vf0();
    virtual void vf1();
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

// 0x7100fc1c40
u32 Unk_2402e98::vf7() {
    return 1;
}

// 0x7100fc1c50
void Unk_2402e98::vf8() {}

// 0x7100fc1d10
void Unk_2402e98::vf10() {}

class Unk_2402f68 {
public:
    virtual ~Unk_2402f68();
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

// 0x7100fc44f0
void Unk_2402f68::vf6() {
    Unk_fc4520(this);
}

// 0x7100fc2d00
u32 Unk_2402f68::vf7() {
    return 1;
}

class Unk_2402fd0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100fc4500
void Unk_2402fd0::vf5() {
    Unk_fc4520(this);
}

class Unk_2403010 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100fc4510
void Unk_2403010::vf0() {
    Unk_fc4520(this);
}

class Unk_2403148 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x7100fc5b40
u32 Unk_2403148::vf0() {
    return 1;
}
