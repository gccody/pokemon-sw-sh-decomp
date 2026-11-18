// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23f4660.h"

class Unk_2439200 : public Unk_23f4660 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4660::Unk_GetType());
        return &type;
    }

    ~Unk_2439200() override;
    const Unk_239a418_Type* vf_type() override;
    void vf8() override;
    void vf15() override;
    Unk_239a418_Ref<Unk_239a418> field_5d0;
    u8 _5d8[0x18];
    Unk_239a418_Ref<Unk_239a418> field_5f0;
    Unk_239a418_Ref<Unk_239a418> field_5f8;
    Unk_239a418_Ref<Unk_239a418> field_600;
    Unk_239a418_Ref<Unk_239a418> field_608;
    Unk_239a418_Ref<Unk_239a418> field_610;
    u8 _618[0x18];
    Unk_239a418_Ref<Unk_239a418> field_630;
};
PKMN_OFFSET_ASSERT(Unk_2439200, field_5d0, 0x5d0);
PKMN_OFFSET_ASSERT(Unk_2439200, field_5f0, 0x5f0);
PKMN_OFFSET_ASSERT(Unk_2439200, field_5f8, 0x5f8);
PKMN_OFFSET_ASSERT(Unk_2439200, field_600, 0x600);
PKMN_OFFSET_ASSERT(Unk_2439200, field_608, 0x608);
PKMN_OFFSET_ASSERT(Unk_2439200, field_610, 0x610);
PKMN_OFFSET_ASSERT(Unk_2439200, field_630, 0x630);

// 0x710141e920: its key function
Unk_2439200::~Unk_2439200() {}

// 0x710141ea20; its type 0x710141ea90
const Unk_239a418_Type* Unk_2439200::vf_type() {
    return Unk_GetType();
}
