// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "gflib3/Unk_239a418.h"

class Unk_2430c78 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    ~Unk_2430c78() override;
    const Unk_239a418_Type* vf_type() override { return Unk_GetType(); }
    u8 _60[0x20];
    Unk_239a418_Ref<Unk_239a418> field_80;
};
PKMN_OFFSET_ASSERT(Unk_2430c78, field_80, 0x80);

// 0x7101334e60: its key function
Unk_2430c78::~Unk_2430c78() {}
