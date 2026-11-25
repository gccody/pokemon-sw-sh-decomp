// Scope: common
// Its own TU: the original tail-calls Unk_7eb3d0 instead of inlining it.
#include <types.h>

bool Unk_7eb3d0(u32 value);

// 0x71007eb490
bool Unk_7eb490(u32 value) {
    if (value == 0x19)
        return false;
    return Unk_7eb3d0(value);
}
