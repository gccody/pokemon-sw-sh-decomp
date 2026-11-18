// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23f43c8.h"

class Unk_23f6ba8 : public Unk_23f43c8 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f43c8::Unk_GetType());
        return &type;
    }

    ~Unk_23f6ba8() override;
    const Unk_239a418_Type* vf_type() override;
    void vf7() override;
    u32 vf8() override;
    void vf9() override;
    u8 _78[0x1a8];
    Unk_239a418_Ref<Unk_239a418> field_220;
    u8 _228[0x68];
    Unk_239a418_Ref<Unk_239a418> field_290;
    Unk_239a418_Ref<Unk_239a418> field_298;
    Unk_239a418_Ref<Unk_239a418> field_2a0;
    Unk_239a418_Ref<Unk_239a418> field_2a8;
    Unk_239a418_Ref<Unk_239a418> field_2b0;
    Unk_239a418_Ref<Unk_239a418> field_2b8;
    Unk_239a418_Ref<Unk_239a418> field_2c0;
    Unk_239a418_Ref<Unk_239a418> field_2c8;
};
PKMN_OFFSET_ASSERT(Unk_23f6ba8, field_220, 0x220);
PKMN_OFFSET_ASSERT(Unk_23f6ba8, field_290, 0x290);
PKMN_OFFSET_ASSERT(Unk_23f6ba8, field_298, 0x298);
PKMN_OFFSET_ASSERT(Unk_23f6ba8, field_2a0, 0x2a0);
PKMN_OFFSET_ASSERT(Unk_23f6ba8, field_2a8, 0x2a8);
PKMN_OFFSET_ASSERT(Unk_23f6ba8, field_2b0, 0x2b0);
PKMN_OFFSET_ASSERT(Unk_23f6ba8, field_2b8, 0x2b8);
PKMN_OFFSET_ASSERT(Unk_23f6ba8, field_2c0, 0x2c0);
PKMN_OFFSET_ASSERT(Unk_23f6ba8, field_2c8, 0x2c8);

// 0x7100ec1d70: its key function
Unk_23f6ba8::~Unk_23f6ba8() {}

// 0x7100ec1c30
void Unk_23f6ba8::vf9() {}

// 0x7100ec1ea0; its type 0x7100ec1f10
const Unk_239a418_Type* Unk_23f6ba8::vf_type() {
    return Unk_GetType();
}
