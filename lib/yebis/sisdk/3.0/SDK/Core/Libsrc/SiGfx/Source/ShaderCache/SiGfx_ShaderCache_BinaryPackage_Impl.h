// SiSDK3::SiGfxShaderBinaryCachePackage: a package of compiled shaders. As
// far as the executable's functions show it, with placeholder members (RTTI
// names the classes). The reference counts are defined in this header (their
// __FILE__), at the original's lines, for the file that asks with
// UNK_SIGFX_SHADERBINARYCACHEPACKAGE_IMPL.
#pragma once

#include <string.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_Array.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_String.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_4bf660.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_Interface.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiOS/Source/Unk_596410.h>

namespace SiSDK3 {

// What a package's entries hold (placeholder name): reference counted.
class Unk_BinaryCacheObject {
public:
    virtual ~Unk_BinaryCacheObject();
    virtual u32 vf2();
    virtual u32 vf3();
    virtual u32 vf4();
    virtual void* vf5();  // its device
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual bool vf18(s64 size, const u8* code, u32 a3);  // compiles a shader's code
};

class SiGfxNXDevice;

// The header of a package's file (placeholder name)
struct Unk_4e9740_Header {
    char field_0[0x20];  // "SSKKShaderBinCache"
    char field_20[8];    // the graphics interface's name
    char field_28[8];    // the shader language's
    bool field_30;
    u8 field_31[0xf];
    s32 field_40;  // the version: 3, 0, 0, 1 (four numbers without a constructor: the package
    s32 field_44;  // keeps a header that its constructor doesn't initialise)
    s32 field_48;
    s32 field_4c;
    s32 field_50;  // how many entries
    s32 field_54;  // where the code is
    s32 field_58;  // where the entries are
    s32 field_5c;  // where the entries' order is
    s32 field_60;  // the code's size
    u8 field_64[0x1c];
};
PKMN_SIZE_ASSERT(Unk_4e9740_Header, 0x80);

// RTTI: SiSDK3::ISiGfxShaderBinaryCachePackage, on ISiInterface. Placeholder
// slots.
class ISiGfxShaderBinaryCachePackage : public ISiInterface {
public:
    virtual bool vf5() = 0;  // starts changes
    virtual void vf6() = 0;
    virtual bool vf7(const char* name, s32 size, const void* code) = 0;  // adds a shader's code
    virtual bool vf8(const char* path, u32 platform, u32 a3) = 0;  // writes the package
    virtual bool vf9(const char* path) = 0;  // reads the package
    virtual void* vf10(const void* a1, void* a2) = 0;
};

class SiGfxShaderBinaryCachePackage : public ISiGfxShaderBinaryCachePackage {
public:
    // A shader being edited (RTTI: the pointee of SiArray<EditEntry*, 16>): its
    // name and its bytes.
    struct EditEntry {
        explicit EditEntry(ISiAllocator* pAllocator) : field_0(pAllocator), field_30(pAllocator) {}
        // 0x71004ea4e0
        ~EditEntry();

        SiString<char> field_0;
        SiArray<u8> field_30;
    };

    // A shader of the package (RTTI: the element of SiArray<Entry, 16>).
    struct Entry {
        // (zero: the entries' reserve, 0x71004ea780, clears the new ones)
        Entry()
            : field_0(0), field_4(0), field_8(0), field_c(0), field_10(0), field_14(0), field_18(nullptr),
              field_20(nullptr), field_28(nullptr) {}

        s32 field_0;
        s32 field_4;
        s32 field_8;
        s32 field_c;   // its code's size
        u32 field_10;  // its name's hash (the entries of field_b8 are in its order)
        s32 field_14;
        const char* field_18;  // its name
        const u8* field_20;    // its code
        Unk_BinaryCacheObject* field_28;
    };

    explicit SiGfxShaderBinaryCachePackage(ISiAllocator* pAllocator);
    ~SiGfxShaderBinaryCachePackage() override;
    u32 vf2() override;
    u32 vf3() override;
    u32 vf4() override;
    bool vf5() override;
    void vf6() override;
    bool vf7(const char* name, s32 size, const void* code) override;
    bool vf8(const char* path, u32 platform, u32 a3) override;
    bool vf9(const char* path) override;
    void* vf10(const void* a1, void* a2) override;

    // 0x71004e8750: releases the entries and empties the arrays
    void Unk_4e8750();
    // 0x71004e8b20: what its maker asks after the constructor (it always
    // succeeds)
    bool Unk_4e8b20();
    // 0x71004ea060: releases what the entries hold for a device
    void Unk_4ea060(SiGfxNXDevice* device);
    // the index in field_b8 of the entry of a hash (-1: none; inline:
    // placeholder name)
    s32 Unk_FindEntry(u32 hash);

    Unk_4bf660 field_8;
    SiArray<EditEntry*> field_18;
    SiArray<Entry> field_68;
    SiArray<Entry*> field_b8;
    SiArray<u8> field_108;
    u32 field_158;  // how many have started changes
    bool field_15c;
    Unk_4e9740_Header field_160;
    SiOSCriticalSection field_1e0;
};
PKMN_SIZE_ASSERT(SiGfxShaderBinaryCachePackage::EditEntry, 0x80);
PKMN_SIZE_ASSERT(SiGfxShaderBinaryCachePackage::Entry, 0x30);
PKMN_OFFSET_ASSERT(SiGfxShaderBinaryCachePackage, field_158, 0x158);
PKMN_OFFSET_ASSERT(SiGfxShaderBinaryCachePackage, field_1e0, 0x1e0);
PKMN_SIZE_ASSERT(SiGfxShaderBinaryCachePackage, 0x210);

}  // namespace SiSDK3

#ifdef UNK_SIGFX_SHADERBINARYCACHEPACKAGE_IMPL
// 0x71004ea0f0 (vf2), 0x71004ea110 (vf3)
#line 32
UNK_REFCOUNT_DEFINE(SiSDK3::SiGfxShaderBinaryCachePackage, field_8.m_pAllocator, field_8.m_count)
#endif
