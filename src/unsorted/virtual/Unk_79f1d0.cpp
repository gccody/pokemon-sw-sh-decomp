// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Tail-called by lifted functions. Placeholders, like the forwarders' callees.
void Unk_1500c40(u64);

class Unk_23a8bd8 {
public:
    virtual ~Unk_23a8bd8();
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
    u8 _8[0x4b8];
    u64 field_4c0;
};
PKMN_OFFSET_ASSERT(Unk_23a8bd8, field_4c0, 0x4c0);

// 0x710079f1d0
void Unk_23a8bd8::vf10() {
    if (field_4c0 != 0) {
        Unk_1500c40(field_4c0);
    }
}

class Unk_23a8d48 {
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
    virtual u32 vf10();
    u8 _8[0xe0];
    u32 field_e8;
};
PKMN_OFFSET_ASSERT(Unk_23a8d48, field_e8, 0xe8);

// 0x71007a0a70
u32 Unk_23a8d48::vf10() {
    return field_e8;
}
