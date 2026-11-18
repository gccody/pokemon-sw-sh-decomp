// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_24034f8.h"

class Unk_2403b08 : public Unk_24034f8 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_24034f8::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf8() override;
    void vf14() override;
    void vf17() override;
    u32 vf18() override;
    void vf19() override;
};

// 0x7100fd0a40
const Unk_239a418_Type* Unk_2403b08::vf_type() {
    return Unk_GetType();
}
