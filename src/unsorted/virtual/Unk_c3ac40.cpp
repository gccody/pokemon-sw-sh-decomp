// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23f4e40.h"

class Unk_23dae20 : public Unk_23f4e40 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4e40::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    u32 vf7() override;
    void vf8() override;
    u32 vf9() override;
    void vf10() override;
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    u64 _88;
    u64 _90;
    u64 _98;
    u64 _a0;
    u64 _a8;
    Unk_239a418_Ref<Unk_239a418> field_b0;
    u64 _b8;
    u64 _c0;
    u64 _c8;
    Unk_239a418_Ref<Unk_239a418> field_d0;
};
PKMN_OFFSET_ASSERT(Unk_23dae20, field_b0, 0xb0);
PKMN_OFFSET_ASSERT(Unk_23dae20, field_d0, 0xd0);

// 0x7100c3ac40
u32 Unk_23dae20::vf7() {
    return 1;
}

// 0x7100c3ac50
void Unk_23dae20::vf8() {}

// 0x7100c3b2e0
void Unk_23dae20::vf10() {}

// 0x7100c3b3c0
void Unk_23dae20::vf13() {}

// 0x7100c3b3d0
void Unk_23dae20::vf14() {}

// 0x7100c3b540; its type 0x7100c3b730
const Unk_239a418_Type* Unk_23dae20::vf_type() {
    return Unk_GetType();
}
