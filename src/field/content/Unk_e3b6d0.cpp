// Scope: common
// The resource of bin/test/nest_hole/net_nest_hole_bonus_rewards.bin
// (Unk_23f15e8, on Unk_23f5d00): its vf5, the lookups in its tables and its
// file name's static initialiser. Placeholder names: rename once the classes
// are known.
#include <types.h>

#include "field/content/Unk_e3b230.h"

class Unk_23f15e8 : public Unk_23f5d00 {
public:
    Unk_23f15e8();
    ~Unk_23f15e8() override;
    u8* vf5() override;
    Unk_23f5d00_Member<void> field_180;
};
PKMN_OFFSET_ASSERT(Unk_23f15e8, field_180, 0x180);

extern Unk_e3b230_Name Unk_27dfec0 __attribute__((visibility("hidden")));

// 0x7100e3b6d0
Unk_23f15e8::Unk_23f15e8() {}

// 0x7100e3b7b0
u8* Unk_23f15e8::vf5() {
    return reinterpret_cast<u8*>(&Unk_27dfec0);
}

// 0x7100e3b7c0: the entry of the root's first field whose u64 field 4 is the key.
const Unk_Table* Unk_e3b7c0(void* self, void* key) {
    const u8* buffer = Unk_ead710(self);
    if (Unk_ead710(self) == nullptr) {
        return nullptr;
    }
    const Unk_e3b230_Tables* tables =
        Unk_e3b230_GetRequired<Unk_e3b230_Tables>(Unk_e3b230_Root(buffer), 4);
    for (const Unk_Table* entry : *tables) {
        if (*static_cast<const u64*>(key) == entry->Get<u64>(4, 0)) {
            return entry;
        }
    }
    return nullptr;
}

// 0x7100e3b8d0
const Unk_Table* Unk_e3b8d0(u64, void* table, u32 index) {
    return Unk_e3b230_GetAt(static_cast<const Unk_Table*>(table), 6, index);
}

// 0x7100e3b930
void Unk_e3b930_init() {
    Unk_27dfec0.field_0 = 0xb0ed7b9af8a29f27;
    Unk_27dfec0.field_8 = "bin/test/nest_hole/net_nest_hole_bonus_rewards.bin";
    Unk_27dfec0.field_10 = 0x32;
    Unk_27dfec0.field_18 = nullptr;
    __cxa_atexit(reinterpret_cast<void (*)(void*)>(Unk_611220_call), &Unk_27dfec0, &__dso_handle);
}
