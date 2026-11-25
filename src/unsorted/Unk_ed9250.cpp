// Scope: common
//
// A class on gflib3's Unk_239c100 (vtable 0x71023f7af0, 0x288 bytes) that
// owns an object made from its allocator (Unk_23f7be8), which holds a class
// on Unk_239bb58 (Unk_23f7c08): their constructors, destructors and thunks,
// and the factories of two other classes on Unk_239c100. The classes'
// vtables are emitted here, with their destructors. Their type getters are
// tools/typegen.py's (src/unsorted/types/Unk_ed9a90.cpp and
// src/unsorted/types/Unk_ed2290.cpp). Placeholder names: rename once the
// classes are known.
#include <memory>
#include <utility>
#include <vector>

#include <nn/os.h>
#include <types.h>

#include "gflib3/Unk_239b8d8.h"
#include "gflib3/Unk_5cf870.h"
#include "gflib3/Unk_New.h"
#include "unsorted/Unk_2771620.h"
#include "unsorted/Unk_d0c0.h"

using Unk_Ref = Unk_239a418_Ref<Unk_239a418>;

// gflib3's class with vtable 0x710239c110, on Unk_239b8d8 (its constructor
// 0x7100608fa0, D2 0x7100609f30 and vf15 to vf17 are gflib3's, not written
// here): a vector of references, a light event and a reference. Its
// destructor is inline: the derived classes' destructors inline it.
class Unk_239c100 : public Unk_239b8d8 {
public:
    // A light event, finalized when it goes.
    struct LightEvent {
        ~LightEvent() { Unk_5cf8d0(&field_0); }

        nn::os::LightEventType field_0;
    };

    Unk_239c100(const Unk_5cfaf0_Name& name, u32 arg);
    ~Unk_239c100() override {}
    const Unk_239a418_Type* vf_type() override;
    void vf15() override;
    void vf16() override;
    virtual void vf17();

    std::vector<Unk_Ref, Unk_239a418_StdAllocator<Unk_Ref>> field_210;
    u64 field_230;
    u64 field_238;
    u32 field_240;
    LightEvent field_244;
    u64 field_250;
    u64 field_258;
    Unk_Ref field_260;
};
static_assert(sizeof(Unk_239c100) == 0x268, "Unk_239c100");
PKMN_OFFSET_ASSERT(Unk_239c100, field_210, 0x210);
PKMN_OFFSET_ASSERT(Unk_239c100, field_244, 0x244);
PKMN_OFFSET_ASSERT(Unk_239c100, field_260, 0x260);

// Two other classes on Unk_239c100, made here (their constructors,
// 0x7100ed1cd0 and 0x7100eeb420, and their destructors aren't written here).
class Unk_23f7780 : public Unk_239c100 {
public:
    Unk_23f7780();
    ~Unk_23f7780() override;

    u8 field_268[0x10];
};
static_assert(sizeof(Unk_23f7780) == 0x278, "Unk_23f7780");

class Unk_23f8680 : public Unk_239c100 {
public:
    Unk_23f8680();
    ~Unk_23f8680() override;

    u64 field_268;
};
static_assert(sizeof(Unk_23f8680) == 0x270, "Unk_23f8680");

// 0x7100ed9250
// NON_MATCHING: the original's TU defines Unk_23f7780's constructor
// (0x7100ed1cd0, not inlined), so LLVM's call-site splitting splits its call
// on the null test (one call with a null pointer); it skips a callee that's
// only declared, as here.
template Unk_23f7780* Unk_New::Create<Unk_23f7780>(Unk_239a418_Allocator*);

// 0x7100ed9330
// NON_MATCHING: as Unk_New::Create<Unk_23f7780>: Unk_23f8680's constructor
// (0x7100eeb420) isn't defined here.
template Unk_23f8680* Unk_New::Create<Unk_23f8680>(Unk_239a418_Allocator*);

// A member function to call and the object to call it on.
struct Unk_ed9410_Call {
    Unk_239a418* m_object;
    void (Unk_239a418::*m_method)(void* arg);
};
static_assert(sizeof(Unk_ed9410_Call) == 0x18, "Unk_ed9410_Call");

// 0x7100ed9410: the call, with its argument.
void Unk_ed9410(const Unk_ed9410_Call* self, void* arg) {
    (self->m_object->*self->m_method)(arg);
}

// Fourteen references and a word, with an out-of-line destructor
// (0x7100ed9480).
struct Unk_ed9480 {
    ~Unk_ed9480();

    Unk_Ref field_0[13];
    u64 field_68;
    Unk_Ref field_70;
};
PKMN_OFFSET_ASSERT(Unk_ed9480, field_70, 0x70);

// 0x7100ed9480
Unk_ed9480::~Unk_ed9480() {}

class Unk_23f7ae0;

// Assigns by copy and swap: the old reference goes with the copy.
template <class T>
void Unk_CopyAssign(Unk_239a418_Ref<T>& to, Unk_239a418_Ref<T> from) {
    std::swap(to.m_ptr, from.m_ptr);
}

// A class on Unk_239bb58 (vtable 0x71023f7c18), made by Unk_23f7be8 with
// Unk_New::Create (0x7100ed9dc0, instantiated by Unk_23f7be8's constructor).
// NON_MATCHING (0x7100ed9dc0): its constructor is inline there, and calls
// Unk_239bb58's (0x7100600a30, with 0 and true), which
// src/gflib3/Unk_239bb58.h doesn't declare; it then sets the base's name at
// +0x80 (Unk_23f7ac8), which the header declares as separate fields. Here it
// gets the implicit constructor.
class Unk_23f7c08 : public Unk_239bb58 {
public:
    ~Unk_23f7c08() override;
    const Unk_239a418_Type* vf_type() override;
    void vf7() override;

    void Unk_SetB0(Unk_Ref ref) { Unk_CopyAssign(field_b0, ref); }

    u64 field_a0;
    u64 field_a8;
    Unk_Ref field_b0;
    Unk_Ref field_b8;
};
static_assert(sizeof(Unk_23f7c08) == 0xc0, "Unk_23f7c08");
PKMN_OFFSET_ASSERT(Unk_23f7c08, field_b0, 0xb0);
PKMN_OFFSET_ASSERT(Unk_23f7c08, field_b8, 0xb8);

// The object Unk_23f7ae0 owns (vtable 0x71023f7bf8): its owner and the
// Unk_23f7c08 it makes, which it hands to its owner. The deleter destroys it
// directly (final). Its constructor is inline (in 0x7100ed9770).
class Unk_23f7be8 final {
public:
    Unk_23f7be8(Unk_23f7ae0* owner, Unk_239a418_Allocator* allocator);
    virtual ~Unk_23f7be8();

    void Unk_SetB0(Unk_Ref ref) { field_10.m_ptr->Unk_SetB0(ref); }

    Unk_23f7ae0* field_8;
    Unk_239a418_Ref<Unk_23f7c08> field_10;
};
static_assert(sizeof(Unk_23f7be8) == 0x18, "Unk_23f7be8");

class Unk_23f7ae0 final : public Unk_239c100 {
public:
    explicit Unk_23f7ae0(Unk_239a418_Allocator* allocator);
    ~Unk_23f7ae0() override;

    void Unk_ed9880(const Unk_Ref& ref);

    std::unique_ptr<Unk_23f7be8, Unk_23f4660_Deleter> field_268;
};
static_assert(sizeof(Unk_23f7ae0) == 0x288, "Unk_23f7ae0");
PKMN_OFFSET_ASSERT(Unk_23f7ae0, field_268, 0x268);

// The name Unk_23f7ae0 and Unk_23f7c08 are made with (0x71023f7ac8).
extern const Unk_5cfad0_Literal Unk_23f7ac8;

// 0x7100ed95f0
Unk_23f7ae0::Unk_23f7ae0(Unk_239a418_Allocator* allocator)
    : Unk_239c100(Unk_23f7ac8.Unk_5cfad0(), 2) {
    field_268 = Unk_2771620_MakeUnique<Unk_23f7be8>(allocator, this, allocator);
}

// Inline: in 0x7100ed9770, Unk_2771620_MakeUnique<Unk_23f7be8>.
// NON_MATCHING (0x7100ed9770): Unk_239c100's vf15 (0x71006091a0) takes the
// object made here, but src/gflib3/Unk_239b8d8.h declares it without a
// parameter.
inline Unk_23f7be8::Unk_23f7be8(Unk_23f7ae0* owner, Unk_239a418_Allocator* allocator)
    : field_8(owner) {
    field_10 = Unk_239a418_Ref<Unk_23f7c08>(Unk_New().Create<Unk_23f7c08>(allocator));
    field_8->vf15();
}

// 0x7100ed9880
void Unk_23f7ae0::Unk_ed9880(const Unk_Ref& ref) {
    field_268->Unk_SetB0(ref);
}

// 0x7100ed9940 (D2), 0x7100ed9a80 (D0), its thunks for +0x48 (0x7100ed9b00
// D2, 0x7100ed9b10 D0) and +0x50 (0x7100ed9d00 D2, 0x7100ed9d10 D0)
Unk_23f7ae0::~Unk_23f7ae0() {}

// 0x7100ed9d20 (D2), 0x7100ed9d70 (D0)
Unk_23f7be8::~Unk_23f7be8() {}

// 0x7100ed9f20 (D2), 0x7100ed9f90 (D0), its thunks for +0x48 (0x7100eda0e0
// D2, 0x7100eda150 D0) and +0x50 (0x7100eda2a0 D2, 0x7100eda310 D0)
Unk_23f7c08::~Unk_23f7c08() {}
