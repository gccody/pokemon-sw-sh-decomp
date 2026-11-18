// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23f4e40.h"

class Unk_23f87b0 : public Unk_23f4e40 {
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
};
PKMN_OFFSET_ASSERT(Unk_23f87b0, field_88, 0x88);

// 0x7100eed050
u32 Unk_23f87b0::vf7() {
    return 1;
}

// 0x7100eed060
void Unk_23f87b0::vf8() {}

// 0x7100eed070
void Unk_23f87b0::vf10() {}

// 0x7100eed310; its type 0x7100eed340
const Unk_239a418_Type* Unk_23f87b0::vf_type() {
    return Unk_GetType();
}
