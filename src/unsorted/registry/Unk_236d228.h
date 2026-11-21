#pragma once
// A registered object: an interface of four functions (vtable 0x710236d238,
// all pure) whose constructor adds the object to a global table of 256
// pointers (Unk_2777f60) and whose destructor removes it, both under
// gflib3's static lock (Unk_65f110). Its destructor isn't virtual.
#include <stdlib.h>
#include <algorithm>

#include "gflib3/Unk_65f110.h"

class Unk_236d228;

struct Unk_2777f60_Table {
    Unk_236d228* m_items[256];
    u64 m_count;
};
PKMN_OFFSET_ASSERT(Unk_2777f60_Table, m_count, 0x800);
PKMN_SIZE_ASSERT(Unk_2777f60_Table, 0x808);

// 0x7102777f60
extern Unk_2777f60_Table Unk_2777f60;

class Unk_236d228 {
public:
    Unk_236d228() {
        Unk_2778770* lock = Unk_65f110();
        lock->Lock();
        if (Unk_2777f60.m_count >= 256)
            abort();
        Unk_2777f60.m_items[Unk_2777f60.m_count] = this;
        Unk_2777f60.m_count++;
        lock->Unlock();
    }
    // 0x7100003340
    // NON_MATCHING: the search for `this`. The original compares the first
    // pointer before its loop, merged with the test for an empty table (a
    // `cmp` of the count times 8 and a `ccmp`), and its loop tests the count
    // first; std::find gives one loop that does both. The rest is the same.
    // It's also inlined into the D0s of the classes in
    // src/unsorted/registry, which don't match for the same reason. A loop
    // spelled out (for, while, do-while, with indices or a count) doesn't
    // give it either.
    //
    // Read from the original: its loop is this one rotated once more. Here
    // the loop is `load, compare, advance, test the end`, after a test for an
    // empty table. There it is `advance, test the end, load, compare`, after
    // `empty || first == this`, and its exit at the end of the table still
    // goes through the `it != end` test (`mov x0, x9; cmp x9, x0`), which
    // here is threaded away. Not tried: what makes LLVM's later LoopRotate
    // run on the loop a second time (it does so only when the loop's latch
    // doesn't leave the loop, or was just folded into the block before it).
    ~Unk_236d228() {
        Unk_2778770* lock = Unk_65f110();
        lock->Lock();
        Unk_236d228** end = Unk_2777f60.m_items + Unk_2777f60.m_count;
        Unk_236d228** it = std::find(Unk_2777f60.m_items, end, this);
        if (it != end) {
            std::move(it + 1, end, it);
            Unk_2777f60.m_count--;
        }
        lock->Unlock();
    }

    virtual u32 vf0() = 0;
    virtual void* vf1(u64 index) = 0;
    virtual void* vf2(u64 index) = 0;
    virtual void vf3(u64 index) = 0;
};
