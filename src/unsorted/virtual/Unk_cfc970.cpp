// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "gflib3/Unk_239a418.h"

// A class on Unk_239a418 whose type getter (0x7100cfd050) is out of line.
struct Unk_27dbd70 {
    static const Unk_239a418_Type* Unk_GetType();
};

class Unk_23e52a8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27dbd70::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    virtual void vf7();
    Unk_239a418_Ref<Unk_239a418> field_60;
};
PKMN_OFFSET_ASSERT(Unk_23e52a8, field_60, 0x60);

// 0x7100cfca90
const Unk_239a418_Type* Unk_23e52a8::vf_type() {
    return Unk_GetType();
}
