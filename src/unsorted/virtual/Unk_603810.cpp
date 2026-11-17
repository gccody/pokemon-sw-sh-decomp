// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "gflib3/Unk_239a418.h"

// The type of Unk_239c050: other classes' getters call its getter.
struct Unk_27771e8 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

class Unk_239c050 : public Unk_239a418 {
public:
    const Unk_239a418_Type* vf_type() override;
};

// 0x7100608e30; its type 0x7100603810
const Unk_239a418_Type* Unk_239c050::vf_type() {
    return Unk_27771e8::Unk_GetType();
}

class Unk_239bfa0 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27771e8::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
};

// 0x7100608b50
const Unk_239a418_Type* Unk_239bfa0::vf_type() {
    return Unk_GetType();
}
