// Scope: common
// The lock of a weak handle as Unk_27e9f48 (src/gflib3/Unk_Lock.h), with the type getters it
// inlines. Written by tools/lockgen.py: regenerate, don't edit.
#include "gflib3/Unk_Lock.h"

// Its getter is out of line.
struct Unk_2399bf0 {
    static const Unk_239a418_Type* Unk_GetType();
};

struct Unk_27d8f98 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2399bf0::Unk_GetType());
        return &type;
    }
};

struct Unk_241b428 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27d8f98::Unk_GetType());
        return &type;
    }
};

class Unk_27e9f48 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_241b428::Unk_GetType());
        return &type;
    }
};

// 0x71012052c0
template Unk_239a418_Ref<Unk_27e9f48> Unk_Lock<Unk_27e9f48>(Unk_239a418_Handle*);
