// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23f43c8.h"

class Unk_23da1c8 : public Unk_23f43c8 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f43c8::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7() override;
    u32 vf8() override;
    u8 _78[0x18];
    Unk_239a418_Ref<Unk_239a418> field_90;
};
PKMN_OFFSET_ASSERT(Unk_23da1c8, field_90, 0x90);

// 0x7100c28b50; its type 0x7100c28d00
const Unk_239a418_Type* Unk_23da1c8::vf_type() {
    return Unk_GetType();
}
