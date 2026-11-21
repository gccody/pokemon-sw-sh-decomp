// SiSDK3's intrusive list, reconstructed from its instances in YEBIS (RTTI:
// SiSDK3::SiDirectLinkedList<T*>). The element links itself: its m_pPrev and
// m_pNext (placeholder names) are wherever the element's class has them.
// Placeholder members.
#pragma once

#include <stddef.h>
#include <types.h>

#include "SiCore_Memory.h"

namespace SiSDK3 {

template <class T>
class SiDirectLinkedList {
public:
    SiDirectLinkedList() : field_8(nullptr), m_pHead(nullptr), m_pTail(nullptr), m_count(0) {
        field_8 = Unk_4bc640();
    }
    // with an allocator, or the kernel's for a null one (inline in every
    // caller)
    explicit SiDirectLinkedList(ISiAllocator* pAllocator)
        : field_8(pAllocator), m_pHead(nullptr), m_pTail(nullptr), m_count(0) {
        if (field_8 == nullptr) {
            field_8 = Unk_4bc640();
        }
    }
    virtual ~SiDirectLinkedList() { RemoveAll(); }

    // empties the list for another allocator (the kernel's for a null pointer)
    void Unk_SetAllocator(ISiAllocator* pAllocator) {
        field_8 = pAllocator != nullptr ? pAllocator : Unk_4bc640();
        m_pHead = nullptr;
        m_pTail = nullptr;
        m_count = 0;
    }

    // unlinks the head, if there is one, and returns it
    T RemoveHead() {
        T node = m_pHead;
        if (node != nullptr) {
            T next = node->m_pNext;
            if (next != nullptr) {
                next->m_pPrev = nullptr;
                m_pHead = next;
            } else {
                m_pHead = nullptr;
                m_pTail = nullptr;
            }
            node->m_pPrev = nullptr;
            node->m_pNext = nullptr;
            m_count--;
        }
        return node;
    }

    // unlinks every element, from the head
    void RemoveAll() {
        while (m_count != 0) {
            T node = m_pHead;
            if (node == nullptr) {
                return;
            }
            T next = node->m_pNext;
            if (next != nullptr) {
                next->m_pPrev = nullptr;
                m_pHead = next;
            } else {
                m_pHead = nullptr;
                m_pTail = nullptr;
            }
            node->m_pPrev = nullptr;
            node->m_pNext = nullptr;
            m_count--;
        }
    }

    // unlinks node, if it's in the list
    void Remove(T node) {
        if (node == nullptr) {
            return;
        }
        T prev = node->m_pPrev;
        T next = node->m_pNext;
        if (prev != nullptr) {
            if (next != nullptr) {
                next->m_pPrev = prev;
                prev->m_pNext = next;
            } else {
                if (m_pTail != node || m_pTail == nullptr) {
                    return;
                }
                prev->m_pNext = nullptr;
                m_pTail = prev;
            }
        } else {
            if (m_pHead != node || m_pHead == nullptr) {
                return;
            }
            if (next != nullptr) {
                next->m_pPrev = nullptr;
                m_pHead = next;
            } else {
                m_pHead = nullptr;
                m_pTail = nullptr;
            }
        }
        node->m_pPrev = nullptr;
        node->m_pNext = nullptr;
        m_count--;
    }

    void AddTail(T node) {
        if (m_pHead != nullptr) {
            m_pTail->m_pNext = node;
            node->m_pPrev = m_pTail;
        } else {
            m_pHead = node;
        }
        m_pTail = node;
        m_count++;
    }

    void* field_8;
    T m_pHead;
    T m_pTail;
    size_t m_count;
};

// SiSDK3's list of nodes it allocates (the class's name isn't in the
// executable: its instances have no vtable; SiLinkedList after the header).
// The original header's __LINE__s (the allocator's file/line arguments) are
// kept with #line.
template <class T>
class SiLinkedList {
public:
    struct Node {
        Node(SiLinkedList* pList, const T& value)
            : m_pList(pList), m_pPrev(nullptr), m_pNext(nullptr), field_18(nullptr), m_value(value) {}

        SiLinkedList* m_pList;
        Node* m_pPrev;
        Node* m_pNext;
        void* field_18;
        T m_value;
    };

    explicit SiLinkedList(ISiAllocator* pAllocator)
        : m_pAllocator(pAllocator), m_pHead(nullptr), m_pTail(nullptr), m_count(0) {
        if (m_pAllocator == nullptr) {
            m_pAllocator = Unk_4bc640();
        }
    }
    ~SiLinkedList() { RemoveAll(); }

    Node* AddTail(const T& value) {
#line 741
        Node* node = UNK_SI_NEW(m_pAllocator, 0x10) Node(this, value);
        if (node == nullptr) {
            return nullptr;
        }
        if (m_pHead != nullptr) {
            m_pTail->m_pNext = node;
            node->m_pPrev = m_pTail;
        } else {
            m_pHead = node;
        }
        m_pTail = node;
        m_count++;
        return node;
    }

    // unlinks and frees a node; the node after it
    Node* Remove(Node* node) {
        Node* prev = node->m_pPrev;
        Node* next = node->m_pNext;
        if (prev != nullptr) {
            prev->m_pNext = next;
        }
        if (next != nullptr) {
            next->m_pPrev = prev;
        }
        bool head = m_pHead == node;
        bool tail = m_pTail == node;
        m_count--;
        if (m_pAllocator != nullptr) {
#line 1243
            SI_FREE(m_pAllocator, node);
        }
        if (head) {
            m_pHead = next;
        }
        if (tail) {
            m_pTail = prev;
        }
        return next;
    }

    void RemoveAll() {
        while (m_pHead != nullptr) {
            Remove(m_pHead);
        }
    }

    ISiAllocator* m_pAllocator;
    Node* m_pHead;
    Node* m_pTail;
    size_t m_count;
};

}  // namespace SiSDK3

PKMN_SIZE_ASSERT(SiSDK3::SiDirectLinkedList<void**>, 0x28);
PKMN_SIZE_ASSERT(SiSDK3::SiLinkedList<void*>, 0x20);
PKMN_SIZE_ASSERT(SiSDK3::SiLinkedList<void*>::Node, 0x28);
