// Scope: common
// A static initialiser, as a function: the statics it sets are one placeholder struct
// at the address its code uses. Written by tools/initgen.py: regenerate, don't edit.
// Order: split
#include <types.h>

struct Unk_27f9cd8_Data {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_27f9cd8_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27f9cd8_Data, field_8, 0x8);

extern Unk_27f9cd8_Data Unk_27f9cd8;

void Unk_1652990_update();
extern "C" int __cxa_atexit(void (*function)(void*), void* object, void* dso);
extern "C" void* __dso_handle __attribute__((visibility("hidden")));

// 0x7101652c50
void Unk_1652c50_init() {
    Unk_27f9cd8.field_0 = 0;
    Unk_27f9cd8.field_8 = 0;
    __cxa_atexit(reinterpret_cast<void (*)(void*)>(Unk_1652990_update), &Unk_27f9cd8.field_0,
                 &__dso_handle);
}
