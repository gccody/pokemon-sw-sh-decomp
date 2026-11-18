// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "gflib3/Unk_239a4c0.h"

class Unk_241cf28 : public Unk_239a4c0 {
public:
    ~Unk_241cf28() override;
    u8 _54[0x4];
    Unk_239a418_Ref<Unk_239a418> field_58;
    Unk_239a418_Ref<Unk_239a418> field_60;
};
PKMN_OFFSET_ASSERT(Unk_241cf28, field_58, 0x58);
PKMN_OFFSET_ASSERT(Unk_241cf28, field_60, 0x60);

// 0x710118ee80: its key function
Unk_241cf28::~Unk_241cf28() {}
