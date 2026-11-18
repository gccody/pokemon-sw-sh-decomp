// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23f43c8.h"

class Unk_2429868 : public Unk_23f43c8 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f43c8::Unk_GetType());
        return &type;
    }

    ~Unk_2429868() override;
    const Unk_239a418_Type* vf_type() override;
    void vf7() override;
    u32 vf8() override;
    void vf9() override;
    Unk_239a418_Ref<Unk_239a418> field_78;
    Unk_239a418_Ref<Unk_239a418> field_80;
    Unk_239a418_Ref<Unk_239a418> field_88;
    Unk_239a418_Ref<Unk_239a418> field_90;
    u8 _98[0x8];
    Unk_239a418_Ref<Unk_239a418> field_a0;
    Unk_239a418_Ref<Unk_239a418> field_a8;
};
PKMN_OFFSET_ASSERT(Unk_2429868, field_78, 0x78);
PKMN_OFFSET_ASSERT(Unk_2429868, field_80, 0x80);
PKMN_OFFSET_ASSERT(Unk_2429868, field_88, 0x88);
PKMN_OFFSET_ASSERT(Unk_2429868, field_90, 0x90);
PKMN_OFFSET_ASSERT(Unk_2429868, field_a0, 0xa0);
PKMN_OFFSET_ASSERT(Unk_2429868, field_a8, 0xa8);

// 0x710127cdd0: its key function
Unk_2429868::~Unk_2429868() {}

// 0x710127cdc0
void Unk_2429868::vf9() {}

// 0x710127ceb0; its type 0x710127cf20
const Unk_239a418_Type* Unk_2429868::vf_type() {
    return Unk_GetType();
}
