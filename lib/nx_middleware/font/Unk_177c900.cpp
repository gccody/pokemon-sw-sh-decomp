// Scope: common
// NintendoWare Font 7.3.2: nn::font::Font's (RTTI) constructor, destructors
// and character stream readers, and the functions of nn::font::ResFont's base
// (vtable 0x710246a5c8) that set up and tear down the texture of a FFNT
// resource's glyph sheets (a NintendoSDK gfx texture file). Placeholder names.
//
// Unk_177baf0.h declares these classes too, but not as the original's: its
// nn::font::Font isn't abstract (the original's deleting destructor is a
// trap, as clang emits it for an abstract class) and its slot 33 returns
// nothing. This file keeps its own declarations, with the same layout.
#include <types.h>

#include "nx_middleware/font/Unk_177ce00_Reader.h"

namespace nn {
namespace util {
class BinaryBlockHeader {
public:
    // _ZNK2nn4util17BinaryBlockHeader12GetBlockSizeEv (SDK import)
    size_t GetBlockSize() const noexcept;
};
}  // namespace util
}  // namespace nn

struct Unk_239a418_Type;
struct Unk_1791080_Device;
struct Unk_1790b60_Texture;
struct Unk_1790b60_Pool;
struct Unk_1789c10_MemoryPool;
struct Unk_1790ca0_View;
struct Unk_1790de0;
struct Unk_1787640_Info;
struct Unk_177cd90;

// A texture's info (lib/nx_middleware/gfx/gfx.h's): mip levels, image format
// and array length.
struct Unk_178dac0_Info {
    u8 _0[0x6];
    u16 field_6;
    u8 _8[0x4];
    s32 field_c;
    u8 _10[0x10];
    s32 field_20;
    u8 _24[0x1c];
};
PKMN_OFFSET_ASSERT(Unk_178dac0_Info, field_6, 0x6);
PKMN_OFFSET_ASSERT(Unk_178dac0_Info, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_178dac0_Info, field_20, 0x20);
PKMN_SIZE_ASSERT(Unk_178dac0_Info, 0x40);

// A memory pool's info (gfx.h's, which has only its first 0x10 bytes): NVN
// flags, size and memory.
struct Unk_178da60_Info {
    void SetMemory(void* memory, u32 size) {
        field_8 = memory;
        field_4 = size;
    }

    s32 field_0;
    u32 field_4;
    void* field_8;
    u8 _10[0x10];
};
PKMN_SIZE_ASSERT(Unk_178da60_Info, 0x20);

// A texture view's info (lib/nx_middleware/gfx/Unk_1790ca0.cpp's, which has
// only its first 0x38 bytes): image dimension, image format, channel mapping,
// mip levels, array length and the texture.
struct Unk_1790ca0_Channels {
    u8 field_0[4];
};

struct Unk_1790ca0_Info {
    u8 field_0;
    u8 _1[0x3];
    s32 field_4;
    Unk_1790ca0_Channels field_8;
    u8 _c[0x6];
    u16 field_12;
    u8 _14[0x10];
    s32 field_24;
    u8 _28[0x8];
    Unk_1790b60_Texture* field_30;
    u8 _38[0x8];
};
PKMN_OFFSET_ASSERT(Unk_1790ca0_Info, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_1790ca0_Info, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_1790ca0_Info, field_12, 0x12);
PKMN_OFFSET_ASSERT(Unk_1790ca0_Info, field_24, 0x24);
PKMN_OFFSET_ASSERT(Unk_1790ca0_Info, field_30, 0x30);
PKMN_SIZE_ASSERT(Unk_1790ca0_Info, 0x40);

void* Unk_17873b0(void* data);
void Unk_1787640(Unk_1787640_Info* self);
void Unk_1789c10(Unk_1789c10_MemoryPool* self, const Unk_1791080_Device* device, const Unk_178da60_Info* info);
void Unk_1789ca0(Unk_1789c10_MemoryPool* self, Unk_1791080_Device* device);
void Unk_1790b60(Unk_1790b60_Texture* self, const Unk_1791080_Device* device, const Unk_178dac0_Info& info,
                 const Unk_1790b60_Pool* pool, s64 offset, size_t size);
void Unk_1790c30(Unk_1790b60_Texture* self, const Unk_1791080_Device* device);
void Unk_1790ca0(Unk_1790ca0_View* self, const Unk_1791080_Device* device, const Unk_1790ca0_Info& info);
void Unk_1790de0_set(Unk_1790de0* self, u64 value);
void Unk_177cd90_set(Unk_177cd90* self, u64 value, u16 arg2, u16 arg3, u16 arg4, u8 arg5, bool arg6);

// The textures of a gfx texture file: their count and data, the memory pool's
// data block, and the memory pool (its own, in field_20, or the one it was
// given) and the offset of its data in it.
struct Unk_177caa0_Texture;
struct Unk_177caa0_Container {
    u32 signature;
    u32 count;
    Unk_177caa0_Texture** field_8;
    const nn::util::BinaryBlockHeader* field_10;
    u8 _18[0x8];
    Unk_1789c10_MemoryPool* field_20;
    Unk_1789c10_MemoryPool* field_28;
    u32 field_30;
};
PKMN_OFFSET_ASSERT(Unk_177caa0_Container, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_177caa0_Container, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_177caa0_Container, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_177caa0_Container, field_30, 0x30);

struct Unk_177caa0_File {
    u8 _0[0x20];
    Unk_177caa0_Container field_20;
};
PKMN_OFFSET_ASSERT(Unk_177caa0_File, field_20, 0x20);

// A texture of the file: its info, size, channel mapping and dimension, the
// file's container, its data, and the texture and view objects.
struct Unk_177caa0_Texture {
    u8 _0[0x10];
    Unk_178dac0_Info field_10;
    u32 field_50;
    u8 _54[0x4];
    Unk_1790ca0_Channels field_58;
    u8 field_5c;
    u8 _5d[0xb];
    Unk_177caa0_Container* field_68;
    const u8* const* field_70;
    u8 _78[0x8];
    Unk_1790b60_Texture* field_80;
    Unk_1790ca0_View* field_88;
};
PKMN_OFFSET_ASSERT(Unk_177caa0_Texture, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_177caa0_Texture, field_50, 0x50);
PKMN_OFFSET_ASSERT(Unk_177caa0_Texture, field_58, 0x58);
PKMN_OFFSET_ASSERT(Unk_177caa0_Texture, field_5c, 0x5c);
PKMN_OFFSET_ASSERT(Unk_177caa0_Texture, field_68, 0x68);
PKMN_OFFSET_ASSERT(Unk_177caa0_Texture, field_80, 0x80);
PKMN_OFFSET_ASSERT(Unk_177caa0_Texture, field_88, 0x88);

// The TGLP block's data (Unk_177c400.cpp's).
struct Unk_177c900_Glyph {
    u8 _0[0xa];
    u16 sheetFormat;
    u8 _c[0x4];
    u16 sheetWidth;
    u16 sheetHeight;
    u32 sheetOffset;  // from the start of the file (0: none)
};
PKMN_OFFSET_ASSERT(Unk_177c900_Glyph, sheetFormat, 0xa);
PKMN_OFFSET_ASSERT(Unk_177c900_Glyph, sheetWidth, 0x10);
PKMN_OFFSET_ASSERT(Unk_177c900_Glyph, sheetOffset, 0x14);

// The FINF block's data: the TGLP data's offset.
struct Unk_177c900_Info {
    u8 _0[0xc];
    u32 glyphOffset;
};
PKMN_OFFSET_ASSERT(Unk_177c900_Info, glyphOffset, 0xc);

namespace nn {
namespace font {

// The texture object (Unk_177baf0.h's Unk_246a758 and its derived class),
// without its virtual functions.
class ResourceTextureObject {
public:
    void Reset() {
        Unk_177cd90_set(reinterpret_cast<Unk_177cd90*>(this), 0, 0xc, 0, 0, 0, true);
        field_20 = -1;
        field_18 = false;
    }

    void Unk_177caa0(const Unk_1791080_Device* device, Unk_1789c10_MemoryPool* pool, s64 offset, size_t size);

    u8 _0[0x8];  // the vtable pointer
    u64 field_8;  // the gfx texture file (Unk_177cd90_set's fields, up to 0x18)
    u16 field_10;
    u16 field_12;
    u16 field_14;  // its format
    u8 _16[0x2];
    bool field_18;
    s64 field_20;
    const Unk_177caa0_Texture* field_28;
};
PKMN_OFFSET_ASSERT(ResourceTextureObject, field_8, 0x8);
PKMN_OFFSET_ASSERT(ResourceTextureObject, field_14, 0x14);
PKMN_OFFSET_ASSERT(ResourceTextureObject, field_18, 0x18);
PKMN_OFFSET_ASSERT(ResourceTextureObject, field_20, 0x20);
PKMN_OFFSET_ASSERT(ResourceTextureObject, field_28, 0x28);
PKMN_SIZE_ASSERT(ResourceTextureObject, 0x30);

class Font {
public:
    Font();
    virtual const Unk_239a418_Type* vf0();
    virtual ~Font();
    virtual void vf3(u64 arg);
    virtual u32 vf4() = 0;
    virtual u32 vf5() = 0;
    virtual u32 vf6() = 0;
    virtual u32 vf7() = 0;
    virtual u32 vf8() = 0;
    virtual u32 vf9() = 0;
    virtual u32 vf10() = 0;
    virtual s32 vf11() = 0;
    virtual u32 vf12() = 0;
    virtual void vf13(s8 value) = 0;
    virtual void vf14(const void* value) = 0;
    virtual bool vf15(u32 code) = 0;
    virtual u32 vf16() = 0;
    virtual u32 vf17(u32 code) = 0;
    virtual void vf18(void* glyph, u32 code) = 0;
    virtual bool vf19(u32 code) = 0;
    virtual s32 vf20(u32 first, u32 second) = 0;
    virtual u32 vf21() = 0;  // the encoding
    virtual s32 vf22() = 0;
    virtual u32 vf23() = 0;
    virtual u32 vf24() = 0;
    virtual void vf25(bool arg1, bool arg2) = 0;
    virtual u32 vf26() = 0;
    virtual u32 vf27() = 0;
    virtual u32 vf28() = 0;
    virtual u32 vf29() = 0;
    virtual void vf30(bool value) = 0;
    virtual bool vf31();
    virtual bool vf32() = 0;

    Unk_177ce00_Reader Unk_177ce00();
    Unk_177ce00_Reader Unk_177ce70();

    bool field_8;
    bool field_9;
};
PKMN_OFFSET_ASSERT(Font, field_8, 0x8);
PKMN_OFFSET_ASSERT(Font, field_9, 0x9);

}  // namespace font
}  // namespace nn

class Unk_246a5b8 : public nn::font::Font {
public:
    virtual u8 vf33();  // the TGLP data's field_2

    void Unk_177c900(u64 device);

    const Unk_177c900_Glyph* Glyph() const {
        return reinterpret_cast<const Unk_177c900_Glyph*>(field_18 + field_20->glyphOffset);
    }

    u64 field_10;
    const u8* field_18;  // the resource
    Unk_177c900_Info* field_20;
    nn::font::ResourceTextureObject field_28;
    u32 field_58;
    u64 field_60;
    u64 field_68;
    s64 field_70;
    u64 field_78;
    u8 _80[0x88];
};
PKMN_OFFSET_ASSERT(Unk_246a5b8, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_246a5b8, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_246a5b8, field_68, 0x68);
PKMN_OFFSET_ASSERT(Unk_246a5b8, field_78, 0x78);
PKMN_SIZE_ASSERT(Unk_246a5b8, 0x108);

// The distance in bytes from one address to another.
inline s64 Unk_177c900_Distance(u64 from, u64 to) {
    return to - from;
}

// NON_MATCHING: the original loads field_78 (the last argument) before
// field_68 and field_70; same instructions otherwise.
// 0x710177c900
void Unk_246a5b8::Unk_177c900(u64 device) {
    if (field_28.field_18) {
        return;
    }
    const Unk_177c900_Glyph* glyph = Glyph();
    u8 sheetCount = vf33();
    const u8* image = glyph->sheetOffset != 0 ? field_18 + glyph->sheetOffset : nullptr;
    Unk_177cd90_set(reinterpret_cast<Unk_177cd90*>(&field_28), reinterpret_cast<u64>(image), glyph->sheetFormat,
                    glyph->sheetWidth, glyph->sheetHeight, sheetCount, true);
    u32 format = field_28.field_14 & 0x3fff;
    if (format < 0x14) {
        switch (format) {
        case 1:
        case 6:
        case 7:
            break;
        default:
            field_28.Unk_177caa0(reinterpret_cast<const Unk_1791080_Device*>(device),
                                 reinterpret_cast<Unk_1789c10_MemoryPool*>(field_68),
                                 Unk_177c900_Distance(field_10, field_28.field_8) + field_70, field_78);
            break;
        }
    }
}

// 0x710177c9f0
void Unk_177c9f0(void* /*font*/, u64 device, void* object) {
    nn::font::ResourceTextureObject* texture = static_cast<nn::font::ResourceTextureObject*>(object);
    if (!texture->field_18) {
        return;
    }
    Unk_177caa0_File* file = static_cast<Unk_177caa0_File*>(Unk_17873b0(reinterpret_cast<void*>(texture->field_8)));
    if (file->field_20.field_28 != nullptr) {
        const Unk_177caa0_Texture* data = texture->field_28;
        Unk_1790c30(data->field_80, reinterpret_cast<const Unk_1791080_Device*>(device));
        Unk_1790de0_set(reinterpret_cast<Unk_1790de0*>(data->field_88), device);
        if (file->field_20.field_28 == file->field_20.field_20) {
            Unk_1789ca0(file->field_20.field_28, reinterpret_cast<Unk_1791080_Device*>(device));
        }
        file->field_20.field_28 = nullptr;
    }
    texture->Reset();
}

namespace nn {
namespace font {

// NON_MATCHING: register allocation (the pool and the offset swap their
// callee-saved registers) and the order of two argument additions.
// 0x710177caa0
void ResourceTextureObject::Unk_177caa0(const Unk_1791080_Device* device, Unk_1789c10_MemoryPool* pool,
                                        s64 offset, size_t /*size*/) {
    Unk_177caa0_File* file = static_cast<Unk_177caa0_File*>(Unk_17873b0(reinterpret_cast<void*>(field_8)));
    Unk_177caa0_Container* container = &file->field_20;
    if (container->field_28 != nullptr) {
        field_28 = container->field_8[0];
        return;
    }

    u32 poolOffset;
    if (pool != nullptr) {
        poolOffset = offset + (reinterpret_cast<const u8*>(container->field_10) + 0x10 -
                               reinterpret_cast<const u8*>(file));
        container->field_28 = pool;
    } else {
        Unk_178da60_Info info = {};
        info.field_0 = 0x21;
        const nn::util::BinaryBlockHeader* block = container->field_10;
        info.SetMemory(const_cast<u8*>(reinterpret_cast<const u8*>(block) + 0x10), block->GetBlockSize() - 0x10);
        Unk_1789c10(container->field_20, device, &info);
        container->field_28 = container->field_20;
        poolOffset = 0;
    }
    container->field_30 = poolOffset;

    const Unk_177caa0_Texture* texture = container->field_8[0];
    field_28 = texture;
    const Unk_177caa0_Container* textures = texture->field_68;
    const u8* data = reinterpret_cast<const u8*>(textures->field_10) + 0x10;
    s64 dataOffset = textures->field_30 + (*texture->field_70 - data);
    Unk_1790b60(texture->field_80, device, texture->field_10,
                reinterpret_cast<const Unk_1790b60_Pool*>(textures->field_28), dataOffset, texture->field_50);

    Unk_1790ca0_Info info = {};
    Unk_1787640(reinterpret_cast<Unk_1787640_Info*>(&info));
    info.field_0 = texture->field_5c;
    info.field_8 = texture->field_58;
    info.field_4 = texture->field_10.field_c;
    info.field_30 = texture->field_80;
    info.field_24 = texture->field_10.field_20;
    info.field_12 = texture->field_10.field_6;
    Unk_1790ca0(texture->field_88, device, info);
}

// 0x710177cdc0
Font::Font() : field_8(true), field_9(true) {}

// 0x710177cde0
Font::~Font() {}

// NON_MATCHING: the original picks the encodings 1 and 2's readers with
// selects after a branch for 3 (a switch of two cases after an `if`, as
// SimplifyCFG leaves it); this switch of three cases is lowered as branches.
// 0x710177ce00
Unk_177ce00_Reader Font::Unk_177ce00() {
    switch (vf21()) {
    case 1:
        return Unk_177ce00_Reader(nullptr, &Unk_177ce00_Reader::Unk_177cf20);
    case 2:
        return Unk_177ce00_Reader(nullptr, &Unk_177ce00_Reader::Unk_177cfa0);
    case 3:
        return Unk_177ce00_Reader(nullptr, &Unk_177ce00_Reader::Unk_177cf80);
    default:
        return Unk_177ce00_Reader(nullptr, nullptr);
    }
}

// 0x710177ce70
Unk_177ce00_Reader Font::Unk_177ce70() {
    return Unk_177ce00_Reader(nullptr, vf21() == 1 ? &Unk_177ce00_Reader::Unk_177cf60 : nullptr);
}

}  // namespace font
}  // namespace nn
