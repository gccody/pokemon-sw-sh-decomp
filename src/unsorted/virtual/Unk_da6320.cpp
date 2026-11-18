// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23f4e40.h"

class Unk_23eef08 : public Unk_23f4e40 {
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
};

// 0x7100da6330; its type 0x7100da63d0
const Unk_239a418_Type* Unk_23eef08::vf_type() {
    return Unk_GetType();
}

// 0x7100da6340
u32 Unk_23eef08::vf7() {
    return 1;
}

// 0x7100da6350
void Unk_23eef08::vf8() {}

// 0x7100da6360
void Unk_23eef08::vf10() {}
