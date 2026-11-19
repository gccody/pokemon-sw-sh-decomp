// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "gflib3/Unk_239a418.h"
#include "unsorted/Unk_23f43c8.h"

// Lifted through their own placeholder structs (cast_member).
struct Unk_fdbc60 {
    u8 _0[0x80];
    Unk_239a418* field_80;
};
PKMN_OFFSET_ASSERT(Unk_fdbc60, field_80, 0x80);

class Unk_2404cd8 : public Unk_23f43c8 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f43c8::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7() override;
    u32 vf8() override;
    void vf9() override;
    u64 _78;
    Unk_239a418_Ref<Unk_239a418> field_80;
    Unk_239a418_Ref<Unk_239a418> field_88;
    Unk_239a418_Ref<Unk_239a418> field_90;
    u64 _98;
    Unk_239a418_Ref<Unk_239a418> field_a0;
    Unk_239a418_Ref<Unk_239a418> field_a8;
};
PKMN_OFFSET_ASSERT(Unk_2404cd8, field_80, 0x80);
PKMN_OFFSET_ASSERT(Unk_2404cd8, field_88, 0x88);
PKMN_OFFSET_ASSERT(Unk_2404cd8, field_90, 0x90);
PKMN_OFFSET_ASSERT(Unk_2404cd8, field_a0, 0xa0);
PKMN_OFFSET_ASSERT(Unk_2404cd8, field_a8, 0xa8);

// 0x7100fdbc60
void Unk_2404cd8::vf9() {
    Unk_fdbc60* self = reinterpret_cast<Unk_fdbc60*>(this);
    Unk_239a418* v0 = self->field_80;
    self->field_80 = nullptr;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf5();
    }
}

// 0x7100fdbe00; its type 0x7100fdc130
const Unk_239a418_Type* Unk_2404cd8::vf_type() {
    return Unk_GetType();
}
