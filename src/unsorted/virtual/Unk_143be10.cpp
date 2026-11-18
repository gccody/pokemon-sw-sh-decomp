// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23d4470.h"
#include "unsorted/Unk_23f4660.h"

class Unk_243b800 : public Unk_23f4660 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4660::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    u32 vf7() override;
    void vf8() override;
    void vf11() override;
    void vf12() override;
    void vf15() override;
    u32 vf16() override;
    u8 _5d0[0x10];
    Unk_239a418_Ref<Unk_239a418> field_5e0;
    Unk_239a418_Ref<Unk_239a418> field_5e8;
    Unk_239a418_Ref<Unk_239a418> field_5f0;
    Unk_239a418_Ref<Unk_239a418> field_5f8;
    Unk_23d4470_Callable field_600;
};
PKMN_OFFSET_ASSERT(Unk_243b800, field_5e0, 0x5e0);
PKMN_OFFSET_ASSERT(Unk_243b800, field_5e8, 0x5e8);
PKMN_OFFSET_ASSERT(Unk_243b800, field_5f0, 0x5f0);
PKMN_OFFSET_ASSERT(Unk_243b800, field_5f8, 0x5f8);
PKMN_OFFSET_ASSERT(Unk_243b800, field_600, 0x600);

// 0x710143be10
u32 Unk_243b800::vf7() {
    return 1;
}

// 0x710143c910
u32 Unk_243b800::vf16() {
    return 0;
}

// 0x710143cbb0; its type 0x710143cee0
const Unk_239a418_Type* Unk_243b800::vf_type() {
    return Unk_GetType();
}
