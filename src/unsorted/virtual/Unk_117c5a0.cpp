// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "gflib3/Unk_239a418.h"

class Unk_241c9f8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    ~Unk_241c9f8() override;
    const Unk_239a418_Type* vf_type() override { return Unk_GetType(); }
    u8 _60[0x8];
    Unk_239a418_Ref<Unk_239a418> field_68;
    u8 _70[0x10];
    Unk_239a418_Ref<Unk_239a418> field_80;
    u8 _88[0x10];
    Unk_239a418_Ref<Unk_239a418> field_98;
    u8 _a0[0x10];
    Unk_239a418_Ref<Unk_239a418> field_b0;
};
PKMN_OFFSET_ASSERT(Unk_241c9f8, field_68, 0x68);
PKMN_OFFSET_ASSERT(Unk_241c9f8, field_80, 0x80);
PKMN_OFFSET_ASSERT(Unk_241c9f8, field_98, 0x98);
PKMN_OFFSET_ASSERT(Unk_241c9f8, field_b0, 0xb0);

// 0x710117c5a0: its key function
Unk_241c9f8::~Unk_241c9f8() {}
