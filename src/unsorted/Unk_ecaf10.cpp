// Scope: common
#include <string.h>

#include "types.h"

// A 0x20-byte fixed-size name buffer, returned by value.
struct Unk_ecaf10_Name {
    char str[0x20];
};
PKMN_SIZE_ASSERT(Unk_ecaf10_Name, 0x20);

// 0x7100ecaf10
Unk_ecaf10_Name Unk_ecaf10() {
    const char* src = "check_point";
    Unk_ecaf10_Name name = {};
    memcpy(name.str, src, strlen(src));
    return name;
}
