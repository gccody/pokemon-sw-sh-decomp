// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "gflib3/Unk_239a4c0.h"

class Unk_241c8d0 : public Unk_239a4c0 {
public:
    ~Unk_241c8d0() override;
    u8 _54[0x1c];
    Unk_239a418_Ref<Unk_239a418> field_70;
    u8 _78[0x50];
    u64 _c8;
    u64 _d0;
    u64 _d8;
    u64 _e0;
    u64 _e8;
    u64 _f0;
    u64 _f8;
    u64 _100;
    u64 _108;
    Unk_239a418_Ref<Unk_239a418> field_110;
};
PKMN_OFFSET_ASSERT(Unk_241c8d0, field_70, 0x70);
PKMN_OFFSET_ASSERT(Unk_241c8d0, field_110, 0x110);

// 0x7101179fd0: its key function
Unk_241c8d0::~Unk_241c8d0() {}
