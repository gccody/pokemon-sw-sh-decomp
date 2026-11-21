// Scope: common
// The lock of a weak handle as Unk_23fec78 (src/gflib3/Unk_Lock.h). Unk_23fec78's getter is
// its type's: a class on the object itself. Written by tools/lockgen.py:
// regenerate, don't edit.
#include "gflib3/Unk_Lock.h"

class Unk_23fec78 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// 0x7100f7fff0
template Unk_239a418_Ref<Unk_23fec78> Unk_Lock<Unk_23fec78>(Unk_239a418_Handle*);
