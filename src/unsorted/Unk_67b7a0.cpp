// Scope: common
//
// Two interfaces: abstract classes with an empty virtual destructor and only
// pure virtual functions. Placeholder names: rename once the classes are
// identified. vfNN is the function's offset in the vtable.
//
// Their vtables (0x71023a0de8 and 0x71023a0e18, both games) have no typeinfo
// (-fno-rtti), the complete (D1) and deleting (D0) destructors, then
// __cxa_pure_virtual for every other slot. The deleting destructor of an
// abstract class can never be called, so clang emits it as a lone trap
// (`llvm.trap`): 0x710067b7b0 and 0x710067b7d0 are one trap word each
// (docs/compiler.md, "Traps").
#include <types.h>

class Unk_67b7a0 {
public:
    virtual ~Unk_67b7a0();
    virtual void vf10() = 0;
    virtual void vf18() = 0;
};
PKMN_SIZE_ASSERT(Unk_67b7a0, 0x8);

class Unk_67b7c0 {
public:
    virtual ~Unk_67b7c0();
    virtual void vf10() = 0;
    virtual void vf18() = 0;
    virtual void vf20() = 0;
    virtual void vf28() = 0;
    virtual void vf30() = 0;
    virtual void vf38() = 0;
};
PKMN_SIZE_ASSERT(Unk_67b7c0, 0x8);

// 0x710067b7a0 (D2, and D1 as its alias): a `ret`
// 0x710067b7b0 (D0): a trap
Unk_67b7a0::~Unk_67b7a0() {}

// 0x710067b7c0 (D2, and D1 as its alias): a `ret`
// 0x710067b7d0 (D0): a trap
Unk_67b7c0::~Unk_67b7c0() {}
