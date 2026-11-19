// Scope: common
// Members of vectors of references (Unk_239a418_Ref) on Unk_2771620's allocator
// that game code instantiates out of line. Their code doesn't depend on what
// the references are to, only that it's an object of gflib3's (Unk_239a418:
// the reference adds and drops through its interface at +0x48). Each one gets
// a placeholder class on the object, named after the function.
#include <types.h>
#include <vector>

#include "gflib3/Unk_239a418.h"
#include "unsorted/Unk_2771620.h"

template <class T>
using Unk_2771620_RefVector =
    std::vector<Unk_239a418_Ref<T>, Unk_2771620_Allocator<Unk_239a418_Ref<T>>>;

class Unk_b86950 : public Unk_239a418 {};
class Unk_c68b30 : public Unk_239a418 {};
class Unk_1159160 : public Unk_239a418 {};
class Unk_13caf80 : public Unk_239a418 {};
class Unk_13fb250 : public Unk_239a418 {};

// 0x7100b86950
// NON_MATCHING: Unk_239a418_Ref's copy constructor tests the other
// reference's pointer (src/gflib3/Unk_239a418.h, for the battle sequence
// functions): the copies into the new buffer then load and test it in
// another order. With the copy's own pointer tested, this matched.
template void Unk_2771620_RefVector<Unk_b86950>::__append(size_t);
// 0x7100c68b30
// NON_MATCHING: Unk_239a418_Ref's copy constructor tests the other
// reference's pointer (src/gflib3/Unk_239a418.h, for the battle sequence
// functions): the copies into the new buffer then load and test it in
// another order. With the copy's own pointer tested, this matched.
template Unk_239a418_Ref<Unk_c68b30>* Unk_2771620_RefVector<Unk_c68b30>::__swap_out_circular_buffer(
    std::__split_buffer<Unk_239a418_Ref<Unk_c68b30>,
                        Unk_2771620_Allocator<Unk_239a418_Ref<Unk_c68b30>>&>&,
    Unk_239a418_Ref<Unk_c68b30>*);
// 0x7101159160
// NON_MATCHING: Unk_239a418_Ref's copy constructor tests the other
// reference's pointer (src/gflib3/Unk_239a418.h, for the battle sequence
// functions): the copies into the new buffer then load and test it in
// another order. With the copy's own pointer tested, this matched.
template void Unk_2771620_RefVector<Unk_1159160>::__append(size_t);
// 0x71013caf80
// NON_MATCHING: Unk_239a418_Ref's copy constructor tests the other
// reference's pointer (src/gflib3/Unk_239a418.h, for the battle sequence
// functions): the copies into the new buffer then load and test it in
// another order. With the copy's own pointer tested, this matched.
template Unk_239a418_Ref<Unk_13caf80>*
Unk_2771620_RefVector<Unk_13caf80>::__swap_out_circular_buffer(
    std::__split_buffer<Unk_239a418_Ref<Unk_13caf80>,
                        Unk_2771620_Allocator<Unk_239a418_Ref<Unk_13caf80>>&>&,
    Unk_239a418_Ref<Unk_13caf80>*);
// 0x71013fb250
// NON_MATCHING: Unk_239a418_Ref's copy constructor tests the other
// reference's pointer (src/gflib3/Unk_239a418.h, for the battle sequence
// functions): the copies into the new buffer then load and test it in
// another order. With the copy's own pointer tested, this matched.
template Unk_239a418_Ref<Unk_13fb250>*
Unk_2771620_RefVector<Unk_13fb250>::__swap_out_circular_buffer(
    std::__split_buffer<Unk_239a418_Ref<Unk_13fb250>,
                        Unk_2771620_Allocator<Unk_239a418_Ref<Unk_13fb250>>&>&,
    Unk_239a418_Ref<Unk_13fb250>*);
