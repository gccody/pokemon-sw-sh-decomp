// SiSDK3's map, reconstructed from its instances in YEBIS (RTTI:
// SiSDK3::SiMap<K, V, Compare, 16>): a binary tree of nodes allocated from the
// map's allocator. Placeholder members; the original header's __LINE__s are
// kept with #line.
#pragma once

#include "SiCore_Memory.h"

namespace SiSDK3 {

// The map's comparison by the key's operator< (RTTI names the template).
template <class T, int ALIGN>
struct SiMapCompareLess {
    bool operator()(const T& a, const T& b) const { return a < b; }
};

template <class K, class V, class Compare, int ALIGN = 16>
class SiMap {
public:
    // a node: its map, key and value, and its links
    struct Unk_Node {
        // a red leaf of the map (inline in the insert)
        Unk_Node(SiMap* pMap, const K& key, V value)
            : m_pMap(pMap), m_key(key), m_value(value), m_pParent(nullptr), m_pLeft(nullptr), m_pRight(nullptr),
              field_30(1) {}
        ~Unk_Node();

        SiMap* m_pMap;
        K m_key;
        V m_value;
        Unk_Node* m_pParent;
        Unk_Node* m_pLeft;
        Unk_Node* m_pRight;
        u8 field_30;  // the node's colour in the tree (1: red)
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

        // moves on to the node after this one (Unk_Next's order; inline in
        // the erase: placeholder name)
        void Unk_Advance() {
            if (m_pNode->m_pLeft != nullptr) {
                m_pNode = m_pNode->m_pLeft;
            } else if (m_pNode->m_pRight != nullptr) {
                m_pNode = m_pNode->m_pRight;
            } else {
                for (;;) {
                    Unk_Node* pParent = m_pNode->m_pParent;
                    if (pParent == nullptr) {
                        m_pNode = nullptr;
                        return;
                    }
                    if (pParent->m_pRight != nullptr && pParent->m_pRight != m_pNode) {
                        m_pNode = pParent->m_pRight;
                        return;
                    }
                    m_pNode = pParent;
                }
            }
        }

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
    // the same walk moving a node variable on (inline: placeholder name).
    // Loops over the map written with it are the original's: the root goes
    // straight into the loop's node register and each way to the next node
    // enters the loop's body without a test (SiGfxFreeTypeManager::vf14);
    // with Unk_Next the new node is tested again where the ways meet.
    static void Unk_AdvanceNode(Unk_Node*& pNode) {
        if (pNode->m_pLeft != nullptr) {
            pNode = pNode->m_pLeft;
        } else if (pNode->m_pRight != nullptr) {
            pNode = pNode->m_pRight;
        } else {
            for (;;) {
                Unk_Node* pChild = pNode;
                pNode = pNode->m_pParent;
                if (pNode == nullptr) {
                    return;
                }
                if (pNode->m_pRight != nullptr && pNode->m_pRight != pChild) {
                    pNode = pNode->m_pRight;
                    return;
                }
            }
        }
    }

    // 0x71004c09a0 (SiKernel's map): adds a value under a key
    bool Unk_4c09a0(const K& key, V value);

    // the red-black tree's balancing after an insert, case by case, and its
    // rotations (inline: placeholder names)
    static void Unk_SetColour(Unk_Node* pNode, u8 colour) { pNode->field_30 = colour; }
    static Unk_Node* Unk_Grandparent(Unk_Node* pNode) {
        if (pNode != nullptr && pNode->m_pParent != nullptr) {
            return pNode->m_pParent->m_pParent;
        }
        return nullptr;
    }
    static Unk_Node* Unk_Sibling(Unk_Node* pNode) {
        Unk_Node* pParent = pNode->m_pParent;
        if (pParent == nullptr) {
            return nullptr;
        }
        if (pNode == pParent->m_pLeft) {
            return pParent->m_pRight;
        }
        return pParent->m_pLeft;
    }
    static Unk_Node* Unk_Uncle(Unk_Node* pNode) {
        Unk_Node* pParent = pNode->m_pParent;
        if (pParent == nullptr || pParent->m_pParent == nullptr) {
            return nullptr;
        }
        Unk_Node* pGrandparent = pParent->m_pParent;
        if (pParent == pGrandparent->m_pLeft) {
            return pGrandparent->m_pRight;
        }
        return pGrandparent->m_pLeft;
    }
    void Unk_RotateLeft(Unk_Node* pNode) {
        if (pNode == nullptr) {
            return;
        }
        Unk_Node* pRight = pNode->m_pRight;
        if (pRight != nullptr) {
            pNode->m_pRight = pRight->m_pLeft;
            if (pRight->m_pLeft != nullptr) {
                pRight->m_pLeft->m_pParent = pNode;
            }
        }
        if (m_pRoot == pNode) {
            m_pRoot = pRight;
            if (pRight != nullptr) {
                pRight->m_pParent = nullptr;
            }
        } else {
            Unk_Node* pParent = pNode->m_pParent;
            if (pRight != nullptr) {
                pRight->m_pParent = pParent;
            }
            if (pParent != nullptr) {
                if (pParent->m_pLeft == pNode) {
                    pParent->m_pLeft = pRight;
                } else {
                    pParent->m_pRight = pRight;
                }
            }
        }
        if (pRight != nullptr) {
            pRight->m_pLeft = pNode;
        }
        pNode->m_pParent = pRight;
    }
    void Unk_RotateRight(Unk_Node* pNode) {
        if (pNode == nullptr) {
            return;
        }
        Unk_Node* pLeft = pNode->m_pLeft;
        if (pLeft != nullptr) {
            pNode->m_pLeft = pLeft->m_pRight;
            if (pLeft->m_pRight != nullptr) {
                pLeft->m_pRight->m_pParent = pNode;
            }
        }
        if (m_pRoot == pNode) {
            m_pRoot = pLeft;
            if (pLeft != nullptr) {
                pLeft->m_pParent = nullptr;
            }
        } else {
            Unk_Node* pParent = pNode->m_pParent;
            if (pLeft != nullptr) {
                pLeft->m_pParent = pParent;
            }
            if (pParent != nullptr) {
                if (pParent->m_pLeft == pNode) {
                    pParent->m_pLeft = pLeft;
                } else {
                    pParent->m_pRight = pLeft;
                }
            }
        }
        if (pLeft != nullptr) {
            pLeft->m_pRight = pNode;
        }
        pNode->m_pParent = pLeft;
    }
    // 0x71004c0e60 (SiKernel's map): takes a node out; the position after it
    Unk_Iterator Unk_4c0e60(const Unk_Iterator& position);

    SiMap() : m_pAllocator(nullptr), m_count(0), m_pRoot(nullptr) { m_pAllocator = Unk_4bc640(); }
    virtual ~SiMap();

    // empties the map: the destructor's body (inline: placeholder name)
    void Unk_Clear();

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

// The insert and the erase are compiled only where a translation unit asks
// for them (each instance is its own TU's in the original).
#ifdef UNK_SIMAP_MEMBERS_DEFINE
// The insert's balancing (placeholder name): the textbook loop, which goes
// up while the node isn't the root and its parent is red. Inlined into the
// insert, as a static function with one caller is. Written as a recursion on
// the grandparent, the node is the function's argument when InstCombine runs
// and the compares with the parent's children swap their operands; the root's
// test in the loop's condition lets the value propagation know the node isn't
// null on the path without rotations (the node's test stays after a rotation),
// and the grandparent's colour goes through a function so that the stores
// through a null grandparent stay.
template <class M, class N>
static void Unk_SiMapInsertFix(M* pMap, N* pNode) {
    while (pNode != pMap->m_pRoot && pNode->m_pParent->field_30) {
        N* pUncle = M::Unk_Uncle(pNode);
        if (pUncle != nullptr && pUncle->field_30) {
            pNode->m_pParent->field_30 = 0;
            pUncle->field_30 = 0;
            pUncle->m_pParent->field_30 = 1;
            pNode = pUncle->m_pParent;
            if (pNode == pMap->m_pRoot) {
                pNode->field_30 = 0;
            }
            continue;
        }
        N* pGrandparent = pNode->m_pParent->m_pParent;
        if (pNode == pNode->m_pParent->m_pRight && pNode->m_pParent == pGrandparent->m_pLeft) {
            pMap->Unk_RotateLeft(pNode->m_pParent);
            pNode = pNode->m_pLeft;
        } else if (pNode == pNode->m_pParent->m_pLeft && pNode->m_pParent == pGrandparent->m_pRight) {
            pMap->Unk_RotateRight(pNode->m_pParent);
            pNode = pNode->m_pRight;
        }
        pNode->m_pParent->field_30 = 0;
        pGrandparent = M::Unk_Grandparent(pNode);
        M::Unk_SetColour(pGrandparent, 1);
        if (pNode == pNode->m_pParent->m_pLeft && pNode->m_pParent == pGrandparent->m_pLeft) {
            pMap->Unk_RotateRight(pGrandparent);
        } else {
            pMap->Unk_RotateLeft(pGrandparent);
        }
        return;
    }
}
// 0x71004c09a0 (SiKernel's map)
template <class K, class V, class Compare, int ALIGN>
bool SiMap<K, V, Compare, ALIGN>::Unk_4c09a0(const K& key, V value) {
    // (the key is read before the allocation)
    K nodeKey = key;
#line 971
    Unk_Node* pNode = UNK_SI_NEW(m_pAllocator, ALIGN) Unk_Node(this, nodeKey, value);
    if (m_pRoot == nullptr) {
        m_pRoot = pNode;
        pNode->field_30 = 0;
    } else {
        Unk_Node* pCurrent = m_pRoot;
        for (;;) {
            if (Compare()(pNode->m_key, pCurrent->m_key)) {
                if (pCurrent->m_pLeft == nullptr) {
                    pNode->m_pParent = pCurrent;
                    pCurrent->m_pLeft = pNode;
                    break;
                }
                pCurrent = pCurrent->m_pLeft;
            } else {
                if (pCurrent->m_pRight == nullptr) {
                    pNode->m_pParent = pCurrent;
                    pCurrent->m_pRight = pNode;
                    break;
                }
                pCurrent = pCurrent->m_pRight;
            }
        }
        pNode->field_30 = 1;
    }
    m_count++;
    if (pNode == m_pRoot) {
        pNode->field_30 = 0;
        return true;
    }
    Unk_SiMapInsertFix(this, pNode);
    return true;
}
// 0x71004c0e60 (SiKernel's map): takes a node out, the next one in order
// standing in for it when it has two children, and rebalances the tree (the
// textbook red-black cases, a missing child standing in by its parent)
// NON_MATCHING: 1692 bytes for 1672. The original reloads the node's
// children after the result's advance (its store to the result is taken as
// a possible alias; here the result is a noalias sret and the loads are
// shared), which changes the first blocks' layout and registers (a capture
// of the result, e.g. an assignment that tests `this != &other`, gives those
// reloads and the advance loop's store of each parent; nothing in the
// original's code shows such a capture); in the
// balancing the second rotations' ends and some reloads of the parent
// differ. (Round 3: with a capture that emits nothing,
// `__builtin_assume(&result != &position)` after the result's construction,
// the stand-in child chosen right first (`m_pRight != nullptr ? m_pRight :
// m_pLeft`), the last case's parent read once into pParent and the leaf's
// unlink comparing `pRemoved == parent->m_pRight`, 316 of the 418
// instructions line up with the original's, against 48 here; what is left
// is the first test, of the right child (both children loaded by one ldp).
// Without the capture none of these changes helps. Tried for a natural
// capture: an iterator operator= that tests `this != &other` (in the
// advance, or assigning a copy), the advance on a temporary.)
template <class K, class V, class Compare, int ALIGN>
typename SiMap<K, V, Compare, ALIGN>::Unk_Iterator SiMap<K, V, Compare, ALIGN>::Unk_4c0e60(
    const Unk_Iterator& position) {
    Unk_Node* pNode = position.m_pNode;
    Unk_Iterator result(this, pNode);
    if (pNode != nullptr) {
        result.Unk_Advance();
    }
    // the node that leaves its place: the node, or the next one in order
    Unk_Node* pRemoved;
    bool bMoved;
    if (pNode->m_pLeft == nullptr || pNode->m_pRight == nullptr) {
        pRemoved = pNode;
        bMoved = false;
    } else {
        pRemoved = pNode->m_pRight;
        while (pRemoved->m_pLeft != nullptr) {
            pRemoved = pRemoved->m_pLeft;
        }
        bMoved = true;
    }
    Unk_Node* pChild = pRemoved->m_pLeft != nullptr ? pRemoved->m_pLeft : pRemoved->m_pRight;
    if (pChild != nullptr) {
        if (m_pRoot == pRemoved) {
            m_pRoot = pChild;
        } else if (pRemoved->m_pParent->m_pRight == pRemoved) {
            pRemoved->m_pParent->m_pRight = pChild;
        } else {
            pRemoved->m_pParent->m_pLeft = pChild;
        }
        pChild->m_pParent = pRemoved->m_pParent;
    }
    if (!pRemoved->field_30) {
        if (pChild != nullptr && pChild->field_30) {
            pChild->field_30 = 0;
        } else {
            Unk_Node* pFix = pChild;
            if (pFix == nullptr) {
                pFix = pRemoved;
                pFix->field_30 = 0;
            }
            while (pFix != m_pRoot) {
                Unk_Node* pParent = pFix->m_pParent;
                Unk_Node* pSibling = Unk_Sibling(pFix);
                if (pSibling != nullptr && pSibling->field_30) {
                    pSibling->field_30 = 0;
                    pParent->field_30 = 1;
                    if (pFix == pParent->m_pLeft) {
                        Unk_RotateLeft(pParent);
                    } else {
                        Unk_RotateRight(pParent);
                    }
                }
                pSibling = Unk_Sibling(pFix);
                if (!pSibling->field_30 && (pSibling->m_pRight == nullptr || !pSibling->m_pRight->field_30) &&
                    (pSibling->m_pLeft == nullptr || !pSibling->m_pLeft->field_30)) {
                    pSibling->field_30 = 1;
                    pFix = pParent;
                    if (!pFix->field_30) {
                        continue;
                    }
                    pFix->field_30 = 0;
                    break;
                }
                if (!pSibling->field_30) {
                    if (pFix == pParent->m_pLeft &&
                        (pSibling->m_pRight == nullptr || !pSibling->m_pRight->field_30) &&
                        (pSibling->m_pLeft != nullptr && pSibling->m_pLeft->field_30)) {
                        pSibling->field_30 = 1;
                        pSibling->m_pLeft->field_30 = 0;
                        Unk_RotateRight(pSibling);
                    } else if (pFix == pParent->m_pRight &&
                               (pSibling->m_pLeft == nullptr || !pSibling->m_pLeft->field_30) &&
                               (pSibling->m_pRight != nullptr && pSibling->m_pRight->field_30)) {
                        pSibling->field_30 = 1;
                        pSibling->m_pRight->field_30 = 0;
                        Unk_RotateLeft(pSibling);
                    }
                }
                pSibling = Unk_Sibling(pFix);
                pSibling->field_30 = pFix->m_pParent->field_30;
                pFix->m_pParent->field_30 = 0;
                if (pFix == pFix->m_pParent->m_pLeft) {
                    if (pSibling->m_pRight != nullptr) {
                        pSibling->m_pRight->field_30 = 0;
                    }
                    Unk_RotateLeft(pFix->m_pParent);
                } else {
                    if (pSibling->m_pLeft != nullptr) {
                        pSibling->m_pLeft->field_30 = 0;
                    }
                    Unk_RotateRight(pFix->m_pParent);
                }
                break;
            }
        }
        pRemoved->field_30 = 0;
    }
    if (pChild == nullptr) {
        // a leaf: unlinked only now (it stood in for its missing child)
        if (pRemoved->m_pParent != nullptr && pRemoved->m_pParent->m_pRight == pRemoved) {
            pRemoved->m_pParent->m_pRight = nullptr;
        } else if (pRemoved->m_pParent != nullptr && pRemoved->m_pParent->m_pLeft == pRemoved) {
            pRemoved->m_pParent->m_pLeft = nullptr;
        } else {
            m_pRoot = nullptr;
        }
    }
    if (bMoved) {
        // the next node takes the removed one's place
        if (pNode->m_pParent == nullptr) {
            m_pRoot = pRemoved;
        } else if (pNode == pNode->m_pParent->m_pRight) {
            pNode->m_pParent->m_pRight = pRemoved;
        } else {
            pNode->m_pParent->m_pLeft = pRemoved;
        }
        pRemoved->field_30 = pNode->field_30;
        pRemoved->m_pParent = pNode->m_pParent;
        pRemoved->m_pLeft = pNode->m_pLeft;
        pRemoved->m_pRight = pNode->m_pRight;
        if (pRemoved->m_pLeft != nullptr) {
            pRemoved->m_pLeft->m_pParent = pRemoved;
        }
        if (pRemoved->m_pRight != nullptr) {
            pRemoved->m_pRight->m_pParent = pRemoved;
        }
    }
    pNode->m_pLeft = nullptr;
    pNode->m_pRight = nullptr;
    pNode->m_pParent = nullptr;
    if (pNode != nullptr) {
#line 1252
        SI_DELETE(m_pAllocator, pNode);
    }
    m_count--;
    return result;
}
#endif

template <class K, class V, class Compare, int ALIGN>
inline void SiMap<K, V, Compare, ALIGN>::Unk_Clear() {
    if (m_pAllocator != nullptr && m_pRoot != nullptr) {
#line 951
        SI_DELETE(m_pAllocator, m_pRoot);
        m_pRoot = nullptr;
    }
    m_count = 0;
    m_pRoot = nullptr;
}

}  // namespace SiSDK3
