// Scope: common
// Out-of-line Set functions of sorted key arrays (sorted_array.h) whose
// owners aren't decompiled yet: the item of a key, added when the array
// doesn't have it. The keys are pointers to objects. Placeholder names.
#include "sorted_array.h"

struct Unk_3d0e80_Key;
struct Unk_3e9f30_Key;

// 0x71003d0e80: growing by 4
template Unk_3d0e80_Key** Unk_SortedKeyArray<
    Unk_3d0e80_Key*, Unk_3d0e80_Key*, Unk_KeyIsItem<Unk_3d0e80_Key*>, Unk_Pool2381488, 4>::Set(
    Unk_3d0e80_Key*);

// 0x71003e9f30: growing by 6
template Unk_3e9f30_Key** Unk_SortedKeyArray<
    Unk_3e9f30_Key*, Unk_3e9f30_Key*, Unk_KeyIsItem<Unk_3e9f30_Key*>, Unk_Pool2385820, 6>::Set(
    Unk_3e9f30_Key*);
