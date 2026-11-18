// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23f43c8.h"

class Unk_23bf0d0 : public Unk_23f43c8 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f43c8::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7() override;
    u32 vf8() override;
    void vf9() override;
    u8 _78[0x8];
    Unk_239a418_Ref<Unk_239a418> field_80;
};
PKMN_OFFSET_ASSERT(Unk_23bf0d0, field_80, 0x80);

// 0x71009269f0
void Unk_23bf0d0::vf9() {}

// 0x7100926ac0; its type 0x7100926c70
const Unk_239a418_Type* Unk_23bf0d0::vf_type() {
    return Unk_GetType();
}
