// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "gflib3/Unk_239a418.h"

class Unk_23f4fc8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    ~Unk_23f4fc8() override;
    const Unk_239a418_Type* vf_type() override { return Unk_GetType(); }
    u8 _60[0x8];
    Unk_239a418_Ref<Unk_239a418> field_68;
    Unk_239a418_Ref<Unk_239a418> field_70;
    Unk_239a418_Ref<Unk_239a418> field_78;
    Unk_239a418_Ref<Unk_239a418> field_80;
};
PKMN_OFFSET_ASSERT(Unk_23f4fc8, field_68, 0x68);
PKMN_OFFSET_ASSERT(Unk_23f4fc8, field_70, 0x70);
PKMN_OFFSET_ASSERT(Unk_23f4fc8, field_78, 0x78);
PKMN_OFFSET_ASSERT(Unk_23f4fc8, field_80, 0x80);

// 0x7100e9de70: its key function
Unk_23f4fc8::~Unk_23f4fc8() {}
