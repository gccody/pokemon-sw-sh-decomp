#pragma once
// Pia's allocation, as its factories call it: a heap (Unk_1652bd0, from a table
// of heaps), `new (heap) T` (0x71017162d0: from the current heap when it's
// null, alignment 4; null when it fails, so the constructor call is checked)
// and freeing (Unk_1716390, through the heap that holds the memory). The heaps
// are pead::Heap (RTTI N4pead4HeapE).
#include <types.h>

namespace pead {
class Heap;
}

pead::Heap* Unk_1652bd0();
void* operator new(size_t size, pead::Heap* heap) noexcept;
void Unk_1716390(void* memory);
