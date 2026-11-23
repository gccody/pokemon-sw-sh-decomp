// Scope: common
// SiSDK3::SiGfxFreeTypeManager: its construction and destruction, the start
// and end of FreeType, and the reference counts its header defines.
#define UNK_SIGFX_FREETYPE_MANAGER_IMPL
#define UNK_SIMAP_MEMBERS_DEFINE
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/SiGfx_FreeType_Manager.h>

#include <string.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_String.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_Alloc.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiIO/SiIO_Stream.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiIO/Source/SiIO_Kernel_Impl.h>

// FreeType's functions that the manager calls (C; the types are FreeType's as
// far as the calls need them).
extern "C" {
s32 FT_Init_FreeType(FT_LibraryRec_** alibrary);
s32 FT_Done_FreeType(FT_LibraryRec_* library);
s32 FT_New_Memory_Face(FT_LibraryRec_* library, const u8* file_base, long file_size, long face_index,
                       FT_FaceRec_** aface);
s32 FT_Done_Face(FT_FaceRec_* face);
}

// 0x710057d030: SiIO's kernel (leafgen's name and type)
u64 Unk_57d030_get();
// 0x7100582d80: whether a file exists
bool Unk_582d80(const char* path, bool searchArchives);
// 0x71004e4400: a path's file name
SiSDK3::SiString<char> Unk_4e4400(SiSDK3::SiString<char>* path, bool);
// 0x710050b590: ends a face and frees its data (placeholder name and types:
// the manager, then the face)
void Unk_50b590(void* manager, void* face);

// 0x71004cbf40: SiGfx's kernel (leafgen's name and type)
u64 Unk_4cbf40_get();

namespace SiSDK3 {

// SiGfx's kernel as the manager uses it: slot 6 is its allocator.
class Unk_FreeTypeKernel {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual ISiAllocator* vf6();
};

inline Unk_FreeTypeKernel* Unk_GetGfxKernel() {
    return reinterpret_cast<Unk_FreeTypeKernel*>(Unk_4cbf40_get());
}

// 0x710050aee0
SiGfxFreeTypeManager::SiGfxFreeTypeManager(SiGfxNXDevice* pDevice)
    : field_8(Unk_GetGfxKernel()->vf6()), field_18(pDevice), field_20(0), field_28(nullptr),
      field_30(Unk_GetGfxKernel()->vf6()) {
    vf13();
}

// 0x710050af80 (D2), 0x710050b050 (D0)
SiGfxFreeTypeManager::~SiGfxFreeTypeManager() {}

// 0x710050b0e0
bool SiGfxFreeTypeManager::vf13() {
    if (FT_Init_FreeType(&field_28) == 0 && field_28 != nullptr) {
        return true;
    }
    return false;
}

// 0x710050b130
void SiGfxFreeTypeManager::vf14() {
    FT_Done_FreeType(field_28);
    field_28 = nullptr;
    for (Unk_Map::Unk_Node* pNode = field_30.m_pRoot; pNode != nullptr; Unk_Map::Unk_AdvanceNode(pNode)) {
        if (pNode->m_value != nullptr) {
#line 94
            UNK_FREE(field_8.m_pAllocator, pNode->m_value);
        }
    }
    field_30.Unk_Clear();
}

// 0x710050b210
bool SiGfxFreeTypeManager::Unk_50b210(FT_FaceRec_** pFace, const char* path, s32 index) {
    if (field_28 == nullptr) {
        return false;
    }
    if (!Unk_582d80(path, true)) {
        return false;
    }
    ISiIOStream* stream = reinterpret_cast<SiIOKernel*>(Unk_57d030_get())->vf9(path, 9, nullptr);
    if (stream == nullptr) {
        return false;
    }
    s64 size = stream->vf10();
#line 140
    u8* data = static_cast<u8*>(UNK_ALLOC(field_8.m_pAllocator, size));
    if (data == nullptr) {
        stream->vf3();
        return false;
    }
    bool read = stream->vf21(data, size, true);
    stream->vf9();
    stream->vf3();
    if (!read) {
        return false;
    }
    if (FT_New_Memory_Face(field_28, data, size, index, pFace) != 0) {
        SiString<char> name;
        name.Unk_SetExternal(path);
        SiString<char> fileName = Unk_4e4400(&name, true);
        Unk_50b590(this, *pFace);
#line 176
        UNK_FREE(field_8.m_pAllocator, data);
        return false;
    }
    Unk_Map::Unk_Iterator position = field_30.Unk_Find(*pFace);
    if (position.m_pNode == nullptr) {
        field_30.Unk_4c09a0(*pFace, data);
    } else {
        if (position.m_pNode->m_value != nullptr) {
#line 183
            UNK_FREE(field_8.m_pAllocator, position.m_pNode->m_value);
        }
        position.m_pNode->m_value = data;
    }
    return true;
}

}  // namespace SiSDK3

// 0x710050b590
void Unk_50b590(void* manager, void* face) {
    using namespace SiSDK3;
    SiGfxFreeTypeManager* self = static_cast<SiGfxFreeTypeManager*>(manager);
    FT_FaceRec_* pFace = static_cast<FT_FaceRec_*>(face);
    SiGfxFreeTypeManager::Unk_Map::Unk_Iterator position = self->field_30.Unk_Find(pFace);
    FT_Done_Face(pFace);
    if (position.m_pNode != nullptr) {
        if (position.m_pNode->m_value != nullptr) {
#line 270
            UNK_FREE(self->field_8.m_pAllocator, position.m_pNode->m_value);
        }
        self->field_30.Unk_4c0e60(position);
    }
}

namespace SiSDK3 {

// 0x710050ba10
bool SiGfxFreeTypeManager::Unk_50ba10(FT_FaceRec_** pFace, const void* data, s32 size, s32 index) {
    if (field_28 == nullptr) {
        return false;
    }
    size_t length = size;
#line 217
    u8* copy = static_cast<u8*>(UNK_ALLOC(field_8.m_pAllocator, length));
    if (copy == nullptr) {
        return false;
    }
    memcpy(copy, data, length);
    if (FT_New_Memory_Face(field_28, copy, length, index, pFace) != 0) {
        Unk_50b590(this, *pFace);
#line 237
        UNK_FREE(field_8.m_pAllocator, copy);
        return false;
    }
    Unk_Map::Unk_Iterator position = field_30.Unk_Find(*pFace);
    if (position.m_pNode == nullptr) {
        field_30.Unk_4c09a0(*pFace, copy);
    } else {
        if (position.m_pNode->m_value != nullptr) {
#line 244
            UNK_FREE(field_8.m_pAllocator, position.m_pNode->m_value);
        }
        position.m_pNode->m_value = copy;
    }
    return true;
}

}  // namespace SiSDK3
