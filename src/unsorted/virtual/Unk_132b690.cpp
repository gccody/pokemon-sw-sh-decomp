// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23f4660.h"

class Unk_24306f8 : public Unk_23f4660 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4660::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf8() override;
    void vf11() override;
    void vf12() override;
    void vf15() override;
    u32 vf16() override;
    u8 _5d0[0x28];
    Unk_239a418_Ref<Unk_239a418> field_5f8;
};
PKMN_OFFSET_ASSERT(Unk_24306f8, field_5f8, 0x5f8);

// 0x710132b690
u32 Unk_24306f8::vf16() {
    return 0;
}

// 0x710132b840; its type 0x710132ba40
const Unk_239a418_Type* Unk_24306f8::vf_type() {
    return Unk_GetType();
}
