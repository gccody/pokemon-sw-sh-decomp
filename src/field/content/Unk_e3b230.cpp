// Scope: common
// The resource of bin/test/nest_hole/net_nest_hole_dai_encount.bin (Unk_23f1508,
// on Unk_23f5d00): its vf5, the lookups in its tables and its file name's
// static initialiser. Placeholder names: rename once the classes are known.
#include <types.h>

#include "field/content/Unk_e3b230.h"
#include "pkmn/version.h"

class Unk_23f1508 : public Unk_23f5d00 {
public:
    ~Unk_23f1508() override;
    u8* vf5() override;
    Unk_23f5d00_Member<void> field_180;
};
PKMN_OFFSET_ASSERT(Unk_23f1508, field_180, 0x180);

extern Unk_e3b230_Name Unk_27dfe70 __attribute__((visibility("hidden")));

// 0x7100e3b260
u8* Unk_23f1508::vf5() {
    return reinterpret_cast<u8*>(&Unk_27dfe70);
}

// 0x7100e3b270 (Shield 0x7100e3b2a0): the entry of the root's first field for
// this game (u32 field 6: 1 in Sword, 2 in Shield).
const Unk_Table* Unk_e3b270(void* self) {
    const u8* buffer = Unk_ead710(self);
    if (Unk_ead710(self) == nullptr) {
        return nullptr;
    }
    const Unk_e3b230_Tables* tables =
        Unk_e3b230_GetRequired<Unk_e3b230_Tables>(Unk_e3b230_Root(buffer), 4);
    Unk_e3b230_Tables::Iterator it = tables->begin();
    Unk_e3b230_Tables::Iterator end = tables->end();
    for (; it != end; ++it) {
        if ((*it)->Get<u32>(6, 0) == PKMN_SW_SH(1, 2)) {
            break;
        }
    }
    if (it == end) {
        return nullptr;
    }
    return *it;
}

// 0x7100e3b390
const Unk_Table* Unk_e3b390(u64, void* table, u32 index) {
    return Unk_e3b230_GetAt(static_cast<const Unk_Table*>(table), 8, index);
}

// 0x7100e3b3f0
void Unk_e3b3f0_init() {
    Unk_27dfe70.field_0 = 0xfeb8bc241c378a04;
    Unk_27dfe70.field_8 = "bin/test/nest_hole/net_nest_hole_dai_encount.bin";
    Unk_27dfe70.field_10 = 0x30;
    Unk_27dfe70.field_18 = nullptr;
    __cxa_atexit(reinterpret_cast<void (*)(void*)>(Unk_611220_call), &Unk_27dfe70, &__dso_handle);
}
