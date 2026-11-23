// SiSDK3::SiGfxShaderUtility: what keeps the shader effect packages and the
// binary cache packages. As far as the executable's functions show it, with
// placeholder members (RTTI names the classes: SiGfxShaderUtility derives from
// ISiGfxShaderUtility, which this leaves out). The reference counts are
// defined in this header (their __FILE__), at the original's lines, for the
// file that asks with UNK_SIGFX_SHADERUTILITY_IMPL. The virtual functions
// declared and not defined here or in the .cpp are lib/yebis/class's or not
// decompiled yet (placeholder signatures).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_Array.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_String.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_4bf660.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/ShaderCache/SiGfx_ShaderCache_BinaryPackage_Impl.h>

namespace SiSDK3 {

class ISiGfxShaderEffectDefinition;
class ISiGfxShaderEffectVariationList;

// What a package's slot 23 returns (placeholder name): slot 19 is what the
// utility's slot 11 asks of it.
class Unk_4e40b0_Object {
public:
    virtual void vf0();
    virtual void vf1();
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
    virtual void vf12(const char* path, bool flag);  // 0x71004e4120
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
};

// A shader effect package as the utility calls it (RTTI: the pointee of
// SiArray<ISiGfxShaderEffectPackage*, 16>; SiGfxShaderEffectPackage's slots,
// placeholder names). The package's own header has this class as the scope
// of the package's data, without its slots: this file doesn't include it.
class ISiGfxShaderEffectPackage {
public:
    // an effect's data, as far as the utility reads it (the package's header
    // has the whole of it)
    struct ShaderEffectData {
        u8 field_0[0x3c];
        s32 field_3c;  // its index among the package's
        s32 field_40;
        s32 field_44;
        s32 field_48;  // the sizes of the variation's two keys
        s32 field_4c;
        s32 field_50;
    };

    virtual ~ISiGfxShaderEffectPackage();
    virtual u32 vf2();
    virtual u32 vf3();
    virtual u32 vf4();
    virtual void vf5(const char* name);    // sets the name
    virtual SiString<char>* vf6();         // the name
    virtual void vf7();
    virtual bool vf8(const char* path);    // reads a file
    virtual void vf9();                    // releases what it holds
    virtual void vf10();
    virtual bool vf11();                   // reads its file again
    virtual void vf12(const char* path, bool flag);  // 0x71004e4120
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual ShaderEffectData* vf21(const char* name);  // an effect's data by name
    virtual void vf22();
    virtual Unk_4e40b0_Object* vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual bool vf28();
};

// What the utility's slot 25 fills in (placeholder name: a shader's
// compilation request, as far as that slot shows it).
struct Unk_4e7710_Request {
    u8 field_0[0x38];
    s32 field_38;
    s32 field_3c;
    u64 field_40;  // two numbers (0x71004ee870 writes them "%d_%d")
    s32 field_48;
    s32 field_4c;
    u64 field_50;
    s32 field_58;
    s32 field_5c;
    s32 field_60;
    SiString<char> field_68;
    SiString<char> field_98;
    SiString<char> field_c8;  // a key, in hexadecimal
    SiString<char> field_f8;  // another
    SiString<char> field_128;
    SiString<char> field_158;
    SiArray<SiString<char>> field_188;
    SiArray<SiString<char>> field_1d8;
    u32 field_228;
};
PKMN_OFFSET_ASSERT(Unk_4e7710_Request, field_68, 0x68);
PKMN_OFFSET_ASSERT(Unk_4e7710_Request, field_188, 0x188);
PKMN_OFFSET_ASSERT(Unk_4e7710_Request, field_228, 0x228);

class SiGfxShaderUtility {
public:
    explicit SiGfxShaderUtility(ISiAllocator* pAllocator);
    virtual ~SiGfxShaderUtility();
    UNK_REFCOUNT_DECLARE;
    virtual u32 vf4();
    // adds a package of that name, read from the file if there is one
    virtual bool vf5(const char* name, const char* path);  // 0x71004e3c40
    virtual void vf6(const char* name);                    // 0x71004e3dc0: takes it out
    virtual void vf7();                                    // 0x71004e3ed0: releases them all
    virtual ISiGfxShaderEffectPackage* vf8(const char* name);  // 0x71004e3f80
    virtual void vf9(bool value);
    virtual u8 vf10();
    virtual void vf11();  // 0x71004e40b0
    virtual void vf12(const char* path, bool flag);  // 0x71004e4120
    virtual const u8* vf13();
    virtual void vf14();
    // reads the variation lists of a file (placeholder types)
    virtual bool vf15(const char* path, SiArray<ISiGfxShaderEffectVariationList*>* lists);  // 0x71004e5f50
    // sets the binary cache package
    virtual bool vf16(ISiGfxShaderBinaryCachePackage* pPackage);  // 0x71004e6190
    virtual ISiGfxShaderBinaryCachePackage* vf17();
    virtual SiGfxShaderBinaryCachePackage* vf18();  // 0x71004e61f0: makes one
    // the same for the list of them
    virtual bool vf19(ISiGfxShaderBinaryCachePackage* pPackage);  // 0x71004e6270
    virtual void vf20(ISiGfxShaderBinaryCachePackage* pPackage);  // 0x71004e6320
    virtual void* vf21(const void* a1, void* a2);                 // 0x71004e64a0
    virtual void vf22();                                          // 0x71004e63f0
    virtual void vf23();                                          // 0x71004e6520
    virtual void vf24();                                          // 0x71004e6580
    virtual bool vf25(Unk_4e7710_Request* request, s32 a2, s32 a3, const u64* a4, s32 a5, s32 a6, const u64* a7,
                      s32 a8, s32 a9, s32 a10, const char* s1, const char* s2, const void* key1, const char* s3,
                      const void* key2, const char* s4, const SiArray<SiString<char>>* names);  // 0x71004e7710

    // 0x71004e65e0: what the kernel asks of it for a new device of a kind
    // (the kind's common package, from the kernel's directory or SiSDK's)
    bool Unk_4e65e0(u32 kind);
    // 0x71004e6c80: the kind's other packages
    bool Unk_4e6c80(u32 kind);
    // 0x71004e57e0: adds lists to others, merging those of the same package
    void Unk_4e57e0(SiArray<ISiGfxShaderEffectVariationList*>* lists, SiArray<ISiGfxShaderEffectVariationList*>* others);
    // 0x71004e5d80: adds the variations of a list that the other doesn't have
    void Unk_4e5d80(ISiGfxShaderEffectVariationList* list, ISiGfxShaderEffectVariationList* other);

    Unk_4bf660 field_8;
    SiArray<ISiGfxShaderEffectDefinition*> field_18;
    SiArray<ISiGfxShaderEffectPackage*> field_68;
    ISiGfxShaderBinaryCachePackage* field_b8;
    SiArray<ISiGfxShaderBinaryCachePackage*> field_c0;
    SiString<char> field_110;
    SiString<char> field_140;
    SiString<char> field_170;
    bool field_1a0;
    bool field_1a1;
};
PKMN_OFFSET_ASSERT(SiGfxShaderUtility, field_c0, 0xc0);
PKMN_OFFSET_ASSERT(SiGfxShaderUtility, field_1a0, 0x1a0);
PKMN_SIZE_ASSERT(SiGfxShaderUtility, 0x1a8);
PKMN_OFFSET_ASSERT(ISiGfxShaderEffectPackage::ShaderEffectData, field_50, 0x50);

}  // namespace SiSDK3

#ifdef UNK_SIGFX_SHADERUTILITY_IMPL
// 0x71004e7870 (vf2), 0x71004e7890 (vf3)
#line 32
UNK_REFCOUNT_DEFINE(SiSDK3::SiGfxShaderUtility, field_8.m_pAllocator, field_8.m_count)
#endif
