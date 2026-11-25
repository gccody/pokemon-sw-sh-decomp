// Scope: common
//
// The destructors of Unk_240c3e8 (vtable 0x710240c3f8), laid out like
// Unk_240c2d8 (Unk_105d610.cpp): an interface at 0 and gflib3's
// reference-counted object (src/gflib3/Unk_239a418.h) at +8. 0x710105c800
// makes one.
//
// And Unk_240c4e8 (vtable 0x710240c4f8): the object, then an interface at
// +0x60 (vtable 0x710240c5b8, without a destructor), 0x68 bytes. Its vf_type
// and vf7 are written by the generators (src/unsorted/types/Unk_105df10.cpp,
// src/unsorted/virtual/Unk_105c3e0.cpp).
#include "gflib3/Unk_239a418_Make.h"

// The interface at 0 (its own vtable: 0x710105c800 stores it before the
// object's constructor runs). Slot 2 is the type getter (written with its
// slot name, src/unsorted/types/Unk_105ce20.cpp: the object has a function of
// that name, so it isn't declared here; its thunks are in Unk_105d8f0.cpp).
class Unk_240c3e8_Interface {
public:
    virtual void vf0();
    virtual void vf1();
    virtual ~Unk_240c3e8_Interface() {}
};

class Unk_240c3e8 : public Unk_240c3e8_Interface, public Unk_239a418 {
public:
    void vf0() override;  // 0x710105d9b0
    void vf1() override;  // 0x710105d9c0
    ~Unk_240c3e8() override;
};
static_assert(sizeof(Unk_240c3e8) == 0x68, "Unk_240c3e8");

// 0x710105dac0, 0x710105db10 (D0), thunks 0x710105db60/0x710105dbb0 (+8),
// 0x710105dc00/0x710105dc50 (+0x50) and 0x710105dcc0/0x710105dd10 (+0x58)
Unk_240c3e8::~Unk_240c3e8() {}

// Not decompiled yet.
u32 Unk_15bbd30(const s32* value);
void Unk_104c140(u64 self, const u32& id);

// Globals other TUs define, named after their addresses.
extern u64 Unk_24ba150;

// The interface at +0x60 (vtable 0x710240c5b8): five slots
// (src/unsorted/virtual/Unk_105c3e0.cpp).
class Unk_240c5a8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
};

class Unk_240c4e8 : public Unk_239a418, public Unk_240c5a8 {
public:
    ~Unk_240c4e8() override;
    const Unk_239a418_Type* vf_type() override;  // 0x710105df10
    virtual void vf7();                          // 0x710105e000
    virtual void vf8(const s32* value);
};
static_assert(sizeof(Unk_240c4e8) == 0x68, "Unk_240c4e8");

// 0x710105dec0 (D0; its D2 is the object's), thunks 0x710105e050/0x710105e0a0
// (+0x48) and 0x710105e110/0x710105e160 (+0x50)
Unk_240c4e8::~Unk_240c4e8() {}

// 0x710105e010
// NON_MATCHING: the id's temporary is at sp+0xc, the original's at sp+8: the
// object Unk_104c140 takes is likely bigger or more aligned than a u32 (only
// its first word is read). Unk_104c140's name lacks its second parameter.
void Unk_240c4e8::vf8(const s32* value) {
    Unk_104c140(Unk_24ba150, Unk_15bbd30(value));
}

// What 0x710105bf40 makes its Unk_240c4e8 with: it passes a stack object
// that isn't otherwise used.
struct Unk_105dd60_Maker {
    Unk_240c4e8* Unk_Make(Unk_239a418_Allocator* allocator);
};

// 0x710105dd60
Unk_240c4e8* Unk_105dd60_Maker::Unk_Make(Unk_239a418_Allocator* allocator) {
    return Unk_Create<Unk_240c4e8>(allocator);
}
