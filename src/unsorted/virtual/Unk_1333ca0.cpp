// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23d4470.h"
#include "unsorted/Unk_23f43c8.h"

class Unk_2430ba8 : public Unk_23f43c8 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f43c8::Unk_GetType());
        return &type;
    }

    ~Unk_2430ba8() override;
    const Unk_239a418_Type* vf_type() override;
    void vf7() override;
    u32 vf8() override;
    void vf9() override;
    u8 _78[0x10];
    Unk_239a418_Ref<Unk_239a418> field_88;
    Unk_239a418_Ref<Unk_239a418> field_90;
    Unk_239a418_Ref<Unk_239a418> field_98;
    Unk_239a418_Ref<Unk_239a418> field_a0;
    u8 _a8[0x8];
    Unk_239a418_Ref<Unk_239a418> field_b0;
    Unk_239a418_Ref<Unk_239a418> field_b8;
    Unk_239a418_Ref<Unk_239a418> field_c0;
    Unk_239a418_Ref<Unk_239a418> field_c8;
    u8 _d0[0x70];
    Unk_23d4470_Callable field_140;
    Unk_23d4470_Callable field_1c0;
    Unk_23d4470_Callable field_240;
};
PKMN_OFFSET_ASSERT(Unk_2430ba8, field_88, 0x88);
PKMN_OFFSET_ASSERT(Unk_2430ba8, field_90, 0x90);
PKMN_OFFSET_ASSERT(Unk_2430ba8, field_98, 0x98);
PKMN_OFFSET_ASSERT(Unk_2430ba8, field_a0, 0xa0);
PKMN_OFFSET_ASSERT(Unk_2430ba8, field_b0, 0xb0);
PKMN_OFFSET_ASSERT(Unk_2430ba8, field_b8, 0xb8);
PKMN_OFFSET_ASSERT(Unk_2430ba8, field_c0, 0xc0);
PKMN_OFFSET_ASSERT(Unk_2430ba8, field_c8, 0xc8);
PKMN_OFFSET_ASSERT(Unk_2430ba8, field_140, 0x140);
PKMN_OFFSET_ASSERT(Unk_2430ba8, field_1c0, 0x1c0);
PKMN_OFFSET_ASSERT(Unk_2430ba8, field_240, 0x240);

// 0x7101333cb0: its key function
Unk_2430ba8::~Unk_2430ba8() {}

// 0x7101333ca0
void Unk_2430ba8::vf9() {}

// 0x7101333e10; its type 0x7101333e80
const Unk_239a418_Type* Unk_2430ba8::vf_type() {
    return Unk_GetType();
}
