// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23f4e40.h"

class Unk_2431778 : public Unk_23f4e40 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4e40::Unk_GetType());
        return &type;
    }

    ~Unk_2431778() override;
    const Unk_239a418_Type* vf_type() override;
    u32 vf7() override;
    void vf8() override;
    u32 vf9() override;
    void vf10() override;
    Unk_239a418_Ref<Unk_239a418> field_88;
    u8 _90[0x8];
    Unk_239a418_Ref<Unk_239a418> field_98;
    u8 _a0[0x10];
    Unk_239a418_Ref<Unk_239a418> field_b0;
    u8 _b8[0x8];
    Unk_239a418_Ref<Unk_239a418> field_c0;
    u8 _c8[0x8];
    Unk_239a418_Ref<Unk_239a418> field_d0;
    u8 _d8[0x8];
    Unk_239a418_Ref<Unk_239a418> field_e0;
    u8 _e8[0xc0];
    Unk_239a418_Ref<Unk_239a418> field_1a8;
};
PKMN_OFFSET_ASSERT(Unk_2431778, field_88, 0x88);
PKMN_OFFSET_ASSERT(Unk_2431778, field_98, 0x98);
PKMN_OFFSET_ASSERT(Unk_2431778, field_b0, 0xb0);
PKMN_OFFSET_ASSERT(Unk_2431778, field_c0, 0xc0);
PKMN_OFFSET_ASSERT(Unk_2431778, field_d0, 0xd0);
PKMN_OFFSET_ASSERT(Unk_2431778, field_e0, 0xe0);
PKMN_OFFSET_ASSERT(Unk_2431778, field_1a8, 0x1a8);

// 0x7101344400: its key function
Unk_2431778::~Unk_2431778() {}

// 0x7101344540
u32 Unk_2431778::vf7() {
    return 1;
}

// 0x71013445d0
void Unk_2431778::vf10() {}

// 0x7101344780; its type 0x71013447b0
const Unk_239a418_Type* Unk_2431778::vf_type() {
    return Unk_GetType();
}
