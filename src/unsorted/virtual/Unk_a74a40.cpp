// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23d4470.h"
#include "unsorted/Unk_23f4e40.h"

class Unk_23c6218 : public Unk_23f4e40 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4e40::Unk_GetType());
        return &type;
    }

    ~Unk_23c6218() override;
    const Unk_239a418_Type* vf_type() override;
    u32 vf7() override;
    void vf8() override;
    u32 vf9() override;
    void vf10() override;
    Unk_239a418_Ref<Unk_239a418> field_88;
    u8 _90[0x170];
    Unk_239a418_Ref<Unk_239a418> field_200;
    Unk_239a418_Ref<Unk_239a418> field_208;
    Unk_239a418_Ref<Unk_239a418> field_210;
    u8 _218[0x20];
    Unk_239a418_Ref<Unk_239a418> field_238;
    u8 _240[0x10];
    Unk_239a418_Ref<Unk_239a418> field_250;
    u8 _258[0x68];
    Unk_23d4470_Callable field_2c0;
    Unk_239a418_Ref<Unk_239a418> field_340;
    Unk_239a418_Ref<Unk_239a418> field_348;
    Unk_239a418_Ref<Unk_239a418> field_350;
    u8 _358[0x20];
    Unk_239a418_Ref<Unk_239a418> field_378;
    Unk_239a418_Ref<Unk_239a418> field_380;
    u8 _388[0x18];
    Unk_239a418_Ref<Unk_239a418> field_3a0;
};
PKMN_OFFSET_ASSERT(Unk_23c6218, field_88, 0x88);
PKMN_OFFSET_ASSERT(Unk_23c6218, field_200, 0x200);
PKMN_OFFSET_ASSERT(Unk_23c6218, field_208, 0x208);
PKMN_OFFSET_ASSERT(Unk_23c6218, field_210, 0x210);
PKMN_OFFSET_ASSERT(Unk_23c6218, field_238, 0x238);
PKMN_OFFSET_ASSERT(Unk_23c6218, field_250, 0x250);
PKMN_OFFSET_ASSERT(Unk_23c6218, field_2c0, 0x2c0);
PKMN_OFFSET_ASSERT(Unk_23c6218, field_340, 0x340);
PKMN_OFFSET_ASSERT(Unk_23c6218, field_348, 0x348);
PKMN_OFFSET_ASSERT(Unk_23c6218, field_350, 0x350);
PKMN_OFFSET_ASSERT(Unk_23c6218, field_378, 0x378);
PKMN_OFFSET_ASSERT(Unk_23c6218, field_380, 0x380);
PKMN_OFFSET_ASSERT(Unk_23c6218, field_3a0, 0x3a0);

// 0x7100a74a40: its key function
Unk_23c6218::~Unk_23c6218() {}

// 0x7100a74c10
u32 Unk_23c6218::vf7() {
    return 1;
}

// 0x7100a75fb0; its type 0x7100a76020
const Unk_239a418_Type* Unk_23c6218::vf_type() {
    return Unk_GetType();
}
