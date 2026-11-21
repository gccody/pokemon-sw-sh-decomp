// Scope: common
// Unk_HashListBare::Reserve for three kinds of item. Placeholder names.
#include "Unk_HashList.h"

struct Unk_378d40_Item {
    u8 _0[0x10];
    u32 field_10;  // key
    Unk_378d40_Item* field_18;  // next
};
struct Unk_378d40_Policy {
    static u32 Key(Unk_378d40_Item* item) { return item->field_10; }
    static Unk_378d40_Item*& Next(Unk_378d40_Item* item) { return item->field_18; }
};

struct Unk_3900a0_Item {
    u8 _0[0x4c];
    u32 field_4c;  // key
    u8 _50[0x18];
    Unk_3900a0_Item* field_68;  // next
};
struct Unk_3900a0_Policy {
    static u32 Key(Unk_3900a0_Item* item) { return item->field_4c; }
    static Unk_3900a0_Item*& Next(Unk_3900a0_Item* item) { return item->field_68; }
};

struct Unk_3a1490_Item {
    u32 field_0;  // key
    Unk_3a1490_Item* field_8;  // next
};
struct Unk_3a1490_Policy {
    static u32 Key(Unk_3a1490_Item* item) { return item->field_0; }
    static Unk_3a1490_Item*& Next(Unk_3a1490_Item* item) { return item->field_8; }
};

// The key of these items is two numbers.
struct Unk_3a3d40_Item {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    Unk_3a3d40_Item* field_10;  // next
};
struct Unk_3a3d40_Policy {
    static u32 Key(Unk_3a3d40_Item* item) { return item->field_0 + item->field_8; }
    static Unk_3a3d40_Item*& Next(Unk_3a3d40_Item* item) { return item->field_10; }
};

// 0x7100378d40
template u32 Unk_HashListBare<Unk_378d40_Item, Unk_378d40_Policy>::Reserve(u32);
// 0x71003900a0
template u32 Unk_HashListBare<Unk_3900a0_Item, Unk_3900a0_Policy>::Reserve(u32);
// 0x71003a1490
template u32 Unk_HashListBare<Unk_3a1490_Item, Unk_3a1490_Policy>::Reserve(u32);
// 0x71003a3d40
template u32 Unk_HashListBare<Unk_3a3d40_Item, Unk_3a3d40_Policy>::Reserve(u32);

struct Unk_399620_Item {
    Unk_399620_Item* field_0;  // next
    u32 field_8;  // key
};
struct Unk_399620_Policy {
    static u32 Key(Unk_399620_Item* item) { return item->field_8; }
    static Unk_399620_Item*& Next(Unk_399620_Item* item) { return item->field_0; }
};

// 0x7100399620
template u32 Unk_HashList<Unk_399620_Item, Unk_399620_Policy>::Reserve(u32);
