// Scope: common
// Wwise's audio thread ("AK::EventManager"): it runs the engine every
// Unk_2382e70 milliseconds, or when its event is signalled. Placeholder names.
#include "Unk_3358b0.h"
#include "Unk_Thread.h"
#include "containers.h"

void Unk_3689d0_update();
void Unk_3689e0_update();

extern Unk_Thread Unk_24bc850;
extern u8 Unk_24bbd88[];  // nn::os::EventType
extern nn::os::ThreadType* Unk_24bca20;
extern Unk_336510_T* Unk_24bbbc0;
extern u32 Unk_2382e70;

static inline nn::os::EventType* Unk_334a10_Event() {
    return reinterpret_cast<nn::os::EventType*>(Unk_24bbd88);
}

// 0x7100334a10
void Unk_334a10(void* self) {
    static_cast<Unk_334a10_T*>(self)->field_0 = false;
    Unk_24bc850.field_40 = 0;
}

// 0x7100334a30
void Unk_334a10_T::Unk_334a30() {
    nn::os::SignalEvent(Unk_334a10_Event());
}

// 0x7100334a40
void Unk_334a10_T::Unk_334a40(void* arg) {
    Unk_334a10_T* self = static_cast<Unk_334a10_T*>(arg);
    Unk_24bca20 = nn::os::GetCurrentThread();
    Unk_3689d0_update();
    do {
        Unk_336510(Unk_24bbbc0);
        nn::TimeSpan timeout;
        timeout.field_0 = static_cast<s64>(Unk_2382e70) * 1000000;
        nn::os::TimedWaitEvent(Unk_334a10_Event(), timeout);
    } while (!self->field_0);
    Unk_3689e0_update();
}

// 0x7100334ac0
u32 Unk_334a10_T::Unk_334ac0() {
    field_0 = false;
    Unk_24bc850.field_1c0 = Unk_673320(Unk_24bcb80.field_0.field_8, 0x1000);
    Unk_24bc850.field_1c8 = Unk_24bcb80.field_0.field_8;
    nn::os::CreateThread(Unk_24bc850.Get(), Unk_334a40, this, Unk_24bc850.field_1c0,
                         Unk_24bc850.field_1c8, Unk_24bcb80.field_0.field_0);
    nn::os::SetThreadName(Unk_24bc850.Get(), "AK::EventManager");
    nn::os::SetThreadCoreMask(Unk_24bc850.Get(), Unk_24bcb80.field_0.field_10,
                              Unk_24bcb80.field_0.field_18);
    nn::os::StartThread(Unk_24bc850.Get());
    return Unk_24bc850.field_40 != 0 ? 1 : 2;
}

// 0x7100334b70
void Unk_334a10_T::Unk_334b70() {
    field_0 = true;
    if (Unk_24bc850.field_40 != 0) {
        nn::os::SignalEvent(Unk_334a10_Event());
        nn::os::WaitThread(Unk_24bc850.Get());
        nn::os::DestroyThread(Unk_24bc850.Get());
        Unk_6733a0(reinterpret_cast<u64>(Unk_24bc850.field_1c0));
        Unk_24bc850.field_1c0 = nullptr;
        Unk_24bc850.field_40 = 0;
        Unk_24bca20 = nullptr;
    }
}
