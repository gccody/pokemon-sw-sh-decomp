// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "gflib3/Unk_239bb58.h"

class Unk_23a1af8 : public Unk_239bb58 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239bb58::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7() override;
    u64 _a0;
    u64 _a8;
    Unk_239a418_Ref<Unk_239a418> field_b0;
    Unk_239a418_Ref<Unk_239a418> field_b8;
};
PKMN_OFFSET_ASSERT(Unk_23a1af8, field_b0, 0xb0);
PKMN_OFFSET_ASSERT(Unk_23a1af8, field_b8, 0xb8);

// 0x710068fdc0; its type 0x7100690130
const Unk_239a418_Type* Unk_23a1af8::vf_type() {
    return Unk_GetType();
}
