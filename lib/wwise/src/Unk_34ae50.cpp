// Scope: common
// The node class with children and nothing else (vtables at 0x710237f528, 0xc8
// bytes): its creation and its destructors (the base's, inline) with their
// copies for the vtable at 0x18. With it come the functions of its base,
// Unk_NodeParent<Unk_2381d78>, and the inline virtual functions of the classes
// below that (Unk_NodeParentImpl.h). Placeholder names.
#include "Unk_NodeParentImpl.h"

class Unk_237f528 : public Unk_NodeActiveParent<Unk_237f858> {
public:
    explicit Unk_237f528(u32 id) : Unk_NodeActiveParent<Unk_237f858>(id) {}

    // The destructors (the base's is inline in them), and their copies for
    // the vtable at 0x18:
    // 0x710034ae50 (_ZN11Unk_237f528D2Ev)
    // 0x710034af30 (_ZN11Unk_237f528D0Ev)
    // 0x710034aec0 (_ZThn24_N11Unk_237f528D1Ev)
    // 0x710034afa0 (_ZThn24_N11Unk_237f528D0Ev)
    ~Unk_237f528() override;
    // The base's own vtables have its destructor, and a trap for the
    // deleting one (the class is abstract):
    // 0x710034c220 (_ZN14Unk_NodeParentI11Unk_2381d78ED2Ev)
    // 0x710034c290 (_ZN14Unk_NodeParentI11Unk_2381d78ED0Ev)
    // 0x710034c2b0 (_ZThn24_N14Unk_NodeParentI11Unk_2381d78ED1Ev)
    // 0x710034c320 (_ZThn24_N14Unk_NodeParentI11Unk_2381d78ED0Ev)
    // The base's virtual functions:
    // 0x710034b270 (_ZN14Unk_NodeParentI11Unk_2381d78E4vf10EP11Unk_2382098)
    // 0x710034b560 (_ZN14Unk_NodeParentI11Unk_2381d78E4vf15EPjP15Unk_NodeEntry15S2_j)
    // 0x710034b660 (_ZN14Unk_NodeParentI11Unk_2381d78E4vf16EPvS2_S2_bS2_jj)
    // 0x710034b720 (_ZN20Unk_NodeActiveParentI14Unk_NodeParentI11Unk_2381d78EE4vf19EP13Unk_NodeArg19)
    // 0x710034b890 (_ZN20Unk_NodeActiveParentI14Unk_NodeParentI11Unk_2381d78EE4vf22EPvS4_j)
    // 0x710034b910 (_ZN20Unk_NodeActiveParentI14Unk_NodeParentI11Unk_2381d78EE4vf23EP13Unk_NodeArg23)
    // 0x710034b9c0 (_ZN20Unk_NodeActiveParentI14Unk_NodeParentI11Unk_2381d78EE4vf25EPvbf)
    // 0x710034bac0 (_ZN20Unk_NodeActiveParentI14Unk_NodeParentI11Unk_2381d78EE4vf26EfPvS4_b)
    // 0x710034bb70 (_ZN20Unk_NodeActiveParentI14Unk_NodeParentI11Unk_2381d78EE4vf27EfjPvS4_)
    // 0x710034bc50 (_ZN20Unk_NodeActiveParentI14Unk_NodeParentI11Unk_2381d78EE4vf29Ev)
    // 0x710034bcc0 (_ZN20Unk_NodeActiveParentI14Unk_NodeParentI11Unk_2381d78EE4vf30EPvS4_S4_)
    // 0x710034bd60 (_ZN20Unk_NodeActiveParentI14Unk_NodeParentI11Unk_2381d78EE4vf31EjjPvS4_)
    // 0x710034be20 (_ZN20Unk_NodeActiveParentI14Unk_NodeParentI11Unk_2381d78EE4vf34Ej)
    // 0x710034bea0 (_ZN20Unk_NodeActiveParentI14Unk_NodeParentI11Unk_2381d78EE4vf39Ev)
    // 0x710034bf40 (_ZN20Unk_NodeActiveParentI14Unk_NodeParentI11Unk_2381d78EE4vf40Ev)
    // 0x710034bf90 (_ZN20Unk_NodeActiveParentI14Unk_NodeParentI11Unk_2381d78EE4vf48Eb)
    // The inline virtual functions of the classes below it:
    // 0x710034b310 (_ZN11Unk_23820984vf11E10Unk_NodeId)
    // 0x710034c040 (_ZN11Unk_2381d784vf61Ej)
    // 0x710034c0e0 (_ZN11Unk_2381d784vf62Ej)
    // 0x710034c1a0 (_ZN11Unk_2381d784vf73Ej)
    // And the base at 0x18's inline slot 7:
    // 0x710034c1f0 (_ZN9Unk_NodeB5b_vf7Ev)

    u32 vf17() override { return 1; }
    u32 p_vf1(Unk_2382098* child) override;
};
PKMN_SIZE_ASSERT(Unk_237f528, 0xc8);

struct Unk_3476d0_Obj;

Unk_237f528::~Unk_237f528() {}

// 0x710034b010
Unk_3476d0_Obj* Unk_34b010(u32 id) {
    Unk_237f528* node = new (Unk_237e820) Unk_237f528(id);
    if (node != nullptr)
        node->Register();
    return reinterpret_cast<Unk_3476d0_Obj*>(node);
}

// NON_MATCHING: matches when built with clang 5.0.2. LLVM 6's LICM clones the search's item
// address (a GEP that is free in the loop) into the exit block, where the original tests the
// one the loop computed
// 0x710034b0a0 (_ZN11Unk_237f5285p_vf1EP11Unk_2382098)
u32 Unk_237f528::p_vf1(Unk_2382098* child) {
    if (child->field_78 != nullptr)
        return 0x15;
    if (children.Exists(child->field_10) != nullptr)
        return 5;
    if (field_10 == child->field_10)
        return 0x17;
    return 1;
}

// Slot 20 of Unk_NodeParent<Unk_2381d78>, under the name another file calls it by.
struct Unk_363570_T;
struct Unk_3643f0_Action;

// 0x710034b7c0
void Unk_34b7c0(Unk_363570_T* self, Unk_3643f0_Action* action) {
    reinterpret_cast<Unk_NodeActiveParent<Unk_237f858>*>(self)->Vf20(
        reinterpret_cast<Unk_NodeArg19*>(action));
}
