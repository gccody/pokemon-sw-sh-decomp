// Scope: common
// The lock of a weak handle as Unk_2418fc0 (src/gflib3/Unk_Lock.h), with the type getters it
// inlines. Written by tools/lockgen.py: regenerate, don't edit.
#include "gflib3/Unk_Lock.h"

// Its getter is out of line.
struct Unk_23f5318 {
    static const Unk_239a418_Type* Unk_GetType();
};

struct Unk_23f41d0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f5318::Unk_GetType());
        return &type;
    }
};

struct Unk_241ff00 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f41d0::Unk_GetType());
        return &type;
    }
};

class Unk_2418fc0 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_241ff00::Unk_GetType());
        return &type;
    }
};

// 0x7101119b00
template Unk_239a418_Ref<Unk_2418fc0> Unk_Lock<Unk_2418fc0>(Unk_239a418_Handle*);
