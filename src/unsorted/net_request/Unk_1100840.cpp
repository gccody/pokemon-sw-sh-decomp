// Scope: common
// A timeout: when it started (nanoseconds since boot) and how long it lasts,
// in milliseconds. Unk_1100840 starts it (src/unsorted/leaf/Unk_1100970.cpp
// calls it as taking a void*), Unk_1100870 says whether it has run out.
// Placeholder types: rename and move once the class is known.
#include <types.h>

#include "nn/os.h"

struct Unk_1100840_Timer {
    s64 field_0;
    s64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1100840_Timer, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1100840_Timer, field_8, 0x8);

// 0x7101100840
void Unk_1100840(void* self, u64 duration) {
    Unk_1100840_Timer* timer = static_cast<Unk_1100840_Timer*>(self);
    timer->field_0 = nn::os::ConvertToTimeSpan(nn::os::GetSystemTick()).field_0;
    timer->field_8 = duration;
}

// NON_MATCHING: the original divides by 1000000 through a 64-bit signed
// high multiply done in 32-bit halves (Hacker's Delight's mulhs), where this
// gives one smulh. 12 game functions share that shape (none matched yet);
// a hand-written mulhs helper reproduces it, so it's likely a source-level
// helper whose name and home aren't known.
// 0x7101100870
bool Unk_1100870(const Unk_1100840_Timer* self) {
    s64 elapsed = nn::os::ConvertToTimeSpan(nn::os::GetSystemTick()).field_0 - self->field_0;
    return self->field_8 <= elapsed / 1000000;
}
