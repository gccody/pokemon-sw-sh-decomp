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

// An object two classes own (Unk_2438308, Unk_2431fa8): words and a list of
// 0x20-byte nodes.
struct Unk_2438308_Node {
    Unk_2438308_Node* m_next;
    u64 field_8;
    u64 field_10;
    u64 field_18;
};

struct Unk_2438308_Owned {
    Unk_2438308_Words<u64> field_0;
    u64 field_18;
    u64 field_20;
    Unk_2438308_List<Unk_2438308_Node> field_28;
};
static_assert(sizeof(Unk_2438308_Owned) == 0x38, "Unk_2438308_Owned");
