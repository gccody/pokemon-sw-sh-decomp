// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "gflib3/Unk_239a418.h"

// A class on Unk_239a418 whose type getter (0x7100cfac80) is out of line.
struct Unk_27dbd10 {
    static const Unk_239a418_Type* Unk_GetType();
};

class Unk_23e4fa0 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27dbd10::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    virtual void vf7(bool value);
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    u8 _60[0x10];
    bool field_70;
    u8 field_71;
};
PKMN_OFFSET_ASSERT(Unk_23e4fa0, field_70, 0x70);
PKMN_OFFSET_ASSERT(Unk_23e4fa0, field_71, 0x71);

// 0x7100cfa7e0
const Unk_239a418_Type* Unk_23e4fa0::vf_type() {
    return Unk_GetType();
}

// 0x7100cfa850
void Unk_23e4fa0::vf7(bool value) {
    field_70 = value;
}

// 0x7100cfa880
void Unk_23e4fa0::vf9() {
    field_71 = 1;
}

// 0x7100cfa890
void Unk_23e4fa0::vf10() {
    field_71 = 0;
}
