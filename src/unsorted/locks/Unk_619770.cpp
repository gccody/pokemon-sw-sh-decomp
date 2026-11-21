// Scope: common
// The lock of a weak handle as Unk_2774000 (src/gflib3/Unk_Lock.h), with the type getters it
// inlines. Written by tools/lockgen.py: regenerate, don't edit.
#include "gflib3/Unk_Lock.h"

struct Unk_2774000_Base {
    virtual void vf0();
};

class Unk_2774000 : public Unk_2774000_Base, public Unk_239a498, public Unk_239a458 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// 0x7100619770
template Unk_239a418_Ref<Unk_2774000> Unk_Lock<Unk_2774000>(Unk_239a418_Handle*);
