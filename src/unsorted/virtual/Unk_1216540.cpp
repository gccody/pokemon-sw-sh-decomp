// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "gflib3/Unk_239a418.h"

class Unk_2423ec8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    ~Unk_2423ec8() override;
    const Unk_239a418_Type* vf_type() override { return Unk_GetType(); }
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    u8 _60[0x10];
    Unk_239a418_Ref<Unk_239a418> field_70;
    Unk_239a418_Ref<Unk_239a418> field_78;
};
PKMN_OFFSET_ASSERT(Unk_2423ec8, field_70, 0x70);
PKMN_OFFSET_ASSERT(Unk_2423ec8, field_78, 0x78);

// 0x7101216dc0: its key function
Unk_2423ec8::~Unk_2423ec8() {}

// 0x7101216540
void Unk_2423ec8::vf10() {}

// 0x7101216ff0
void Unk_2423ec8::vf11() {}

// 0x7101217000
void Unk_2423ec8::vf12() {}

// 0x7101217010
void Unk_2423ec8::vf13() {}

// 0x7101217020
void Unk_2423ec8::vf14() {}

// 0x7101217030
void Unk_2423ec8::vf15() {}

// 0x7101217040
void Unk_2423ec8::vf16() {}

// 0x7101217050
void Unk_2423ec8::vf17() {}
