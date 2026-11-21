// Scope: common
// The lock of a weak handle as Unk_2401d00 (src/gflib3/Unk_Lock.h). Unk_2401d00's getter is
// its type's: a class on the object itself. Written by tools/lockgen.py:
// regenerate, don't edit.
#include "gflib3/Unk_Lock.h"

class Unk_2401d00 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// 0x7100fa8210
template Unk_239a418_Ref<Unk_2401d00> Unk_Lock<Unk_2401d00>(Unk_239a418_Handle*);
