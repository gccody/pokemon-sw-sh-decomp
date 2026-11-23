// SiSDK3::SiIOMemoryStream (RTTI names the class): a stream over a buffer of
// its own or a borrowed one. Placeholder members; the virtual functions are
// vf<slot>. The reference counts are defined in this header (their __FILE__),
// at the original's lines, for the class's own translation unit
// (UNK_SIIO_MEMORYSTREAM_IMPL).
#pragma once

#include <stdarg.h>
#include <wchar.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_4bf660.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_StringFuncs.h>

namespace SiSDK3 {

class SiIOMemoryStream {
public:
    explicit SiIOMemoryStream(ISiAllocator* pAllocator);
    virtual ~SiIOMemoryStream();
    UNK_REFCOUNT_DECLARE;
    virtual u32 vf4();
    virtual u32 vf5();
    virtual bool vf6(const char* name, u32 mode, size_t size);  // allocates the buffer
    virtual void vf7(u32, u64, u64);
    virtual void vf8(u32, u64, u64);
    virtual void vf9();  // frees the buffer
    virtual u64 vf10();
    virtual u32 vf11();
    virtual u32 vf12();
    virtual void vf13(u32);
    virtual void vf14(u32);
    virtual u32 vf15();
    virtual u32 vf16();
    virtual s64 vf17();                        // the position
    virtual bool vf18(s64 pos, bool fromEnd);  // seeks
    virtual bool vf19(s64 offset);             // skips
    virtual bool vf20();
    virtual bool vf21(void* p, s64 size, bool advance);  // reads
    virtual bool vf22(bool advance);
    virtual s32 vf23(bool advance);  // a character (the callers mask it)
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
    virtual bool vf64(const char* s, bool advance);
    virtual bool vf65(const wchar_t* s, bool advance);
    virtual bool vf66(const char* format, ...);
    virtual bool vf67(const wchar_t* format, ...);
    virtual bool vf68(const char* format, ...);
    virtual bool vf69(const wchar_t* format, ...);
    virtual void vf70();
    virtual bool vf71();
    virtual u32 vf72();
    virtual u64 vf73();
    virtual u64 vf74();
    virtual u32 vf75(u64, u64);
    virtual u64 vf76();
    virtual u64 vf77();
    virtual u64 vf78();
    virtual bool vf79(u64 length);
    virtual u32 vf80();
    virtual u32 vf81();

    // moves the end of the data up to the position (inline in every caller)
    void Unk_UpdateLength() {
        if (field_20 < static_cast<u64>(field_18)) {
            if (static_cast<u64>(field_28) >= static_cast<u64>(field_18)) {
                field_20 = field_18;
            } else if (static_cast<u64>(field_28) > field_20) {
                field_20 = field_28;
            }
        }
    }
    bool Unk_Swaps() const { return field_40 != field_44; }

    Unk_4bf660 field_8;
    s64 field_18;  // the buffer's size
    u64 field_20;  // the data's size
    s64 field_28;  // the position
    u8* field_30;  // the buffer
    u32 field_38;  // the mode vf6 was given
    bool field_3c;  // the buffer isn't the stream's own
    u32 field_40;  // the data's byte order
    u32 field_44;  // the machine's
};
PKMN_SIZE_ASSERT(SiIOMemoryStream, 0x48);
PKMN_OFFSET_ASSERT(SiIOMemoryStream, field_30, 0x30);
PKMN_OFFSET_ASSERT(SiIOMemoryStream, field_40, 0x40);

}  // namespace SiSDK3

#ifdef UNK_SIIO_MEMORYSTREAM_IMPL
// 0x7100582c10 (vf2), 0x7100582c30 (vf3)
#line 26
UNK_REFCOUNT_DEFINE(SiSDK3::SiIOMemoryStream, field_8.m_pAllocator, field_8.m_count)
#endif
