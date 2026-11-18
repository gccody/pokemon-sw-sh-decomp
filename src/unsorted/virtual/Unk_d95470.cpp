// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23f4e40.h"

class Unk_23ee3f8 : public Unk_23f4e40 {
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
PKMN_OFFSET_ASSERT(Unk_23ee3f8, field_88, 0x88);

// 0x7100d95470
u32 Unk_23ee3f8::vf7() {
    return 1;
}

// 0x7100d95480
void Unk_23ee3f8::vf8() {}

// 0x7100d96140
void Unk_23ee3f8::vf10() {}

// 0x7100d96210; its type 0x7100d963c0
const Unk_239a418_Type* Unk_23ee3f8::vf_type() {
    return Unk_GetType();
}
