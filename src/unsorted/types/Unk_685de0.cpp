// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x7102774028: its getter is out of line.
struct Unk_2399708 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027740c8: its getter is out of line.
struct Unk_239bb58 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x7102777198.
struct Unk_239ba98 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_2399708::Unk_GetType());
        return &type;
    }
};

// vtable 0x71023a1298: vf_type and its thunks 0x7100685e50 (+0x48), 0x7100685ec0 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23a1288 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239bb58::Unk_GetType());
        return &type;
    }

    ~Unk_23a1288() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x71023a13f8: vf_type and its thunks 0x71006866a0 (+0x48), 0x7100686750 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23a13e8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239ba98::Unk_GetType());
        return &type;
    }

    ~Unk_23a13e8() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x7100685de0
// 0x7100685e50
// 0x7100685ec0
const Unk_239a418_Type* Unk_23a1288::vf_type() {
    return Unk_GetType();
}

// 0x7100686530
// 0x71006866a0
// 0x7100686750
const Unk_239a418_Type* Unk_23a13e8::vf_type() {
    return Unk_GetType();
}
