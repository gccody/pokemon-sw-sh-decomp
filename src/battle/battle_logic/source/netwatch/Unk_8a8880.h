#pragma once
// The reference the two small objects of 0x71008a8880 and 0x71008a8a70 keep
// at +0x20: to an object on Unk_239a4c0, added and dropped through its +0x48
// interface (as src/unsorted/unk_8bf520/Unk_8e1cf0.cpp's). Placeholder
// names: rename once the classes are known.
#include <types.h>

#include "gflib3/Unk_239a4c0.h"

template <class T>
class Unk_8a8880_Ref {
public:
    Unk_8a8880_Ref() : m_ptr(nullptr) {}
    ~Unk_8a8880_Ref() {
        if (m_ptr) {
            static_cast<Unk_239a4f8*>(m_ptr)->vf4();
            m_ptr = nullptr;
        }
    }

    // Holds the other's object too: its reference added, then stored, then
    // the old one dropped.
    Unk_8a8880_Ref& operator=(const Unk_8a8880_Ref& other) {
        T* p = other.m_ptr;
        if (p)
            static_cast<Unk_239a4f8*>(p)->vf3();
        T* old = m_ptr;
        m_ptr = p;
        if (old)
            static_cast<Unk_239a4f8*>(old)->vf4();
        return *this;
    }

    T* operator->() const { return m_ptr; }

    T* m_ptr;
};
static_assert(sizeof(Unk_8a8880_Ref<Unk_239a4c0>) == 0x8, "Unk_8a8880_Ref");
