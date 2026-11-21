// Scope: common
// A static initialiser, as a function: the statics it sets are one placeholder struct
// at the address its code uses. Written by tools/initgen.py: regenerate, don't edit.
// Order: split
#include <types.h>

struct Unk_24bba00_Data {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
    u8 _20[0x30];
    u64 field_50;
};
PKMN_OFFSET_ASSERT(Unk_24bba00_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_24bba00_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_24bba00_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_24bba00_Data, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_24bba00_Data, field_50, 0x50);

extern Unk_24bba00_Data Unk_24bba00 __attribute__((visibility("hidden")));

void Unk_315020(void*);
extern "C" int __cxa_atexit(void (*function)(void*), void* object, void* dso);
extern "C" void* __dso_handle __attribute__((visibility("hidden")));

// 0x71003161b0
void Unk_3161b0_init() {
    Unk_24bba00.field_50 = 0;
    Unk_24bba00.field_10 = 0;
    Unk_24bba00.field_18 = 0;
    Unk_24bba00.field_0 = 0;
    Unk_24bba00.field_8 = 0;
    __cxa_atexit(Unk_315020, &Unk_24bba00.field_0, &__dso_handle);
}
