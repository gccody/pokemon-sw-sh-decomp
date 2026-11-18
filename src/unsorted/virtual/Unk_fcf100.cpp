// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_24034f8.h"

class Unk_2403638 : public Unk_24034f8 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_24034f8::Unk_GetType());
        return &type;
    }

    ~Unk_2403638() override;
    const Unk_239a418_Type* vf_type() override;
    void vf8() override;
    void vf15() override;
    void vf17() override;
    u32 vf18() override;
    void vf19() override;
    Unk_239a418_Ref<Unk_239a418> field_708;
    Unk_239a418_Ref<Unk_239a418> field_710;
    Unk_239a418_Ref<Unk_239a418> field_718;
    Unk_239a418_Ref<Unk_239a418> field_720;
    Unk_239a418_Ref<Unk_239a418> field_728;
    u8 _730[0x20];
    Unk_239a418_Ref<Unk_239a418> field_750;
};
PKMN_OFFSET_ASSERT(Unk_2403638, field_708, 0x708);
PKMN_OFFSET_ASSERT(Unk_2403638, field_710, 0x710);
PKMN_OFFSET_ASSERT(Unk_2403638, field_718, 0x718);
PKMN_OFFSET_ASSERT(Unk_2403638, field_720, 0x720);
PKMN_OFFSET_ASSERT(Unk_2403638, field_728, 0x728);
PKMN_OFFSET_ASSERT(Unk_2403638, field_750, 0x750);

// 0x7100fcf100: its key function
Unk_2403638::~Unk_2403638() {}

// 0x7100fcf1e0
const Unk_239a418_Type* Unk_2403638::vf_type() {
    return Unk_GetType();
}
