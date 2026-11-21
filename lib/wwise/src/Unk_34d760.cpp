// Scope: common
// The class derived from the node class with two sets of children (vtables at
// 0x710237fbc0): its destructors, its creation and its kind. The executable
// has the functions of Unk_NodeParent<Unk_2382098> here. Placeholder names.
#include "Unk_237ff98.h"
#include "Unk_NodeParentImpl.h"

class Unk_237fbc0 : public Unk_237ff98 {
public:
    explicit Unk_237fbc0(u32 id) : Unk_237ff98(id) {}
    ~Unk_237fbc0() override;

    u32 vf17() override { return 10; }  // 0x710034d860
};
PKMN_SIZE_ASSERT(Unk_237fbc0, 0x168);

// The destructor (the base's), its copy for the vtable at 0x18, and the
// deleting one:
// 0x710034d760 (_ZN11Unk_237fbc0D2Ev)
// 0x710034d770 (_ZThn24_N11Unk_237fbc0D1Ev)
// 0x710034d780 (_ZN11Unk_237fbc0D0Ev)
// 0x710034d7b0 (_ZThn24_N11Unk_237fbc0D0Ev)
Unk_237fbc0::~Unk_237fbc0() {}

struct Unk_347550_Obj;

// 0x710034d7e0
Unk_347550_Obj* Unk_34d7e0(u32 id) {
    Unk_237fbc0* node = new (Unk_237e820) Unk_237fbc0(id);
    if (node != nullptr)
        node->Register();
    return reinterpret_cast<Unk_347550_Obj*>(node);
}
