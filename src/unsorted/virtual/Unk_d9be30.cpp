// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23f4e40.h"

class Unk_23ee950 : public Unk_23f4e40 {
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
    Unk_239a418_Ref<Unk_239a418> field_98;
    Unk_239a418_Ref<Unk_239a418> field_a0;
    u64 _a8;
    u64 _b0;
    u64 _b8;
    u64 _c0;
    Unk_239a418_Ref<Unk_239a418> field_c8;
};
PKMN_OFFSET_ASSERT(Unk_23ee950, field_90, 0x90);
PKMN_OFFSET_ASSERT(Unk_23ee950, field_98, 0x98);
PKMN_OFFSET_ASSERT(Unk_23ee950, field_a0, 0xa0);
PKMN_OFFSET_ASSERT(Unk_23ee950, field_c8, 0xc8);

// 0x7100d9be30
u32 Unk_23ee950::vf7() {
    return 1;
}

// 0x7100d9c590; its type 0x7100d9c840
const Unk_239a418_Type* Unk_23ee950::vf_type() {
    return Unk_GetType();
}
