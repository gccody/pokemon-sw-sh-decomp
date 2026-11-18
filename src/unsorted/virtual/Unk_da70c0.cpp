// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23f4e40.h"

class Unk_23ef0a8 : public Unk_23f4e40 {
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

// 0x7100da70c0
u32 Unk_23ef0a8::vf7() {
    return 1;
}

// 0x7100da70d0
void Unk_23ef0a8::vf8() {}

// 0x7100da7740
void Unk_23ef0a8::vf10() {}

// 0x7100da7760; its type 0x7100da77d0
const Unk_239a418_Type* Unk_23ef0a8::vf_type() {
    return Unk_GetType();
}
