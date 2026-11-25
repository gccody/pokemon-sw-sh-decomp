// Scope: common
// A guarded static with a destructor: its storage is constant-initialised, so the init
// function only registers the destructor (a template static data member, like the
// `core_typeid_<T>::ti_` of Unk_1ec0.h).
#include <types.h>

struct Unk_7060;
void Unk_7060_call(Unk_7060* self) __attribute__((visibility("hidden")));

extern "C" int __cxa_atexit(void (*function)(void*), void* object, void* dso);
extern "C" void* __dso_handle __attribute__((visibility("hidden")));

extern Unk_7060 Unk_24ba6d8;
extern u64 Unk_24ba6e0;

// 0x7100007010
void Unk_7010_init() {
    if ((Unk_24ba6e0 & 1) == 0) {
        __cxa_atexit(reinterpret_cast<void (*)(void*)>(Unk_7060_call), &Unk_24ba6d8, &__dso_handle);
        Unk_24ba6e0 = 1;
    }
}
