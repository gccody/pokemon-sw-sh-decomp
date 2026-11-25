// Scope: common
// NEX 4.6.8: the end of OnlineCore's Platform/Core/Result.cpp (the result
// constructors, which name it in __FILE__) and the functions linked before
// it: a String assignment, a byte ring buffer, a random generator's seeding
// and rapidjson 1.1 object lookups. Everything the executable doesn't name
// keeps a placeholder.
#include <string.h>

#include <nn/nex/Call.h>
#include <nn/nex/String.h>

// 0x71015bc1e0: copies at most `length` characters of `str` (all of it for
// -1) into the string, growing its buffer when needed.
void Unk_15bc1e0(nn::nex::String* self, const char* str, size_t length);

// 0x71015bb6c0
nn::nex::String* Unk_15bb6c0(nn::nex::String* self, const char* str) {
    if (self->m_ptr != str) {
        Unk_15bc1e0(self, str, static_cast<size_t>(-1));
    }
    return self;
}

// A byte ring buffer: the data at m_readPos, m_size bytes of it.
struct Unk_15bb700 {
    void advanceRead(int size) { m_readPos = (m_readPos + size) % m_capacity; }

    u8 _0[0x8];
    u8* m_buffer;
    u8 _10[0x10];
    size_t m_writePos;
    size_t m_readPos;
    size_t m_size;
    size_t m_capacity;
};
PKMN_OFFSET_ASSERT(Unk_15bb700, m_buffer, 0x8);
PKMN_OFFSET_ASSERT(Unk_15bb700, m_writePos, 0x20);
PKMN_OFFSET_ASSERT(Unk_15bb700, m_readPos, 0x28);
PKMN_OFFSET_ASSERT(Unk_15bb700, m_size, 0x30);
PKMN_SIZE_ASSERT(Unk_15bb700, 0x40);

// 0x71015bb700: appends `size` bytes.
void Unk_15bb700_write(Unk_15bb700* self, const void* data, size_t size) {
    size_t space = self->m_capacity - self->m_writePos;
    if (size < space) {
        memcpy(self->m_buffer + self->m_writePos, data, size);
        self->m_size += size;
        self->m_writePos += size;
        return;
    }
    memcpy(self->m_buffer + self->m_writePos, data, space);
    self->m_size += space;
    self->m_writePos = (self->m_writePos + space) % self->m_capacity;
    size -= space;
    if (size != 0) {
        memcpy(self->m_buffer, static_cast<const u8*>(data) + space, size);
        self->m_size += size;
        self->m_writePos = size;
    }
}

// 0x71015bb7c0: copies the first `size` bytes out, leaving them in.
void Unk_15bb7c0_peek(const Unk_15bb700* self, void* data, size_t size) {
    size_t space = self->m_capacity - self->m_readPos;
    if (size < space) {
        memcpy(data, self->m_buffer + self->m_readPos, size);
        return;
    }
    memcpy(data, self->m_buffer + self->m_readPos, space);
    size -= space;
    if (size != 0) {
        memcpy(static_cast<u8*>(data) + space, self->m_buffer, size);
    }
}

// 0x71015bb850: drops the first `size` bytes.
void Unk_15bb850_skip(Unk_15bb700* self, size_t size) {
    self->advanceRead(size);
    self->m_size -= size;
}

// A Mersenne Twister's state (its matrix 0x9908b0df), seeded the 1998 way
// (sgenrand: each word the previous one times 69069).
struct Unk_15bb890 {
    void seed(u32 seed) {
        m_state[0] = seed;
        for (m_index = 1; m_index < 624; m_index++) {
            m_state[m_index] = m_state[m_index - 1] * 69069;
        }
    }

    u32 m_state[624];
    u32 m_index;
    u32 m_mag01[2];
};
PKMN_OFFSET_ASSERT(Unk_15bb890, m_index, 0x9c0);
PKMN_OFFSET_ASSERT(Unk_15bb890, m_mag01, 0x9c4);
PKMN_SIZE_ASSERT(Unk_15bb890, 0x9cc);

// 0x71015bb890
void Unk_15bb890_init(Unk_15bb890* self) {
    self->m_mag01[0] = 0;
    self->m_mag01[1] = 0x9908b0df;
    self->seed(1);
}

// 0x71015bb900
void Unk_15bb900() {}

// rapidjson 1.1's GenericValue, as these functions use it (64-bit, no 48-bit
// pointers; the flags are rapidjson's): a
// value is 0x18 bytes, its flags in the last two, a short string inline.
enum {
    kBoolFlag = 0x0008,
    kNumberFlag = 0x0010,
    kStringFlag = 0x0400,
    kInlineStrFlag = 0x1000,
    kTrueFlag = 2 | kBoolFlag,
    kConstStringFlag = 5 | kStringFlag,
};

struct Unk_15bb950_Member;

class Unk_15bb950_Value {
public:
    struct String {
        u32 length;
        u32 hashcode;
        const char* str;
    };
    struct ShortString {
        enum { MaxChars = 22, MaxSize = MaxChars - 1, LenPos = MaxSize };
        char str[MaxChars];
        u32 GetLength() const { return static_cast<u32>(MaxSize - str[LenPos]); }
    };
    struct Number {
        int i;
        int padding;
    };
    struct Object {
        u32 size;
        u32 capacity;
        Unk_15bb950_Member* members;
    };
    struct Flag {
        char payload[22];
        u16 flags;
    };
    union Data {
        String s;
        ShortString ss;
        Number n;
        Object o;
        Flag f;
    };

    // rapidjson's GenericStringRef: a string and its length.
    struct StringRef {
        explicit StringRef(const char* str) : s(str), length(StrLen(str)) {}

        static u32 StrLen(const char* str) {
            const char* end = str;
            while (*end != '\0') {
                ++end;
            }
            return static_cast<u32>(end - str);
        }

        const char* s;
        u32 length;
    };

    explicit Unk_15bb950_Value(StringRef ref) : data_() {
        data_.f.flags = kConstStringFlag;
        data_.s.str = ref.s;
        data_.s.length = ref.length;
    }

    bool IsBool() const { return (data_.f.flags & kBoolFlag) != 0; }
    bool IsTrue() const { return data_.f.flags == kTrueFlag; }
    bool IsNumber() const { return (data_.f.flags & kNumberFlag) != 0; }
    int GetInt() const { return data_.n.i; }

    u32 GetStringLength() const {
        return (data_.f.flags & kInlineStrFlag) ? data_.ss.GetLength() : data_.s.length;
    }
    const char* GetString() const {
        return (data_.f.flags & kInlineStrFlag) ? data_.ss.str : data_.s.str;
    }
    bool StringEqual(const Unk_15bb950_Value& rhs) const {
        const u32 len1 = GetStringLength();
        const u32 len2 = rhs.GetStringLength();
        if (len1 != len2) {
            return false;
        }
        const char* const str1 = GetString();
        const char* const str2 = rhs.GetString();
        if (str1 == str2) {
            return true;
        }
        return memcmp(str1, str2, len1) == 0;
    }

    inline Unk_15bb950_Member* MemberBegin() const;
    inline Unk_15bb950_Member* MemberEnd() const;
    inline Unk_15bb950_Member* FindMember(const Unk_15bb950_Value& name) const;
    Unk_15bb950_Member* FindMember(const char* name) const {
        Unk_15bb950_Value n{StringRef(name)};
        return FindMember(n);
    }

    Data data_;
};
PKMN_SIZE_ASSERT(Unk_15bb950_Value, 0x18);

struct Unk_15bb950_Member {
    Unk_15bb950_Value name;
    Unk_15bb950_Value value;
};
PKMN_SIZE_ASSERT(Unk_15bb950_Member, 0x30);

Unk_15bb950_Member* Unk_15bb950_Value::MemberBegin() const {
    return data_.o.members;
}
Unk_15bb950_Member* Unk_15bb950_Value::MemberEnd() const {
    return data_.o.members + data_.o.size;
}
Unk_15bb950_Member* Unk_15bb950_Value::FindMember(const Unk_15bb950_Value& name) const {
    Unk_15bb950_Member* member = MemberBegin();
    for (; member != MemberEnd(); ++member) {
        if (name.StringEqual(member->name)) {
            break;
        }
    }
    return member;
}

// A parsed document: its root value first, the parse result's code at 0x58.
struct Unk_15bb910 {
    Unk_15bb950_Value m_root;
    u8 _18[0x40];
    int m_parseError;
};
PKMN_OFFSET_ASSERT(Unk_15bb910, m_parseError, 0x58);

// rapidjson's StringStream: where it reads and where it started.
struct Unk_15bb910_Stream {
    explicit Unk_15bb910_Stream(const char* str) : m_src(str), m_head(str) {}

    const char* m_src;
    const char* m_head;
};

// 0x71015c0f20: parses the stream into the document.
Unk_15bb910* Unk_15c0f20(Unk_15bb910* self, Unk_15bb910_Stream& stream);

// 0x71015bb910: true when `json` parses.
bool Unk_15bb910_parse(Unk_15bb910* self, const char* json) {
    Unk_15bb910_Stream stream(json);
    Unk_15c0f20(self, stream);
    return self->m_parseError == 0;
}

// NON_MATCHING: register allocation: the original keeps the members pointer in
// one register (x22) from the first load through the end of the search.
// 0x71015bb950: the bool member `name` of `object`.
bool Unk_15bb950(const Unk_15bb910* self,
                 const Unk_15bb950_Value& object,
                 const char* name,
                 bool* value) {
    Unk_15bb950_Member* member = object.FindMember(name);
    if (member != self->m_root.MemberEnd() && member->value.IsBool()) {
        *value = member->value.IsTrue();
        return true;
    }
    return false;
}

// NON_MATCHING: register allocation: the original keeps the members pointer in
// one register (x22) from the first load through the end of the search.
// 0x71015bbaa0: the number member `name` of `object`, as an int.
bool Unk_15bbaa0(const Unk_15bb910* self,
                 const Unk_15bb950_Value& object,
                 const char* name,
                 int* value) {
    Unk_15bb950_Member* member = object.FindMember(name);
    if (member == self->m_root.MemberEnd()) {
        return false;
    }
    if (!member->value.IsNumber()) {
        return false;
    }
    *value = member->value.GetInt();
    return true;
}

// Platform/Core/Result.cpp's __FILE__.
#define UNK_RESULT_FILE "C:/home/ws/hac-appor/Pack/7923402a/OnlineCore/src/Platform/Core/Result.cpp"

// 0x71015bbbe0: a failure.
void Unk_15bbbe0(Unk_15bbc10* self) {
    self->m_code = 0x80010001;
    self->m_file = UNK_RESULT_FILE;
    self->m_line = 95;
}

// 0x71015bbc10
Unk_15bbc10::Unk_15bbc10(const u32& code) {
    m_code = code;
    m_file = UNK_RESULT_FILE;
    m_line = 102;
}

// 0x71015bbc30: success or failure.
void Unk_15bbc30(Unk_15bbc10* self, const bool& success) {
    self->m_code = success ? 0x10001 : 0x80010001;
    self->m_file = UNK_RESULT_FILE;
    self->m_line = 116;
}

// 0x71015bbcb0: success or failure (an assignment: it returns the result).
Unk_15bbc10* Unk_15bbcb0(Unk_15bbc10* self, const bool& success) {
    self->m_code = success ? 0x10001 : 0x80010001;
    self->m_file = UNK_RESULT_FILE;
    self->m_line = 145;
    return self;
}
