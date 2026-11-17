// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23bb318 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual u8 vf6();
    u8 _8[0xbc];
    u8 field_c4;
};
PKMN_OFFSET_ASSERT(Unk_23bb318, field_c4, 0xc4);

// 0x71008c8c70
u8 Unk_23bb318::vf6() {
    return field_c4;
}
