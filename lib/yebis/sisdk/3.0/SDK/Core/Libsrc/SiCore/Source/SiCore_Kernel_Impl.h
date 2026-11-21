// SiSDK3::SiKernel (RTTI; C:/workspace/sisdk/3.0/SDK/Core/Libsrc/SiCore/Source/
// SiCore_Kernel_Impl.cpp is the __FILE__ of its allocations): SiCore's kernel,
// which holds the allocator, the string tables, the report handlers and the
// reflection objects. Placeholder members. The reference counts are defined
// in this header (their __FILE__), at the original's lines, for the file that
// asks with UNK_SIKERNEL_DEFINE (SiCore_Kernel_Impl.cpp).
#pragma once

#include <stdio.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_Array.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_CriticalSection.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_Map.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_String.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_4bf660.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_Guid.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiCore/Source/SiCore_SystemInfo_Impl.h>

namespace SiSDK3 {

// a reflected class, as far as the kernel uses it: its name is the key of the
// kernel's map
class SiReflectionObject {
public:
    const char* Unk_GetName() const { return field_40; }

    u8 _0[0x40];
    const char* field_40;
};

}  // namespace SiSDK3

// 0x71004c5630: compares two strings (below zero: a is before b)
s64 Unk_4c5630(const char* a, const char* b, bool);

// eight bytes that name a language (leafgen-style placeholder: 0x71004ca820
// takes one)
struct Unk_4ca820_arg0 {
    Unk_4ca820_arg0() : field_0(0) {}

    u64 field_0;
};

namespace SiSDK3 {

// a string table, as far as the kernel uses it (its class is in
// SiCore_StringTable_Impl.cpp)
class SiStringTable {
public:
    explicit SiStringTable(ISiAllocator* pAllocator);  // 0x71004c6b70
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();  // one reference more
    virtual void vf3();  // one less
    virtual void vf4();
    virtual const SI_GUID* vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11(const Unk_4ca820_arg0& language, void* value);
    virtual void vf12();
    virtual void vf13();
    virtual SiString<char>* vf14(int id);

    // 0x71004c70f0
    void Unk_4c70f0(const SI_GUID* id);

    u8 _8[0x1148 - 8];
};

class ISiKernel {
public:
    // what a report goes to
    struct IReportUserHandler {
        virtual void vf0();
        virtual void vf1();
        virtual void vf2();  // one reference more
        virtual void vf3();  // one less
        virtual void vf4();
        virtual void vf5(int level, const char* text);
    };
};

class SiKernel {
public:
    // the order of the reflected classes' names
    struct ReflectionCompare {
        bool operator()(const char* a, const char* b) const { return Unk_4c5630(a, b, true) < 0; }
    };

    SiKernel();           // 0x71004bf7c0
    virtual ~SiKernel();  // 0x71004bfa80, 0x71004bff90
    UNK_REFCOUNT_DECLARE;
    virtual u32 vf4();
    virtual u64 vf5();
    virtual void vf6(u64 value);
    virtual u64 vf7();
    virtual bool vf8();
    virtual void vf9(bool value);
    virtual u8 vf10();
    virtual void vf11(ISiAllocator* pAllocator);  // 0x71004c0820
    virtual ISiAllocator* vf12();
    virtual SiString<char> vf13();  // 0x71004c17a0
    virtual SI_GUID vf14();         // 0x71004c1890
    virtual const u8* vf15();
    virtual u32 vf16();
    virtual u32 vf17();
    virtual u32 vf18();
    virtual SiReflectionObject* vf19(const char* name);                  // 0x71004c14f0
    virtual int vf20();                                                  // 0x71004c1590
    virtual SiReflectionObject* vf21(int index);                         // 0x71004c1760
    virtual const u8* vf22();
    virtual SiStringTable* vf23(ISiAllocator* pAllocator);               // 0x71004c1800
    virtual const Unk_4ca820_arg0* vf24();
    virtual const u8* vf25();
    virtual bool vf26(const SI_GUID* id, SiStringTable* table);          // 0x71004c18a0
    virtual bool vf27(SiStringTable* table);                             // 0x71004c19b0
    virtual void vf28();                                                 // 0x71004c1ac0
    virtual SiStringTable* vf29(const SI_GUID* id);                      // 0x71004c1b90
    virtual SiStringTable* vf30(const SI_GUID* id);                      // 0x71004c1c10
    virtual const char* vf31(const SI_GUID* id, int string);             // 0x71004c1c90
    virtual void vf32(int level, const char* text);                      // 0x71004c1ce0
    virtual bool vf33(ISiKernel::IReportUserHandler* handler);           // 0x71004c1da0
    virtual void vf34(ISiKernel::IReportUserHandler* handler);           // 0x71004c1e70
    virtual void vf35();                                                 // 0x71004c1f80
    virtual int vf36();                                                  // 0x71004c2050
    virtual const u8* vf37();
    virtual int vf38();                                                  // 0x71004c2090
    virtual const u8* vf39();
    virtual bool vf40(int count);                                        // 0x71004c20d0
    virtual u32 vf41();
    virtual bool vf42(int index, ISiAllocator* pAllocator);              // 0x71004c2210
    virtual ISiAllocator* vf43(int index);                               // 0x71004c22c0
    virtual ISiAllocator* vf44(int index);                               // 0x71004c22f0

    // the allocator of the reflected classes' map and array (inline:
    // placeholder name)
    void Unk_SetMapAllocator(ISiAllocator* pAllocator) {
        field_f70.m_pAllocator = pAllocator;
        field_f98.Unk_SetAllocator(pAllocator);
    }

    // the string tables' array with another allocator, empty in the kernel's
    // buffer again (inline: placeholder name; an inline function of its own,
    // by the set-up's code: the buffer's free is gone where the allocator
    // changed, and the buffer's address is computed on both ways)
    void Unk_SetTablesAllocator(ISiAllocator* pAllocator) {
        field_678.Unk_SetAllocator(pAllocator);
        field_678.Unk_SetBuffer(field_6c8, 0x100);
    }

    bool Unk_4bffc0(ISiAllocator* pAllocator);  // sets the kernel up, the first time
    bool Unk_4c0390(ISiAllocator* pAllocator);
    void Unk_4c04e0();  // takes the kernel down, the last time
    void Unk_4c06f0();
    void Unk_4c0910(SiReflectionObject* object);
    void Unk_4c0d60(SiReflectionObject* object);

    Unk_4bf660 field_8;
    // how many times the kernel was set up (read again after every write:
    // volatile)
    volatile u32 field_18;
    SiCoreCriticalSection field_20;
    void* field_48;
    char field_50[0x400];
    SiString<char> field_450;
    u32 field_480;
    bool field_484;
    bool field_485;
    bool field_486;
    bool field_487;
    ISiAllocator* field_488;  // the allocator
    SiSystemInfo field_490;
    u64 field_668;
    u64 field_670;
    SiArray<SiStringTable*, 16> field_678;  // in field_6c8
    SiStringTable* field_6c8[0x100];
    SiStringTable* field_ec8;  // the kernel's own string table
    SiArray<ISiKernel::IReportUserHandler*, 16> field_ed0;
    SiArray<ISiAllocator*, 16> field_f20;  // the allocators of an index
    SiMap<const char*, SiReflectionObject*, ReflectionCompare, 16> field_f70;
    u64 field_f90;  // (the map's, by its size here: its compare object?)
    SiArray<SiReflectionObject*, 16> field_f98;
    SiString<char> field_fe8;
    SiString<char> field_1018;
    FILE* field_1048;
    FILE* field_1050;  // where reports are written
};
PKMN_SIZE_ASSERT(SiStringTable, 0x1148);
PKMN_OFFSET_ASSERT(SiKernel, field_450, 0x450);
PKMN_OFFSET_ASSERT(SiKernel, field_490, 0x490);
PKMN_OFFSET_ASSERT(SiKernel, field_678, 0x678);
PKMN_OFFSET_ASSERT(SiKernel, field_ed0, 0xed0);
PKMN_OFFSET_ASSERT(SiKernel, field_f70, 0xf70);
PKMN_OFFSET_ASSERT(SiKernel, field_f98, 0xf98);
PKMN_SIZE_ASSERT(SiKernel, 0x1058);

}  // namespace SiSDK3

#ifdef UNK_SIKERNEL_DEFINE
// 0x71004c2320 (vf2), 0x71004c2340 (vf3)
#line 36
UNK_REFCOUNT_DEFINE(SiSDK3::SiKernel, field_8.m_pAllocator, field_8.m_count)
#endif
