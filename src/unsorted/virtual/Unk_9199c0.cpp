// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "gflib3/Unk_239a4c0.h"

class Unk_23be270 : public Unk_239a4c0 {
public:
    ~Unk_23be270() override;
    u8 _54[0x4];
    Unk_239a418_Ref<Unk_239a418> field_58;
    u64 _60;
    u64 _68;
    u64 _70;
    u64 _78;
    u64 _80;
    Unk_239a418_Ref<Unk_239a418> field_88;
};
PKMN_OFFSET_ASSERT(Unk_23be270, field_58, 0x58);
PKMN_OFFSET_ASSERT(Unk_23be270, field_88, 0x88);

// 0x71009199c0: its key function
Unk_23be270::~Unk_23be270() {}
