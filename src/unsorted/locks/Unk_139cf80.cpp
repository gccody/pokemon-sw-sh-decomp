// Scope: common
// The lock of a weak handle as Unk_2431de8 (src/gflib3/Unk_Lock.h), with the type getters it
// inlines. Written by tools/lockgen.py: regenerate, don't edit.
#include "gflib3/Unk_Lock.h"

class Unk_2431de8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// 0x710139cf80
template Unk_239a418_Ref<Unk_2431de8> Unk_Lock<Unk_2431de8>(Unk_239a418_Handle*);
