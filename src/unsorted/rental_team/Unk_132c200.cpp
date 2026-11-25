// Scope: common
// A class of game/rental_team on gflib3's object (vtable 0x71024308b8) that
// holds four references: its constructor, destructors and the accessors of
// the references. Its destructor is its key function: its vtables are emitted
// here (vf_type and its thunks are in src/unsorted/types/Unk_132c510.cpp).
// Placeholder names: rename once the class is known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// Its base (vtable 0x71024a8668's group), as in src/unsorted/Unk_23f43c8.h,
// with its constructor.
class Unk_23f4318 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    Unk_23f4318();  // 0x7100e7c210
    ~Unk_23f4318() override;
    const Unk_239a418_Type* vf_type() override { return Unk_GetType(); }
};
static_assert(sizeof(Unk_23f4318) == 0x60, "Unk_23f4318");

// The four references Unk_24308a8::Unk_132c250 takes.
struct Unk_132c250_Refs {
    Unk_239a418_Ref<Unk_239a418> field_0;
    Unk_239a418_Ref<Unk_239a418> field_8;
    Unk_239a418_Ref<Unk_239a418> field_10;
    Unk_239a418_Ref<Unk_239a418> field_18;
};
static_assert(sizeof(Unk_132c250_Refs) == 0x20, "Unk_132c250_Refs");

class Unk_24308a8 : public Unk_23f4318 {
public:
    Unk_24308a8();
    ~Unk_24308a8() override;
    const Unk_239a418_Type* vf_type() override;

    void Unk_132c250(const Unk_132c250_Refs& refs);
    Unk_239a418_Ref<Unk_239a418> Unk_132c350() const;
    Unk_239a418_Ref<Unk_239a418> Unk_132c370() const;
    Unk_239a418_Ref<Unk_239a418> Unk_132c390() const;
    Unk_239a418_Ref<Unk_239a418> Unk_132c3b0() const;

    Unk_239a418_Ref<Unk_239a418> field_60;
    Unk_239a418_Ref<Unk_239a418> field_68;
    Unk_239a418_Ref<Unk_239a418> field_70;
    Unk_239a418_Ref<Unk_239a418> field_78;
};
static_assert(sizeof(Unk_24308a8) == 0x80, "Unk_24308a8");
static_assert(__builtin_offsetof(Unk_24308a8, field_60) == 0x60, "Unk_24308a8::field_60");

namespace {

// `to` becomes a copy of `from`.
template <class T>
void Unk_Copy(Unk_239a418_Ref<T>& to, const Unk_239a418_Ref<T>& from) {
    Unk_239a418_Ref<T> copy(from);
    T* old = to.m_ptr;
    to.m_ptr = copy.m_ptr;
    copy.m_ptr = old;
}

}  // namespace

// 0x710132c200
Unk_24308a8::Unk_24308a8() {}

// 0x710132c3d0, 0x710132c470 (D0), thunks 0x710132c520/0x710132c5c0 (+0x48)
// and 0x710132c680/0x710132c720 (+0x50)
Unk_24308a8::~Unk_24308a8() {}

// 0x710132c250
void Unk_24308a8::Unk_132c250(const Unk_132c250_Refs& refs) {
    Unk_Copy(field_60, refs.field_0);
    Unk_Copy(field_68, refs.field_8);
    Unk_Copy(field_70, refs.field_10);
    Unk_Copy(field_78, refs.field_18);
}

// 0x710132c350
Unk_239a418_Ref<Unk_239a418> Unk_24308a8::Unk_132c350() const {
    return field_60;
}

// 0x710132c370
Unk_239a418_Ref<Unk_239a418> Unk_24308a8::Unk_132c370() const {
    return field_68;
}

// 0x710132c390
Unk_239a418_Ref<Unk_239a418> Unk_24308a8::Unk_132c390() const {
    return field_70;
}

// 0x710132c3b0
Unk_239a418_Ref<Unk_239a418> Unk_24308a8::Unk_132c3b0() const {
    return field_78;
}
