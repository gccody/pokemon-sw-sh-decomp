// Scope: common
// A guarded static with a destructor: its storage is constant-initialised, so the init
// function only registers the destructor (a template static data member, like the
// `core_typeid_<T>::ti_` of Unk_1ec0.h).
#include <types.h>

struct Unk_6610;
void Unk_6610_call(Unk_6610* self) __attribute__((visibility("hidden")));

extern "C" int __cxa_atexit(void (*function)(void*), void* object, void* dso);
extern "C" void* __dso_handle __attribute__((visibility("hidden")));

extern Unk_6610 Unk_24ba5e8;
extern u64 Unk_24ba5f0;

// 0x71000065c0
void Unk_65c0_init() {
    if ((Unk_24ba5f0 & 1) == 0) {
        __cxa_atexit(reinterpret_cast<void (*)(void*)>(Unk_6610_call), &Unk_24ba5e8, &__dso_handle);
        Unk_24ba5f0 = 1;
    }
}
