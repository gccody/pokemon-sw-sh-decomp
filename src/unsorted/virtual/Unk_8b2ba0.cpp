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

class Unk_23b9e78 : public Unk_239a418 {
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
PKMN_OFFSET_ASSERT(Unk_23b9e78, field_78, 0x78);

// 0x71008b2bf0
const Unk_239a418_Type* Unk_23b9e78::vf_type() {
    return Unk_GetType();
}

// 0x71008b2c60
u64 Unk_23b9e78::vf7() {
    return field_78;
}
