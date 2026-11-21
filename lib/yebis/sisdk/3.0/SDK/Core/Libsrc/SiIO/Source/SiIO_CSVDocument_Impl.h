// SiSDK3::SiIOCSVDocument (RTTI names the class): a table of strings read
// from and written as comma-separated text. Placeholder members; the virtual
// functions are vf<slot>. The reference counts are defined in this header
// (their __FILE__), at the original's lines, for the class's own translation
// unit (UNK_SIIO_CSVDOCUMENT_IMPL).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_Array.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_String.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_4bf660.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>

namespace SiSDK3 {

class ISiIOStream;

class SiIOCSVDocument {
public:
    explicit SiIOCSVDocument(ISiAllocator* pAllocator);
    virtual ~SiIOCSVDocument();
    UNK_REFCOUNT_DECLARE;
    virtual u32 vf4();
    virtual bool vf5(const char* path);     // reads a file
    virtual bool vf6(ISiIOStream* stream);  // reads a stream
    virtual bool vf7(const char* path);     // writes a file
    virtual bool vf8(ISiIOStream* stream);  // writes a stream
    virtual u32 vf9();                      // the number of rows
    virtual u32 vf10(s32 row);              // a row's number of cells
    virtual SiString<char>* vf11(s32 column, s32 row);  // a cell
    virtual s32 vf12(s32 column, s32 row);              // a cell as numbers
    virtual f32 vf13(s32 column, s32 row);
    virtual f64 vf14(s32 column, s32 row);
    virtual bool vf15(s32 count);                               // sets the number of rows
    virtual bool vf16(s32 row, s32 count);                      // sets a row's number of cells
    virtual bool vf17(s32 column, s32 row, const char* value);  // sets a cell
    virtual bool vf18(s32 column, s32 row, s32 value);
    virtual bool vf19(s32 column, s32 row, f32 value);
    virtual bool vf20(s32 column, s32 row, f64 value);
    virtual void vf21(bool value);
    virtual u8 vf22();

    // 0x710057eb50: reads a line of the stream into line
    void Unk_57eb50(ISiIOStream* stream, SiString<char>* line);
    // 0x710057edd0: adds a line's cells as a row
    bool Unk_57edd0(SiString<char>* line);

    Unk_4bf660 field_8;
    bool field_18;  // the text is UTF-8 (otherwise wide characters)
    SiArray<SiArray<SiString<char> > > field_20;  // the rows
    SiArray<u8> field_70;                          // a line as it is in the stream
    SiArray<wchar_t> field_c0;
    SiArray<char> field_110;
};
PKMN_SIZE_ASSERT(SiIOCSVDocument, 0x160);

}  // namespace SiSDK3

#ifdef UNK_SIIO_CSVDOCUMENT_IMPL
// 0x710057feb0 (vf2), 0x710057fed0 (vf3)
#line 34
UNK_REFCOUNT_DEFINE(SiSDK3::SiIOCSVDocument, field_8.m_pAllocator, field_8.m_count)
#endif
