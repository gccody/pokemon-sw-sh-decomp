// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "gflib3/Unk_239a418.h"

// A class on Unk_239a418 whose type getter (0x7100c657d0) is out of line.
struct Unk_27effd0 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type between Unk_239a418 and Unk_23edd30 (its class isn't known yet).
struct Unk_27da210 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27effd0::Unk_GetType());
        return &type;
    }
};

class Unk_23edd30 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27da210::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    u8 _60[0x40];
    Unk_239a418_Ref<Unk_239a418> field_a0;
};
PKMN_OFFSET_ASSERT(Unk_23edd30, field_a0, 0xa0);

// 0x7100d83580
const Unk_239a418_Type* Unk_23edd30::vf_type() {
    return Unk_GetType();
}
