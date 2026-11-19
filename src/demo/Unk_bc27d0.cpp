// Scope: common
// The demo player's commands (bin/demo/..., bin/archive/demo/%s.gfpak: the strings of this
// TU, Sword 0x7100bba3d0-0x7100c23050) are classes on Unk_23d4470. 0x7100bc27d0 makes one
// from its description: a switch on the description's hash (96 cases, none of their names
// in the executable) picks the class, and a Creator<T> allocates and constructs it. Most
// classes are declared by tools/vtables.py in src/unsorted/virtual/Unk_bbbff0.cpp, with
// the virtual functions it writes; here they are declared again with the members their
// constructors set (they inherit Unk_23d4470's constructor, so the owner the Creator moves
// into it outlives the whole construction). Placeholder names: rename once the classes are
// known.
#include <types.h>

#include <arm_neon.h>
#include <new>
#include <unordered_map>
#include <utility>

#include "unsorted/Unk_23d4470.h"
#include "unsorted/Unk_23f2df0.h"
#include "unsorted/Unk_23f4660.h"
#include "unsorted/Unk_2771620.h"

// Allocates a T from `allocator` with the allocator current, constructs it and records
// the allocation in it (Unk_239a418_Base's field_8..field_20), the way an object frees
// itself (vf3). The object operator() belongs to is empty: the switch passes a stack
// address it never reads.
template <class T>
struct Unk_bc27d0_Creator {
    T* operator()(Unk_239a418_Allocator* allocator,
                  Unk_239a418_Ref<Unk_239a418_Handle>&& owner,
                  const Unk_23d4470_Desc& desc) const {
        Unk_2771620_Scope scope(allocator);
        void* p = allocator->vf2(sizeof(T), alignof(T));
        if (p == nullptr)
            allocator->vf23();
        T* command = new (p) T(std::move(owner), desc);
        command->field_8 = allocator;
        command->field_10 = reinterpret_cast<u64>(command);
        command->field_18 = sizeof(T);
        command->field_20 = alignof(T);
        return command;
    }
};

// A base of commands with timing fields (field_368 starts at -1) and a reference. It has no
// vtable of its own in the executable (abstract, its constructor always inlined), so it is
// named after vf9 (0x7100c02310), the first virtual function it adds; vf12 and vf13
// (0x7100c02330, 0x7100c02340) return field_378 and field_379.
class Unk_c02310 : public Unk_23d4470 {
public:
    using Unk_23d4470::Unk_23d4470;

    virtual Unk_239a418_Ref<Unk_239a418> vf9();
    virtual void vf10();
    virtual void vf11();
    virtual bool vf12();
    virtual bool vf13();

    u64 field_348 = 0;
    u64 field_350 = 0;
    u64 field_358 = 0;
    u64 field_360 = 0;
    s32 field_368 = -1;
    u32 field_36c = 1;
    Unk_239a418_Ref<Unk_239a418> field_370;
    bool field_378 = false;
    bool field_379 = false;
    u8 field_37a = 0;
    u8 field_37b = 0;
    u8 field_37c = 0;
};
PKMN_OFFSET_ASSERT(Unk_c02310, field_368, 0x368);
PKMN_OFFSET_ASSERT(Unk_c02310, field_370, 0x370);
PKMN_OFFSET_ASSERT(Unk_c02310, field_37c, 0x37c);

// A text of up to 0x80 characters and its name: vf7 of Unk_23d7950 (0x7100bfe1b0) reads
// the text, then hashes it (64-bit FNV-1a) into field_80 with its length, and drops the
// reference.
struct Unk_23d4470_Name {
    u64 field_0 = 0xcbf29ce484222645;  // the hash of ""
    const char* field_8 = "";
    u64 field_10 = 0;
    Unk_239a418_Ref<Unk_239a418> field_18;
};
static_assert(sizeof(Unk_23d4470_Name) == 0x20, "Unk_23d4470_Name");

struct Unk_23d4470_Text {
    char field_0[0x80];
    Unk_23d4470_Name field_80;
};
static_assert(sizeof(Unk_23d4470_Text) == 0xa0, "Unk_23d4470_Text");

// 0x71007910a0, out of line (called from several TUs): zeroes field_0..field_e and field_10.
struct Unk_7910a0 {
    Unk_7910a0();

    u64 field_0;
    u8 field_8[0x7];
    u32 field_10;
};
static_assert(sizeof(Unk_7910a0) == 0x18, "Unk_7910a0");

// Two callables and a reference, Unk_23dba98's shape (src/unsorted/Unk_23f2df0.h), each
// named after its vtable. The classes the commands hold are on them without functions of
// their own (the same slots), so their vptrs are stored after the members.
class Unk_23c1460 {
public:
    virtual void vf0();
    virtual void vf1();

    Unk_239a418_Ref<Unk_239a418> field_8;
    Unk_23d4470_Callable field_10;
    Unk_23d4470_Callable field_90;
};
static_assert(sizeof(Unk_23c1460) == 0x110, "Unk_23c1460");

class Unk_236d3d8 {
public:
    virtual void vf0();
    virtual void vf1();

    Unk_239a418_Ref<Unk_239a418> field_8;
    Unk_23d4470_Callable field_10;
    Unk_23d4470_Callable field_90;
};
static_assert(sizeof(Unk_236d3d8) == 0x110, "Unk_236d3d8");

class Unk_23c1f90 {
public:
    virtual void vf0();
    virtual void vf1();

    Unk_239a418_Ref<Unk_239a418> field_8;
    Unk_23d4470_Callable field_10;
    Unk_23d4470_Callable field_90;
};
static_assert(sizeof(Unk_23c1f90) == 0x110, "Unk_23c1f90");

class Unk_23d95b0 {
public:
    virtual void vf0();
    virtual void vf1();

    Unk_239a418_Ref<Unk_239a418> field_8;
    Unk_23d4470_Callable field_10;
    Unk_23d4470_Callable field_90;
};
static_assert(sizeof(Unk_23d95b0) == 0x110, "Unk_23d95b0");

class Unk_23c1440 : public Unk_23c1460 {};
class Unk_23c1480 : public Unk_236d3d8 {};
class Unk_23c2620 : public Unk_236d3d8 {};
class Unk_23d4c18 : public Unk_236d3d8 {};
class Unk_23983c0 : public Unk_23c1f90 {};
class Unk_23d4b30 : public Unk_23d95b0 {};

class Unk_23c4708 {
public:
    virtual void vf0();
    virtual void vf1();

    Unk_239a418_Ref<Unk_239a418> field_8;
    Unk_23d4470_Callable field_10;
    Unk_23d4470_Callable field_90;
};
static_assert(sizeof(Unk_23c4708) == 0x110, "Unk_23c4708");

class Unk_23c46e8 : public Unk_236d3d8 {};
class Unk_23c4840 : public Unk_23c4708 {};

// A map whose allocators take the allocator current when the map is made (two TLS
// lookups: the buckets' and the nodes'). What it maps isn't known.
using Unk_23d4470_Map = std::unordered_map<u64,
                                           u64,
                                           std::hash<u64>,
                                           std::equal_to<u64>,
                                           Unk_2771620_Allocator<std::pair<const u64, u64>>>;
static_assert(sizeof(Unk_23d4470_Map) == 0x58, "Unk_23d4470_Map");

// Unk_23c14a0's base: it has no vtable of its own in the executable, so it is named after
// its vf0 (0x7100967200, which Unk_23c14a0 and Unk_23c14c0 share).
class Unk_967200 {
public:
    virtual void vf0();
    virtual void vf1();

    Unk_239a418_Ref<Unk_239a418> field_8;
    Unk_23d4470_Callable field_10;
    Unk_23d4470_Callable field_90;
};
static_assert(sizeof(Unk_967200) == 0x110, "Unk_967200");

class Unk_23c14a0 : public Unk_967200 {};

// Created by 0x7100bc8af0
class Unk_23d6a30 : public Unk_23d4470 {
public:
    using Unk_23d4470::Unk_23d4470;
    const Unk_239a418_Type* vf_type() override;
    Unk_23f4660_Name field_348;
    u64 field_378 = 0;
    Unk_23c1440 field_380;
    u64 field_490 = 0;
    u8 field_498 = 0;
    u8 field_499 = 0;
    u8 field_49a = 0;
    u32 field_49c = 1;
    Unk_23c1480 field_4a0;
    u8 field_5b0 = 0;
};
static_assert(sizeof(Unk_23d6a30) == 0x5c0, "Unk_23d6a30");
PKMN_OFFSET_ASSERT(Unk_23d6a30, field_348, 0x348);
PKMN_OFFSET_ASSERT(Unk_23d6a30, field_378, 0x378);
PKMN_OFFSET_ASSERT(Unk_23d6a30, field_380, 0x380);
PKMN_OFFSET_ASSERT(Unk_23d6a30, field_490, 0x490);
PKMN_OFFSET_ASSERT(Unk_23d6a30, field_498, 0x498);
PKMN_OFFSET_ASSERT(Unk_23d6a30, field_499, 0x499);
PKMN_OFFSET_ASSERT(Unk_23d6a30, field_49a, 0x49a);
PKMN_OFFSET_ASSERT(Unk_23d6a30, field_49c, 0x49c);
PKMN_OFFSET_ASSERT(Unk_23d6a30, field_4a0, 0x4a0);
PKMN_OFFSET_ASSERT(Unk_23d6a30, field_5b0, 0x5b0);

// Created by 0x7100bc8cb0
class Unk_23d7e00 : public Unk_23d4470 {
public:
    using Unk_23d4470::Unk_23d4470;

    const Unk_239a418_Type* vf_type() override;
    virtual Unk_239a418_Ref<Unk_239a418> vf9();
    virtual void vf10();
    virtual void vf11();
    virtual bool vf12();
    virtual bool vf13();

    u64 field_348 = 0;
    u64 field_350 = 0;
    u64 field_358 = 0;
    u64 field_360 = 0;
    s32 field_368 = -1;
    u32 field_36c = 1;
    Unk_239a418_Ref<Unk_239a418> field_370;
    bool field_378 = false;
    bool field_379 = false;
    u8 field_37a = 0;
    u8 field_37b = 0;
    u8 field_37c = 0;
};
static_assert(sizeof(Unk_23d7e00) == 0x380, "Unk_23d7e00");
PKMN_OFFSET_ASSERT(Unk_23d7e00, field_348, 0x348);
PKMN_OFFSET_ASSERT(Unk_23d7e00, field_350, 0x350);
PKMN_OFFSET_ASSERT(Unk_23d7e00, field_358, 0x358);
PKMN_OFFSET_ASSERT(Unk_23d7e00, field_360, 0x360);
PKMN_OFFSET_ASSERT(Unk_23d7e00, field_368, 0x368);
PKMN_OFFSET_ASSERT(Unk_23d7e00, field_36c, 0x36c);
PKMN_OFFSET_ASSERT(Unk_23d7e00, field_370, 0x370);
PKMN_OFFSET_ASSERT(Unk_23d7e00, field_378, 0x378);
PKMN_OFFSET_ASSERT(Unk_23d7e00, field_379, 0x379);
PKMN_OFFSET_ASSERT(Unk_23d7e00, field_37a, 0x37a);
PKMN_OFFSET_ASSERT(Unk_23d7e00, field_37b, 0x37b);
PKMN_OFFSET_ASSERT(Unk_23d7e00, field_37c, 0x37c);

// Created by 0x7100bc8de0
class Unk_23d8e98 : public Unk_c02310 {
public:
    using Unk_c02310::Unk_c02310;

    const Unk_239a418_Type* vf_type() override;

    u32 field_380 = 0;
    u16 field_384 = 0;
    u32 field_388 = 0;
    u16 field_38c = 0;
    u64 field_390 = 0;
    s32 field_398 = -1;
    u32 field_39c = 0;
    u32 field_3a0 = 0;
    s32 field_3a4 = -100;
    s32 field_3a8 = -100;
    u32 field_3ac = 0;
};
static_assert(sizeof(Unk_23d8e98) == 0x3b0, "Unk_23d8e98");
PKMN_OFFSET_ASSERT(Unk_23d8e98, field_380, 0x380);
PKMN_OFFSET_ASSERT(Unk_23d8e98, field_384, 0x384);
PKMN_OFFSET_ASSERT(Unk_23d8e98, field_388, 0x388);
PKMN_OFFSET_ASSERT(Unk_23d8e98, field_38c, 0x38c);
PKMN_OFFSET_ASSERT(Unk_23d8e98, field_390, 0x390);
PKMN_OFFSET_ASSERT(Unk_23d8e98, field_398, 0x398);
PKMN_OFFSET_ASSERT(Unk_23d8e98, field_39c, 0x39c);
PKMN_OFFSET_ASSERT(Unk_23d8e98, field_3a0, 0x3a0);
PKMN_OFFSET_ASSERT(Unk_23d8e98, field_3a4, 0x3a4);
PKMN_OFFSET_ASSERT(Unk_23d8e98, field_3a8, 0x3a8);
PKMN_OFFSET_ASSERT(Unk_23d8e98, field_3ac, 0x3ac);

// Created by 0x7100bc8f40
class Unk_23d8db0 : public Unk_c02310 {
public:
    using Unk_c02310::Unk_c02310;

    const Unk_239a418_Type* vf_type() override;

    u32 field_380 = 0;
    s32 field_384 = -100;
    s32 field_388 = -100;
    u32 field_38c = 0;
};
static_assert(sizeof(Unk_23d8db0) == 0x390, "Unk_23d8db0");
PKMN_OFFSET_ASSERT(Unk_23d8db0, field_380, 0x380);
PKMN_OFFSET_ASSERT(Unk_23d8db0, field_384, 0x384);
PKMN_OFFSET_ASSERT(Unk_23d8db0, field_388, 0x388);
PKMN_OFFSET_ASSERT(Unk_23d8db0, field_38c, 0x38c);

// Created by 0x7100bc9080
class Unk_23d9048 : public Unk_c02310 {
public:
    using Unk_c02310::Unk_c02310;
    const Unk_239a418_Type* vf_type() override;
    Unk_23d4470_Map field_380;
    u32 field_3d8 = 0;
};
static_assert(sizeof(Unk_23d9048) == 0x3e0, "Unk_23d9048");
PKMN_OFFSET_ASSERT(Unk_23d9048, field_380, 0x380);
PKMN_OFFSET_ASSERT(Unk_23d9048, field_3d8, 0x3d8);

// Created by 0x7100bc9230
class Unk_23d7360 : public Unk_23d6a30 {
public:
    using Unk_23d6a30::Unk_23d6a30;
    const Unk_239a418_Type* vf_type() override;
    Unk_23c1480 field_5c0;
    u64 field_6d0 = 0;
    Unk_23c2620 field_6e0;
    u64 field_7f0 = 0;
    u64 field_7f8 = 0;
};
static_assert(sizeof(Unk_23d7360) == 0x800, "Unk_23d7360");
PKMN_OFFSET_ASSERT(Unk_23d7360, field_5c0, 0x5c0);
PKMN_OFFSET_ASSERT(Unk_23d7360, field_6d0, 0x6d0);
PKMN_OFFSET_ASSERT(Unk_23d7360, field_6e0, 0x6e0);
PKMN_OFFSET_ASSERT(Unk_23d7360, field_7f0, 0x7f0);
PKMN_OFFSET_ASSERT(Unk_23d7360, field_7f8, 0x7f8);

// Created by 0x7100bc9460
class Unk_23d87b8 : public Unk_23d4470 {
public:
    using Unk_23d4470::Unk_23d4470;
    const Unk_239a418_Type* vf_type() override;
    Unk_23f4660_Name field_348;
    u64 field_378 = 0;
    Unk_23983c0 field_380;
    u64 field_490 = 0;
    u8 _498[0x8];
    Unk_23c1480 field_4a0;
    char field_5b0[0x101] = {};
};
static_assert(sizeof(Unk_23d87b8) == 0x6c0, "Unk_23d87b8");
PKMN_OFFSET_ASSERT(Unk_23d87b8, field_348, 0x348);
PKMN_OFFSET_ASSERT(Unk_23d87b8, field_378, 0x378);
PKMN_OFFSET_ASSERT(Unk_23d87b8, field_380, 0x380);
PKMN_OFFSET_ASSERT(Unk_23d87b8, field_490, 0x490);
PKMN_OFFSET_ASSERT(Unk_23d87b8, field_4a0, 0x4a0);
PKMN_OFFSET_ASSERT(Unk_23d87b8, field_5b0, 0x5b0);

// Created by 0x7100bc9620
class Unk_23d8278 : public Unk_23d4470 {
public:
    using Unk_23d4470::Unk_23d4470;

    const Unk_239a418_Type* vf_type() override;

    u8 _348[0x20];
    u8 field_368 = 0;
};
static_assert(sizeof(Unk_23d8278) == 0x370, "Unk_23d8278");
PKMN_OFFSET_ASSERT(Unk_23d8278, field_368, 0x368);

// Created by 0x7100bc9730
class Unk_23d84b8 : public Unk_23d4470 {
public:
    using Unk_23d4470::Unk_23d4470;

    const Unk_239a418_Type* vf_type() override;

    u8 _348[0x20];
    u32 field_368 = 0;
    u8 field_36c = 0;
};
static_assert(sizeof(Unk_23d84b8) == 0x370, "Unk_23d84b8");
PKMN_OFFSET_ASSERT(Unk_23d84b8, field_368, 0x368);
PKMN_OFFSET_ASSERT(Unk_23d84b8, field_36c, 0x36c);

// Created by 0x7100bc9840
class Unk_23d86f8 : public Unk_23d4470 {
public:
    using Unk_23d4470::Unk_23d4470;

    const Unk_239a418_Type* vf_type() override;

    u8 _348[0x20];
    u32 field_368 = 0;
    u8 field_36c = 0;
};
static_assert(sizeof(Unk_23d86f8) == 0x370, "Unk_23d86f8");
PKMN_OFFSET_ASSERT(Unk_23d86f8, field_368, 0x368);
PKMN_OFFSET_ASSERT(Unk_23d86f8, field_36c, 0x36c);

// Created by 0x7100bc9950
class Unk_23d8638 : public Unk_23d4470 {
public:
    using Unk_23d4470::Unk_23d4470;

    const Unk_239a418_Type* vf_type() override;

    u8 _348[0x20];
    u16 field_368 = 0;
};
static_assert(sizeof(Unk_23d8638) == 0x370, "Unk_23d8638");
PKMN_OFFSET_ASSERT(Unk_23d8638, field_368, 0x368);

// Created by 0x7100bc9a60
class Unk_23d43b0 : public Unk_23d4470 {
public:
    using Unk_23d4470::Unk_23d4470;

    const Unk_239a418_Type* vf_type() override;

    f32 field_348 = 1.0f;
};
static_assert(sizeof(Unk_23d43b0) == 0x350, "Unk_23d43b0");
PKMN_OFFSET_ASSERT(Unk_23d43b0, field_348, 0x348);

// Created by 0x7100bca070
class Unk_23d7030 : public Unk_23d4470 {
public:
    using Unk_23d4470::Unk_23d4470;

    const Unk_239a418_Type* vf_type() override;

    u8 _348[0x28];
};
static_assert(sizeof(Unk_23d7030) == 0x370, "Unk_23d7030");

// Created by 0x7100bcaaa0
class Unk_23d45f0 : public Unk_23d4470 {
public:
    using Unk_23d4470::Unk_23d4470;

    const Unk_239a418_Type* vf_type() override;

    u8 _348[0x28];
    u8 field_370 = 0;
};
static_assert(sizeof(Unk_23d45f0) == 0x380, "Unk_23d45f0");
PKMN_OFFSET_ASSERT(Unk_23d45f0, field_370, 0x370);

// Created by 0x7100bcb1c0
class Unk_23d6728 : public Unk_23d4470 {
public:
    using Unk_23d4470::Unk_23d4470;

    const Unk_239a418_Type* vf_type() override;
    virtual void vf9();

    u8 _348[0x28];
    u64 field_370 = 0;
    u64 field_378 = 0;
    u8 field_380 = 0;
};
static_assert(sizeof(Unk_23d6728) == 0x390, "Unk_23d6728");
PKMN_OFFSET_ASSERT(Unk_23d6728, field_370, 0x370);
PKMN_OFFSET_ASSERT(Unk_23d6728, field_378, 0x378);
PKMN_OFFSET_ASSERT(Unk_23d6728, field_380, 0x380);

// Created by 0x7100bcb2e0
class Unk_23d46b0 : public Unk_23d4470 {
public:
    using Unk_23d4470::Unk_23d4470;

    const Unk_239a418_Type* vf_type() override;

    u8 _348[0x8];
    float32x4_t field_350 = {1.0f, 1.0f, 1.0f, 0.0f};
    u64 field_360 = 0;
    u64 field_368 = 0;
    u8 field_370 = 0;
};
static_assert(sizeof(Unk_23d46b0) == 0x380, "Unk_23d46b0");
PKMN_OFFSET_ASSERT(Unk_23d46b0, field_350, 0x350);
PKMN_OFFSET_ASSERT(Unk_23d46b0, field_360, 0x360);
PKMN_OFFSET_ASSERT(Unk_23d46b0, field_368, 0x368);
PKMN_OFFSET_ASSERT(Unk_23d46b0, field_370, 0x370);

// Created by 0x7100bcb970
class Unk_23d8338 : public Unk_23d4470 {
public:
    using Unk_23d4470::Unk_23d4470;

    const Unk_239a418_Type* vf_type() override;

    u8 field_348 = 1;
};
static_assert(sizeof(Unk_23d8338) == 0x350, "Unk_23d8338");
PKMN_OFFSET_ASSERT(Unk_23d8338, field_348, 0x348);

// Created by 0x7100bcd170
class Unk_23d4830 : public Unk_23d4470 {
public:
    using Unk_23d4470::Unk_23d4470;

    const Unk_239a418_Type* vf_type() override;

    u8 _348[0x18];
};
static_assert(sizeof(Unk_23d4830) == 0x360, "Unk_23d4830");

// Created by 0x7100bcd730
class Unk_23d48f0 : public Unk_23d4470 {
public:
    using Unk_23d4470::Unk_23d4470;

    const Unk_239a418_Type* vf_type() override;

    u64 field_348 = 0;
    u64 field_350 = 0;
    u32 field_358 = 0;
};
static_assert(sizeof(Unk_23d48f0) == 0x360, "Unk_23d48f0");
PKMN_OFFSET_ASSERT(Unk_23d48f0, field_348, 0x348);
PKMN_OFFSET_ASSERT(Unk_23d48f0, field_350, 0x350);
PKMN_OFFSET_ASSERT(Unk_23d48f0, field_358, 0x358);

// Created by 0x7100bcf620
class Unk_23d83f8 : public Unk_23d4470 {
public:
    using Unk_23d4470::Unk_23d4470;

    const Unk_239a418_Type* vf_type() override;

    u64 field_348 = 0;
    u64 field_350 = 0;
    u64 field_358 = 0;
    u64 field_360 = 0;
    u64 field_368 = 0;
    u8 field_370 = 0;
};
static_assert(sizeof(Unk_23d83f8) == 0x380, "Unk_23d83f8");
PKMN_OFFSET_ASSERT(Unk_23d83f8, field_348, 0x348);
PKMN_OFFSET_ASSERT(Unk_23d83f8, field_350, 0x350);
PKMN_OFFSET_ASSERT(Unk_23d83f8, field_358, 0x358);
PKMN_OFFSET_ASSERT(Unk_23d83f8, field_360, 0x360);
PKMN_OFFSET_ASSERT(Unk_23d83f8, field_368, 0x368);
PKMN_OFFSET_ASSERT(Unk_23d83f8, field_370, 0x370);

// Created by 0x7100bcf740
class Unk_23d8578 : public Unk_23d4470 {
public:
    using Unk_23d4470::Unk_23d4470;

    const Unk_239a418_Type* vf_type() override;

    u32 field_348 = 0;
    u8 field_34c = 0;
};
static_assert(sizeof(Unk_23d8578) == 0x350, "Unk_23d8578");
PKMN_OFFSET_ASSERT(Unk_23d8578, field_348, 0x348);
PKMN_OFFSET_ASSERT(Unk_23d8578, field_34c, 0x34c);

// Created by 0x7100bcf850
class Unk_23d6af0 : public Unk_23d4470 {
public:
    using Unk_23d4470::Unk_23d4470;

    const Unk_239a418_Type* vf_type() override;

    u32 field_348 = 0;
    u8 field_34c = 0;
};
static_assert(sizeof(Unk_23d6af0) == 0x350, "Unk_23d6af0");
PKMN_OFFSET_ASSERT(Unk_23d6af0, field_348, 0x348);
PKMN_OFFSET_ASSERT(Unk_23d6af0, field_34c, 0x34c);

// Created by 0x7100bcf960
class Unk_23d94f0 : public Unk_23d4470 {
public:
    using Unk_23d4470::Unk_23d4470;
    const Unk_239a418_Type* vf_type() override;
    u32 field_348 = 0;
    Unk_23f4660_Name field_350;
    Unk_23f4660_Name field_380;
    Unk_23d4b30 field_3b0;
    Unk_23d4b30 field_4c0;
    u64 field_5d0 = 0;
    u64 field_5d8 = 0;
    u64 field_5e0 = 0;
    u64 field_5e8 = 0;
    u64 field_5f0 = 0;
    u8 _5f8[0x8];
    u64 field_600 = 0;
    u64 field_608 = 0;
    u8 field_610 = 0;
    s32 field_614 = -1;
};
static_assert(sizeof(Unk_23d94f0) == 0x620, "Unk_23d94f0");
PKMN_OFFSET_ASSERT(Unk_23d94f0, field_348, 0x348);
PKMN_OFFSET_ASSERT(Unk_23d94f0, field_350, 0x350);
PKMN_OFFSET_ASSERT(Unk_23d94f0, field_380, 0x380);
PKMN_OFFSET_ASSERT(Unk_23d94f0, field_3b0, 0x3b0);
PKMN_OFFSET_ASSERT(Unk_23d94f0, field_4c0, 0x4c0);
PKMN_OFFSET_ASSERT(Unk_23d94f0, field_5d0, 0x5d0);
PKMN_OFFSET_ASSERT(Unk_23d94f0, field_5d8, 0x5d8);
PKMN_OFFSET_ASSERT(Unk_23d94f0, field_5e0, 0x5e0);
PKMN_OFFSET_ASSERT(Unk_23d94f0, field_5e8, 0x5e8);
PKMN_OFFSET_ASSERT(Unk_23d94f0, field_5f0, 0x5f0);
PKMN_OFFSET_ASSERT(Unk_23d94f0, field_600, 0x600);
PKMN_OFFSET_ASSERT(Unk_23d94f0, field_608, 0x608);
PKMN_OFFSET_ASSERT(Unk_23d94f0, field_610, 0x610);
PKMN_OFFSET_ASSERT(Unk_23d94f0, field_614, 0x614);

// Created by 0x7100bcfb80
class Unk_23d4b50 : public Unk_23d6728 {
public:
    using Unk_23d6728::Unk_23d6728;

    const Unk_239a418_Type* vf_type() override;

    s32 field_384 = -1;
    u8 field_388 = 0;
};
static_assert(sizeof(Unk_23d4b50) == 0x390, "Unk_23d4b50");
PKMN_OFFSET_ASSERT(Unk_23d4b50, field_384, 0x384);
PKMN_OFFSET_ASSERT(Unk_23d4b50, field_388, 0x388);

// Created by 0x7100bd05a0
class Unk_23d7778 : public Unk_23d4470 {
public:
    using Unk_23d4470::Unk_23d4470;
    const Unk_239a418_Type* vf_type() override;
    s32 field_348 = -1;
    u16 field_34c = 0;
    u8 field_34e = 0;
    Unk_23f4660_Name field_350;
    Unk_23f4660_Name field_380;
    Unk_23d4c18 field_3b0;
    Unk_23d4c18 field_4c0;
    u64 field_5d0 = 0;
    u64 field_5d8 = 0;
    u64 field_5e0 = 0;
    u64 field_5e8 = 0;
};
static_assert(sizeof(Unk_23d7778) == 0x5f0, "Unk_23d7778");
PKMN_OFFSET_ASSERT(Unk_23d7778, field_348, 0x348);
PKMN_OFFSET_ASSERT(Unk_23d7778, field_34c, 0x34c);
PKMN_OFFSET_ASSERT(Unk_23d7778, field_34e, 0x34e);
PKMN_OFFSET_ASSERT(Unk_23d7778, field_350, 0x350);
PKMN_OFFSET_ASSERT(Unk_23d7778, field_380, 0x380);
PKMN_OFFSET_ASSERT(Unk_23d7778, field_3b0, 0x3b0);
PKMN_OFFSET_ASSERT(Unk_23d7778, field_4c0, 0x4c0);
PKMN_OFFSET_ASSERT(Unk_23d7778, field_5d0, 0x5d0);
PKMN_OFFSET_ASSERT(Unk_23d7778, field_5d8, 0x5d8);
PKMN_OFFSET_ASSERT(Unk_23d7778, field_5e0, 0x5e0);
PKMN_OFFSET_ASSERT(Unk_23d7778, field_5e8, 0x5e8);

// Created by 0x7100bd0a30
class Unk_23d6bb0 : public Unk_23d4470 {
public:
    using Unk_23d4470::Unk_23d4470;
    const Unk_239a418_Type* vf_type() override;
    u64 field_348 = 0;
    Unk_23f4660_Name field_350;
    Unk_23c4840 field_380;
    u64 field_490 = 0;
    u64 field_498 = 0;
    u32 field_4a0 = 0x7f;
};
static_assert(sizeof(Unk_23d6bb0) == 0x4b0, "Unk_23d6bb0");
PKMN_OFFSET_ASSERT(Unk_23d6bb0, field_348, 0x348);
PKMN_OFFSET_ASSERT(Unk_23d6bb0, field_350, 0x350);
PKMN_OFFSET_ASSERT(Unk_23d6bb0, field_380, 0x380);
PKMN_OFFSET_ASSERT(Unk_23d6bb0, field_490, 0x490);
PKMN_OFFSET_ASSERT(Unk_23d6bb0, field_498, 0x498);
PKMN_OFFSET_ASSERT(Unk_23d6bb0, field_4a0, 0x4a0);

// Created by 0x7100bd0bb0
class Unk_23d8038 : public Unk_23d4470 {
public:
    using Unk_23d4470::Unk_23d4470;
    const Unk_239a418_Type* vf_type() override;
    Unk_23f4660_Name field_348;
    u64 field_378 = 0;
    Unk_23c46e8 field_380;
    u64 field_490 = 0;
};
static_assert(sizeof(Unk_23d8038) == 0x4a0, "Unk_23d8038");
PKMN_OFFSET_ASSERT(Unk_23d8038, field_348, 0x348);
PKMN_OFFSET_ASSERT(Unk_23d8038, field_378, 0x378);
PKMN_OFFSET_ASSERT(Unk_23d8038, field_380, 0x380);
PKMN_OFFSET_ASSERT(Unk_23d8038, field_490, 0x490);

// Created by 0x7100bd0d30
class Unk_23d4cf8 : public Unk_23d4470 {
public:
    using Unk_23d4470::Unk_23d4470;

    const Unk_239a418_Type* vf_type() override;

    f32 field_348 = -1.0f;
    f32 field_34c = 1.0f;
};
static_assert(sizeof(Unk_23d4cf8) == 0x350, "Unk_23d4cf8");
PKMN_OFFSET_ASSERT(Unk_23d4cf8, field_348, 0x348);
PKMN_OFFSET_ASSERT(Unk_23d4cf8, field_34c, 0x34c);

// Created by 0x7100bd11b0
class Unk_23d72a0 : public Unk_23d4470 {
public:
    using Unk_23d4470::Unk_23d4470;
    const Unk_239a418_Type* vf_type() override;
    Unk_23f4660_Name field_348;
    u8 field_378 = 0;
    u32 field_37c = 0;
    u32 field_380 = 0;
    u32 field_384 = 0;
    u32 field_388 = 0;
    u32 field_38c = 0;
    Unk_23c14a0 field_390;
    s32 field_4a0 = -1;
};
static_assert(sizeof(Unk_23d72a0) == 0x4b0, "Unk_23d72a0");
PKMN_OFFSET_ASSERT(Unk_23d72a0, field_348, 0x348);
PKMN_OFFSET_ASSERT(Unk_23d72a0, field_378, 0x378);
PKMN_OFFSET_ASSERT(Unk_23d72a0, field_37c, 0x37c);
PKMN_OFFSET_ASSERT(Unk_23d72a0, field_380, 0x380);
PKMN_OFFSET_ASSERT(Unk_23d72a0, field_384, 0x384);
PKMN_OFFSET_ASSERT(Unk_23d72a0, field_388, 0x388);
PKMN_OFFSET_ASSERT(Unk_23d72a0, field_38c, 0x38c);
PKMN_OFFSET_ASSERT(Unk_23d72a0, field_390, 0x390);
PKMN_OFFSET_ASSERT(Unk_23d72a0, field_4a0, 0x4a0);

// Created by 0x7100bd1750
class Unk_23d4e78 : public Unk_23d4470 {
public:
    using Unk_23d4470::Unk_23d4470;

    const Unk_239a418_Type* vf_type() override;

    u8 _348[0x18];
};
static_assert(sizeof(Unk_23d4e78) == 0x360, "Unk_23d4e78");

// Created by 0x7100bd1db0
class Unk_23d4f38 : public Unk_23d4470 {
public:
    using Unk_23d4470::Unk_23d4470;

    const Unk_239a418_Type* vf_type() override;

    u64 field_348 = 0;
    u64 field_350 = 0;
    u32 field_358 = 0;
};
static_assert(sizeof(Unk_23d4f38) == 0x360, "Unk_23d4f38");
PKMN_OFFSET_ASSERT(Unk_23d4f38, field_348, 0x348);
PKMN_OFFSET_ASSERT(Unk_23d4f38, field_350, 0x350);
PKMN_OFFSET_ASSERT(Unk_23d4f38, field_358, 0x358);

// Created by 0x7100bd24a0
class Unk_23d6c70 : public Unk_23d4470 {
public:
    using Unk_23d4470::Unk_23d4470;
    const Unk_239a418_Type* vf_type() override;
    Unk_23f4660_Name field_348;
    u64 field_378 = 0;
    u64 field_380 = 0;
    u8 _388[0x8];
    Unk_23dba78 field_390;
    Unk_23f2df0_1e0 field_4a0;
    s32 field_580 = -1;
};
static_assert(sizeof(Unk_23d6c70) == 0x590, "Unk_23d6c70");
PKMN_OFFSET_ASSERT(Unk_23d6c70, field_348, 0x348);
PKMN_OFFSET_ASSERT(Unk_23d6c70, field_378, 0x378);
PKMN_OFFSET_ASSERT(Unk_23d6c70, field_380, 0x380);
PKMN_OFFSET_ASSERT(Unk_23d6c70, field_390, 0x390);
PKMN_OFFSET_ASSERT(Unk_23d6c70, field_4a0, 0x4a0);
PKMN_OFFSET_ASSERT(Unk_23d6c70, field_580, 0x580);

// Created by 0x7100bd2630
class Unk_23d81b8 : public Unk_23d4470 {
public:
    using Unk_23d4470::Unk_23d4470;

    const Unk_239a418_Type* vf_type() override;

    u8 _348[0x28];
};
static_assert(sizeof(Unk_23d81b8) == 0x370, "Unk_23d81b8");

// Created by 0x7100bd2740
class Unk_23d68b0 : public Unk_23d4470 {
public:
    using Unk_23d4470::Unk_23d4470;

    const Unk_239a418_Type* vf_type() override;

    u8 _348[0x20];
    s32 field_368 = -1;
};
static_assert(sizeof(Unk_23d68b0) == 0x370, "Unk_23d68b0");
PKMN_OFFSET_ASSERT(Unk_23d68b0, field_368, 0x368);

// Created by 0x7100bd2850
class Unk_23d9130 : public Unk_23d4470 {
public:
    using Unk_23d4470::Unk_23d4470;

    const Unk_239a418_Type* vf_type() override;

    u32 field_348 = 0;
    u8 _34c[0x64];
};
static_assert(sizeof(Unk_23d9130) == 0x3b0, "Unk_23d9130");
PKMN_OFFSET_ASSERT(Unk_23d9130, field_348, 0x348);

// Created by 0x7100bd2960
class Unk_23d71e0 : public Unk_23d4470 {
public:
    using Unk_23d4470::Unk_23d4470;
    const Unk_239a418_Type* vf_type() override;
    Unk_23d4470_Text field_348;
    Unk_7910a0 field_3e8;
    bool field_400 = false;
};
static_assert(sizeof(Unk_23d71e0) == 0x410, "Unk_23d71e0");
PKMN_OFFSET_ASSERT(Unk_23d71e0, field_348, 0x348);
PKMN_OFFSET_ASSERT(Unk_23d71e0, field_3e8, 0x3e8);
PKMN_OFFSET_ASSERT(Unk_23d71e0, field_400, 0x400);

// Created by 0x7100bd2aa0
class Unk_23d7950 : public Unk_23d4470 {
public:
    using Unk_23d4470::Unk_23d4470;
    const Unk_239a418_Type* vf_type() override;
    Unk_23d4470_Text field_348;
    bool field_3e8 = false;
    s32 field_3ec = -1;
};
static_assert(sizeof(Unk_23d7950) == 0x3f0, "Unk_23d7950");
PKMN_OFFSET_ASSERT(Unk_23d7950, field_348, 0x348);
PKMN_OFFSET_ASSERT(Unk_23d7950, field_3e8, 0x3e8);
PKMN_OFFSET_ASSERT(Unk_23d7950, field_3ec, 0x3ec);

// Created by 0x7100bd2be0
class Unk_23d7a10 : public Unk_23d4470 {
public:
    using Unk_23d4470::Unk_23d4470;

    const Unk_239a418_Type* vf_type() override;
    virtual void vf9();

    u32 field_348 = 0;
    u8 field_34c = 0;
    u8 _34d[0x3];
    u32 field_350 = 0;
};
static_assert(sizeof(Unk_23d7a10) == 0x360, "Unk_23d7a10");
PKMN_OFFSET_ASSERT(Unk_23d7a10, field_348, 0x348);
PKMN_OFFSET_ASSERT(Unk_23d7a10, field_34c, 0x34c);
PKMN_OFFSET_ASSERT(Unk_23d7a10, field_350, 0x350);

// Created by 0x7100bd2d00
class Unk_23d8f80 : public Unk_23d7a10 {
public:
    using Unk_23d7a10::Unk_23d7a10;

    const Unk_239a418_Type* vf_type() override;

    u32 field_354 = 0;
    u16 field_358 = 0;
    u32 field_35c = 0;
    u16 field_360 = 0;
    u32 field_364 = 0;
    u32 field_368 = 0;
    s32 field_36c = -1;
    u32 field_370 = 0;
    u32 field_374 = 0;
};
static_assert(sizeof(Unk_23d8f80) == 0x380, "Unk_23d8f80");
PKMN_OFFSET_ASSERT(Unk_23d8f80, field_354, 0x354);
PKMN_OFFSET_ASSERT(Unk_23d8f80, field_358, 0x358);
PKMN_OFFSET_ASSERT(Unk_23d8f80, field_35c, 0x35c);
PKMN_OFFSET_ASSERT(Unk_23d8f80, field_360, 0x360);
PKMN_OFFSET_ASSERT(Unk_23d8f80, field_364, 0x364);
PKMN_OFFSET_ASSERT(Unk_23d8f80, field_368, 0x368);
PKMN_OFFSET_ASSERT(Unk_23d8f80, field_36c, 0x36c);
PKMN_OFFSET_ASSERT(Unk_23d8f80, field_370, 0x370);
PKMN_OFFSET_ASSERT(Unk_23d8f80, field_374, 0x374);

// Created by 0x7100bd2e40
class Unk_23d7f78 : public Unk_23d4470 {
public:
    using Unk_23d4470::Unk_23d4470;
    const Unk_239a418_Type* vf_type() override;
    Unk_23d4470_Text field_348;
    Unk_23d4470_Text field_3e8;
};
static_assert(sizeof(Unk_23d7f78) == 0x490, "Unk_23d7f78");
PKMN_OFFSET_ASSERT(Unk_23d7f78, field_348, 0x348);
PKMN_OFFSET_ASSERT(Unk_23d7f78, field_3e8, 0x3e8);

// Created by 0x7100bd2f80
class Unk_23d9430 : public Unk_23d4470 {
public:
    using Unk_23d4470::Unk_23d4470;

    const Unk_239a418_Type* vf_type() override;

    u32 field_348 = 0;
    u8 _34c[0x24];
    u16 field_370 = 0;
};
static_assert(sizeof(Unk_23d9430) == 0x380, "Unk_23d9430");
PKMN_OFFSET_ASSERT(Unk_23d9430, field_348, 0x348);
PKMN_OFFSET_ASSERT(Unk_23d9430, field_370, 0x370);

// Created by 0x7100bd31a0
class Unk_23d92b0 : public Unk_23d4470 {
public:
    using Unk_23d4470::Unk_23d4470;

    const Unk_239a418_Type* vf_type() override;

    u64 field_348 = 0;
    u64 field_350 = 0;
    f32 field_358 = 1.0f;
    f32 field_35c = 1.0f;
    u32 field_360 = 0;
    u8 field_364 = 0;
    u8 _365[0x3];
    u32 field_368 = 0;
};
static_assert(sizeof(Unk_23d92b0) == 0x370, "Unk_23d92b0");
PKMN_OFFSET_ASSERT(Unk_23d92b0, field_348, 0x348);
PKMN_OFFSET_ASSERT(Unk_23d92b0, field_350, 0x350);
PKMN_OFFSET_ASSERT(Unk_23d92b0, field_358, 0x358);
PKMN_OFFSET_ASSERT(Unk_23d92b0, field_35c, 0x35c);
PKMN_OFFSET_ASSERT(Unk_23d92b0, field_360, 0x360);
PKMN_OFFSET_ASSERT(Unk_23d92b0, field_364, 0x364);
PKMN_OFFSET_ASSERT(Unk_23d92b0, field_368, 0x368);

// Created by 0x7100bd32d0
class Unk_23d4ff8 : public Unk_23d4470 {
public:
    using Unk_23d4470::Unk_23d4470;

    const Unk_239a418_Type* vf_type() override;

    u8 _348[0x8];
    u64 field_350 = 0;
    u64 field_358 = 0;
    u64 field_360 = 0;
    u64 field_368 = 0;
};
static_assert(sizeof(Unk_23d4ff8) == 0x370, "Unk_23d4ff8");
PKMN_OFFSET_ASSERT(Unk_23d4ff8, field_350, 0x350);
PKMN_OFFSET_ASSERT(Unk_23d4ff8, field_358, 0x358);
PKMN_OFFSET_ASSERT(Unk_23d4ff8, field_360, 0x360);
PKMN_OFFSET_ASSERT(Unk_23d4ff8, field_368, 0x368);

// Created by 0x7100bd3620
class Unk_23d50b8 : public Unk_23d4470 {
public:
    using Unk_23d4470::Unk_23d4470;
    const Unk_239a418_Type* vf_type() override;
    u8 _348[0x38];
    Unk_23d4470_Map field_380;
};
static_assert(sizeof(Unk_23d50b8) == 0x3e0, "Unk_23d50b8");
PKMN_OFFSET_ASSERT(Unk_23d50b8, field_380, 0x380);

// Created by 0x7100bd4c40
class Unk_23d5178 : public Unk_23d4470 {
public:
    using Unk_23d4470::Unk_23d4470;
    const Unk_239a418_Type* vf_type() override;
    u8 _348[0x20];
    u32 field_368 = 0;
    Unk_23d4470_Map field_370;
};
static_assert(sizeof(Unk_23d5178) == 0x3d0, "Unk_23d5178");
PKMN_OFFSET_ASSERT(Unk_23d5178, field_368, 0x368);
PKMN_OFFSET_ASSERT(Unk_23d5178, field_370, 0x370);

// Created by 0x7100bd5f50
class Unk_23d5238 : public Unk_23d4470 {
public:
    using Unk_23d4470::Unk_23d4470;

    const Unk_239a418_Type* vf_type() override;

    u8 _348[0x20];
    u8 field_368 = 0;
};
static_assert(sizeof(Unk_23d5238) == 0x370, "Unk_23d5238");
PKMN_OFFSET_ASSERT(Unk_23d5238, field_368, 0x368);

// Created by 0x7100bd6550
class Unk_23d91f0 : public Unk_23d4470 {
public:
    using Unk_23d4470::Unk_23d4470;
    const Unk_239a418_Type* vf_type() override;
    f32 field_348 = 0.18f;
    f32 field_34c = 0.5f;
    f32 field_350 = -16.0f;
    f32 field_354 = 16.0f;
    f32 field_358 = 1.0f;
    f32 field_35c = 1.0f;
    u64 field_360 = 0;
    f32 field_368 = 0.5f;
    f32 field_36c = 0.85f;
    f32 field_370 = 8.0f;
    f32 field_374 = 0.5f;
    f32 field_378 = 0.85f;
    f32 field_37c = 8.0f;
    u64 field_380 = 0;
    u32 field_388 = 0;
};
static_assert(sizeof(Unk_23d91f0) == 0x390, "Unk_23d91f0");
PKMN_OFFSET_ASSERT(Unk_23d91f0, field_348, 0x348);
PKMN_OFFSET_ASSERT(Unk_23d91f0, field_34c, 0x34c);
PKMN_OFFSET_ASSERT(Unk_23d91f0, field_350, 0x350);
PKMN_OFFSET_ASSERT(Unk_23d91f0, field_354, 0x354);
PKMN_OFFSET_ASSERT(Unk_23d91f0, field_358, 0x358);
PKMN_OFFSET_ASSERT(Unk_23d91f0, field_35c, 0x35c);
PKMN_OFFSET_ASSERT(Unk_23d91f0, field_360, 0x360);
PKMN_OFFSET_ASSERT(Unk_23d91f0, field_368, 0x368);
PKMN_OFFSET_ASSERT(Unk_23d91f0, field_36c, 0x36c);
PKMN_OFFSET_ASSERT(Unk_23d91f0, field_370, 0x370);
PKMN_OFFSET_ASSERT(Unk_23d91f0, field_374, 0x374);
PKMN_OFFSET_ASSERT(Unk_23d91f0, field_378, 0x378);
PKMN_OFFSET_ASSERT(Unk_23d91f0, field_37c, 0x37c);
PKMN_OFFSET_ASSERT(Unk_23d91f0, field_380, 0x380);
PKMN_OFFSET_ASSERT(Unk_23d91f0, field_388, 0x388);

// Created by 0x7100bd66c0
class Unk_23d80f8 : public Unk_23d4470 {
public:
    using Unk_23d4470::Unk_23d4470;
    const Unk_239a418_Type* vf_type() override;
    f32 field_348 = 0.0f;
    f32 field_34c = 1.0f;
    f32 field_350 = 1.0f;
    f32 field_354 = 1.0f;
    f32 field_358 = 0.0f;
    f32 field_35c = 6500.0f;
    f32 field_360 = 6500.0f;
    u32 field_364 = 0;
    u32 field_368 = 0;
    u32 field_36c = 0;
    u32 field_370 = 0;
    u32 field_374 = 0;
    f32 field_378 = 1.0f;
    f32 field_37c = 1.0f;
    f32 field_380 = 1.0f;
    f32 field_384 = 0.0f;
    f32 field_388 = 6500.0f;
    f32 field_38c = 6500.0f;
    u64 field_390 = 0;
    u64 field_398 = 0;
};
static_assert(sizeof(Unk_23d80f8) == 0x3a0, "Unk_23d80f8");
PKMN_OFFSET_ASSERT(Unk_23d80f8, field_348, 0x348);
PKMN_OFFSET_ASSERT(Unk_23d80f8, field_34c, 0x34c);
PKMN_OFFSET_ASSERT(Unk_23d80f8, field_350, 0x350);
PKMN_OFFSET_ASSERT(Unk_23d80f8, field_354, 0x354);
PKMN_OFFSET_ASSERT(Unk_23d80f8, field_358, 0x358);
PKMN_OFFSET_ASSERT(Unk_23d80f8, field_35c, 0x35c);
PKMN_OFFSET_ASSERT(Unk_23d80f8, field_360, 0x360);
PKMN_OFFSET_ASSERT(Unk_23d80f8, field_364, 0x364);
PKMN_OFFSET_ASSERT(Unk_23d80f8, field_368, 0x368);
PKMN_OFFSET_ASSERT(Unk_23d80f8, field_36c, 0x36c);
PKMN_OFFSET_ASSERT(Unk_23d80f8, field_370, 0x370);
PKMN_OFFSET_ASSERT(Unk_23d80f8, field_374, 0x374);
PKMN_OFFSET_ASSERT(Unk_23d80f8, field_378, 0x378);
PKMN_OFFSET_ASSERT(Unk_23d80f8, field_37c, 0x37c);
PKMN_OFFSET_ASSERT(Unk_23d80f8, field_380, 0x380);
PKMN_OFFSET_ASSERT(Unk_23d80f8, field_384, 0x384);
PKMN_OFFSET_ASSERT(Unk_23d80f8, field_388, 0x388);
PKMN_OFFSET_ASSERT(Unk_23d80f8, field_38c, 0x38c);
PKMN_OFFSET_ASSERT(Unk_23d80f8, field_390, 0x390);
PKMN_OFFSET_ASSERT(Unk_23d80f8, field_398, 0x398);

// Created by 0x7100bd6830
class Unk_23d6d30 : public Unk_23d4470 {
public:
    using Unk_23d4470::Unk_23d4470;

    const Unk_239a418_Type* vf_type() override;

    u8 field_348 = 0;
    u8 _349[0x3];
    f32 field_34c = 20.0f;
    f32 field_350 = 100.0f;
    f32 field_354 = 20.0f;
    f32 field_358 = 100.0f;
    u8 field_35c = 0;
};
static_assert(sizeof(Unk_23d6d30) == 0x360, "Unk_23d6d30");
PKMN_OFFSET_ASSERT(Unk_23d6d30, field_348, 0x348);
PKMN_OFFSET_ASSERT(Unk_23d6d30, field_34c, 0x34c);
PKMN_OFFSET_ASSERT(Unk_23d6d30, field_350, 0x350);
PKMN_OFFSET_ASSERT(Unk_23d6d30, field_354, 0x354);
PKMN_OFFSET_ASSERT(Unk_23d6d30, field_358, 0x358);
PKMN_OFFSET_ASSERT(Unk_23d6d30, field_35c, 0x35c);

// Created by 0x7100bd6960
class Unk_23d6970 : public Unk_23d4470 {
public:
    using Unk_23d4470::Unk_23d4470;

    const Unk_239a418_Type* vf_type() override;

    u64 field_348 = 0;
    f32 field_350 = 0.2f;
    f32 field_354 = 1.0f;
    s32 field_358 = -1;
    f32 field_35c = 0.0f;
    f32 field_360 = 0.0f;
    f32 field_364 = 0.2f;
    f32 field_368 = 1.0f;
};
static_assert(sizeof(Unk_23d6970) == 0x370, "Unk_23d6970");
PKMN_OFFSET_ASSERT(Unk_23d6970, field_348, 0x348);
PKMN_OFFSET_ASSERT(Unk_23d6970, field_350, 0x350);
PKMN_OFFSET_ASSERT(Unk_23d6970, field_354, 0x354);
PKMN_OFFSET_ASSERT(Unk_23d6970, field_358, 0x358);
PKMN_OFFSET_ASSERT(Unk_23d6970, field_35c, 0x35c);
PKMN_OFFSET_ASSERT(Unk_23d6970, field_360, 0x360);
PKMN_OFFSET_ASSERT(Unk_23d6970, field_364, 0x364);
PKMN_OFFSET_ASSERT(Unk_23d6970, field_368, 0x368);

// Created by 0x7100bd6aa0
class Unk_23d75f8 : public Unk_23d4470 {
public:
    using Unk_23d4470::Unk_23d4470;

    const Unk_239a418_Type* vf_type() override;

    u64 field_348 = 0;
    f32 field_350 = 1.0f;
    f32 field_354 = 0.0f;
    f32 field_358 = 1.0f;
    f32 field_35c = 1.0f;
    f32 field_360 = 1.0f;
    f32 field_364 = 0.0f;
    f32 field_368 = 0.0f;
    f32 field_36c = 1.0f;
    f32 field_370 = 0.0f;
    f32 field_374 = 1.0f;
    f32 field_378 = 1.0f;
    f32 field_37c = 1.0f;
};
static_assert(sizeof(Unk_23d75f8) == 0x380, "Unk_23d75f8");
PKMN_OFFSET_ASSERT(Unk_23d75f8, field_348, 0x348);
PKMN_OFFSET_ASSERT(Unk_23d75f8, field_350, 0x350);
PKMN_OFFSET_ASSERT(Unk_23d75f8, field_354, 0x354);
PKMN_OFFSET_ASSERT(Unk_23d75f8, field_358, 0x358);
PKMN_OFFSET_ASSERT(Unk_23d75f8, field_35c, 0x35c);
PKMN_OFFSET_ASSERT(Unk_23d75f8, field_360, 0x360);
PKMN_OFFSET_ASSERT(Unk_23d75f8, field_364, 0x364);
PKMN_OFFSET_ASSERT(Unk_23d75f8, field_368, 0x368);
PKMN_OFFSET_ASSERT(Unk_23d75f8, field_36c, 0x36c);
PKMN_OFFSET_ASSERT(Unk_23d75f8, field_370, 0x370);
PKMN_OFFSET_ASSERT(Unk_23d75f8, field_374, 0x374);
PKMN_OFFSET_ASSERT(Unk_23d75f8, field_378, 0x378);
PKMN_OFFSET_ASSERT(Unk_23d75f8, field_37c, 0x37c);

// Created by 0x7100bd6bd0
class Unk_23d6f70 : public Unk_23d4470 {
public:
    using Unk_23d4470::Unk_23d4470;

    const Unk_239a418_Type* vf_type() override;

    u64 field_348 = 0;
    u64 field_350 = 0;
    f32 field_358 = 0.005f;
    bool field_35c = true;
    bool field_35d = true;
    u8 _35e[0x12];
    f32 field_370 = 0.005f;
};
static_assert(sizeof(Unk_23d6f70) == 0x380, "Unk_23d6f70");
PKMN_OFFSET_ASSERT(Unk_23d6f70, field_348, 0x348);
PKMN_OFFSET_ASSERT(Unk_23d6f70, field_350, 0x350);
PKMN_OFFSET_ASSERT(Unk_23d6f70, field_358, 0x358);
PKMN_OFFSET_ASSERT(Unk_23d6f70, field_35c, 0x35c);
PKMN_OFFSET_ASSERT(Unk_23d6f70, field_35d, 0x35d);
PKMN_OFFSET_ASSERT(Unk_23d6f70, field_370, 0x370);

// Created by 0x7100bd6d00
class Unk_23d76b8 : public Unk_23d4470 {
public:
    using Unk_23d4470::Unk_23d4470;

    const Unk_239a418_Type* vf_type() override;

    f32 field_348 = 0.0f;
    f32 field_34c = 1.0f;
    f32 field_350 = 30.0f;
    f32 field_354 = 20.0f;
};
static_assert(sizeof(Unk_23d76b8) == 0x360, "Unk_23d76b8");
PKMN_OFFSET_ASSERT(Unk_23d76b8, field_348, 0x348);
PKMN_OFFSET_ASSERT(Unk_23d76b8, field_34c, 0x34c);
PKMN_OFFSET_ASSERT(Unk_23d76b8, field_350, 0x350);
PKMN_OFFSET_ASSERT(Unk_23d76b8, field_354, 0x354);

// Created by 0x7100bd7030
class Unk_23d52f8 : public Unk_23d4470 {
public:
    using Unk_23d4470::Unk_23d4470;

    const Unk_239a418_Type* vf_type() override;

    u8 field_348 = 1;
};
static_assert(sizeof(Unk_23d52f8) == 0x350, "Unk_23d52f8");
PKMN_OFFSET_ASSERT(Unk_23d52f8, field_348, 0x348);

// Created by 0x7100bd77a0
class Unk_23d53b8 : public Unk_23d4470 {
public:
    using Unk_23d4470::Unk_23d4470;

    const Unk_239a418_Type* vf_type() override;

    bool field_348 = true;
    bool field_349 = true;
    bool field_34a = true;
    bool field_34b = true;
    bool field_34c = true;
};
static_assert(sizeof(Unk_23d53b8) == 0x350, "Unk_23d53b8");
PKMN_OFFSET_ASSERT(Unk_23d53b8, field_348, 0x348);
PKMN_OFFSET_ASSERT(Unk_23d53b8, field_349, 0x349);
PKMN_OFFSET_ASSERT(Unk_23d53b8, field_34a, 0x34a);
PKMN_OFFSET_ASSERT(Unk_23d53b8, field_34b, 0x34b);
PKMN_OFFSET_ASSERT(Unk_23d53b8, field_34c, 0x34c);

// Created by 0x7100bd7cc0
class Unk_23d5478 : public Unk_23d4470 {
public:
    using Unk_23d4470::Unk_23d4470;

    const Unk_239a418_Type* vf_type() override;

    u32 field_348 = 1;
    u32 field_34c = 1;
    u32 field_350 = 0;
};
static_assert(sizeof(Unk_23d5478) == 0x360, "Unk_23d5478");
PKMN_OFFSET_ASSERT(Unk_23d5478, field_348, 0x348);
PKMN_OFFSET_ASSERT(Unk_23d5478, field_34c, 0x34c);
PKMN_OFFSET_ASSERT(Unk_23d5478, field_350, 0x350);

// Created by 0x7100bd8320
class Unk_23d5538 : public Unk_23d4470 {
public:
    using Unk_23d4470::Unk_23d4470;

    const Unk_239a418_Type* vf_type() override;

    u16 field_348 = 0;
};
static_assert(sizeof(Unk_23d5538) == 0x350, "Unk_23d5538");
PKMN_OFFSET_ASSERT(Unk_23d5538, field_348, 0x348);

// Created by 0x7100bd8a40
class Unk_23d67f0 : public Unk_23d4470 {
public:
    using Unk_23d4470::Unk_23d4470;

    const Unk_239a418_Type* vf_type() override;

    char field_348[0x20];
    u32 field_368 = 0;
    Unk_239a418_Ref<Unk_239a418> field_370;
    u32 field_378 = 30;
    u32 field_37c = 1;
    bool field_380 = false;
    bool field_381 = false;
    bool field_382 = false;
    bool field_383 = false;
    bool field_384 = false;
    bool field_385 = false;
    bool field_386 = false;
};
static_assert(sizeof(Unk_23d67f0) == 0x390, "Unk_23d67f0");
PKMN_OFFSET_ASSERT(Unk_23d67f0, field_348, 0x348);
PKMN_OFFSET_ASSERT(Unk_23d67f0, field_368, 0x368);
PKMN_OFFSET_ASSERT(Unk_23d67f0, field_370, 0x370);
PKMN_OFFSET_ASSERT(Unk_23d67f0, field_378, 0x378);
PKMN_OFFSET_ASSERT(Unk_23d67f0, field_37c, 0x37c);
PKMN_OFFSET_ASSERT(Unk_23d67f0, field_380, 0x380);
PKMN_OFFSET_ASSERT(Unk_23d67f0, field_381, 0x381);
PKMN_OFFSET_ASSERT(Unk_23d67f0, field_382, 0x382);
PKMN_OFFSET_ASSERT(Unk_23d67f0, field_383, 0x383);
PKMN_OFFSET_ASSERT(Unk_23d67f0, field_384, 0x384);
PKMN_OFFSET_ASSERT(Unk_23d67f0, field_385, 0x385);
PKMN_OFFSET_ASSERT(Unk_23d67f0, field_386, 0x386);

// Created by 0x7100bd8b70
class Unk_23d55f8 : public Unk_23d4470 {
public:
    using Unk_23d4470::Unk_23d4470;

    const Unk_239a418_Type* vf_type() override;

    u64 field_348 = 0;
};
static_assert(sizeof(Unk_23d55f8) == 0x350, "Unk_23d55f8");
PKMN_OFFSET_ASSERT(Unk_23d55f8, field_348, 0x348);

// Created by 0x7100bd9100
class Unk_23d8950 : public Unk_23d4470 {
public:
    using Unk_23d4470::Unk_23d4470;

    const Unk_239a418_Type* vf_type() override;

    s32 field_348 = -1;
};
static_assert(sizeof(Unk_23d8950) == 0x350, "Unk_23d8950");
PKMN_OFFSET_ASSERT(Unk_23d8950, field_348, 0x348);

// Created by 0x7100bd9210
class Unk_23d56b8 : public Unk_23d4470 {
public:
    using Unk_23d4470::Unk_23d4470;

    const Unk_239a418_Type* vf_type() override;

    u64 field_348 = 0;
    u64 field_350 = 0;
    u64 field_358 = 0;
    u64 field_360 = 0;
    u64 field_368 = 0;
    u64 field_370 = 0;
    u64 field_378 = 0;
    u32 field_380 = 0;
};
static_assert(sizeof(Unk_23d56b8) == 0x390, "Unk_23d56b8");
PKMN_OFFSET_ASSERT(Unk_23d56b8, field_348, 0x348);
PKMN_OFFSET_ASSERT(Unk_23d56b8, field_350, 0x350);
PKMN_OFFSET_ASSERT(Unk_23d56b8, field_358, 0x358);
PKMN_OFFSET_ASSERT(Unk_23d56b8, field_360, 0x360);
PKMN_OFFSET_ASSERT(Unk_23d56b8, field_368, 0x368);
PKMN_OFFSET_ASSERT(Unk_23d56b8, field_370, 0x370);
PKMN_OFFSET_ASSERT(Unk_23d56b8, field_378, 0x378);
PKMN_OFFSET_ASSERT(Unk_23d56b8, field_380, 0x380);

// Created by 0x7100bd9f60
class Unk_23d5778 : public Unk_23d4470 {
public:
    using Unk_23d4470::Unk_23d4470;

    const Unk_239a418_Type* vf_type() override;

    u64 field_348 = 0;
};
static_assert(sizeof(Unk_23d5778) == 0x350, "Unk_23d5778");
PKMN_OFFSET_ASSERT(Unk_23d5778, field_348, 0x348);

// Created by 0x7100bda870
class Unk_23d5838 : public Unk_23d4470 {
public:
    using Unk_23d4470::Unk_23d4470;

    const Unk_239a418_Type* vf_type() override;

    u64 field_348 = 0;
    u64 field_350 = 0;
    u64 field_358 = 0;
};
static_assert(sizeof(Unk_23d5838) == 0x360, "Unk_23d5838");
PKMN_OFFSET_ASSERT(Unk_23d5838, field_348, 0x348);
PKMN_OFFSET_ASSERT(Unk_23d5838, field_350, 0x350);
PKMN_OFFSET_ASSERT(Unk_23d5838, field_358, 0x358);

// Created by 0x7100bdb500
class Unk_23d58f8 : public Unk_23d4470 {
public:
    using Unk_23d4470::Unk_23d4470;

    const Unk_239a418_Type* vf_type() override;

    u64 field_348 = 0;
};
static_assert(sizeof(Unk_23d58f8) == 0x350, "Unk_23d58f8");
PKMN_OFFSET_ASSERT(Unk_23d58f8, field_348, 0x348);

// Created by 0x7100bdbe10
class Unk_23d59b8 : public Unk_23d4470 {
public:
    using Unk_23d4470::Unk_23d4470;

    const Unk_239a418_Type* vf_type() override;

    u64 field_348 = 0;
    u8 field_350 = 0;
};
static_assert(sizeof(Unk_23d59b8) == 0x360, "Unk_23d59b8");
PKMN_OFFSET_ASSERT(Unk_23d59b8, field_348, 0x348);
PKMN_OFFSET_ASSERT(Unk_23d59b8, field_350, 0x350);

// Created by 0x7100bdc7d0
class Unk_23d5a78 : public Unk_23d4470 {
public:
    using Unk_23d4470::Unk_23d4470;

    const Unk_239a418_Type* vf_type() override;

    u64 field_348 = 0;
};
static_assert(sizeof(Unk_23d5a78) == 0x350, "Unk_23d5a78");
PKMN_OFFSET_ASSERT(Unk_23d5a78, field_348, 0x348);

// Created by 0x7100bdd0e0
class Unk_23d5b38 : public Unk_23d4470 {
public:
    using Unk_23d4470::Unk_23d4470;

    const Unk_239a418_Type* vf_type() override;

    u8 field_348 = 0;
};
static_assert(sizeof(Unk_23d5b38) == 0x350, "Unk_23d5b38");
PKMN_OFFSET_ASSERT(Unk_23d5b38, field_348, 0x348);

// Created by 0x7100bdd630
class Unk_23d5bf8 : public Unk_23d4470 {
public:
    using Unk_23d4470::Unk_23d4470;

    const Unk_239a418_Type* vf_type() override;

    u8 _348[0x8];
    float32x4_t field_350 = {1.0f, 1.0f, 1.0f, 0.0f};
    u64 field_360 = 0;
    u64 field_368 = 0;
    u64 field_370 = 0;
    u64 field_378 = 0;
    u64 field_380 = 0;
    u64 field_388 = 0;
    u16 field_390 = 0;
};
static_assert(sizeof(Unk_23d5bf8) == 0x3a0, "Unk_23d5bf8");
PKMN_OFFSET_ASSERT(Unk_23d5bf8, field_350, 0x350);
PKMN_OFFSET_ASSERT(Unk_23d5bf8, field_360, 0x360);
PKMN_OFFSET_ASSERT(Unk_23d5bf8, field_368, 0x368);
PKMN_OFFSET_ASSERT(Unk_23d5bf8, field_370, 0x370);
PKMN_OFFSET_ASSERT(Unk_23d5bf8, field_378, 0x378);
PKMN_OFFSET_ASSERT(Unk_23d5bf8, field_380, 0x380);
PKMN_OFFSET_ASSERT(Unk_23d5bf8, field_388, 0x388);
PKMN_OFFSET_ASSERT(Unk_23d5bf8, field_390, 0x390);

// Created by 0x7100bde090
class Unk_23d5cb8 : public Unk_23d4470 {
public:
    using Unk_23d4470::Unk_23d4470;

    const Unk_239a418_Type* vf_type() override;

    s32 field_348 = -1;
};
static_assert(sizeof(Unk_23d5cb8) == 0x350, "Unk_23d5cb8");
PKMN_OFFSET_ASSERT(Unk_23d5cb8, field_348, 0x348);

// Created by 0x7100bdedb0
class Unk_23d5d78 : public Unk_23d4470 {
public:
    using Unk_23d4470::Unk_23d4470;

    const Unk_239a418_Type* vf_type() override;

    u32 field_348 = 0;
};
static_assert(sizeof(Unk_23d5d78) == 0x350, "Unk_23d5d78");
PKMN_OFFSET_ASSERT(Unk_23d5d78, field_348, 0x348);

// Created by 0x7100bdf410
class Unk_23d5e38 : public Unk_23d4470 {
public:
    using Unk_23d4470::Unk_23d4470;

    const Unk_239a418_Type* vf_type() override;

    u64 field_348 = 0xcbf29ce484222645;  // the hash (64-bit FNV-1a) of ""
};
static_assert(sizeof(Unk_23d5e38) == 0x350, "Unk_23d5e38");
PKMN_OFFSET_ASSERT(Unk_23d5e38, field_348, 0x348);

// Created by 0x7100be0ca0
class Unk_23d61f8 : public Unk_23d4470 {
public:
    using Unk_23d4470::Unk_23d4470;

    const Unk_239a418_Type* vf_type() override;

    u32 field_348 = 0;
    u32 field_34c = -1;
};
static_assert(sizeof(Unk_23d61f8) == 0x350, "Unk_23d61f8");
PKMN_OFFSET_ASSERT(Unk_23d61f8, field_348, 0x348);
PKMN_OFFSET_ASSERT(Unk_23d61f8, field_34c, 0x34c);

// Created by 0x7100be14a0
class Unk_23d6378 : public Unk_23d4470 {
public:
    using Unk_23d4470::Unk_23d4470;

    const Unk_239a418_Type* vf_type() override;

    u16 field_348 = 0x101;
};
static_assert(sizeof(Unk_23d6378) == 0x350, "Unk_23d6378");
PKMN_OFFSET_ASSERT(Unk_23d6378, field_348, 0x348);

// Created by 0x7100be2090
class Unk_23d95d0 : public Unk_23d4470 {
public:
    using Unk_23d4470::Unk_23d4470;

    const Unk_239a418_Type* vf_type() override;

    u64 field_348 = 0;
    u8 field_350 = 0;
};
static_assert(sizeof(Unk_23d95d0) == 0x360, "Unk_23d95d0");
PKMN_OFFSET_ASSERT(Unk_23d95d0, field_348, 0x348);
PKMN_OFFSET_ASSERT(Unk_23d95d0, field_350, 0x350);

// Created by 0x7100be21a0
class Unk_23d8a10 : public Unk_c02310 {
public:
    using Unk_c02310::Unk_c02310;

    const Unk_239a418_Type* vf_type() override;

    u32 field_380 = 0;
    u64 field_388 = 0;
};
static_assert(sizeof(Unk_23d8a10) == 0x390, "Unk_23d8a10");
PKMN_OFFSET_ASSERT(Unk_23d8a10, field_380, 0x380);
PKMN_OFFSET_ASSERT(Unk_23d8a10, field_388, 0x388);

// Created by 0x7100be22e0
class Unk_23d7ad8 : public Unk_c02310 {
public:
    using Unk_c02310::Unk_c02310;

    const Unk_239a418_Type* vf_type() override;

    u32 field_380 = 0;
    u64 field_388 = 0;
};
static_assert(sizeof(Unk_23d7ad8) == 0x390, "Unk_23d7ad8");
PKMN_OFFSET_ASSERT(Unk_23d7ad8, field_380, 0x380);
PKMN_OFFSET_ASSERT(Unk_23d7ad8, field_388, 0x388);

// Created by 0x7100be2420
class Unk_23d70f0 : public Unk_23d4470 {
public:
    using Unk_23d4470::Unk_23d4470;

    const Unk_239a418_Type* vf_type() override;

    u8 _348[0x20];
    s32 field_368 = -1;
    u8 _36c[0x4];
    u64 field_370 = 0;
    u64 field_378 = 0;
    u64 field_380 = 0;
    u64 field_388 = 0;
};
static_assert(sizeof(Unk_23d70f0) == 0x390, "Unk_23d70f0");
PKMN_OFFSET_ASSERT(Unk_23d70f0, field_368, 0x368);
PKMN_OFFSET_ASSERT(Unk_23d70f0, field_370, 0x370);
PKMN_OFFSET_ASSERT(Unk_23d70f0, field_378, 0x378);
PKMN_OFFSET_ASSERT(Unk_23d70f0, field_380, 0x380);
PKMN_OFFSET_ASSERT(Unk_23d70f0, field_388, 0x388);

// Created by 0x7100be2640
class Unk_23d6438 : public Unk_23d4470 {
public:
    using Unk_23d4470::Unk_23d4470;

    const Unk_239a418_Type* vf_type() override;

    u64 field_348 = 0;
    u8 _350[0x20];
};
static_assert(sizeof(Unk_23d6438) == 0x370, "Unk_23d6438");
PKMN_OFFSET_ASSERT(Unk_23d6438, field_348, 0x348);

// Created by 0x7100be3b10
class Unk_23d64f8 : public Unk_23d4470 {
public:
    using Unk_23d4470::Unk_23d4470;

    const Unk_239a418_Type* vf_type() override;

    u32 field_348 = 0;
    u8 field_34c = 0;
    u8 _34d[0x13];
};
static_assert(sizeof(Unk_23d64f8) == 0x360, "Unk_23d64f8");
PKMN_OFFSET_ASSERT(Unk_23d64f8, field_348, 0x348);
PKMN_OFFSET_ASSERT(Unk_23d64f8, field_34c, 0x34c);

// Created by 0x7100be4b40
class Unk_23d6eb0 : public Unk_23d4470 {
public:
    using Unk_23d4470::Unk_23d4470;
    const Unk_239a418_Type* vf_type() override;
    u64 field_348 = 0;
    Unk_23f4660_Name field_350;
    Unk_23c4840 field_380;
    u64 field_490 = 0;
    u64 field_498 = 0;
    u32 field_4a0 = 0x7f;
    u8 _4a4[0x2c];
    u32 field_4d0 = 0;
    u8 _4d4[0x1c];
    f32 field_4f0 = 1.0f;
};
static_assert(sizeof(Unk_23d6eb0) == 0x500, "Unk_23d6eb0");
PKMN_OFFSET_ASSERT(Unk_23d6eb0, field_348, 0x348);
PKMN_OFFSET_ASSERT(Unk_23d6eb0, field_350, 0x350);
PKMN_OFFSET_ASSERT(Unk_23d6eb0, field_380, 0x380);
PKMN_OFFSET_ASSERT(Unk_23d6eb0, field_490, 0x490);
PKMN_OFFSET_ASSERT(Unk_23d6eb0, field_498, 0x498);
PKMN_OFFSET_ASSERT(Unk_23d6eb0, field_4a0, 0x4a0);
PKMN_OFFSET_ASSERT(Unk_23d6eb0, field_4d0, 0x4d0);
PKMN_OFFSET_ASSERT(Unk_23d6eb0, field_4f0, 0x4f0);

// Created by 0x7100be4cd0
class Unk_23d8cf0 : public Unk_23d4470 {
public:
    using Unk_23d4470::Unk_23d4470;

    const Unk_239a418_Type* vf_type() override;

    u32 field_348 = 0;
};
static_assert(sizeof(Unk_23d8cf0) == 0x350, "Unk_23d8cf0");
PKMN_OFFSET_ASSERT(Unk_23d8cf0, field_348, 0x348);
// Until the switch (0x7100bc27d0) is written, the Creators it calls are instantiated here.
template struct Unk_bc27d0_Creator<Unk_23d6a30>;  // 0x7100bc8af0
template struct Unk_bc27d0_Creator<Unk_23d7e00>;  // 0x7100bc8cb0
template struct Unk_bc27d0_Creator<Unk_23d8e98>;  // 0x7100bc8de0
template struct Unk_bc27d0_Creator<Unk_23d8db0>;  // 0x7100bc8f40
template struct Unk_bc27d0_Creator<Unk_23d9048>;  // 0x7100bc9080
template struct Unk_bc27d0_Creator<Unk_23d7360>;  // 0x7100bc9230
template struct Unk_bc27d0_Creator<Unk_23d87b8>;  // 0x7100bc9460
template struct Unk_bc27d0_Creator<Unk_23d8278>;  // 0x7100bc9620
template struct Unk_bc27d0_Creator<Unk_23d84b8>;  // 0x7100bc9730
template struct Unk_bc27d0_Creator<Unk_23d86f8>;  // 0x7100bc9840
template struct Unk_bc27d0_Creator<Unk_23d8638>;  // 0x7100bc9950
template struct Unk_bc27d0_Creator<Unk_23d43b0>;  // 0x7100bc9a60
template struct Unk_bc27d0_Creator<Unk_23d7030>;  // 0x7100bca070
template struct Unk_bc27d0_Creator<Unk_23d45f0>;  // 0x7100bcaaa0
template struct Unk_bc27d0_Creator<Unk_23d6728>;  // 0x7100bcb1c0
template struct Unk_bc27d0_Creator<Unk_23d46b0>;  // 0x7100bcb2e0
template struct Unk_bc27d0_Creator<Unk_23d8338>;  // 0x7100bcb970
template struct Unk_bc27d0_Creator<Unk_23d4830>;  // 0x7100bcd170
template struct Unk_bc27d0_Creator<Unk_23d48f0>;  // 0x7100bcd730
template struct Unk_bc27d0_Creator<Unk_23d83f8>;  // 0x7100bcf620
template struct Unk_bc27d0_Creator<Unk_23d8578>;  // 0x7100bcf740
template struct Unk_bc27d0_Creator<Unk_23d6af0>;  // 0x7100bcf850
template struct Unk_bc27d0_Creator<Unk_23d94f0>;  // 0x7100bcf960
template struct Unk_bc27d0_Creator<Unk_23d4b50>;  // 0x7100bcfb80
template struct Unk_bc27d0_Creator<Unk_23d7778>;  // 0x7100bd05a0
template struct Unk_bc27d0_Creator<Unk_23d6bb0>;  // 0x7100bd0a30
template struct Unk_bc27d0_Creator<Unk_23d8038>;  // 0x7100bd0bb0
template struct Unk_bc27d0_Creator<Unk_23d4cf8>;  // 0x7100bd0d30
template struct Unk_bc27d0_Creator<Unk_23d72a0>;  // 0x7100bd11b0
template struct Unk_bc27d0_Creator<Unk_23d4e78>;  // 0x7100bd1750
template struct Unk_bc27d0_Creator<Unk_23d4f38>;  // 0x7100bd1db0
template struct Unk_bc27d0_Creator<Unk_23d6c70>;  // 0x7100bd24a0
template struct Unk_bc27d0_Creator<Unk_23d81b8>;  // 0x7100bd2630
template struct Unk_bc27d0_Creator<Unk_23d68b0>;  // 0x7100bd2740
template struct Unk_bc27d0_Creator<Unk_23d9130>;  // 0x7100bd2850
template struct Unk_bc27d0_Creator<Unk_23d71e0>;  // 0x7100bd2960
template struct Unk_bc27d0_Creator<Unk_23d7950>;  // 0x7100bd2aa0
template struct Unk_bc27d0_Creator<Unk_23d7a10>;  // 0x7100bd2be0
template struct Unk_bc27d0_Creator<Unk_23d8f80>;  // 0x7100bd2d00
template struct Unk_bc27d0_Creator<Unk_23d7f78>;  // 0x7100bd2e40
template struct Unk_bc27d0_Creator<Unk_23d9430>;  // 0x7100bd2f80
template struct Unk_bc27d0_Creator<Unk_23d92b0>;  // 0x7100bd31a0
template struct Unk_bc27d0_Creator<Unk_23d4ff8>;  // 0x7100bd32d0
template struct Unk_bc27d0_Creator<Unk_23d50b8>;  // 0x7100bd3620
template struct Unk_bc27d0_Creator<Unk_23d5178>;  // 0x7100bd4c40
template struct Unk_bc27d0_Creator<Unk_23d5238>;  // 0x7100bd5f50
template struct Unk_bc27d0_Creator<Unk_23d91f0>;  // 0x7100bd6550
template struct Unk_bc27d0_Creator<Unk_23d80f8>;  // 0x7100bd66c0
template struct Unk_bc27d0_Creator<Unk_23d6d30>;  // 0x7100bd6830
template struct Unk_bc27d0_Creator<Unk_23d6970>;  // 0x7100bd6960
template struct Unk_bc27d0_Creator<Unk_23d75f8>;  // 0x7100bd6aa0
template struct Unk_bc27d0_Creator<Unk_23d6f70>;  // 0x7100bd6bd0
template struct Unk_bc27d0_Creator<Unk_23d76b8>;  // 0x7100bd6d00
template struct Unk_bc27d0_Creator<Unk_23d52f8>;  // 0x7100bd7030
template struct Unk_bc27d0_Creator<Unk_23d53b8>;  // 0x7100bd77a0
template struct Unk_bc27d0_Creator<Unk_23d5478>;  // 0x7100bd7cc0
template struct Unk_bc27d0_Creator<Unk_23d5538>;  // 0x7100bd8320
template struct Unk_bc27d0_Creator<Unk_23d67f0>;  // 0x7100bd8a40
template struct Unk_bc27d0_Creator<Unk_23d55f8>;  // 0x7100bd8b70
template struct Unk_bc27d0_Creator<Unk_23d8950>;  // 0x7100bd9100
template struct Unk_bc27d0_Creator<Unk_23d56b8>;  // 0x7100bd9210
template struct Unk_bc27d0_Creator<Unk_23d5778>;  // 0x7100bd9f60
template struct Unk_bc27d0_Creator<Unk_23d5838>;  // 0x7100bda870
template struct Unk_bc27d0_Creator<Unk_23d58f8>;  // 0x7100bdb500
template struct Unk_bc27d0_Creator<Unk_23d59b8>;  // 0x7100bdbe10
template struct Unk_bc27d0_Creator<Unk_23d5a78>;  // 0x7100bdc7d0
template struct Unk_bc27d0_Creator<Unk_23d5b38>;  // 0x7100bdd0e0
template struct Unk_bc27d0_Creator<Unk_23d5bf8>;  // 0x7100bdd630
template struct Unk_bc27d0_Creator<Unk_23d5cb8>;  // 0x7100bde090
template struct Unk_bc27d0_Creator<Unk_23d5d78>;  // 0x7100bdedb0
template struct Unk_bc27d0_Creator<Unk_23d5e38>;  // 0x7100bdf410
template struct Unk_bc27d0_Creator<Unk_23d61f8>;  // 0x7100be0ca0
template struct Unk_bc27d0_Creator<Unk_23d6378>;  // 0x7100be14a0
template struct Unk_bc27d0_Creator<Unk_23d95d0>;  // 0x7100be2090
template struct Unk_bc27d0_Creator<Unk_23d8a10>;  // 0x7100be21a0
template struct Unk_bc27d0_Creator<Unk_23d7ad8>;  // 0x7100be22e0
template struct Unk_bc27d0_Creator<Unk_23d70f0>;  // 0x7100be2420
template struct Unk_bc27d0_Creator<Unk_23d6438>;  // 0x7100be2640
template struct Unk_bc27d0_Creator<Unk_23d64f8>;  // 0x7100be3b10
template struct Unk_bc27d0_Creator<Unk_23d6eb0>;  // 0x7100be4b40
template struct Unk_bc27d0_Creator<Unk_23d8cf0>;  // 0x7100be4cd0
