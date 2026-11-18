// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23f4e40.h"

class Unk_23eefd8 : public Unk_23f4e40 {
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
    u64 _88;
    u64 _90;
    u64 _98;
    Unk_239a418_Ref<Unk_239a418> field_a0;
};
PKMN_OFFSET_ASSERT(Unk_23eefd8, field_a0, 0xa0);

// 0x7100da6580
u32 Unk_23eefd8::vf7() {
    return 1;
}

// 0x7100da6590
void Unk_23eefd8::vf8() {}

// 0x7100da6af0
void Unk_23eefd8::vf10() {}

// 0x7100da6bc0; its type 0x7100da6d70
const Unk_239a418_Type* Unk_23eefd8::vf_type() {
    return Unk_GetType();
}
