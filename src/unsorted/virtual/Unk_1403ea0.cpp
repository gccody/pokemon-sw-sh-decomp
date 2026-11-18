// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "gflib3/Unk_239a418.h"

class Unk_24377b0 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    ~Unk_24377b0() override;
    const Unk_239a418_Type* vf_type() override { return Unk_GetType(); }
    virtual void vf7();
    u8 _60[0x10];
    Unk_239a418_Ref<Unk_239a418> field_70;
    u8 _78[0x18];
    Unk_239a418_Ref<Unk_239a418> field_90;
    u8 _98[0x20];
    Unk_239a418_Ref<Unk_239a418> field_b8;
};
PKMN_OFFSET_ASSERT(Unk_24377b0, field_70, 0x70);
PKMN_OFFSET_ASSERT(Unk_24377b0, field_90, 0x90);
PKMN_OFFSET_ASSERT(Unk_24377b0, field_b8, 0xb8);

// 0x7101403ea0: its key function
Unk_24377b0::~Unk_24377b0() {}
