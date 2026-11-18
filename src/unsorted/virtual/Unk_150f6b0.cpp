// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23f4e40.h"

// Tail-called by lifted functions. Placeholders, like the forwarders' callees.
void Unk_1063fe0(u64);

// Globals other TUs define, named after their addresses.
extern u64 Unk_24ba5b8;

class Unk_2447078 : public Unk_23f4e40 {
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
    Unk_239a418_Ref<Unk_239a418> field_88;
};
PKMN_OFFSET_ASSERT(Unk_2447078, field_88, 0x88);

// 0x710150f8f0
u32 Unk_2447078::vf7() {
    return 1;
}

// 0x710150f900
void Unk_2447078::vf8() {
    Unk_1063fe0(Unk_24ba5b8);
}

// 0x710150f910
void Unk_2447078::vf10() {}

// 0x710150fd50; its type 0x710150fd80
const Unk_239a418_Type* Unk_2447078::vf_type() {
    return Unk_GetType();
}
