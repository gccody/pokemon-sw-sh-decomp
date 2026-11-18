// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "gflib3/Unk_2399590.h"

class Unk_23f4f10 : public Unk_2399590 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2399590::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
};

// 0x7100e9d7d0; its type 0x7100e9d840
const Unk_239a418_Type* Unk_23f4f10::vf_type() {
    return Unk_GetType();
}
