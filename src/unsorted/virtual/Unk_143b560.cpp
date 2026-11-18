// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23f43c8.h"

// A class on Unk_23f43c8 whose type getter (0x710143ad70) is out of line.
struct Unk_27f0a48 {
    static const Unk_239a418_Type* Unk_GetType();
};

class Unk_243b560 : public Unk_23f43c8 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27f0a48::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7() override;
    u32 vf8() override;
    void vf9() override;
};

// 0x710143b560
void Unk_243b560::vf9() {}

// 0x710143b580
const Unk_239a418_Type* Unk_243b560::vf_type() {
    return Unk_GetType();
}
