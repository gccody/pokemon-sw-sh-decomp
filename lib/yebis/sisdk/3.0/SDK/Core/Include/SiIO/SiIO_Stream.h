// SiSDK3::ISiIOStream: the stream interface, as the code that holds a stream
// calls it. RTTI names it and its place: SiIOMemoryStream is an
// ISiIOMemoryStream, SiIONXFileStream an ISiIONXFileStream and an
// ISiIOFileStream, each of those an ISiIOStream, which is an ISiInterface
// (slots 0 to 3: the destructors and the reference count). Placeholder
// members, vf<slot>; the header's name is a guess after SiIO_BinaryArchive.h.
//
// The implementations declare their slots themselves (leafgen named their
// small functions on the class, with its own guess of each signature), so
// they don't derive from this class here.
#pragma once

#include <wchar.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_String.h>

namespace SiSDK3 {

class ISiIOStream {
public:
    virtual ~ISiIOStream();
    virtual u32 vf2();  // adds a reference
    virtual u32 vf3();  // releases one
    virtual u32 vf4();
    virtual u32 vf5();
    virtual bool vf6(const char* name, u32 mode, size_t size);  // opens
    virtual bool vf7(const char* name, u32 mode, size_t size);
    virtual bool vf8(const wchar_t* name, u32 mode, size_t size);
    virtual void vf9();  // closes
    virtual s64 vf10();  // the size
    virtual bool vf11();
    virtual bool vf12();
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
    virtual s32 vf25(bool advance);
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
};

}  // namespace SiSDK3
