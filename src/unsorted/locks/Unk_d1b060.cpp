// Scope: common
// The lock of a weak handle as Unk_23e9f78 (src/gflib3/Unk_Lock.h), with the type getters it
// inlines. Written by tools/lockgen.py: regenerate, don't edit.
#include "gflib3/Unk_Lock.h"

// Its getter is out of line.
struct Unk_27771d8 {
    static const Unk_239a418_Type* Unk_GetType();
};

struct Unk_27771c8 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27771d8::Unk_GetType());
        return &type;
    }
};

struct Unk_23dc940 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27771c8::Unk_GetType());
        return &type;
    }
};

class Unk_23e9f78 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23dc940::Unk_GetType());
        return &type;
    }
};

// 0x7100d1b060
template Unk_239a418_Ref<Unk_23e9f78> Unk_Lock<Unk_23e9f78>(Unk_239a418_Handle*);
