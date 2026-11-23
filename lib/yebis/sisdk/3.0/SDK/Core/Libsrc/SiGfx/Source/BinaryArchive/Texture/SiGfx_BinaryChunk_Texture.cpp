// Scope: common
// SiSDK3::SiGfxTextureChunkHandler: the function that makes one, what it
// holds, its constructor and destructors and the function that gives it the
// two objects it keeps, its writer (slot 6) and its reader (slot 8).
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/BinaryArchive/Texture/SiGfx_BinaryChunk_Texture.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_Alloc.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_Interface.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_StringFuncs.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiIO/SiIO_Stream.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiIO/Source/SiIO_BinaryArchive_Impl.h>

// SiIO_Utility.cpp's block header and functions as the writer and reader use
// them: 0x7100582f70 pads a stream to an alignment, 0x7100582ff0 writes a
// block, 0x7100583410 compresses one with a codec; 0x7100583240 (leafgen's
// name and types) writes a version.
struct Unk_BlockHeader {
    s64 field_0;   // the data's size
    s64 field_8;   // its size in the stream, if field_10 isn't 0
    s32 field_10;  // the codec
    s32 field_14;
    s32 field_18;
    s32 field_1c;
};
s64 Unk_582f70(SiSDK3::ISiIOStream* stream, s64 alignment, u8 fill);
bool Unk_582ff0(SiSDK3::ISiIOStream* stream, const Unk_BlockHeader* header, const void* data, s32 alignment);
const void* Unk_583410(SiSDK3::ISiAllocator* pAllocator, Unk_BlockHeader* header, const void* data, u32 codec,
                       float ratio, void** buffer);
struct Unk_583240;
struct Unk_583240_arg1 {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
};
u32 Unk_583240_call(Unk_583240* self, const Unk_583240_arg1* value);
// ... and as the reader uses them: 0x7100582f10 skips to an alignment,
// 0x71005832c0 (leafgen's name and types) reads a version, 0x7100583140
// reads a block's header, 0x7100583580 the block (decompressed into a buffer
// it allocates if it has to; the last argument is how many bytes it read)
s64 Unk_582f10(SiSDK3::ISiIOStream* stream, s64 alignment);
struct Unk_5832c0;
struct Unk_5832c0_arg1 {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
};
u32 Unk_5832c0_call(Unk_5832c0* self, Unk_5832c0_arg1* value);
bool Unk_583140(SiSDK3::ISiIOStream* stream, Unk_BlockHeader* header, s32 alignment);
const void* Unk_583580(SiSDK3::ISiAllocator* pAllocator, const Unk_BlockHeader* header, const void* data, void** buffer,
                       s64* size);

// 0x7101eec778: the texture chunk's identifier
extern const SiSDK3::ISiIOBinaryArchive::Unk_Id Unk_1eec778;

namespace SiSDK3 {

// 0x71004efb80
Unk_4efb80::Unk_4efb80(ISiAllocator* pAllocator)
    : field_0(pAllocator), field_70(0), field_188(pAllocator), field_1d8(pAllocator), field_228(pAllocator),
      field_2d8(pAllocator) {}

// 0x71004efe40
Unk_4efb80::~Unk_4efb80() {
    field_1d8.Unk_FreeAll();
    field_0.Unk_EmptyAll();
    field_188.Unk_FreeAll();
    field_228.Unk_EmptyAll();
    field_2d8.Unk_EmptyAll();
}

// 0x71004efb10
SiGfxTextureChunkHandler::SiGfxTextureChunkHandler(ISiAllocator* pAllocator)
    : ChunkHandler(pAllocator), field_b8(pAllocator), field_458(0), field_45c(0), field_460(0), field_468(nullptr), field_470(nullptr) {
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
void SiGfxTextureChunkHandler::Unk_4f0f90(SiGfxNXDevice* a, ISiGfxTexture* b) {
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

// 0x71004f0220: writes the chunk: its version, the three names, then either
// what tells the texture of the second name or the description and the
// pixels (compressed with the archive's codec) with where each level's are
bool SiGfxTextureChunkHandler::vf6(ISiIOBinaryArchive* archive, ISiIOStream* stream) {
    s32 alignment = reinterpret_cast<const SiIOBinaryArchive::Unk_Header*>(archive->vf9())->field_44;
    Unk_582f70(stream, alignment, 0);
    {
        // (in a scope of its own: the header below reuses its stack)
        Unk_583240_arg1 version;
        version.field_0 = 3;
        version.field_4 = 0;
        version.field_8 = 0;
        version.field_c = 11;
        Unk_583240_call(reinterpret_cast<Unk_583240*>(stream), &version);
    }
    u8* pixels = field_b8.field_188.m_pData;
    s64 size = field_b8.field_188.m_itemCount;
    Unk_582f70(stream, alignment, 0);
    stream->vf64(Unk_StringCStr(&field_b8.field_0), true);
    Unk_582f70(stream, alignment, 0);
    stream->vf64(Unk_StringCStr(&field_b8.field_228), true);
    Unk_582f70(stream, alignment, 0);
    stream->vf64(Unk_StringCStr(&field_b8.field_2d8), true);
    size_t length = field_b8.field_228.field_10;
    Unk_582f70(stream, alignment, 0);
    if (length != 0) {
        stream->vf54(field_b8.field_388.field_0, true);
        stream->vf50(field_b8.field_388.field_4, true);
        stream->vf50(field_b8.field_388.field_8, true);
        stream->vf50(field_b8.field_388.field_c.field_0, true);
        stream->vf50(field_b8.field_388.field_c.field_4, true);
        stream->vf45(field_b8.field_388.field_14, true);
        stream->vf45(field_b8.field_388.field_15, true);
        stream->vf45(field_b8.field_388.field_16, true);
        return true;
    }
    stream->vf50(field_b8.field_70, true);
    Unk_582f70(stream, alignment, 0);
    stream->vf44(&field_b8.field_78, 0x60, true);
    Unk_582f70(stream, alignment, 0);
    Unk_BlockHeader header = {};
    header.field_0 = size;
    header.field_10 = archive->vf27();
    void* buffer = nullptr;
    const void* data = Unk_583410(field_8.m_pAllocator, &header, pixels, archive->vf27(), 0.75f, &buffer);
    Unk_582ff0(stream, &header, data, alignment);
    Unk_582f70(stream, alignment, 0);
    if (size > 0) {
        for (s32 i = 0; i < static_cast<s32>(field_b8.field_78.field_54); i++) {
            SIGFX_TEXTURE_INITDATA* level = &field_b8.field_1d8.m_pData[i];
            stream->vf51(level->field_0 - pixels, true);
            stream->vf51(level->field_8, true);
            stream->vf50(level->field_10, true);
            stream->vf50(level->field_14, true);
        }
    }
    if (buffer != nullptr) {
#line 199
        UNK_FREE(field_8.m_pAllocator, buffer);
    }
    return true;
}

// NON_MATCHING: the return for a failed allocation of the levels shares its
// block with the return for a null allocator (and the 2D texture's), where
// the original's reaches the end of the failed description's cleanup
// (412-413): a goto there, a result flag, the cleanup written in the test,
// the rest of the function nested in `if (levels != nullptr)` and the
// levels' zeroing under a null test of its own (as SI_NEW_ARRAY has it) were
// tried.
// Also tried: a goto into the failure's block, a goto to a cleanup at the
// end, the success path nested with the failure after it, a result
// variable.
// 0x71004f05c0: reads the chunk: its version, the three names, then either
// what tells the texture of the second name (a 2D texture made from it) or
// the texture's kind, description and pixels; makes the texture or has the
// one it has take the kind
bool SiGfxTextureChunkHandler::vf8(ISiIOBinaryArchive* archive, ISiIOBinaryArchive::Unk_ChunkHeader* header,
                                   ISiIOStream* stream) {
    if (field_468 == nullptr) {
        return false;
    }
    s32 alignment = reinterpret_cast<const SiIOBinaryArchive::Unk_Header*>(archive->vf9())->field_44;
    Unk_582f10(stream, alignment);
    Unk_5832c0_arg1 version = {};
    Unk_5832c0_call(reinterpret_cast<Unk_5832c0*>(stream), &version);
    Unk_582f10(stream, alignment);
    Unk_NXString<0x80> name(nullptr);
    stream->vf41(&name, true);
    Unk_582f10(stream, alignment);
    Unk_NXString<0x80> source(nullptr);
    stream->vf41(&source, true);
    Unk_582f10(stream, alignment);
    Unk_NXString<0x80> source2(nullptr);
    stream->vf41(&source2, true);
    if (source.field_10 != 0) {
        SiGfxNXTexture::Unk_Desc desc;
        desc.field_88 = source;
        desc.field_b8 = source2;
        desc.field_30 = 1;
        desc.field_34 = 8 | field_458;
        desc.field_38 = field_45c;
        desc.field_3c = field_460;
        Unk_582f10(stream, alignment);
        desc.field_e8 = stream->vf31(true);
        desc.field_ec = stream->vf27(true);
        desc.field_f0 = stream->vf27(true);
        desc.field_f4.field_0 = stream->vf27(true);
        desc.field_f4.field_4 = stream->vf27(true);
        desc.field_fc = stream->vf22(true);
        desc.field_fd = stream->vf22(true);
        desc.field_fe = stream->vf22(true);
        field_470 = field_468->vf49(2, nullptr, 0, nullptr);
        if (field_470 == nullptr) {
            return false;
        }
        field_470->vf45(Unk_StringCStr(&name));
        return field_470->vf22(&desc);
    }
    Unk_582f10(stream, alignment);
    s32 kind = stream->vf27(true);
    if (field_470 != nullptr) {
        if (field_470->vf37()) {
            field_470->vf39(kind);
        }
        if (field_470->vf19()->field_0 != kind) {
            return false;
        }
    } else {
        field_470 = field_468->vf49(kind, nullptr, 0, nullptr);
        if (field_470 == nullptr) {
            return false;
        }
    }
    field_470->vf45(Unk_StringCStr(&name));
    Unk_582f10(stream, alignment);
    SiGfxNXTexture::Unk_Desc desc;
    stream->vf21(&desc, 0x60, true);
    Unk_582f10(stream, alignment);
    Unk_BlockHeader block = {};
    Unk_583140(stream, &block, alignment);
    Unk_582f10(stream, alignment);
    void* buffer = nullptr;
    s32 count = static_cast<s32>(desc.field_54);
#line 343
    SIGFX_TEXTURE_INITDATA* levels = UNK_ALLOC_ARRAY(field_8.m_pAllocator, SIGFX_TEXTURE_INITDATA, count, 0xffffffff);
    if (levels == nullptr) {
        return false;
    }
    for (s64 i = 0; i < count; i++) {
        levels[i].field_0 = nullptr;
        levels[i].field_8 = 0;
        levels[i].field_10 = 0;
        levels[i].field_14 = 0;
    }
    if (block.field_0 > 0) {
        const u8* data = reinterpret_cast<const u8*>(stream->vf76()) + stream->vf17();
        s64 size = 0;
        const u8* pixels =
            static_cast<const u8*>(Unk_583580(field_8.m_pAllocator, &block, data, &buffer, &size));
        stream->vf19(size);
        Unk_582f10(stream, alignment);
        for (s32 i = 0; i < static_cast<s32>(desc.field_54); i++) {
            levels[i].field_0 = const_cast<u8*>(pixels) + stream->vf28(true);
            levels[i].field_8 = stream->vf28(true);
            levels[i].field_10 = stream->vf27(true);
            levels[i].field_14 = stream->vf27(true);
        }
        desc.field_60 = levels;
    }
    desc.field_34 |= field_458;
    desc.field_38 |= field_45c;
    desc.field_3c |= field_460;
    if (desc.field_0 != 0 && static_cast<s32>(desc.field_10) > 0 && static_cast<s32>(desc.field_14) > 0) {
        if (!field_470->vf22(&desc)) {
            if (buffer != nullptr) {
#line 412
                UNK_FREE(field_8.m_pAllocator, buffer);
            }
#line 413
            SI_DELETE_ARRAY(field_8.m_pAllocator, levels);
            return false;
        }
    }
    if (buffer != nullptr) {
#line 418
        UNK_FREE(field_8.m_pAllocator, buffer);
    }
#line 419
    SI_DELETE_ARRAY(field_8.m_pAllocator, levels);
    return true;
}

}  // namespace SiSDK3

// 0x71004efa70: a new handler
SiSDK3::SiGfxTextureChunkHandler* Unk_4efa70(SiSDK3::ISiAllocator* pAllocator) {
#line 35
    return UNK_SI_NEW(pAllocator, 0x10) SiSDK3::SiGfxTextureChunkHandler(pAllocator);
}
