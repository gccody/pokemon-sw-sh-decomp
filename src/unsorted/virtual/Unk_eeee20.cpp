// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23f4660.h"

class Unk_23f8b08 : public Unk_23f4660 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4660::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    u32 vf7() override;
    void vf8() override;
    void vf11() override;
    void vf12() override;
    void vf15() override;
    u32 vf16() override;
};

// 0x7100eef380
u32 Unk_23f8b08::vf16() {
    return 0;
}

// 0x7100eef790; its type 0x7100eeee20
const Unk_239a418_Type* Unk_23f8b08::vf_type() {
    return Unk_GetType();
}
