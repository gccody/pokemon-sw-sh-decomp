// Scope: common
// The lock of a weak handle as Unk_240df18 (src/gflib3/Unk_Lock.h), with the type getters it
// inlines. Written by tools/lockgen.py: regenerate, don't edit.
#include "gflib3/Unk_Lock.h"

class Unk_240df18 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// 0x71010a7c10
template Unk_239a418_Ref<Unk_240df18> Unk_Lock<Unk_240df18>(Unk_239a418_Handle*);
