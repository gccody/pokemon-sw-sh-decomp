// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027f0020: its getter is out of line.
struct Unk_27f0020 {
    static const Unk_239a418_Type* Unk_GetType();
};

// vtable 0x7102435b18: vf_type and its thunks 0x71013d27e0 (+0x48), 0x71013d2850 (+0x50).
// Its base and its other functions aren't written here.
class Unk_2435b08 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27f0020::Unk_GetType());
        return &type;
    }

    ~Unk_2435b08() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x7102435bf0: vf_type and its thunks 0x71013d34d0 (+0x48), 0x71013d3540 (+0x50).
// Its base and its other functions aren't written here.
class Unk_2435be0 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27f0020::Unk_GetType());
        return &type;
    }

    ~Unk_2435be0() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x71013d2750
// 0x71013d27e0
// 0x71013d2850
const Unk_239a418_Type* Unk_2435b08::vf_type() {
    return Unk_GetType();
}

// 0x71013d3440
// 0x71013d34d0
// 0x71013d3540
const Unk_239a418_Type* Unk_2435be0::vf_type() {
    return Unk_GetType();
}
