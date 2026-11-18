// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23f4e40.h"

struct Unk_23ed1d0_90 {
    u8 _0[0x8];
    u64 field_8;
    u64 field_10;
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_23ed1d0_90, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_23ed1d0_90, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_23ed1d0_90, field_18, 0x18);

class Unk_23ed1d0 : public Unk_23f4e40 {
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
    Unk_23ed1d0_90* field_90;
};
PKMN_OFFSET_ASSERT(Unk_23ed1d0, field_88, 0x88);
PKMN_OFFSET_ASSERT(Unk_23ed1d0, field_90, 0x90);

// 0x7100d6c7f0
u32 Unk_23ed1d0::vf7() {
    return 1;
}

// 0x7100d6c800
void Unk_23ed1d0::vf8() {
    if (field_90 != nullptr) {
        field_90->field_8 = 0;
        field_90->field_10 = 0;
        field_90->field_18 = 0;
    }
}

// 0x7100d6c8f0
void Unk_23ed1d0::vf10() {}

// 0x7100d6c900; its type 0x7100d6c930
const Unk_239a418_Type* Unk_23ed1d0::vf_type() {
    return Unk_GetType();
}
