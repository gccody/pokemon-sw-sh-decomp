// SiSDK3's map, reconstructed from its instances in YEBIS (RTTI:
// SiSDK3::SiMap<K, V, Compare, 16>): a binary tree of nodes allocated from the
// map's allocator. Placeholder members; the original header's __LINE__s are
// kept with #line.
#pragma once

#include "SiCore_Memory.h"

namespace SiSDK3 {

template <class K, class V, class Compare, int ALIGN = 16>
class SiMap {
public:
    // a node: its map, key and value, and its links
    struct Unk_Node {
        ~Unk_Node();

        SiMap* m_pMap;
        K m_key;
        V m_value;
        Unk_Node* m_pParent;
        Unk_Node* m_pLeft;
        Unk_Node* m_pRight;
    };

    virtual ~SiMap();

    ISiAllocator* m_pAllocator;
    size_t m_count;
    Unk_Node* m_pRoot;
};

template <class K, class V, class Compare, int ALIGN>
SiMap<K, V, Compare, ALIGN>::Unk_Node::~Unk_Node() {
    if (m_pMap != nullptr) {
        // one line each in the original (its lines 199 and 200)
#line 199
        if (m_pLeft != nullptr) { SI_DELETE(m_pMap->m_pAllocator, m_pLeft); m_pLeft = nullptr; }
        if (m_pRight != nullptr) { SI_DELETE(m_pMap->m_pAllocator, m_pRight); m_pRight = nullptr; }
    }
    m_pLeft = nullptr;
    m_pRight = nullptr;
}

template <class K, class V, class Compare, int ALIGN>
SiMap<K, V, Compare, ALIGN>::~SiMap() {
    if (m_pAllocator != nullptr && m_pRoot != nullptr) {
#line 951
        SI_DELETE(m_pAllocator, m_pRoot);
        m_pRoot = nullptr;
    }
    m_count = 0;
    m_pRoot = nullptr;
}

}  // namespace SiSDK3
