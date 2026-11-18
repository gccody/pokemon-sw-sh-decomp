// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23d4470.h"
#include "unsorted/Unk_23f4660.h"

class Unk_24386c0 : public Unk_23f4660 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4660::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf8() override;
    void vf10() override;
    void vf15() override;
    u8 _5d0[0x388];
    Unk_239a418_Ref<Unk_239a418> field_958;
    Unk_239a418_Ref<Unk_239a418> field_960;
    u8 _968[0x58];
    Unk_23d4470_Callable field_9c0;
    Unk_23d4470_Callable field_a40;
    Unk_23d4470_Callable field_ac0;
    Unk_23d4470_Callable field_b40;
    Unk_23d4470_Callable field_bc0;
};
PKMN_OFFSET_ASSERT(Unk_24386c0, field_958, 0x958);
PKMN_OFFSET_ASSERT(Unk_24386c0, field_960, 0x960);
PKMN_OFFSET_ASSERT(Unk_24386c0, field_9c0, 0x9c0);
PKMN_OFFSET_ASSERT(Unk_24386c0, field_a40, 0xa40);
PKMN_OFFSET_ASSERT(Unk_24386c0, field_ac0, 0xac0);
PKMN_OFFSET_ASSERT(Unk_24386c0, field_b40, 0xb40);
PKMN_OFFSET_ASSERT(Unk_24386c0, field_bc0, 0xbc0);

// 0x7101411e90
void Unk_24386c0::vf10() {}

// 0x71014125e0; its type 0x7101412a50
const Unk_239a418_Type* Unk_24386c0::vf_type() {
    return Unk_GetType();
}
