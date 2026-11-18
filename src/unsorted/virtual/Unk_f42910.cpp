// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23f43c8.h"

// Tail-called by lifted functions. Placeholders, like the forwarders' callees.
void Unk_f43570(u64);

class Unk_23fd850 : public Unk_23f43c8 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f43c8::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7() override;
    u32 vf8() override;
    void vf9() override;
    u64 field_78;
    u64 _80;
    u64 _88;
    Unk_239a418_Ref<Unk_239a418> field_90;
};
PKMN_OFFSET_ASSERT(Unk_23fd850, field_78, 0x78);
PKMN_OFFSET_ASSERT(Unk_23fd850, field_90, 0x90);

// 0x7100f42910
void Unk_23fd850::vf9() {
    Unk_f43570(field_78);
}

// 0x7100f429e0; its type 0x7100f42da0
const Unk_239a418_Type* Unk_23fd850::vf_type() {
    return Unk_GetType();
}
