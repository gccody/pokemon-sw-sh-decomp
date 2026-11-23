// SiSDK3's quick sort without recursion (the header's name is the __FILE__ of
// its stack's allocation and delete): it keeps the parts still to sort on a
// stack it allocates for as many elements as there are. Placeholder names;
// the comparison is a class with a static Unk_Compare (its object is the
// sorter's first member, which nothing initialises).
#pragma once

#include <types.h>

#include "SiCore_Memory.h"
#include "Unk_Alloc.h"

namespace SiSDK3 {

template <class T, class Compare>
class SiQSorter {
public:
    // a part still to sort
    struct Unk_Part {
        s64 m_count;
        T* m_pItems;
    };

    // (inline in its callers) makes the stack's room for capacity parts.
    // The count is taken by reference: the caller's is read after the
    // default allocator's call, and the stack's store in the reserve comes
    // after the constructor's own (so its address is computed once, which
    // gives the room's test `cmp #1 ; b.lt`).
    SiQSorter(ISiAllocator* pAllocator, const size_t& capacity)
        : m_pAllocator(pAllocator), m_capacity(0), m_depth(0), m_pStack(nullptr) {
        if (m_pAllocator == nullptr) {
            m_pAllocator = Unk_4bc640();
        }
        Unk_Reserve(capacity);
    }
    // makes the stack's room (inline in its callers)
    void Unk_Reserve(s64 capacity) {
        if (capacity < 1) {
            return;
        }
        m_capacity = capacity;
#line 250
        m_pStack = UNK_ALLOC_ARRAY(m_pAllocator, Unk_Part, capacity, 0xffffffff);
    }
    ~SiQSorter() {
#line 231
        UNK_SAFE_DELETE_ARRAY(m_pAllocator, m_pStack);
    }

    // sorts count items (false: more than the stack has room for)
    bool Unk_Sort(s64 count, T* items);

private:
    // the partition around the middle item; the index it ends at
    static s64 Unk_Partition(s64 count, T* items) {
        s64 pivot = count < 2 ? 1 : count / 2;
        if (pivot >= count) {
            return 0;
        }
        T t = items[pivot];
        items[pivot] = items[0];
        items[0] = t;
        T first = items[0];
        s64 i = 1;
        s64 j = count - 1;
        while (i <= j) {
            if (Compare::Unk_Compare(first, items[i]) > 0) {
                do {
                    if (++i >= j) {
                        break;
                    }
                } while (Compare::Unk_Compare(first, items[i]) > 0);
            }
            if (Compare::Unk_Compare(first, items[j]) <= 0) {
                do {
                    if (--j <= i) {
                        break;
                    }
                } while (Compare::Unk_Compare(first, items[j]) <= 0);
            }
            if (i < j) {
                T u = items[i];
                items[i] = items[j];
                items[j] = u;
            }
        }
        s64 middle = i - 1;
        T u = items[middle];
        items[middle] = items[0];
        items[0] = u;
        return middle;
    }
    // keeps a part to sort (one of a single item is done)
    // the same for the items after the middle one
    void Unk_PushRest(s64 count, T* items, s64 middle) {
        Unk_Part& part = m_pStack[m_depth];
        part.m_count = count - middle - 1;
        if (part.m_count > 1) {
            part.m_pItems = &items[middle + 1];
            m_depth++;
        }
    }
    void Unk_Push(s64 count, T* items) {
        Unk_Part& part = m_pStack[m_depth];
        part.m_count = count;
        if (count > 1) {
            part.m_pItems = items;
            m_depth++;
        }
    }

    Compare m_compare;
    ISiAllocator* m_pAllocator;
    s64 m_capacity;
    s64 m_depth;
    Unk_Part* m_pStack;
};

template <class T, class Compare>
bool SiQSorter<T, Compare>::Unk_Sort(s64 count, T* items) {
    if (m_capacity < count) {
        return false;
    }
    m_depth = 0;
    s64 middle = Unk_Partition(count, items);
    Unk_PushRest(count, items, middle);
    Unk_Push(middle, items);
    while (m_depth >= 1) {
        m_depth--;
        Unk_Part& part = m_pStack[m_depth];
        s64 n = part.m_count;
        T* p = part.m_pItems;
        middle = Unk_Partition(n, p);
        Unk_PushRest(n, p, middle);
        Unk_Push(middle, p);
    }
    return true;
}

}  // namespace SiSDK3
