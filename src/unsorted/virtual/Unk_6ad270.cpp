// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23a2c10 {
public:
    virtual ~Unk_23a2c10();
    virtual void vf2();
    virtual u32 vf3();
    virtual void vf4();
    u32 field_8;
    u16 field_c;
};
PKMN_OFFSET_ASSERT(Unk_23a2c10, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_23a2c10, field_c, 0xc);

// 0x71006ad2b0, 0x71006ad260
Unk_23a2c10::~Unk_23a2c10() {}

// 0x71006ad270
void Unk_23a2c10::vf2() {
    field_8 = 0;
    field_c = 0;
}

// 0x71006ad280
u32 Unk_23a2c10::vf3() {
    return 1;
}
