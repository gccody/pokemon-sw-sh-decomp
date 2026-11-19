// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23f5d00.h"

class Unk_23d0bd8 : public Unk_23f5d00 {
public:
    ~Unk_23d0bd8() override;
    u8* vf5() override;
    Unk_23f5d00_Member<void> field_180;
};
PKMN_OFFSET_ASSERT(Unk_23d0bd8, field_180, 0x180);

// 0x7100b747a0: its key function
Unk_23d0bd8::~Unk_23d0bd8() {}
