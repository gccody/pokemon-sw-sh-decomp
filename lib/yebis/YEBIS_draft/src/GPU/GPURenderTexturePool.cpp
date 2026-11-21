// Scope: common
// PPFX::CRenderTexturePool (lib/yebis/YEBIS_draft/src/GPU/GPURenderTexturePool.h):
// C:/workspace/YEBIS_draft/src/GPU/GPURenderTexturePool.cpp is the __FILE__ of
// its allocations and log lines. The TU's statics are the ones every src/GPU
// TU has (Unk_Statics.h), which its static initialiser, 0x71004a02c0, sets up.
#include <yebis/YEBIS_draft/src/GPU/GPURenderTexturePool.h>
#include <yebis/YEBIS_draft/src/GPU/Unk_Statics.h>

// log switch: PPFX_LOG's
extern s32 Unk_24e0008;

#define UNK_LOG(...)                                                                                     \
    do {                                                                                                 \
        if (Unk_238c1e0 != 0 && Unk_24e0008 != 0) {                                                      \
            Unk_417a30("C:/workspace/YEBIS_draft/src/GPU/GPURenderTexturePool.cpp(%d) : PPFX: ", __LINE__); \
            Unk_417a30(__VA_ARGS__);                                                                     \
        }                                                                                                \
    } while (0)

// 0x710049c8d0
s32 Unk_49c8d0_call(void* self, void* value);

namespace PPFX {

// 0x7101e7a0fb: the class's name
extern const char Unk_1e7a0fb[];
const char Unk_1e7a0fb[] = "CRenderTexturePool";

// 0x710049f650
CRenderTexturePool::CRenderTexturePool(const char* name) : CGPUResourceManage(nullptr) {
    Unk_49f6a0(name);
}

// 0x710049f6a0
s32 CRenderTexturePool::Unk_49f6a0(const char* name) {
    if (name != nullptr && name[0] != '\0')
        field_10 = Unk_TFXString(Unk_1e7a0fb) + " " + name;
    else
        field_10 = Unk_1e7a0fb;
    field_30.clear();
    return 0;
}

// 0x710049f7b0
// NON_MATCHING: the original's three failed comparisons share one `return
// false` block (64 bytes); here each gets its own copy (80 bytes), whether
// the test is written as one && chain or as early returns. Inlined in
// AllocateTextures it is the same code as the original's.
bool CRenderTexturePool::Unk_49f7b0(const CRenderTexture* texture, s32 width, s32 height, s32 format, u32 flags,
                                    u32 mask) {
    if (texture->field_54 != width || texture->field_58 != height || texture->field_2c.field_c != format)
        return false;
    return ((texture->field_2c.field_0 ^ flags) & mask) == 0;
}

// 0x710049f7f0
// NON_MATCHING: register allocation only (11 instructions). In the loop that
// makes the missing textures, the original keeps the new texture in x26 and
// its name, then its list entry, in x20; here they're swapped.
s32 CRenderTexturePool::AllocateTextures(s32 count, CRenderTexture** textures, s32 width, s32 height, s32 format,
                                         bool shared, u32 flags, u32 mask) {
    if (count == 0)
        return 0;
#line 119
    CRenderTexture** found = UNK_NEW_ARRAY(CRenderTexture*, count);
    for (s32 i = 0; i < count; i++)
        found[i] = nullptr;
    s32 sharedCount = 0;
    if (shared) {
        for (Unk_List::iterator it = field_30.begin(); it != field_30.end(); ++it) {
            CRenderTexture* texture = (*it)->field_8;
            if (texture->field_c && Unk_49f7b0(texture, width, height, format, flags, mask)) {
                found[sharedCount] = texture;
                if (++sharedCount >= count)
                    break;
            }
        }
    }
    s32 generated = count - sharedCount;
    if (textures == nullptr) {
        UNK_DELETE_ARRAY(found);
        return generated;
    }
    for (s32 i = 0; i < count; i++)
        textures[i] = found[i];
    UNK_DELETE_ARRAY(found);
    for (s32 i = 0; i < count; i++) {
        if (textures[i] != nullptr) {
            textures[i]->field_8++;
            continue;
        }
        Unk_TFXString number = Unk_4525a0(i);
#line 189
        const char* name = number.field_8;
        CRenderTexture* texture = UNK_NEW(CRenderTexture)(name);
        textures[i] = texture;
        texture->Unk_SetC(shared);
        texture->Unk_Create(flags, width, height, format);
        if (field_20 != nullptr)
            texture->vf0(field_20);
#line 204
        Unk_Entry* entry = UNK_NEW(Unk_Entry);
        entry->field_0 = true;
        entry->field_8 = texture;
        field_30.push_back(entry);
    }
#line 211
    UNK_LOG("CRenderTexturePool::AllocateTextures(): Shared: %d, Generated: %d, %s\n", sharedCount, generated, field_10.field_8);
    return generated;
}

// 0x710049fc10
s32 CRenderTexturePool::Unk_49fc10(CRenderTexture** texture, s32 width, s32 height, s32 format, bool shared,
                                   u32 flags, u32 mask) {
    return AllocateTextures(1, texture, width, height, format, shared, flags, mask);
}

// 0x710049fdf0
void CRenderTexturePool::Unk_49fdf0(CRenderTexture* texture, bool front) {
#line 323
    Unk_Entry* entry = UNK_NEW(Unk_Entry);
    entry->field_0 = false;
    entry->field_8 = texture;
    if (front)
        field_30.push_front(entry);
    else
        field_30.push_back(entry);
    entry->field_8->field_8++;
}

// 0x710049fed0
s32 CRenderTexturePool::Unk_49fed0(void* arg) {
    s32 result = 0;
    for (Unk_List::iterator it = field_30.begin(); it != field_30.end(); ++it) {
        s32 r = Unk_49c8d0_call((*it)->field_8, arg);
        if (r < 0)
            result = r;
    }
    return result;
}

// 0x710049ff40, 0x710049ffd0
CRenderTexturePool::~CRenderTexturePool() {
    Unk_49ec80();
}

// 0x71004a0070
s32 CRenderTexturePool::vf0(IGPUDevice* device) {
    s32 result = CGPUResourceManage::vf0(device);
    if (result < 0)
        return result;
    if (field_20 == nullptr)
        return 0;
    result = 0;
    for (Unk_List::iterator it = field_30.begin(); it != field_30.end(); ++it) {
        if ((*it)->field_0) {
            s32 r = (*it)->field_8->vf0(field_20);
            if (r < 0)
                result = r;
        }
    }
    return result;
}

// 0x71004a0100
s32 CRenderTexturePool::vf1() {
    for (Unk_List::iterator it = field_30.begin(); it != field_30.end(); ++it) {
        if ((*it)->field_0)
            (*it)->field_8->vf1();
    }
    return CGPUResourceManage::vf1();
}

// 0x71004a0170
s32 CRenderTexturePool::vf2() {
    s32 result = CGPUResourceManage::vf2();
    return result < 0 ? result : 0;
}

// 0x71004a0190
s32 CRenderTexturePool::vf3() {
    for (Unk_List::iterator it = field_30.begin(); it != field_30.end(); ++it) {
        Unk_Entry* entry = *it;
        s32 count = entry->field_8->Unk_Release();
        if ((*it)->field_0) {
            while (count != 0)
                count = entry->field_8->Unk_Release();
        }
        entry->field_8 = nullptr;
        UNK_DELETE(*it);
    }
    field_30.clear();
    s32 result = CGPUResourceManage::vf3();
    return result < 0 ? result : 0;
}

}  // namespace PPFX

// 0x710049fc60
// NON_MATCHING: 4 instructions. The original reads the erased node's links
// before it clears the node's entry pointer (here the store comes first), and
// in the copy of the loop for a count below 1 one comparison has its operands
// the other way round.
s32 Unk_49fc60(void* self, u32 count_, void* textures_) {
    using namespace PPFX;
    CRenderTexturePool* pool = static_cast<CRenderTexturePool*>(self);
    s32 count = count_;
    CRenderTexture** textures = static_cast<CRenderTexture**>(textures_);
    s32 destroyed = 0;
    if (count == 0 || textures == nullptr)
        return 0;
    CRenderTexturePool::Unk_List::iterator it = pool->field_30.begin();
    while (pool->field_30.end() != it) {
        CRenderTexturePool::Unk_Entry* entry = *it;
        s32 i;
        for (i = 0; i < count; i++) {
            CRenderTexture* texture = textures[i];
            if (texture != nullptr && entry->field_8 == texture) {
                if (texture->Unk_Release() == 0) {
                    entry->field_8 = nullptr;
                    destroyed++;
                    UNK_DELETE(*it);
                    it = pool->field_30.erase(it);
                    break;
                }
            }
        }
        if (i >= count && pool->field_30.end() != it)
            ++it;
    }
    return destroyed;
}
