// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "gflib3/Unk_239bb58.h"

class Unk_239fc70 : public Unk_239bb58 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239bb58::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7() override;
};

// 0x710066a850; its type 0x710066a900
const Unk_239a418_Type* Unk_239fc70::vf_type() {
    return Unk_GetType();
}
