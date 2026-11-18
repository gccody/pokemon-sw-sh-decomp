// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23f43c8.h"

// Tail-called by lifted functions. Placeholders, like the forwarders' callees.
void Unk_136e8b0(u32);

class Unk_2440620 : public Unk_23f43c8 {
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

// 0x7101490cf0
u32 Unk_2440620::vf8() {
    return 1;
}

// 0x7101490d00
void Unk_2440620::vf9() {
    Unk_136e8b0(0x2d);
}

// 0x7101490d20; its type 0x7101490d90
const Unk_239a418_Type* Unk_2440620::vf_type() {
    return Unk_GetType();
}
