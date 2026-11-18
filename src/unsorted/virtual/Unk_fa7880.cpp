// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23d4470.h"
#include "unsorted/Unk_23f43c8.h"

class Unk_24025b0 : public Unk_23f43c8 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f43c8::Unk_GetType());
        return &type;
    }

    ~Unk_24025b0() override;
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
    Unk_239a418_Ref<Unk_239a418> field_b8;
    u8 _c0[0x70];
    Unk_23d4470_Callable field_130;
    Unk_23d4470_Callable field_1b0;
    Unk_23d4470_Callable field_230;
    Unk_23d4470_Callable field_2b0;
};
PKMN_OFFSET_ASSERT(Unk_24025b0, field_80, 0x80);
PKMN_OFFSET_ASSERT(Unk_24025b0, field_88, 0x88);
PKMN_OFFSET_ASSERT(Unk_24025b0, field_90, 0x90);
PKMN_OFFSET_ASSERT(Unk_24025b0, field_98, 0x98);
PKMN_OFFSET_ASSERT(Unk_24025b0, field_a0, 0xa0);
PKMN_OFFSET_ASSERT(Unk_24025b0, field_a8, 0xa8);
PKMN_OFFSET_ASSERT(Unk_24025b0, field_b0, 0xb0);
PKMN_OFFSET_ASSERT(Unk_24025b0, field_b8, 0xb8);
PKMN_OFFSET_ASSERT(Unk_24025b0, field_130, 0x130);
PKMN_OFFSET_ASSERT(Unk_24025b0, field_1b0, 0x1b0);
PKMN_OFFSET_ASSERT(Unk_24025b0, field_230, 0x230);
PKMN_OFFSET_ASSERT(Unk_24025b0, field_2b0, 0x2b0);

// 0x7100fa7890: its key function
Unk_24025b0::~Unk_24025b0() {}

// 0x7100fa7880
void Unk_24025b0::vf9() {}

// 0x7100fa7a10; its type 0x7100fa7a80
const Unk_239a418_Type* Unk_24025b0::vf_type() {
    return Unk_GetType();
}
