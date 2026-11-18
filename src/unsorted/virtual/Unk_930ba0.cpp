// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23f43c8.h"

// Tail-called by lifted functions. Placeholders, like the forwarders' callees.
void Unk_92e170(u64);

// A class on Unk_23f43c8 whose type getter (0x710091d680) is out of line.
struct Unk_27d2fa0 {
    static const Unk_239a418_Type* Unk_GetType();
};

class Unk_23bf8d8 : public Unk_23f43c8 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27d2fa0::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7() override;
    u32 vf8() override;
    void vf9() override;
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    u8 _78[0x8];
    u64 field_80;
};
PKMN_OFFSET_ASSERT(Unk_23bf8d8, field_80, 0x80);

// 0x7100930ba0
void Unk_23bf8d8::vf14() {
    Unk_92e170(field_80);
}

// 0x7100930bc0
const Unk_239a418_Type* Unk_23bf8d8::vf_type() {
    return Unk_GetType();
}
