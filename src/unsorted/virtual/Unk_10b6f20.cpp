// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "gflib3/Unk_239a418.h"

// Tail-called by lifted functions. Placeholders, like the forwarders' callees.
void Unk_6a1ee0(u64);

class Unk_2412500 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// A class on Unk_239a418 whose type getter (0x7101054c40) is out of line.
struct Unk_27e3958 {
    static const Unk_239a418_Type* Unk_GetType();
};

class Unk_2412428 : public Unk_239a418, public Unk_2412500 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27e3958::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    Unk_239a418_Ref<Unk_239a418> field_68;
    u8 _70[0x8];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_2412428, field_68, 0x68);
PKMN_OFFSET_ASSERT(Unk_2412428, field_78, 0x78);

// 0x71010b7040
const Unk_239a418_Type* Unk_2412428::vf_type() {
    return Unk_GetType();
}

// 0x71010b70f0
void Unk_2412428::vf8() {
    Unk_6a1ee0(field_78);
}
