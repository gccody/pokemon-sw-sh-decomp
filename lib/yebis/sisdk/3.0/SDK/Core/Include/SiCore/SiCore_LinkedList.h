// SiSDK3's intrusive list, reconstructed from its instances in YEBIS (RTTI:
// SiSDK3::SiDirectLinkedList<T*>). The element links itself: its m_pPrev and
// m_pNext (placeholder names) are wherever the element's class has them.
// Placeholder members.
#pragma once

#include <stddef.h>
#include <types.h>

namespace SiSDK3 {

template <class T>
class SiDirectLinkedList {
public:
    virtual ~SiDirectLinkedList() { RemoveAll(); }

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

}  // namespace SiSDK3

PKMN_SIZE_ASSERT(SiSDK3::SiDirectLinkedList<void**>, 0x28);
