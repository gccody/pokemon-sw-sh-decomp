// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23eee38 {
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

// 0x7100da5f70
u32 Unk_23eee38::vf7() {
    return 1;
}

// 0x7100da5ff0
void Unk_23eee38::vf10() {}

class Unk_23eef08 {
public:
    virtual ~Unk_23eef08();
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

// 0x7100da6340
u32 Unk_23eef08::vf7() {
    return 1;
}

// 0x7100da6350
void Unk_23eef08::vf8() {}

// 0x7100da6360
void Unk_23eef08::vf10() {}

class Unk_23eefd8 {
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

// 0x7100da6580
u32 Unk_23eefd8::vf7() {
    return 1;
}

// 0x7100da6590
void Unk_23eefd8::vf8() {}

// 0x7100da6af0
void Unk_23eefd8::vf10() {}
