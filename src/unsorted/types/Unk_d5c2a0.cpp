// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027efd90: its getter is out of line.
struct Unk_23dd820 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027efd80.
struct Unk_23e4758 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23dd820::Unk_GetType());
        return &type;
    }
};

// The type 0x71027effd0.
struct Unk_27effd0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// 0x71013cc840: the copy of its getter that the getters below call (too big
// to be inlined into them: clang emits it here).
// The type 0x71027effc0.
struct Unk_27effc0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27effd0::Unk_GetType());
        return &type;
    }
};

// The type 0x71027dbb20.
struct Unk_23e8d60 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27effc0::Unk_GetType());
        return &type;
    }
};

// vtable 0x71023ec030: vf_type and its thunks 0x7100d5c380 (+0x48), 0x7100d5c430 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23ec020 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23e4758::Unk_GetType());
        return &type;
    }

    ~Unk_23ec020() override;
    const Unk_239a418_Type* vf_type() override;
};

// The type 0x71027dce28.
struct Unk_23ec308 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23e8d60::Unk_GetType());
        return &type;
    }
};

// 0x7100d5c2a0
// 0x7100d5c380
// 0x7100d5c430
const Unk_239a418_Type* Unk_23ec020::vf_type() {
    return Unk_GetType();
}

// Whether an object's type is the template argument or one derived from it,
// through the object's +0x50 interface.
template <class T>
bool Unk_61a530(Unk_239a498* object) {
    const Unk_239a418_Type* type = object->vf_type();
    const Unk_239a418_Type* kind = T::Unk_GetType();
    for (; type != nullptr; type = type->field_0)
        if (type == kind)
            return true;
    return false;
}

// 0x7100d5c8e0
template bool Unk_61a530<Unk_23ec308>(Unk_239a498* object);
