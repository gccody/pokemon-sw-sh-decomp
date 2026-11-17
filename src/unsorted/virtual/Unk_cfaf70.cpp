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

// The type between Unk_239a418 and Unk_23e5078 (its class isn't known yet).
struct Unk_27dbd30 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27dbd10::Unk_GetType());
        return &type;
    }
};

class Unk_23e5078 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27dbd30::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    virtual void vf7(bool value);
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14(u32 value);
    virtual void vf15(u32 value);
    virtual void vf16(u32 value);
    virtual u32 vf17();
    virtual u32 vf18();
    virtual u32 vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    u32 field_60;
    u32 field_64;
    u32 field_68;
    u8 _6c[0x24];
    bool field_90;
    u8 field_91;
};
PKMN_OFFSET_ASSERT(Unk_23e5078, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_23e5078, field_64, 0x64);
PKMN_OFFSET_ASSERT(Unk_23e5078, field_68, 0x68);
PKMN_OFFSET_ASSERT(Unk_23e5078, field_90, 0x90);
PKMN_OFFSET_ASSERT(Unk_23e5078, field_91, 0x91);

// 0x7100cfafc0
const Unk_239a418_Type* Unk_23e5078::vf_type() {
    return Unk_GetType();
}

// 0x7100cfb070
void Unk_23e5078::vf7(bool value) {
    field_90 = value;
}

// 0x7100cfb0a0
void Unk_23e5078::vf9() {
    field_91 = 1;
}

// 0x7100cfb0b0
void Unk_23e5078::vf10() {
    field_91 = 0;
}

// 0x7100cfb180
void Unk_23e5078::vf14(u32 value) {
    field_60 = value;
}

// 0x7100cfb190
void Unk_23e5078::vf15(u32 value) {
    field_64 = value;
}

// 0x7100cfb1a0
void Unk_23e5078::vf16(u32 value) {
    field_68 = value;
}

// 0x7100cfb1b0
u32 Unk_23e5078::vf17() {
    return field_60;
}

// 0x7100cfb1c0
u32 Unk_23e5078::vf18() {
    return field_64;
}

// 0x7100cfb1d0
u32 Unk_23e5078::vf19() {
    return field_68;
}
