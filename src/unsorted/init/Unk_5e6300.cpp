// Scope: common
// A static initialiser, as a function: the statics it sets are one placeholder struct
// at the address its code uses. Written by tools/initgen.py: regenerate, don't edit.
// Order: split
#include <types.h>

struct Unk_27736f8_Data {
    u64 field_0;
    u64 field_8;
    const char* field_10;
    u64 field_18;
    u64 field_20;
    u32 field_28;
};
PKMN_OFFSET_ASSERT(Unk_27736f8_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27736f8_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27736f8_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27736f8_Data, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_27736f8_Data, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_27736f8_Data, field_28, 0x28);

extern Unk_27736f8_Data Unk_27736f8;

void Unk_5e6100(void*);
extern "C" int __cxa_atexit(void (*function)(void*), void* object, void* dso);
extern "C" void* __dso_handle __attribute__((visibility("hidden")));

// 0x71005e6300
void Unk_5e6300_init() {
    Unk_27736f8.field_0 = 0;
    Unk_27736f8.field_8 = 0xcbf29ce484222645;
    Unk_27736f8.field_28 = 0;
    Unk_27736f8.field_18 = 0;
    Unk_27736f8.field_20 = 0;
    Unk_27736f8.field_10 = "";
    __cxa_atexit(Unk_5e6100, &Unk_27736f8.field_0, &__dso_handle);
}
