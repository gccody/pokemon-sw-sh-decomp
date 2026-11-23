#pragma once

// Declarations for the parts of the Nintendo SDK's nn::time that decompiled
// code calls (see os.h for how they were found: every function here is an
// import of `main`, its parameter types from the mangled name). Struct
// layouts are only what the callers show.

#include <stdint.h>

#include <nn/os.h>

namespace nn {
namespace time {

// 8 bytes: YEBIS's license check fills in the year (16 bits), month and day
// (bytes at 2 and 3) and the time of day (bytes at 4 to 6).
struct CalendarTime {
    int16_t field_0;  // year
    int8_t field_2;   // month
    int8_t field_3;   // day
    int8_t field_4;   // hour
    int8_t field_5;   // minute
    int8_t field_6;   // second
};
static_assert(sizeof(CalendarTime) == 0x8, "CalendarTime");

// a point in time, compared as a 64-bit number
struct PosixTime {
    int64_t field_0;
};
static_assert(sizeof(PosixTime) == 0x8, "PosixTime");

bool IsInitialized() noexcept;
Result Initialize() noexcept;
Result Finalize() noexcept;
PosixTime ToPosixTimeFromUtc(const CalendarTime& calendarTime) noexcept;

class StandardUserSystemClock {
public:
    static Result GetCurrentTime(PosixTime* outValue) noexcept;
};

}  // namespace time
}  // namespace nn
