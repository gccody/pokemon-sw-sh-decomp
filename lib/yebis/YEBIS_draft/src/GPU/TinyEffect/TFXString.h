// The string of PPFX's TinyEffect code (C:/workspace/YEBIS_draft/src/GPU/TinyEffect/TFXString.cpp,
// the __FILE__ of its allocations and asserts). The class has no vtable, so
// nothing names it: Unk_TFXString, after its file. `Clear` and `Construct` are
// the __func__ of its asserts, `__s_null` and `_allocated` what they test; the
// other members are placeholders.
#pragma once

#include <types.h>

namespace PPFX {

class Unk_TFXString {
public:
    Unk_TFXString() : field_8(nullptr) { Clear(); }
    Unk_TFXString(const char* text) { Unk_450f30(text); }
    Unk_TFXString(const char* text, s32 length, s32 count) { Unk_451050(text, length, count); }
    Unk_TFXString(const Unk_TFXString& other) { Construct(other); }
    ~Unk_TFXString();  // 0x71004512d0

    // What the constructors call: they set every member (and return the string, by reference: a caller that returns a string doesn't tail-call them).
    Unk_TFXString& Unk_450f30(const char* text);  // 0x7100450f30
    // 0x7100451050: `length` characters, the first `count` of them from `text`
    // (all of it when `count` is negative) and spaces after
    Unk_TFXString& Unk_451050(const char* text, s32 length, s32 count);
    Unk_TFXString& Construct(const Unk_TFXString& other);  // 0x71004511e0

    Unk_TFXString& Clear();  // 0x7100450eb0
    // 0x7100451320: makes room for `length` characters, keeping the text if `keep`
    void Unk_451320(s32 length, s32 keep);
    // 0x7100451530: sets the length (pads with spaces)
    Unk_TFXString& Unk_451530(s32 length);
    // 0x7100452b30: without the spaces at the end
    Unk_TFXString& Unk_452b30();
    // 0x7100452c00: without the characters of `chars` at the start
    Unk_TFXString& Unk_452c00(const Unk_TFXString& chars);
    // 0x7100452d20: the same with the first `count` characters of a C
    // string (all of it when `count` is negative); `CutLeft` and `szDefSpace`
    // are its assert's
    Unk_TFXString& CutLeft(const char* szDefSpace, s32 count);
    // the `pos`th character (counted from 1; 0 past the end)
    char Unk_At(s32 pos) const {
        s32 length = field_0;
        return pos > length ? '\0' : field_8[pos - 1];
    }
    Unk_TFXString& operator=(const Unk_TFXString& other);       // 0x71004515c0
    Unk_TFXString& operator=(const char* text);                 // 0x71004517b0
    Unk_TFXString operator+(const Unk_TFXString& other) const;  // 0x7100451630
    Unk_TFXString& operator+=(const char* text);                // 0x7100451880
    // one more character (inline in its callers)
    Unk_TFXString& operator+=(char c) {
        Unk_451320(field_0 + 1, 1);
        s32 length = field_0;
        field_0 = length + 1;
        field_8[length] = c;
        field_8[length + 1] = '\0';
        return *this;
    }
    // 0x7100451dc0: where `c` is, from the `start`th character on (counted from 1; 0 if nowhere)
    s32 Unk_451dc0(char c, s32 start) const;
    // 0x7100451e00: keeps `count` characters from the `start`th
    Unk_TFXString& Unk_451e00(s32 start, s32 count);
    // 0x71004522d0: `count` characters from the `start`th
    Unk_TFXString Unk_4522d0(s32 start, s32 count) const;
    // 0x7100452340: the `start`th to the `end`th character (to the last when `end` is 0)
    Unk_TFXString Unk_452340(s32 start, s32 end) const;
    Unk_TFXString operator+(char c) const;  // 0x7100452740
    // 0x7100452790: strcmp, or strncmp over `count` characters
    s32 Unk_452790(const char* text, s32 count) const;
    s32 operator!=(const Unk_TFXString& other) const;      // 0x71004527b0 (an int to its caller)
    // 0x71004527e0 (an int: CTinyEffect's callers test the whole register)
    s32 operator==(const char* text) const;
    Unk_TFXString operator+(const char* text) const;       // 0x7100452820
    // 0x7100451f00: without the spaces, tabs and line feeds around it, and
    // without a pair of the characters of `quotes` around that
    Unk_TFXString& Unk_451f00(const char* quotes);
    // 0x71004520d0: where `text` (its first `count` characters, all of it
    // when `count` is negative) is, from the `start`th character on (0 if
    // nowhere)
    s32 Unk_4520d0(const char* text, s32 start, s32 count) const;
    // 0x7100452400: where `text` is, searching backwards (0 if nowhere)
    s32 Unk_452400(const char* text, s32 arg2, s32 arg3) const;

    s32 field_0;  // length
    union {
        s32 field_4;
        s32 _allocated;  // the buffer's size
    };
    char* field_8;  // the text, or __s_null
};
PKMN_SIZE_ASSERT(Unk_TFXString, 0x10);

// 0x71004525a0: a number's decimal digits
Unk_TFXString Unk_4525a0(s32 value);
// 0x71004529a0: `text` followed by `other`
Unk_TFXString Unk_4529a0(const char* text, const Unk_TFXString& other);

}  // namespace PPFX
