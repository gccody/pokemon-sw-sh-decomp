// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23cec70 {
public:
    virtual ~Unk_23cec70();
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
    virtual u32 vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual u32 vf25();
};

// 0x7100b2ea50
u32 Unk_23cec70::vf20() {
    return 1;
}

// 0x7100b2f090
void Unk_23cec70::vf22() {}

// 0x7100b2f400
u32 Unk_23cec70::vf25() {
    return 1;
}

class Unk_23cedd0 {
public:
    virtual ~Unk_23cedd0();
    virtual void vf2();
    virtual u64 vf3();
    virtual void vf4();
    virtual void vf5();
    u8 _8[0x50];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_23cedd0, field_58, 0x58);

// 0x7100b30080
u64 Unk_23cedd0::vf3() {
    return field_58;
}

class Unk_23cee10 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x7100b301f0
u32 Unk_23cee10::vf0() {
    return 1;
}
