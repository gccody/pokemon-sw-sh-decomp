// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x7102777228: its getter is out of line.
struct Unk_2399bf0 {
    static const Unk_239a418_Type* Unk_GetType();
};

// vtable 0x710242eae8: vf_type and its thunks 0x71012f5300 (+0x48), 0x71012f5370 (+0x50).
// Its base and its other functions aren't written here.
class Unk_242ead8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2399bf0::Unk_GetType());
        return &type;
    }

    ~Unk_242ead8() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x71012f5270
// 0x71012f5300
// 0x71012f5370
const Unk_239a418_Type* Unk_242ead8::vf_type() {
    return Unk_GetType();
}
