// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23d4470.h"
#include "unsorted/Unk_23f4e40.h"

class Unk_242cf00 : public Unk_23f4e40 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4e40::Unk_GetType());
        return &type;
    }

    ~Unk_242cf00() override;
    const Unk_239a418_Type* vf_type() override;
    u32 vf7() override;
    void vf8() override;
    u32 vf9() override;
    void vf10() override;
    u8 _88[0x8];
    Unk_239a418_Ref<Unk_239a418> field_90;
    u8 _98[0x10];
    Unk_239a418_Ref<Unk_239a418> field_a8;
    u8 _b0[0x8];
    Unk_239a418_Ref<Unk_239a418> field_b8;
    u8 _c0[0x8];
    Unk_239a418_Ref<Unk_239a418> field_c8;
    u8 _d0[0x8];
    Unk_239a418_Ref<Unk_239a418> field_d8;
    u8 _e0[0xc0];
    Unk_239a418_Ref<Unk_239a418> field_1a0;
    u8 _1a8[0x20];
    Unk_239a418_Ref<Unk_239a418> field_1c8;
    Unk_239a418_Ref<Unk_239a418> field_1d0;
    u8 _1d8[0x18];
    Unk_239a418_Ref<Unk_239a418> field_1f0;
    u8 _1f8[0x18];
    Unk_239a418_Ref<Unk_239a418> field_210;
    u8 _218[0x68];
    Unk_23d4470_Callable field_280;
};
PKMN_OFFSET_ASSERT(Unk_242cf00, field_90, 0x90);
PKMN_OFFSET_ASSERT(Unk_242cf00, field_a8, 0xa8);
PKMN_OFFSET_ASSERT(Unk_242cf00, field_b8, 0xb8);
PKMN_OFFSET_ASSERT(Unk_242cf00, field_c8, 0xc8);
PKMN_OFFSET_ASSERT(Unk_242cf00, field_d8, 0xd8);
PKMN_OFFSET_ASSERT(Unk_242cf00, field_1a0, 0x1a0);
PKMN_OFFSET_ASSERT(Unk_242cf00, field_1c8, 0x1c8);
PKMN_OFFSET_ASSERT(Unk_242cf00, field_1d0, 0x1d0);
PKMN_OFFSET_ASSERT(Unk_242cf00, field_1f0, 0x1f0);
PKMN_OFFSET_ASSERT(Unk_242cf00, field_210, 0x210);
PKMN_OFFSET_ASSERT(Unk_242cf00, field_280, 0x280);

// 0x71012c9280: its key function
Unk_242cf00::~Unk_242cf00() {}

// 0x71012c9420
u32 Unk_242cf00::vf7() {
    return 1;
}

// 0x71012c9780
void Unk_242cf00::vf10() {}

// 0x71012c9790; its type 0x71012c97c0
const Unk_239a418_Type* Unk_242cf00::vf_type() {
    return Unk_GetType();
}
