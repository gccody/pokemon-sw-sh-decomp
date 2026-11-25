// Scope: common
// A class of game/nesthole on gflib3's object (vtable 0x7102402240) that owns
// an object made from six references and steps it through three states: its
// constructor, destructors, type getter and the step. Its destructor is its
// key function: its vtables and thunks are emitted here. Placeholder names:
// rename once the class is known.
#include <memory>

#include <types.h>

#include "gflib3/Unk_239a418.h"
#include "unsorted/Unk_23f4660.h"
#include "unsorted/Unk_2771620.h"
#include "unsorted/nesthole/Unk_fa2190.h"

// The base of the owned object (vtable 0x71023c1530, as in
// src/unsorted/Unk_989900.cpp): its vf2 and vf3 return flags (their callers
// test bit 0).
class Unk_23c1530 {
public:
    explicit Unk_23c1530(u64 arg);
    virtual ~Unk_23c1530() {}
    virtual bool vf2();
    virtual bool vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();

    u64 field_8;
    Unk_239a418_Ref<Unk_239a418> field_10;
};
static_assert(sizeof(Unk_23c1530) == 0x18, "Unk_23c1530");

// The owned object (vtable 0x71024022f0), 0x50 bytes: the six references it
// was made from. The deleter destroys it through its vtable.
class Unk_24022e0 : public Unk_23c1530 {
public:
    Unk_24022e0(Unk_239a418_Allocator* allocator, const Unk_2402180_Refs& refs);  // 0x7100fa2d70
    ~Unk_24022e0() override;
    bool vf2() override;
    bool vf3() override;
    void vf5() override;

    Unk_2402180_Refs field_18;
    u64 field_48;
};
static_assert(sizeof(Unk_24022e0) == 0x50, "Unk_24022e0");
static_assert(__builtin_offsetof(Unk_24022e0, field_18) == 0x18, "Unk_24022e0::field_18");

// What the owned object is asked (0x71014d...), as in src/unsorted/Unk_989900.cpp.
void Unk_14dbf60(u64 object);
void Unk_14dbff0(u64 object);
void Unk_14dc050(u64 object);

class Unk_2402230 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    explicit Unk_2402230(const Unk_2402180_Refs& refs);
    ~Unk_2402230() override;
    const Unk_239a418_Type* vf_type() override { return Unk_GetType(); }

    bool Unk_fa2720();

    u64 Unk_Object68() const { return reinterpret_cast<u64>(field_68.get()); }
    void Unk_Start(u32 state) {
        field_64 = state;
        field_60 = true;
    }

    bool field_60;
    u32 field_64;
    std::unique_ptr<Unk_24022e0, Unk_23f4660_Deleter> field_68;
    bool field_88;
};
static_assert(sizeof(Unk_2402230) == 0x90, "Unk_2402230");
PKMN_OFFSET_ASSERT(Unk_2402230, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_2402230, field_64, 0x64);
PKMN_OFFSET_ASSERT(Unk_2402230, field_68, 0x68);
PKMN_OFFSET_ASSERT(Unk_2402230, field_88, 0x88);

// 0x7100fa25f0
Unk_2402230::Unk_2402230(const Unk_2402180_Refs& refs) : field_60(false), field_88(false) {
    Unk_239a418_Allocator* allocator = field_8;
    field_68 = Unk_2771620_MakeUnique<Unk_24022e0>(allocator, allocator, refs);
    Unk_Start(0);
}

// 0x7100fa2720
bool Unk_2402230::Unk_fa2720() {
    if (field_60) {
        switch (field_64) {
            case 0:
                Unk_14dbff0(Unk_Object68());
                if (field_68->vf2())
                    Unk_Start(1);
                break;
            case 1:
                Unk_14dbf60(Unk_Object68());
                Unk_14dbff0(Unk_Object68());
                Unk_14dc050(Unk_Object68());
                if (field_88)
                    Unk_Start(2);
                break;
            case 2:
                Unk_14dbff0(Unk_Object68());
                if (field_68->vf3())
                    field_60 = false;
                break;
        }
    }
    return field_60;
}

// 0x7100fa2800, 0x7100fa28a0 (D0), thunks 0x7100fa2a30/0x7100fa2ad0 (+0x48)
// and 0x7100fa2b90/0x7100fa2c30 (+0x50); vf_type's thunks 0x7100fa2b70 (+0x48)
// and 0x7100fa2b80 (+0x50) are emitted with them
Unk_2402230::~Unk_2402230() {}
