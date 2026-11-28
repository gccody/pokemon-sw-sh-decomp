// Scope: common
// A classifier that extends Unk_7eb6d0's set (in Unk_7eb5d0.cpp; a TU of its
// own, since the original calls it) with a table of IDs.
#include <types.h>

bool Unk_7eb6d0(u16 value);

extern const u16 Unk_1f10b96[105] __attribute__((visibility("hidden")));

// 0x71007eba10
bool Unk_7eba10(u16 value) {
    if (Unk_7eb6d0(value))
        return true;
    for (u32 i = 0; i < 105; i++) {
        if (Unk_1f10b96[i] == value)
            return true;
    }
    return false;
}
