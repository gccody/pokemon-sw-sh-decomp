// Scope: common
// SiSDK3::SiPool<SiGfxQuadTree<SiGfxFreeTypeFaceCache::CacheData>::QuadNode,
// 16>'s members (SiCore_Pool.h) and its nodes' array's reserve: explicit
// instantiations. The node is as far as that code shows it: the reserve
// constructs each node and copies one as two runs of bytes, its links and
// index, then the rest without its last three bytes, which is how two base
// classes with constructors are copied. Placeholder names for the two.
#define UNK_SIPOOL_WHOLE_ELEMENT
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_Pool.h>

namespace SiSDK3 {

class SiGfxFreeTypeFaceCache {
public:
    struct CacheData;
};

template <class T>
class SiGfxQuadTree {
public:
    struct QuadNode;

    // a node's links and its index in the pool
    struct Unk_Links {
        Unk_Links() : m_pPrev(nullptr), m_pNext(nullptr), field_10(-1) {}

        QuadNode* m_pPrev;
        QuadNode* m_pNext;
        s64 field_10;
    };
    // whether a node is in use, and what the tree keeps in it: four
    // pointers that a loop clears (a quad tree's node has four children),
    // two words, a number and a flag. The reserve's loop of constructors
    // shows the shape: it isn't unrolled, which it is with fewer stores in
    // it, and it clears the six words from the last pair to the first.
    struct Unk_Data {
        Unk_Data() : field_18(false), field_40(0), field_48(0), field_50(-1), field_54(false) {
            for (int i = 0; i < 4; i++) {
                field_20[i] = nullptr;
            }
        }

        bool field_18;
        QuadNode* field_20[4];
        u64 field_40;
        u64 field_48;
        s32 field_50;
        bool field_54;
    };

    struct QuadNode : Unk_Links, Unk_Data {};
};
PKMN_SIZE_ASSERT(SiGfxQuadTree<SiGfxFreeTypeFaceCache::CacheData>::QuadNode, 0x58);

}  // namespace SiSDK3

using namespace SiSDK3;

typedef SiGfxQuadTree<SiGfxFreeTypeFaceCache::CacheData>::QuadNode Unk_Node;

// 0x71005329e0 = _ZN6SiSDK37SiArrayINS_13SiGfxQuadTreeINS_22SiGfxFreeTypeFaceCache9CacheDataEE8QuadNodeELi16EE10Unk_4bf190Emb
template bool SiArray<Unk_Node, 16>::Unk_4bf190(size_t, bool);
// 0x7100531df0 = _ZN6SiSDK36SiPoolINS_13SiGfxQuadTreeINS_22SiGfxFreeTypeFaceCache9CacheDataEE8QuadNodeELi16EE3vf2Em
template bool SiPool<Unk_Node, 16>::vf2(size_t);
// 0x7100532300 = _ZN6SiSDK36SiPoolINS_13SiGfxQuadTreeINS_22SiGfxFreeTypeFaceCache9CacheDataEE8QuadNodeELi16EE3vf5Em
template bool SiPool<Unk_Node, 16>::vf5(size_t);
// 0x7100533880 = _ZN6SiSDK36SiPoolINS_13SiGfxQuadTreeINS_22SiGfxFreeTypeFaceCache9CacheDataEE8QuadNodeELi16EE10Unk_4be3f0EPS5_
template void SiPool<Unk_Node, 16>::Unk_4be3f0(Unk_Node*);
