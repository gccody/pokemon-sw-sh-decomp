// Scope: common
//
// The destructors of Unk_240c2d8 (vtable 0x710240c2e8): an interface at 0 and
// gflib3's reference-counted object (src/gflib3/Unk_239a418.h) at +8,
// 0x68 bytes in all (0x710105c670 makes one). Neither part has anything of
// its own to destroy, so the destructor only runs the object's: the vtable
// pointers of the class and of its interface aren't stored. Its thunks
// adjust by the object (+8) and the object's two interfaces (+0x50, +0x58).
//
// Its other slots (0x710105d5f0 to 0x710105d620) are written by the
// generators with their slot names (src/unsorted/virtual/Unk_105c3e0.cpp,
// src/unsorted/types/Unk_105ce20.cpp): slot 2 and the type getter in slot 3
// share their names with the object's functions, so they aren't declared here
// (the type getter's thunks are in Unk_105d8f0.cpp).
#include "gflib3/Unk_239a418.h"

// The interface at 0 (its own vtable: 0x710105c670 stores it before the
// object's constructor runs).
class Unk_240c2d8_Interface {
public:
    virtual void vf0();
    virtual void vf1();
    virtual ~Unk_240c2d8_Interface() {}
};

class Unk_240c2d8 : public Unk_240c2d8_Interface, public Unk_239a418 {
public:
    void vf0() override;  // 0x710105d5f0
    void vf1() override;  // 0x710105d600
    ~Unk_240c2d8() override;
};
static_assert(sizeof(Unk_240c2d8) == 0x68, "Unk_240c2d8");

// 0x710105d710, 0x710105d760 (D0), thunks 0x710105d7b0/0x710105d800 (+8),
// 0x710105d850/0x710105d8a0 (+0x50) and 0x710105d910/0x710105d960 (+0x58)
Unk_240c2d8::~Unk_240c2d8() {}
