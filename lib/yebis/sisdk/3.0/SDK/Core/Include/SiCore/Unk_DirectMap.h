// SiSDK3::SiDirectMap<K, V, Compare> (RTTI names the template; the header's
// name isn't in the executable): a map whose nodes it doesn't allocate, so
// emptying it only unlinks them. Placeholder members, as far as the FreeType
// face's code shows them (its constructor, its destructor 0x71005004c0 and
// 0x71005011a0, and the nodes' unlinking 0x7100501ba0).
#pragma once

#include "SiCore_Memory.h"

namespace SiSDK3 {

// The map's comparison by the key's operator< (RTTI names the template).
template <class T>
struct SiDirectMapCompareLess;

template <class K, class V, class Compare>
class SiDirectMap {
public:
    // a node: unlinks the ones under it, then itself
    struct Unk_Node {
        void Unk_Clear() {
            if (m_pLeft != nullptr) {
                m_pLeft->Unk_Clear();
                m_pLeft = nullptr;
            }
            if (m_pRight != nullptr) {
                m_pRight->Unk_Clear();
                m_pRight = nullptr;
            }
            field_20 = 0;
        }

        u8 _0[0x20];
        u64 field_20;
        Unk_Node* m_pLeft;
        Unk_Node* m_pRight;
        u64 field_38;
        K m_key;
        V m_value;
    };

    // with an allocator, or the kernel's for a null one
    explicit SiDirectMap(ISiAllocator* pAllocator) : m_pAllocator(pAllocator), m_count(0), m_pRoot(nullptr) {
        if (m_pAllocator == nullptr) {
            m_pAllocator = Unk_4bc640();
        }
    }
    virtual ~SiDirectMap() { Unk_Clear(); }

    // the node of a key, or none (inline: placeholder name)
    Unk_Node* Unk_Find(const K& key) {
        Unk_Node* pNode = m_pRoot;
        while (pNode != nullptr) {
            if (key < pNode->m_key) {
                pNode = pNode->m_pLeft;
            } else if (pNode->m_key < key) {
                pNode = pNode->m_pRight;
            } else {
                return pNode;
            }
        }
        return nullptr;
    }

    // adds a value (placeholder name; 0x7100500a30 for the face's glyphs)
    bool Unk_Insert(const K& key, V value);

    // empties the map (inline: placeholder name)
    void Unk_Clear() {
        if (m_pRoot != nullptr) {
            m_pRoot->Unk_Clear();
            m_pRoot = nullptr;
        }
        m_count = 0;
    }

    ISiAllocator* m_pAllocator;
    size_t m_count;
    Unk_Node* m_pRoot;
};

}  // namespace SiSDK3
