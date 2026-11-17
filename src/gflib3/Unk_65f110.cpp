// Scope: common
//
// A static object of gflib3's memory code, created on first use. Its TU is
// not the heap globals' (src/gflib3/Unk_65d670.cpp): its guard and object
// (0x7102778768) are far from theirs. It sits with the TLSF pool resource
// (lib/gflib3/src/mem/tlsf_pool_resource.cpp) in the code.
#include "gflib3/Unk_5cf870.h"

// A static object (0x7102778770) that Unk_65f110 returns, created on first use.
class Unk_2778770 {
public:
    Unk_2778770() {
        Unk_5cf8c0(&field_4, nn::os::EventClearMode(1), false);
        field_10 = nullptr;
    }
    ~Unk_2778770() { Unk_5cf8d0(&field_4); }

    u32 field_0;
    nn::os::LightEventType field_4;
    void* field_10;
};
PKMN_OFFSET_ASSERT(Unk_2778770, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_2778770, field_10, 0x10);

// 0x710065f110
Unk_2778770* Unk_65f110() {
    static Unk_2778770 instance;
    return &instance;
}
