// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "gflib3/Unk_239a418.h"

// A class on Unk_239a418 whose type getter (0x710089b390) is out of line.
struct Unk_27d1078 {
    static const Unk_239a418_Type* Unk_GetType();
};

class Unk_2407130 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27d1078::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    virtual u64 vf7();
    virtual void vf8();
    virtual void vf9();
    u8 _60[0x18];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_2407130, field_78, 0x78);

// 0x71010082f0
const Unk_239a418_Type* Unk_2407130::vf_type() {
    return Unk_GetType();
}

// 0x7101008360
u64 Unk_2407130::vf7() {
    return field_78;
}
