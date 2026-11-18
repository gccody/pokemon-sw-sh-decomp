// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23f4e40.h"

class Unk_23ede30 : public Unk_23f4e40 {
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
    u64 _88;
    Unk_239a418_Ref<Unk_239a418> field_90;
    u64 _98;
    u64 _a0;
    u64 _a8;
    u64 _b0;
    u64 _b8;
    u64 _c0;
    Unk_239a418_Ref<Unk_239a418> field_c8;
};
PKMN_OFFSET_ASSERT(Unk_23ede30, field_90, 0x90);
PKMN_OFFSET_ASSERT(Unk_23ede30, field_c8, 0xc8);

// 0x7100d83f40
u32 Unk_23ede30::vf7() {
    return 1;
}

// 0x7100d84290; its type 0x7100d842c0
const Unk_239a418_Type* Unk_23ede30::vf_type() {
    return Unk_GetType();
}
