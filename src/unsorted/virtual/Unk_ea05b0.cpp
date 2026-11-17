// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "gflib3/Unk_239a418.h"

// A class on Unk_239a418 whose type getter (0x7100ea0b20) is out of line.
struct Unk_27d9360 {
    static const Unk_239a418_Type* Unk_GetType();
};

class Unk_23f5318 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27d9360::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    virtual void vf7();
    virtual u32 vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    u8 _60[0x10];
    Unk_239a418_Ref<Unk_239a418> field_70;
    Unk_239a418_Ref<Unk_239a418> field_78;
};
PKMN_OFFSET_ASSERT(Unk_23f5318, field_70, 0x70);
PKMN_OFFSET_ASSERT(Unk_23f5318, field_78, 0x78);

// 0x7100ea0980
u32 Unk_23f5318::vf8() {
    return 0;
}

// 0x7100ea09d0
const Unk_239a418_Type* Unk_23f5318::vf_type() {
    return Unk_GetType();
}
