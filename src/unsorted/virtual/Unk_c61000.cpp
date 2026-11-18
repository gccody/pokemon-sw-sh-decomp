// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23c1a68.h"

// The type between Unk_23c1a68 and Unk_23dc888 (its class isn't known yet).
struct Unk_27771c8 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27771d8::Unk_GetType());
        return &type;
    }
};

class Unk_23dc888 : public Unk_23c1a68 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27771c8::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    Unk_239a418_Ref<Unk_239a418> field_188;
    Unk_239a418_Ref<Unk_239a418> field_190;
    Unk_239a418_Ref<Unk_239a418> field_198;
};
PKMN_OFFSET_ASSERT(Unk_23dc888, field_188, 0x188);
PKMN_OFFSET_ASSERT(Unk_23dc888, field_190, 0x190);
PKMN_OFFSET_ASSERT(Unk_23dc888, field_198, 0x198);

// 0x7100c620e0
const Unk_239a418_Type* Unk_23dc888::vf_type() {
    return Unk_GetType();
}
