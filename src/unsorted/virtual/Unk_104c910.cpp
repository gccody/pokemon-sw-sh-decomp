// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23f4e40.h"

class Unk_240b1d8 : public Unk_23f4e40 {
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

// 0x710104c920; its type 0x710104ca50
const Unk_239a418_Type* Unk_240b1d8::vf_type() {
    return Unk_GetType();
}

// 0x710104c930
u32 Unk_240b1d8::vf7() {
    return 1;
}

// 0x710104c9d0
u32 Unk_240b1d8::vf9() {
    return 0;
}

// 0x710104c9e0
void Unk_240b1d8::vf10() {}
