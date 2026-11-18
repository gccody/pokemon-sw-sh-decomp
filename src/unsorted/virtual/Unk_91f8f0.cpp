// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23f4660.h"

// Tail-called by lifted functions. Placeholders, like the forwarders' callees.
void Unk_91b5a0(void*, u64);
void Unk_91b5c0(void*, u64, u64, u32);

// A class on Unk_23f4660 whose type getter (0x71009196c0) is out of line.
struct Unk_27d2f70 {
    static const Unk_239a418_Type* Unk_GetType();
};

class Unk_23be868 : public Unk_23f4660 {
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
    u64 _5d0;
    u64 _5d8;
    u64 _5e0;
    Unk_239a418_Ref<Unk_239a418> field_5e8;
    u64 _5f0;
    u64 field_5f8;
};
PKMN_OFFSET_ASSERT(Unk_23be868, field_5e8, 0x5e8);
PKMN_OFFSET_ASSERT(Unk_23be868, field_5f8, 0x5f8);

// 0x710091f8f0
void Unk_23be868::vf17() {
    Unk_91b5c0(this, field_5f8, 0, 1);
}

// 0x710091f900
void Unk_23be868::vf18() {
    Unk_91b5a0(this, field_5f8);
}

// 0x710091fc80
const Unk_239a418_Type* Unk_23be868::vf_type() {
    return Unk_GetType();
}
