#pragma once
// Unk_23c9ec8 (vtable 0x71023c9ec8), a class on Unk_23c9470
// (src/unsorted/Unk_23c9470.h) that holds a reference of its own at +0x848,
// in its base's tail padding: an Unk_2443e50 it makes itself (0x7100adaea0).
// Its destructor is in src/unsorted/Unk_ada660.cpp, its type getter in
// src/unsorted/types/Unk_ada760.cpp. Placeholder names: rename once the
// classes are known.
#include <cstring>

#include "unsorted/Unk_23c9470.h"
#include "unsorted/unk_8bf520/Unk_8c6550.h"

// A name of 0x64 characters, copied whole (Unk_ec3340 and Unk_2443e50's
// description take one).
struct Unk_ec3340_Name {
    Unk_ec3340_Name() : str() {}
    explicit Unk_ec3340_Name(const char* name) : str() { std::strcpy(str, name); }

    char str[0x64];
};
static_assert(sizeof(Unk_ec3340_Name) == 0x64, "Unk_ec3340_Name");

// What Unk_2443e50's constructor (0x71014d8c20) is given.
struct Unk_2443e50_Desc {
    Unk_239a418_Allocator* field_0 = nullptr;
    Unk_239a418_Ref<Unk_239a418> field_8;
    Unk_239a418_Ref<Unk_239a418> field_10;
    u32 field_18 = 3;
    u64 field_20[7] = {};
    Unk_ec3340_Name field_58;
    bool field_bc = true;
};
static_assert(sizeof(Unk_2443e50_Desc) == 0xc0, "Unk_2443e50_Desc");
PKMN_OFFSET_ASSERT(Unk_2443e50_Desc, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_2443e50_Desc, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_2443e50_Desc, field_58, 0x58);
PKMN_OFFSET_ASSERT(Unk_2443e50_Desc, field_bc, 0xbc);

// The object on Unk_239a4c0 with vtable 0x7102443e50, 0x1a0 bytes (declared
// with its fields in src/unsorted/virtual/Unk_14c4b80.cpp, which has its key
// function).
class Unk_2443e50 : public Unk_239a4c0 {
public:
    explicit Unk_2443e50(const Unk_2443e50_Desc& desc);
    ~Unk_2443e50() override;

    u8 _54[0x14c];
};
static_assert(sizeof(Unk_2443e50) == 0x1a0, "Unk_2443e50");

class Unk_23c9ec8 : public Unk_23c9470 {
public:
    ~Unk_23c9ec8() override;
    const Unk_239a418_Type* vf_type() override;

    // Makes field_848 with the given name.
    void Unk_adaea0(const Unk_ec3340_Name& name);

    Unk_8c6550_Ref<Unk_2443e50> field_848;
};
static_assert(sizeof(Unk_23c9ec8) == 0x850, "Unk_23c9ec8");
static_assert(__builtin_offsetof(Unk_23c9ec8, field_848) == 0x848, "Unk_23c9ec8::field_848");
