// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23f43c8.h"

class Unk_2439318 : public Unk_23f43c8 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f43c8::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7() override;
    u32 vf8() override;
    void vf9() override;
    u8 _78[0x20];
    Unk_239a418_Ref<Unk_239a418> field_98;
    Unk_239a418_Ref<Unk_239a418> field_a0;
    Unk_239a418_Ref<Unk_239a418> field_a8;
    Unk_239a418_Ref<Unk_239a418> field_b0;
    u8 _b8[0x50];
    Unk_239a418_Ref<Unk_239a418> field_108;
    Unk_239a418_Ref<Unk_239a418> field_110;
    Unk_239a418_Ref<Unk_239a418> field_118;
    Unk_239a418_Ref<Unk_239a418> field_120;
    Unk_239a418_Ref<Unk_239a418> field_128;
    Unk_239a418_Ref<Unk_239a418> field_130;
    Unk_239a418_Ref<Unk_239a418> field_138;
    u8 _140[0x8];
    Unk_239a418_Ref<Unk_239a418> field_148;
    u8 _150[0x8];
    Unk_239a418_Ref<Unk_239a418> field_158;
};
PKMN_OFFSET_ASSERT(Unk_2439318, field_98, 0x98);
PKMN_OFFSET_ASSERT(Unk_2439318, field_a0, 0xa0);
PKMN_OFFSET_ASSERT(Unk_2439318, field_a8, 0xa8);
PKMN_OFFSET_ASSERT(Unk_2439318, field_b0, 0xb0);
PKMN_OFFSET_ASSERT(Unk_2439318, field_108, 0x108);
PKMN_OFFSET_ASSERT(Unk_2439318, field_110, 0x110);
PKMN_OFFSET_ASSERT(Unk_2439318, field_118, 0x118);
PKMN_OFFSET_ASSERT(Unk_2439318, field_120, 0x120);
PKMN_OFFSET_ASSERT(Unk_2439318, field_128, 0x128);
PKMN_OFFSET_ASSERT(Unk_2439318, field_130, 0x130);
PKMN_OFFSET_ASSERT(Unk_2439318, field_138, 0x138);
PKMN_OFFSET_ASSERT(Unk_2439318, field_148, 0x148);
PKMN_OFFSET_ASSERT(Unk_2439318, field_158, 0x158);

// 0x7101420c30
void Unk_2439318::vf9() {}

// 0x7101420dd0; its type 0x7101420e40
const Unk_239a418_Type* Unk_2439318::vf_type() {
    return Unk_GetType();
}
