#pragma once
// Two small containers that free their storage through an allocator, members
// of several game classes (first seen in Unk_2438308, 0x710140c1d0):
// words and how many fit, and a singly linked list whose nodes are destroyed
// and freed one by one. Placeholder names: rename once the classes are known.
#include "gflib3/Unk_239a418.h"

template <class T>
struct Unk_2438308_Words {
    ~Unk_2438308_Words() {
        T* data = m_data;
        m_data = nullptr;
        if (data)
            m_allocator.deallocate(data, m_capacity);
    }

    T* m_data;
    u64 m_capacity;
    Unk_239a418_StdAllocator<T> m_allocator;
};

// Node starts with its link to the next one (m_next).
template <class Node>
struct Unk_2438308_List {
    ~Unk_2438308_List() {
        for (Node* node = m_head; node;) {
            Node* next = node->m_next;
            node->~Node();
            m_allocator.deallocate(node, 1);
            node = next;
        }
    }

    Node* m_head;
    Unk_239a418_StdAllocator<Node> m_allocator;
};
