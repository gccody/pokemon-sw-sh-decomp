// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_241e850 {
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
    u8 _8[0xa0];
    u64 field_a8;
    u64 field_b0;
    u32 field_b8;
};
PKMN_OFFSET_ASSERT(Unk_241e850, field_a8, 0xa8);
PKMN_OFFSET_ASSERT(Unk_241e850, field_b0, 0xb0);
PKMN_OFFSET_ASSERT(Unk_241e850, field_b8, 0xb8);

// 0x71011a1c90
void Unk_241e850::vf9() {
    field_b8 = 0;
    field_a8 = 0;
    field_b0 = 0;
}
