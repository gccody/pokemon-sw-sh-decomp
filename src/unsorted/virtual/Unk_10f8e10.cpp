// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "gflib3/Unk_239a418.h"

class Unk_2417c28 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    ~Unk_2417c28() override;
    const Unk_239a418_Type* vf_type() override { return Unk_GetType(); }
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    Unk_239a418_Ref<Unk_239a418> field_60;
};
PKMN_OFFSET_ASSERT(Unk_2417c28, field_60, 0x60);

// 0x71010f8e10: its key function
Unk_2417c28::~Unk_2417c28() {}
