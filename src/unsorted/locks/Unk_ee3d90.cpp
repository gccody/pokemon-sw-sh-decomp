// Scope: common
// The lock of a weak handle as Unk_239ebc8 (src/gflib3/Unk_Lock.h). Unk_239ebc8's getter is
// its type's: a class on the object itself. Written by tools/lockgen.py:
// regenerate, don't edit.
#include "gflib3/Unk_Lock.h"

class Unk_239ebc8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// 0x7100ee3d90
template Unk_239a418_Ref<Unk_239ebc8> Unk_Lock<Unk_239ebc8>(Unk_239a418_Handle*);
