// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23c9470.h"

class Unk_23cc148 : public Unk_23c9470 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23c9470::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf8() override;
    void vf15() override;
    void vf17() override;
    u32 vf18() override;
    void vf19() override;
    Unk_239a418_Ref<Unk_239a418> field_848;
};
PKMN_OFFSET_ASSERT(Unk_23cc148, field_848, 0x848);

// 0x7100aecf80
const Unk_239a418_Type* Unk_23cc148::vf_type() {
    return Unk_GetType();
}
