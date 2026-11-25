// Scope: common
// A guarded static with a destructor: its storage is constant-initialised, so the init
// function only registers the destructor (a template static data member, like the
// `core_typeid_<T>::ti_` of Unk_1ec0.h).
#include <types.h>

struct Unk_6820;
void Unk_6820_call(Unk_6820* self) __attribute__((visibility("hidden")));

extern "C" int __cxa_atexit(void (*function)(void*), void* object, void* dso);
extern "C" void* __dso_handle __attribute__((visibility("hidden")));

extern Unk_6820 Unk_24ba618;
extern u64 Unk_24ba620;

// 0x71000067d0
void Unk_67d0_init() {
    if ((Unk_24ba620 & 1) == 0) {
        __cxa_atexit(reinterpret_cast<void (*)(void*)>(Unk_6820_call), &Unk_24ba618, &__dso_handle);
        Unk_24ba620 = 1;
    }
}
