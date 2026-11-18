// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23d4470.h"
#include "unsorted/Unk_23f4e40.h"

class Unk_23eee38 : public Unk_23f4e40 {
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
    u8 _88[0x8];
    u32 field_90;
    u8 _94[0xc];
    Unk_239a418_Ref<Unk_239a418> field_a0;
    u8 _a8[0x68];
    Unk_23d4470_Callable field_110;
};
PKMN_OFFSET_ASSERT(Unk_23eee38, field_90, 0x90);
PKMN_OFFSET_ASSERT(Unk_23eee38, field_a0, 0xa0);
PKMN_OFFSET_ASSERT(Unk_23eee38, field_110, 0x110);

// 0x7100da5f70
u32 Unk_23eee38::vf7() {
    return 1;
}

// 0x7100da5f80
void Unk_23eee38::vf8() {
    field_90 = 0xa;
}

// 0x7100da5ff0
void Unk_23eee38::vf10() {}

// 0x7100da6000; its type 0x7100da6030
const Unk_239a418_Type* Unk_23eee38::vf_type() {
    return Unk_GetType();
}
