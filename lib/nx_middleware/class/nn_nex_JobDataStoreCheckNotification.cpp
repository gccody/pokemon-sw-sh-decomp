// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N2nn3nex29JobDataStoreCheckNotificationE
#include <types.h>

struct Unk_157f0b0 {
    u8 _0[0x298];
    u32 field_298;
};
PKMN_OFFSET_ASSERT(Unk_157f0b0, field_298, 0x298);

struct Unk_1591c20_arg4 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1591c20_arg4, field_0, 0x0);

struct Unk_157f0c0 {
    u8 _0[0x1f8];
    u32 field_1f8;
};
PKMN_OFFSET_ASSERT(Unk_157f0c0, field_1f8, 0x1f8);

namespace nn {
namespace nex {
class JobDataStoreCheckNotification {
public:
    void vf15(u32 /*unused*/, u32 arg2);
    u64 vf3(u32 /*unused*/, u32 /*unused*/, u32 /*unused*/, Unk_1591c20_arg4* arg4);
    void vf4(u32 /*unused*/, u32 arg2);
};
}  // namespace nex
}  // namespace nn

// 0x710157f0b0
void nn::nex::JobDataStoreCheckNotification::vf15(u32 /*unused*/, u32 arg2) {
    Unk_157f0b0* self = reinterpret_cast<Unk_157f0b0*>(this);
    self->field_298 = arg2;
}

// 0x710157f0c0
void nn::nex::JobDataStoreCheckNotification::vf4(u32 /*unused*/, u32 arg2) {
    Unk_157f0c0* self = reinterpret_cast<Unk_157f0c0*>(this);
    self->field_1f8 = arg2;
}

// 0x7101591c20
u64 nn::nex::JobDataStoreCheckNotification::vf3(u32 /*unused*/, u32 /*unused*/, u32 /*unused*/, Unk_1591c20_arg4* arg4) {
    arg4->field_0 = 1;
    return 0;
}
