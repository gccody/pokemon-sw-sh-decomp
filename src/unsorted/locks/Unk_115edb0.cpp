// Scope: common
// The lock of a weak handle as Unk_241b378 (src/gflib3/Unk_Lock.h). Unk_241b378's getter is
// its type's: a class on the object itself. Written by tools/lockgen.py:
// regenerate, don't edit.
#include "gflib3/Unk_Lock.h"

class Unk_241b378 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// 0x710115edb0
template Unk_239a418_Ref<Unk_241b378> Unk_Lock<Unk_241b378>(Unk_239a418_Handle*);
