// Scope: common
// The lock of a weak handle as Unk_2401e68 (src/gflib3/Unk_Lock.h), with the type getters it
// inlines. Written by tools/lockgen.py: regenerate, don't edit.
#include "gflib3/Unk_Lock.h"

class Unk_2401e68 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// 0x7100f9d830
template Unk_239a418_Ref<Unk_2401e68> Unk_Lock<Unk_2401e68>(Unk_239a418_Handle*);
