// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23f4e40.h"

class Unk_23eea20 : public Unk_23f4e40 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4e40::Unk_GetType());
        return &type;
    }

    ~Unk_23eea20() override;
    const Unk_239a418_Type* vf_type() override;
    u32 vf7() override;
    void vf8() override;
    u32 vf9() override;
    void vf10() override;
    Unk_239a418_Ref<Unk_239a418> field_88;
    u8 _90[0x1c8];
    Unk_239a418_Ref<Unk_239a418> field_258;
    u8 _260[0x18];
    Unk_239a418_Ref<Unk_239a418> field_278;
    u8 _280[0x18];
    Unk_239a418_Ref<Unk_239a418> field_298;
    u8 _2a0[0x18];
    Unk_239a418_Ref<Unk_239a418> field_2b8;
    u8 _2c0[0x18];
    Unk_239a418_Ref<Unk_239a418> field_2d8;
    u8 _2e0[0x18];
    Unk_239a418_Ref<Unk_239a418> field_2f8;
    u8 _300[0x18];
    Unk_239a418_Ref<Unk_239a418> field_318;
};
PKMN_OFFSET_ASSERT(Unk_23eea20, field_88, 0x88);
PKMN_OFFSET_ASSERT(Unk_23eea20, field_258, 0x258);
PKMN_OFFSET_ASSERT(Unk_23eea20, field_278, 0x278);
PKMN_OFFSET_ASSERT(Unk_23eea20, field_298, 0x298);
PKMN_OFFSET_ASSERT(Unk_23eea20, field_2b8, 0x2b8);
PKMN_OFFSET_ASSERT(Unk_23eea20, field_2d8, 0x2d8);
PKMN_OFFSET_ASSERT(Unk_23eea20, field_2f8, 0x2f8);
PKMN_OFFSET_ASSERT(Unk_23eea20, field_318, 0x318);

// 0x7100da0210: its key function
Unk_23eea20::~Unk_23eea20() {}

// 0x7100d9d560
u32 Unk_23eea20::vf7() {
    return 1;
}

// 0x7100d9d570
void Unk_23eea20::vf8() {}

// 0x7100d9fc10
void Unk_23eea20::vf10() {}

// 0x7100da0320; its type 0x7100da1430
const Unk_239a418_Type* Unk_23eea20::vf_type() {
    return Unk_GetType();
}
