// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23f4e40.h"

class Unk_23edb90 : public Unk_23f4e40 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4e40::Unk_GetType());
        return &type;
    }

    ~Unk_23edb90() override;
    const Unk_239a418_Type* vf_type() override;
    u32 vf7() override;
    void vf8() override;
    u32 vf9() override;
    void vf10() override;
};

// 0x7100d7e3e0: its key function
Unk_23edb90::~Unk_23edb90() {}

// 0x7100d7e440
u32 Unk_23edb90::vf7() {
    return 1;
}

// 0x7100d7e450
void Unk_23edb90::vf8() {}

// 0x7100d7e700
void Unk_23edb90::vf10() {}

// 0x7100d7e710; its type 0x7100d7e740
const Unk_239a418_Type* Unk_23edb90::vf_type() {
    return Unk_GetType();
}
