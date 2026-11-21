// SiSDK3::SiGfxShaderEffectPackage (RTTI names the class): a file of shader
// effects, their definitions and variations. Its layout is its constructor's
// and destructor's; placeholder members, the virtual functions are vf<slot>.
// The reference counts are defined in this header (their __FILE__), at the
// original's lines, for the class's own translation unit
// (UNK_SIGFX_SHADEREFFECTPACKAGE_IMPL).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_Array.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_String.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_4bf660.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/ShaderEffect/SiGfx_ShaderEffectVariationList_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiOS/Source/Unk_596410.h>

namespace SiSDK3 {

class ISiIOStream;
class ISiGfxShader;

// A definition and a variation as the package uses them: slot 14 writes one
// to a stream.
class ISiGfxShaderEffectDefinition {
public:
    virtual ~ISiGfxShaderEffectDefinition();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual bool vf14(ISiIOStream* stream);
};
class ISiGfxShaderEffectVariation {
public:
    virtual ~ISiGfxShaderEffectVariation();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual bool vf14(ISiIOStream* stream);
};

class ISiGfxShaderEffectPackage {
public:
    // An effect's data (RTTI: the pointee of the package's arrays), as far
    // as the package's functions written so far read it.
    struct ShaderEffectData {
        // What field_58 is, as the package uses it: slot 5 is its name.
        class Unk_Object {
        public:
            virtual ~Unk_Object();
            virtual u32 vf2();
            virtual u32 vf3();
            virtual void vf4();
            virtual SiString<char>* vf5();
        };
        // One of its field_60's (placeholder name)
        struct Unk_Item;

        u64 field_0;
        SiString<char> field_8;  // its name
        u32 field_38;
        s32 field_3c;  // its index among the package's
        s32 field_40;
        u32 field_44;
        u64 field_48;
        u64 field_50;
        Unk_Object* field_58;
        SiArray<Unk_Item*> field_60;
    };
};

// A table of 64 entries and four numbers (placeholder name): the package
// writes and reads them (and its options end with the same members).
struct Unk_56a350 {
    struct Unk_Entry {
        s32 field_0;
        s32 field_4;
        s32 field_8;
        s32 field_c;
        s32 field_10;
        s32 field_14;
        s32 field_18;
        s32 field_1c;
    };

    s32 field_0;  // the number of entries
    Unk_Entry field_4[0x40];
    s32 field_804;  // the number of field_808's
    s32 field_808[4];
    s32 field_818;
};
PKMN_SIZE_ASSERT(Unk_56a350, 0x81c);

// A shader's code as vf14 is given it (placeholder name): 16 bytes.
struct Unk_5693e0 {
    u64 field_0[2];
};

// A preprocessor definition: its name and its value (RTTI: the element of
// SiArray<SIGFX_SHADER_PREPROCESSOR, 16>).
struct SIGFX_SHADER_PREPROCESSOR {
    SiString<char> field_0;
    SiString<char> field_30;
};
PKMN_SIZE_ASSERT(SIGFX_SHADER_PREPROCESSOR, 0x60);

// Two numbers that are read and written one after the other and copied as one
// (placeholder name).
struct Unk_567750_Pair {
    s32 field_0;
    s32 field_4;
};

// Two numbers and such a pair, copied as one (placeholder name).
struct Unk_567750_Half {
    u32 field_0;
    u32 field_4;
    Unk_567750_Pair field_8;
};

// What a package is made for (placeholder name): vf12 takes one, the file's
// header holds its members. Its constructor clears the two pairs.
struct Unk_567750_Desc {
    Unk_567750_Desc() {
        field_0.field_8.field_0 = 0;
        field_0.field_8.field_4 = 0;
        field_10.field_8.field_0 = 0;
        field_10.field_8.field_4 = 0;
    }

    Unk_567750_Half field_0;
    Unk_567750_Half field_10;
    u32 field_20;
};
PKMN_SIZE_ASSERT(Unk_567750_Desc, 0x24);

// The version in the file's header (placeholder name).
struct Unk_567750_Version {
    Unk_567750_Version() : field_0(0), field_4(0), field_8(0), field_c(0) {}

    s32 field_0;
    s32 field_4;
    s32 field_8;
    s32 field_c;
};

// The file's header (placeholder name).
struct Unk_567750_Header {
    char field_0[0x20];  // "SiGfxShaderEffectPackage"
    u8 field_20;         // the byte order
    u8 field_21[0xf];
    Unk_567750_Version field_30;
    // Unk_567750_Desc's members
    Unk_567750_Half field_40;
    Unk_567750_Half field_50;
    u32 field_60;
    s32 field_64;  // what the bytes at field_be8 are aligned to in the file
    s64 field_68;  // how many they are
    s32 field_70;  // the number of variations
    s32 field_74;
    s32 field_78;  // the number of definitions
    s32 field_7c;  // the number of effects' data
    s32 field_80;  // the numbers of shaders
    s32 field_84;
    s32 field_88;
    s32 field_8c;
    s32 field_90;
    s32 field_94;
};
PKMN_SIZE_ASSERT(Unk_567750_Header, 0x98);

// The options effects are compiled with (placeholder name, after its
// constructor): vf16 takes one.
struct Unk_567b80 {
    struct Unk_Sub {
        Unk_Sub()
            : field_0(0), field_4(0), field_8(0), field_c(0), field_10(4), field_14(0), field_18(0), field_1c(0) {}
        u32 field_0;
        u32 field_4;
        u32 field_8;
        u32 field_c;
        u32 field_10;
        u32 field_14;
        u32 field_18;
        u32 field_1c;
    };
    // 0x7100567b80
    explicit Unk_567b80(ISiAllocator* pAllocator);

    ISiAllocator* field_0;
    SiArray<SIGFX_SHADER_PREPROCESSOR> field_8;
    SiArray<SiString<char> > field_58;
    u64 field_a8;
    u64 field_b0;
    SiString<char> field_b8;
    s32 field_e8;
    s32 field_ec;
    s32 field_f0;
    bool field_f4;
    bool field_f5;
    u32 field_f8;
    u32 field_fc;
    Unk_Sub field_100[0x40];
    s32 field_900;
    s32 field_904;
    s32 field_908;
    s32 field_90c;
    s32 field_910;
    s32 field_914;
};
PKMN_SIZE_ASSERT(Unk_567b80, 0x918);

class SiGfxShaderEffect;

class SiGfxShaderEffectPackage {
public:
    explicit SiGfxShaderEffectPackage(ISiAllocator* pAllocator);
    virtual ~SiGfxShaderEffectPackage();
    UNK_REFCOUNT_DECLARE;
    virtual u32 vf4();
    virtual void vf5(const char* name);  // sets the name
    virtual SiString<char>* vf6();       // the name
    virtual const u8* vf7();
    virtual bool vf8(const char* path);  // reads a file
    virtual bool vf9();  // releases what it holds
    virtual bool vf10(const char* path, u32 byteOrder);  // writes a file
    virtual bool vf11();
    virtual bool vf12(const Unk_567750_Desc* desc);
    virtual bool vf13(ISiIOStream* stream);
    virtual bool vf14(s64 value108, void* valueBe8, u32 value104, const SiArray<Unk_5693e0>* shaders0,
                      const SiArray<Unk_5693e0>* shaders1, const SiArray<Unk_5693e0>* shaders2,
                      const SiArray<Unk_5693e0>* shaders3, const SiArray<Unk_5693e0>* shaders4,
                      const SiArray<Unk_5693e0>* shaders5);
    virtual bool vf15(ISiGfxShaderEffectPackage::ShaderEffectData* data);  // adds an effect's data
    virtual void vf16(const Unk_567b80* options);
    virtual const u8* vf17();
    virtual const u8* vf18();
    virtual u32 vf19();
    virtual ISiGfxShaderEffectPackage::ShaderEffectData* vf20(s32 index);
    virtual void* vf21(const char* name);
    virtual bool vf22(SiGfxShaderEffect* effect);  // adds an effect
    virtual const u8* vf23();
    virtual void vf24(bool value);
    virtual u8 vf25();
    virtual void vf26(bool value);
    virtual u8 vf27();
    virtual bool vf28();

    // 0x71005686f0: releases the effects' data, definitions and variations
    bool Unk_5686f0();
    // 0x7100569c40: writes the shaders' code, 0x7100569dd0: an effect's data
    bool Unk_569c40(ISiIOStream* stream);
    bool Unk_569dd0(ISiIOStream* stream, ISiGfxShaderEffectPackage::ShaderEffectData* data);
    // 0x7100569f40: writes one of an effect's field_60's
    bool Unk_569f40(ISiIOStream* stream, ISiGfxShaderEffectPackage::ShaderEffectData* data,
                    ISiGfxShaderEffectPackage::ShaderEffectData::Unk_Item* item);
    // 0x710056a350: writes a table, 0x710056c480: reads one
    bool Unk_56a350_(ISiIOStream* stream, Unk_56a350* table);
    bool Unk_56c480(ISiIOStream* stream, Unk_56a350* table);
    // 0x710056ae10, 0x710056b000, 0x710056b230, 0x710056b8a0: read the parts
    // of a file after its header
    bool Unk_56ae10(ISiIOStream* stream, Unk_567750_Header* header);
    bool Unk_56b000(ISiIOStream* stream, Unk_567750_Header* header);
    bool Unk_56b230(ISiIOStream* stream, Unk_567750_Header* header);
    bool Unk_56b8a0(ISiIOStream* stream, Unk_567750_Header* header);
    // 0x71005697b0: writes the file's header, 0x710056a960: reads it
    bool Unk_5697b0(ISiIOStream* stream, u32 byteOrder);
    bool Unk_56a960(ISiIOStream* stream, Unk_567750_Header* header);
    // 0x710056d320
    bool Unk_56d320();

    Unk_4bf660 field_8;
    SiString<char> field_18;  // the name
    SiString<char> field_48;
    Unk_567750_Desc field_78;
    Unk_567750_Header field_a0;
    s32 field_138;  // how many times vf12 was called
    bool field_13c;
    bool field_13d;
    bool field_13e;
    bool field_13f;
    SiArray<ISiGfxShaderEffectPackage::ShaderEffectData*> field_140;
    SiArray<ISiGfxShaderEffectPackage::ShaderEffectData*> field_190;
    SiArray<SiGfxShaderEffect*> field_1e0;
    SiArray<ISiGfxShaderEffectVariation*> field_230;
    SiArray<ISiGfxShaderEffectDefinition*> field_280;
    Unk_567b80 field_2d0;
    void* field_be8;
    bool field_bf0;
    Unk_5693e0* field_bf8[6];  // the shaders' code of the header's six numbers
    Unk_CriticalSection field_c28;
    SiArray<ISiGfxShader*> field_c58[6];
    SiGfxShaderEffectVariationList field_e38;
};
PKMN_SIZE_ASSERT(SiGfxShaderEffectPackage, 0xfb0);
PKMN_OFFSET_ASSERT(SiGfxShaderEffectPackage, field_140, 0x140);
PKMN_OFFSET_ASSERT(SiGfxShaderEffectPackage, field_2d0, 0x2d0);
PKMN_OFFSET_ASSERT(SiGfxShaderEffectPackage, field_c28, 0xc28);
PKMN_OFFSET_ASSERT(SiGfxShaderEffectPackage, field_e38, 0xe38);

}  // namespace SiSDK3

#ifdef UNK_SIGFX_SHADEREFFECTPACKAGE_IMPL
// 0x710056d8a0 (vf2), 0x710056d8c0 (vf3)
#line 34
UNK_REFCOUNT_DEFINE(SiSDK3::SiGfxShaderEffectPackage, field_8.m_pAllocator, field_8.m_count)
#endif
