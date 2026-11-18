// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "gflib3/Unk_239a418.h"

class Unk_241a360 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
};

class Unk_241a2a8 : public Unk_239a418, public Unk_241a360 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    ~Unk_241a2a8() override;
    const Unk_239a418_Type* vf_type() override { return Unk_GetType(); }
    virtual void vf7();
    Unk_239a418_Ref<Unk_239a418> field_68;
};
PKMN_OFFSET_ASSERT(Unk_241a2a8, field_68, 0x68);

// 0x71011496a0: its key function
Unk_241a2a8::~Unk_241a2a8() {}
