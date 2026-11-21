// Scope: common
// The frequency a low-pass filter cuts off at, from how much it filters (0 to
// 100). Written from the executable. Placeholder names.
#include "Unk_FastMath.h"

extern u32 Unk_2382e68;  // samples in a second

// 0x71003cf630
f32 Unk_3cf630(f32 amount) {
    f32 cutoff;
    if (amount < 30.0f)
        cutoff = (30.0f - amount) * 433.33334f + 7000.0f;
    else
        cutoff = Unk_Pow10Unchecked((100.0f - amount) * 0.037426498f) * 16.797443f;
    f32 highest = Unk_2382e68 * 0.45f;
    return highest < cutoff ? highest : cutoff;
}

// 0x71003cf6f0: from how much it lets through
f32 Unk_3cf6f0(f32 amount) {
    return Unk_3cf630(100.0f - amount);
}
