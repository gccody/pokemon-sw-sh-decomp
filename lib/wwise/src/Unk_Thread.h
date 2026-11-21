#pragma once
// Wwise's threads on this platform: an nn::os thread with the stack it
// allocated, and the properties each of the engine's threads is created with.
// Placeholder names.
#include <nn/os.h>
#include <types.h>

namespace nn::os {
void WaitEvent(EventType* event) noexcept;
bool TimedWaitEvent(EventType* event, TimeSpan timeout) noexcept;
void SetThreadName(ThreadType* thread, const char* name) noexcept;
}  // namespace nn::os

// 0x1d0 bytes.
struct Unk_Thread {
    u8 field_0[0x40];  // nn::os::ThreadType, 0x1c0 bytes
    u8 field_40;  // its state: zero when it wasn't created
    u8 _41[0x17f];
    void* field_1c0;  // stack
    u32 field_1c8;  // and its size

    nn::os::ThreadType* Get() { return reinterpret_cast<nn::os::ThreadType*>(field_0); }
};
PKMN_OFFSET_ASSERT(Unk_Thread, field_40, 0x40);
PKMN_OFFSET_ASSERT(Unk_Thread, field_1c0, 0x1c0);
PKMN_SIZE_ASSERT(Unk_Thread, 0x1d0);

struct Unk_ThreadProperties {
    s32 field_0;  // priority
    u64 field_8;  // stack size
    s32 field_10;  // ideal core
    u64 field_18;  // affinity mask
};
PKMN_SIZE_ASSERT(Unk_ThreadProperties, 0x20);

// The platform settings: the properties of the engine's threads.
struct Unk_24bcb80_T {
    Unk_ThreadProperties field_0;  // the event manager's
    Unk_ThreadProperties field_20;
    Unk_ThreadProperties field_40;
    Unk_ThreadProperties field_60;  // the Opus decoding thread's
};
extern Unk_24bcb80_T Unk_24bcb80;

void* Unk_673320(u64 size, u32 align);
void Unk_6733a0(u64 ptr);
