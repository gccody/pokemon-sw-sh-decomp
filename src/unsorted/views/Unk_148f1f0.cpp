// Scope: common
// The lookup of a view by name as a Unk_2441dc0 (contents/common/views.inl), with the type
// getters it inlines. Written by tools/viewgen.py: regenerate, don't edit. Placeholder
// classes, named after their vtables or type objects: rename them once they're known.
#include <vector>

#include <types.h>

#include "contents/common/cast.h"
#include "gflib3/Unk_239a418.h"
#include "unsorted/Unk_d0c0.h"

// The views (src/unsorted/Unk_23f4660.h): what the lookup reads of them.
class Unk_23f4660 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType();

    u8 _60[0x5c0 - 0x60];
    Unk_d0c0_String field_5c0;
};

// An app's frame's views (contents/common/framework.h).
class Unk_a7bb80_Views {
public:
    template <class T>
    T* Unk_a7bb80(const Unk_5cfaf0_Name& name);

    u8 _0[0x78];
    std::vector<Unk_23f4660*> field_78;
};

#include "contents/common/views.inl"

// The type 0x71027f1370 (its getter inlined).
class Unk_2441dc0 : public Unk_23f4660 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4660::Unk_GetType());
        return &type;
    }
};

// 0x710148f1f0
template Unk_2441dc0* Unk_a7bb80_Views::Unk_a7bb80<Unk_2441dc0>(const Unk_5cfaf0_Name& name);
