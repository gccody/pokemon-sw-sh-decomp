// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23f4660.h"

class Unk_2449970 : public Unk_23f4660 {
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

// 0x71015434f0
void Unk_2449970::vf10() {}

// 0x7101543500
u32 Unk_2449970::vf16() {
    return 0;
}

// 0x71015443e0; its type 0x7101544450
const Unk_239a418_Type* Unk_2449970::vf_type() {
    return Unk_GetType();
}
