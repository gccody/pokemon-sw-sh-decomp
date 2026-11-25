// Scope: common
// A guarded static with a destructor: its storage is constant-initialised, so the init
// function only registers the destructor (a template static data member, like the
// `core_typeid_<T>::ti_` of Unk_1ec0.h).
#include <types.h>

struct Unk_64b0;
void Unk_64b0_call(Unk_64b0* self) __attribute__((visibility("hidden")));

extern "C" int __cxa_atexit(void (*function)(void*), void* object, void* dso);
extern "C" void* __dso_handle __attribute__((visibility("hidden")));

extern Unk_64b0 Unk_24ba5c8;
extern u64 Unk_24ba5d0;

// 0x7100006460
void Unk_6460_init() {
    if ((Unk_24ba5d0 & 1) == 0) {
        __cxa_atexit(reinterpret_cast<void (*)(void*)>(Unk_64b0_call), &Unk_24ba5c8, &__dso_handle);
        Unk_24ba5d0 = 1;
    }
}
