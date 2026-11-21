// SiSDK3::SiIONXFileStream (RTTI names the class): a stream over a C file
// with a buffer of its own, or over the stream a file of a mounted archive
// (SiIOVFS) gives. Placeholder members; the virtual functions are vf<slot>.
// The reference counts are defined in this header (their __FILE__), at the
// original's lines.
#pragma once

#include <stdarg.h>
#include <stdio.h>
#include <wchar.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_4bf660.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_Endian.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_StringFuncs.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiIO/SiIO_Stream.h>

namespace SiSDK3 {

// A file of a mounted archive (SiIOVFSEntry's interface): slot 19 opens its
// stream.
class Unk_VFSEntryInterface {
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
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual ISiIOStream* vf19();
};

class SiIONXFileStream {
public:
    explicit SiIONXFileStream(ISiAllocator* pAllocator);
    virtual ~SiIONXFileStream();
    UNK_REFCOUNT_DECLARE;
    virtual u32 vf4();
    virtual u32 vf5();
    virtual bool vf6(const char* path, u32 mode, size_t size);  // opens
    virtual void vf7(u64, u64, u64);
    virtual bool vf8(const wchar_t* path, u32 mode, size_t size);
    virtual void vf9();  // closes
    virtual s64 vf10();  // the size
    virtual bool vf11();
    virtual bool vf12();  // open for writing
    virtual void vf13(u32);
    virtual void vf14(u32);
    virtual u32 vf15();
    virtual u32 vf16();
    virtual s64 vf17();                        // the position
    virtual bool vf18(s64 pos, bool fromEnd);  // seeks
    virtual bool vf19(s64 offset);             // skips
    virtual bool vf20();                       // at the end
    virtual bool vf21(void* p, s64 size, bool advance);  // reads
    virtual bool vf22(bool advance);
    virtual char vf23(bool advance);
    virtual wchar_t vf24(bool advance);
    virtual void vf25(bool);
    virtual s16 vf26(bool advance);
    virtual s32 vf27(bool advance);
    virtual s64 vf28(bool advance);
    virtual u8 vf29(bool advance);
    virtual u16 vf30(bool advance);
    virtual u32 vf31(bool advance);
    virtual u64 vf32(bool advance);
    virtual float vf33(bool advance);
    virtual double vf34(bool advance);
    virtual bool vf35(SiString<char>* str, bool advance);
    virtual bool vf36(SiString<wchar_t>* str, bool advance);
    virtual bool vf37(SiString<char>* str, bool advance);
    virtual bool vf38(SiString<wchar_t>* str, bool advance);
    virtual bool vf39(SiString<char>* str, bool advance);
    virtual bool vf40(SiString<wchar_t>* str, bool advance);
    virtual bool vf41(SiString<char>* str, bool advance);
    virtual bool vf42(SiString<wchar_t>* str, bool advance);
    virtual s32 vf43(char* p, s32 size, bool advance);         // reads a line
    virtual bool vf44(const void* p, s64 size, bool advance);  // writes
    virtual bool vf45(bool value, bool advance);
    virtual bool vf46(char value, bool advance);
    virtual bool vf47(wchar_t value, bool advance);
    virtual void vf48(u64, bool);
    virtual bool vf49(s16 value, bool advance);
    virtual bool vf50(s32 value, bool advance);
    virtual bool vf51(s64 value, bool advance);
    virtual bool vf52(u8 value, bool advance);
    virtual bool vf53(u16 value, bool advance);
    virtual bool vf54(u32 value, bool advance);
    virtual bool vf55(u64 value, bool advance);
    virtual bool vf56(float value, bool advance);
    virtual bool vf57(double value, bool advance);
    virtual bool vf58(const char* s, bool advance);
    virtual bool vf59(const wchar_t* s, bool advance);
    virtual bool vf60(const char* s, bool advance);
    virtual bool vf61(const wchar_t* s, bool advance);
    virtual bool vf62(const char* s, bool advance);
    virtual bool vf63(const wchar_t* s, bool advance);
    virtual bool vf64(const wchar_t* s, bool advance);
    virtual bool vf65(const wchar_t* s, bool advance);
    virtual bool vf66(const char* format, ...);
    virtual bool vf67(const wchar_t* format, ...);
    virtual bool vf68(const char* format, ...);
    virtual bool vf69(const wchar_t* format, ...);
    virtual void vf70();  // flushes
    virtual bool vf71();
    virtual bool vf72();  // reads a byte of every page ahead
    virtual u64 vf73();
    virtual u64 vf74();
    virtual u64 vf75();
    virtual u64 vf76();
    virtual const u8* vf77();
    virtual const u8* vf78();
    virtual u8* vf79();
    virtual u32 vf80();
    virtual u32 vf81();

    // 0x7100588cc0: reads through the buffer; the number of bytes read
    s64 Unk_588cc0(void* p, s64 size, bool advance);
    // 0x710058a520: writes through the buffer; the number of bytes written
    s64 Unk_58a520(const void* p, s64 size, bool advance);

    bool Unk_Swaps() const { return field_24 != field_28; }
    // the file's size, by seeking to its end and back
    s64 Unk_FileSize() {
        s64 pos = ftell(field_18);
        fseek(field_18, 0, SEEK_END);
        s64 size = ftell(field_18);
        fseek(field_18, pos, SEEK_SET);
        return size;
    }
    // writes the buffer out, if the file is open for writing
    void Unk_Flush() {
        if (vf12() && field_10108 > 0) {
            if (static_cast<s32>(fwrite(field_10110, field_10108, 1, field_18)) == 1) {
                field_10118 = 0;
                field_10108 = 0;
            }
        }
    }

    Unk_4bf660 field_8;
    FILE* field_18;
    u32 field_20;  // the mode vf6 was given
    u32 field_24;  // the data's byte order
    u32 field_28;  // the machine's
    SiString<char> field_30;  // the path
    SiString<char> field_60;
    Unk_VFSEntryInterface* field_90;  // the archive's file, if the path is in one
    ISiIOStream* field_98;            // and its stream
    s64 field_a0;                     // where the data starts in the file
    s64 field_a8;                     // the size
    s64 field_b0;                     // the position
    bool field_b8;
    bool field_b9;
    u8 field_ba[0x10040];  // the buffer's storage (0x10000 bytes at the first 32-byte boundary)
    s64 field_10100;       // the buffer's size
    s64 field_10108;       // how much of it is filled
    u8* field_10110;       // the buffer
    s64 field_10118;       // the position in it
    u8* field_10120;       // the buffer when allocated (a whole file's)
};
PKMN_SIZE_ASSERT(SiIONXFileStream, 0x10128);
PKMN_OFFSET_ASSERT(SiIONXFileStream, field_90, 0x90);
PKMN_OFFSET_ASSERT(SiIONXFileStream, field_10100, 0x10100);

}  // namespace SiSDK3

// 0x710058b780 (vf2), 0x710058b7a0 (vf3)
#line 37
UNK_REFCOUNT_DEFINE(SiSDK3::SiIONXFileStream, field_8.m_pAllocator, field_8.m_count)
