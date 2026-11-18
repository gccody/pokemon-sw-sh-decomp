// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23f4e40.h"

class Unk_2449338 : public Unk_23f4e40 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4e40::Unk_GetType());
        return &type;
    }

    ~Unk_2449338() override;
    const Unk_239a418_Type* vf_type() override;
    u32 vf7() override;
    void vf8() override;
    u32 vf9() override;
    void vf10() override;
    Unk_239a418_Ref<Unk_239a418> field_88;
    u8 _90[0x8];
    Unk_239a418_Ref<Unk_239a418> field_98;
    u8 _a0[0x20];
    Unk_239a418_Ref<Unk_239a418> field_c0;
    Unk_239a418_Ref<Unk_239a418> field_c8;
    u8 _d0[0x18];
    Unk_239a418_Ref<Unk_239a418> field_e8;
    Unk_239a418_Ref<Unk_239a418> field_f0;
    u8 _f8[0x8];
    Unk_239a418_Ref<Unk_239a418> field_100;
    u8 _108[0x10];
    Unk_239a418_Ref<Unk_239a418> field_118;
    u8 _120[0x8];
    Unk_239a418_Ref<Unk_239a418> field_128;
    u8 _130[0x8];
    Unk_239a418_Ref<Unk_239a418> field_138;
    u8 _140[0x8];
    Unk_239a418_Ref<Unk_239a418> field_148;
};
PKMN_OFFSET_ASSERT(Unk_2449338, field_88, 0x88);
PKMN_OFFSET_ASSERT(Unk_2449338, field_98, 0x98);
PKMN_OFFSET_ASSERT(Unk_2449338, field_c0, 0xc0);
PKMN_OFFSET_ASSERT(Unk_2449338, field_c8, 0xc8);
PKMN_OFFSET_ASSERT(Unk_2449338, field_e8, 0xe8);
PKMN_OFFSET_ASSERT(Unk_2449338, field_f0, 0xf0);
PKMN_OFFSET_ASSERT(Unk_2449338, field_100, 0x100);
PKMN_OFFSET_ASSERT(Unk_2449338, field_118, 0x118);
PKMN_OFFSET_ASSERT(Unk_2449338, field_128, 0x128);
PKMN_OFFSET_ASSERT(Unk_2449338, field_138, 0x138);
PKMN_OFFSET_ASSERT(Unk_2449338, field_148, 0x148);

// 0x7101539d10: its key function
Unk_2449338::~Unk_2449338() {}

// 0x7101539eb0
u32 Unk_2449338::vf7() {
    return 1;
}

// 0x710153ad50; its type 0x710153ad80
const Unk_239a418_Type* Unk_2449338::vf_type() {
    return Unk_GetType();
}
