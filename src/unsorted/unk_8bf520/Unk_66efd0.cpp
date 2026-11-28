// Scope: common
// The script machine's strings and the math commands of 0x71023a0500.
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <types.h>

#include "unsorted/unk_8bf520/Unk_66efd0.h"

// 0x710066efe0: the string at the offset in the data block, or error 5.
u32 Unk_66efe0(Unk_66efd0* self, s64 offset, u64** out) {
    u8* data = self->field_10;
    if (data == nullptr)
        data = reinterpret_cast<u8*>(self->field_0) + self->field_0->field_10;
    if ((offset >= self->field_40 && offset < self->field_50) || offset < 0 ||
        offset >= self->field_58) {
        *out = nullptr;
        return 5;
    }
    *out = reinterpret_cast<u64*>(data + static_cast<s32>(offset));
    return 0;
}

// NON_MATCHING: in the one-character-a-word copy the original tests `wide`
// before the first word and checks count at the loop's head; here the first
// word is tested first (same instructions, other order).
// 0x710066f050: copies a string (packed eight characters a word, the first
// in the top byte, or one a word) into count characters, wide ones or not.
u32 Unk_66f050(void* dst, const u64* src, u32 wide, u64 count) {
    s32 i = 0;
    if (src[0] >> 56) {
        s64 word = 0;
        u64 shift = 7;
        while (i < count) {
            if (shift == 7)
                word = *src++;
            u8 c = word >> (shift * 8);
            if (c == 0)
                break;
            if (wide)
                static_cast<u32*>(dst)[i] = c;
            else
                static_cast<char*>(dst)[i] = c;
            i++;
            shift = (shift - 1) & 7;
        }
    } else {
        for (u64 c = src[0]; c != 0; c = src[++i]) {
            if (i >= count)
                break;
            if (wide)
                static_cast<u32*>(dst)[i] = c;
            else
                static_cast<char*>(dst)[i] = c;
        }
    }
    s32 end = i < count ? i : static_cast<s32>(count) - 1;
    if (end >= 0) {
        if (wide)
            static_cast<u32*>(dst)[end] = 0;
        else
            static_cast<char*>(dst)[end] = 0;
    }
    return 0;
}

// The length of a string (as Unk_66f050 reads it).
static u64 Length(const u64* str) {
    if (str[0] >> 56) {
        u64 length = strlen(reinterpret_cast<const char*>(str)) & ~7;
        u64 word = *reinterpret_cast<const u64*>(reinterpret_cast<const u8*>(str) + length);
        while (word >> 56) {
            length++;
            word <<= 8;
        }
        return length;
    }
    u64 length = 0;
    while (str[length] != 0)
        length++;
    return length;
}

// 0x710066f180: an integer as a double.
s64 Unk_66f180(Unk_66efd0* self, const Unk_66efd0_Args* args) {
    return Unk_66efd0_Result(static_cast<f64>(args->field_8.i));
}

// 0x710066f190: the number a string spells.
s64 Unk_66f190(Unk_66efd0* self, const Unk_66efd0_Args* args) {
    u64* str;
    Unk_66efe0(self, args->field_8.i, &str);
    if (str == nullptr)
        return 0;
    u64 length = Length(str);
    if (length == 0 || length >= 60)
        return 0;
    char buffer[60];
    Unk_66f050(buffer, str, 0, sizeof(buffer));
    return Unk_66efd0_Result(atof(buffer));
}

// 0x710066f340
s64 Unk_66f340(Unk_66efd0* self, const Unk_66efd0_Args* args) {
    return Unk_66efd0_Result(args->field_8.f * args->field_10.f);
}

// 0x710066f350
s64 Unk_66f350(Unk_66efd0* self, const Unk_66efd0_Args* args) {
    return Unk_66efd0_Result(args->field_8.f / args->field_10.f);
}

// 0x710066f360
s64 Unk_66f360(Unk_66efd0* self, const Unk_66efd0_Args* args) {
    return Unk_66efd0_Result(args->field_8.f + args->field_10.f);
}

// 0x710066f370
s64 Unk_66f370(Unk_66efd0* self, const Unk_66efd0_Args* args) {
    return Unk_66efd0_Result(args->field_8.f - args->field_10.f);
}

// 0x710066f380: the fractional part.
s64 Unk_66f380(Unk_66efd0* self, const Unk_66efd0_Args* args) {
    f64 value = args->field_8.f;
    return Unk_66efd0_Result(value - floor(value));
}

// NON_MATCHING: case 3's select: the original computes ceil before floor
// and selects on lt (the inverse of ge), so its frint/fcmp order and
// registers differ.
// 0x710066f3a0: a double as an integer, rounded down (1), up (2), towards
// zero (3) or to the nearest.
s64 Unk_66f3a0(Unk_66efd0* self, const Unk_66efd0_Args* args) {
    f64 value = args->field_8.f;
    switch (args->field_10.i) {
        case 1:
            return static_cast<s64>(floor(value));
        case 2:
            return static_cast<s64>(ceil(value));
        case 3:
            return static_cast<s64>(value >= 0.0 ? floor(value) : ceil(value));
        default:
            return static_cast<s64>(floor(value + 0.5));
    }
}

// 0x710066f400: -1, 0 or 1 as the first double is below, equal to or above
// the second.
s64 Unk_66f400(Unk_66efd0* self, const Unk_66efd0_Args* args) {
    f64 a = args->field_8.f;
    f64 b = args->field_10.f;
    if (a == b)
        return 0;
    return a > b ? 1 : -1;
}

// 0x710066f420: the square root, error 0x1a when there's none.
s64 Unk_66f420(Unk_66efd0* self, const Unk_66efd0_Args* args) {
    f64 result = sqrt(args->field_8.f);
    if (result < 0.0) {
        self->field_a4 = 0x1a;
        return 0;
    }
    return Unk_66efd0_Result(result);
}

// 0x710066f480
s64 Unk_66f480(Unk_66efd0* self, const Unk_66efd0_Args* args) {
    return Unk_66efd0_Result(pow(args->field_8.f, args->field_10.f));
}

// 0x710066f4a0: the logarithm in a base, error 0x1a when there's none.
s64 Unk_66f4a0(Unk_66efd0* self, const Unk_66efd0_Args* args) {
    f64 value = args->field_8.f;
    f64 base = args->field_10.f;
    if (value <= 0.0 || base <= 0.0) {
        self->field_a4 = 0x1a;
        return 0;
    }
    f64 result = base == 10.0 ? log10(value) : log(value) / log(base);
    return Unk_66efd0_Result(result);
}

// 0x710066f520: the sine of an angle in radians, degrees (1) or 2's unit.
s64 Unk_66f520(Unk_66efd0* self, const Unk_66efd0_Args* args) {
    return Unk_66efd0_Result(static_cast<f32>(sin(Unk_66efd0_Radians(args))));
}
