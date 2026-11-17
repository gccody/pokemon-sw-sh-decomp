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

// The type between Unk_239a418 and Unk_23e51b0 (its class isn't known yet).
struct Unk_27dbd50 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27dbd10::Unk_GetType());
        return &type;
    }
};

class Unk_23e51b0 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27dbd50::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    virtual void vf7(bool value);
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12(u32 value);
    virtual u32 vf13();
    virtual void vf14();
    virtual void vf15();
    u32 field_60;
    u8 _64[0x1c];
    bool field_80;
    u8 field_81;
};
PKMN_OFFSET_ASSERT(Unk_23e51b0, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_23e51b0, field_80, 0x80);
PKMN_OFFSET_ASSERT(Unk_23e51b0, field_81, 0x81);

// 0x7100cfc150
const Unk_239a418_Type* Unk_23e51b0::vf_type() {
    return Unk_GetType();
}

// 0x7100cfc200
void Unk_23e51b0::vf7(bool value) {
    field_80 = value;
}

// 0x7100cfc230
void Unk_23e51b0::vf9() {
    field_81 = 1;
}

// 0x7100cfc240
void Unk_23e51b0::vf10() {
    field_81 = 0;
}

// 0x7100cfc550
void Unk_23e51b0::vf12(u32 value) {
    field_60 = value;
}

// 0x7100cfc560
u32 Unk_23e51b0::vf13() {
    return field_60;
}
