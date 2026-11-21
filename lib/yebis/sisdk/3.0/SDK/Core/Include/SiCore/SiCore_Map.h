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
        bool field_30;  // the node's colour in the tree (set: red)
    };

    // with an allocator, or the kernel's for a null one (inline in every
    // caller)
    explicit SiMap(ISiAllocator* pAllocator) : m_pAllocator(pAllocator), m_count(0), m_pRoot(nullptr) {
        if (m_pAllocator == nullptr) {
            m_pAllocator = Unk_4bc640();
        }
    }
    // a position in the map: its copy constructor is its own (0x71004c0e60
    // returns one in memory)
    struct Unk_Iterator {
        Unk_Iterator(SiMap* pMap, Unk_Node* pNode) : m_pMap(pMap), m_pNode(pNode) {}
        Unk_Iterator(const Unk_Iterator& other) : m_pMap(other.m_pMap), m_pNode(other.m_pNode) {}

        SiMap* m_pMap;
        Unk_Node* m_pNode;
    };

    // the node of a key, or none (inline in every caller: placeholder name)
    Unk_Iterator Unk_Find(const K& key) {
        Unk_Node* pNode = m_pRoot;
        Unk_Node* pPrev = nullptr;
        while (pNode != nullptr && pNode != pPrev) {
            pPrev = pNode;
            if (Compare()(key, pNode->m_key)) {
                pNode = pNode->m_pLeft;
            } else if (Compare()(pNode->m_key, key)) {
                pNode = pNode->m_pRight;
            } else {
                return Unk_Iterator(this, pNode);
            }
        }
        return Unk_Iterator(this, nullptr);
    }

    // the node after one, a node before the ones under it (inline:
    // placeholder name)
    static Unk_Node* Unk_Next(Unk_Node* pNode) {
        if (pNode->m_pLeft != nullptr) {
            return pNode->m_pLeft;
        }
        if (pNode->m_pRight != nullptr) {
            return pNode->m_pRight;
        }
        for (;;) {
            Unk_Node* pParent = pNode->m_pParent;
            if (pParent == nullptr) {
                return nullptr;
            }
            Unk_Node* pRight = pParent->m_pRight;
            if (pRight != nullptr && pRight != pNode) {
                return pRight;
            }
            pNode = pParent;
        }
    }

    // 0x71004c09a0 (SiKernel's map): adds a value under a key
    bool Unk_4c09a0(const K& key, V value);
    // 0x71004c0e60 (SiKernel's map): takes a node out; the position after it
    Unk_Iterator Unk_4c0e60(const Unk_Iterator& position);

    SiMap() : m_pAllocator(nullptr), m_count(0), m_pRoot(nullptr) { m_pAllocator = Unk_4bc640(); }
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
