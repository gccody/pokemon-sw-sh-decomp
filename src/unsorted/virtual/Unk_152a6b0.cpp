// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23f4660.h"

class Unk_2448020 : public Unk_23f4660 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4660::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf8() override;
    void vf10() override;
    void vf15() override;
    u32 vf16() override;
};

// 0x710152a6b0
void Unk_2448020::vf8() {}

// 0x710152a6c0
void Unk_2448020::vf10() {}

// 0x710152a6d0
u32 Unk_2448020::vf16() {
    return 0;
}

// 0x710152a810; its type 0x710152a880
const Unk_239a418_Type* Unk_2448020::vf_type() {
    return Unk_GetType();
}
