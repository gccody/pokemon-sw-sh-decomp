// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23d4470.h"
#include "unsorted/Unk_23f43c8.h"

class Unk_2426db8 : public Unk_23f43c8 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f43c8::Unk_GetType());
        return &type;
    }

    ~Unk_2426db8() override;
    const Unk_239a418_Type* vf_type() override;
    void vf7() override;
    u32 vf8() override;
    void vf9() override;
    u8 _78[0x58];
    Unk_23d4470_Callable field_d0;
    Unk_23d4470_Callable field_150;
    Unk_23d4470_Callable field_1d0;
    Unk_23d4470_Callable field_250;
    Unk_23d4470_Callable field_2d0;
    Unk_23d4470_Callable field_350;
    Unk_23d4470_Callable field_3d0;
    Unk_23d4470_Callable field_450;
    Unk_23d4470_Callable field_4d0;
};
PKMN_OFFSET_ASSERT(Unk_2426db8, field_d0, 0xd0);
PKMN_OFFSET_ASSERT(Unk_2426db8, field_150, 0x150);
PKMN_OFFSET_ASSERT(Unk_2426db8, field_1d0, 0x1d0);
PKMN_OFFSET_ASSERT(Unk_2426db8, field_250, 0x250);
PKMN_OFFSET_ASSERT(Unk_2426db8, field_2d0, 0x2d0);
PKMN_OFFSET_ASSERT(Unk_2426db8, field_350, 0x350);
PKMN_OFFSET_ASSERT(Unk_2426db8, field_3d0, 0x3d0);
PKMN_OFFSET_ASSERT(Unk_2426db8, field_450, 0x450);
PKMN_OFFSET_ASSERT(Unk_2426db8, field_4d0, 0x4d0);

// 0x7101250d30: its key function
Unk_2426db8::~Unk_2426db8() {}

// 0x710124d540
void Unk_2426db8::vf9() {}

// 0x7101250e90; its type 0x7101250f00
const Unk_239a418_Type* Unk_2426db8::vf_type() {
    return Unk_GetType();
}
