// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23f4e40.h"

class Unk_23db008 : public Unk_23f4e40 {
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
    Unk_239a418_Ref<Unk_239a418> field_90;
    Unk_239a418_Ref<Unk_239a418> field_98;
    u8 _a0[0x18];
    Unk_239a418_Ref<Unk_239a418> field_b8;
};
PKMN_OFFSET_ASSERT(Unk_23db008, field_88, 0x88);
PKMN_OFFSET_ASSERT(Unk_23db008, field_90, 0x90);
PKMN_OFFSET_ASSERT(Unk_23db008, field_98, 0x98);
PKMN_OFFSET_ASSERT(Unk_23db008, field_b8, 0xb8);

// 0x7100c3dcb0
u32 Unk_23db008::vf7() {
    return 1;
}

// 0x7100c3e6b0; its type 0x7100c3e6e0
const Unk_239a418_Type* Unk_23db008::vf_type() {
    return Unk_GetType();
}
