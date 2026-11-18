// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23f4e40.h"

class Unk_23ee258 : public Unk_23f4e40 {
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
PKMN_OFFSET_ASSERT(Unk_23ee258, field_88, 0x88);

// 0x7100d943c0
u32 Unk_23ee258::vf7() {
    return 1;
}

// 0x7100d943d0
void Unk_23ee258::vf8() {}

// 0x7100d94830
void Unk_23ee258::vf10() {}

// 0x7100d94900; its type 0x7100d94ab0
const Unk_239a418_Type* Unk_23ee258::vf_type() {
    return Unk_GetType();
}
