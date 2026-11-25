// Scope: common
// What sets up the two listener lists (Unk_102ac40.h, Unk_102b460.h) and adds
// a listener to each: it calls their vf6 directly. Placeholder names: rename
// once the classes are known.
#include <types.h>

#include "network/net_contents/source/trade/box/box_sync_state/Unk_102ac40.h"
#include "network/net_contents/source/trade/box/box_sync_state/Unk_102b460.h"

struct Unk_1028e70 {
    u8 _0[0x20];
    Unk_2409118* field_20;
    Unk_24092b8* field_28;
    u64 field_30;
};
PKMN_OFFSET_ASSERT(Unk_1028e70, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_1028e70, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_1028e70, field_30, 0x30);

void Unk_10285c0(void*);

// 0x7101028e70
void Unk_1028e70_call(Unk_1028e70* self, Unk_102bf70* listener, Unk_102c130* listener2) {
    Unk_10285c0(self);
    self->field_20->Unk_2409118::vf6(listener);
    self->field_28->Unk_24092b8::vf6(listener2);
    self->field_30 = 1;
}
