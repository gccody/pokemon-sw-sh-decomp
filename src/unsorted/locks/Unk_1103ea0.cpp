// Scope: common
// The lock of a weak handle as Unk_27e51b8 (src/gflib3/Unk_Lock.h), with the type getters it
// inlines. Written by tools/lockgen.py: regenerate, don't edit.
#include "gflib3/Unk_Lock.h"

struct Unk_27e51b8_Base {
    virtual void vf0();
};

class Unk_27e51b8 : public Unk_27e51b8_Base, public Unk_239a498, public Unk_239a458 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// 0x7101103ea0
template Unk_239a418_Ref<Unk_27e51b8> Unk_Lock<Unk_27e51b8>(Unk_239a418_Handle*);
