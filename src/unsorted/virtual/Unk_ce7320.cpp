// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

struct Unk_23e3de8_18 {
    u8 _0[0x170];
    u8 field_170;
};
PKMN_OFFSET_ASSERT(Unk_23e3de8_18, field_170, 0x170);

class Unk_23e3de8 {
public:
    virtual ~Unk_23e3de8();
    virtual bool vf2();
    virtual void vf3();
    u8 _8[0x10];
    Unk_23e3de8_18* field_18;
};
PKMN_OFFSET_ASSERT(Unk_23e3de8, field_18, 0x18);

// 0x7100ce7320
bool Unk_23e3de8::vf2() {
    if (field_18 == nullptr) {
        return false;
    }
    return field_18->field_170 != 0;
}
