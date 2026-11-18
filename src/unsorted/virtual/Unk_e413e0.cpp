// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23f5ec8.h"

class Unk_23f1b08 : public Unk_23f5ec8 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f5ec8::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7() override;
    void vf8() override;
    u32 vf9() override;
    void vf10() override;
    void vf11() override;
    Unk_239a418_Ref<Unk_239a418> field_80;
};
PKMN_OFFSET_ASSERT(Unk_23f1b08, field_80, 0x80);

// 0x7100e413e0
void Unk_23f1b08::vf8() {}

// 0x7100e413f0
u32 Unk_23f1b08::vf9() {
    return 1;
}

// 0x7100e417e0; its type 0x7100e41a80
const Unk_239a418_Type* Unk_23f1b08::vf_type() {
    return Unk_GetType();
}
