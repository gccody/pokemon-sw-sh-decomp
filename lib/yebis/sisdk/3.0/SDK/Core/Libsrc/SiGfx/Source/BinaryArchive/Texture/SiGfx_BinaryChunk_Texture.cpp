// Scope: common
// SiSDK3::SiGfxTextureChunkHandler: the function that makes one, its
// constructor and destructors and the function that gives it the two objects
// it keeps. (What it holds, 0x71004efb80 and 0x71004efe40, and its reading
// and writing, slots 6 and 8, aren't written yet.)
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/BinaryArchive/Texture/SiGfx_BinaryChunk_Texture.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_Interface.h>

// 0x7101eec778: the texture chunk's identifier
extern const SiSDK3::ISiIOBinaryArchive::Unk_Id Unk_1eec778;

namespace SiSDK3 {

// 0x71004efb10
SiGfxTextureChunkHandler::SiGfxTextureChunkHandler(ISiAllocator* pAllocator)
    : ChunkHandler(pAllocator), field_b8(pAllocator), field_458(0), field_460(0), field_468(nullptr), field_470(nullptr) {
    field_28.field_0 = Unk_1eec778;
    field_28.field_10.field_0 = 3;
    field_28.field_10.field_4 = 0;
    field_28.field_10.field_8 = 0;
    field_28.field_10.field_c = 11;
}

// 0x71004efdd0 (D2), 0x71004f01b0 (D0)
SiGfxTextureChunkHandler::~SiGfxTextureChunkHandler() {
    if (field_470 != nullptr) {
        field_470->vf3();
        field_470 = nullptr;
    }
    if (field_468 != nullptr) {
        field_468->vf3();
        field_468 = nullptr;
    }
}

// 0x71004f0f90
void SiGfxTextureChunkHandler::Unk_4f0f90(ISiInterface* a, ISiInterface* b) {
    if (a != nullptr) {
        a->vf2();
    }
    if (field_468 != nullptr) {
        field_468->vf3();
    }
    field_468 = a;
    if (b != nullptr) {
        b->vf2();
    }
    if (field_470 != nullptr) {
        field_470->vf3();
    }
    field_470 = b;
}

}  // namespace SiSDK3

// 0x71004efa70: a new handler
SiSDK3::SiGfxTextureChunkHandler* Unk_4efa70(SiSDK3::ISiAllocator* pAllocator) {
#line 35
    return UNK_SI_NEW(pAllocator, 0x10) SiSDK3::SiGfxTextureChunkHandler(pAllocator);
}
