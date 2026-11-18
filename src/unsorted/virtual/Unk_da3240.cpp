// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23eebc0 {
public:
    virtual ~Unk_23eebc0();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual u32 vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    u8 _8[0x60];
    u32 field_68;
};
PKMN_OFFSET_ASSERT(Unk_23eebc0, field_68, 0x68);

// 0x7100da3240
u32 Unk_23eebc0::vf7() {
    return 1;
}

// 0x7100da3250
void Unk_23eebc0::vf8() {
    field_68 = 0;
}

// 0x7100da34a0
void Unk_23eebc0::vf10() {}
