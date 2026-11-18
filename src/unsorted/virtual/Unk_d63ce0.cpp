// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23f4e40.h"

class Unk_23ec9e8 : public Unk_23f4e40 {
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
    u8 _88[0xc];
    u32 field_94;
};
PKMN_OFFSET_ASSERT(Unk_23ec9e8, field_94, 0x94);

// 0x7100d63ce0
u32 Unk_23ec9e8::vf7() {
    return 1;
}

// 0x7100d63cf0
void Unk_23ec9e8::vf8() {
    field_94 = 1;
}

// 0x7100d64200
void Unk_23ec9e8::vf10() {}

// 0x7100d64220; its type 0x7100d64290
const Unk_239a418_Type* Unk_23ec9e8::vf_type() {
    return Unk_GetType();
}
