// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "gflib3/Unk_239a418.h"

// A class on Unk_239a418 whose type getter (0x7101113c90) is out of line.
struct Unk_27e9d10 {
    static const Unk_239a418_Type* Unk_GetType();
};

class Unk_24194a0 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27e9d10::Unk_GetType());
        return &type;
    }

    ~Unk_24194a0() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x7101128c40: its key function
Unk_24194a0::~Unk_24194a0() {}

// 0x71011291f0
const Unk_239a418_Type* Unk_24194a0::vf_type() {
    return Unk_GetType();
}
