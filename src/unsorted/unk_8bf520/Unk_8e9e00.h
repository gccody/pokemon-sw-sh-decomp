#pragma once
// The Battle Tower's views (vtable 0x71023bd130): five views of an app's
// frame, found by name, and the battle they show. The battle scene calls its
// functions with what Unk_95bb50 returns (battle/battle_scene/Unk_a38ab0.cpp),
// src/unsorted/leaf/Unk_987eb0.cpp with +0x2f8 of its object. Its
// destructors are in src/unsorted/virtual/Unk_8e4150.cpp. Placeholder names:
// rename once the class is known.
#include <types.h>

#include "battle/battle_logic/source/netwatch/Unk_8a9b50.h"
#include "contents/common/framework.h"

// The views it finds (their type getters are in src/unsorted/types).
class Unk_23bd220;  // "BossView"
class Unk_23bd6b8;  // "SpectatorViewName"
class Unk_23bd4b8;  // "CommonBGView"

// "RemainTimeView".
class Unk_23be058 : public Unk_23f4660 {};

// What the top view keeps at +0x5d0.
struct Unk_8ea550_Data {
    u8 _0[0x60];
    u32 field_60;
};
PKMN_OFFSET_ASSERT(Unk_8ea550_Data, field_60, 0x60);

// "TopView".
class Unk_23bda50 : public Unk_23f4660 {
public:
    Unk_8ea550_Data* field_5d0;
};
PKMN_OFFSET_ASSERT(Unk_23bda50, field_5d0, 0x5d0);

// What it gets the battle from. Its slots 267 and 275 are Unk_23b9048's
// signatures (battle/battle_logic/source/netwatch/Unk_8a9b50.h).
struct Unk_8ea2b0_Source {
    u8 _0[0x370];
    Unk_23b9048* field_370;
};
PKMN_OFFSET_ASSERT(Unk_8ea2b0_Source, field_370, 0x370);

class Unk_23bd130 {
public:
    virtual ~Unk_23bd130();
    virtual void vf2();

    bool Unk_8ea550();

    Unk_23f41d0* field_8;
    Unk_8ea2b0_Source* field_10;
    u8 _18[8];
    Unk_23bda50* field_20;
    Unk_23bd220* field_28;
    Unk_23be058* field_30;
    Unk_23bd6b8* field_38;
    Unk_23bd4b8* field_40;
};
PKMN_OFFSET_ASSERT(Unk_23bd130, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_23bd130, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_23bd130, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_23bd130, field_40, 0x40);

// The flags the views' setters (Unk_8fa9a0_call/Unk_8faa60 for the
// spectator view, Unk_9059f0_call/Unk_905af0 for the top view) take.
struct Unk_8faa60_Flags {
    bool field_0;
    bool field_1;
    bool field_2;
};
PKMN_SIZE_ASSERT(Unk_8faa60_Flags, 3);

struct Unk_905af0_Flags {
    bool field_0;
    bool field_1;
    bool field_2;
    bool field_3;
};
PKMN_SIZE_ASSERT(Unk_905af0_Flags, 4);
