// Scope: common
// A static initialiser, as a function: the statics it sets are one placeholder struct
// at the address its code uses. Written by tools/initgen.py: regenerate, don't edit.
// Order: split
#include <types.h>

struct Unk_27789f0_Data {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27789f0_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27789f0_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27789f0_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27789f0_Data, field_18, 0x18);

extern Unk_27789f0_Data Unk_27789f0;

void Unk_687630(void*);
extern "C" int __cxa_atexit(void (*function)(void*), void* object, void* dso);
extern "C" void* __dso_handle __attribute__((visibility("hidden")));

// 0x7100687cc0
void Unk_687cc0_init() {
    Unk_27789f0.field_10 = 0;
    Unk_27789f0.field_18 = 0;
    Unk_27789f0.field_0 = 0;
    Unk_27789f0.field_8 = 0;
    __cxa_atexit(Unk_687630, &Unk_27789f0.field_0, &__dso_handle);
}
