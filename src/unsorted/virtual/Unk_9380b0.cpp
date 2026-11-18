// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23f43c8.h"

struct Unk_23bff18_80 {
    u8 _0[0x788];
    u8 field_788;
};
PKMN_OFFSET_ASSERT(Unk_23bff18_80, field_788, 0x788);

// A class on Unk_23f43c8 whose type getter (0x710091d680) is out of line.
struct Unk_27d2fa0 {
    static const Unk_239a418_Type* Unk_GetType();
};

class Unk_23bff18 : public Unk_23f43c8 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27d2fa0::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7() override;
    u32 vf8() override;
    void vf9() override;
    virtual void vf11();
    virtual void vf12();
    virtual u8 vf13();
    virtual void vf14();
    virtual void vf15();
    u8 _78[0x8];
    Unk_23bff18_80* field_80;
};
PKMN_OFFSET_ASSERT(Unk_23bff18, field_80, 0x80);

// 0x71009380b0
u8 Unk_23bff18::vf13() {
    return field_80->field_788;
}

// 0x7100938110
const Unk_239a418_Type* Unk_23bff18::vf_type() {
    return Unk_GetType();
}
