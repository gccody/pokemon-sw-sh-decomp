// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23f43c8.h"

// Tail-called by lifted functions. Placeholders, like the forwarders' callees.
void Unk_f497b0(u64);

class Unk_23fe1a0 : public Unk_23f43c8 {
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
    u64 field_88;
};
PKMN_OFFSET_ASSERT(Unk_23fe1a0, field_88, 0x88);

// 0x7100f4dc90
void Unk_23fe1a0::vf9() {
    Unk_f497b0(field_88);
}

// 0x7100f4dcb0; its type 0x7100f4dd20
const Unk_239a418_Type* Unk_23fe1a0::vf_type() {
    return Unk_GetType();
}
