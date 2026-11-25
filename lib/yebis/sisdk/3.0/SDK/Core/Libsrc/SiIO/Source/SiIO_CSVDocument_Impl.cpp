// Scope: common
// SiSDK3::SiIOCSVDocument.
#define UNK_SIIO_CSVDOCUMENT_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiIO/Source/SiIO_CSVDocument_Impl.h>

#include <string.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_StringFuncs.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiIO/SiIO_Stream.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiIO/Source/SiIO_Kernel_Impl.h>

// 0x710057d030: SiIO's kernel as a number (leafgen's name and type)
u64 Unk_57d030_get();
// 0x7100583340: skips a byte order mark
bool Unk_583340(SiSDK3::ISiIOStream* stream);
// 0x71004c58e0, 0x71004c58f0, 0x71004c5920: a string as numbers (null: 0)
long Unk_4c58e0(const char* s);
f32 Unk_4c58f0(const char* s);
f64 Unk_4c5920(const char* s);
// 0x71004c5a40: a number as a string in a base, 0x71004c5a90: a formatted
// string
bool Unk_4c5a40(char* dst, size_t size, s64 value, s32 base);
void Unk_4c5a90(char* dst, size_t size, const char* format, ...);

// 0x71004c4d70 (leafgen's name and types): a line's bytes as UTF-8 (here as
// they are), 0x71004c5280: a line's bytes into a string (placeholder name)
const char* Unk_4c4d70_update(u64 src, u64 dst, u64 size);
// 0x71004c4d80 (leafgen's name and types): UTF-8 as a line's bytes (here as
// they are), 0x71004c51e0: Latin-1 to UTF-8
const char* Unk_4c4d80_update(u64 src, u64 dst, u64 size);
char* Unk_4c51e0(const char* s, char* dst, s64 size);
void Unk_4c5280(const u8* src, SiSDK3::SiString<char>* dst, s64 size);
// 0x71024e9360: the empty string a string without a buffer reads as
extern char Unk_24e9360[];

// 0x710057e080
void* Unk_57e080(SiSDK3::ISiAllocator* pAllocator) {
#line 34
    return UNK_SI_NEW(pAllocator, 0x10) SiSDK3::SiIOCSVDocument(pAllocator);
}

namespace SiSDK3 {

namespace {

inline const char* Unk_CStr(const SiString<char>* s) {
    return s->m_pBuffer != nullptr ? s->m_pBuffer : Unk_24e9360;
}

// a string's length (null: 0; inline: placeholder name)
inline s64 Unk_StrLen(const char* s) {
    if (s == nullptr) {
        return 0;
    }
    s64 n = 0;
    while (s[n] != 0) {
        n++;
    }
    return n;
}

// copies count characters of s (all of them for a negative count) and
// terminates them, unless there are none (inline: placeholder name)
inline void Unk_StrNCopy(char* dst, const char* src, s64 count) {
    if (count < 0) {
        count = Unk_StrLen(src);
    }
    if (dst == nullptr || count <= 0) {
        return;
    }
    for (s64 i = 0; i < count; i++) {
        dst[i] = src[i];
    }
    dst[count] = 0;
}

// count characters of a string from start (the rest of it for 0) as
// another (inline: placeholder name)
inline void Unk_StringMid(const SiString<char>* self, SiString<char>* result, s64 start, s64 count) {
    if (self->field_10 == 0) {
        if (result->m_pBuffer != nullptr) {
            result->m_pBuffer[0] = 0;
        }
        result->field_10 = 0;
    } else if (static_cast<size_t>(start) < self->field_10) {
        if (count == 0) {
            count = self->field_10 - start;
        }
        if (result->field_20 <= static_cast<size_t>(count)) {
            size_t step = result->field_18;
            size_t length = count + 1;
            size_t capacity;
            if (step != 0) {
                capacity = step + length;
            } else {
                capacity = length > result->field_20 * 2 ? length : result->field_20 * 2;
            }
            Unk_StringSetCapacity(result, capacity, false);
        }
        Unk_StrNCopy(result->m_pBuffer, self->m_pBuffer + start, count);
        result->field_10 = count;
    }
}

// where s is in a string from start, or -1 (inline: placeholder name)
inline s64 Unk_StringFind(const SiString<char>* self, const char* s, s64 start) {
    if (self->field_10 == 0) {
        return -1;
    }
    size_t n = 0;
    while (s[n] != 0) {
        n++;
    }
    if (n == 0 || static_cast<size_t>(start) >= self->field_10) {
        return -1;
    }
    const char* p = self->m_pBuffer + start;
    for (size_t i = 0; start + i < self->field_10; i++) {
        if (p[i] == s[0]) {
            return start + i;
        }
    }
    return -1;
}

// where c is in a string from start, or -1 (inline: placeholder name)
inline s64 Unk_StringFind(const SiString<char>* self, char c, s64 start) {
    char s[2] = {};
    s[0] = c;
    return Unk_StringFind(self, s, start);
}

}  // namespace

// 0x710057e0d0
// NON_MATCHING: four bytes longer. The three reserves are inlined like the original's, but this
// keeps the addresses of the arrays' counts in two more callee-saved registers (a 0x50-byte frame
// instead of 0x40). Tried: the reserves as Unk_ReserveAtLeast, Unk_SetReserved,
// Unk_Reserve or the reserve itself, with and without the room's test.
SiIOCSVDocument::SiIOCSVDocument(ISiAllocator* pAllocator)
    : field_8(pAllocator), field_18(false), field_20(pAllocator), field_70(pAllocator), field_c0(pAllocator),
      field_110(pAllocator) {
    if (field_70.m_reservedCount < 0x1000) {
        field_70.Unk_Reserve(0x1000);
    }
    if (field_c0.m_reservedCount < 0x400) {
        field_c0.Unk_Reserve(0x400);
    }
    if (field_110.m_reservedCount < 0x400) {
        field_110.Unk_Reserve(0x400);
    }
}

// 0x710057e5f0 (D2), 0x710057e9b0 (D0)
SiIOCSVDocument::~SiIOCSVDocument() {}

// 0x710057e9e0
bool SiIOCSVDocument::vf5(const char* path) {
    ISiIOStream* stream = reinterpret_cast<SiIOKernel*>(Unk_57d030_get())->vf9(path, 0x28, nullptr);
    if (stream == nullptr) {
        return false;
    }
    bool result = vf6(stream);
    stream->vf3();
    return result;
}

// 0x710057ea50
bool SiIOCSVDocument::vf6(ISiIOStream* stream) {
    if (stream == nullptr) {
        return false;
    }
    if (!stream->vf11()) {
        return false;
    }
    Unk_583340(stream);
    SiString<char> line(field_8.m_pAllocator);
    while (!stream->vf20()) {
        Unk_57eb50(stream, &line);
        if (!Unk_57edd0(&line)) {
            return false;
        }
    }
    return true;
}

// 0x710057eb50
// (The first character is read before the loop and the next one at its end,
// which gives the original's two copies of the test of '\r'. The last string
// assignment is a call, not a tail call, because the assignment returns a
// reference: see Unk_StringFuncs.h.)
void SiIOCSVDocument::Unk_57eb50(ISiIOStream* stream, SiString<char>* line) {
    Unk_StringAssign(line, "");
    field_70.Unk_Clear();
    if (stream->vf20()) {
        return;
    }
    u8 c = stream->vf29(true);
    for (;;) {
        if (c != '\r') {
            if (c == '\n' || c == 0xff) {
                break;
            }
            field_70.Unk_Add(c);
        }
        if (stream->vf20()) {
            break;
        }
        c = stream->vf29(true);
    }
    field_70.Unk_Add(0);
    Unk_StringReserve(line, field_70.m_itemCount);
    if (field_18) {
        field_110.Unk_SetCount(field_70.m_itemCount);
        Unk_StringAssign(line, Unk_4c4d70_update(reinterpret_cast<u64>(field_70.m_pData),
                                                 reinterpret_cast<u64>(field_110.m_pData), field_110.m_reservedCount));
    } else {
        Unk_4c5280(field_70.m_pData, line, static_cast<s32>(field_c0.m_reservedCount));
    }
}

// 0x710057edd0
// NON_MATCHING: 24 bytes long. The separator's buffer and the loop that
// measures it are the original's now: the buffer is zeroed, then given its
// character (`char s[2] = {}; s[0] = c;` in the inline: GVN then doesn't
// forward the terminator into the loop; with `{c, 0}` it does and the loop is
// deleted), and the length is a size_t (no nsw).
// What's left is the code before the loop: the original keeps the separator
// in w27 and stores it once after the allocator's selection, then reloads the
// line's length for the first search on both paths; here the join is
// duplicated into both paths and only the allocator's path reloads it.
// The cells' substrings, the arrays' growth and the destructors are the
// original's. (Each cell is constructed in its branch: with the substring
// returned by value, an inline that also constructs the string, the inliner
// finds it 5 to 15 over its threshold at both calls.)
bool SiIOCSVDocument::Unk_57edd0(SiString<char>* line) {
    if (line->field_10 == 0) {
        return false;
    }
    SiArray<SiString<char> > cells(field_8.m_pAllocator);
    s64 pos = 0;
    s64 index;
    while ((index = Unk_StringFind(line, ',', pos)) >= 0) {
        if (index > pos) {
            SiString<char> cell(field_8.m_pAllocator);
            Unk_StringMid(line, &cell, pos, index - pos);
            cells.Unk_Add(cell);
        } else {
            SiString<char> cell;
            cells.Unk_Add(cell);
        }
        pos = index + 1;
    }
    if (static_cast<size_t>(pos) < line->field_10) {
        SiString<char> cell(field_8.m_pAllocator);
        Unk_StringMid(line, &cell, pos, 0);
        cells.Unk_Add(cell);
    } else {
        SiString<char> cell;
        cells.Unk_Add(cell);
    }
    field_20.Unk_Add(cells);
    return true;
}

// 0x710057f560
bool SiIOCSVDocument::vf7(const char* path) {
    ISiIOStream* stream = reinterpret_cast<SiIOKernel*>(Unk_57d030_get())->vf9(path, 0x14, nullptr);
    if (stream == nullptr) {
        return false;
    }
    vf8(stream);
    stream->vf3();
    return true;
}

// 0x710057f5d0
bool SiIOCSVDocument::vf8(ISiIOStream* stream) {
    SiString<char> line(field_8.m_pAllocator);
    for (s64 row = 0; row < static_cast<s32>(field_20.m_itemCount); row++) {
        SiArray<SiString<char> >* cells = &field_20.m_pData[row];
        Unk_StringAssign(&line, "");
        for (s64 column = 0; column < static_cast<s32>(cells->m_itemCount); column++) {
            Unk_StringAppendString(&line, &cells->m_pData[column]);
            if (column < static_cast<s32>(cells->m_itemCount) - 1) {
                Unk_StringAppend(&line, ',');
            }
        }
        Unk_StringAppend(&line, '\n');
        const char* p;
        if (field_18) {
            field_70.Unk_SetCount(line.field_10);
            p = Unk_4c4d80_update(reinterpret_cast<u64>(line.m_pBuffer), reinterpret_cast<u64>(field_70.m_pData),
                                  field_70.m_reservedCount);
        } else {
            field_70.Unk_SetCount(line.field_10 * 4);
            Unk_4c51e0(line.m_pBuffer, reinterpret_cast<char*>(field_70.m_pData), field_70.m_reservedCount);
            p = reinterpret_cast<const char*>(field_70.m_pData);
        }
        for (; *p != 0; p++) {
            stream->vf52(*p, true);
        }
    }
    return true;
}

// 0x710057f9a0
u32 SiIOCSVDocument::vf10(s32 row) {
    return field_20.m_pData[row].m_itemCount;
}

// 0x710057f9c0
SiString<char>* SiIOCSVDocument::vf11(s32 column, s32 row) {
    return &field_20.m_pData[row].m_pData[column];
}

// 0x710057f9e0
s32 SiIOCSVDocument::vf12(s32 column, s32 row) {
    return Unk_4c58e0(Unk_CStr(&field_20.m_pData[row].m_pData[column]));
}

// 0x710057fa20
f32 SiIOCSVDocument::vf13(s32 column, s32 row) {
    return Unk_4c58f0(Unk_CStr(&field_20.m_pData[row].m_pData[column]));
}

// 0x710057fa50
f64 SiIOCSVDocument::vf14(s32 column, s32 row) {
    return Unk_4c5920(Unk_CStr(&field_20.m_pData[row].m_pData[column]));
}

// 0x710057fa80
// (the result tested and returned as constants: returned as it is, the count's test shares
// the return with the other paths, as vf16's does in the original too)
bool SiIOCSVDocument::vf15(s32 count) {
    if (!field_20.Unk_SetCount(count)) {
        return false;
    }
    return true;
}

// 0x710057fb30
bool SiIOCSVDocument::vf16(s32 row, s32 count) {
    return field_20.m_pData[row].Unk_SetCount(count);
}

// 0x710057fbf0
// (The row and the cell through SiArray's operator[]: the row's address is
// then one value from the test of its cell count to the call that grows it,
// kept in x0, where `&m_pData[row]` gives two addresses that InstCombine
// merges with the members' offsets separately.)
bool SiIOCSVDocument::vf17(s32 column, s32 row, const char* value) {
    if (static_cast<s32>(field_20.m_itemCount) <= row) {
        if (!field_20.Unk_SetCount(row + 1)) {
            return false;
        }
    }
    SiArray<SiString<char> >& cells = field_20[row];
    if (static_cast<s32>(cells.m_itemCount) <= column) {
        if (!cells.Unk_SetCount(column + 1)) {
            return false;
        }
    }
    Unk_StringAssign(&field_20[row][column], value);
    return true;
}

// 0x710057fd60
bool SiIOCSVDocument::vf18(s32 column, s32 row, s32 value) {
    char text[0x100];
    Unk_4c5a40(text, sizeof(text), value, 10);
    return vf17(column, row, text);
}

// 0x710057fdd0
bool SiIOCSVDocument::vf19(s32 column, s32 row, f32 value) {
    char text[0x100];
    Unk_4c5a90(text, sizeof(text), "%f", value);
    return vf17(column, row, text);
}

// 0x710057fe40
bool SiIOCSVDocument::vf20(s32 column, s32 row, f64 value) {
    char text[0x100];
    Unk_4c5a90(text, sizeof(text), "%e", value);
    return vf17(column, row, text);
}

}  // namespace SiSDK3

// The array functions this translation unit instantiates out of line.
// 0x7100580100 = _ZN6SiSDK37SiArrayIcLi16EE10Unk_4bf190Emb
template bool SiSDK3::SiArray<char, 16>::Unk_4bf190(size_t, bool);
// 0x7100580290 = _ZN6SiSDK37SiArrayINS0_INS_8SiStringIcEELi16EEELi16EE10Unk_4bf190Emb
template bool SiSDK3::SiArray<SiSDK3::SiArray<SiSDK3::SiString<char>, 16>, 16>::Unk_4bf190(size_t, bool);
