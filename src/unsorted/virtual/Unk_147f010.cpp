// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23f43c8.h"

class Unk_243f1c8 : public Unk_23f43c8 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f43c8::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7() override;
    u32 vf8() override;
    void vf9() override;
    u8 _78[0x10];
    Unk_239a418_Ref<Unk_239a418> field_88;
    Unk_239a418_Ref<Unk_239a418> field_90;
    Unk_239a418_Ref<Unk_239a418> field_98;
};
PKMN_OFFSET_ASSERT(Unk_243f1c8, field_88, 0x88);
PKMN_OFFSET_ASSERT(Unk_243f1c8, field_90, 0x90);
PKMN_OFFSET_ASSERT(Unk_243f1c8, field_98, 0x98);

// 0x710147f010
void Unk_243f1c8::vf9() {}

// 0x710147f140; its type 0x710147f3b0
const Unk_239a418_Type* Unk_243f1c8::vf_type() {
    return Unk_GetType();
}
