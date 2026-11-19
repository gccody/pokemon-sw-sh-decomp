// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

void Unk_6c2bb0();

// 0x71006c2ba0
void Unk_6c2ba0_call() {
    Unk_6c2bb0();
}

namespace nn {
namespace os {
struct MutexType;
}
}  // namespace nn
struct Unk_6c3100_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_6c3100_arg1, field_0, 0x0);

struct Unk_6c3100 {
    u8 _0[0xd0];
    u64 field_d0;
    u8 field_d8;
};
PKMN_OFFSET_ASSERT(Unk_6c3100, field_d0, 0xd0);
PKMN_OFFSET_ASSERT(Unk_6c3100, field_d8, 0xd8);

namespace nn {
namespace os {
u64 LockMutex(MutexType*);
}
}  // namespace nn
namespace nn {
namespace os {
u64 UnlockMutex(MutexType*);
}
}  // namespace nn

// 0x71006c3100
void Unk_6c3100_call(Unk_6c3100* self, const Unk_6c3100_arg1* value) {
    nn::os::LockMutex(reinterpret_cast<nn::os::MutexType*>(&self->field_d8));
    self->field_d0 = value->field_0;
    nn::os::UnlockMutex(reinterpret_cast<nn::os::MutexType*>(&self->field_d8));
}

struct Unk_2779124_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_2779124_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_2779124_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_2779124_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_2779124_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_2779124_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_2779124_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_2779124_Data, field_18, 0x18);

extern Unk_2779124_Data Unk_2779124 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x71006c3790
void Unk_6c3790_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_2779124.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_2779124.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_2779124.field_10 = 0xffff;
    Unk_2779124.field_8 = r2;
    Unk_2779124.field_c = 0xffffffff;
    Unk_2779124.field_18 = 0;
    Unk_2779124.field_14 = 0;
}
