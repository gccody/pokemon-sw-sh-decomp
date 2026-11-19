// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Tail-called by lifted functions. Placeholders, like the forwarders' callees.
void Unk_f89e70(void*, u32);

struct Unk_2401220_1e0 {
    u8 _0[0x638];
    u64 field_638;
};
PKMN_OFFSET_ASSERT(Unk_2401220_1e0, field_638, 0x638);

class Unk_2401220 {
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
    u8 _8[0x1d8];
    Unk_2401220_1e0* field_1e0;
};
PKMN_OFFSET_ASSERT(Unk_2401220, field_1e0, 0x1e0);

// 0x7100f89c90
void Unk_2401220::vf9() {
    field_1e0->field_638 = 0;
}

// 0x7100f8ae00
void Unk_2401220::vf16() {
    Unk_f89e70(this, 0);
}

// 0x7100f89dd0
void Unk_2401220::vf17() {}

// 0x7100f88e70
u32 Unk_2401220::vf18() {
    return 1;
}
