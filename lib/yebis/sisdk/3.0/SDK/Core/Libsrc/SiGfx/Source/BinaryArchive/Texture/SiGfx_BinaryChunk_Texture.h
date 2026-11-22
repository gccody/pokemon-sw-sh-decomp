// SiSDK3::SiGfxTextureChunkHandler (RTTI: it derives from
// ISiIOBinaryArchive::ChunkHandler): the chunk of a binary archive that holds
// a texture. Placeholder header name (its translation unit is
// SiGfx_BinaryChunk_Texture.cpp) and placeholder members; the virtual
// functions are vf<slot>.
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_Interface.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiIO/SiIO_BinaryArchive.h>

namespace SiSDK3 {

// What the chunk holds (placeholder name, after its constructor): a texture's
// description, its names, its pixels and where each level's are. 0x3a0 bytes;
// only its constructor and destructor are declared so far.
struct Unk_4efb80 {
    explicit Unk_4efb80(ISiAllocator* pAllocator);  // 0x71004efb80
    ~Unk_4efb80();                                  // 0x71004efe40

    u64 field_0[0x74];
};

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

    // 0x71004f0f90: the two objects it keeps a reference to
    void Unk_4f0f90(ISiInterface* a, ISiInterface* b);

    Unk_4efb80 field_b8;
    u64 field_458;
    u32 field_460;
    ISiInterface* field_468;
    ISiInterface* field_470;
};
PKMN_SIZE_ASSERT(SiGfxTextureChunkHandler, 0x478);
PKMN_OFFSET_ASSERT(SiGfxTextureChunkHandler, field_458, 0x458);

}  // namespace SiSDK3
