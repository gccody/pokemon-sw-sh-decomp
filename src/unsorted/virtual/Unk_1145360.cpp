// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "gflib3/Unk_239a418.h"

// A class on Unk_239a418 whose type getter (0x7101113c90) is out of line.
struct Unk_27e9d10 {
    static const Unk_239a418_Type* Unk_GetType();
};

class Unk_241a148 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27e9d10::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    Unk_239a418_Ref<Unk_239a418> field_60;
};
PKMN_OFFSET_ASSERT(Unk_241a148, field_60, 0x60);

// 0x7101145480
const Unk_239a418_Type* Unk_241a148::vf_type() {
    return Unk_GetType();
}
