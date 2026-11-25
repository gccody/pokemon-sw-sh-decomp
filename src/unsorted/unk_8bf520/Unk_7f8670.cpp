// Scope: common
// The TU's static initialiser, as a function: the statics it sets are one
// placeholder struct at the address its code uses (the three addresses an
// nn::ldn header makes, then two objects with destructors), written the way
// tools/initgen.py writes them.
#include <types.h>

struct Unk_7f6e10;
struct Unk_7f6e70;
void Unk_7f6e10_call(Unk_7f6e10* self) __attribute__((visibility("hidden")));
void Unk_7f6e70_call(Unk_7f6e70* self) __attribute__((visibility("hidden")));

struct Unk_27ced08_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u8 _c[0x4];
    u32 field_10;
    u16 field_14;
    u8 _16[0x2];
    u32 field_18;
    u16 field_1c;
    u8 _1e[0xa];
    u8 field_28[0x20];
    u8 field_48[0x8];
};
PKMN_OFFSET_ASSERT(Unk_27ced08_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27ced08_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27ced08_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27ced08_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27ced08_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27ced08_Data, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_27ced08_Data, field_1c, 0x1c);
PKMN_OFFSET_ASSERT(Unk_27ced08_Data, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_27ced08_Data, field_48, 0x48);

extern Unk_27ced08_Data Unk_27ced08 __attribute__((visibility("hidden")));

namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

extern "C" int __cxa_atexit(void (*function)(void*), void* object, void* dso);
extern "C" void* __dso_handle __attribute__((visibility("hidden")));

// 0x71007f86d0
void Unk_7f86d0_init() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27ced08.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27ced08.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27ced08.field_8 = r2;
    Unk_27ced08.field_1c = 0xffff;
    Unk_27ced08.field_14 = 0;
    Unk_27ced08.field_10 = 0;
    Unk_27ced08.field_18 = 0xffffffff;
    __cxa_atexit(reinterpret_cast<void (*)(void*)>(Unk_7f6e10_call), &Unk_27ced08.field_28,
                 &__dso_handle);
    __cxa_atexit(reinterpret_cast<void (*)(void*)>(Unk_7f6e70_call), &Unk_27ced08.field_48,
                 &__dso_handle);
}
