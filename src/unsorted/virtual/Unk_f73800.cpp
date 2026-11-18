// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23f43c8.h"

class Unk_23ffd30 : public Unk_23f43c8 {
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
    u64 _80;
    Unk_239a418_Ref<Unk_239a418> field_88;
    Unk_239a418_Ref<Unk_239a418> field_90;
};
PKMN_OFFSET_ASSERT(Unk_23ffd30, field_88, 0x88);
PKMN_OFFSET_ASSERT(Unk_23ffd30, field_90, 0x90);

// 0x7100f73800
void Unk_23ffd30::vf9() {}

// 0x7100f738f0; its type 0x7100f73ae0
const Unk_239a418_Type* Unk_23ffd30::vf_type() {
    return Unk_GetType();
}
