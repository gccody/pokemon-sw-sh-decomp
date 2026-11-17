// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

struct Unk_23bf7e0_80 {
    u8 _0[0x5d4];
    u8 field_5d4;
};
PKMN_OFFSET_ASSERT(Unk_23bf7e0_80, field_5d4, 0x5d4);

class Unk_23bf7e0 {
public:
    virtual ~Unk_23bf7e0();
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
    virtual u8 vf13();
    virtual void vf14();
    virtual void vf15();
    u8 _8[0x78];
    Unk_23bf7e0_80* field_80;
};
PKMN_OFFSET_ASSERT(Unk_23bf7e0, field_80, 0x80);

// 0x7100930060
u8 Unk_23bf7e0::vf13() {
    return field_80->field_5d4;
}
