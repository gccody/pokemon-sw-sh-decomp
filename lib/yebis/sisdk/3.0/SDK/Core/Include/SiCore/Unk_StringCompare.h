// SiSDK3's comparison of strings without case, which is inline in every
// function that has it (0x71004ca820 and the other libraries' locale tables,
// SiGfxShaderGraphUtility's searches by name, 0x71004e57e0, 0x71004f5100,
// 0x7100571c00, 0x7100573480, ...). Placeholder names: nothing in the
// executable names these functions, and the header's name isn't in it either.
//
// What the callers' code shows of it, and what each part of the source below
// is there for (every one of them changes the code):
// - The index is an `int`, and both characters are read into locals before
//   either is tested. The two tests are then one block, `c1 == 0 || c2 == 0`,
//   which is merged into one exit before the loop is rotated: both are at the
//   loop's end (`cbz w8 ; cbnz w9`), and what follows the loop can't tell
//   which of them ended it.
// - The results of the two comparisons are different values (-1 and 1), and
//   the index's increment follows them: with it between the second comparison
//   and its branch, the two branches are never folded into one `!=`
//   (`cmp ; b.lo ; b.hi` to the same place).
// - After the loop the result is one expression of both characters, with the
//   first one's test outermost: `c1 != 0 ? -1 : (c1 == 0 && c2 == 0 ? 0 : 1)`.
//   A caller that only asks for equality gets a branch on c1 and then on
//   `(c1 | c2) != 0`, which is the original's `orr` of both characters after
//   c1 was already tested (the inner test was computed before the branch).
// - The string's function returns the three-way result as an `int`, and the
//   callers compare it with 0. With a `bool` in between, the end collapses
//   into one test of `c1 | c2`.
// - The lowered characters are declared before the loop. Declared in it,
//   the returns in the loop leave a scope, and the loop's end is merged with
//   them before the loop is rotated; then this function isn't rotated on its
//   own. The locale tables (0x71005967f0 and its four twins), which compare
//   with constant strings, show that it was: the first iteration's test of
//   the constant is gone and an empty string jumps past every comparison,
//   and after the loop the constant's end is a test of the index
//   (`cmp x24, #7`), not of a character.
#pragma once

#include <ctype.h>

#include "SiCore_String.h"

namespace SiSDK3 {

// Compares two strings of characters without case: 0 if they are the same.
inline int Unk_CompareNoCase(const char* a, const char* b) {
    int i = 0;
    char c1;
    char c2;
    u8 lower1;
    u8 lower2;
    for (;;) {
        c1 = a[i];
        c2 = b[i];
        if (c1 == 0 || c2 == 0) {
            break;
        }
        lower1 = tolower(static_cast<u8>(c1));
        lower2 = tolower(static_cast<u8>(c2));
        if (lower1 < lower2) {
            return 1;
        }
        if (lower1 > lower2) {
            return -1;
        }
        i++;
    }
    return c1 != 0 ? -1 : ((c1 == 0 && c2 == 0) ? 0 : 1);
}

// Compares a string with characters without case (a null pointer is the
// empty string): 0 if they are the same, else which of them is greater.
inline int Unk_CompareNoCase(const SiString<char>* self, const char* s) {
    if (s == nullptr || *s == 0) {
        return self->field_10 != 0;
    }
    if (self->field_10 == 0) {
        return -1;
    }
    return Unk_CompareNoCase(s, self->m_pBuffer);
}

// Compares two strings without case: an empty other is tested by its length
// and its first character, not its buffer (SiGfxShaderEffectVariationList's
// slot 22). The two tests return on their own: the second one's then reads
// self's length before it branches (SiGfxShaderUtility's 0x71004e57e0).
inline int Unk_CompareNoCase(const SiString<char>* self, const SiString<char>* other) {
    if (other->field_10 == 0) {
        return self->field_10 != 0;
    }
    if (other->m_pBuffer[0] == 0) {
        return self->field_10 != 0;
    }
    if (self->field_10 == 0) {
        return -1;
    }
    return Unk_CompareNoCase(other->m_pBuffer, self->m_pBuffer);
}

// The same with case (placeholder name: SiGfxShaderUtility's search of its
// packages by name, 0x71004e3f80).
inline int Unk_Compare(const char* a, const char* b) {
    int i = 0;
    char c1;
    char c2;
    u8 u1;
    u8 u2;
    for (;;) {
        c1 = a[i];
        c2 = b[i];
        if (c1 == 0 || c2 == 0) {
            break;
        }
        u1 = static_cast<u8>(c1);
        u2 = static_cast<u8>(c2);
        if (u1 < u2) {
            return 1;
        }
        if (u1 > u2) {
            return -1;
        }
        i++;
    }
    return c1 != 0 ? -1 : ((c1 == 0 && c2 == 0) ? 0 : 1);
}

inline int Unk_Compare(const SiString<char>* self, const char* s) {
    if (s == nullptr || *s == 0) {
        return self->field_10 != 0;
    }
    if (self->field_10 == 0) {
        return -1;
    }
    return Unk_Compare(s, self->m_pBuffer);
}

}  // namespace SiSDK3
