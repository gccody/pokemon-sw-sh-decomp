// Scope: common
// A guarded static with a destructor: its storage is constant-initialised, so the init
// function only registers the destructor (a template static data member, like the
// `core_typeid_<T>::ti_` of Unk_1ec0.h).
#include <types.h>

struct Unk_6560;
void Unk_6560_call(Unk_6560* self) __attribute__((visibility("hidden")));

extern "C" int __cxa_atexit(void (*function)(void*), void* object, void* dso);
extern "C" void* __dso_handle __attribute__((visibility("hidden")));

extern Unk_6560 Unk_24ba5d8;
extern u64 Unk_24ba5e0;

// 0x7100006510
void Unk_6510_init() {
    if ((Unk_24ba5e0 & 1) == 0) {
        __cxa_atexit(reinterpret_cast<void (*)(void*)>(Unk_6560_call), &Unk_24ba5d8, &__dso_handle);
        Unk_24ba5e0 = 1;
    }
}
