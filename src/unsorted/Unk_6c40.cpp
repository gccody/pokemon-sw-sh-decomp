// Scope: common
// A guarded static with a destructor: its storage is constant-initialised, so the init
// function only registers the destructor (a template static data member, like the
// `core_typeid_<T>::ti_` of Unk_1ec0.h).
#include <types.h>

struct Unk_6cf0;
void Unk_6cf0_call(Unk_6cf0* self) __attribute__((visibility("hidden")));

extern "C" int __cxa_atexit(void (*function)(void*), void* object, void* dso);
extern "C" void* __dso_handle __attribute__((visibility("hidden")));

extern Unk_6cf0 Unk_24ba688;
extern u64 Unk_24ba690;

// 0x7100006ca0
void Unk_6ca0_init() {
    if ((Unk_24ba690 & 1) == 0) {
        __cxa_atexit(reinterpret_cast<void (*)(void*)>(Unk_6cf0_call), &Unk_24ba688, &__dso_handle);
        Unk_24ba690 = 1;
    }
}
