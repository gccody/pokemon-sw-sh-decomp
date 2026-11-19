#pragma once
// An array that frees its storage through an allocator, with a callback
// between the two (0x60 bytes, 16-aligned for the callback): the elements,
// how many there are and how many fit. Its destructor destroys the elements and frees the storage
// when there is any; clear() destroys them and empties it. Members of several game classes (first
// seen in 0x710131fb20). Placeholder names: rename once the class is known.
#include <functional>

#include "gflib3/Unk_239a418.h"

template <class T>
class Unk_131fb20_Array {
public:
    ~Unk_131fb20_Array() {
        T* p = m_data;
        u64 n = m_size;
        while (n--) {
            p->~T();
            ++p;
        }
        if (m_capacity)
            m_allocator.deallocate(m_data, m_capacity);
    }

    void clear() {
        T* p = m_data;
        u64 n = m_size;
        while (n--) {
            p->~T();
            ++p;
        }
        m_size = 0;
    }

    Unk_239a418_StdAllocator<T> m_allocator;
    u64 field_8;
    std::function<void()> field_10;
    T* m_data;
    u64 m_size;
    u64 m_capacity;
};
static_assert(sizeof(Unk_131fb20_Array<u64>) == 0x60, "Unk_131fb20_Array");
