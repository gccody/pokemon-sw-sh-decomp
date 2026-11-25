// Scope: common
// NEX 4.6.8: two scrambled IDs, a 32-bit one (Unk_162fef0) and a 64-bit one
// (Unk_16305b0). Each holds the value it gives back when it isn't set, the key
// it's XORed with, the scrambled value and whether it is set. The scrambled
// value carries a checksum byte (bits 24-31): the XOR of the value's bytes and
// of a hash of a name. They're read from and written as codes in base 28.
#include <algorithm>

#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include <nn/nex/String.h>

// 0x71015bca70: the string's length.
size_t Unk_15bca70(const nn::nex::String* self);

// lib/nx_middleware/leaf/Unk_162eec0.cpp
struct Unk_162fef0 {
    u32 field_0;  // the value when it isn't set
    u8 _4[0x4];
    u64 field_8;   // the key
    u64 field_10;  // the scrambled value
    u8 field_18;   // whether it is set
};
PKMN_OFFSET_ASSERT(Unk_162fef0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_162fef0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_162fef0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_162fef0, field_18, 0x18);

struct Unk_16305b0 {
    u64 field_0;  // the value when it isn't set
    u64 field_8;   // the key
    u64 field_10;  // the scrambled value
    u8 field_18;   // whether it is set
};
PKMN_OFFSET_ASSERT(Unk_16305b0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_16305b0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_16305b0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_16305b0, field_18, 0x18);

// 0x710162fcf0: the 32-bit ID a code gives.
u64 Unk_162fcf0(const Unk_162fef0* self, const nn::nex::String& code);
// 0x710162fbd0: whether a scrambled 32-bit ID's checksum is the name's.
bool Unk_162fbd0(const Unk_162fef0* self, const nn::nex::String& name, u64 value);


// 0x71015bc1e0: assigns `length` characters of `str` (all of it for -1).
void Unk_15bc1e0(nn::nex::String* self, const char* str, size_t length);

// A String with a copy of `str` (NEX's String(const char*), inline).
static inline nn::nex::String MakeString(const char* str) {
    nn::nex::String result;
    Unk_15bc1e0(&result, str, static_cast<size_t>(-1));
    return result;
}

// The digits of the codes, in base 28: the 32-bit ID's (0x7101f3e014) and the
// 64-bit ID's (0x7101f3e030).
static const char Unk_1f3e014[28] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'B', 'C', 'D', 'F',
                                     'G', 'H', 'J', 'K', 'L', 'M', 'N', 'P', 'R', 'T', 'V', 'W', 'X', 'Y'};
static const char Unk_1f3e030[28] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'B', 'C', 'D', 'F',
                                     'G', 'H', 'J', 'K', 'L', 'M', 'N', 'P', 'R', 'T', 'V', 'W', 'X', 'Y'};

// Writes a value's digits in base 28, the lowest first; how many.
static inline int WriteDigits(char* out, u64 value, const char* digits) {
    int count = 0;
    if (value == 0) {
        out[count++] = '0';
        return count;
    }
    while (value != 0) {
        out[count++] = digits[value % 28];
        value /= 28;
    }
    return count;
}

// The hash of a name in the checksums (its first 32 characters).
static inline u8 NameHash(const nn::nex::String& name) {
    u8 hash = 0;
    for (size_t i = 0; i < std::min(Unk_15bca70(&name), static_cast<size_t>(32)); ++i) {
        hash ^= name.m_ptr[i];
        hash = (hash >> 4) | (hash << 4);
    }
    return hash;
}

// The XOR of a value's bytes (but the checksum's, when `skip` is 3).
static inline u8 ByteSum(u64 value, int skip) {
    const u8* bytes = reinterpret_cast<const u8*>(&value);
    u8 sum = 0;
    for (int i = 0; i < 8; ++i) {
        if (i != skip) sum ^= bytes[i];
    }
    return sum;
}

// 0x710162fe60: sets the ID from a code, if it is valid for the name.
bool Unk_162fe60(Unk_162fef0* self, const nn::nex::String& name, const nn::nex::String& code) {
    u64 value = Unk_162fcf0(self, code);
    if (value == self->field_8) {
        self->field_10 = value;
        self->field_18 = false;
        return false;
    }
    if (Unk_162fbd0(self, name, value)) {
        self->field_10 = value;
        self->field_18 = true;
    } else {
        self->field_10 = self->field_8;
        self->field_18 = false;
    }
    return self->field_18;
}

// 0x710162ff00: the ID.
u32 Unk_162ff00(const Unk_162fef0* self) {
    if (!self->field_18) return self->field_0;
    u64 x = self->field_10 ^ self->field_8;
    u32 v = static_cast<u32>(((x >> 8) & 0xff000000) | (x & 0xffffff));
    v *= 0x66cddf03;
    v = ((v << 1) & 0xaaaaaaaa) | ((v >> 1) & 0x55555555);
    v = ((v << 2) & 0xcccccccc) | ((v >> 2) & 0x33333333);
    v = ((v << 4) & 0xf0f0f0f0) | ((v >> 4) & 0x0f0f0f0f);
    v = ((v << 8) & 0xff00ff00) | ((v >> 8) & 0x00ff00ff);
    v = (v >> 16) | (v << 16);
    return v * 0x7ff503ab;
}

// 0x710162ffa0: the ID's code (9 digits; "" when it isn't set).
// NON_MATCHING: the digit loop's condition is compiled as value > 27 (cmp #0x1b, b.hi;
// the original's value >= 28, cmp #0x1c, b.hs), and the padding's count is sign-extended
// (the original zero-extends it, as if the count were unsigned).
nn::nex::String Unk_162ffa0(const Unk_162fef0* self) {
    if (!self->field_18) return MakeString("");
    u64 value = self->field_10;
    char digits[9];
    memset(digits, 0, sizeof(digits));
    int count = WriteDigits(digits, value, Unk_1f3e014);
    char code[10];
    u32 length = 0;
    while (length < sizeof(digits) - count) {
        code[length++] = '0';
    }
    for (int i = count - 1; i >= 0; --i) {
        code[length++] = digits[i];
    }
    code[length] = '\0';
    return MakeString(code);
}

// 0x7101630270: compares two characters (bsearch's comparison).
static int Unk_1630270(const void* a, const void* b) {
    u8 x = *static_cast<const u8*>(a);
    u8 y = *static_cast<const u8*>(b);
    if (x < y) return -1;
    return x > y;
}

// 0x7101630140: the value of a code (the unset value if it's too long, the key
// if it has a character that isn't a digit).
// NON_MATCHING: the 'I' case stores its '1' itself (the original branches to the 'S'
// case's store), so the cases' blocks are laid out differently.

u64 Unk_1630140(const Unk_16305b0* self, const nn::nex::String& code) {
    if (Unk_15bca70(&code) >= 15) return self->field_0;
    u64 value = 0;
    for (const char* p = code.m_ptr; *p != '\0'; ++p) {
        // The letters read as the digits they look like.
        char c = toupper(*p);
        switch (c) {
        case 'I':
            c = '1';
            break;
        case 'O':
        case 'Q':
            c = '0';
            break;
        case 'S':
            c = '5';
            break;
        case 'Z':
            c = '2';
            break;
        }
        const char* digit = static_cast<const char*>(
            bsearch(&c, Unk_1f3e030, sizeof(Unk_1f3e030), 1, Unk_1630270));
        if (digit == nullptr) return self->field_8;
        value = value * 28 + (digit - Unk_1f3e030);
    }
    return value;
}

// The scrambled value of an ID (the key: none, when its top byte is set or it's
// the unset one).
static inline u64 Scramble(const Unk_16305b0* self, const nn::nex::String& name, u64 value) {
    if (value == self->field_0) return self->field_8;
    if ((value >> 56) != 0) return self->field_8;
    u8 hash = NameHash(name);
    u8 sum = hash ^ ByteSum(value, -1);
    // The value's bytes moved up past the checksum's (byte 3).
    u64 encoded = (value & 0xffffff) | ((value >> 24) << 32) | (static_cast<u64>(sum) << 24);
    return encoded ^ self->field_8;
}

// 0x7101630290: sets the ID to a value.
// NON_MATCHING: the checksum's byte shifts are scheduled differently around the
// encoded value's bit inserts (the same instructions otherwise).
bool Unk_1630290(Unk_16305b0* self, const nn::nex::String& name, u64 value) {
    u64 scrambled = Scramble(self, name, value);
    bool set = scrambled != self->field_8;
    self->field_10 = scrambled;
    self->field_18 = set;
    return set;
}

// 0x71016304c0: sets the scrambled ID, if its checksum is the name's.
bool Unk_16304c0(Unk_16305b0* self, const nn::nex::String& name, u64 scrambled) {
    u64 x = self->field_8 ^ scrambled;
    u8 hash = NameHash(name);
    u8 sum = hash ^ ByteSum(x, 3);
    if (sum != static_cast<u8>(x >> 24)) {
        self->field_10 = self->field_8;
        self->field_18 = false;
        return false;
    }
    self->field_10 = scrambled;
    self->field_18 = true;
    return true;
}

// 0x71016303a0: sets the ID from a code, if it is valid for the name.
bool Unk_16303a0(Unk_16305b0* self, const nn::nex::String& name, const nn::nex::String& code) {
    u64 value = Unk_1630140(self, code);
    if (value == self->field_8) {
        self->field_10 = value;
        self->field_18 = false;
        return false;
    }
    Unk_16304c0(self, name, value);
    return self->field_18;
}

// 0x71016305c0: the ID.
u64 Unk_16305c0(const Unk_16305b0* self) {
    if (!self->field_18) return self->field_0;
    u64 x = self->field_10 ^ self->field_8;
    return ((x >> 8) & 0xffffffff000000) | (x & 0xffffff);
}

// 0x71016305f0: the 64-bit scrambled ID's code ("" when it isn't set).
// NON_MATCHING: the digit loop's condition is compiled as value > 27 (cmp #0x1b, b.hi;
// the original's value >= 28, cmp #0x1c, b.hs), and the copy's guard as count >= 1.
nn::nex::String Unk_16305f0(const Unk_16305b0* self) {
    if (!self->field_18) return MakeString("");
    u64 value = self->field_10;
    char digits[14];
    memset(digits, 0, sizeof(digits));
    int count = WriteDigits(digits, value, Unk_1f3e030);
    char code[15];
    int length = 0;
    for (int i = count - 1; i >= 0; --i) {
        code[length++] = digits[i];
    }
    code[length] = '\0';
    return MakeString(code);
}
