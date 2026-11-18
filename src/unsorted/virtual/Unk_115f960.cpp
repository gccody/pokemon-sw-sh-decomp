// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "gflib3/Unk_239a418.h"

class Unk_241b378 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    ~Unk_241b378() override;
    const Unk_239a418_Type* vf_type() override { return Unk_GetType(); }
    Unk_239a418_Ref<Unk_239a418> field_60;
    Unk_239a418_Ref<Unk_239a418> field_68;
};
PKMN_OFFSET_ASSERT(Unk_241b378, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_241b378, field_68, 0x68);

// 0x710115f960: its key function
Unk_241b378::~Unk_241b378() {}
