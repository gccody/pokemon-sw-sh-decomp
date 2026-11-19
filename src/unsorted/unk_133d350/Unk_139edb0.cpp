// Scope: common
//
// Four classes on gflib3's Unk_23994d8, two pairs with the same members: a
// reference and a mutex (vtables 0x71024336d0 and 0x7102433870), or a name
// and a mutex (vtables 0x7102433788 and 0x7102433928). Their destructors are
// their key functions: their vtables and thunks are emitted here. Placeholder
// names: rename once the classes are known.
#include <nn/os.h>

#include "gflib3/Unk_23994d8.h"
#include "unsorted/Unk_23f4660.h"

class Unk_24336d0 : public Unk_23994d8 {
public:
    ~Unk_24336d0() override;
    void vf8() override;

    u64 field_2e8;
    u64 field_2f0;
    u64 field_2f8;
    u64 field_300;
    u64 field_308;
    u64 field_310;
    u64 field_318;
    u64 field_320;
    u64 field_328;
    Unk_239a418_Ref<Unk_239a418> field_330;
    u8 _338[0x358 - 0x338];
    nn::os::Mutex field_358;
};
static_assert(sizeof(Unk_24336d0) == 0x378, "Unk_24336d0");
static_assert(__builtin_offsetof(Unk_24336d0, field_330) == 0x330, "Unk_24336d0::field_330");
static_assert(__builtin_offsetof(Unk_24336d0, field_358) == 0x358, "Unk_24336d0::field_358");

// 0x710139edb0, its D0 and thunks for +0x48 and +0x58
Unk_24336d0::~Unk_24336d0() {}

class Unk_2433788 : public Unk_23994d8 {
public:
    ~Unk_2433788() override;
    void vf8() override;

    u8 _2e8[0x308 - 0x2e8];
    Unk_23f4660_Name field_308;
    u8 _338[0x340 - 0x338];
    nn::os::Mutex field_340;
};
static_assert(sizeof(Unk_2433788) == 0x360, "Unk_2433788");
static_assert(__builtin_offsetof(Unk_2433788, field_308) == 0x308, "Unk_2433788::field_308");
static_assert(__builtin_offsetof(Unk_2433788, field_340) == 0x340, "Unk_2433788::field_340");

// 0x710139fa80, its D0 and thunks for +0x48 and +0x58
Unk_2433788::~Unk_2433788() {}

class Unk_2433870 : public Unk_23994d8 {
public:
    ~Unk_2433870() override;
    void vf8() override;

    u64 field_2e8;
    u64 field_2f0;
    u64 field_2f8;
    u64 field_300;
    u64 field_308;
    u64 field_310;
    u64 field_318;
    u64 field_320;
    u64 field_328;
    Unk_239a418_Ref<Unk_239a418> field_330;
    u8 _338[0x358 - 0x338];
    nn::os::Mutex field_358;
};
static_assert(sizeof(Unk_2433870) == 0x378, "Unk_2433870");

// 0x71013a0540, its D0 and thunks for +0x48 and +0x58
Unk_2433870::~Unk_2433870() {}

class Unk_2433928 : public Unk_23994d8 {
public:
    ~Unk_2433928() override;
    void vf8() override;

    u8 _2e8[0x308 - 0x2e8];
    Unk_23f4660_Name field_308;
    u8 _338[0x340 - 0x338];
    nn::os::Mutex field_340;
};
static_assert(sizeof(Unk_2433928) == 0x360, "Unk_2433928");

// 0x71013a0b20, its D0 and thunks for +0x48 and +0x58
Unk_2433928::~Unk_2433928() {}
