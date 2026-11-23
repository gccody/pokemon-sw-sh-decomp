// Scope: common
// SiSDK3::SiGfxNXFontPool: its slot 7 and the font it makes of its own (the
// pool's constructor, destructor and other slots are in Unk_Pools.cpp), the
// function that makes a font, and the resource pools' item of an index.
// (the pools' header first: the resources' includes bring SiCore_Pool.h's
// member definitions, which the original doesn't inline here)
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/Unk_Pools.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_StringFuncs.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_Font_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/Unk_NXResource.h>

// 0x7100582d80: whether a file exists
bool Unk_582d80(const char* path, bool searchArchives);

// 0x71023932f8: the own font's file name; 0x7102393300: its name
extern const char* Unk_23932f8;
extern const char* Unk_2393300;
// 0x7101efebc0
extern const s32 Unk_1efebc0;

namespace SiSDK3 {

// (The free list's removal has no test of a null element here, unlike
// SiDirectLinkedList::Remove: LLVM can't tell that the item isn't null.)
// 0x71004fef10 (SiGfxResourcePool::ResourceItem, its only instance: the
// pools' makers after this one call it)
// The free list's removal of an element known to be there (placeholder
// name): SiDirectLinkedList::Remove without its test of a null element.
template <class T>
static inline void Unk_Unlink(SiDirectLinkedList<T*>* list, T* node) {
    T* prev = node->m_pPrev;
    T* next = node->m_pNext;
    if (prev != nullptr) {
        if (next != nullptr) {
            next->m_pPrev = prev;
            prev->m_pNext = next;
        } else {
            if (list->m_pTail != node || list->m_pTail == nullptr) {
                return;
            }
            prev->m_pNext = nullptr;
            list->m_pTail = prev;
        }
    } else {
        if (list->m_pHead != node || list->m_pHead == nullptr) {
            return;
        }
        if (next != nullptr) {
            next->m_pPrev = nullptr;
            list->m_pHead = next;
        } else {
            list->m_pHead = nullptr;
            list->m_pTail = nullptr;
        }
    }
    node->m_pPrev = nullptr;
    node->m_pNext = nullptr;
    list->m_count--;
}

template <class T, int ALIGN>
T* SiPool<T, ALIGN>::Unk_4fef10(size_t index) {
    if (m_freeList.m_count == 0 || field_118 <= index) {
        size_t needed = index + 1;
        size_t count = field_118 * 2;
        vf5(needed > count ? needed : count);
        if (m_freeList.m_count == 0) {
            return nullptr;
        }
    }
    T* item = Unk_Get(index);
    if (item->field_18) {
        return nullptr;
    }
    Unk_Unlink(&m_freeList, item);
    m_usedList.AddTail(item);
    item->field_18 = true;
    size_t block = item->field_10 / field_110;
    m_blocks.m_pData[block]->field_c++;
    return item;
}

// 0x71004fed10: under the name and type the device's translation unit calls
// it by (the pointer is the index of the pool's item to take, 0 for any).
SiGfxNXFont* Unk_4fed10(SiGfxNXFontPool* pool, ISiAllocator* pAllocator, const void* index) {
    Unk_596640 lock(pool->field_18.Unk_Get(), true);
    SiGfxResourcePool::ResourceItem* item;
    if (index != nullptr) {
        item = pool->field_48.Unk_4fef10(reinterpret_cast<size_t>(index));
    } else {
        item = pool->field_48.Unk_Alloc();
    }
    if (item == nullptr) {
        return nullptr;
    }
#line 120
    SiGfxNXFont* font = UNK_SI_NEW(pAllocator, 0x10) SiGfxNXFont(pAllocator, pool->field_178);
    if (font == nullptr) {
        pool->field_48.Unk_4be3f0(item);
        return nullptr;
    }
    if (!font->Unk_4ff6d0(item->field_10)) {
        pool->field_48.Unk_4be3f0(item);
        return nullptr;
    }
    item->field_20 = reinterpret_cast<Unk_534460_Resource*>(font);
    s32 number = static_cast<s32>(pool->field_48.m_usedList.m_count);
    if (Unk_NXDevice(pool->field_178)->vf11()->field_b5) {
        char name[0x80];
        Unk_4c5a90(name, sizeof(name), "Font_%d", number);
        font->vf25(name);
    }
    return font;
}

// 0x71004fe950
void SiGfxNXFontPool::vf7() {
    if (Unk_NXDevice(field_178)->vf11()->field_52) {
        Unk_4fe990();
    }
    SiGfxResourcePool::vf7();
}

// 0x71004fe990
void SiGfxNXFontPool::Unk_4fe990() {
    if (field_178->field_398 == nullptr) {
        return;
    }
    if (!Unk_NXKernel()->vf27()->field_61) {
        return;
    }
    char buffer[0x400];
    SiString<char> path(field_8.m_pAllocator, buffer, sizeof(buffer));
    path = Unk_StringConcat(Unk_NXKernel()->vf27()->field_30, Unk_23932f8);
    if (!Unk_582d80(Unk_StringCStr(&path), true)) {
        return;
    }
    SiGfxNXFont* font = Unk_4fed10(this, field_8.m_pAllocator, reinterpret_cast<const void*>(1));
    if (font == nullptr) {
        return;
    }
    const char* file = Unk_StringCStr(&path);
    s32 value = Unk_1efebc0;
    Unk_FontDesc desc;
    desc.field_0.Unk_SetExternal(file);
    desc.field_38 = value;
    desc.field_3c = 0x200;
    desc.field_40 = 0x200;
    desc.field_30 = 0;
    desc.field_34 = 0;
    desc.field_44 = 0x1000;
    desc.field_48 = nullptr;
    desc.field_50 = 0;
    font->vf18(&desc);
    // (named through its named object: the call goes through that base's
    // table)
    static_cast<Unk_NXFontNamedObject*>(font)->vf25(Unk_2393300);
    font->vf21("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    font->vf21("abcdefghijklmnopqrstuvwxyz");
    font->vf21("0123456789");
    font->vf21("!\"#$%&'()=-~^\\|{}[]`@*:+?/<>,. \t");
}

}  // namespace SiSDK3
