// Scope: common
// The lock of a weak handle as Unk_2402d18 (src/gflib3/Unk_Lock.h), with the type getters it
// inlines. Written by tools/lockgen.py: regenerate, don't edit.
#include "gflib3/Unk_Lock.h"

class Unk_2402d18 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// 0x7100fa1340
template Unk_239a418_Ref<Unk_2402d18> Unk_Lock<Unk_2402d18>(Unk_239a418_Handle*);
