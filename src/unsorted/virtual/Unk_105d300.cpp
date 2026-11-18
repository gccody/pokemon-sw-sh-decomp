// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "gflib3/Unk_239a418.h"

// Tail-called by lifted functions. Placeholders, like the forwarders' callees.
void Unk_104c140(u64);

// Globals other TUs define, named after their addresses.
extern u64 Unk_24ba150;

class Unk_240c200 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override { return Unk_GetType(); }
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
};

// 0x710105d440
void Unk_240c200::vf7() {
    Unk_104c140(Unk_24ba150);
}

// 0x710105d450
void Unk_240c200::vf8() {
    Unk_104c140(Unk_24ba150);
}

// 0x710105d460
void Unk_240c200::vf9() {
    Unk_104c140(Unk_24ba150);
}

// 0x710105d470
void Unk_240c200::vf10() {
    Unk_104c140(Unk_24ba150);
}

// 0x710105d480
void Unk_240c200::vf11() {
    Unk_104c140(Unk_24ba150);
}
