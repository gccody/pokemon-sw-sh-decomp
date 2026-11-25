// Scope: common
// PPFX's TinyEffect string (lib/yebis/YEBIS_draft/src/GPU/TinyEffect/TFXString.h).
// YEBIS was built with its asserts: their __FILE__, __LINE__ and __func__ are
// in the executable, so the functions with one keep the original's lines.
#undef NDEBUG
#include <assert.h>
#include <ctype.h>
#include <string.h>

#include <miniz/miniz_yebis.h>
#include <yebis/YEBIS_draft/src/GPU/Unk_StaticsBase.h>
#include <yebis/YEBIS_draft/src/GPU/TinyEffect/TFXString.h>

// the empty string every empty Unk_TFXString points at
extern char __s_null[];

// YEBIS's array allocation: the element count goes before the elements
#define UNK_NEW_CHARS(count) Unk_NewChars(count, __FILE__, __LINE__)
#define UNK_DELETE_CHARS(text) Unk_4b9a60(Unk_238d5f8, reinterpret_cast<u64*>(text) - 1)

static inline char* Unk_NewChars(s32 count, const char* file, int line) {
    u64* block = static_cast<u64*>(Unk_4b99a0(Unk_238d5f8, count + sizeof(u64), file, line, nullptr));
    if (block != nullptr)
        *block++ = count;
    return reinterpret_cast<char*>(block);
}

// the buffer size for a text of that length
static inline s32 Unk_Capacity(s32 length) {
    if (length < 0x20)
        return 0x40;
    if (length < 0x40)
        return 0x80;
    if (length >= 0x200000)
        return (length + 0x400001) & ~0xf;
    return (length * 2 + 0x11) & ~0xf;
}

namespace PPFX {

// 0x7100450eb0
#line 42
Unk_TFXString& Unk_TFXString::Clear() {
    assert(__s_null[0] == '\0');
    if (field_8 != nullptr && field_8 != __s_null)
        UNK_DELETE_CHARS(field_8);
    field_0 = 0;
    field_4 = 0;
    field_8 = __s_null;
    return *this;
}

// 0x7100450f30
Unk_TFXString& Unk_TFXString::Unk_450f30(const char* text) {
    field_0 = text != nullptr ? strlen(text) : 0;
    if (field_0 != 0) {
        field_4 = Unk_Capacity(field_0);
#line 102
        field_8 = UNK_NEW_CHARS(field_4);
        memcpy(field_8, text, field_0);
        if (field_4 != 0)
            field_8[field_0] = '\0';
    } else {
        field_8 = nullptr;
        Clear();
    }
    return *this;
}

// 0x7100451050
Unk_TFXString& Unk_TFXString::Unk_451050(const char* text, s32 length, s32 count) {
    if (text != nullptr) {
        if (count < 0)
            count = strlen(text);
        field_0 = length;
        field_4 = Unk_Capacity(length);
#line 125
        field_8 = UNK_NEW_CHARS(field_4);
        if (count < field_0) {
            memcpy(field_8, text, count);
            memset(field_8 + count, ' ', field_0 - count);
        } else {
            memcpy(field_8, text, field_0);
        }
        if (field_4 != 0)
            field_8[field_0] = '\0';
    } else {
        Clear();
    }
    return *this;
}

// 0x71004511e0
#line 155
Unk_TFXString& Unk_TFXString::Construct(const Unk_TFXString& other) {
    if (other.field_0 != 0) {
        field_0 = other.field_0;
        field_4 = other.field_4;
        field_8 = UNK_NEW_CHARS(field_4);
        memcpy(field_8, other.field_8, field_0);
        assert(_allocated);
        field_8[field_0] = '\0';
    } else {
        field_8 = nullptr;
        Clear();
    }
    return *this;
}

// 0x71004512d0
Unk_TFXString::~Unk_TFXString() {
    if (field_8 != __s_null && field_8 != nullptr) {
        UNK_DELETE_CHARS(field_8);
        field_8 = nullptr;
    }
}

// 0x7100451320
void Unk_TFXString::Unk_451320(s32 length, s32 keep) {
    if (field_0 == length)
        return;
    s32 allocated = field_4;
    s32 capacity = Unk_Capacity(length);
    if (allocated > length) {
        if (allocated > capacity * 4) {
            field_4 = capacity;
#line 305
            char* text = UNK_NEW_CHARS(capacity);
            if (keep) {
                if (field_4 > length) {
                    memcpy(text, field_8, length);
                    text[length] = '\0';
                } else {
                    memcpy(text, field_8, field_4 - 1);
                    text[field_4 - 1] = '\0';
                }
            }
            if (field_8 != __s_null && field_8 != nullptr)
                UNK_DELETE_CHARS(field_8);
            field_8 = text;
        }
    } else {
        field_4 = capacity;
#line 271
        char* text = UNK_NEW_CHARS(capacity);
        if (keep) {
            if (field_0 > length) {
                memcpy(text, field_8, length);
                text[length] = '\0';
            } else {
                memcpy(text, field_8, field_0 + 1);
            }
        }
        if (field_8 != __s_null && field_8 != nullptr)
            UNK_DELETE_CHARS(field_8);
        field_8 = text;
    }
}

// 0x7100451530
Unk_TFXString& Unk_TFXString::Unk_451530(s32 length) {
    s32 old = field_0;
    if (old != length) {
        Unk_451320(length, 1);
        if (old > length) {
            field_0 = length;
            if (field_4 != 0)
                field_8[length] = '\0';
        } else {
            memset(field_8 + field_0, ' ', length - field_0);
            field_0 = length;
        }
    }
    return *this;
}

// 0x71004515c0
Unk_TFXString& Unk_TFXString::operator=(const Unk_TFXString& other) {
    if (this != &other) {
        Unk_451320(other.field_0, 0);
        field_0 = other.field_0;
        memcpy(field_8, other.field_8, other.field_0);
        if (field_4 != 0)
            field_8[field_0] = '\0';
    }
    return *this;
}

// 0x7100451630
Unk_TFXString Unk_TFXString::operator+(const Unk_TFXString& other) const {
    if (field_0 == 0)
        return other;
    if (other.field_0 == 0)
        return *this;
    Unk_TFXString sum(field_8, field_0 + other.field_0, -1);
    memcpy(sum.field_8 + field_0, other.field_8, other.field_0);
    return sum;
}

// 0x71004517b0
Unk_TFXString& Unk_TFXString::operator=(const char* text) {
    s32 length;
    if (text != nullptr && (length = strlen(text)) != 0) {
        Unk_451320(length, 0);
        field_0 = length;
        memcpy(field_8, text, length + 1);
    } else {
        Clear();
    }
    return *this;
}

// 0x7100451880
Unk_TFXString& Unk_TFXString::operator+=(const char* text) {
    s32 length;
    if (text != nullptr && (length = strlen(text)) != 0) {
        Unk_451320(field_0 + length, 1);
        memcpy(field_8 + field_0, text, length + 1);
        field_0 += length;
    }
    return *this;
}

// where the line after `start` begins (the end if there's none)
static inline s32 Unk_NextLine(const Unk_TFXString* string, s32 start) {
    s32 i = string->Unk_451dc0('\n', start);
    return i == 0 ? string->field_0 : i + 1;
}

// 0x7100451900
// NON_MATCHING: the loop over `quotes` keeps a `quoted |= match` (cset, orr)
// in the original and its not-found exit doesn't clear the flag; every form
// tried here (break, `&& !quoted`, a helper) gets it folded. The comment's
// buffer is also 4 bytes higher in the frame.
// (Round 5: the quote loop as `quoted |= match` with and without the loop's
// `!quoted`, `quoted = match` with a break, a `while`, the match tested on
// the quote's character: the same or worse.)
Unk_TFXString Token(Unk_TFXString* string, const char* delimiters, const char* comment, const char* quotes, s32 delimLen,
                    s32 commentLength, s32 quoteLength) {
#line 756
    assert(delimiters);
    if (delimLen < 0)
        delimLen = strlen(delimiters);
    if (comment != nullptr && commentLength < 0)
        commentLength = strlen(comment);
    s32 commentLen = comment != nullptr ? commentLength : 0;
#line 767
    assert(commentLen < 256);
    char text[256];
    text[commentLen] = '\0';
    s32 length = string->field_0;
    s32 pos;
    for (pos = 1; pos <= length; pos++) {
        if (commentLen != 0) {
            memcpy(text, string->field_8 + pos - 1, commentLen);
            text[commentLen] = '\0';
        }
        if (comment != nullptr && comment[0] != '\0' && strcmp(text, comment) == 0) {
            pos = Unk_NextLine(string, pos + commentLen);
            continue;
        }
        s32 i;
        for (i = 0; i < delimLen; i++)
            if (string->Unk_CharAt(pos) == delimiters[i])
                break;
        if (i >= delimLen)
            break;
    }
    string->Unk_451e00(pos, length);
    text[commentLen] = '\0';
    if (quotes != nullptr && quoteLength < 0)
        quoteLength = strlen(quotes);
    s32 quoteLen = quotes != nullptr ? quoteLength : 0;
    length = string->field_0;
    char quote = '\0';
    bool quoted = false;
    for (s32 i = 0; i < quoteLen && !quoted; i++) {
        if (string->Unk_CharAt(1) == quotes[i]) {
            quote = string->Unk_CharAt(1);
            quoted = true;
        }
    }
    s32 end;
    for (end = 2; end <= length; end++) {
        if (quoted) {
            if (string->field_8[end - 1] != quote)
                continue;
            quoted = false;
        }
        if (commentLen != 0) {
            memcpy(text, string->field_8 + end - 1, commentLen);
            text[commentLen] = '\0';
        }
        if (comment != nullptr && comment[0] != '\0' && strcmp(text, comment) == 0)
            break;
        char c = string->field_8[end - 1];
        s32 i;
        for (i = 0; i < delimLen; i++)
            if (c == delimiters[i])
                break;
        if (i < delimLen)
            break;
    }
    Unk_TFXString token = string->Unk_4522d0(1, end - 1);
    string->Unk_451e00(end, string->field_0);
    if (quote != '\0') {
        char text[2] = {quote, '\0'};
        token.Unk_451f00(text);
    }
    return token;
}

// 0x7100451dc0
s32 Unk_TFXString::Unk_451dc0(char c, s32 start) const {
    for (s32 i = start; i <= field_0; i++)
        if (field_8[i - 1] == c)
            return i;
    return 0;
}

// 0x7100451e00
Unk_TFXString& Unk_TFXString::Unk_451e00(s32 start, s32 count) {
    s32 length = field_0;
    s32 first = start > 1 ? start : 1;
    if (count < 0 || first > length)
        return Clear();
    if (first + count > length + 1)
        count = length + 1 - first;
    if (start > 1)
        memmove(field_8, field_8 + (first - 1), count);
    Unk_451320(count, 1);
    field_0 = count;
    if (field_4 != 0)
        field_8[count] = '\0';
    return *this;
}

// 0x7100451f00
// The last character is read as `*(field_8 + length - 1)`: with `field_8[length
// - 1]` its address is computed before the first character is loaded.
Unk_TFXString& Unk_TFXString::Unk_451f00(const char* quotes) {
    s32 length = field_0;
    if (length >= 1) {
        s32 i;
        for (i = 1; i <= length; i++) {
            char c = field_8[i - 1];
            if (c != ' ' && c != '\t' && c != '\n')
                break;
        }
        if (i >= 2)
            Unk_451e00(i, length);
    }
    Unk_452b30();
    length = field_0;
    if (length >= 1 && field_8[0] == *(field_8 + length - 1) && length != 1) {
        char c = field_8[0];
        s32 count = strlen(quotes);
        for (s32 i = 0; i < count; i++) {
            if (c == quotes[i]) {
                Unk_451e00(2, length - 2);
                break;
            }
        }
    }
    return *this;
}

// 0x71004520d0
s32 Unk_TFXString::Unk_4520d0(const char* text, s32 start, s32 count) const {
    if (text == nullptr)
        return 0;
    char first = text[0];
    if (first == '\0')
        return 0;
    if (count < 0)
        count = strlen(text);
    if (count == 0)
        return 0;
    s32 from = start - 1 > 0 ? start - 1 : 0;
    if (field_0 < from)
        return 0;
    s32 end = field_0 + 1 - count;
    for (s32 i = from; i < end; i++) {
        if (first == field_8[i]) {
            if (count == 1)
                return i + 1;
            s32 j;
            for (j = 1; j < count; j++)
                if (field_8[i + j] != text[j])
                    break;
            if (j == count)
                return i + 1;
        }
    }
    return 0;
}

// 0x71004522d0
Unk_TFXString Unk_TFXString::Unk_4522d0(s32 start, s32 count) const {
    s32 length = field_0;
    s32 first = start > 1 ? start : 1;
    if (count < 0 || first > length)
        return Unk_TFXString("");
    if (first + count > length + 1)
        count = length + 1 - first;
    return Unk_TFXString(field_8 + (first - 1), count, count);
}

// 0x7100452340
Unk_TFXString Unk_TFXString::Unk_452340(s32 start, s32 end) const {
    if (end <= 0)
        return Unk_4522d0(start, field_0);
    return Unk_4522d0(start, end - start + 1);
}

// 0x7100452400
s32 Unk_TFXString::Unk_452400(const char* text, s32 start, s32 count) const {
    if (text == nullptr)
        return 0;
    char first = text[0];
    if (first == '\0')
        return 0;
    if (count < 0)
        count = strlen(text);
    if (start <= 0)
        start = field_0;
    s32 from = start - count;
    if (from < count)
        return 0;
    for (s32 i = from; i >= 0; i--) {
        if (first == field_8[i]) {
            if (count == 1)
                return i + 1;
            s32 j;
            for (j = 1; j < count; j++)
                if (field_8[i + j] != text[j])
                    break;
            if (j == count)
                return i + 1;
        }
    }
    return 0;
}

// 0x71004525a0
// (the zero digit first: with the digit's branch first the remainder comes
// after the digit's stores)
Unk_TFXString Unk_4525a0(s32 value) {
    Unk_TFXString text;
    if (value < 0) {
        text = "-";
        value = -value;
    }
    s32 started = 0;
    for (s32 divisor = 1000000000; divisor > 1; divisor /= 10) {
        if (divisor > value) {
            if (started) {
                text += '0';
            }
        } else {
            text += static_cast<char>('0' + value / divisor);
            value %= divisor;
            started = 1;
        }
    }
    return text + static_cast<char>('0' + value);
}

// 0x7100452740
Unk_TFXString Unk_TFXString::operator+(char c) const {
    Unk_TFXString sum(field_8, field_0 + 1, -1);
    sum.field_8[sum.field_0 - 1] = c;
    return sum;
}

// 0x7100452790
s32 Unk_TFXString::Unk_452790(const char* text, s32 count) const {
    if (count < 0)
        return strcmp(field_8, text);
    return strncmp(field_8, text, count);
}

// 0x71004527b0
// (an int: its caller, the license check, tests the whole register)
s32 Unk_TFXString::operator!=(const Unk_TFXString& other) const {
    return strcmp(field_8, other.field_8) != 0;
}

// 0x71004527e0
s32 Unk_TFXString::operator==(const char* text) const {
    return strcmp(field_8, text) == 0;
}

// 0x7100452820
Unk_TFXString Unk_TFXString::operator+(const char* text) const {
    if (text == nullptr)
        return *this;
    s32 length = strlen(text);
    if (length == 0)
        return *this;
    Unk_TFXString sum(field_8, field_0 + length, -1);
    memcpy(sum.field_8 + field_0, text, length);
    return sum;
}

// 0x71004529a0: `text` followed by `other`
Unk_TFXString Unk_4529a0(const char* text, const Unk_TFXString& other) {
    if (text == nullptr)
        return other;
    s32 length = strlen(text);
    if (length == 0)
        return other;
    Unk_TFXString sum(text, other.field_0 + length, -1);
    for (s32 i = 0; i < other.field_0; i++)
        sum.field_8[length + i] = other.field_8[i];
    return sum;
}

// 0x7100452b30
Unk_TFXString& Unk_TFXString::Unk_452b30() {
    s32 length = field_0;
    if (length >= 1) {
        s32 end = length;
        for (; end > 0; end--) {
            if (!isspace(Unk_At(end))) {
                break;
            }
        }
        Unk_451530(end);
    }
    return *this;
}

// 0x7100452c00
Unk_TFXString& Unk_TFXString::Unk_452c00(const Unk_TFXString& chars) {
    s32 length = field_0;
    if (length >= 1 && chars.field_0 >= 1) {
        s32 count = chars.field_0;
        const char* set = chars.field_8;
        s32 i;
        for (i = 1; i <= length; i++) {
            char c = field_8[i - 1];
            bool other = true;
            for (s32 j = 1; j <= count; j++) {
                if (c == set[j - 1]) {
                    other = false;
                }
            }
            if (other) {
                break;
            }
        }
        if (i >= 2) {
            Unk_451e00(i, length);
        }
    }
    return *this;
}

// 0x7100452d20
// `count` isn't tested: the test of the inner loop's guard that the original
// has after the length's is LLVM's (loop unswitching finds that nothing is
// cut when the inner loop doesn't run). Written out, it comes first.
Unk_TFXString& Unk_TFXString::CutLeft(const char* szDefSpace, s32 count) {
#line 2216
    assert(szDefSpace);
    if (count < 0) {
        count = strlen(szDefSpace);
    }
    s32 length = field_0;
    if (length >= 1) {
        s32 i;
        for (i = 1; i <= length; i++) {
            char c = field_8[i - 1];
            bool other = true;
            for (s32 j = 1; j <= count; j++) {
                if (c == szDefSpace[j - 1]) {
                    other = false;
                }
            }
            if (other) {
                break;
            }
        }
        if (i >= 2) {
            Unk_451e00(i, length);
        }
    }
    return *this;
}

}  // namespace PPFX

// 0x7100452e70: _GLOBAL__sub_I_TFXString.cpp, the static objects of Unk_StaticsBase.h
