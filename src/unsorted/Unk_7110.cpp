// Scope: common
// A guarded static with a destructor: its storage is constant-initialised, so the init
// function only registers the destructor (a template static data member, like the
// `core_typeid_<T>::ti_` of Unk_1ec0.h).
#include <types.h>

struct Unk_71c0;
void Unk_71c0_call(Unk_71c0* self) __attribute__((visibility("hidden")));

extern "C" int __cxa_atexit(void (*function)(void*), void* object, void* dso);
extern "C" void* __dso_handle __attribute__((visibility("hidden")));

extern Unk_71c0 Unk_24ba6f8;
extern u64 Unk_24ba700;

// 0x7100007170
void Unk_7170_init() {
    if ((Unk_24ba700 & 1) == 0) {
        __cxa_atexit(reinterpret_cast<void (*)(void*)>(Unk_71c0_call), &Unk_24ba6f8, &__dso_handle);
        Unk_24ba700 = 1;
    }
}
