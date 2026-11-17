// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "gflib3/Unk_239a418.h"

// A class on Unk_239a418 whose type getter (0x7100603810) is out of line.
struct Unk_27771e8 {
    static const Unk_239a418_Type* Unk_GetType();
};

class Unk_2399b40 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27771e8::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
};

// 0x71005d9bc0
const Unk_239a418_Type* Unk_2399b40::vf_type() {
    return Unk_GetType();
}
