// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23f43c8.h"

// Tail-called by lifted functions. Placeholders, like the forwarders' callees.
void Unk_f4ea10(u64);

class Unk_23fe440 : public Unk_23f43c8 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f43c8::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7() override;
    u32 vf8() override;
    void vf9() override;
    u64 _78;
    u64 field_80;
    u64 _88;
    u64 _90;
    Unk_239a418_Ref<Unk_239a418> field_98;
};
PKMN_OFFSET_ASSERT(Unk_23fe440, field_80, 0x80);
PKMN_OFFSET_ASSERT(Unk_23fe440, field_98, 0x98);

// 0x7100f511b0
void Unk_23fe440::vf9() {
    Unk_f4ea10(field_80);
}

// 0x7100f513c0; its type 0x7100f51570
const Unk_239a418_Type* Unk_23fe440::vf_type() {
    return Unk_GetType();
}
