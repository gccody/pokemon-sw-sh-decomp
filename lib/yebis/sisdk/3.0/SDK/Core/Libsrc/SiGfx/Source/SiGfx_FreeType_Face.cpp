// Scope: common
// SiSDK3::SiGfxFreeTypeFace: its construction and destruction, and the
// reference counts its header defines.
#define UNK_SIGFX_FREETYPE_FACE_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/SiGfx_FreeType_Face.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_StringFuncs.h>

// FreeType's functions that the face calls (C; the types are FreeType's as
// far as the calls need them).
extern "C" {
u32 FT_Get_Char_Index(FT_FaceRec_* face, unsigned long charcode);
s32 FT_Load_Glyph(FT_FaceRec_* face, u32 glyph_index, s32 load_flags);
s32 FT_Render_Glyph(void* slot, s32 render_mode);
s32 FT_Set_Char_Size(FT_FaceRec_* face, s64 char_width, s64 char_height, u32 horz_resolution, u32 vert_resolution);
}

// FreeType's face as the face reads it.
static inline const Unk_FTFace* Unk_FTFaceOf(FT_FaceRec_* face) {
    return reinterpret_cast<const Unk_FTFace*>(face);
}

// 0x71004ed6d0 (leafgen's name): the resolution, 96
s32 Unk_4ed6d0_get();

// 0x710050b590: the FreeType library's release of a face (placeholder name
// and types: its object, then the face)
void Unk_50b590(void* library, void* face);

namespace SiSDK3 {

// 0x71004ffd70
// NON_MATCHING: registers only: this keeps the name's buffer's address from
// the string's construction in x22 for the allocator's change; the original
// computes it again there (4 bytes).
// Also tried: the zeroes before or after the allocator's change, the scales
// in the body, field_20 in the initialiser list, field_18 in the body.
SiGfxFreeTypeFace::SiGfxFreeTypeFace(ISiAllocator* pAllocator)
    : field_8(nullptr), field_18(nullptr), field_60(nullptr), field_68(0), field_70(pAllocator), field_98(pAllocator, true),
      field_1c0(nullptr), field_1c8(0), field_1cc(0), field_1d0(0), field_1d4(0), field_1d8(0.0f), field_1dc(0.0f),
      field_1e0(0.0f), field_1e4(0.0f), field_1e8(0.0f), field_1ec(0.0f) {
    field_20.Unk_SetAllocator(pAllocator);
    Unk_StringAssign(&field_20, "");
    field_50 = 0;
    field_54 = 0;
    field_58 = false;
    field_59 = false;
    field_5a = false;
    field_5b = false;
    field_5c = false;
}

// 0x7100500010 (D2), 0x7100500500 (D0)
SiGfxFreeTypeFace::~SiGfxFreeTypeFace() {
    if (field_1c0 != nullptr) {
        field_1c0->vf3();
        field_1c0 = nullptr;
    }
    field_70.Unk_Clear();
    field_98.Unk_4be7d0();
}

// 0x7100500810: releases the face
void SiGfxFreeTypeFace::Unk_500810() {
    if (field_18 == nullptr) {
        return;
    }
    if (field_1c0 != nullptr) {
        field_1c0->vf3();
        field_1c0 = nullptr;
    }
    Unk_50b590(reinterpret_cast<void*>(field_18), field_60);
    field_60 = nullptr;
    field_1c8 = 0;
    field_1cc = 0;
    field_1d0 = 0;
    field_1d4 = 0;
    field_1d8 = 0.0f;
    field_1dc = 0.0f;
    field_1e0 = 0.0f;
    field_1e4 = 0.0f;
    field_1e8 = 0.0f;
    field_1ec = 0.0f;
    Unk_StringAssign(&field_20, "");
    field_50 = 0;
    field_54 = 0;
    field_58 = false;
    field_59 = false;
    field_5a = false;
    field_5b = false;
    field_5c = false;
}

// 0x7100500da0: forgets the glyphs
void SiGfxFreeTypeFace::Unk_500da0() {
    field_70.Unk_Clear();
    field_98.Unk_4bd7e0();
}

// 0x7100500890
void* SiGfxFreeTypeFace::Unk_500890(u32 character) {
    wchar_t key = character;
    auto* node = field_70.Unk_Find(key);
    if (node != nullptr) {
        return node->m_value;
    }
    SiGfxFreeTypeGlyph* glyph = field_98.Unk_Alloc();
    if (glyph == nullptr) {
        return nullptr;
    }
    u32 index = FT_Get_Char_Index(field_60, character);
    if (FT_Load_Glyph(field_60, index, 0) != 0 || FT_Render_Glyph(Unk_FTFaceOf(field_60)->glyph, field_68) != 0) {
        return nullptr;
    }
    glyph->field_50 = character;
    glyph->field_54 = index;
    field_1c0->Unk_531420(glyph);
    field_70.Unk_Insert(key, glyph);
    return glyph;
}

// 0x7100500550
void SiGfxFreeTypeFace::Unk_500550(SiGfxFreeTypeFaceCache* pCache) {
    if (pCache != nullptr) {
        pCache->vf2();
    }
    if (field_1c0 != nullptr) {
        field_1c0->vf3();
    }
    field_1c0 = pCache;
    if (pCache != nullptr) {
        pCache->Unk_530f20(this);
    }
}

// 0x71005005c0
bool SiGfxFreeTypeFace::Unk_5005c0(const Unk_FontDesc* desc) {
    if (desc->field_48 != nullptr) {
        if (!field_18->Unk_50ba10(&field_60, desc->field_48, desc->field_50, desc->field_30)) {
            return false;
        }
    } else if (!field_18->Unk_50b210(&field_60, Unk_StringCStr(&desc->field_0), desc->field_30)) {
        return false;
    }
    Unk_5006c0(desc->field_34, desc->field_38);
    field_98.vf2(desc->field_44);
    field_20 = desc->field_0;
    field_50 = desc->field_34;
    field_54 = desc->field_38;
    const Unk_FTFace* face = Unk_FTFaceOf(field_60);
    field_58 = (face->field_18 & 1) != 0;  // FT_STYLE_FLAG_ITALIC
    field_59 = (face->field_18 & 2) != 0;  // FT_STYLE_FLAG_BOLD
    field_5a = (face->field_10 & 4) != 0;  // FT_FACE_FLAG_FIXED_WIDTH
    field_5b = (face->field_10 & 0x40) != 0;  // FT_FACE_FLAG_KERNING
    field_5c = (face->field_10 & 0x20) != 0;  // FT_FACE_FLAG_VERTICAL
    return true;
}

// NON_MATCHING: scheduling only, in the measures at the size: the original
// converts both of the x products before storing the x scale and stores the
// first two integers after the third (tried every order of the statements,
// the scales in locals, the products both ways round).
// Also tried (216 orders): the scales stored first, between or after the
// products, each product from the member, the size's field or a local.
// 0x71005006c0
bool SiGfxFreeTypeFace::Unk_5006c0(s32 width, s32 height) {
    if (field_18 == nullptr) {
        return false;
    }
    if (Unk_4ed6d0_get() <= 0) {
        return false;
    }
    if (FT_Set_Char_Size(field_60, width << 6, height << 6, 96, 96) != 0) {
        return false;
    }
    field_50 = width;
    field_54 = height;
    const Unk_FTFace* face = Unk_FTFaceOf(field_60);
    f32 units = face->field_88;
    field_1e0 = face->field_68 / units;
    field_1ec = face->field_70 / units;
    field_1e4 = face->field_78 / units;
    field_1e8 = face->field_80 / units;
    const Unk_FTSize* size = face->field_a0;
    if (size != nullptr) {
        field_1d8 = size->field_18;
        field_1dc = size->field_1a;
        field_1c8 = static_cast<s32>(field_1d8 * field_1e0);
        field_1cc = static_cast<s32>(field_1d8 * field_1e4);
        field_1d0 = static_cast<s32>(field_1dc * field_1e8);
        field_1d4 = static_cast<s32>(field_1dc * field_1ec);
    }
    return true;
}

}  // namespace SiSDK3

namespace SiSDK3 {

// The map's node as its insertion sees it (placeholder names): Unk_DirectMap.h's
// Unk_Node, with its parent at 0x20, its two children as an array (the
// original stores a child through a computed offset) and its colour in the
// byte at 0x38 (true: red).
template <class K, class V>
struct Unk_MapNode {
    u8 _0[0x20];
    Unk_MapNode* m_pParent;
    Unk_MapNode* m_pChild[2];
    bool m_bRed;
    u8 _39[7];
    K m_key;
    V m_value;
};

// Turns x's right child into its parent (placeholder name).
template <class N>
static inline void Unk_RotateLeft(N** root, N* x) {
    if (x == nullptr) {
        return;
    }
    N* y = x->m_pChild[1];
    if (y != nullptr) {
        x->m_pChild[1] = y->m_pChild[0];
        if (y->m_pChild[0] != nullptr) {
            y->m_pChild[0]->m_pParent = x;
        }
    }
    if (*root == x) {
        *root = y;
        if (y != nullptr) {
            y->m_pParent = nullptr;
        }
    } else {
        N* parent = x->m_pParent;
        if (y != nullptr) {
            y->m_pParent = parent;
        }
        if (parent != nullptr) {
            if (parent->m_pChild[0] == x) {
                parent->m_pChild[0] = y;
            } else {
                parent->m_pChild[1] = y;
            }
        }
    }
    if (y != nullptr) {
        y->m_pChild[0] = x;
    }
    x->m_pParent = y;
}

// Turns x's left child into its parent (placeholder name).
template <class N>
static inline void Unk_RotateRight(N** root, N* x) {
    if (x == nullptr) {
        return;
    }
    N* y = x->m_pChild[0];
    if (y != nullptr) {
        x->m_pChild[0] = y->m_pChild[1];
        if (y->m_pChild[1] != nullptr) {
            y->m_pChild[1]->m_pParent = x;
        }
    }
    if (*root == x) {
        *root = y;
        if (y != nullptr) {
            y->m_pParent = nullptr;
        }
    } else {
        N* parent = x->m_pParent;
        if (y != nullptr) {
            y->m_pParent = parent;
        }
        if (parent != nullptr) {
            if (parent->m_pChild[0] == x) {
                parent->m_pChild[0] = y;
            } else {
                parent->m_pChild[1] = y;
            }
        }
    }
    if (y != nullptr) {
        y->m_pChild[1] = x;
    }
    x->m_pParent = y;
}

// A node's grandparent, if it has one (placeholder name).
template <class N>
static inline N* Unk_Grandparent(N* node) {
    if (node != nullptr && node->m_pParent != nullptr) {
        return node->m_pParent->m_pParent;
    }
    return nullptr;
}

// A node's sibling, if it has one (placeholder name).
template <class N>
static inline N* Unk_Sibling(N* node) {
    if (node == nullptr || node->m_pParent == nullptr) {
        return nullptr;
    }
    N* parent = node->m_pParent;
    return node == parent->m_pChild[0] ? parent->m_pChild[1] : parent->m_pChild[0];
}

// NON_MATCHING: 32 bytes shorter. The insertion and the recolouring are the
// original's but for the order of one comparison's operands (`cmp x12, x9`
// for the parent's sibling); in the rotations' case the original merges the
// two rotations' ends (the new node through the address of the child it
// was, then its parent's colour, then the test of the node for the
// grandparent) and lays the second rotation out of line, where here each
// rotation keeps its own end. Tried: the uncle through the grandparent, the
// comparison's operands swapped, the parent's colour set in each branch.
// 0x7100500a30 (the face's glyphs, which are their own nodes): links the
// value in as a node, then rebalances the red-black tree
template <class K, class V, class Compare>
bool SiDirectMap<K, V, Compare>::Unk_Insert(const K& key, V value) {
    typedef Unk_MapNode<K, V> Node;
    K k = key;
    Node** root = reinterpret_cast<Node**>(&m_pRoot);
    Node* node = reinterpret_cast<Node*>(value);
    node->m_value = value;
    node->m_key = k;
    if (node != nullptr) {
        if (*root == nullptr) {
            *root = node;
            node->m_bRed = false;
        } else {
            Node* parent = *root;
            Node** link;
            for (;;) {
                if (k < parent->m_key) {
                    if (parent->m_pChild[0] == nullptr) {
                        link = &parent->m_pChild[0];
                        break;
                    }
                    parent = parent->m_pChild[0];
                } else {
                    if (parent->m_pChild[1] == nullptr) {
                        link = &parent->m_pChild[1];
                        break;
                    }
                    parent = parent->m_pChild[1];
                }
            }
            node->m_pParent = parent;
            *link = node;
            node->m_bRed = true;
        }
        m_count++;
    }
    if (*root == node) {
        node->m_bRed = false;
        return true;
    }
    do {
        Node* parent = node->m_pParent;
        if (!parent->m_bRed) {
            break;
        }
        Node* uncle = Unk_Sibling(parent);
        if (uncle != nullptr && uncle->m_bRed) {
            parent->m_bRed = false;
            uncle->m_bRed = false;
            uncle->m_pParent->m_bRed = true;
            node = uncle->m_pParent;
            if (node == *root) {
                node->m_bRed = false;
            }
        } else {
            Node* grandparent = parent->m_pParent;
            if (node == parent->m_pChild[1] && parent == grandparent->m_pChild[0]) {
                Unk_RotateLeft(root, parent);
                node = node->m_pChild[0];
            } else if (node == parent->m_pChild[0] && parent == grandparent->m_pChild[1]) {
                Unk_RotateRight(root, parent);
                node = node->m_pChild[1];
            }
            node->m_pParent->m_bRed = false;
            grandparent = Unk_Grandparent(node);
            grandparent->m_bRed = true;
            if (node == node->m_pParent->m_pChild[0] && node->m_pParent == grandparent->m_pChild[0]) {
                Unk_RotateRight(root, grandparent);
            } else {
                Unk_RotateLeft(root, grandparent);
            }
            break;
        }
    } while (node != *root);
    return true;
}

// NON_MATCHING: registers: in each block's array delete the original tests
// the count from the allocator (`cbz x0`) before it copies the count and
// the elements into the loop's registers; here the copies come first (the
// same code matches in SiArray<SiGfxFreeTypeGlyph>'s destructor). The block's
// null test is explicit: written as SI_DELETE's alone, clang drops it.
// Also tried: the block loop's counter as s32, s64, size_t or u32, the
// test nested or as `continue`, the block not in a local, the array emptied
// through Unk_4e3050 or Unk_FreeData, field_c zeroed first.
// 0x71005000e0 (SiGfxFreeTypeGlyph; SiCore_Pool.h declares it): frees every
// block but the first, and empties the lists. Its delete's __FILE__ is the
// header's (the last function of this file for that #line).
template <class T, int ALIGN>
void SiPool<T, ALIGN>::Unk_4be7d0() {
    m_usedList.RemoveAll();
    m_freeList.RemoveAll();
    for (int i = 0; i < static_cast<int>(m_blocks.m_itemCount); i++) {
        DataArray* block = m_blocks.m_pData[i];
        block->m_items.Unk_FreeAll();
        block->field_c = 0;
        if (i != 0 && block != nullptr) {
#line 231 "../../../../Include\\SiCore/SiCore_Pool.h"
            SI_DELETE(m_pAllocator, block);
        }
    }
    m_blocks.Unk_FreeAll();
    field_110 = 0;
    field_118 = 0;
}

template void SiPool<SiGfxFreeTypeGlyph, 16>::Unk_4be7d0();

}  // namespace SiSDK3
