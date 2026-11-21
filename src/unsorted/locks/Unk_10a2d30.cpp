// Scope: common
// The lock of a weak handle as Unk_240f100 (src/gflib3/Unk_Lock.h). Unk_240f100's getter is
// its type's: a class on the object itself. Written by tools/lockgen.py:
// regenerate, don't edit.
#include "gflib3/Unk_Lock.h"

class Unk_240f100 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// 0x71010a2d30
template Unk_239a418_Ref<Unk_240f100> Unk_Lock<Unk_240f100>(Unk_239a418_Handle*);
