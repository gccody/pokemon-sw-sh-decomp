#pragma once
// Two tables of battle sequence functions (game/battle_scene): each maps 385
// 64-bit hashes, the same in both, to a function, in an unordered_map whose
// memory comes from the owner's allocator (+0xb8). Unk_23c4ef0 (vtable
// 0x71023c4ef0) holds an Unk_23c4f18 (vtable 0x71023c4f18) at +0x20. Their
// constructors fill the maps with 385 inlined emplaces each (0x71009be950 and
// 0x71009fd0e0, 239 KB apiece). Placeholder names: rename once the classes
// are known.
#include <unordered_map>

#include "battle/battle_scene/Unk_23c4ef0_Owner.h"
#include "unsorted/Unk_23f5d00.h"
#include "unsorted/Unk_2771620.h"

// A sequence function: called with vf2's first argument, the owner and the hash.
using Unk_23c4ef0_Func = void (*)(void*, Unk_23c4ef0_Owner*, const u64*);
using Unk_23c4ef0_Map =
    std::unordered_map<u64,
                       Unk_23c4ef0_Func,
                       std::hash<u64>,
                       std::equal_to<u64>,
                       Unk_2771620_Allocator<std::pair<const u64, Unk_23c4ef0_Func>>>;
static_assert(sizeof(Unk_23c4ef0_Map) == 0x58, "Unk_23c4ef0_Map");

// The table at +0x20 of Unk_23c4ef0 (vtable 0x71023c4f18).
class Unk_23c4f18 {
public:
    explicit Unk_23c4f18(Unk_23c4ef0_Owner* owner);
    virtual ~Unk_23c4f18();
    virtual void vf2(void* arg1, const u64* hash, bool arg3);

    Unk_23c4ef0_Owner* field_8;
    std::unique_ptr<Unk_23c4ef0_Map, Unk_23f4660_Deleter> field_10;
};
static_assert(sizeof(Unk_23c4f18) == 0x30, "Unk_23c4f18");
PKMN_OFFSET_ASSERT(Unk_23c4f18, field_10, 0x10);

// The outer table (vtable 0x71023c4ef0), 0x190 bytes. vf2 (0x71009f93a0)
// handles some hashes itself and looks the others up; field_71 turns it off.
class Unk_23c4ef0 {
public:
    explicit Unk_23c4ef0(Unk_23c4ef0_Owner* owner);
    virtual ~Unk_23c4ef0();
    virtual void vf2(void* arg1, const u64* hash, bool arg3);

    Unk_23c4ef0_Owner* field_8;
    Unk_239a418_Ref<Unk_239a418> field_10;
    Unk_239a418_Ref<Unk_239a418> field_18;
    Unk_23c4f18 field_20;
    std::unique_ptr<Unk_23c4ef0_Map, Unk_23f4660_Deleter> field_50;
    u8 field_70;
    u8 field_71;
    u64 field_78;
    Unk_236d618 field_80;
};
static_assert(sizeof(Unk_23c4ef0) == 0x190, "Unk_23c4ef0");
PKMN_OFFSET_ASSERT(Unk_23c4ef0, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_23c4ef0, field_50, 0x50);
PKMN_OFFSET_ASSERT(Unk_23c4ef0, field_70, 0x70);
PKMN_OFFSET_ASSERT(Unk_23c4ef0, field_80, 0x80);
