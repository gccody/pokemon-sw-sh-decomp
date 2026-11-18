// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23d4470.h"
#include "unsorted/Unk_23f43c8.h"

class Unk_2430958 : public Unk_23f43c8 {
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
    Unk_239a418_Ref<Unk_239a418> field_80;
    Unk_239a418_Ref<Unk_239a418> field_88;
    Unk_239a418_Ref<Unk_239a418> field_90;
    Unk_239a418_Ref<Unk_239a418> field_98;
    Unk_239a418_Ref<Unk_239a418> field_a0;
    Unk_239a418_Ref<Unk_239a418> field_a8;
    u8 _b0[0x70];
    Unk_23d4470_Callable field_120;
    Unk_23d4470_Callable field_1a0;
    Unk_23d4470_Callable field_220;
};
PKMN_OFFSET_ASSERT(Unk_2430958, field_80, 0x80);
PKMN_OFFSET_ASSERT(Unk_2430958, field_88, 0x88);
PKMN_OFFSET_ASSERT(Unk_2430958, field_90, 0x90);
PKMN_OFFSET_ASSERT(Unk_2430958, field_98, 0x98);
PKMN_OFFSET_ASSERT(Unk_2430958, field_a0, 0xa0);
PKMN_OFFSET_ASSERT(Unk_2430958, field_a8, 0xa8);
PKMN_OFFSET_ASSERT(Unk_2430958, field_120, 0x120);
PKMN_OFFSET_ASSERT(Unk_2430958, field_1a0, 0x1a0);
PKMN_OFFSET_ASSERT(Unk_2430958, field_220, 0x220);

// 0x710132e090
void Unk_2430958::vf9() {}

// 0x710132e1d0; its type 0x710132e240
const Unk_239a418_Type* Unk_2430958::vf_type() {
    return Unk_GetType();
}
