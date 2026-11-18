// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_241b640.h"

class Unk_241d190 : public Unk_241b640 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_241b640::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7() override;
    void vf9() override;
    void vf10() override;
    virtual u32 vf11();
    virtual u32 vf12();
    virtual void vf13();
};

class Unk_241e850 : public Unk_241d190 {
public:
    void vf9() override;
    void vf7() override;
    void vf10() override;
    u32 vf12() override;
    void vf13() override;
    u8 _a1[0x7];
    u64 field_a8;
    u64 field_b0;
    u32 field_b8;
};
PKMN_OFFSET_ASSERT(Unk_241e850, field_a8, 0xa8);
PKMN_OFFSET_ASSERT(Unk_241e850, field_b0, 0xb0);
PKMN_OFFSET_ASSERT(Unk_241e850, field_b8, 0xb8);

// 0x71011a1c90
void Unk_241e850::vf9() {
    field_b8 = 0;
    field_a8 = 0;
    field_b0 = 0;
}
