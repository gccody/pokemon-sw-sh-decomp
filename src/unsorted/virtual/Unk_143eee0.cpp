// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23f4e40.h"

class Unk_243bb70 : public Unk_23f4e40 {
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
PKMN_OFFSET_ASSERT(Unk_243bb70, field_88, 0x88);

// 0x710143f120
u32 Unk_243bb70::vf7() {
    return 1;
}

// 0x710143f130
void Unk_243bb70::vf8() {}

// 0x710143f140
void Unk_243bb70::vf10() {}

// 0x710143f530; its type 0x710143f560
const Unk_239a418_Type* Unk_243bb70::vf_type() {
    return Unk_GetType();
}
