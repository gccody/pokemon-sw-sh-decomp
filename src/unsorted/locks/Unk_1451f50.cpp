// Scope: common
// The lock of a weak handle as Unk_2409458 (src/gflib3/Unk_Lock.h). Unk_2409458's getter is
// its type's: a class on the object itself. Written by tools/lockgen.py:
// regenerate, don't edit.
#include "gflib3/Unk_Lock.h"

class Unk_2409458 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// 0x7101451f50
template Unk_239a418_Ref<Unk_2409458> Unk_Lock<Unk_2409458>(Unk_239a418_Handle*);
