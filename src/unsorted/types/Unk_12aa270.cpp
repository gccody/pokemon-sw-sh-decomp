// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027ee8c8: its getter is out of line.
struct Unk_242b7a0 {
    static const Unk_239a418_Type* Unk_GetType();
};

// vtable 0x710242bbd8: vf_type and its thunks 0x71012aa300 (+0x48), 0x71012aa370 (+0x50).
// Its base and its other functions aren't written here.
class Unk_242bbc8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_242b7a0::Unk_GetType());
        return &type;
    }

    ~Unk_242bbc8() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x71012aa270
// 0x71012aa300
// 0x71012aa370
const Unk_239a418_Type* Unk_242bbc8::vf_type() {
    return Unk_GetType();
}
