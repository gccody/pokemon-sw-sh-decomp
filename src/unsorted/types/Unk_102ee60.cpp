// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027d9438: its getter is out of line.
struct Unk_27d9438 {
    static const Unk_239a418_Type* Unk_GetType();
};

// vtable 0x7102409538: vf_type and its thunks 0x710102f0c0 (+0x48), 0x710102f2c0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_2409528 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27d9438::Unk_GetType());
        return &type;
    }

    ~Unk_2409528() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x710102ee60
// 0x710102f0c0
// 0x710102f2c0
const Unk_239a418_Type* Unk_2409528::vf_type() {
    return Unk_GetType();
}
