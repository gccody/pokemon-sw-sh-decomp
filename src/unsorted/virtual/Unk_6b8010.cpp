// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23a34b8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual u16 vf7();
    virtual void vf8();
    u8 _8[0x158];
    u16 field_160;
};
PKMN_OFFSET_ASSERT(Unk_23a34b8, field_160, 0x160);

// 0x71006b8010
u16 Unk_23a34b8::vf7() {
    return field_160;
}
