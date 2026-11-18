// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23f4660.h"

class Unk_23fe058 : public Unk_23f4660 {
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

// 0x7100f4c650
void Unk_23fe058::vf10() {}

// 0x7100f4cde0; its type 0x7100f4ce50
const Unk_239a418_Type* Unk_23fe058::vf_type() {
    return Unk_GetType();
}
