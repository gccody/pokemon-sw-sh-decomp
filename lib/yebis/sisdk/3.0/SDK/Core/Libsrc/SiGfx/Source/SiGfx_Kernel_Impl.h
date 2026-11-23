// SiSDK3::SiGfxKernel: SiGfx's kernel (a function-local static of
// Unk_4cbec0). As far as the executable's functions show it, with placeholder
// members (RTTI names the classes). The reference counts are defined in this
// header (their __FILE__), at the original's lines, for the file that asks with
// UNK_SIGFX_KERNEL_IMPL. The virtual functions declared and not defined here
// or in the .cpp are lib/yebis/class's or not decompiled yet (placeholder
// signatures).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_Array.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_String.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_4bf660.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_Interface.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_StringFuncs.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiGfx/SiGfx_Kernel.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiOS/Source/Unk_596410.h>

namespace SiSDK3 {

class SiGfxNXManager;
class SiGfxShaderUtility;

// A graphics device as the kernel calls it (RTTI: the pointee of
// SiArray<ISiGfxDevice*, 16>; placeholder slots).
class ISiGfxDevice {
public:
    virtual void vf0();
    virtual void vf1();
    virtual u32 vf2();
    virtual u32 vf3();
    virtual void vf4();
    virtual void vf5(ISiAllocator* pAllocator);  // 0x71004cde00: sets the allocator
    virtual void vf6();
    virtual void vf7();
    virtual ISiGfxDevice* vf8(u32 kind);  // 0x71004ce080: makes a device of a kind
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31(const char* name);  // 0x71004ce5b0: adds a name
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();  // 0x71004cf5b0: destroys the resources given to it
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual void vf59();
    virtual void vf60();
    virtual void vf61();
    virtual void vf62();
    virtual void vf63();
    virtual void vf64();
    virtual void vf65();
    virtual void vf66();
    virtual void vf67();
    virtual void vf68();
    virtual void vf69();
    virtual void vf70();
    virtual void vf71();
    virtual void vf72();
    virtual void vf73();
    virtual void vf74();
    virtual void vf75();
    virtual void vf76();
    virtual void vf77();
    virtual void vf78();  // what Unk_4ce8b0 asks of every device
    virtual void vf79();  // and Unk_4ce940
};

// What the kernel keeps after its strings (placeholder name, after its
// constructor): two directories' names and eight flags. A function of PPFX
// has one on its stack too.
struct Unk_4ecbc0 {
    // 0x71004ecbc0
    explicit Unk_4ecbc0(ISiAllocator* pAllocator);
    // 0x71004ecc80
    ~Unk_4ecbc0();
    // 0x71004ecd20: empties it for another allocator, with the default names
    void Unk_4ecd20(ISiAllocator* pAllocator);

    SiString<char> field_0;   // "ShaderPackage"
    SiString<char> field_30;  // "Font"
    bool field_60;
    bool field_61;
    bool field_62;
    bool field_63;
    bool field_64;
    bool field_65;
    bool field_66;
    bool field_67;
};
PKMN_SIZE_ASSERT(Unk_4ecbc0, 0x68);

class SiGfxKernel {
public:
    // RTTI: the element of SiArray<SiGfxKernel::DelayedDeletionEntry, 16>
    // a resource to destroy later and the frame it was given in
    struct DelayedDeletionEntry {
        ISiInterface* field_0;
        u64 field_8;
    };

    // 0x71004cbf50
    SiGfxKernel();
    virtual ~SiGfxKernel();
    UNK_REFCOUNT_DECLARE;
    virtual u32 vf4();
    virtual void vf5(ISiAllocator* pAllocator);  // 0x71004cde00: sets the allocator
    virtual u64 vf6();
    virtual u64 vf7();
    // 0x71004ce080: makes a device of a kind (the second argument is unread;
    // PPFX gives it 0)
    virtual ISiGfxDevice* vf8(u32 kind, u32 arg2);
    virtual u32 vf9();
    virtual ISiGfxDevice* vf10(s32 index);   // 0x71004ce1c0
    virtual void vf11(ISiGfxDevice* device);  // 0x71004ce210: takes one out
    virtual u64 vf12();
    virtual u64 vf13();
    virtual u64 vf14();
    virtual u64 vf15();
    virtual u64 vf16();
    virtual u64 vf17();
    virtual u64 vf18();
    virtual u64 vf19();
    virtual u64 vf20();
    virtual u64 vf21();
    virtual u64 vf22();
    virtual u64 vf23();
    virtual u64 vf24();
    virtual u64 vf25();
    // 0x71004ce3e0: takes the directories and flags, and the shader cache's
    // directory after the shader packages'
    virtual void vf26(const Unk_4ecbc0* settings);
    virtual const u8* vf27();
    virtual void vf28(const char* s);  // 0x71004ce580
    virtual const u8* vf29();
    virtual u32 vf30();
    virtual void vf31(const char* name);  // 0x71004ce5b0: adds a name
    virtual SiString<char>* vf32(s32 index);                     // 0x71004ce710
    virtual bool vf33(ISiGfxKernel::EventHandler* pHandler);      // 0x71004ce720
    virtual void vf34(ISiGfxKernel::EventHandler* pHandler);      // 0x71004ce7d0
    virtual bool vf35(u32 value);
    virtual void vf36();  // 0x71004cf5b0: destroys the resources given to it
    virtual u64 vf37();

    // 0x71004ce8b0, 0x71004ce940: what the shader utility's slots 23 and 24
    // end with (placeholder names)
    void Unk_4ce8b0();
    void Unk_4ce940();
    // 0x71004ccb30, 0x71004cc450: its initialisation and shutdown, which
    // SiGfx's (0x71004cbd40, 0x71004cbdd0) call
    bool Unk_4ccb30(ISiAllocator* pAllocator);
    void Unk_4cc450();
    // 0x71004cd1b0: makes SiGfx's string table and gives it to the core
    // kernel (what the initialisation calls)
    bool Unk_4cd1b0();
    // 0x71004cd2a0: the shader packages' directory from the working
    // directory, and the shader cache's after it (what the initialisation
    // calls)
    void Unk_4cd2a0();
    // 0x71004cd490, 0x71004cd960: registers the shader graph's classes with
    // the reflection, and takes them out (what the initialisation and the
    // shutdown call)
    void Unk_4cd490(ISiAllocator* pAllocator);
    static void Unk_4cd960();

    Unk_4bf660 field_8;
    ISiAllocator* field_18;  // the core kernel's allocator, with a reference
    // how many times it was initialised (read again after every change: a
    // volatile in the original)
    volatile u32 field_20;
    u64 field_28;
    SiGfxShaderUtility* field_30;
    // the other utilities (shader graph, texture, geometry, display, image,
    // performance)
    ISiInterface* field_38;
    ISiInterface* field_40;
    ISiInterface* field_48;
    ISiInterface* field_50;
    ISiInterface* field_58;
    ISiInterface* field_60;
    SiOSCriticalSection field_68;  // what the devices' list is locked with
    SiArray<ISiGfxDevice*> field_98;
    SiString<char> field_e8;
    SiArray<SiString<char>> field_118;
    Unk_4ecbc0 field_168;
    Unk_StringTableInterface* field_1d0;  // SiGfx's string table
    SiArray<ISiGfxKernel::EventHandler*> field_1d8;
    SiOSCriticalSection field_228;
    SiArray<DelayedDeletionEntry> field_258;
    u64 field_2a8;
    SiGfxNXManager* field_2b0;  // what makes the NX devices
};
PKMN_OFFSET_ASSERT(SiGfxKernel, field_68, 0x68);
PKMN_OFFSET_ASSERT(SiGfxKernel, field_168, 0x168);
PKMN_OFFSET_ASSERT(SiGfxKernel, field_1d8, 0x1d8);
PKMN_OFFSET_ASSERT(SiGfxKernel, field_258, 0x258);
PKMN_SIZE_ASSERT(SiGfxKernel, 0x2b8);

}  // namespace SiSDK3

#ifdef UNK_SIGFX_KERNEL_IMPL
// 0x71004cf6b0 (vf2), 0x71004cf6d0 (vf3)
#line 81
UNK_REFCOUNT_DEFINE(SiSDK3::SiGfxKernel, field_8.m_pAllocator, field_8.m_count)
#endif
