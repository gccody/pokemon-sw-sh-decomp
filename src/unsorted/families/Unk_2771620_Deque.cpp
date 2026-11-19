// Scope: common
// Deques on Unk_2771620's allocator whose push_back Game Freak's code instantiates
// out of line (game/pokecamp), with their __add_back_capacity and the
// __split_buffer members that grow their maps of blocks, and one more deque's
// __add_back_capacity (gflib3; its caller isn't a push_back). The elements are trivially copyable:
// the code depends only on their size (and so on the block size), so each
// element type is a placeholder of that size, named after its push_back.
#include <types.h>
#include <deque>

#include "unsorted/Unk_2771620.h"

template <class T>
using Unk_2771620_Deque = std::deque<T, Unk_2771620_Allocator<T>>;

struct Unk_1230ca0 {
    u64 _0;
};
struct Unk_12181e0 {
    u64 _0[12];
};
struct Unk_5f5d20 {
    u64 _0[9];
};

// 0x7101230ca0 (and 0x71012335e0, 0x7101233ac0, 0x7101233cc0, 0x7101233ec0, 0x71012340d0)
template void Unk_2771620_Deque<Unk_1230ca0>::push_back(const Unk_1230ca0&);
// 0x71012181e0 (and 0x710121efd0, 0x710121f1d0, 0x710121f3d0, 0x710121f5e0, 0x710121f910)
template void Unk_2771620_Deque<Unk_12181e0>::push_back(const Unk_12181e0&);
// 0x71005f5d20 (and 0x71005f6200, 0x71005f6400, 0x71005f6600, 0x71005f6810)
template void Unk_2771620_Deque<Unk_5f5d20>::__add_back_capacity();
