// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "gflib3/Unk_239a418.h"

// Tail-called by lifted functions. Placeholders, like the forwarders' callees.
void Unk_104bf60(u64);
void Unk_104bfc0(u64);
void Unk_104c140(u64);
void Unk_104c390(u64);

// Globals other TUs define, named after their addresses.
extern u64 Unk_24ba150;

class Unk_240c008 : public Unk_239a418 {
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
    virtual void vf12();
    virtual void vf13();
};

// 0x710105cc20
void Unk_240c008::vf7() {
    Unk_104bf60(Unk_24ba150);
}

// 0x710105cc30
void Unk_240c008::vf8() {
    Unk_104c390(Unk_24ba150);
}

// 0x710105cc40
void Unk_240c008::vf9() {
    Unk_104c140(Unk_24ba150);
}

// 0x710105cc50
void Unk_240c008::vf10() {
    Unk_104bf60(Unk_24ba150);
}

// 0x710105cc60
void Unk_240c008::vf11() {
    Unk_104bf60(Unk_24ba150);
}

// 0x710105cc70
void Unk_240c008::vf12() {
    Unk_104bf60(Unk_24ba150);
}

// 0x710105cc80
void Unk_240c008::vf13() {
    Unk_104bfc0(Unk_24ba150);
}
