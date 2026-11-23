// SiSDK3::SiGfxTextureChunkHandler (RTTI: it derives from
// ISiIOBinaryArchive::ChunkHandler): the chunk of a binary archive that holds
// a texture. Placeholder header name (its translation unit is
// SiGfx_BinaryChunk_Texture.cpp) and placeholder members; the virtual
// functions are vf<slot>.
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_Interface.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiIO/SiIO_BinaryArchive.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_Device_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_Texture_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/SiGfx_FreeType_FaceCache.h>

namespace SiSDK3 {

// A level's pixels as the texture is made from them (RTTI names the type:
// SiArray's element). Placeholder members; its destructor isn't trivial (the
// array's delete asks the allocator for the count), and its constructor
// zeroes it (the array's reserve, 0x71004ec920, clears what it allocates).
struct SIGFX_TEXTURE_INITDATA {
    SIGFX_TEXTURE_INITDATA() : field_0(nullptr), field_8(0), field_10(0), field_14(0) {}

    u8* field_0;    // the pixels (in the chunk's: the writer stores the offset)
    u64 field_8;    // how many bytes
    u32 field_10;   // how many bytes a row is
    u32 field_14;   // how many bytes a slice is
};
PKMN_SIZE_ASSERT(SIGFX_TEXTURE_INITDATA, 0x18);

// (the arrays' destructors are instantiated in lib/yebis/instances)
extern template SiArray<SIGFX_TEXTURE_INITDATA, 16>::~SiArray();
extern template SiArray<u8, 16>::~SiArray();

// What the chunk holds (placeholder name, after its constructor): a texture's
// name and description, its pixels and where each level's are, and two more
// names. 0x3a0 bytes.
struct Unk_4efb80 {
    // the part of a texture's description the chunk keeps apart (placeholder
    // name: its members and defaults are those of the end of the
    // description)
    struct Unk_View {
        Unk_View() : field_0(0), field_4(-1), field_8(-1) {
            field_c = SiGfxNXTexture::Unk_Desc::Unk_Pair();
            field_16 = false;
            field_14 = false;
            field_15 = false;
        }

        u32 field_0;
        s32 field_4;
        s32 field_8;
        SiGfxNXTexture::Unk_Desc::Unk_Pair field_c;
        bool field_14;
        bool field_15;
        bool field_16;
    };

    explicit Unk_4efb80(ISiAllocator* pAllocator);  // 0x71004efb80
    ~Unk_4efb80();                                  // 0x71004efe40

    Unk_NXString<0x40> field_0;  // the name
    u32 field_70;
    SiGfxNXTexture::Unk_Desc field_78;
    SiArray<u8, 16> field_188;                        // the pixels
    SiArray<SIGFX_TEXTURE_INITDATA, 16> field_1d8;    // each level's
    Unk_NXString<0x80> field_228;
    Unk_NXString<0x80> field_2d8;
    Unk_View field_388;
};
PKMN_OFFSET_ASSERT(Unk_4efb80, field_78, 0x78);
PKMN_OFFSET_ASSERT(Unk_4efb80, field_188, 0x188);
PKMN_OFFSET_ASSERT(Unk_4efb80, field_228, 0x228);
PKMN_OFFSET_ASSERT(Unk_4efb80, field_388, 0x388);
PKMN_SIZE_ASSERT(Unk_4efb80, 0x3a0);

class SiGfxTextureChunkHandler : public ISiIOBinaryArchive::ChunkHandler {
public:
    explicit SiGfxTextureChunkHandler(ISiAllocator* pAllocator);  // 0x71004efb10
    ~SiGfxTextureChunkHandler() override;                         // 0x71004efdd0, 0x71004f01b0
    u32 vf4() override;
    const char* vf5() override;
    bool vf6(ISiIOBinaryArchive* archive, ISiIOStream* stream) override;                          // 0x71004f0220
    bool vf8(ISiIOBinaryArchive* archive, ISiIOBinaryArchive::Unk_ChunkHeader* header,
             ISiIOStream* stream) override;  // 0x71004f05c0
    bool vf9(ISiIOBinaryArchive* archive, ISiIOBinaryArchive::Unk_ChunkHeader* header,
             ISiIOStream* stream) override;  // 0x710057a640

    // 0x71004f0f90: the device that makes the texture and the texture,
    // which it keeps a reference to
    void Unk_4f0f90(SiGfxNXDevice* device, ISiGfxTexture* texture);

    Unk_4efb80 field_b8;
    // what the reader adds to the description's flags at 0x34, 0x38, 0x3c
    u32 field_458;
    u32 field_45c;
    u32 field_460;
    SiGfxNXDevice* field_468;
    ISiGfxTexture* field_470;
};
PKMN_SIZE_ASSERT(SiGfxTextureChunkHandler, 0x478);
PKMN_OFFSET_ASSERT(SiGfxTextureChunkHandler, field_458, 0x458);

}  // namespace SiSDK3
