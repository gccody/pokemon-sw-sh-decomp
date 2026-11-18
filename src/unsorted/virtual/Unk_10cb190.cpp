// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "gflib3/Unk_239a418.h"

class Unk_24141d8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    ~Unk_24141d8() override;
    const Unk_239a418_Type* vf_type() override { return Unk_GetType(); }
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    Unk_239a418_Ref<Unk_239a418> field_60;
};
PKMN_OFFSET_ASSERT(Unk_24141d8, field_60, 0x60);

// 0x71010cbbb0: its key function
Unk_24141d8::~Unk_24141d8() {}

// 0x71010cb190
void Unk_24141d8::vf9() {}
