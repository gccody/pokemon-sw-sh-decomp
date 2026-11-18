// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23f4660.h"

class Unk_23c0790 : public Unk_23f4660 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4660::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf8() override;
    u32 vf9() override;
    void vf15() override;
};

// 0x710093fbe0
u32 Unk_23c0790::vf9() {
    return 1;
}

// 0x710093fdb0; its type 0x710093a090
const Unk_239a418_Type* Unk_23c0790::vf_type() {
    return Unk_GetType();
}
