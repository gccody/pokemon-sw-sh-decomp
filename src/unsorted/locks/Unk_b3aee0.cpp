// Scope: common
// The lock of a weak handle as Unk_23d1de8 (src/gflib3/Unk_Lock.h), with the type getters it
// inlines. Written by tools/lockgen.py: regenerate, don't edit.
#include "gflib3/Unk_Lock.h"

// Its getter is out of line.
struct Unk_27d8528 {
    static const Unk_239a418_Type* Unk_GetType();
};

struct Unk_23cf760 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27d8528::Unk_GetType());
        return &type;
    }
};

struct Unk_27d8538 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23cf760::Unk_GetType());
        return &type;
    }
};

class Unk_23d1de8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27d8538::Unk_GetType());
        return &type;
    }
};

// 0x7100b3aee0
template Unk_239a418_Ref<Unk_23d1de8> Unk_Lock<Unk_23d1de8>(Unk_239a418_Handle*);
