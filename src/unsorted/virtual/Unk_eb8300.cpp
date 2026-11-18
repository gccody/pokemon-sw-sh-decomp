// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23f6328.h"

class Unk_23f6218 : public Unk_23f6328 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f6328::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf8() override;
    void vf14() override;
    void vf17() override;
    u32 vf18() override;
};

// 0x7100eb8310
const Unk_239a418_Type* Unk_23f6218::vf_type() {
    return Unk_GetType();
}
