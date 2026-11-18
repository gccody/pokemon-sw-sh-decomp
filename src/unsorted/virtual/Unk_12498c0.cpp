// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23f43c8.h"

// Tail-called by lifted functions. Placeholders, like the forwarders' callees.
void Unk_c43ed0(u64, u32, u32, u32);

// Globals other TUs define, named after their addresses.
extern u64 Unk_24ba638;

class Unk_2426900 : public Unk_23f43c8 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f43c8::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7() override;
    u32 vf8() override;
    void vf9() override;
};

// 0x71012498c0
void Unk_2426900::vf9() {
    Unk_c43ed0(Unk_24ba638, 0, 0, 0xa);
}

// 0x71012498f0; its type 0x7101249960
const Unk_239a418_Type* Unk_2426900::vf_type() {
    return Unk_GetType();
}
