// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23d4470.h"
#include "unsorted/Unk_23f4e40.h"

class Unk_242cfd0 : public Unk_23f4e40 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4e40::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    u32 vf7() override;
    void vf8() override;
    u32 vf9() override;
    void vf10() override;
    Unk_239a418_Ref<Unk_239a418> field_88;
    u8 _90[0x10];
    Unk_239a418_Ref<Unk_239a418> field_a0;
    u8 _a8[0x68];
    Unk_23d4470_Callable field_110;
};
PKMN_OFFSET_ASSERT(Unk_242cfd0, field_88, 0x88);
PKMN_OFFSET_ASSERT(Unk_242cfd0, field_a0, 0xa0);
PKMN_OFFSET_ASSERT(Unk_242cfd0, field_110, 0x110);

// 0x71012ca0e0
u32 Unk_242cfd0::vf7() {
    return 1;
}

// 0x71012ca410; its type 0x71012ca440
const Unk_239a418_Type* Unk_242cfd0::vf_type() {
    return Unk_GetType();
}
