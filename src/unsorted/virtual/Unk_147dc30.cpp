// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23f43c8.h"

class Unk_243ef40 : public Unk_23f43c8 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f43c8::Unk_GetType());
        return &type;
    }

    ~Unk_243ef40() override;
    const Unk_239a418_Type* vf_type() override;
    void vf7() override;
    u32 vf8() override;
    void vf9() override;
    u8 _78[0x10];
    Unk_239a418_Ref<Unk_239a418> field_88;
    Unk_239a418_Ref<Unk_239a418> field_90;
    Unk_239a418_Ref<Unk_239a418> field_98;
    Unk_239a418_Ref<Unk_239a418> field_a0;
    Unk_239a418_Ref<Unk_239a418> field_a8;
    Unk_239a418_Ref<Unk_239a418> field_b0;
    Unk_239a418_Ref<Unk_239a418> field_b8;
};
PKMN_OFFSET_ASSERT(Unk_243ef40, field_88, 0x88);
PKMN_OFFSET_ASSERT(Unk_243ef40, field_90, 0x90);
PKMN_OFFSET_ASSERT(Unk_243ef40, field_98, 0x98);
PKMN_OFFSET_ASSERT(Unk_243ef40, field_a0, 0xa0);
PKMN_OFFSET_ASSERT(Unk_243ef40, field_a8, 0xa8);
PKMN_OFFSET_ASSERT(Unk_243ef40, field_b0, 0xb0);
PKMN_OFFSET_ASSERT(Unk_243ef40, field_b8, 0xb8);

// 0x710147dc40: its key function
Unk_243ef40::~Unk_243ef40() {}

// 0x710147dc30
void Unk_243ef40::vf9() {}

// 0x710147dd40; its type 0x710147ddb0
const Unk_239a418_Type* Unk_243ef40::vf_type() {
    return Unk_GetType();
}
