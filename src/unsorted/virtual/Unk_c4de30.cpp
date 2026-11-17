// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23f43c8.h"

class Unk_23dbf20 : public Unk_23f4318 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4318::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
};

// 0x7100c4de40; its type 0x7100c4deb0
const Unk_239a418_Type* Unk_23dbf20::vf_type() {
    return Unk_GetType();
}
