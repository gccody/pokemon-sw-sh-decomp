// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "gflib3/Unk_239a418.h"

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_dc5e30(void* self);

// A class on Unk_239a418 whose type getter (0x7100dadb70) is out of line.
struct Unk_27de920 {
    static const Unk_239a418_Type* Unk_GetType();
};

class Unk_23efc48 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27de920::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    virtual u32 vf7();
    virtual u32 vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual u32 vf13();
    virtual void vf14();
};

// 0x7100dc5900
u32 Unk_23efc48::vf7() {
    return 1;
}

// 0x7100dc5910
u32 Unk_23efc48::vf8() {
    return 1;
}

// 0x7100dc5920
void Unk_23efc48::vf9() {}

// 0x7100dc5930
void Unk_23efc48::vf10() {}

// 0x7100dc7690
void Unk_23efc48::vf11() {
    Unk_dc5e30(this);
}

// 0x7100dc76a0
void Unk_23efc48::vf12() {}

// 0x7100dc76b0
u32 Unk_23efc48::vf13() {
    return 0;
}

// 0x7100dc7a10
const Unk_239a418_Type* Unk_23efc48::vf_type() {
    return Unk_GetType();
}
