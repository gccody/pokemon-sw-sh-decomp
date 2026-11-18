// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23f43c8.h"

// Tail-called by lifted functions. Placeholders, like the forwarders' callees.
void Unk_1256f10(u64);

class Unk_2427890 : public Unk_23f43c8 {
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
    u64 field_80;
};
PKMN_OFFSET_ASSERT(Unk_2427890, field_80, 0x80);

// 0x71012599d0
void Unk_2427890::vf9() {
    Unk_1256f10(field_80);
}

// 0x71012599f0; its type 0x7101259a60
const Unk_239a418_Type* Unk_2427890::vf_type() {
    return Unk_GetType();
}
