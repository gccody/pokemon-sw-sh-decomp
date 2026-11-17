// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23aa6d0 {
public:
    virtual ~Unk_23aa6d0();
};

// 0x71007c3a70, 0x71007cd950
Unk_23aa6d0::~Unk_23aa6d0() {}

class Unk_23aa570 {
public:
    virtual u32 vf0();
    u8 _8[0x16c];
    u8 field_174;
};
PKMN_OFFSET_ASSERT(Unk_23aa570, field_174, 0x174);

// 0x71007c84a0
u32 Unk_23aa570::vf0() {
    field_174 = 0;
    return 1;
}
