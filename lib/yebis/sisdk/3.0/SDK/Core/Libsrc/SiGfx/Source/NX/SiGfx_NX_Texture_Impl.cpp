// Scope: common
// SiSDK3::SiGfxNXTexture: its name, its class's GUID, the accessors of its
// surfaces, volumes and views, and the reference counts its header defines.
// (Its constructor, destructor and the functions that make it aren't written
// yet; its other small accessors are lib/yebis/class's.)
#define UNK_SIGFX_NX_TEXTURE_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_Texture_Impl.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_StringFuncs.h>

// 0x71004c8f80: whether two GUIDs are the same
bool Unk_4c8f80(const void* a, const void* b);
// 0x7101f0028c: the texture class's GUID (placeholder type)
extern u8 Unk_1f0028c;

namespace SiSDK3 {

// 0x710055f1e0 (0x710055f250: its thunk)
bool SiGfxNXTexture::vf45(const char* name) {
    Unk_4c4700(&field_38, const_cast<char*>(name));
    field_a8 = Unk_4c3510(&field_38);
    if (field_328 != nullptr) {
        nvnTextureSetDebugLabel(field_328, Unk_StringCStr(&field_38));
    }
    return true;
}

// 0x710055f2c0 (0x710055f2d0: its thunk)
const SiString<char>* SiGfxNXTexture::vf46() {
    return &field_38;
}

// 0x710055f2e0 (0x710055f2f0: its thunk)
u32 SiGfxNXTexture::vf47() {
    return field_a8;
}

// 0x7100561040
SiGfxNXSurface* SiGfxNXTexture::vf25(s32 level) {
    u32 kind = field_1d4;
    if (level < 0 || kind == 3) {
        return nullptr;
    }
    if (field_22c <= level) {
        return nullptr;
    }
    return &field_238.m_pData[level];
}

// 0x7100561080
SiGfxNXSurface* SiGfxNXTexture::vf26(s32 layer, s32 level) {
    u32 kind = field_1d4;
    if (level < 0 || kind != 4) {
        return nullptr;
    }
    if (field_22c <= level) {
        return nullptr;
    }
    return &field_238.m_pData[field_22c * layer + level];
}

// NON_MATCHING (and slot 28, which has the same tests): the original tests
// the two signs one after the other (`tbnz w1 ; tbnz w2`) and keeps the
// result in a register that is zero for those and for the layers' test, with
// one return for all of them. Here the two signs become one test of both
// (`orr ; tbnz`) and every early return is a block of its own (100 bytes for
// 92).
// 0x71005610c0
SiGfxNXSurface* SiGfxNXTexture::vf27(s32 layer, s32 level) {
    if (field_1d4 != 5 && field_1d4 != 2) {
        return nullptr;
    }
    s32 layers = field_230;
    if (layer < 0 || level < 0 || layers <= layer) {
        return nullptr;
    }
    if (field_22c <= level) {
        return nullptr;
    }
    return &field_238.m_pData[field_22c * layer + level];
}

// NON_MATCHING: see slot 27
// 0x7100561120
SiGfxNXSurface* SiGfxNXTexture::vf28(s32 layer, s32 face, s32 level) {
    if (field_1d4 != 4 && field_1d4 != 6) {
        return nullptr;
    }
    s32 layers = field_230;
    if (layer < 0 || level < 0 || layers <= layer) {
        return nullptr;
    }
    if (field_22c <= level) {
        return nullptr;
    }
    return &field_238.m_pData[field_22c * (layer * 6 + face) + level];
}

// 0x7100561190
SiGfxNXVolume* SiGfxNXTexture::vf29(s32 level) {
    u32 kind = field_1d4;
    if (level < 0 || kind != 3) {
        return nullptr;
    }
    if (field_22c <= level) {
        return nullptr;
    }
    return &field_288.m_pData[level];
}

// 0x7100561630
bool SiGfxNXTexture::vf31(Unk_NXTextureTarget* pTarget) {
    if (pTarget == nullptr) {
        return false;
    }
    u32 a1 = field_1d8;
    u32 a2 = field_1e8;
    u32 a3 = field_1f4;
    switch (field_1d4) {
    case 3:
    case 4:
    case 5:
    case 6:
        pTarget->vf13(a1, a2, a3, field_230);
        break;
    case 2:
        pTarget->vf10(a1, a2, field_1ec, a3);
        break;
    }
    return true;
}

// 0x71005616b0
bool SiGfxNXTexture::vf32(Unk_NXTextureOwner* pOwner) {
    if (field_318 == pOwner) {
        return true;
    }
    if (field_318 != nullptr) {
        field_318->vf3();
        field_318 = nullptr;
    }
    if (pOwner == nullptr) {
        return false;
    }
    pOwner->vf2();
    if (field_318 != nullptr) {
        field_318->vf3();
    }
    field_318 = pOwner;
    return true;
}

// 0x7100561dc0
void* SiGfxNXTexture::vf42(s32 level, s32 layer) {
    s32 index = nvnTextureGetLevels(field_328) * layer + level;
    return field_348.m_pData[index];
}

// 0x7100561e10
void* SiGfxNXTexture::Unk_561e10() {
    void* pool = nvnTextureGetMemoryPool(field_328);
    if (pool == nullptr) {
        return nullptr;
    }
    return nvnMemoryPoolMap(pool);
}

// 0x7100561e50
void SiGfxNXTexture::Unk_561e50() {
    void* pool = nvnTextureGetMemoryPool(field_328);
    if (pool != nullptr) {
        s64 offset = nvnTextureGetMemoryOffset(field_328);
        nvnMemoryPoolFlushMappedRange(pool, offset, static_cast<s32>(nvnTextureGetStorageSize(field_328)));
    }
}

// 0x7100562370
bool SiGfxNXTexture::vf39(u32 kind) {
    if (!vf37()) {
        return false;
    }
    field_1d4 = kind;
    return true;
}

// 0x71005624f0 (0x7100562530: its thunk)
bool SiGfxNXTexture::vf17(const void* guid) {
    return Unk_4c8f80(guid, &Unk_1f0028c);
}

// 0x7100562510 (0x7100562550: its thunk)
const void* SiGfxNXTexture::vf18() {
    return &Unk_1f0028c;
}

}  // namespace SiSDK3
