// Scope: common
// A static initialiser, as a function: the statics it sets are one placeholder struct
// at the address its code uses. Written by tools/initgen.py: regenerate, don't edit.
// Order: split
#include <types.h>

struct Unk_24bbdb0_Data {
    u8 _0[0x28];
    u8 field_28;
};
PKMN_OFFSET_ASSERT(Unk_24bbdb0_Data, field_28, 0x28);

extern Unk_24bbdb0_Data Unk_24bbdb0;

void Unk_333880(void*);
extern "C" int __cxa_atexit(void (*function)(void*), void* object, void* dso);
extern "C" void* __dso_handle __attribute__((visibility("hidden")));

// 0x7100333a10
void Unk_333a10_init() {
    Unk_24bbdb0.field_28 = 0;
    __cxa_atexit(Unk_333880, &Unk_24bbdb0, &__dso_handle);
}
