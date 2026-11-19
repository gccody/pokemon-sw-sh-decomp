// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Tail-called by lifted functions. Placeholders, like the forwarders' callees.
void Unk_793ac0(u64, u64, u64);
void Unk_793b20(u64, u64, u64, u32);

// Globals other TUs define, named after their addresses.
extern u64 Unk_27ce848;

class Unk_23a80b0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x7100792950
void Unk_23a80b0::vf2() {}

class Unk_23a80e0 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x71007929d0
void Unk_23a80e0::vf0() {}

class Unk_23a8100 {
public:
    virtual ~Unk_23a8100();
    virtual void vf2();
    virtual void vf3(u64 value, u32 arg2);
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7(u64 value);
    virtual void vf8();
};

// 0x71007944a0, 0x71007944b0
Unk_23a8100::~Unk_23a8100() {}

// 0x7100794310
void Unk_23a8100::vf3(u64 value, u32 arg2) {
    Unk_793b20(Unk_27ce848, value, 0xffffffffffffffff, arg2);
}

// 0x7100794470
void Unk_23a8100::vf7(u64 value) {
    Unk_793ac0(Unk_27ce848, value, 0xffffffffffffffff);
}

class Unk_23a81a8 {
public:
    virtual ~Unk_23a81a8();
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
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual u32 vf25();
};

// 0x7100799410
u32 Unk_23a81a8::vf25() {
    return 1;
}
