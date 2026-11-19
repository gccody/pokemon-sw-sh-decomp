#pragma once
// The battle engine's event system (constructed at 0x71007e8a20): code that
// raises an event pushes a frame of variables (Unk_7e94d0), sets the ones the
// handlers read (by label: Unk_7e95a0, Unk_7e9610, Unk_7e9680, ...), calls the
// event by number (Unk_7e8f60_call), reads back what the handlers changed
// (Unk_7e9830) and pops the frame (Unk_7e9510). Placeholder names: rename once
// the class is known.
#include <types.h>

struct Unk_7e8a20;

void Unk_7e94d0(Unk_7e8a20* self);
void Unk_7e9510(Unk_7e8a20* self);
void Unk_7e95a0(Unk_7e8a20* self, u16 label, u32 value);
void Unk_7e9610(Unk_7e8a20* self, u16 label, u32 value);
void Unk_7e9680(Unk_7e8a20* self, u16 label, u32 value);
void Unk_7e9720(Unk_7e8a20* self, u16 label, u32 value, u32 min, u32 max);
void Unk_7e98a0(Unk_7e8a20* self, u16 label, void* value);
void Unk_7e8f60_call(void* self, u64 event);
void Unk_7e9050_call(void* self, u64 event);

// Declared as src/unsorted/leaf/Unk_819600.cpp declares them (its callers
// there match): the system as an integer. The overloads below take it.
u32 Unk_7e9830(u64 self, u32 label);
bool Unk_7e97b0(u64 self, u32 label, u32 value);

inline u32 Unk_7e9830(Unk_7e8a20* self, u32 label) {
    return Unk_7e9830(reinterpret_cast<u64>(self), label);
}
inline bool Unk_7e97b0(Unk_7e8a20* self, u32 label, u32 value) {
    return Unk_7e97b0(reinterpret_cast<u64>(self), label, value);
}
