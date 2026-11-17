// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Tail-called by lifted functions. Placeholders, like the forwarders' callees.
void Unk_91b5a0(void*, u64);
void Unk_91b5c0(void*, u64, u64, u32);

class Unk_23be868 {
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
    virtual void vf18();
    u8 _8[0x5f0];
    u64 field_5f8;
};
PKMN_OFFSET_ASSERT(Unk_23be868, field_5f8, 0x5f8);

// 0x710091f8f0
void Unk_23be868::vf17() {
    Unk_91b5c0(this, field_5f8, 0, 1);
}

// 0x710091f900
void Unk_23be868::vf18() {
    Unk_91b5a0(this, field_5f8);
}
