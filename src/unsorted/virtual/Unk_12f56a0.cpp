// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "gflib3/Unk_239a418.h"

class Unk_242ec10 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    ~Unk_242ec10() override;
    const Unk_239a418_Type* vf_type() override { return Unk_GetType(); }
    u8 _60[0x40];
    Unk_239a418_Ref<Unk_239a418> field_a0;
};
PKMN_OFFSET_ASSERT(Unk_242ec10, field_a0, 0xa0);

// 0x71012f56a0: its key function
Unk_242ec10::~Unk_242ec10() {}
