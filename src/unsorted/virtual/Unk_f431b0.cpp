// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23f4660.h"

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_f431c0(void* self);

class Unk_23fd920 : public Unk_23f4660 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4660::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf8() override;
    void vf10() override;
    void vf15() override;
    u32 vf16() override;
    u64 _5d0;
    Unk_239a418_Ref<Unk_239a418> field_5d8;
    Unk_239a418_Ref<Unk_239a418> field_5e0;
    Unk_239a418_Ref<Unk_239a418> field_5e8;
};
PKMN_OFFSET_ASSERT(Unk_23fd920, field_5d8, 0x5d8);
PKMN_OFFSET_ASSERT(Unk_23fd920, field_5e0, 0x5e0);
PKMN_OFFSET_ASSERT(Unk_23fd920, field_5e8, 0x5e8);

// 0x7100f431b0
void Unk_23fd920::vf8() {
    Unk_f431c0(this);
}

// 0x7100f43410
void Unk_23fd920::vf10() {}

// 0x7100f43cc0; its type 0x7100f43f30
const Unk_239a418_Type* Unk_23fd920::vf_type() {
    return Unk_GetType();
}
