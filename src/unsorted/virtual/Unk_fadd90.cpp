// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23d4470.h"
#include "unsorted/Unk_23f43c8.h"

class Unk_2402800 : public Unk_23f43c8 {
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
    Unk_239a418_Ref<Unk_239a418> field_b0;
    u8 _b8[0x8];
    Unk_239a418_Ref<Unk_239a418> field_c0;
    Unk_239a418_Ref<Unk_239a418> field_c8;
    Unk_239a418_Ref<Unk_239a418> field_d0;
    Unk_239a418_Ref<Unk_239a418> field_d8;
    u8 _e0[0x70];
    Unk_23d4470_Callable field_150;
    Unk_23d4470_Callable field_1d0;
    Unk_23d4470_Callable field_250;
    Unk_23d4470_Callable field_2d0;
};
PKMN_OFFSET_ASSERT(Unk_2402800, field_80, 0x80);
PKMN_OFFSET_ASSERT(Unk_2402800, field_88, 0x88);
PKMN_OFFSET_ASSERT(Unk_2402800, field_90, 0x90);
PKMN_OFFSET_ASSERT(Unk_2402800, field_98, 0x98);
PKMN_OFFSET_ASSERT(Unk_2402800, field_a0, 0xa0);
PKMN_OFFSET_ASSERT(Unk_2402800, field_a8, 0xa8);
PKMN_OFFSET_ASSERT(Unk_2402800, field_b0, 0xb0);
PKMN_OFFSET_ASSERT(Unk_2402800, field_c0, 0xc0);
PKMN_OFFSET_ASSERT(Unk_2402800, field_c8, 0xc8);
PKMN_OFFSET_ASSERT(Unk_2402800, field_d0, 0xd0);
PKMN_OFFSET_ASSERT(Unk_2402800, field_d8, 0xd8);
PKMN_OFFSET_ASSERT(Unk_2402800, field_150, 0x150);
PKMN_OFFSET_ASSERT(Unk_2402800, field_1d0, 0x1d0);
PKMN_OFFSET_ASSERT(Unk_2402800, field_250, 0x250);
PKMN_OFFSET_ASSERT(Unk_2402800, field_2d0, 0x2d0);

// 0x7100fadd90
void Unk_2402800::vf9() {}

// 0x7100fadf70; its type 0x7100fadfe0
const Unk_239a418_Type* Unk_2402800::vf_type() {
    return Unk_GetType();
}
