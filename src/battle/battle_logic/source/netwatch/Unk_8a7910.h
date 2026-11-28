#pragma once
// A battle data exchange with the net peer (Unk_8a7910.cpp). Placeholder
// names: rename once the classes are known.
#include <types.h>

#include "battle/battle_logic/source/net/Unk_8974a0.h"

// A packet (vtable 0x71023b7ea8): a header of four 16-bit fields at +0x8
// (the last 0x33 when it's reset, 0x7100892380), the body's size among them
// (+0xc), then the body. src/unsorted/virtual/Unk_8923e0.cpp declares it
// without its fields.
class Unk_23b7ea8 {
public:
    Unk_23b7ea8();
    virtual ~Unk_23b7ea8();

    u16 field_8;
    u16 field_a;
    u16 field_c;  // the body's size
    u16 field_e;
    u8 field_10[0x2718];
};
PKMN_SIZE_ASSERT(Unk_23b7ea8, 0x2728);
PKMN_OFFSET_ASSERT(Unk_23b7ea8, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_23b7ea8, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_23b7ea8, field_10, 0x10);

// The exchange: the peer (none in a local battle), the packet to send, the
// reply, and its state (0 idle, 1 to send, 3 sent, 4 replied).
class Unk_8a7ab0_Handle {
public:
    Unk_8a7ab0_Handle(u8 clientId, bool remote, const Unk_239a418_Ref<Unk_23b7ee8>& peer);
    ~Unk_8a7ab0_Handle();

    Unk_239a418_Ref2<Unk_23b7ee8> field_0;  // the peer, none in a local battle
    Unk_23b7ea8 field_8;                    // the request
    Unk_23b7ea8 field_2730;                 // the reply
    u8 field_4e58;
    u8 field_4e59;    // the client
    u32 field_4e5c;   // the state
    bool field_4e60;  // a reply came
    bool field_4e61;  // talks to the peer
    u8 field_4e62;
};
PKMN_SIZE_ASSERT(Unk_8a7ab0_Handle, 0x4e68);
PKMN_OFFSET_ASSERT(Unk_8a7ab0_Handle, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_8a7ab0_Handle, field_2730, 0x2730);
PKMN_OFFSET_ASSERT(Unk_8a7ab0_Handle, field_4e58, 0x4e58);
PKMN_OFFSET_ASSERT(Unk_8a7ab0_Handle, field_4e59, 0x4e59);
PKMN_OFFSET_ASSERT(Unk_8a7ab0_Handle, field_4e5c, 0x4e5c);
PKMN_OFFSET_ASSERT(Unk_8a7ab0_Handle, field_4e60, 0x4e60);
PKMN_OFFSET_ASSERT(Unk_8a7ab0_Handle, field_4e61, 0x4e61);
PKMN_OFFSET_ASSERT(Unk_8a7ab0_Handle, field_4e62, 0x4e62);
