// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "gflib3/Unk_239a418.h"

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_fcbc00(void* self);

class Unk_2403398 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
};

class Unk_24032c0 : public Unk_239a418, public Unk_2403398 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    ~Unk_24032c0() override;
    const Unk_239a418_Type* vf_type() override { return Unk_GetType(); }
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    u8 _68[0x8];
    Unk_239a418_Ref<Unk_239a418> field_70;
};
PKMN_OFFSET_ASSERT(Unk_24032c0, field_70, 0x70);

// 0x7100fcac40: its key function
Unk_24032c0::~Unk_24032c0() {}

// 0x7100fcbfd0
void Unk_24032c0::vf9() {
    Unk_fcbc00(this);
}
