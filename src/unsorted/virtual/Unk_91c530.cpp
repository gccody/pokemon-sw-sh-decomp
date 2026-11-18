// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23f4660.h"

// Tail-called by lifted functions. Placeholders, like the forwarders' callees.
void Unk_91b5a0(void*, u64);

// A class on Unk_23f4660 whose type getter (0x71009196c0) is out of line.
struct Unk_27d2f70 {
    static const Unk_239a418_Type* Unk_GetType();
};

class Unk_23be300 : public Unk_23f4660 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27d2f70::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf8() override;
    void vf10() override;
    void vf11() override;
    void vf12() override;
    void vf15() override;
    u32 vf16() override;
    virtual void vf17();
    virtual void vf18();
    u8 _5d0[0x60];
    u64 field_630;
};
PKMN_OFFSET_ASSERT(Unk_23be300, field_630, 0x630);

// 0x710091c530
void Unk_23be300::vf18() {
    Unk_91b5a0(this, field_630);
}

// 0x710091cae0
const Unk_239a418_Type* Unk_23be300::vf_type() {
    return Unk_GetType();
}
