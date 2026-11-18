// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "gflib3/Unk_239a418.h"

class Unk_23d2cd8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    ~Unk_23d2cd8() override;
    const Unk_239a418_Type* vf_type() override { return Unk_GetType(); }
    u8 _60[0x18];
    Unk_239a418_Ref<Unk_239a418> field_78;
};
PKMN_OFFSET_ASSERT(Unk_23d2cd8, field_78, 0x78);

// 0x7100ba2140: its key function
Unk_23d2cd8::~Unk_23d2cd8() {}
