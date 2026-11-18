// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23f4e40.h"

class Unk_23ecbb8 : public Unk_23f4e40 {
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
    u8 _88[0xa8];
    u64 _130;
    u64 _138;
    u64 _140;
    u64 _148;
    u64 _150;
    u64 _158;
    u64 _160;
    u64 _168;
    u64 _170;
    Unk_239a418_Ref<Unk_239a418> field_178;
};
PKMN_OFFSET_ASSERT(Unk_23ecbb8, field_178, 0x178);

// 0x7100d64fc0
u32 Unk_23ecbb8::vf7() {
    return 1;
}

// 0x7100d64fd0
void Unk_23ecbb8::vf8() {}

// 0x7100d677c0
void Unk_23ecbb8::vf10() {}

// 0x7100d67f60; its type 0x7100d68110
const Unk_239a418_Type* Unk_23ecbb8::vf_type() {
    return Unk_GetType();
}
