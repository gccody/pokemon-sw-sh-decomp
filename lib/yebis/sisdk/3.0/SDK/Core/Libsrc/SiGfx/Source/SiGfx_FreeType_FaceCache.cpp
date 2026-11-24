// Scope: common
// SiSDK3::SiGfxFreeTypeFaceCache and its quad tree: construction and
// destruction, the tree's slots, and the reference counts its header defines.
// (Slot 4 is lib/yebis/class's.)
#define UNK_SIGFX_FREETYPE_FACECACHE_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/SiGfx_FreeType_FaceCache.h>

#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/SiGfx_FreeType_Face.h>

// 0x7100500540 (leafgen's name and type: the face's FreeType face)
struct Unk_500540;
u64 Unk_500540_get(const Unk_500540* self);

namespace SiSDK3 {

// 0x7100531240
template <class T>
bool SiGfxQuadTree<T>::vf2(u32 width, u32 height, size_t count) {
    size_t n = count > 1 ? count : 1;
    field_10.vf2(n);
    field_140 = width;
    field_144 = height;
    field_138 = field_10.Unk_Alloc();
    field_138->Unk_Reset();
    field_138->field_40.field_0 = 0;
    field_138->field_48.field_0 = 0;
    field_138->field_40.field_4 = field_140;
    field_138->field_48.field_4 = field_144;
    return true;
}

// 0x7100531750
template <class T>
void SiGfxQuadTree<T>::Unk_531750() {
    field_10.Unk_4bd7e0();
    field_138 = field_10.Unk_Alloc();
    field_138->Unk_Reset();
    field_138->field_40.field_0 = 0;
    field_138->field_48.field_0 = 0;
    field_138->field_40.field_4 = field_140;
    field_138->field_48.field_4 = field_144;
}

// 0x7100530d80
SiGfxFreeTypeFaceCache::SiGfxFreeTypeFaceCache(ISiAllocator* pAllocator, SiGfxNXDevice* pDevice)
    : field_8(pAllocator), field_18(pDevice), field_20(0), field_28(nullptr), field_30(nullptr), field_38(nullptr),
      field_40(pAllocator), field_1c0(pAllocator), field_308(2) {
    field_30c.field_0 = 0;
    field_30c.field_4 = 0;
    field_314.field_0 = 0;
    field_314.field_4 = 0;
}

// 0x7100530e20
SiGfxFreeTypeFaceCache::~SiGfxFreeTypeFaceCache() {
    Unk_Release();
}

// 0x7100530f50
bool SiGfxFreeTypeFaceCache::vf5(u32 width, u32 height) {
    field_30 = field_18->vf49(2, nullptr, 0, nullptr);
    if (field_30 == nullptr) {
        return false;
    }
    SiGfxNXTexture::Unk_Desc desc(0x3d, width, height, 0, 1, 0, 0, 0);
    if (!field_30->vf22(&desc)) {
        if (field_30 != nullptr) {
            field_30->vf3();
            field_30 = nullptr;
        }
        return false;
    }
    Unk_FaceCacheImageInfo info;
    info.field_0.field_0 = 2;
    info.field_0.field_4 = 0x3d;
    info.field_0.field_8 = width;
    info.field_0.field_c = height;
    info.field_0.field_10 = 0;
    info.field_0.field_14 = 1;
    info.field_0.field_18 = 0;
    field_40.vf8(&info.field_0);
    memset(field_40.vf17(0, 0)->field_0, 0, field_40.vf17(0, 0)->field_8);
    field_1c0.vf2(width, height, 0x1000);
    ISiGfxDescriptorTable* table = field_18->vf27(1, 0, nullptr);
    table->vf8(1, 0);
    table->vf10(1);
    table->vf12(0, field_30);
    table->vf9();
    field_38 = table;
    return true;
}

// 0x7100530f20
void SiGfxFreeTypeFaceCache::Unk_530f20(SiGfxFreeTypeFace* pFace) {
    field_28 = pFace;
    field_20 = Unk_500540_get(reinterpret_cast<const Unk_500540*>(pFace));
}

// 0x7100531390
void SiGfxFreeTypeFaceCache::vf6() {
    Unk_Release();
}

// 0x71005316f0
void SiGfxFreeTypeFaceCache::Unk_5316f0(const char* name) {
    if (field_30 != nullptr) {
        field_30->vf45(name);
    }
}

// 0x7100531710
void SiGfxFreeTypeFaceCache::Unk_531710() {
    field_1c0.Unk_531750();
    field_40.Unk_4f3700(0, 0, -1, -1);
}

// 0x7100531420
// The rectangle's scope ends before `return true`: the two failed lookups
// then leave through one cleanup block, which keeps the `mov w0, wzr` of the
// no-node branch (`cbz x0`).
bool SiGfxFreeTypeFaceCache::Unk_531420(SiGfxFreeTypeGlyph* glyph) {
    if (field_30 == nullptr) {
        return false;
    }
    if (field_30->vf19()->field_14 < 1) {
        return false;
    }
    if (field_30->vf19()->field_18 < 1) {
        return false;
    }
    Unk_FTFace* face = reinterpret_cast<Unk_FTFace*>(field_28->field_60);
    if (face == nullptr) {
        return false;
    }
    const Unk_FTGlyphSlot* slot = static_cast<const Unk_FTGlyphSlot*>(face->glyph);
    if (slot == nullptr) {
        return false;
    }
    if (slot->field_98.field_4 == 0 || slot->field_98.field_0 == 0) {
        glyph->field_58 = static_cast<s32>(slot->field_50) >> 6;
        glyph->field_5c = static_cast<s32>(slot->field_68) >> 6;
        glyph->field_60 = static_cast<s32>(slot->field_40) >> 6;
        glyph->field_64 = static_cast<s32>(slot->field_48) >> 6;
        glyph->field_68 = slot->field_98.field_4;
        glyph->field_6c = slot->field_98.field_0;
        return true;
    }
    s32 width = slot->field_98.field_4 + field_308;
    s32 height = slot->field_98.field_0 + field_308;
    {
        Unk_FaceCacheRect rect = {{0, width}, {0, height}};
        if (field_1c0.field_138 == nullptr) {
            return false;
        }
        SiGfxQuadTree<CacheData>::QuadNode* node = field_1c0.Unk_532ca0(field_1c0.field_138, &rect);
        if (node == nullptr) {
            return false;
        }
        node->field_54 = true;
        node->field_50 = static_cast<s32>(glyph->field_10);
        glyph->field_58 = static_cast<s32>(slot->field_50) >> 6;
        glyph->field_5c = static_cast<s32>(slot->field_68) >> 6;
        glyph->field_60 = static_cast<s32>(slot->field_40) >> 6;
        glyph->field_64 = static_cast<s32>(slot->field_48) >> 6;
        glyph->field_68 = slot->field_98.field_4;
        glyph->field_6c = slot->field_98.field_0;
        f32 textureWidth = static_cast<f32>(field_30->vf19()->field_14);
        f32 textureHeight = static_cast<f32>(field_30->vf19()->field_18);
        glyph->field_70 = node->field_40.field_0;
        glyph->field_74 = node->field_48.field_0;
        glyph->field_78 = node->field_40.field_4 - node->field_40.field_0;
        glyph->field_7c = node->field_48.field_4 - node->field_48.field_0;
        glyph->field_90 = node->field_40.field_4 - node->field_40.field_0 - field_308;
        glyph->field_94 = node->field_48.field_4 - node->field_48.field_0 - field_308;
        glyph->field_80 = static_cast<f32>(node->field_40.field_0) / textureWidth;
        glyph->field_84 = static_cast<f32>(node->field_48.field_0) / textureHeight;
        glyph->field_88 = static_cast<f32>(glyph->field_90) / textureWidth;
        glyph->field_8c = static_cast<f32>(glyph->field_94) / textureHeight;
        vf8(glyph, &slot->field_98, &field_40);
        if (node->field_40.field_0 < field_30c.field_0) {
            field_30c.field_0 = node->field_40.field_0;
        }
        if (node->field_48.field_0 < field_314.field_0) {
            field_314.field_0 = node->field_48.field_0;
        }
        if (node->field_40.field_4 > field_30c.field_4) {
            field_30c.field_4 = node->field_40.field_4;
        }
        if (node->field_48.field_4 > field_314.field_4) {
            field_314.field_4 = node->field_48.field_4;
        }
    }
    return true;
}

// 0x7100532ca0
// NON_MATCHING: 13 instructions, registers and the order of two loads. The
// y at which a leaf is split in two is computed again in the original (`add
// w8, w13, w8 ; sub w2, w8, w11`, (a + b) - c): with the sizes declared in
// their natural order Reassociate makes it (a - c) + b, which GVN takes from
// the rectangle's height (4 bytes less). With the node's height read before
// the rectangle's (as here) the ranks keep (a + b) - c and the size is the
// original's, but the node's pair is then loaded first and the third split's
// sum has its operands the other way round (`add w3, w11, w8` for `add w3,
// w8, w9`). The original's sum probably isn't reassociated at all (a + b with
// another use, so Reassociate doesn't break up the subtraction); 48 orders
// of the declarations and the sums were tried.
template <class T>
typename SiGfxQuadTree<T>::QuadNode* SiGfxQuadTree<T>::Unk_532ca0(QuadNode* node, const Unk_FaceCacheRect* rect) {
    if (node->field_54) {
        return nullptr;
    }
    if (rect->field_0.field_4 - rect->field_0.field_0 > node->field_40.field_4 - node->field_40.field_0) {
        return nullptr;
    }
    if (rect->field_8.field_4 - rect->field_8.field_0 > node->field_48.field_4 - node->field_48.field_0) {
        return nullptr;
    }
    bool hasChildren = false;
    for (int i = 0; i < 4; i++) {
        if (node->field_20[i] != nullptr) {
            QuadNode* found = Unk_532ca0(node->field_20[i], rect);
            if (found != nullptr) {
                return found;
            }
            hasChildren = true;
        }
    }
    if (hasChildren) {
        return nullptr;
    }
    s32 width = rect->field_0.field_4 - rect->field_0.field_0;
    s32 nodeHeight = node->field_48.field_4 - node->field_48.field_0;
    s32 nodeWidth = node->field_40.field_4 - node->field_40.field_0;
    s32 height = rect->field_8.field_4 - rect->field_8.field_0;
    if (width == nodeWidth) {
        if (height == nodeHeight) {
            return node;
        }
        Unk_532e90(node, rect->field_8.field_4 + node->field_48.field_0 - rect->field_8.field_0);
    } else if (height == nodeHeight) {
        Unk_533120(node, node->field_40.field_0 + width);
    } else {
        Unk_5333b0(node, node->field_40.field_0 + width, node->field_48.field_0 + height);
    }
    for (int i = 0; i < 4; i++) {
        if (node->field_20[i] != nullptr) {
            QuadNode* found = Unk_532ca0(node->field_20[i], rect);
            if (found != nullptr) {
                return found;
            }
        }
    }
    return nullptr;
}

// 0x7100532e90
template <class T>
bool SiGfxQuadTree<T>::Unk_532e90(QuadNode* node, s32 y) {
    if (node->field_54) {
        return false;
    }
    if (node->field_48.field_4 - node->field_48.field_0 < 2) {
        return false;
    }
    QuadNode* top = field_10.Unk_Alloc();
    QuadNode* bottom = field_10.Unk_Alloc();
    if (top == nullptr || bottom == nullptr) {
        if (top != nullptr) {
            field_10.Unk_4be3f0(top);
        }
        if (bottom != nullptr) {
            field_10.Unk_4be3f0(bottom);
        }
        return false;
    }
    top->Unk_Reset();
    top->field_40.field_0 = node->field_40.field_0;
    top->field_40.field_4 = node->field_40.field_4;
    top->field_48.field_0 = node->field_48.field_0;
    top->field_48.field_4 = y;
    bottom->Unk_Reset();
    bottom->field_40.field_0 = node->field_40.field_4;
    bottom->field_40.field_4 = node->field_40.field_4;
    bottom->field_48.field_0 = top->field_48.field_4;
    bottom->field_48.field_4 = node->field_48.field_4;
    node->field_20[0] = top;
    node->field_20[2] = bottom;
    return true;
}

// 0x7100533120
template <class T>
bool SiGfxQuadTree<T>::Unk_533120(QuadNode* node, s32 x) {
    if (node->field_54) {
        return false;
    }
    if (node->field_40.field_4 - node->field_40.field_0 < 2) {
        return false;
    }
    QuadNode* left = field_10.Unk_Alloc();
    QuadNode* right = field_10.Unk_Alloc();
    if (left == nullptr || right == nullptr) {
        if (left != nullptr) {
            field_10.Unk_4be3f0(left);
        }
        if (right != nullptr) {
            field_10.Unk_4be3f0(right);
        }
        return false;
    }
    left->Unk_Reset();
    left->field_40.field_0 = node->field_40.field_0;
    left->field_40.field_4 = x;
    left->field_48.field_0 = node->field_48.field_0;
    left->field_48.field_4 = node->field_48.field_4;
    right->Unk_Reset();
    right->field_40.field_0 = left->field_40.field_4;
    right->field_40.field_4 = node->field_40.field_4;
    right->field_48.field_0 = node->field_48.field_0;
    right->field_48.field_4 = node->field_48.field_4;
    node->field_20[0] = left;
    node->field_20[3] = right;
    return true;
}

// 0x71005333b0
template <class T>
bool SiGfxQuadTree<T>::Unk_5333b0(QuadNode* node, s32 x, s32 y) {
    if (node->field_54) {
        return false;
    }
    if (node->field_40.field_4 - node->field_40.field_0 < 2) {
        return false;
    }
    if (node->field_48.field_4 - node->field_48.field_0 < 2) {
        return false;
    }
    QuadNode* a = field_10.Unk_Alloc();
    QuadNode* b = field_10.Unk_Alloc();
    QuadNode* c = field_10.Unk_Alloc();
    QuadNode* d = field_10.Unk_Alloc();
    if (a == nullptr || b == nullptr || c == nullptr || d == nullptr) {
        if (a != nullptr) {
            field_10.Unk_4be3f0(a);
        }
        if (b != nullptr) {
            field_10.Unk_4be3f0(b);
        }
        if (c != nullptr) {
            field_10.Unk_4be3f0(c);
        }
        if (d != nullptr) {
            field_10.Unk_4be3f0(d);
        }
        return false;
    }
    a->Unk_Reset();
    a->field_40.field_0 = node->field_40.field_0;
    a->field_40.field_4 = x;
    a->field_48.field_0 = node->field_48.field_0;
    a->field_48.field_4 = y;
    b->Unk_Reset();
    b->field_40.field_0 = a->field_40.field_4;
    b->field_40.field_4 = node->field_40.field_4;
    b->field_48.field_0 = node->field_48.field_0;
    b->field_54 = false;
    b->field_48.field_4 = y;
    c->Unk_Reset();
    c->field_40.field_0 = node->field_40.field_0;
    c->field_40.field_4 = x;
    c->field_48.field_0 = a->field_48.field_4;
    c->field_48.field_4 = node->field_48.field_4;
    d->Unk_Reset();
    d->field_40.field_0 = c->field_40.field_4;
    d->field_40.field_4 = node->field_40.field_4;
    d->field_48.field_0 = b->field_48.field_4;
    d->field_48.field_4 = node->field_48.field_4;
    node->field_20[0] = a;
    node->field_20[1] = b;
    node->field_20[2] = c;
    node->field_20[3] = d;
    return true;
}

// 0x7100531880
// NON_MATCHING: the original tests the pixel mode for 2 first and has the
// one-bit case's loop right after the tests (the switch's last case falls
// through to it); here both are the other way round, whatever the order of
// the cases or the form of the tests.
// (Round 3: `if (mode == 2) ... else if (mode == 1)`, a switch with case 2
// first, if/else both ways, a mode local, an early return: the same code.)
bool SiGfxFreeTypeFaceCache::vf8(SiGfxFreeTypeGlyph* glyph, const Unk_FTBitmap* bitmap, SiGfxImage* image) {
    if (bitmap->field_1a != 1 && bitmap->field_1a != 2) {
        return false;
    }
    SiGfxImage::ImageData2D* data = image->vf17(0, 0);
    u8* dst = data->field_0 + glyph->field_70 + glyph->field_74 * data->field_14;
    const u8* src = bitmap->field_10;
    if (bitmap->field_1a == 1) {
        s32 stride = glyph->field_78;
        for (u32 y = 0; y < bitmap->field_0; y++) {
            u8 mask = 0x80;
            for (u32 x = 0; x < bitmap->field_4; x++) {
                dst[x] = (*src & mask) != 0 ? 0xff : 0;
                mask >>= 1;
                if (mask == 0) {
                    mask = 0x80;
                    src++;
                }
            }
            dst += stride;
            src = bitmap->field_10 + bitmap->field_8 * y;
        }
    } else if (bitmap->field_1a == 2) {
        for (u32 y = 0; y < bitmap->field_0; y++) {
            memcpy(dst, src, bitmap->field_4);
            src += bitmap->field_8;
            dst += data->field_14;
        }
    }
    return true;
}

}  // namespace SiSDK3
