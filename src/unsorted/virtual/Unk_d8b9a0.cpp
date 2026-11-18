// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "gflib3/Unk_239a4c0.h"

class Unk_23ee108 : public Unk_239a4c0 {
public:
    ~Unk_23ee108() override;
    u8 _54[0x14];
    Unk_239a418_Ref<Unk_239a418> field_68;
    u8 _70[0x78];
    u64 _e8;
    u64 _f0;
    u64 _f8;
    u64 _100;
    u64 _108;
    u64 _110;
    u64 _118;
    u64 _120;
    u64 _128;
    Unk_239a418_Ref<Unk_239a418> field_130;
};
PKMN_OFFSET_ASSERT(Unk_23ee108, field_68, 0x68);
PKMN_OFFSET_ASSERT(Unk_23ee108, field_130, 0x130);

// 0x7100d8b9a0: its key function
Unk_23ee108::~Unk_23ee108() {}
