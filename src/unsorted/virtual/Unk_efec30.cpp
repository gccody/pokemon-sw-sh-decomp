// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23f4e40.h"

class Unk_23f9a80 : public Unk_23f4e40 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4e40::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    u32 vf7() override;
    void vf8() override;
    u32 vf9() override;
    void vf10() override;
    Unk_239a418_Ref<Unk_239a418> field_88;
    u8 _90[0x8];
    u64 _98;
    u64 _a0;
    u64 _a8;
    u64 _b0;
    Unk_239a418_Ref<Unk_239a418> field_b8;
    Unk_239a418_Ref<Unk_239a418> field_c0;
    u64 _c8;
    u64 _d0;
    u64 _d8;
    Unk_239a418_Ref<Unk_239a418> field_e0;
};
PKMN_OFFSET_ASSERT(Unk_23f9a80, field_88, 0x88);
PKMN_OFFSET_ASSERT(Unk_23f9a80, field_b8, 0xb8);
PKMN_OFFSET_ASSERT(Unk_23f9a80, field_c0, 0xc0);
PKMN_OFFSET_ASSERT(Unk_23f9a80, field_e0, 0xe0);

// 0x7100efeff0
u32 Unk_23f9a80::vf7() {
    return 1;
}

// 0x7100eff0e0
void Unk_23f9a80::vf10() {}

// 0x7100eff3c0; its type 0x7100eff3f0
const Unk_239a418_Type* Unk_23f9a80::vf_type() {
    return Unk_GetType();
}
