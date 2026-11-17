// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "gflib3/Unk_239a418.h"

class Unk_23c0390 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override { return Unk_GetType(); }
    virtual u32 vf7();
    u8 _60[0x8];
    Unk_239a418_Ref<Unk_239a418> field_68;
};
PKMN_OFFSET_ASSERT(Unk_23c0390, field_68, 0x68);

// 0x710093ccc0
u32 Unk_23c0390::vf7() {
    return 0;
}
