// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_24034f8.h"

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_fcd090(void* self);

struct Unk_24039e0_710 {
    u8 _0[0x58];
    u8 field_58;
};
PKMN_OFFSET_ASSERT(Unk_24039e0_710, field_58, 0x58);

struct Unk_24039e0_718 {
    u8 _0[0x58];
    u8 field_58;
};
PKMN_OFFSET_ASSERT(Unk_24039e0_718, field_58, 0x58);

class Unk_24039e0 : public Unk_24034f8 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_24034f8::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf8() override;
    void vf14() override;
    u32 vf18() override;
    void vf19() override;
    void vf21() override;
    Unk_239a418_Ref<Unk_239a418> field_708;
    Unk_24039e0_710* field_710;
    Unk_24039e0_718* field_718;
};
PKMN_OFFSET_ASSERT(Unk_24039e0, field_708, 0x708);
PKMN_OFFSET_ASSERT(Unk_24039e0, field_710, 0x710);
PKMN_OFFSET_ASSERT(Unk_24039e0, field_718, 0x718);

// 0x7100fd04c0
void Unk_24039e0::vf19() {
    Unk_fcd090(this);
}

// 0x7100fd04d0
void Unk_24039e0::vf21() {
    field_710->field_58 = field_710->field_58 & 0xfe;
    field_718->field_58 = field_718->field_58 & 0xfe;
}

// 0x7100fd05c0
const Unk_239a418_Type* Unk_24039e0::vf_type() {
    return Unk_GetType();
}
