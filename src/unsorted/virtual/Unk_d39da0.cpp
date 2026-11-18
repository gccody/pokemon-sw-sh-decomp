// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "gflib3/Unk_239a4c0.h"

class Unk_23e99f0 : public Unk_239a4c0 {
public:
    ~Unk_23e99f0() override;
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual u32 vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual bool vf14();
    u8 _54[0x4];
    Unk_239a418_Ref<Unk_239a418> field_58;
    u8 _60[0x30];
    u64 _90;
    u64 _98;
    u64 _a0;
    u64 _a8;
    u64 _b0;
    u64 _b8;
    u64 _c0;
    u64 _c8;
    u64 _d0;
    u32 field_d8;
};
PKMN_OFFSET_ASSERT(Unk_23e99f0, field_58, 0x58);
PKMN_OFFSET_ASSERT(Unk_23e99f0, field_d8, 0xd8);

// 0x7100d3a2b0: its key function
Unk_23e99f0::~Unk_23e99f0() {}

// 0x7100d39da0
u32 Unk_23e99f0::vf9() {
    return 0;
}

// 0x7100d3a350
bool Unk_23e99f0::vf14() {
    return field_d8 != 0xffffffff;
}
