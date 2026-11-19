// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "gflib3/Unk_239a418.h"
#include "unsorted/Unk_23d4470.h"

class Unk_240de68 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    ~Unk_240de68() override;
    const Unk_239a418_Type* vf_type() override { return Unk_GetType(); }
    Unk_23d4470_Callable field_60;
};
PKMN_OFFSET_ASSERT(Unk_240de68, field_60, 0x60);

// 0x710108abc0: its key function
Unk_240de68::~Unk_240de68() {}
