// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23f43c8.h"

class Unk_23dc118 : public Unk_23f43c8 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f43c8::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7() override;
    u32 vf8() override;
    void vf9() override;
    u64 _78;
    Unk_239a418_Ref<Unk_239a418> field_80;
    Unk_239a418_Ref<Unk_239a418> field_88;
};
PKMN_OFFSET_ASSERT(Unk_23dc118, field_80, 0x80);
PKMN_OFFSET_ASSERT(Unk_23dc118, field_88, 0x88);

// 0x7100c4e710
u32 Unk_23dc118::vf8() {
    return 0;
}

// 0x7100c4e720
void Unk_23dc118::vf9() {}

// 0x7100c4e810; its type 0x7100c4ea00
const Unk_239a418_Type* Unk_23dc118::vf_type() {
    return Unk_GetType();
}
