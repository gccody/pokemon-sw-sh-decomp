// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23d4470.h"
#include "unsorted/Unk_23f4660.h"

class Unk_2429118 : public Unk_23f4660 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4660::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf8() override;
    void vf14() override;
    Unk_23d4470_Callable field_5d0;
};
PKMN_OFFSET_ASSERT(Unk_2429118, field_5d0, 0x5d0);

// 0x71012766e0; its type 0x7101276890
const Unk_239a418_Type* Unk_2429118::vf_type() {
    return Unk_GetType();
}
